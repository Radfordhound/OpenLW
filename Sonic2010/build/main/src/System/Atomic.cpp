// TODO: This entire header was guessed. Is it all accurate?
#include "pch.h"
#include "Atomic.h"

#ifdef __WIIU__
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
