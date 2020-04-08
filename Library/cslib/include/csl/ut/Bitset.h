#pragma once
namespace csl
{
namespace ut
{
/* @brief A helpful wrapper for dealing with collections of bits. */
template<typename T>
class Bitset
{
    T value = 0;

    inline bool any() const
    {
        return (value != 0);
    }

    inline unsigned int count() const
    {
        unsigned int mask = 1;
        unsigned int bitCount = 0;

        for (int index = (sizeof(T) * 8); index != 0; --index)
        {
            if ((value & mask))
            {
                ++bitCount;
            }

            mask <<= 1;
        }

        return bitCount;
    }

    inline void flip(unsigned int index)
    {
        value ^= static_cast<T>(1 << index);
    }

    inline void reset(unsigned int index)
    {
        value &= ~static_cast<T>(1 << index);
    }

    inline void set(unsigned int index)
    {
        value |= static_cast<T>(1 << index);
    }

    inline void set(unsigned int index, bool v)
    {
        if (v)
        {
            set(index);
        }
        else
        {
            reset(index);
        }
    }

    inline bool test(unsigned int index) const
    {
        return ((value >> index) & 1);
    }

    inline unsigned long to_ulong() const
    {
        return static_cast<unsigned long>(value);
    }

public:
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
    inline unsigned int Count() const
    {
        return count();
    }

    /*
        @brief Flips the value of the bit at the given index (i.e. if the given bit is 0 it becomes 1).
        @param[in] index     The zero-based index of the bit to flip within the bitset.
    */
    inline void Flip(unsigned int index)
    {
        flip(index);
    }

    /*
        @brief Sets the bit at the given index to 0.
        @param[in] index     The zero-based index of the bit to disable within the bitset.
    */
    inline void Reset(unsigned int index)
    {
        reset(index);
    }

    /*
        @brief Sets the bit at the given index to 1.
        @param[in] index    The zero-based index of the bit to enable within the bitset.
    */
    inline void Set(unsigned int index)
    {
        set(index);
    }

    /*
        @brief Sets the bit at the given index within the bitset to the given value.
        @param[in] index    The zero-based index of the bit to modify within the bitset.
        @param[in] v        The value to set the given bit to (false == 0 and true == 1).
    */
    inline void Set(unsigned int index, bool v)
    {
        set(index, v);
    }

    /*
        @brief Returns whether the bit at the given index within the bitset is set to 1.
        @param[in] index    The zero-based index of the bit to check within the bitset.
        @return Whether the bit at the given index is set to 1 or not.
    */
    inline bool Test(unsigned int index) const
    {
        return test(index);
    }
};
}
}
