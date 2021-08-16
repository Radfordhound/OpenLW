#pragma once
#include "Renderable.h"
#include "../fnd/ReferencedObject.h"

namespace app
{
namespace gfx
{
struct RenderableContainer : public fnd::ReferencedObject // size == 28
{
    csl::ut::LinkList<Renderable> Renderables;

    // Wii U: 0x02256d28, PC: TODO
    RenderableContainer();

    // Wii U: 0x02256d7c, PC: TODO
    static RenderableContainer* Create(csl::fnd::IAllocator* allocator);

    // Wii U: 0x02256e98, PC: TODO
    ~RenderableContainer();

    // Wii U: 0x02256fec, PC: TODO
    void AddObject(Renderable* obj);

    // Wii U: 0x02257040, PC: TODO
    void RemoveObject(Renderable* obj);
};
}
}
