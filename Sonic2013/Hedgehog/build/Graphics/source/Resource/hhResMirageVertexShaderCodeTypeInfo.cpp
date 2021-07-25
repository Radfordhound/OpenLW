#include "Hedgehog/Graphics/Resource/hhResMirageVertexShaderCodeTypeInfo.h"
#include "Hedgehog/Graphics/Resource/hhResMirageVertexShaderCode.h"

using namespace hh::ut;
using namespace hh::gfx::res;

// Wii U: 0x03685890, PC: TODO
static IResourceLoader* CreateResMirageVertexShaderCodeResourceLoader()
{
    return new ResMirageVertexShaderCodeLoader();
}

namespace hh
{
namespace gfx
{
namespace res
{
ResMirageVertexShaderCodeLoader::~ResMirageVertexShaderCodeLoader() {}

void* ResMirageVertexShaderCodeLoader::ReplaceLoadedResource(const char* name,
    void* data, std::size_t* size, csl::fnd::IAllocator* allocator)
{
    ResMirageVertexShaderCode vtxShaderCode(data);
    return vtxShaderCode.Replace(size, allocator);
}

bool ResMirageVertexShaderCodeLoader::FinishLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator)
{
    ResMirageVertexShaderCode vtxShaderCode(data);
    return vtxShaderCode.Setup(size, allocator);
}

bool ResMirageVertexShaderCodeLoader::BindLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile packfile)
{
    ResMirageVertexShaderCode vtxShaderCode(data);
    return vtxShaderCode.Setup(size, allocator, packfile);
}

void ResMirageVertexShaderCodeLoader::CleanupLoadedResource(void* data, std::size_t size)
{
    // TODO: Un-comment the following:
    /*ResMirageVertexShaderCode vtxShaderCode(data);
    return vtxShaderCode.Cleanup(size);*/
}

ut::ResourceTypeInfo ResMirageVertexShaderCodeTypeInfo =
{
    "ResMirageVertexShaderCode",                                        // Type
    CreateResMirageVertexShaderCodeResourceLoader                       // CreateLoader
};
}
}
}
