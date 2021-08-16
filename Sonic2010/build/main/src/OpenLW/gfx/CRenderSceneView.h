#pragma once
#include "../fnd/ReferencedObject.h"

namespace app
{
namespace gfx
{
class CRenderSceneViewImpl;
struct Renderable;

class CRenderSceneView : public fnd::ReferencedObject // size == 20
{
    CRenderSceneViewImpl* m_impl;
    bool field_0x10;

public:
    // Wii U: 0x0226e4ac, PC: TODO
    CRenderSceneView(CRenderSceneViewImpl* impl, bool param_2);

    // Wii U: 0x0226e6f8, PC: TODO
    void AddRenderable(Renderable* renderable);
};
}
}
