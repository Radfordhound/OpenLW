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

void RsdxDestroyEvent(RsdxEventHandle event)
{
#ifdef _WIN32
    CloseHandle(event); // TODO: Do we return this actually?
#elif defined(__WIIU__)
    // TODO
#endif
}

bool RsdxResetEvent(RsdxEventHandle event)
{
#ifdef _WIN32
    return (ResetEvent(event) != 0);
#elif defined(__WIIU__)
    OSResetEvent(event);
    return true;
#endif
}

bool RsdxSetEvent(RsdxEventHandle event)
{
#ifdef _WIN32
    BOOL r = SetEvent(event);
    return (!r);
#elif defined(__WIIU__)
    OSSignalEvent(event);
    return true;
#endif
}

bool RsdxWaitEvent(RsdxEventHandle event, unsigned int timeout)
{
#ifdef _WIN32
    return (WaitForSingleObject(event, timeout) == WAIT_OBJECT_0);
#elif defined(__WIIU__)
    if (event != -1)
    {
        return (OSWaitEventWithTimeout(event, timeout * 1000) != 0);
    }

    OSWaitEvent(event);
    return true;
#endif
}

bool RsdxCheckEvent(RsdxEventHandle event)
{
#ifdef _WIN32
    return (WaitForSingleObject(event, 0) == WAIT_OBJECT_0);
#elif defined(__WIIU__)
    return (OSWaitEventWithTimeout(event, 0) != 0);
#endif
}
}
}
