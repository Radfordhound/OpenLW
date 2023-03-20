// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "gfx_Renderable.h"
#include "System/ReferencedObject.h"

namespace app
{
namespace gfx
{
struct RenderableContainer : public fnd::ReferencedObject // size == 28
{
    csl::ut::LinkList<Renderable> Renderables;

    LWAPI(0x02256d28, TODO)
    RenderableContainer();

    LWAPI(0x02256d7c, TODO)
    static RenderableContainer* Create(csl::fnd::IAllocator* allocator);

    LWAPI(0x02256e98, TODO)
    ~RenderableContainer();

    LWAPI(0x02256fec, TODO)
    void AddObject(Renderable* obj);

    LWAPI(0x02257040, TODO)
    void RemoveObject(Renderable* obj);
};
}
}
