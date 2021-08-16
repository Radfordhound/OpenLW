#pragma once
#include "RsdxObject.h"

namespace hh
{
namespace rsdx
{
#ifdef _WIN32
typedef RsdxRefcountObject RsdxResource; // TODO: Is this correct?
#else
struct RsdxResource : public RsdxRefcountObject
{
    // TODO
};
#endif
}
}
