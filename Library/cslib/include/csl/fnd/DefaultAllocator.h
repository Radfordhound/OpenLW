#pragma once
#include "IAllocator.h"

namespace csl
{
namespace fnd
{
struct DefaultAllocator : IAllocator
{
    /* <b>Wii U: [Inlined], PC: 0x00445a30</b> */
    inline void* Alloc(std::size_t size, int alignment = 16) override
    {
        return (size) ? ::operator new(size) : nullptr;
    }

    /* <b>Wii U: [Inlined], PC: 0x00445a50</b> */
    inline void Free(void* ptr) override
    {
        ::operator delete(ptr);
    }
};
}
}
