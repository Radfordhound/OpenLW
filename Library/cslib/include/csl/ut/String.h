#pragma once
#include "../fnd/IAllocator.h"
#include <cstring>

namespace csl
{
namespace ut
{
class String
{
protected:
    char* data = nullptr;
    unsigned short len = 0;
    unsigned short capacityAndFlags = 0;
    fnd::IAllocator* allocator = nullptr;

    constexpr static unsigned short CapacityBitCount = (sizeof(capacityAndFlags) << 3);
    constexpr static unsigned short NoFreeFlag = (1 << (CapacityBitCount - 1));
    constexpr static unsigned short CapacityMask = ~NoFreeFlag;
    constexpr static std::size_t CapacityMaskSizeT = ~static_cast<std::size_t>(NoFreeFlag);

    inline String() = default;
    inline String(char* data, unsigned short len,
        unsigned short capacityAndFlags, fnd::IAllocator* allocator) :
        data(data), len(len), capacityAndFlags(capacityAndFlags),
        allocator(allocator) {}

public:
    /* <b>Wii U: 0x02ca86b0, PC: 0x00967ae0</b> */
    std::size_t copyFrom(const char* src, std::size_t srcLen,
        std::size_t srcOff, std::size_t dstOff);

    inline std::size_t copyFrom(const char* src, std::size_t srcLen,
        std::size_t srcOff = 0)
    {
        return copyFrom(src, srcLen, srcOff, static_cast<std::size_t>(len));
    }

    inline ~String()
    {
        if (data && !(capacityAndFlags & NoFreeFlag))
        {
            allocator->Free(data);
        }
    }

    inline String(const String& other)
    {
        copyFrom(other.c_str(), other.length(), 0, 0);
    }

    inline String& operator=(const char* other)
    {
        copyFrom(other, std::strlen(other), 0, 0);
        return *this;
    }

    inline String& operator+=(const String& other)
    {
        copyFrom(other.data, static_cast<std::size_t>(other.len),
            0, static_cast<std::size_t>(len));

        return *this;
    }

    inline String& operator+=(const char* other)
    {
        copyFrom(other, std::strlen(other),
            0, static_cast<std::size_t>(len));

        return *this;
    }

    inline bool operator==(const String& other) const noexcept
    {
        // TODO: Is this how the game does it?
        return !std::strncmp(data, other.data, other.length());
    }

    inline bool operator==(const char* other) const noexcept
    {
        return !std::strcmp(data, other);
    }

    inline bool operator!=(const String& other) const noexcept
    {
        // TODO: Is this how the game does it?
        return std::strncmp(data, other.data, other.length());
    }

    inline bool operator!=(const char* other) const noexcept
    {
        return std::strcmp(data, other);
    }

    inline String& append(const char* str)
    {
        return operator+=(str);
    }

    inline String& append(const String& str)
    {
        return operator+=(str);
    }

    inline const char* c_str() const noexcept
    {
        return data;
    }

    inline std::size_t length() const noexcept
    {
        return static_cast<std::size_t>(len);
    }

    inline bool empty() const noexcept
    {
        return (len == 0);
    }

    /*<b>Wii U: 0x02ca85a8, PC: 0x00967a70</b> */
    void resize(std::size_t len);
};

template<unsigned short bufLen = 128>
class StringBuf : public String
{
    char buf[bufLen];

public:
    inline StringBuf(fnd::IAllocator* allocator = nullptr) :
        String(buf, 0, NoFreeFlag | bufLen, allocator) {}

    inline StringBuf(const char* initialText, fnd::IAllocator* allocator = nullptr) :
        String(buf, 0, NoFreeFlag | bufLen, allocator)
    {
        copyFrom(initialText, std::strlen(initialText), 0, 0);
    }
};
}
}
