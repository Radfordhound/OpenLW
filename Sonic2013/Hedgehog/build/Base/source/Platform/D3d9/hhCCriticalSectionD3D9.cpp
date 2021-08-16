#include "Hedgehog/Base/Platform/D3d9/hhCCriticalSectionD3D9.h"

using namespace hh::rsdx;

namespace hh
{
namespace base
{
CCriticalSectionD3D9::CCriticalSectionD3D9()
{
    RsdxInitializeMutex2(&m_mutex, true);
}

void CCriticalSectionD3D9::Enter()
{
    RsdxLockMutex2(&m_mutex);
}

void CCriticalSectionD3D9::Leave()
{
    RsdxUnlockMutex2(&m_mutex);
}
}
}
