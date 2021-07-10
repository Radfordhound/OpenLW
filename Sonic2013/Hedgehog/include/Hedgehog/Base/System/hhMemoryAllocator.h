#pragma once
#include "csl/fnd/memory.h"

// Wii U: 0x03698554, PC: TODO
void* __HH_ALLOC__(std::size_t size);

// Wii U: TODO, PC: TODO
void __HH_FREE__(void* ptr);

// Wii U: 0x03698724, PC: 0x00c1b230
void* __HH_ALLOCALIGN(std::size_t size, std::size_t alignment = 16);

namespace hh
{
class CMemoryAllocator
{
    // Wii U: TODO, PC: TODO
    static csl::fnd::IAllocator* cslAllocator;

    // TODO: Data Members

public:
    // TODO

    // Wii U: TODO, PC: TODO
    inline static csl::fnd::IAllocator* GetCSLAllocator()
    {
        return cslAllocator;
    }

    // Wii U: TODO, PC: TODO
    inline static void SetCSLAllocator(csl::fnd::IAllocator* allocator)
    {
        cslAllocator = allocator;
    }
};
}
