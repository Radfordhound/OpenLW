#include "Atomic.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#elif defined(__WIIU__)
#include <coreinit/atomic.h>
#endif

namespace app
{
AtomicBase AtomicInc(Atomic& v)
{
#ifdef _WIN32
    return InterlockedIncrement(&v);
#elif defined(__WIIU__)
    return OSAddAtomic(&v, 1);
#endif
}

// TODO: Is this function actually a thing?
AtomicBase AtomicDec(Atomic& v)
{
#ifdef _WIN32
    return InterlockedDecrement(&v);
#elif defined(__WIIU__)
    return OSAddAtomic(&v, -1);
#endif
}
}
