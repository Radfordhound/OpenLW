#include "pch.h"
#include "Hedgehog/Graphics/Resource/hhResMirageVertexShaderCode.h"
#include "Hedgehog/Graphics/Resource/hhResMirageVertexShaderCodeTypeInfo.h"
#include "Hedgehog/Graphics/hhGraphics.h"
#include <csl/fnd/memory.h>

using namespace hh::mr;
using namespace hh::gfx::internal;

namespace hh
{
namespace gfx
{
namespace res
{
LWAPI(0x036856ac, TODO)
static std::size_t CalcSize()
{
    return (sizeof(ResMirageVertexShaderCodeData) + sizeof(CVertexShaderCodeData));
}

LWAPI(0x036856b4, TODO)
static void Make(ResMirageVertexShaderCodeData* param_1,
    const u32* param_2, csl::fnd::IAllocator* allocator)
{
    param_1->CodeData = ::new (param_1 + 1) CVertexShaderCodeData();

    param_1->CodeData->Make(param_1->CodeData,
        param_2, GetRenderingInfrastructure());

    param_1->Allocator = allocator;
}

const ut::ResourceTypeInfo& ResMirageVertexShaderCode::staticTypeInfo()
{
    return ResMirageVertexShaderCodeTypeInfo;
}

void* ResMirageVertexShaderCode::Replace(std::size_t* size, csl::fnd::IAllocator* allocator)
{
    const std::size_t newSize = CalcSize();
    auto newData = static_cast<ResMirageVertexShaderCodeData*>(allocator->Alloc(newSize));

    Make(newData, reinterpret_cast<const u32*>(ptr()), allocator);

    *size = newSize;
    return newData;
}

bool ResMirageVertexShaderCode::Setup(std::size_t size, csl::fnd::IAllocator* allocator)
{
    return false;
}

bool ResMirageVertexShaderCode::Setup(std::size_t size,
    csl::fnd::IAllocator* allocator, ut::Packfile packfile)
{
    return false;
}
}
}
}
