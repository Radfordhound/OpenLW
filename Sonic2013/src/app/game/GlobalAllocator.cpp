#include "GlobalAllocator.h"
#include "csl/fnd/DefaultAllocator.h" // TODO: REMOVE ME

namespace app
{
namespace game
{

static csl::fnd::DefaultAllocator defaultAllocator = csl::fnd::DefaultAllocator(); // TODO: REMOVE ME
static csl::fnd::IAllocator* Allocators[4] =
{
    &defaultAllocator, &defaultAllocator, &defaultAllocator, &defaultAllocator // TODO: REMOVE ME
};

csl::fnd::IAllocator* GlobalAllocator::GetAllocator(csl::fnd::AllocatorID type)
{
    return Allocators[static_cast<unsigned int>(type)];
}

void GlobalAllocator::SetAllocator(csl::fnd::AllocatorID type,
    csl::fnd::IAllocator* allocator)
{
    Allocators[static_cast<unsigned int>(type)] = allocator;
}
}
}
