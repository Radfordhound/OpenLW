#include "OpenLW/pch.h"
#include "Handle.h"

namespace app
{
namespace fnd
{
bool HandleBase::IsValid() const
{
    return (m_entry != nullptr &&
        m_entry->obj != nullptr &&
        m_entry->handle == m_handle);
}

bool HandleBase::operator==(const HandleBase& other) const
{
    return (IsValid() && other.IsValid() && m_handle == other.m_handle);
}

bool HandleBase::operator==(const RefByHandleObject* obj) const
{
    return (obj && IsValid() && m_handle == obj->m_handleObj.m_handle);
}

bool HandleBase::operator!=(const HandleBase& other) const
{
    return !operator==(other);
}

bool HandleBase::operator!=(const RefByHandleObject* obj) const
{
    return !operator==(obj);
}

HandleBase::HandleBase(const RefByHandleObject* obj)
{
    if (obj)
    {
        m_handle = obj->m_handleObj.m_handle;
        m_entry = obj->m_handleObj.m_entry;
    }
    else
    {
        m_handle = nullptr;
        m_entry = nullptr;
    }
}

void* HandleBase::Get() const
{
    return IsValid() ? m_entry->obj : nullptr;
}

HandleBase& HandleBase::operator=(const HandleBase& other)
{
    m_handle = other.m_handle;
    m_entry = other.m_entry;
    return *this;
}

HandleBase& HandleBase::operator=(const RefByHandleObject* obj)
{
    if (obj)
    {
        m_handle = obj->m_handleObj.m_handle;
        m_entry = obj->m_handleObj.m_entry;
    }
    else
    {
        m_handle = nullptr;
        m_entry = nullptr;
    }

    return *this;
}
} // fnd
} // app
