#include "pch.h"
#include "Hedgehog/Graphics/Resource/hhResMiragePixelShaderParameterTypeInfo.h"
#include "Hedgehog/Graphics/Resource/hhResMiragePixelShaderParameter.h"

using namespace hh::ut;
using namespace hh::gfx::res;

LWAPI(0x03684754, TODO)
static IResourceLoader* CreateResMiragePixelShaderParameterResourceLoader()
{
    return new ResMiragePixelShaderParameterLoader();
}

namespace hh
{
namespace gfx
{
namespace res
{
ResMiragePixelShaderParameterLoader::~ResMiragePixelShaderParameterLoader() {}

void* ResMiragePixelShaderParameterLoader::ReplaceLoadedResource(const char* name,
    void* data, std::size_t* size, csl::fnd::IAllocator* allocator)
{
    ResMiragePixelShaderParameter pixelShaderParam(data);
    return pixelShaderParam.Replace(size, allocator);
}

bool ResMiragePixelShaderParameterLoader::FinishLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator)
{
    ResMiragePixelShaderParameter pixelShaderParam(data);
    return pixelShaderParam.Setup(size, allocator);
}

bool ResMiragePixelShaderParameterLoader::BindLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile packfile)
{
    ResMiragePixelShaderParameter pixelShaderParam(data);
    return pixelShaderParam.Setup(size, allocator, packfile);
}

void ResMiragePixelShaderParameterLoader::CleanupLoadedResource(void* data, std::size_t size)
{
    // TODO
}

ut::ResourceTypeInfo ResMiragePixelShaderParameterTypeInfo =
{
    "ResMiragePixelShaderParameter",                                    // Type
    CreateResMiragePixelShaderParameterResourceLoader                   // CreateLoader
};
}
}
}
