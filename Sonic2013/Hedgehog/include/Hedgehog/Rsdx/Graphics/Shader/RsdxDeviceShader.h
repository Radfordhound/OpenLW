#pragma once
#include "../../System/RsdxObject.h"

namespace hh
{
namespace rsdx
{
#ifdef _WIN32
typedef IDirect3DVertexShader9 RsdxVertexShader9;
#else
class RsdxVertexShader9 // TODO: Inheritance
{
    // TODO
};
#endif
}
}
