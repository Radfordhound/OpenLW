#include "pch.h"
#include "Hedgehog/Graphics/Resource/hhResMaterialAcTypeInfo.h"
#include "Hedgehog/Graphics/Resource/hhResMaterial.h"

using namespace hh::ut;
using namespace hh::gfx::res;

LWAPI(0x03688e24, TODO)
static IResourceLoader* CreateResMaterialResourceLoader()
{
    return new ResMaterialLoader();
}

namespace hh
{
namespace gfx
{
namespace res
{
ResMaterialLoader::~ResMaterialLoader() {}

void* ResMaterialLoader::ReplaceLoadedResource(const char* name,
    void* data, std::size_t* size, csl::fnd::IAllocator* allocator)
{
    ResMaterial mat(data);
    return mat.Replace(name, size, allocator);
}

bool ResMaterialLoader::FinishLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator)
{
    ResMaterial mat(data);
    return mat.Setup(size, allocator);
}

bool ResMaterialLoader::BindLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile packfile)
{
    ResMaterial mat(data);
    return mat.Setup(size, allocator, packfile);
}

void ResMaterialLoader::CleanupLoadedResource(void* data, std::size_t size)
{
    ResMaterial mat(data);
    mat.Cleanup(size);
}

ResourceTypeInfo ResMaterialTypeInfo =
{
    "ResMirageMaterial",                                                // Type
    CreateResMaterialResourceLoader                                     // CreateLoader
};
}
}
}
