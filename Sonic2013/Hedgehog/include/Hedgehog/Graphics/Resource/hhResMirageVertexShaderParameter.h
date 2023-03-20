#pragma once
#include "hhResShaderConstantUsage.h"
#include <Hedgehog/Utility/hhResource.h>
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResMirageVertexShaderParameterData
{
    mr::CVertexShaderParameterData* field_0x0;
    ResShaderConstantUsageData* FloatConstants;
    ResShaderConstantUsageData* IntConstants;
    ResShaderConstantUsageData* BoolConstants;
    std::size_t FloatConstantCount;
    std::size_t IntConstantCount;
    std::size_t BoolConstantCount;
    csl::fnd::IAllocator* Allocator;
};

struct ResMirageVertexShaderParameter : ut::ResCommon<ResMirageVertexShaderParameterData>
{
    LWAPI(0x03687778, TODO)
    static const ut::ResourceTypeInfo& staticTypeInfo();

    LWAPI(0x036878dc, 0x00c15570)
    void* Replace(std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x03687a48, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    LWAPI(0x03687a50, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile pac);

    inline ResMirageVertexShaderParameter(const void* data) :
        ResCommon<ResMirageVertexShaderParameterData>(data) {}

    inline ResMirageVertexShaderParameter(void* data = nullptr) :
        ResCommon<ResMirageVertexShaderParameterData>(data) {}
};
}
}
}
