#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
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

// Wii U: 0x036a7af0, PC: Inlined
void RsdxInitializeMutex(RsdxMutex* mutex, bool param_2);

// Wii U: 0x036a7b1c, PC: Inlined (TODO: Is this PC address correct??)
void RsdxLockMutex(RsdxMutex* mutex);

// Wii U: 0x036a7b20, PC: Inlined (TODO: Is this PC address correct??)
void RsdxUnlockMutex(RsdxMutex* mutex);

// Wii U: 0x036c0170, PC: Inlined
void RsdxInitializeMutex2(RsdxMutex2* mutex, bool param_2);

// Wii U: 0x036c01f8, PC: Inlined (TODO: Is this PC address correct??)
void RsdxLockMutex2(RsdxMutex2* mutex);

// Wii U: 0x036c0200, PC: Inlined (TODO: Is this PC address correct??)
void RsdxUnlockMutex2(RsdxMutex2* mutex);
}
}
