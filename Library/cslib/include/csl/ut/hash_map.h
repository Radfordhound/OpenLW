// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "../fnd/memory.h"
#include "number.h"
#include <climits>

namespace csl
{
namespace ut
{
template<typename OP>
class HashMap
{
OPENLW_PROTECTED
    struct Elem
    {
        std::size_t Hash;
        std::size_t Key;
        std::size_t Value;
    };

    Elem* m_data;
    std::size_t m_count;
    std::size_t m_capacityAndFlags;
    std::size_t m_maxCapacity;
    fnd::IAllocator* m_allocator;
    OP m_op;

    Elem* AllocateMemory(std::size_t count)
    {
        return static_cast<Elem*>(m_allocator->Alloc(sizeof(Elem) * count));
    }

    void ReleaseMemory()
    {
        if (CSL_HIGH_BIT(m_capacityAndFlags) == 0 && m_allocator && m_data)
        {
            m_allocator->Free(m_data);
        }
    }

    std::size_t CalcResize(std::size_t requiredCapacity)
    {
        std::size_t newCapacity = 16;
        while (newCapacity < requiredCapacity)
        {
            newCapacity *= 2;
        }

        return (newCapacity < 16) ? 16 : newCapacity;
    }

public:
    class iterator
    {
        const HashMap<OP>* m_hashMapPtr;
        std::size_t m_index;

    public:
        friend std::size_t HashMap<OP>::GetValue(iterator it) const;

        friend bool operator==(iterator it1, iterator it2)
        {
            return (it1.m_index == it2.m_index);
        }

        friend bool operator!=(iterator it1, iterator it2)
        {
            return !(it1 == it2);
        }

        iterator(const HashMap<OP>* hashMapPtr, std::size_t index) :
            m_hashMapPtr(hashMapPtr),
            m_index(index) {}
    };

    // TODO

    std::size_t GetSize() const
    {
        return m_count;
    }

    std::size_t GetCapacity() const
    {
        return (m_capacityAndFlags & ~CSL_HIGH_BITMASK(m_capacityAndFlags));
    }

    std::size_t GetValue(iterator it) const
    {
        return m_data[it.m_index].Value;
    }

    bool empty() const
    {
        return (GetSize() == 0);
    }

    iterator GetBegin() const
    {
        if (!m_data)
        {
            return GetEnd();
        }

        std::size_t i;
        for (i = 0; i < m_maxCapacity; ++i)
        {
            if (m_data[i].Hash != SIZE_MAX) break;
        }
        
        return iterator(this, i);
    }

    iterator GetEnd() const
    {
        return iterator(this, m_maxCapacity + 1);
    }

    void ResizeTbl(std::size_t count)
    {
        Elem* oldData = m_data;
        std::size_t oldCapacity = GetCapacity();
        std::size_t oldCapacityAndFlags = m_capacityAndFlags;

        m_data = AllocateMemory(count);
        std::memset(m_data, 0xFF, sizeof(Elem) * count);

        m_count = 0;
        m_capacityAndFlags = count;
        m_maxCapacity = (count - 1);

        if (oldData)
        {
            for (std::size_t i = 0; i < oldCapacity; ++i)
            {
                if (oldData[i].Hash != SIZE_MAX)
                {
                    Insert(oldData[i].Key, oldData[i].Value);
                }
            }
        }

        if (CSL_HIGH_BIT(oldCapacityAndFlags) == 0 && m_allocator && oldData)
        {
            m_allocator->Free(oldData);
        }
    }

    void Reserve(std::size_t capacity)
    {
        std::size_t newCapacity = CalcResize(capacity);
        if (GetCapacity() < newCapacity)
        {
            ResizeTbl(newCapacity);
        }
    }

    iterator Find(std::size_t key) const
    {
        if (m_data)
        {
            std::size_t hash = m_op.hash(key);

            for (std::size_t i = (hash & m_maxCapacity);
                m_data[i].Hash != SIZE_MAX;
                i = ((i + 1) & m_maxCapacity))
            {
                if (m_data[i].Hash == hash && m_op.equal(key, m_data[i].Key))
                {
                    return iterator(this, i);
                }
            }
        }

        return GetEnd();
    }

    void Insert(std::size_t key, std::size_t value)
    {
        std::size_t hash = m_op.hash(key);
        if (m_count == 0 && GetCapacity() == 0)
        {
            ResizeTbl(16);
        }
        else if (GetCapacity() <= (m_count << 1))
        {
            ResizeTbl(GetCapacity() << 1);
        }

        std::size_t i;
        for (i = (hash & m_maxCapacity);
            m_data[i].Hash != SIZE_MAX;
            i = ((i + 1) & m_maxCapacity))
        {
            if (m_data[i].Hash == hash && m_op.equal(key, m_data[i].Key))
            {
                m_data[i].Hash = hash;
                m_data[i].Key = key;
                m_data[i].Value = value;
                return;
            }
        }

        // Add element to end.
        ++m_count;
        m_data[i].Hash = hash;
        m_data[i].Key = key;
        m_data[i].Value = value;
    }

    void Erase(iterator it)
    {
        // TODO
    }

    void Clear()
    {
        if (m_maxCapacity != SIZE_MAX)
        {
            for (std::size_t i = 0; i < (m_maxCapacity + 1); ++i)
            {
                m_data[i].Hash = SIZE_MAX;
            }
        }

        m_count = 0;
    }

    void Reset(void* param_1, std::size_t param_2, fnd::IAllocator* allocator)
    {
        ReleaseMemory();

        // TODO
    }

    HashMap() :
        m_data(nullptr),
        m_count(0),
        m_capacityAndFlags(0),
        m_maxCapacity(0),
        m_allocator(nullptr) {}

    HashMap(std::size_t initialCapacity, fnd::IAllocator* allocator) :
        m_count(0),
        m_capacityAndFlags(CalcResize(initialCapacity)),
        m_maxCapacity(m_capacityAndFlags - 1),
        m_allocator(allocator)
    {
        m_data = AllocateMemory(m_capacityAndFlags);
        std::memset(m_data, 0xFF, sizeof(Elem) * m_capacityAndFlags);
    }

    ~HashMap()
    {
        ReleaseMemory();
    }
};
} // ut
} // csl
