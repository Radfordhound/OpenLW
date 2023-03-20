#pragma once
#include "number.h"
#include "../fnd/memory.h"
#include <cstddef>
#include <cstring>

namespace csl
{
namespace ut
{
class String
{
protected:
    char* m_data;
    unsigned short m_len;
    unsigned short m_capacityAndFlags;
    fnd::IAllocator* m_allocator;

    inline String(char* data, unsigned short len,
        unsigned short capacityAndFlags,
        fnd::IAllocator* allocator) :
        m_data(data),
        m_len(len),
        m_capacityAndFlags(capacityAndFlags),
        m_allocator(allocator) {}

public:
    LWAPI(0x02ca86b0, 0x00967ae0)
    std::size_t copyFrom(const char* src, std::size_t srcLen,
        std::size_t srcOff, std::size_t dstOff)
    {
        // Resize string if necessary.
        if ((m_capacityAndFlags & ~static_cast<std::size_t>(
            CSL_HIGH_BITMASK(m_capacityAndFlags))) <= (srcLen + dstOff))
        {
            resize(srcLen + dstOff + 1);
        }

        // Copy data and set null terminator.
        std::strncpy(m_data + dstOff, src + srcOff, srcLen);
        m_data[dstOff + srcLen] = '\0';

        // Set length and return.
        m_len = static_cast<unsigned short>(dstOff + srcLen);
        return static_cast<std::size_t>(m_len);
    }

    std::size_t copyFrom(const char* src, std::size_t srcLen, std::size_t srcOff = 0)
    {
        return copyFrom(src, srcLen, srcOff, static_cast<std::size_t>(m_len));
    }

    inline String& operator=(const String& other)
    {
        copyFrom(other.c_str(), other.length(), 0, 0);
        return *this;
    }

    inline String& operator=(const char* other)
    {
        copyFrom(other, std::strlen(other), 0, 0);
        return *this;
    }

    inline String& operator+=(const String& other)
    {
        copyFrom(other.m_data, static_cast<std::size_t>(other.m_len),
            0, static_cast<std::size_t>(m_len));

        return *this;
    }

    inline String& operator+=(const char* str)
    {
        copyFrom(str, std::strlen(str),
            0, static_cast<std::size_t>(m_len));

        return *this;
    }

    inline bool operator==(const String& other) const
    {
        // TODO: Is this how the game does it?
        return (std::strncmp(m_data, other.m_data, other.length()) == 0);
    }

    inline bool operator==(const char* other) const
    {
        return (std::strcmp(m_data, other) == 0);
    }

    inline bool operator!=(const String& other) const
    {
        // TODO: Is this how the game does it?
        return (std::strncmp(m_data, other.m_data, other.length()) != 0);
    }

    inline bool operator!=(const char* other) const
    {
        return (std::strcmp(m_data, other) != 0);
    }

    // TODO: Is this function actually a thing?
    inline operator const char*() const
    {
        return m_data;
    }

    String& append(const char* str)
    {
        return operator+=(str);
    }

    String& append(const String& str)
    {
        return operator+=(str);
    }

    const char* c_str() const
    {
        return m_data;
    }

    std::size_t length() const
    {
        return static_cast<std::size_t>(m_len);
    }

    inline bool empty() const
    {
        return (m_len == 0);
    }

    LWAPI(0x02ca85a8, 0x00967a70)
    void resize(std::size_t len)
    {
        // Only resize if the string's size doesn't already match the requested size.
        if ((m_capacityAndFlags & ~static_cast<std::size_t>(
            CSL_HIGH_BITMASK(m_capacityAndFlags))) != len)
        {
            // Allocate a new buffer of the requested size.
            char* newBuf = static_cast<char*>(m_allocator->Alloc(len));
            if (m_data)
            {
                // Copy over the data from the previous buffer and set the null terminator.
                std::strncpy(newBuf, m_data, static_cast<std::size_t>(m_len));
                newBuf[m_len] = '\0';

                // Free the previous buffer if necessary.
                if (!(m_capacityAndFlags & CSL_HIGH_BITMASK(m_capacityAndFlags)))
                {
                    m_allocator->Free(m_data);
                }
            }

            // Set pointer to the new buffer and new capacity.
            m_data = newBuf;
            m_capacityAndFlags = static_cast<unsigned short>(len);
        }
    }

    ~String()
    {
        if (m_data && (CSL_HIGH_BIT(m_capacityAndFlags) == 0))
        {
            m_allocator->Free(m_data);
        }
    }

    inline String() :
        m_data(nullptr),
        m_len(0),
        m_capacityAndFlags(0),
        m_allocator(nullptr) {}

    inline String(const String& other)
    {
        copyFrom(other.c_str(), other.length(), 0, 0);
    }
};

template<unsigned short bufLen>
class StringBuf : public String
{
    char m_buf[bufLen];

public:
    inline StringBuf(fnd::IAllocator* allocator = nullptr) :
        String(m_buf, 0, CSL_HIGH_BITMASK(m_capacityAndFlags) | bufLen, allocator) {}

    StringBuf(const char* initialText, fnd::IAllocator* allocator = nullptr) :
        String(m_buf, 0, CSL_HIGH_BITMASK(m_capacityAndFlags) | bufLen, allocator)
    {
        copyFrom(initialText, std::strlen(initialText), 0, 0);
    }

    inline StringBuf<bufLen>& operator=(const StringBuf<bufLen>& other) // TODO: Is this correct?
    {
        copyFrom(other.c_str(), other.length(), 0, 0);
        std::memcpy(m_buf, other.m_buf, bufLen);
        return *this;
    }
};

template<const std::size_t bufLen>
class FixedString
{
    char m_buf[bufLen];

public:
    const char* c_str() const
    {
        return m_buf;
    }

    std::size_t length() const
    {
        return std::strlen(c_str());
    }

    bool empty() const
    {
        return (length() == 0);
    }

    bool operator==(const char* str) const
    {
        return (std::strcmp(m_buf, str) == 0);
    }

    bool operator!=(const char* str) const
    {
        return (std::strcmp(m_buf, str) != 0);
    }

    FixedString<bufLen>& operator=(const char* str)
    {
        fnd::StrLcpy(m_buf, str, bufLen);
        return *this;
    }

    FixedString()
    {
        m_buf[0] = '\0';
    }

    FixedString(const char* str)
    {
        fnd::StrLcpy(m_buf, str, bufLen);
    }
};
}
}
