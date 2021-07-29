#include "Hedgehog/Graphics/Resource/hhResShaderConstant.h"

namespace hh
{
namespace gfx
{
namespace res
{
ResShaderConstantUsage ResShaderConstant::GetUsage(std::size_t index) const
{
    return (index < HH_COUNT_OF(ptr()->Usages)) ?
        ResShaderConstantUsage(ptr()->Usages[index]) :
        ResShaderConstantUsage();
}

ResName ResShaderConstant::GetUsageName()
{
    return ResName(&ptr()->UsageName);
}
}
}
}
