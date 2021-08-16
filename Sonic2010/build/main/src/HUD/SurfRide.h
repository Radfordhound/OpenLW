#pragma once
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>

namespace app
{
namespace HUD
{
// Wii U: 0x022e0cc0, PC: 0x00530eb0
boost::shared_ptr<hh::mr::CVertexShaderData>
    CreateGetVertexShaderData(char* param_1);

// Wii U: 0x022e2d54, PC: 0x005311e0
boost::shared_ptr<hh::mr::CPixelShaderData>
    CreateGetPixelShaderData(char* param_1);
}
}
