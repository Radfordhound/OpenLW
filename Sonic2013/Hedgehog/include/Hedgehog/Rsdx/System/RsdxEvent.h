#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
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

// Wii U: 0x036a7b24, PC: 0x00c25ad0
RsdxEventHandle RsdxCreateEvent(unsigned int param_1, unsigned int param_2);

// Wii U: 0x036a7bb0, PC: 0x00c25b20
bool RsdxSetEvent(RsdxEventHandle event);
}
}
