#include "Hedgehog/Graphics/Resource/hhResShaderSamplerUsage.h"

namespace hh
{
namespace gfx
{
namespace res
{
ResName ResShaderSamplerUsage::GetName()
{
    return ResName(&ptr()->Name);
}
}
}
}
