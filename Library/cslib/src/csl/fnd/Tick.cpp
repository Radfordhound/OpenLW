#include "csl/fnd/Tick.h"

#ifdef _WIN32
#include <windows.h>
#else
#error Non-Windows platforms are not currently supported
#endif

namespace csl
{
namespace fnd
{
void Tick::Sample(Tick* tick)
{
#ifdef _WIN32
    LARGE_INTEGER counter;
    if (!QueryPerformanceCounter(&counter))
    {
        tick->Value = 0;
        return;
    }

    tick->Value = counter.QuadPart;
#else
#error Non-Windows platforms are not currently supported
#endif
}
}
}
