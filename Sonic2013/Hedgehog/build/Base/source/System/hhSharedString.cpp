#include "pch.h"
#include "Hedgehog/Base/System/hhSharedString.h"
#include <Hedgehog/Rsdx/System/RsdxAtomic.h>

using namespace hh::rsdx;

namespace hh
{
namespace base
{
enum CSharedStringFlags
{
    /* Masks */
    SHARED_STRING_LEN_MASK = 0xFFFF0000,
    SHARED_STRING_REF_COUNT_MASK = 0xffff,
};

LWAPI(0x102c16a0, 0x00eb29b4)
static char* StaticData = "";

CSharedString::CSharedString() :
    m_data(StaticData) {}

LWAPI(0x0369de1c, NONE)
static bool is_memstatic(const char* data)
{
    return (!data || data == StaticData);
}

void CSharedString::clearstr()
{
    if (!is_memstatic(m_data))
    {
        RsdxAtomic* flags = reinterpret_cast<RsdxAtomic*>(m_data - sizeof(RsdxAtomic));
        if ((RsdxAtomicDec2(flags) & SHARED_STRING_REF_COUNT_MASK) == 0)
        {
            delete[](m_data - sizeof(RsdxAtomic));
        }
    }

    m_data = StaticData;
}

void CSharedString::assign(const CSharedString& str)
{
    if (this != &str)
    {
        clearstr();
        if (!is_memstatic(str.m_data))
        {
            RsdxAtomic flags = *reinterpret_cast<RsdxAtomic*>(
                str.m_data - sizeof(RsdxAtomic));

            // TODO: Is this correct? If so, this seems to be a bug in Sonic Team's code, as it would just make the thread freeze forever!
            // I assume they meant to get the other string's flags again every iteration instead of just doing it once like this?
            while ((flags & SHARED_STRING_REF_COUNT_MASK) == 0) {}
        }

        m_data = str.m_data;
    }
}

CSharedString::CSharedString(const CSharedString& other) :
    m_data(StaticData)
{
    assign(other);
}

const char* CSharedString::c_str() const
{
    return (is_memstatic(m_data) && !m_data) ?
        StaticData : m_data;
}

LWAPI(0x0369dfc8, TODO)
static bool TryExtend(char* data, const char* str, int len)
{
    if (!is_memstatic(data))
    {
        // If we are currently the only owner of this string, and
        // the existing data buffer's length is sufficient...
        RsdxAtomic* flags = reinterpret_cast<RsdxAtomic*>(data - sizeof(RsdxAtomic));

        if ((*flags & SHARED_STRING_REF_COUNT_MASK) == 1 &&
            (((sizeof(RsdxAtomic) + (*flags >> 16) + 16) ^
            (sizeof(RsdxAtomic) + len + 16)) & 0xfffffff0) == 0)
        {
            // Copy string data into buffer.
            std::memcpy(data, str, len);

            // Fill extra bytes after string with 0s.
            std::memset(data + len, 0, (sizeof(RsdxAtomic) + len +
                16 & 0xfffffff0) - (sizeof(RsdxAtomic) + len));

            // Store string length and reference count in atomic.
            *reinterpret_cast<RsdxAtomic*>(data - sizeof(RsdxAtomic)) =
                ((len << 16) | 1);
            
            return true;
        }
    }

    return false;
}

void CSharedString::newallocstr(const char* initialText, int len)
{
    if (len < 0)
    {
        len = std::strlen(initialText);
    }

    if (len == 0)
    {
        // Clear previous data and set new data pointer.
        clearstr();
        m_data = StaticData;
    }
    else if (!TryExtend(m_data, initialText, len))
    {
        // Allocate 16-byte-aligned buffer for string data + an atomic value.
        char* newData = new char[sizeof(RsdxAtomic) + len + 16 & 0xfffffff0];

        // Copy string data into buffer.
        std::memcpy(newData + sizeof(RsdxAtomic), initialText, len);

        // Fill extra bytes after string with 0s.
        std::memset(newData + sizeof(RsdxAtomic) + len, 0,
            (sizeof(RsdxAtomic) + len + 16 & 0xfffffff0) -
            (sizeof(RsdxAtomic) + len));

        // Store string length and reference count in atomic.
        *reinterpret_cast<RsdxAtomic*>(newData) =
            ((len << 16) | 1);

        // Clear previous data and set new data pointer.
        clearstr();
        m_data = (newData + sizeof(RsdxAtomic));
    }
}

CSharedString::CSharedString(const CSharedString& other, int off) :
    m_data(StaticData)
{
    std::string a_Stack48(other.c_str(), off);
    newallocstr(a_Stack48.c_str());
}

CSharedString::CSharedString(const CSharedString& other, int off, int count) :
    m_data(StaticData)
{
    std::string a_Stack48(other.c_str(), off, count);
    newallocstr(a_Stack48.c_str());
}

CSharedString::CSharedString(const std::string& str) :
    m_data(StaticData)
{
    newallocstr(str.c_str());
}

CSharedString::CSharedString(const char* first, const char* last) :
    m_data(StaticData)
{
    std::string a_Stack48(first, last);
    newallocstr(a_Stack48.c_str());
}

CSharedString::CSharedString(const char* str) :
    m_data(StaticData)
{
    if (!is_memstatic(str))
    {
        newallocstr(str);
    }
    else
    {
        m_data = const_cast<char*>(str);
    }
}

CSharedString::CSharedString(const char* str, int off) :
    m_data(StaticData)
{
    std::string auStack48(str, off);
    newallocstr(auStack48.c_str());
}

CSharedString::CSharedString(const char* str, int off, int count) :
    m_data(StaticData)
{
    std::string a_Stack80(str, off, count);
    newallocstr(a_Stack80.c_str());
}

CSharedString::CSharedString(const char* str, int count, char val) :
    m_data(StaticData)
{
    std::string auStack48(count, val);
    newallocstr(auStack48.c_str());
}

void CSharedString::reserve(int amount) {} // NOTE: It seems Sonic Team never implemented this lol

void CSharedString::clear()
{
    clearstr();
}

std::size_t CSharedString::size() const
{
    if (m_data)
    {
        if (is_memstatic(m_data))
        {
            return std::strlen(m_data);
        }
        
        return (*reinterpret_cast<RsdxAtomic*>(m_data -
            sizeof(RsdxAtomic)) >> 16);
    }

    return 0;
}

std::size_t CSharedString::length() const
{
    return size();
}

std::size_t CSharedString::find(const char* str) const
{
    std::string auStack40(c_str());
    return auStack40.find(str);
}

std::size_t CSharedString::find(const CSharedString& other) const
{
    std::string auStack40(c_str());
    return auStack40.find(other.c_str());
}

std::size_t CSharedString::find(char val) const
{
    std::string auStack40(c_str());
    return auStack40.find(val);
}

CSharedString& CSharedString::operator=(const char* str)
{
    newallocstr(str);
    return *this;
}

CSharedString& CSharedString::replace(int off, int count, const char* str, int count2)
{
    std::string auStack56(c_str());

    auStack56.replace(off, count, str, count2);
    *this = auStack56.c_str();

    return *this;
}

CSharedString& CSharedString::replace(int off, int count, const char* str)
{
    std::string auStack56(c_str());

    auStack56.replace(off, count, str);
    *this = auStack56.c_str();

    return *this;
}

CSharedString& CSharedString::replace(int off, int count, const CSharedString& str)
{
    std::string auStack48(c_str());

    auStack48.replace(off, count, str.c_str());
    *this = auStack48.c_str();

    return *this;
}

void CSharedString::erase()
{
    clearstr();
}

CSharedString::~CSharedString()
{
    clearstr();
}

CSharedString CSharedString::substr(int param_1, int param_2) const
{
    std::string auStack44(c_str());
    return CSharedString(auStack44.substr(param_1, param_2).c_str());
}

bool CSharedString::empty() const
{
    return (size() == 0);
}

CSharedString& CSharedString::operator=(const CSharedString& other)
{
    assign(other);
    return *this;
}
}
}
