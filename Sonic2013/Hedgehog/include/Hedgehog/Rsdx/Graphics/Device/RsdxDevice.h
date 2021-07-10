#pragma once
#include "RsdxDevCore.h"

namespace hh
{
namespace rsdx
{
#ifdef _WIN32
typedef IDirect3DDevice9Ex RsdxDevice;
#else
// TODO
#endif
}
}
