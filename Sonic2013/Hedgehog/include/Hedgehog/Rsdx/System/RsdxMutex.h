#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#elif defined(__WIIU__)
#include <coreinit/mutex.h>
#endif

namespace hh
{
namespace rsdx
{
#ifdef _WIN32
typedef CRITICAL_SECTION RsdxMutex;
#elif defined(__WIIU__)
typedef OSMutex RsdxMutex;
#endif

struct RsdxMutex2
{
#ifdef _WIN32
    RsdxMutex Mutex;
#else
    RsdxMutex* Handle;
#endif

    // TODO: Other data members?
};

LWAPI(0x036a7af0, NONE)
void RsdxInitializeMutex(RsdxMutex* mutex, bool param_2);

LWAPI(0x036a7b1c, NONE)
void RsdxLockMutex(RsdxMutex* mutex);

LWAPI(0x036a7b20, NONE)
void RsdxUnlockMutex(RsdxMutex* mutex);

LWAPI(0x036c0170, NONE)
void RsdxInitializeMutex2(RsdxMutex2* mutex, bool param_2);

LWAPI(0x036c01f8, NONE)
void RsdxLockMutex2(RsdxMutex2* mutex);

LWAPI(0x036c0200, NONE)
void RsdxUnlockMutex2(RsdxMutex2* mutex);
}
}
