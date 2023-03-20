#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#elif defined(__WIIU__)
#include <coreinit/event.h>
#endif

namespace hh
{
namespace rsdx
{
#ifdef _WIN32
typedef HANDLE RsdxEventHandle;
#elif defined(__WIIU__)
typedef OSEvent* RsdxEventHandle;
#endif

LWAPI(0x036a7b24, 0x00c25ad0)
RsdxEventHandle RsdxCreateEvent(unsigned int param_1, unsigned int param_2);

LWAPI(0x036a7b80, 0x00c25af0)
void RsdxDestroyEvent(RsdxEventHandle event);

LWAPI(0x036a7b8c, 0x00c25b00)
bool RsdxResetEvent(RsdxEventHandle event);

LWAPI(0x036a7bb0, 0x00c25b20)
bool RsdxSetEvent(RsdxEventHandle event);

LWAPI(0x036a7bd4, 0x00c25b40)
bool RsdxWaitEvent(RsdxEventHandle event, unsigned int timeout);

LWAPI(0x036a7c24, 0x00c25b60)
bool RsdxCheckEvent(RsdxEventHandle event);
}
}
