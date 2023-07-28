#include "OpenLW/pch.h"
#include "Application.h"
#include "CriSystem.h"
#include "FileSystemCri.h"
#include "Game.h"
#include "SyncTimer.h"
#include "Input/DeviceManager.h"
#include "Memory/GlobalAllocator.h"
#include "Render/RenderManager.h"
#include "Movie/MovieSystem.h"
#include <Hedgehog/MirageCore/hhMirageCore.h>
#include <Hedgehog/Utility/hhUtility.h>

using namespace app::fnd;
using namespace app::gfx;
using namespace app::game;
using namespace app::hid;
using namespace hh::base;
using namespace hh::mr;
using namespace hh::ut;
using namespace csl::fnd;

namespace app
{
Application::~Application()
{
    // TODO
}

void Application::InitializeBasic()
{
    // TODO
}

void Application::ShutdownBasic()
{
    // TODO
}

void Application::InitializeMain()
{
    IAllocator* allocator = GlobalAllocator::GetAllocator(ALLOCATOR_UNK_TWO);

    // TODO

    SInitializeHHBaseSetting baseSetting = {};
    baseSetting.field_0x1 = true;
    baseSetting.field_0x2 = true;
    // TODO

    InitializeHHBase(&baseSetting);
    InitializeHHUtility();
    InitializeHHMirage();

    CreateDevice();

    // TODO

    // Create FileSystemCri instance and use it as the FileSystem.
    FileSystem::ReplaceInstance(FileSystemCri::Create(allocator));

    // Create RenderManager instance and use it as the RenderManager.
    RenderManager::ReplaceInstance(RenderManager::Create(allocator));

    // Set rendering device.
    RenderManager& renderMgr = RenderManager::GetInstance();
    CRenderingInfrastructure* renderInfrs = renderMgr.GetRenderingDevice();

    renderInfrs->GetDevice()->SetHandle(RsdxDevice);

    // Create CMovieSystem instance and use it as the CMovieSystem.
    CMovieSystem::ReplaceInstance(CMovieSystem::Create(allocator));
}

void Application::ShutdownMain()
{
    // TODO
    RenderManager::ReplaceInstance(nullptr);
    FileSystem::ReplaceInstance(nullptr);
    // TODO
    DestroyDevice();
    // TODO
}

void Application::RunCore(SyncTimer* timer) {}

void Application::Initialize()
{
    InitializeBasic();
    InitSingletons();

    Game = CreateGame(*this);
    Game->Config(*this);

    InitializeMain();
    InitializeCommon();

    Game->OnSetup(*this);
}

void Application::InitializeCommon()
{
    // TODO

    // Setup FileSystem.
    FileSystem& fileSystem = FileSystem::GetInstance();
    FileSystem::Info fsInfo = FileSystem::Info();
    fsInfo.RootDirectory = RootDirectory;

    fileSystem.Setup(fsInfo);

    // Bind file directories.
    FileBinder* binder = fileSystem.GetDefaultBinder();
    if (binder)
    {
        if ((fileSystem.Flags & FILE_SYSTEM_FLAG_USE_CPK) == 0)
        {
            binder->BindDirectory("raw", 0x100, false);
            binder->BindDirectory("", 0x300, false);
            binder->WaitSyncAll();
        }
        else
        {
            binder->BindCpk("disk/sonic2013_0.cpk", 0x1000, false);
            binder->BindCpk("disk/sonic2013_patch_0.cpk", 0x4000, false);
            binder->WaitSyncAll();
        }
    }

    // Set FileCache size.
    fileSystem.SetFileCacheSize(0xC000000);

    // Setup RenderManager.
    RenderManager::SetupInfo setupInfo = RenderManager::SetupInfo();
    setupInfo.SetAspect(1280 / 720.0f);
    setupInfo.SetShaderName("shader.pac");

    RenderManager& renderMgr = RenderManager::GetInstance();
    renderMgr.Setup(setupInfo);

    // TODO

    // Setup CMovieSystem.
    CMovieSystem::GetInstance().Setup("movie");

    // Setup DeviceManager.
    DeviceManager& deviceMgr = DeviceManager::GetInstance();
    deviceMgr.Setup();

    // TODO
}

void Application::RunOnce(const fnd::SUpdateInfo& updateInfo)
{
    Poll(updateInfo);
    Tick();
}

void Application::Poll(const fnd::SUpdateInfo& updateInfo)
{
    // Poll devices.
    DeviceManager& deviceMgr = DeviceManager::GetInstance();
    deviceMgr.Poll(updateInfo.DeltaTime);

    // Update CriSystem.
    CriSystem& criSystem = CriSystem::GetInstance();
    criSystem.Update();

    // Update FileSystem.
    FileSystem& fileSystem = FileSystem::GetInstance();
    fileSystem.Update();

    // TODO
}

void Application::Tick()
{
    Game->Tick(*this);
}

void Application::Run()
{
    SyncTimer& syncTimer = SyncTimer::GetInstance();
    syncTimer.Reset();
    RunCore(&syncTimer);
}

void Application::Draw()
{
    Game->Draw(*this);
}

void Application::Shutdown()
{
    Game->OnShutdown(*this);
    ShutdownCommon();
    ShutdownMain();
    DestroyGame(Game);
    DestroySingletons();
    ShutdownBasic();
}

void Application::ShutdownCommon()
{
    // TODO

    RenderManager& renderMgr = RenderManager::GetInstance();
    renderMgr.Shutdown();

    // TODO
}

Application::Application()
{
    RsdxDevCore = nullptr;
    RsdxDevice = nullptr;
    InstHandle = nullptr;
    SurfaceHandle = nullptr;
    // TODO
    Width = 1280;
    Height = 720;
    // TODO
    Game = nullptr;
    RootDirectory[0] = '\0';
    UpdateInfo = SUpdateInfo();
    UpdateInfo.DeltaTime = (1 / 60.0f);
    UpdateInfo.field_0x8 = 1;
}
} // app
