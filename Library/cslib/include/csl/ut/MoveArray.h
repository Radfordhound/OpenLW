#pragma once
#include "../fnd/IAllocator.h"
#include <cstring>

namespace csl
{
namespace ut
{
template<typename T>
class MoveArray
{
    T* data = nullptr;
    std::size_t count = 0;
    std::size_t meta = 0;
    fnd::IAllocator* allocator = nullptr;

    constexpr static std::size_t metaBitCount = (sizeof(std::size_t) << 3);
    constexpr static std::size_t metaNoFreeFlag = (1 << (metaBitCount - 1));
    constexpr static std::size_t metaCapacityMask = ~metaNoFreeFlag;
    
    inline T* AllocateMemory(std::size_t count)
    {
        return (count) ? static_cast<T*>(allocator->Alloc(sizeof(T) * count)) : nullptr;
    }

    inline std::size_t capacity() const noexcept
    {
        return (meta & metaCapacityMask);
    }

    inline std::size_t dontFree() const noexcept
    {
        return (meta & metaNoFreeFlag);
    }

public:
    using const_iterator = const T*;
    using iterator = T*;

    inline MoveArray() = default;
    inline MoveArray(fnd::IAllocator* allocator) : allocator(allocator) {}

    inline MoveArray(std::size_t capacity, fnd::IAllocator* allocator) :
        allocator(allocator)
    {
        data = AllocateMemory(capacity);
        meta = capacity;
    }

    inline ~MoveArray()
    {
        if (!dontFree() && allocator && data)
        {
            allocator->Free(data);
        }
    }

    inline bool empty() const noexcept
    {
        return (count == 0);
    }

    inline std::size_t size() const noexcept
    {
        return count;
    }

    inline void clear()
    {
        if (!count) count = 0;
    }

    inline void reserve(std::size_t count)
    {
        if (capacity() < this->count)
        {
            T* buf = AllocateMemory(count);
            if (this->count)
            {
                std::memcpy(buf, data, count * sizeof(T));
            }

            if (!dontFree() && allocator && data)
            {
                allocator->Free(data);
            }

            data = buf;
            meta = count;
        }
    }

    inline void resize(std::size_t count)
    {
        reserve(count);
        this->count = count;
    }

    inline void resize_unchecked(std::size_t count)
    {
        this->count = count;
    }

    inline void pop_back()
    {
        --count;
    }

    inline void push_back(const T& value)
    {
        std::size_t cap = capacity();
        if (count > cap)
        {
            reserve((cap) ? cap * 2 : 1);
        }

        data[count++] = value;
    }

    inline void push_back_unchecked(const T& value)
    {
        data[count++] = value;
    }

    inline const_iterator begin() const
    {
        return data;
    }

    inline iterator begin()
    {
        return data;
    }

    inline const_iterator end() const
    {
        return data + count;
    }

    inline iterator end()
    {
        return data + count;
    }

    inline iterator erase(const_iterator pos)
    {
        --count;
        for (iterator it = const_cast<iterator>(pos); it != (data + count); ++it)
        {
            *it = it[1];
        }

        return const_cast<iterator>(pos);
    }
};
}
}
