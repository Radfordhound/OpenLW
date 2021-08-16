#pragma once
#include <Hedgehog/Graphics/hhRenderEvent.h>

namespace app
{
namespace gfx
{
struct Renderable;

struct RenderableEvent : public hh::gfx::RenderEvent // sizeof == 12
{
    unsigned char field_0x4;
    Renderable* field_0x8;

    // Wii U: 0x02255db8, PC: TODO
    virtual void Invoke(const hh::gfx::RenderEventParam* params);
};
}
}
