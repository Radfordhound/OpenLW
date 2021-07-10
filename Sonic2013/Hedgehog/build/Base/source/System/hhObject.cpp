#include "Hedgehog/Base/System/hhObject.h"

namespace hh
{
namespace base
{
void* CObject::operator new(std::size_t size)
{
    return __HH_ALLOC__(size);
}

void CObject::operator delete(void* ptr)
{
    return __HH_FREE__(ptr);
}

CRefCountObject::~CRefCountObject() {}

std::size_t CRefCountObject::RefCount() const
{
    return m_refCount;
}

bool CRefCountObject::IsUnique() const
{
    return (m_refCount == 1);
}

void CRefCountObject::AddRef()
{
    // TODO
}

std::size_t CRefCountObject::Release()
{
    // TODO
    return 0;
}

CRefCountObject::CRefCountObject() :
    m_refCount(0) {}
}
}
