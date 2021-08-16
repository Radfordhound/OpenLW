#include "Renderable.h"

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
