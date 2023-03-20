#include "pch.h"
#include "Hedgehog/Base/System/hhMemoryAllocator.h"

using namespace csl::fnd;

CHedgehogMemoryAllocatorHeap hhBaseGetUserMemoryAllocator()
{
    // TODO
    return CHedgehogMemoryAllocatorHeap();
}

CHedgehogMemoryAllocatorHeap hhGetHeapHandle(unsigned int param_1)
{
    return hhBaseGetUserMemoryAllocator();
}

namespace hh
{
namespace base
{
IAllocator* CMemoryAllocator::Allocator = nullptr;

IAllocator* CMemoryAllocator::GetCSLAllocator()
{
    return Allocator;
}

void CMemoryAllocator::SetCSLAllocator(IAllocator* allocator)
{
    Allocator = allocator;
}
}
}
