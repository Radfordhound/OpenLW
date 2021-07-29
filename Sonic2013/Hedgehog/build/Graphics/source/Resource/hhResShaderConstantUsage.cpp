#include "Hedgehog/Graphics/Resource/hhResShaderConstantUsage.h"

namespace hh
{
namespace gfx
{
namespace res
{
ResName ResShaderConstantUsage::GetName()
{
    return ResName(&ptr()->Name);
}
}
}
}
