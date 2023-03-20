// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "System/ReferencedObject.h"

namespace app
{
namespace gfx
{
class CRenderSceneViewImpl;
struct Renderable;

class CRenderSceneView : public fnd::ReferencedObject // size == 20
{
LWAPI_PRIVATE
    CRenderSceneViewImpl* m_impl;
    bool field_0x10;

public:
    LWAPI(0x0226e4ac, TODO)
    CRenderSceneView(CRenderSceneViewImpl* impl, bool param_2);

    LWAPI(0x0226e6f8, TODO)
    void AddRenderable(Renderable* renderable);
};
}
}
