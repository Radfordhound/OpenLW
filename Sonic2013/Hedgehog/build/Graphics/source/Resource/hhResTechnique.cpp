#include "Hedgehog/Graphics/Resource/hhResTechnique.h"

namespace hh
{
namespace gfx
{
namespace res
{
ResName ResTechnique::GetVSName()
{
    return ResName(&ptr()->VertexShaderName);
}

ResName ResTechnique::GetFSName()
{
    return ResName(&ptr()->PixelShaderName);
}
}
}
}
