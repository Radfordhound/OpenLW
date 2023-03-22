// TODO: The name of this file is correct, but the path was guessed!
#include "OpenLW/pch.h"
#include "GlobalAllocator.h"

namespace app
{
namespace game
{
static csl::fnd::DefaultAllocator defaultAllocator = csl::fnd::DefaultAllocator(); // TODO: REMOVE THIS

csl::fnd::IAllocator* GlobalAllocator::Allocators[4] =
{
    &defaultAllocator, &defaultAllocator, &defaultAllocator, &defaultAllocator // TODO: Use the correct allocators instead of this!
};

csl::fnd::IAllocator* GlobalAllocator::GetAllocator(AllocatorID allocID)
{
    return Allocators[allocID];
}

void GlobalAllocator::SetAllocator(AllocatorID allocID,
    csl::fnd::IAllocator* allocator)
{
    Allocators[allocID] = allocator;
}
}
}
