#pragma once
#include "hhMemory.h"
#include <csl/fnd/memory.h>

LWAPI(0x03698a70, TODO)
CHedgehogMemoryAllocatorHeap hhBaseGetUserMemoryAllocator(); // TODO: Is this return type correct?

LWAPI(0x03698ae8, TODO)
CHedgehogMemoryAllocatorHeap hhGetHeapHandle(unsigned int param_1);

namespace hh
{
namespace base
{
class CMemoryAllocator
{
    LWAPI(0x1031f2c0, TODO)
    static csl::fnd::IAllocator* Allocator;

public:
    LWAPI(0x03698b1c, TODO)
    static csl::fnd::IAllocator* GetCSLAllocator();

    LWAPI(0x03698b10, TODO)
    static void SetCSLAllocator(csl::fnd::IAllocator* allocator);
};
}
}
