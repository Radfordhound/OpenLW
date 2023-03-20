// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "Render/gfx_Renderable.h"

namespace app
{
class CWorld // TODO: Inheritance
{
LWAPI_PRIVATE
    // TODO: Other data members.

public:
    LWAPI(0x02255b98, 0x004df5f0)
    void AddRenderable(gfx::Renderable* renderable,
        Render::SceneGroupType::_ESceneGroupType groupType);
};
}
