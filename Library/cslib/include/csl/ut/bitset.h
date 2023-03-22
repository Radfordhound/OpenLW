#pragma once
#include "number.h"

namespace csl
{
namespace ut
{
/** @brief A helpful wrapper for dealing with collections of bits. */
template<typename T, int BitCount = CSL_BIT_COUNT(T)>
class Bitset
{
    T m_Data;

public:
    /**
        @brief Returns whether any bits within the bitset are currently set to 1.
        @return Whether any bits within the bitset are currently set to 1.
    */
    bool any() const
    {
        return (m_Data != 0);
    }

    /**
        @brief Returns whether any bits within the bitset are currently set to 1.
        @return Whether any bits within the bitset are currently set to 1.
    */
    inline bool Any() const
    {
        return any();
    }

    /**
        @brief Counts the amount of bits that are currently set to 1 within the bitset.
        @returns How many bits are currently set to 1 within the bitset.
    */
    unsigned int count() const
    {
        T bitMask(1);
        unsigned int count = 0;

        for (int pos = BitCount; pos != 0; --pos)
        {
            if ((m_Data & bitMask))
            {
                ++count;
            }

            bitMask <<= 1;
        }

        return count;
    }

    /**
        @brief Counts the amount of bits that are currently set to 1 within the bitset.
        @returns How many bits are currently set to 1 within the bitset.
    */
    inline unsigned int Count() const
    {
        return count();
    }

    /**
        @brief Flips the value of the bit at the given index (i.e. if the given bit is 0 it becomes 1).
        @param[in] bitIndex The zero-based index of the bit to flip within the bitset.
    */
    Bitset<T, BitCount> flip(unsigned int bitIndex)
    {
        m_Data ^= static_cast<T>(1 << bitIndex);
        return *this;
    }

    /**
        @brief Flips the value of the bit at the given index (i.e. if the given bit is 0 it becomes 1).
        @param[in] bitIndex The zero-based index of the bit to flip within the bitset.
    */
    inline Bitset<T, BitCount> Flip(unsigned int bitIndex)
    {
        return flip(bitIndex);
    }

    /** @brief Resets all bits in the bitset to 0. */
    Bitset<T, BitCount> reset()
    {
        m_Data = 0;
        return *this;
    }

    /** @brief Resets all bits in the bitset to 0. */
    inline Bitset<T, BitCount> Reset()
    {
        return *this;
    }

    /**
        @brief Sets the bit at the given index to 0.
        @param[in] bitIndex The zero-based index of the bit to disable within the bitset.
    */
    Bitset<T, BitCount> reset(unsigned int bitIndex)
    {
        m_Data &= ~static_cast<T>(1 << bitIndex);
        return *this;
    }

    /**
        @brief Sets the bit at the given index to 0.
        @param[in] bitIndex The zero-based index of the bit to disable within the bitset.
    */
    inline Bitset<T, BitCount> Reset(unsigned int bitIndex)
    {
        return reset(bitIndex);
    }

    /** @brief Sets all bits in the bitset to 1. */
    Bitset<T, BitCount> set()
    {
        m_Data = (std::numeric_limits<T>::max)();
        return *this;
    }

    /** @brief Sets all bits in the bitset to 1. */
    inline Bitset<T, BitCount> Set()
    {
        return set();
    }

    /**
        @brief Sets the bit at the given index to 1.
        @param[in] bitIndex The zero-based index of the bit to enable within the bitset.
    */
    Bitset<T, BitCount> set(unsigned int bitIndex)
    {
        m_Data |= static_cast<T>(1 << bitIndex);
        return *this;
    }

    /**
        @brief Sets the bit at the given index to 1.
        @param[in] bitIndex The zero-based index of the bit to enable within the bitset.
    */
    inline Bitset<T, BitCount> Set(unsigned int bitIndex)
    {
        return set(bitIndex);
    }

    /**
        @brief Sets the bit at the given index within the bitset to the given value.
        @param[in] bitIndex The zero-based index of the bit to modify within the bitset.
        @param[in] val      The value to set the given bit to (false == 0 and true == 1).
    */
    Bitset<T, BitCount> set(unsigned int bitIndex, bool val)
    {
        return (val) ? set(bitIndex) : reset(bitIndex);
    }

    /**
        @brief Sets the bit at the given index within the bitset to the given value.
        @param[in] bitIndex The zero-based index of the bit to modify within the bitset.
        @param[in] val      The value to set the given bit to (false == 0 and true == 1).
    */
    inline Bitset<T, BitCount> Set(unsigned int bitIndex, bool val)
    {
        return set(bitIndex, val);
    }

    /**
        @brief Returns whether the bit at the given index within the bitset is set to 1.
        @param[in] bitIndex The zero-based index of the bit to check within the bitset.
        @return Whether the bit at the given index is set to 1 or not.
    */
    bool test(unsigned int bitIndex) const
    {
        return ((m_Data >> bitIndex) & 1);
    }

    /**
        @brief Returns whether the bit at the given index within the bitset is set to 1.
        @param[in] bitIndex The zero-based index of the bit to check within the bitset.
        @return Whether the bit at the given index is set to 1 or not.
    */
    inline bool Test(unsigned int bitIndex) const
    {
        return test(bitIndex);
    }

    unsigned int to_ulong() const
    {
        return static_cast<unsigned int>(m_Data);
    }

    Bitset() :
        m_Data(0) {}

    Bitset(T data) :
        m_Data(data) {}

    Bitset(const Bitset<T, BitCount>& other) :
        m_Data(other.m_Data) {}
};
}
}
