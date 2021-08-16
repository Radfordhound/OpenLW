#include "Hedgehog/Base/System/hhMemory.h"
#include "Hedgehog/Base/System/hhMemoryAllocator.h"
#include <cstdlib> // TODO: REMOVE THIS LINE

using namespace csl::fnd;
using namespace hh::base;

void __HH_FREE(void* ptr)
{
    // If a CSL Allocator is set, free using that.
    IAllocator* allocator = CMemoryAllocator::GetCSLAllocator();
    if (allocator)
    {
        allocator->Free(ptr);
        return;
    }

    // TODO: Do this properly instead
    std::free(ptr);
}

void* __HH_ALLOC(std::size_t size)
{
    // If a CSL Allocator is set, allocate using that.
    IAllocator* allocator = CMemoryAllocator::GetCSLAllocator();
    if (allocator) return allocator->Alloc(size);

    // TODO: Do this properly instead
    return std::malloc(size);
}

void* __HH_ALLOC(std::size_t size, const CHedgehogMemoryAllocatorFileLine& fileLineInfo)
{
    // If a CSL Allocator is set, allocate using that.
    IAllocator* allocator = CMemoryAllocator::GetCSLAllocator();
    if (allocator) return allocator->Alloc(size);

    // TODO: Do this properly instead
    return std::malloc(size);
}

void* __HH_ALLOC(std::size_t size, const CHedgehogMemoryAllocatorFileLine& fileLineInfo,
    CHedgehogMemoryAllocatorHeap heap)
{
    // If a CSL Allocator is set, allocate using that.
    IAllocator* allocator = CMemoryAllocator::GetCSLAllocator();
    if (allocator) return allocator->Alloc(size);

    // TODO: Do this properly instead
    return std::malloc(size);
}

void* __HH_ALLOCALIGN(std::size_t size, std::size_t alignment)
{
    // If a CSL Allocator is set, allocate using that.
    IAllocator* allocator = CMemoryAllocator::GetCSLAllocator();
    if (allocator) return allocator->Alloc(size, alignment);

    // TODO: Do this properly instead
    return _aligned_malloc(size, alignment);
}

void* operator new(std::size_t size)
{
    return __HH_ALLOC(size);
}

void operator delete(void* ptr)
{
    __HH_FREE(ptr);
}
