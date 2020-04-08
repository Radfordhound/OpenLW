#pragma once
#include "csl/fnd/IAllocator.h"

/* <b>Wii U: 0x03698554, PC: TODO</b> */
void* __HH_ALLOC__(std::size_t size);

/* <b>Wii U: TODO, PC: TODO</b> */
void __HH_FREE__(void* ptr) noexcept;

namespace hh
{
class CMemoryAllocator
{
    static csl::fnd::IAllocator* cslAllocator;

    // TODO: Data Members

public:
    // TODO

    /* <b>Wii U: TODO, PC: TODO</b> */
    inline static csl::fnd::IAllocator* GetCSLAllocator() noexcept
    {
        return cslAllocator;
    }

    /* <b>Wii U: TODO, PC: TODO</b> */
    inline static void SetCSLAllocator(csl::fnd::IAllocator* allocator) noexcept
    {
        cslAllocator = allocator;
    }
};
}
