// TODO: The name of this file is correct, but the path was guessed!
#include "pch.h"
#include "gfx_Renderable.h"

namespace app
{
namespace gfx
{
void RenderableEvent::Invoke(const hh::gfx::RenderEventParam* params)
{
    field_0x8->Render(params);
}
}
}
