#pragma once
#include "../fnd/IAllocator.h"

namespace csl
{
namespace ut
{
template<typename T>
class MoveArray
{
    void* data = nullptr;
    std::size_t count = 0;
    std::size_t capacity = 0;
    fnd::IAllocator* allocator = nullptr;
    
public:
    inline MoveArray() = default;
    inline MoveArray(std::size_t capacity, fnd::IAllocator* allocator) :
        allocator(allocator), data(), capacity(capacity) {}

    inline ~MoveArray()
    {
        // TODO: What's actually going on with this bitwise and?? This isn't 64-bit compatible!!
        if ((capacity & 0x80000000) == 0 && allocator && data)
        {
            allocator->Free(data);
        }
        // TODO
    }

    inline void* AllocateMemory(std::size_t count)
    {
        return (count) ? allocator->Alloc(count * sizeof(T)) : nullptr;
    }

    // TODO
};
}
}
