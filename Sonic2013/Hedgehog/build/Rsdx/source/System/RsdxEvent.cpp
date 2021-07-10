#include "Hedgehog/Rsdx/System/RsdxEvent.h"

namespace hh
{
namespace rsdx
{
RsdxEventHandle RsdxCreateEvent(unsigned int param_1, unsigned int param_2)
{
#ifdef _WIN32
    return CreateEventA(NULL, param_2, (param_1 != 0), NULL);
#elif defined(__WIIU__)
    // TODO
#endif
}

bool RsdxSetEvent(RsdxEventHandle event)
{
#ifdef _WIN32
    return (SetEvent(event) != 0);
#elif defined(__WIIU__)
    OSSignalEvent(event);
    return true;
#endif
}
}
}
