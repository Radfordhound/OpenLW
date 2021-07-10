#include "csl/fnd/tick.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace csl
{
namespace fnd
{
static LARGE_INTEGER PerformanceFrequency;

long long Tick::ToMicroseconds() const
{
    return ((Value * 1000000LL) / PerformanceFrequency.QuadPart);
}

void Tick::Initialize()
{
    QueryPerformanceFrequency(&PerformanceFrequency);
}

void Tick::Finalize() {}

Tick Tick::Sample()
{
    LARGE_INTEGER counter;
    return Tick((QueryPerformanceCounter(&counter)) ? 
        counter.QuadPart : 0);
}
}
}
