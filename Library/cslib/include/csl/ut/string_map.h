#pragma once
#include "hash_map.h"
#include <cstring>

namespace csl
{
namespace ut
{
struct StringMapOperation
{
    // TODO: Are there any data members?

public:
    // Wii U: 0x02ca8778, PC: TODO
    std::size_t hash(std::size_t key) const
    {
        const char* keyStr = reinterpret_cast<const char*>(key);
        std::size_t hashResult = 0;

        for (std::size_t i = 0; keyStr[i] != '\0'; ++i)
        {
            hashResult = ((hashResult * 31) + static_cast<std::size_t>(keyStr[i]));
        }

        return (hashResult & ~CSL_HIGH_BITMASK(std::size_t));
    }

    // TODO: Is this function actually a thing?
    inline bool equal(size_t key1, size_t key2) const
    {
        return (std::strcmp(
            reinterpret_cast<const char*>(key1),
            reinterpret_cast<const char*>(key2)) == 0);
    }
};

template<typename T>
class StringMap : public HashMap<StringMapOperation>
{
    // TODO: Any data members?

public:
    class iterator : public HashMap<StringMapOperation>::iterator
    {
        //HashMap<StringMapOperation>::iterator m_impl;

    public:
        friend bool operator==(iterator it1, iterator it2)
        {
            HashMap<StringMapOperation>::iterator baseIt1 = it1;
            HashMap<StringMapOperation>::iterator baseIt2 = it2;
            return (baseIt1 == baseIt2);

            //return (it1.m_impl == it2.m_impl);
        }

        friend bool operator!=(iterator it1, iterator it2)
        {
            return !(it1 == it2);
        }

        // TODO: Is this actually a thing?
        inline iterator(HashMap<StringMapOperation>::iterator other) :
            HashMap<StringMapOperation>::iterator(other) {}
    };

    class const_iterator
    {
        HashMap<StringMapOperation>::iterator m_impl;

    public:
        friend bool operator==(const_iterator it1, const_iterator it2)
        {
            return (it1.m_impl == it2.m_impl);
        }

        friend bool operator!=(const_iterator it1, const_iterator it2)
        {
            return !(it1 == it2);
        }

        const_iterator(iterator it) : m_impl(it) {}
    };
    
    const std::size_t PtrCast(const char* key) const
    {
        return reinterpret_cast<const std::size_t>(key);
    }

    T GetValue(iterator it) const
    {
        return reinterpret_cast<T>(HashMap<StringMapOperation>::GetValue(it));
    }

    const_iterator end() const
    {
        return GetEnd();
    }

    iterator end()
    {
        return GetEnd();
    }

    void reserve(std::size_t capacity)
    {
        Reserve(capacity);
    }

    iterator find(const char* key) const
    {
        return Find(PtrCast(key));
    }

    void insert(const char* key, T val)
    {
        Insert(PtrCast(key), (std::size_t)val);
    }

    void erase(iterator it)
    {
        Erase(it);
    }

    void clear()
    {
        Clear();
    }

    StringMap() : HashMap<StringMapOperation>() {}

    StringMap(std::size_t initialCapacity, fnd::IAllocator* allocator) :
        HashMap<StringMapOperation>(initialCapacity, allocator) {}
};
}
}
