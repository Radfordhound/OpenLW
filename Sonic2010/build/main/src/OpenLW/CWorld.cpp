#include "CWorld.h"
#include "gfx/RenderManager.h"

using namespace app::gfx;

namespace app
{
void CWorld::AddRenderable(gfx::Renderable* renderable,
    Render::SceneGroupType::_ESceneGroupType groupType)
{
    RenderManager::GetInstance().AddRenderable(renderable);
}
}
