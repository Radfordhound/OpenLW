#include "Extra/System/hhFxObject.h"
#include <Hedgehog/Base/System/hhMemory.h>

using namespace hh::rsdx;

namespace Extra
{
namespace fx
{
CFxRefcountObject::CFxRefcountObject() :
    m_refCount(0) {}

CFxRefcountObject::~CFxRefcountObject() {}

void CFxRefcountObject::AddRef()
{
    RsdxAtomicInc2(&m_refCount);
}

void CFxRefcountObject::Release()
{
    if (RsdxAtomicDec2(&m_refCount) == 0)
    {
        delete this;
    }
}
}
}
