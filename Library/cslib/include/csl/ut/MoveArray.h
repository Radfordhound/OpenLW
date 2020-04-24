#pragma once
#include "../fnd/IAllocator.h"
#include <cstring>
#include <iterator>

namespace csl
{
namespace ut
{
template<typename T>
class MoveArray
{
    T* data = nullptr;
    std::size_t count = 0;
    std::size_t capacityAndFlags = 0;
    fnd::IAllocator* allocator = nullptr;

    constexpr static std::size_t CapacityBitCount = (sizeof(capacityAndFlags) << 3);
    constexpr static std::size_t NoFreeFlag = (1 << (CapacityBitCount - 1));
    constexpr static std::size_t CapacityMask = ~NoFreeFlag;
    
    inline T* AllocateMemory(std::size_t count)
    {
        return (count) ? static_cast<T*>(allocator->Alloc(sizeof(T) * count)) : nullptr;
    }

    inline std::size_t dontFree() const noexcept
    {
        return (capacityAndFlags & NoFreeFlag);
    }

public:
    using const_iterator = const T*;
    using iterator = T*;
    using reverse_iterator = std::reverse_iterator<T*>;
    using const_reverse_iterator = const std::reverse_iterator<T*>;

    inline MoveArray() = default;
    inline MoveArray(fnd::IAllocator* allocator) : allocator(allocator) {}

    inline MoveArray(std::size_t capacity, fnd::IAllocator* allocator) :
        allocator(allocator)
    {
        data = AllocateMemory(capacity);
        capacityAndFlags = capacity;
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

    inline std::size_t capacity() const noexcept
    {
        return (capacityAndFlags & CapacityMask);
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
            capacityAndFlags = count;
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

    inline reverse_iterator rbegin() noexcept
    {
        return data + count;
    }

    inline const_reverse_iterator rbegin() const noexcept
    {
        return data + count;
    }

    inline reverse_iterator rend() noexcept
    {
        return data;
    }

    inline const_reverse_iterator rend() const noexcept
    {
        return data;
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

    inline void erase_unstable(const_iterator pos)
    {
        if (pos == (data + --count)) return;
        *pos = data[count];
    }

    inline void swap(MoveArray<T>& other)
    {
        if (&other != this)
        {
            std::size_t tmpCount = count;
            std::size_t tmpCapacity = capacityAndFlags;
            fnd::IAllocator* tmpAllocator = allocator;
            T* tmpData = data;

            count = other.count;
            capacityAndFlags = other.tmpCapacity;
            allocator = other.allocator;
            data = other.data;

            other.count = tmpCount;
            other.tmpCapacity = tmpCapacity;
            other.allocator = tmpAllocator;
            other.data = tmpData;
        }
    }
};
}
}
