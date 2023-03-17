// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include <csl/fnd/memory.h>

namespace app
{
enum AllocatorID // TODO: Does this belong in this header?
{
    ALLOCATOR_UNK_ZERO = 0,
    ALLOCATOR_UNK_ONE = 1,
    ALLOCATOR_UNK_TWO = 2,
    ALLOCATOR_DEBUG = 3
};

namespace game
{
class GlobalAllocator
{
    // Wii U: 0x10338d38, PC: TODO
    static csl::fnd::IAllocator* Allocators[4];

public:
    // Wii U: 0x02230294, PC: 0x004d0c90
    static csl::fnd::IAllocator* GetAllocator(AllocatorID allocID);

    // Wii U: 0x022302a8, PC: TODO
    static void SetAllocator(AllocatorID allocID,
        csl::fnd::IAllocator* allocator);
};
}
}
