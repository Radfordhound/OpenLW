#pragma once
#include "hhMemory.h"
#include <csl/fnd/memory.h>

// Wii U: 0x03698a70, PC: TODO
CHedgehogMemoryAllocatorHeap hhBaseGetUserMemoryAllocator(); // TODO: Is this return type correct?

// Wii U: 0x03698ae8, PC: TODO
CHedgehogMemoryAllocatorHeap hhGetHeapHandle(unsigned int param_1);

namespace hh
{
namespace base
{
class CMemoryAllocator
{
    // Wii U: 0x1031f2c0, PC: TODO
    static csl::fnd::IAllocator* Allocator;

public:
    // Wii U: 0x03698b1c, PC: TODO
    static csl::fnd::IAllocator* GetCSLAllocator();

    // Wii U: 0x03698b10, PC: TODO
    static void SetCSLAllocator(csl::fnd::IAllocator* allocator);
};
}
}
