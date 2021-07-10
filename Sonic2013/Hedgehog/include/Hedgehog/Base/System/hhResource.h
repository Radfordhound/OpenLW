#pragma once
#include "hhTypes.h"

namespace hh
{
namespace ut
{
template<typename T>
class ResCommon
{
protected:
    T* m_ptr;

public:
    typedef T value_type;

    const T* ptr() const
    {
        return m_ptr;
    }

    const T& ref() const
    {
        return *m_ptr;
    }

    bool IsValid() const
    {
        return (m_ptr != nullptr);
    }

    ResCommon(const void* data) :
        m_ptr(static_cast<T*>(const_cast<void*>(data))) {}

    ResCommon(void* data) :
        m_ptr(static_cast<T*>(data)) {}
};

class ResFileCommon
{
    // TODO: Any data members or anything??

public:

    // Wii U: 0x036945fc, PC: 0x00c1a210
    static u32 GetReverseBigEndian(u32 val);
};
}
}
