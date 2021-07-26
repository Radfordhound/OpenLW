#include "Hedgehog/Graphics/Resource/hhResMiragePixelShaderCode.h"
#include "Hedgehog/Graphics/Resource/hhResMiragePixelShaderCodeTypeInfo.h"
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
// Wii U: 0x03680884, PC: TODO
static std::size_t CalcSize()
{
    return (sizeof(ResMiragePixelShaderCodeData) + sizeof(CPixelShaderCodeData));
}

// Wii U: 0x0368088c, PC: TODO
static void Make(ResMiragePixelShaderCodeData* param_1,
    const u32* param_2, csl::fnd::IAllocator* allocator)
{
    param_1->CodeData = ::new (param_1 + 1) CPixelShaderCodeData();

    param_1->CodeData->Make(param_1->CodeData,
        param_2, GetRenderingInfrastructure());

    param_1->Allocator = allocator;
}

const ut::ResourceTypeInfo& ResMiragePixelShaderCode::staticTypeInfo()
{
    return ResMiragePixelShaderCodeTypeInfo;
}

void* ResMiragePixelShaderCode::Replace(std::size_t* size, csl::fnd::IAllocator* allocator)
{
    const std::size_t newSize = CalcSize();
    auto newData = static_cast<ResMiragePixelShaderCodeData*>(allocator->Alloc(newSize));

    Make(newData, reinterpret_cast<const u32*>(ptr()), allocator);

    *size = newSize;
    return newData;
}

bool ResMiragePixelShaderCode::Setup(std::size_t size, csl::fnd::IAllocator* allocator)
{
    return false;
}

bool ResMiragePixelShaderCode::Setup(std::size_t size,
    csl::fnd::IAllocator* allocator, ut::Packfile packfile)
{
    return false;
}
}
}
}
