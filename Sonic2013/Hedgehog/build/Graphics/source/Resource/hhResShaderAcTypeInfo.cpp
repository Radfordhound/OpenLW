#include "Hedgehog/Graphics/Resource/hhResShaderAcTypeInfo.h"
#include "Hedgehog/Graphics/Resource/hhResVertexShader.h"
#include "Hedgehog/Graphics/Resource/hhResFragmentShader.h"

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
namespace gfx
{
namespace res
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
    std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile packfile)
{
    ResVertexShader vtxShader(data);
    return vtxShader.Setup(size, allocator, packfile);
}

void ResVertexShaderLoader::CleanupLoadedResource(void* data, std::size_t size)
{
    ResVertexShader vtxShader(data);
    vtxShader.Cleanup(size);
}

ResFragmentShaderLoader::~ResFragmentShaderLoader() {}

void* ResFragmentShaderLoader::ReplaceLoadedResource(const char* name,
    void* data, std::size_t* size, csl::fnd::IAllocator* allocator)
{
    ResFragmentShader pixelShader(data);
    return pixelShader.Replace(size, allocator);
}

bool ResFragmentShaderLoader::FinishLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator)
{
    ResFragmentShader pixelShader(data);
    return pixelShader.Setup(size, allocator);
}

bool ResFragmentShaderLoader::BindLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile packfile)
{
    ResFragmentShader pixelShader(data);
    return pixelShader.Setup(size, allocator, packfile);
}

void ResFragmentShaderLoader::CleanupLoadedResource(void* data, std::size_t size)
{
    ResFragmentShader pixelShader(data);
    pixelShader.Cleanup(size);
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
}
