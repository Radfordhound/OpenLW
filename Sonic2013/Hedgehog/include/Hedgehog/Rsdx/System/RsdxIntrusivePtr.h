#pragma once

namespace hh
{
namespace rsdx
{
template<typename T, typename lock_unlock_t>
class rsdx_intrusive_ptr // TODO: Inheritance?
{
    T* m_ptr;

public:
    T* get() const
    {
        return m_ptr;
    }

    rsdx_intrusive_ptr<T, lock_unlock_t>& operator=(T* ptr)
    {
        lock_unlock_t::Lock(ptr);

        T* oldPtr = m_ptr;
        m_ptr = ptr;

        lock_unlock_t::Unlock(oldPtr);

        return *this;
    }

    operator bool() const
    {
        return (m_ptr != nullptr);
    }

    rsdx_intrusive_ptr() :
        m_ptr(nullptr) {}

    // TODO: Is this correct?
    rsdx_intrusive_ptr(const rsdx_intrusive_ptr<T, lock_unlock_t>& other) :
        m_ptr(other.m_ptr)
    {
        lock_unlock_t::Lock(m_ptr);
    }

    ~rsdx_intrusive_ptr()
    {
        lock_unlock_t::Unlock(m_ptr);
    }
};
}
}
