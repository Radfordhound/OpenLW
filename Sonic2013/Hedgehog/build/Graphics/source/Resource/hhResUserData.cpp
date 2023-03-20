#include "pch.h"
#include "Hedgehog/Graphics/Resource/hhResUserData.h"

namespace hh
{
namespace gfx
{
namespace res
{
std::size_t ResUserData::GetNumResUserDataItems() const
{
    return ptr()->ItemCount;
}

ResUserDataItem ResUserData::GetResUserDataItem(std::size_t index)
{
    return ResUserDataItem((index < GetNumResUserDataItems()) ?
        &ptr()->Items[index] : nullptr);
}
}
}
}

