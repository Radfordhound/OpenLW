#pragma once
#include "hhMemory.h"
#include <climits>

namespace hh
{
namespace base
{
template<typename T>
struct TAllocator
{
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;

    template<class T2>
    struct rebind
    {
        typedef TAllocator<T2> other;
    };

    inline TAllocator() {}
    
    template<typename T2>
    TAllocator(const TAllocator<T2>&) {}

    inline pointer address(reference val) const
    {
        // TODO: Is this correct??
        return &val;
    }

    inline const_pointer address(const_reference val) const
    {
        // TODO: Is this correct??
        return &val;
    }

    inline T* allocate(std::size_t count)
    {
        // TODO: Is this correct?? Do they do any checks/throw any exceptions or anything?
        return static_cast<T*>(__HH_ALLOC_DBG(sizeof(T) * count)); // line: 45
    }

    inline void construct(pointer ptr, const T& val)
    {
        new ((void*)ptr) T(val); // TODO: Is this correct??
    }

    inline void deallocate(pointer ptr, size_type count)
    {
        __HH_FREE(ptr); // TODO: Is this correct??
    }

    inline void destroy(pointer ptr)
    {
        ptr->T::~T(); // TODO: Is this correct??
    }

    inline size_type max_size() const
    {
        return (SIZE_MAX / sizeof(T)); // TODO: Is this correct??
    }
};

// TODO: Does this function actually exist??
template<typename T1, typename T2>
bool operator==(const TAllocator<T1>&, const TAllocator<T2>&)
{
    return true;
}

// TODO: Does this function actually exist??
template<typename T1, typename T2>
bool operator!=(const TAllocator<T1>&, const TAllocator<T2>&)
{
    return false;
}
}
}
