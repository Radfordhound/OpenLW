#include "pch.h"
#include "csl/fnd/thread.h"

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
