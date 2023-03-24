// TODO: Both the name of this file and its path were guessed!
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
} // fnd
} // csl
