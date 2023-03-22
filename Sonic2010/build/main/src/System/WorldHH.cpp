// TODO: The name of this file is correct, but the path was guessed!
#include "OpenLW/pch.h"
#include "WorldHH.h"
#include "Render/RenderManager.h"

using namespace app::gfx;

namespace app
{
void CWorld::AddRenderable(gfx::Renderable* renderable,
    Render::SceneGroupType::_ESceneGroupType groupType)
{
    RenderManager::GetInstance().AddRenderable(renderable);
}
}
