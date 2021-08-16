#pragma once
#ifdef _WIN32
#include "../../System/hhEventWait.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace hh
{
namespace base
{
class CEventWaitD3D9 : public CEventWait
{
    HANDLE m_handle;

public:
    // Wii U: N/A, PC: 0x00c26ff0
    CEventWaitD3D9(bool param_1);

    // Wii U: N/A, PC: 0x00c27080
    ~CEventWaitD3D9();

    // Wii U: N/A, PC: 0x00c26f80
    void Set();

    // Wii U: N/A, PC: 0x00c26f90
    void Reset();

    // Wii U: N/A, PC: 0x00c26fa0
    void WaitOne();

    // Wii U: N/A, PC: 0x00c26fb0
    bool WaitOne(unsigned int param_1);

    // Wii U: N/A, PC: 0x00c26fd0
    bool IsSignal();
};
}
}
#endif
