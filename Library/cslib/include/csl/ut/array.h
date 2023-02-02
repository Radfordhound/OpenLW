#pragma once
#include "number.h"
#include "../fnd/memory.h"
#include <new>
#include <iterator>
#include <algorithm>
#include <cstring>

namespace csl
{
namespace ut
{
template<typename T>
class MoveArray
{
protected:
    T* m_data;
    std::size_t m_count;
    std::size_t m_flags;
    fnd::IAllocator* m_allocator;

    MoveArray(T* data, std::size_t count,
        std::size_t capacityAndFlags,
        fnd::IAllocator* allocator) :
        m_data(data),
        m_count(count),
        m_flags(capacityAndFlags),
        m_allocator(allocator) {}

public:
    typedef T value_type;
    typedef fnd::IAllocator allocator_type; // TODO: Is this correct?
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef const T* const_iterator;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef pointer iterator;
    typedef const_pointer const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    inline bool empty() const
    {
        return (m_count == 0);
    }

    inline std::size_t size() const
    {
        return m_count;
    }

    inline std::size_t capacity() const
    {
        return (m_flags & ~CSL_HIGH_BITMASK(m_flags));
    }

    T& back()
    {
        return m_data[m_count - 1];
    }

    T& at(std::size_t index)
    {
        return (index >= m_count) ? *m_data : m_data[index];
    }

    inline const_iterator begin() const
    {
        return m_data;
    }

    inline iterator begin()
    {
        return m_data;
    }

    inline const_iterator end() const
    {
        return (m_data + m_count);
    }

    inline iterator end()
    {
        return (m_data + m_count);
    }

    inline reverse_iterator rbegin()
    {
        return reverse_iterator(m_data + m_count);
    }

    inline const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator(m_data + m_count);
    }

    inline reverse_iterator rend()
    {
        return reverse_iterator(m_data);
    }

    inline const_reverse_iterator rend() const
    {
        return const_reverse_iterator(m_data);
    }

    T* AllocateMemory(std::size_t count)
    {
        return (count) ? static_cast<T*>(m_allocator->Alloc(sizeof(T) * count)) : nullptr;
    }

    void reserve(std::size_t capacity)
    {
        if (this->capacity() < capacity)
        {
            // Allocate a new buffer of the given size.
            T* newData = AllocateMemory(capacity);
            if (!empty())
            {
                std::memcpy(newData, m_data, m_count);
            }

            // Free the old buffer if necessary.
            if ((CSL_HIGH_BIT(m_flags) == 0) && m_allocator && m_data)
            {
                m_allocator->Free(m_data);
            }

            // Set the new data pointer and capacity.
            m_data = newData;
            m_flags = capacity;
        }
    }

    void resize(std::size_t count)
    {
        reserve(count);
        m_count = count;
    }

    inline void resize_unchecked(std::size_t count)
    {
        m_count = count;
    }

    inline void pop_back()
    {
        --m_count;
    }

    void push_back(const T& value)
    {
        std::size_t cap = capacity();
        if (m_count > cap)
        {
            reserve((cap) ? cap * 2 : 1);
        }

        m_data[m_count++] = value;
    }

    void push_back_unchecked(const T& value)
    {
        m_data[m_count++] = value;
    }

    void clear()
    {
        if (!m_count) m_count = 0;
    }

    template<typename it_t>
    it_t erase(it_t pos)
    {
        --m_count;
        for (it_t it = pos; it != (m_data + m_count); ++it)
        {
            *it = *(it + 1);
        }

        return pos;
    }

    template<typename it_t>
    void erase_unstable(it_t pos)
    {
        if (pos != (m_data + --m_count))
        {
            *pos = m_data[m_count];
        }
    }

    void Reset(void* newData, std::size_t newCount, std::size_t newCapacity,
        fnd::IAllocator* newAllocator, bool noFree)
    {
        if ((CSL_HIGH_BIT(m_flags) == 0) && m_allocator && m_data)
        {
            m_allocator->Free(m_data);
        }

        m_data = static_cast<T*>(newData);
        m_count = newCount;

        if (noFree)
        {
            newCapacity |= CSL_HIGH_BITMASK(m_flags);
        }

        m_flags = newCapacity;
        m_allocator = newAllocator;
    }

    void swap(MoveArray<T>& other)
    {
        if (&other != this)
        {
            std::size_t tmpCount = m_count;
            std::size_t tmpFlags = m_flags;
            fnd::IAllocator* tmpAllocator = m_allocator;
            T* tmpData = m_data;

            m_count = other.m_count;
            m_flags = other.m_flags;
            m_allocator = other.m_allocator;
            m_data = other.m_data;

            other.m_count = tmpCount;
            other.m_flags = tmpFlags;
            other.m_allocator = tmpAllocator;
            other.m_data = tmpData;
        }
    }

    inline const T& operator[] (std::size_t index) const
    {
        return m_data[index];
    }

    inline T& operator[] (std::size_t index)
    {
        return m_data[index];
    }

    MoveArray() :
        m_data(nullptr),
        m_count(0),
        m_flags(0),
        m_allocator(nullptr) {}

    MoveArray(fnd::IAllocator* allocator) :
        m_data(nullptr),
        m_count(0),
        m_flags(0),
        m_allocator(allocator) {}

    MoveArray(std::size_t initialCapacity, fnd::IAllocator* allocator) :
        m_data(nullptr),
        m_count(0),
        m_flags(0),
        m_allocator(allocator)
    {
        m_data = AllocateMemory(initialCapacity);
        m_flags = initialCapacity;
    }

    ~MoveArray()
    {
        if ((CSL_HIGH_BIT(m_flags) == 0) && m_allocator && m_data)
        {
            m_allocator->Free(m_data);
        }
    }
};

template<typename T, std::size_t bufferSize>
class InplaceMoveArray : public MoveArray<T>
{
    T m_buffer[bufferSize];

public:
    // TODO

    InplaceMoveArray(std::size_t count = 0) :
        MoveArray<T>(m_buffer, count, bufferSize, nullptr) {}
};

template<typename T>
class ObjectMoveArray
{
protected:
    T* m_data;
    std::size_t m_count;
    std::size_t m_flags;
    fnd::IAllocator* m_allocator;

    ObjectMoveArray(T* data, std::size_t count,
        std::size_t capacityAndFlags, fnd::IAllocator* allocator) :
        m_data(data),
        m_count(count),
        m_flags(capacityAndFlags),
        m_allocator(allocator) {}

public:
    typedef T value_type;
    typedef fnd::IAllocator allocator_type; // TODO: Is this correct?
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef const T* const_iterator;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef pointer iterator;
    typedef const_pointer const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    inline bool empty() const
    {
        return (m_count == 0);
    }

    inline std::size_t size() const
    {
        return m_count;
    }

    inline std::size_t capacity() const
    {
        return (m_flags & ~CSL_HIGH_BITMASK(m_flags));
    }

    inline const_iterator begin() const
    {
        return m_data;
    }

    inline iterator begin()
    {
        return m_data;
    }

    inline const_iterator end() const
    {
        return (m_data + m_count);
    }

    inline iterator end()
    {
        return (m_data + m_count);
    }

    /*inline reverse_iterator rbegin()
    {
        return reverse_iterator(m_data + m_count);
    }

    inline const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator(m_data + m_count);
    }

    inline reverse_iterator rend()
    {
        return reverse_iterator(m_data);
    }

    inline const_reverse_iterator rend() const
    {
        return const_reverse_iterator(m_data);
    }*/

    T* AllocateMemory(std::size_t count)
    {
        return (count) ? static_cast<T*>(m_allocator->Alloc(sizeof(T) * count)) : nullptr;
    }

    void reserve(std::size_t capacity)
    {
        if (this->capacity() < capacity)
        {
            // Allocate a new buffer of the given size.
            T* newData = AllocateMemory(capacity);
            if (!empty())
            {
                std::memcpy(newData, m_data, m_count);
            }

            // Free the old buffer if necessary.
            if ((CSL_HIGH_BIT(m_flags) == 0) && m_allocator && m_data)
            {
                m_allocator->Free(m_data);
            }

            // Set the new data pointer and capacity.
            m_data = newData;
            m_flags = capacity;
        }
    }

    void resize(std::size_t count)
    {
        if (count < m_count)
        {
            for (std::size_t i = 0; i < m_count; ++i)
            {
                m_data[i].~T();
            }
        }
        else
        {
            reserve(count);

            for (std::size_t i = 0; i < m_count; ++i)
            {
                new (m_data + i) T();
            }
        }

        m_count = count;
    }

    //inline void resize_unchecked(std::size_t count)
    //{
    //    m_count = count;
    //}

    inline void pop_back()
    {
        m_data[--m_count].~T();
    }

    void push_back_unchecked(const T& value)
    {
        new (m_data + m_count++) T(value);
    }

    //void push_back(const T& value)
    //{
    //    std::size_t cap = capacity();
    //    if (m_count > cap)
    //    {
    //        reserve((cap) ? cap * 2 : 1);
    //    }

    //    m_data[m_count++] = value;
    //}

    void clear()
    {
        if (!empty())
        {
            for (iterator it = begin(); it != end(); ++it)
            {
                it->~T();
                --m_count;
            }

            m_count = 0;
        }
    }

    bool erase_find(const T& val)
    {
        T* ptr = std::remove(m_data, m_data + m_count, val);
        if (ptr == (m_data + m_count))
        {
            return false;
        }

        while (ptr != (m_data + m_count))
        {
            ptr->~T();

            ++ptr;
            --m_count;
        }
        
        return true;
    }

    inline const T& operator[] (std::size_t index) const
    {
        return m_data[index];
    }

    inline T& operator[] (std::size_t index)
    {
        return m_data[index];
    }

    /*ObjectMoveArray() :
        m_data(nullptr),
        m_count(0),
        m_flags(0),
        m_allocator(nullptr) {}

    ObjectMoveArray(fnd::IAllocator* allocator) :
        m_data(nullptr),
        m_count(0),
        m_flags(0),
        m_allocator(allocator) {}*/

    ObjectMoveArray(std::size_t initialCapacity, fnd::IAllocator* allocator) :
        m_data(nullptr),
        m_count(0),
        m_flags(0),
        m_allocator(allocator)
    {
        m_data = AllocateMemory(initialCapacity);
        m_flags = initialCapacity;
    }

    ~ObjectMoveArray()
    {
        clear();

        if ((CSL_HIGH_BIT(m_flags) == 0) && m_allocator && m_data)
        {
            m_allocator->Free(m_data);
        }
    }
};
}
}
