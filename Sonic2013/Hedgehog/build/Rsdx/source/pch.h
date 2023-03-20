#pragma once

// LWAPI
#define LWAPI(addrWiiU, addrPC)
#define LWAPI_PRIVATE private:
#define LWAPI_PROTECTED protected:

// Standard library includes
#include <cstring>

// Win32 includes
#ifdef _WIN32
#include <Windows.h>
#include <process.h>
#include <d3d9.h>
#endif
