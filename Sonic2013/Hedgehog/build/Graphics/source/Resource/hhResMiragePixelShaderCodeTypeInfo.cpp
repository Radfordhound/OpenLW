#include "Hedgehog/Graphics/Resource/hhResMiragePixelShaderCodeTypeInfo.h"
#include "Hedgehog/Graphics/Resource/hhResMiragePixelShaderCode.h"

using namespace hh::ut;
using namespace hh::gfx::res;

// Wii U: 0x03680a68, PC: TODO
static IResourceLoader* CreateResMiragePixelShaderCodeResourceLoader()
{
    return new ResMiragePixelShaderCodeLoader();
}

namespace hh
{
namespace gfx
{
namespace res
{
ResMiragePixelShaderCodeLoader::~ResMiragePixelShaderCodeLoader() {}

void* ResMiragePixelShaderCodeLoader::ReplaceLoadedResource(const char* name,
    void* data, std::size_t* size, csl::fnd::IAllocator* allocator)
{
    ResMiragePixelShaderCode pixelShaderCode(data);
    return pixelShaderCode.Replace(size, allocator);
}

bool ResMiragePixelShaderCodeLoader::FinishLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator)
{
    ResMiragePixelShaderCode pixelShaderCode(data);
    return pixelShaderCode.Setup(size, allocator);
}

bool ResMiragePixelShaderCodeLoader::BindLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile packfile)
{
    ResMiragePixelShaderCode pixelShaderCode(data);
    return pixelShaderCode.Setup(size, allocator, packfile);
}

void ResMiragePixelShaderCodeLoader::CleanupLoadedResource(void* data, std::size_t size)
{
    // TODO: Un-comment the following:
    /*ResMiragePixelShaderCode pixelShaderCode(data);
    return pixelShaderCode.Cleanup(size);*/
}

ut::ResourceTypeInfo ResMiragePixelShaderCodeTypeInfo =
{
    "ResMiragePixelShaderCode",                                         // Type
    CreateResMiragePixelShaderCodeResourceLoader                        // CreateLoader
};
}
}
}
