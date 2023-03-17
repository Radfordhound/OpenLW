// TODO: This entire header was guessed. Is it all accurate?
#pragma once

#ifdef __WIIU__
#include <cstdint>
#endif

namespace app
{
#ifdef _WIN32
typedef long AtomicBase;
#elif defined(__WIIU__)
typedef std::int32_t AtomicBase;
#endif

typedef volatile AtomicBase Atomic;

// TODO: Is this function actually a thing?
AtomicBase AtomicInc(Atomic& v);

// TODO: Is this function actually a thing?
AtomicBase AtomicDec(Atomic& v);
}
