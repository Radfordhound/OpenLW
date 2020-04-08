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
