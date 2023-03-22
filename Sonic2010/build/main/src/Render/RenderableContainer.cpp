// TODO: The name of this file is correct, but the path was guessed!
#include "OpenLW/pch.h"
#include "RenderableContainer.h"

namespace app
{
namespace gfx
{
RenderableContainer::RenderableContainer()
{
    Renderables.init(offsetof(Renderable, Node));
}

RenderableContainer* RenderableContainer::Create(csl::fnd::IAllocator* allocator)
{
    return new (allocator) RenderableContainer();
}

RenderableContainer::~RenderableContainer()
{
    for (auto it = Renderables.begin(); it != Renderables.end(); ++it)
    {
        it->Container = nullptr;
    }
}

void RenderableContainer::AddObject(Renderable* obj)
{
    obj->Container = this;
    Renderables.push_back(obj);
}

void RenderableContainer::RemoveObject(Renderable* obj)
{
    Renderables.erase(obj);
}
}
}
