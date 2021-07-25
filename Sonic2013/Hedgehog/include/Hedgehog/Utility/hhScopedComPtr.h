#pragma once

namespace hh
{
namespace ut
{
template<typename T, typename scope_t>
class ScopedComPtr
{
    T* m_ptr;

public:
    ScopedComPtr(T* ptr = nullptr) :
        m_ptr(ptr) {}

    T* get() const
    {
        return m_ptr;
    }

    void reset(T* ptr = nullptr)
    {

        // TODO
        m_ptr = ptr;
    }
};
}
}
