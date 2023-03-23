#pragma once

// OpenLW
#define OPENLW_PRIVATE private:
#define OPENLW_PROTECTED protected:
#define OPENLW_STD_NAMESPACE ::std::

// LWAPI
#define LWAPI(addrWiiU, addrPC)
#define LWAPI_STATIC_ASSERT_SIZE(type, size)

// Standard library includes
#include <cstdint>
#include <cstring>

// Win32 includes
#ifdef _WIN32
#include <Windows.h>
#endif
