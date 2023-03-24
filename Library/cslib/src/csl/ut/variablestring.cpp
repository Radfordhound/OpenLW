// TODO: Both the name of this file and its path were guessed!
#include "csl/ut/variablestring.h"
#include "csl/ut/number.h"
#include "csl/fnd/memory.h"

namespace csl
{
namespace ut
{
char* VariableString::getDataPointer() const
{
    return reinterpret_cast<std::uintptr_t>(m_data) & ~1;
}

bool VariableString::needsFree() const
{
    return (reinterpret_cast<std::uintptr_t>(m_data) & 1) != 0;
}

const char* VariableString::c_str() const
{
    return (m_data == nullptr) ? "" : getDataPointer();
}

void VariableString::assign(const fnd::IAllocator* allocator, const char* data, int len)
{
    // Return early if myData is already equal to data.
    if (c_str() == data) return;

    // Free the existing string data if necessary.
    if (needsFree())
    {
        m_allocator->Free(reinterpret_cast<char*>(
            reinterpret_cast<std::uintptr_t>(m_data) - 1));
    }

    // Set allocator.
    m_allocator = allocator;

    // Set data.
    if (data == nullptr)
    {
        m_data = nullptr;
    }
    else if (len == -1)
    {
        const auto buf = static_cast<char*>(m_allocator->Alloc(std::strlen(data) + 1));
        std::strcpy(buf, data);
        m_data = (buf + 1);
    }
    else
    {
        const auto bufLen = Min<std::size_t>(std::strlen(data), len);
        const auto buf = static_cast<char*>(m_allocator->Alloc(bufLen));

        std::strncpy(buf, data, bufLen);
        buf[bufLen] = '\0'; // TODO: If bufLen is 0, this invokes undefined behavior. Does the game do this too?
        m_data = (buf + 1);
    }
}

VariableString::VariableString(const char* data, fnd::IAllocator* allocator) :
    m_data(nullptr),
    m_allocator(nullptr)
{
    assign(allocator, data);
}

VariableString::VariableString(const char* data, int len, fnd::IAllocator* allocator) :
    m_data(nullptr),
    m_allocator(nullptr)
{
    assign(allocator, data, len);
}

VariableString::VariableString(const VariableString& other) :
    m_data(nullptr),
    m_allocator(nullptr)
{
    assign(other.m_allocator, other.c_str());
}

VariableString::~VariableString()
{
    assign(nullptr, nullptr);
}

VariableString& VariableString::operator=(const VariableString& other)
{
    assign(m_allocator, other.c_str());
    return *this;
}

void VariableString::Set(const fnd::IAllocator* allocator, const char* data, int len)
{
    assign(allocator, data, len);
}

void VariableString::SetDataUserFree(const fnd::IAllocator* allocator, const char* data)
{
    m_data = data;
    m_allocator = allocator;
}

int VariableString::compareTo(const char* data) const
{
    const auto myData = c_str();
    if (myData == nullptr)
    {
        return (data == nullptr) ? 0 : -1;
    }
    else
    {
        return (data == nullptr) ? 1 :
            std::strcmp(myData, data);
    }
}
} // ut
} // csl
