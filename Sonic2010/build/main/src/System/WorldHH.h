// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "Render/gfx_Renderable.h"

namespace app
{
class CWorld // TODO: Inheritance
{
    // TODO: Other data members.

public:
    // Wii U: 0x02255b98, PC: 0x004df5f0
    void AddRenderable(gfx::Renderable* renderable,
        Render::SceneGroupType::_ESceneGroupType groupType);
};
}
