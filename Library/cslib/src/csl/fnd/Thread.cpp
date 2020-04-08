#include "csl/fnd/Thread.h"
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
