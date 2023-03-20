#include "pch.h"
#include "Hedgehog/Graphics/Resource/hhResMirageVertexShaderParameterTypeInfo.h"
#include "Hedgehog/Graphics/Resource/hhResMirageVertexShaderParameter.h"

using namespace hh::ut;
using namespace hh::gfx::res;

LWAPI(0x03687b08, TODO)
static IResourceLoader* CreateResMirageVertexShaderParameterResourceLoader()
{
    return new ResMirageVertexShaderParameterLoader();
}

namespace hh
{
namespace gfx
{
namespace res
{
ResMirageVertexShaderParameterLoader::~ResMirageVertexShaderParameterLoader() {}

void* ResMirageVertexShaderParameterLoader::ReplaceLoadedResource(const char* name,
    void* data, std::size_t* size, csl::fnd::IAllocator* allocator)
{
    ResMirageVertexShaderParameter vtxShaderParam(data);
    return vtxShaderParam.Replace(size, allocator);
}

bool ResMirageVertexShaderParameterLoader::FinishLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator)
{
    ResMirageVertexShaderParameter vtxShaderParam(data);
    return vtxShaderParam.Setup(size, allocator);
}

bool ResMirageVertexShaderParameterLoader::BindLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile packfile)
{
    ResMirageVertexShaderParameter vtxShaderParam(data);
    return vtxShaderParam.Setup(size, allocator, packfile);
}

void ResMirageVertexShaderParameterLoader::CleanupLoadedResource(void* data, std::size_t size)
{
    // TODO
}

ut::ResourceTypeInfo ResMirageVertexShaderParameterTypeInfo =
{
    "ResMirageVertexShaderParameter",                                   // Type
    CreateResMirageVertexShaderParameterResourceLoader                  // CreateLoader
};
}
}
}
