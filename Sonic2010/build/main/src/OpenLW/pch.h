#pragma once

// OpenLW
#define OPENLW_PRIVATE private:
#define OPENLW_PROTECTED protected:

// LWAPI
#define LWAPI(addrWiiU, addrPC)

// Standard library includes
#include <cstring>

// Win32 includes
#ifdef _WIN32
#include <Windows.h>
#include <d3d9.h>

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#endif
