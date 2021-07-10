#include "Hedgehog/Base/System/hhMemoryAllocator.h"
#include <cstdlib> // TODO: REMOVE ME

void* __HH_ALLOC__(std::size_t size)
{
    // If a CSL Allocator is set, allocate using that.
    csl::fnd::IAllocator* allocator = hh::CMemoryAllocator::GetCSLAllocator();
    if (allocator) return allocator->Alloc(size);

    // TODO: Do this properly instead
    return std::malloc(size);
}

void __HH_FREE__(void* ptr)
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

void* __HH_ALLOCALIGN(std::size_t size, std::size_t alignment)
{
    // If a CSL Allocator is set, allocate using that.
    csl::fnd::IAllocator* allocator = hh::CMemoryAllocator::GetCSLAllocator();
    if (allocator) return allocator->Alloc(size, alignment);

    // TODO: Do this properly instead
    return _aligned_malloc(size, alignment);
}

void* operator new(std::size_t size)
{
    return __HH_ALLOC__(size);
}

void operator delete(void* ptr)
{
    __HH_FREE__(ptr);
}

namespace hh
{
csl::fnd::IAllocator* CMemoryAllocator::cslAllocator = nullptr;
}
