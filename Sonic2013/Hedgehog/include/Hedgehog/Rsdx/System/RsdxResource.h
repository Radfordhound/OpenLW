#pragma once
#include "RsdxObject.h"

namespace hh
{
namespace rsdx
{
#ifdef _WIN32
typedef IDirect3DResource9 RsdxResource;
#else
struct RsdxResource : public RsdxRefcountObject
{
    // TODO
};
#endif
}
}
