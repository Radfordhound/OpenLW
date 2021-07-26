#pragma once
#include "../../System/RsdxObject.h"

namespace hh
{
namespace rsdx
{
#ifdef _WIN32
typedef IDirect3DVertexShader9 RsdxVertexShader9;
typedef IDirect3DPixelShader9 RsdxPixelShader9;
#else
class RsdxVertexShader9 // TODO: Inheritance
{
    // TODO
};

class RsdxPixelShader9 // TODO: Inheritance
{
    // TODO
};
#endif
}
}
