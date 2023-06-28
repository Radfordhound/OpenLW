# OpenLW

An open-source recreation of Sonic Lost World, based on decompilations of the Wii U/PC versions of the game done via Ghidra.

**This is a major WIP hobby project; don't expect much!!**

For now I'm aiming to just make things work and make it as accurate to the PC version of the game as possible. Compiling therefore currently is a bit of a pain as it requires the following proprietary third-party libraries:

- Criware SDK
- Havok 2012 SDK (Newer versions might work as well?)

I cannot provide these libraries for legal reasons.

Intel released a legal free version of the Havok 2012 SDK a while ago, so you should be able to use a mirror of that.

Eventually I'd like to replace these with free and/or open-source equivalents (would be a major pain but would be worth it), but for now, this is how it is.

It's also using Direct3D 9 just like the original game, so you'll need its SDK as well. Someday I'd love to write optional additional backends such as Direct3D 11/12, OpenGL, and/or Vulkan. This combined with open-source replacements for the Criware/Havok SDKs could allow this to compile on macOS/Linux/other platforms (Switch homebrew??) as well which would be cool. Although, this is a very long-term goal and would be quite a pain (I'd have to port shaders and such), so don't count on it.

Everything is named/organized with the intent of being as accurate to what I imagine Sonic Team's original source looked like as possible. Since Sonic Team accidentally (?) released a debug build of the game on the Wii U with symbols enabled, this is a lot more achievable than you might think.

I'm also attempting to document much of the source code via doxygen comments. Obviously that's another long-term goal; hardly anything is actually documented right now. I have been logging the addresses of functions within the Wii U/PC builds of the game, however, as I believe this may be useful to others who want to create code injection mods and such for the actual game.

## LWAPI

This repository also hosts a separate project: "LWAPI".

Based on Sajid's project of the same name, LWAPI is a library that aims to drastically simplify the process of creating DLL mods for Sonic Lost World!

### Building

1. Download [the latest release of LWAPIBindingGenerator](https://github.com/Radfordhound/LWAPIBindingGenerator/releases/latest) and save it somewhere.

2. Set the `LWAPI_BINDING_GENERATOR_DIR` environment variable in Windows to the directory you placed `LWAPIBindingGenerator.exe` in.

3. Open [LWAPI.sln](LWAPI/LWAPI.sln) and hit build.

You should get a .lib file in the `LWAPI/bin/$(Configuration)` directory, where `$(Configuration)` is either `Debug` or `Release` depending on the configuration you used to build.

This .lib file contains auto-generated assembly bindings for every function from the game that is supported by LWAPI.

In your dll mod, you can simply link against this .lib file, include LWAPI.h and the OpenLW headers, and build your dll.

The compiler will automatically optimize-out the bindings that are not used in your dll mod, leaving only the ones which are used.

All of this enables you to write very simple/readable code for your dll mods, similar to what Sonic Team's actual codebase would have looked like!

### Example

**NOTE:** The following examples use the [HookHelpers](https://github.com/Radfordhound/HookHelpers) library to simplify the process of installing function hooks.

#### Example #1

Give the player 100 rings whenever the camera is first initialized

```cpp
#include <HookHelpers.h>
#include <LWAPI.h>
#include <Camera/Camera.h>

namespace app
{
namespace Camera
{
MEMBER_HOOK(LWAPI_ASLR(0x00419580), CCamera,
    CCamera_AddCallback_Hook, void,
    GameDocument* gameDoc)
{
    // Get level info.
    const auto levelInfo = m_owner->GetService<CLevelInfo>();

    // Attempt to get the actor for player #1.
    const auto playerID = levelInfo->GetPlayerID(0);
    const auto player = static_cast<Player::CPlayer*>(m_msgMgr->GetActor(playerID));

    // If there is an actor for player #1 (there isn't one on the world map, for example), give the player 100 rings.
    if (player)
    {
        Player::StateUtil::AddRingNum(*player->GetStateGOC(), 100, true);
    }
}

static void CCamera_InstallHooks()
{
    // Unprotect vtable1.
    const vtable_ptr vtable1(LWAPI_ASLR(0x00d590f0));
    vtable1.Unprotect(4);

    // Install vtable1 hooks.
    vtable1.InstallHook<CCamera_AddCallback_Hook>(1);
}

LWAPI_DEFINE_PATCH(CCamera_InstallHooks)
} // Camera
} // app

// Called by LostCodeLoader at game initialization time.
extern "C" __declspec(dllexport) void Init(const char* path)
{
    // Apply all defined patches.
    lwapi::ApplyPatches();
}

// Called by Windows at DLL initialization time.
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}
```

