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
LWAPI_PRIVATE
    LWAPI(0x10338d38, 0x00fd7c34)
    static csl::fnd::IAllocator* Allocators[4];

public:
    LWAPI(0x02230294, 0x004d0c90)
    static csl::fnd::IAllocator* GetAllocator(AllocatorID allocID);

    LWAPI(0x022302a8, 0x004d0ca0)
    static void SetAllocator(AllocatorID allocID,
        csl::fnd::IAllocator* allocator);
};
}
}
