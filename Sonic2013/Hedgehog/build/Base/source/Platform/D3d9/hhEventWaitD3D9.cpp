#ifdef _WIN32
#include "Hedgehog/Base/Platform/D3d9/hhEventWaitD3D9.h"

namespace hh
{
namespace base
{
CEventWaitD3D9::CEventWaitD3D9(bool param_1) :
    m_handle(CreateEventA(NULL, !param_1, FALSE, NULL)) {}

CEventWaitD3D9::~CEventWaitD3D9()
{
    CloseHandle(m_handle);
}

void CEventWaitD3D9::Set()
{
    SetEvent(m_handle);
}

void CEventWaitD3D9::Reset()
{
    ResetEvent(m_handle);
}

void CEventWaitD3D9::WaitOne()
{
    WaitForSingleObject(m_handle, INFINITE);
}

bool CEventWaitD3D9::WaitOne(unsigned int param_1)
{
    return (WaitForSingleObject(m_handle, param_1) != WAIT_TIMEOUT);
}

bool CEventWaitD3D9::IsSignal()
{
    return (WaitForSingleObject(m_handle, 0) == WAIT_OBJECT_0);
}
}
}
#endif
