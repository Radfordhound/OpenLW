#include "pch.h"
#include "Hedgehog/Graphics/Resource/hhResMapChannelFixed.h"

namespace hh
{
namespace gfx
{
namespace res
{
ResName ResMapChannelFixed::GetSlotName()
{
    return ResName(&ptr()->SlotName);
}
}
}
}
