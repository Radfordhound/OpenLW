#include "hhMemoryAllocator.h"
#include <cstdlib> // TODO: REMOVE ME

void* __HH_ALLOC__(std::size_t size)
{
    // If a CSL Allocator is set, allocate using that.
    csl::fnd::IAllocator* allocator = hh::CMemoryAllocator::GetCSLAllocator();
    if (allocator) return allocator->Alloc(size);

    // TODO: Do this properly instead
    return std::malloc(size);
}

void __HH_FREE__(void* ptr) noexcept
{
    // If a CSL Allocator is set, free using that.
    csl::fnd::IAllocator* allocator = hh::CMemoryAllocator::GetCSLAllocator();
    if (allocator)
    {
        allocator->Free(ptr);
        return;
    }
    
    // TODO: Do this properly instead
    std::free(ptr);
}

void* operator new(std::size_t size)
{
    return __HH_ALLOC__(size);
}

void operator delete(void* ptr) noexcept
{
    __HH_FREE__(ptr);
}

namespace hh
{
csl::fnd::IAllocator* CMemoryAllocator::cslAllocator = nullptr;
}
