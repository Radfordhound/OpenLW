#include "Hedgehog/Rsdx/System/RsdxMutex.h"

namespace hh
{
namespace rsdx
{
void RsdxInitializeMutex(RsdxMutex* mutex, bool param_2)
{
#ifdef _WIN32
    InitializeCriticalSection(mutex);
#elif defined(__WIIU__)
    OSInitMutex(mutex);
#endif
}

void RsdxLockMutex(RsdxMutex* mutex)
{
#ifdef _WIN32
    EnterCriticalSection(mutex);
#elif defined(__WIIU__)
    OSLockMutex(mutex);
#endif
}

void RsdxUnlockMutex(RsdxMutex* mutex)
{
#ifdef _WIN32
    LeaveCriticalSection(mutex);
#elif defined(__WIIU__)
    OSUnlockMutex(mutex);
#endif
}

void RsdxInitializeMutex2(RsdxMutex2* mutex, bool param_2)
{
#ifdef _WIN32
    RsdxInitializeMutex(&mutex->Mutex, true);
#else
    mutex->Handle = RsdxAllocateDefaultMemory(0, 0x2c, 0x10);
    RsdxInitializeMutex(mutex->Handle, true);
#endif
}

void RsdxLockMutex2(RsdxMutex2* mutex)
{
#ifdef _WIN32
    RsdxLockMutex(&mutex->Mutex);
#else
    RsdxLockMutex(mutex->Handle);
#endif
}

void RsdxUnlockMutex2(RsdxMutex2* mutex)
{
#ifdef _WIN32
    RsdxUnlockMutex(&mutex->Mutex);
#else
    RsdxUnlockMutex(mutex->Handle);
#endif
}
}
}
