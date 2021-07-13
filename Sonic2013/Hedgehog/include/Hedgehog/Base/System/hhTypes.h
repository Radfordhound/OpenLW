#pragma once
#include <cstdint>

#if UINTPTR_MAX > UINT32_MAX
#include <type_traits>
#include <stdexcept>
#endif

namespace hh
{
typedef std::int8_t s8;
typedef std::uint8_t u8;
typedef std::int16_t s16;
typedef std::uint16_t u16;
typedef std::int32_t s32;
typedef std::uint32_t u32;
typedef std::int64_t s64;
typedef std::uint64_t u64;

// NOTE: All of the code in this #if block is custom and is NOT present in the original game!
#if UINTPTR_MAX > UINT32_MAX
template<typename T>
class Off32
{
public:
    typedef s32 val_t;
    typedef Off32<T> this_t;
    typedef const this_t cthis_t;
    typedef T* ptr_t;
    typedef const T* cptr_t;
    typedef typename std::add_lvalue_reference<T>::type ref_t;
    typedef typename std::add_lvalue_reference<const T>::type cref_t;

private:
    val_t m_val;

public:
    cptr_t get() const
    {
        // Convert from relative pointer to absolute pointer and return result.
        return (m_val != 0) ? reinterpret_cast<cptr_t>(
            reinterpret_cast<std::intptr_t>(this) + m_val) :
            nullptr;
    }

    inline ptr_t get()
    {
        return const_cast<ptr_t>(const_cast<cthis_t*>(this)->get());
    }

    val_t set(ptr_t ptr)
    {
        // Just set m_val to 0 if ptr is null.
        if (!ptr)
        {
            m_val = 0;
            return m_val;
        }

        // Pointers are > 32 bits, so ptr will not fit within a 32-bit offset.
        // We have to convert ptr to a relative pointer instead, and
        // store that within the given offset.
        const std::intptr_t ptrAddr = reinterpret_cast<std::intptr_t>(ptr);
        std::intptr_t offAddr = reinterpret_cast<std::intptr_t>(this);

        // Ensure offset does not point to itself; we can't do that
        // with our relative offsets, since we still use 0 for null.
        if (ptrAddr == offAddr)
        {
            throw std::runtime_error("Cannot have 32-bit offsets which point to themselves");
        }

        // Compute a relative offset which points to ptr.
        offAddr = (ptrAddr - offAddr);

        // Ensure relative offset can fit within a signed
        // 32-bit integer, since we're about to cast to that.
        if (offAddr > INT32_MAX || offAddr < INT32_MIN)
        {
            throw std::range_error("Relative offset value would not fit within 32-bits");
        }

        // Set the offset to the relative offset we just computed.
        m_val = static_cast<val_t>(offAddr);
        return m_val;
    }

    inline this_t& operator=(ptr_t ptr)
    {
        set(ptr);
        return *this;
    }

    /*inline cptr_t operator->() const
    {
        return get();
    }

    inline ptr_t operator->()
    {
        return get();
    }

    inline cref_t operator*() const
    {
        return *get();
    }

    inline ref_t operator*()
    {
        return *get();
    }

    inline cref_t operator[](std::size_t i) const
    {
        return *(get() + i);
    }

    inline ref_t operator[](std::size_t i)
    {
        return *(get() + i);
    }

    inline bool operator<(cthis_t& other) const
    {
        return (get() < other.get());
    }

    inline bool operator>(cthis_t& other) const
    {
        return (get() > other.get());
    }

    inline bool operator<=(cthis_t& other) const
    {
        return (get() <= other.get());
    }

    inline bool operator>=(cthis_t& other) const
    {
        return (get() >= other.get());
    }

    inline bool operator==(cthis_t& other) const
    {
        return (get() == other.get());
    }

    inline bool operator!=(cthis_t& other) const
    {
        return (get() != other.get());
    }

    inline bool operator<(cptr_t ptr) const
    {
        return (get() < ptr);
    }

    inline bool operator>(cptr_t ptr) const
    {
        return (get() > ptr);
    }

    inline bool operator<=(cptr_t ptr) const
    {
        return (get() <= ptr);
    }

    inline bool operator>=(cptr_t ptr) const
    {
        return (get() >= ptr);
    }

    inline bool operator==(cptr_t ptr) const
    {
        return (get() == ptr);
    }

    inline bool operator!=(cptr_t ptr) const
    {
        return (get() != ptr);
    }

    inline operator bool() const
    {
        return (m_val != 0);
    }*/

    inline operator cptr_t() const
    {
        return get();
    }

    inline operator ptr_t()
    {
        return get();
    }

    inline Off32() {}
    inline Off32(std::nullptr_t) : m_val(0) {}
    inline Off32(u32 v) : m_val(static_cast<val_t>(v)) {}
    inline Off32(ptr_t ptr) : m_val(set(ptr)) {}
};

#define OFF32(type) Off32<type>
#else
#define OFF32(type) type*
#endif
}
