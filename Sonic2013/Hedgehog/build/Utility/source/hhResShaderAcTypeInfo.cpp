#include "Hedgehog/Utility/hhResShaderAcTypeInfo.h"
#include <Hedgehog/Graphics/Resource/hhResVertexShader.h>

using namespace hh::ut;
using namespace hh::gfx::res;

// Wii U: 0x03689818, PC: TODO
static IResourceLoader* CreateResVertexShaderResourceLoader()
{
    return new ResVertexShaderLoader();
}

// Wii U: 0x03689850, PC: TODO
static IResourceLoader* CreateResFragmentShaderResourceLoader()
{
    return new ResFragmentShaderLoader();
}

// Wii U: 0x03689888, PC: TODO
static IResourceLoader* CreateResShaderResourceLoader()
{
    return new ResShaderLoader();
}

namespace hh
{
namespace ut
{
ResVertexShaderLoader::~ResVertexShaderLoader() {}

void* ResVertexShaderLoader::ReplaceLoadedResource(const char* name,
    void* data, std::size_t* size, csl::fnd::IAllocator* allocator)
{
    ResVertexShader vtxShader(data);
    return vtxShader.Replace(size, allocator);
}

bool ResVertexShaderLoader::FinishLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator)
{
    ResVertexShader vtxShader(data);
    return vtxShader.Setup(size, allocator);
}

bool ResVertexShaderLoader::BindLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator, Packfile packfile)
{
    ResVertexShader vtxShader(data);
    return vtxShader.Setup(size, allocator, packfile);
}

void ResVertexShaderLoader::CleanupLoadedResource(void* data, std::size_t size)
{
    ResVertexShader vtxShader(data);
    vtxShader.Cleanup(size);
}

ResourceTypeInfo ResVertexShaderTypeInfo =
{
    "ResMirageVertexShader",                                            // Type
    CreateResVertexShaderResourceLoader                                 // CreateLoader
};

ResourceTypeInfo ResFragmentShaderTypeInfo =
{
    "ResMiragePixelShader",                                             // Type
    CreateResFragmentShaderResourceLoader                               // CreateLoader
};

ResourceTypeInfo ResShaderTypeInfo =
{
    "ResMirageShaderList",                                              // Type
    CreateResShaderResourceLoader                                       // CreateLoader
};
}
}
