#pragma once
#include <cstdint>
#include <cstring>

namespace Extra
{
namespace fx
{
struct SStackAllocator
{
    void* field_0x0;
    void* Top;
    // TODO: Other data members?

    void* AllocateMemory(std::size_t size, std::size_t alignment = 16)
    {
        // Get an address to the top of the stack that's aligned as requested.
        std::uintptr_t topAddr = reinterpret_cast<std::uintptr_t>(Top);
        std::uintptr_t alignedMemAddr = ((topAddr +
            (alignment - 1)) & ~(alignment - 1));

        // Fill the requested stack memory with zero bytes, 128 bytes at a time.
        std::uintptr_t newTopAddr = (alignedMemAddr + size);
        std::uintptr_t uVar2 = (topAddr + 0x7FU & 0xffffff80);

        while (uVar2 != (newTopAddr + 0x7FU & 0xffffff80))
        {
            std::memset(reinterpret_cast<void*>(uVar2), 0, 128);
            uVar2 += 128;
        }

        // Set the new top pointer and return the requested stack memory.
        Top = reinterpret_cast<void*>(newTopAddr);
        return reinterpret_cast<void*>(alignedMemAddr);
    }
};
}
}
