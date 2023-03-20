// TODO: The name of this file is correct, but the path was guessed!
#include "pch.h"
#include "RenderSceneView.h"
#include "RenderSceneViewImpl.h"

namespace app
{
namespace gfx
{
CRenderSceneView::CRenderSceneView(CRenderSceneViewImpl* impl, bool param_2) :
    m_impl(impl),
    field_0x10(param_2) {}

void CRenderSceneView::AddRenderable(Renderable* renderable)
{
    m_impl->m_renderableContainer->AddObject(renderable);
}
}
}
