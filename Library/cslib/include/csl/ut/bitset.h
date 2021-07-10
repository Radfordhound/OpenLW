#pragma once
#include <cstddef>
#include <climits>

namespace csl
{
namespace ut
{
/* @brief A helpful wrapper for dealing with collections of bits. */
template<typename T>
class Bitset
{
    T m_val;

public:
    /*
        @brief Returns whether any bits within the bitset are currently set to 1.
        @return Whether any bits within the bitset are currently set to 1.
    */
    bool any() const
    {
        return (m_val != 0);
    }

    /*
        @brief Returns whether any bits within the bitset are currently set to 1.
        @return Whether any bits within the bitset are currently set to 1.
    */
    inline bool Any() const
    {
        return any();
    }

    /*
        @brief Counts the amount of bits that are currently set to 1 within the bitset.
        @returns How many bits are currently set to 1 within the bitset.
    */
    std::size_t count() const
    {
        T mask(1);
        std::size_t bitCount = 0;

        for (int pos = (sizeof(T) * CHAR_BIT); pos != 0; --pos)
        {
            if ((m_val & mask))
            {
                ++bitCount;
            }

            mask <<= 1;
        }

        return bitCount;
    }

    /*
        @brief Counts the amount of bits that are currently set to 1 within the bitset.
        @returns How many bits are currently set to 1 within the bitset.
    */
    inline unsigned int Count() const
    {
        return count();
    }

    /*
        @brief Flips the value of the bit at the given index (i.e. if the given bit is 0 it becomes 1).
        @param[in] pos      The zero-based index of the bit to flip within the bitset.
    */
    void flip(std::size_t pos)
    {
        m_val ^= static_cast<T>(1 << pos);
    }

    /*
        @brief Flips the value of the bit at the given index (i.e. if the given bit is 0 it becomes 1).
        @param[in] pos      The zero-based index of the bit to flip within the bitset.
    */
    inline void Flip(std::size_t pos)
    {
        flip(pos);
    }

    /*
        @brief Sets the bit at the given index to 0.
        @param[in] pos      The zero-based index of the bit to disable within the bitset.
    */
    void reset(std::size_t pos)
    {
        m_val &= ~static_cast<T>(1 << pos);
    }

    /*
        @brief Sets the bit at the given index to 0.
        @param[in] pos      The zero-based index of the bit to disable within the bitset.
    */
    inline void Reset(std::size_t pos)
    {
        reset(pos);
    }

    /*
        @brief Sets the bit at the given index to 1.
        @param[in] pos      The zero-based index of the bit to enable within the bitset.
    */
    void set(std::size_t pos)
    {
        m_val |= static_cast<T>(1 << pos);
    }

    /*
        @brief Sets the bit at the given index to 1.
        @param[in] pos      The zero-based index of the bit to enable within the bitset.
    */
    inline void Set(std::size_t pos)
    {
        set(pos);
    }

    /*
        @brief Sets the bit at the given index within the bitset to the given value.
        @param[in] pos      The zero-based index of the bit to modify within the bitset.
        @param[in] v        The value to set the given bit to (false == 0 and true == 1).
    */
    void set(std::size_t pos, bool v)
    {
        if (v)
        {
            set(pos);
        }
        else
        {
            reset(pos);
        }
    }

    /*
        @brief Sets the bit at the given index within the bitset to the given value.
        @param[in] pos      The zero-based index of the bit to modify within the bitset.
        @param[in] v        The value to set the given bit to (false == 0 and true == 1).
    */
    inline void Set(std::size_t pos, bool v)
    {
        set(pos, v);
    }

    /*
        @brief Returns whether the bit at the given index within the bitset is set to 1.
        @param[in] pos      The zero-based index of the bit to check within the bitset.
        @return Whether the bit at the given index is set to 1 or not.
    */
    bool test(std::size_t pos) const
    {
        return ((m_val >> pos) & 1);
    }

    /*
        @brief Returns whether the bit at the given index within the bitset is set to 1.
        @param[in] pos      The zero-based index of the bit to check within the bitset.
        @return Whether the bit at the given index is set to 1 or not.
    */
    inline bool Test(std::size_t pos) const
    {
        return test(pos);
    }

    unsigned long to_ulong() const
    {
        return static_cast<unsigned long>(m_val);
    }

    // TODO: Is this constructor actually a thing?
    inline Bitset() :
        m_val(0) {}

    // TODO: Is this constructor actually a thing?
    inline Bitset(T val) :
        m_val(val) {}
};
}
}
