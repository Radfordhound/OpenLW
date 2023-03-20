#pragma once

// LWAPI
#define LWAPI(addrWiiU, addrPC)
#define LWAPI_PRIVATE private:
#define LWAPI_PROTECTED protected:

// Standard library includes
#include <math.h>

// Win32 includes
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif
