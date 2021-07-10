#include "csl/fnd/thread.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace csl
{
namespace fnd
{
void ThreadSleep(unsigned int milliseconds)
{
    SleepEx(milliseconds, 0);
}
}
}
