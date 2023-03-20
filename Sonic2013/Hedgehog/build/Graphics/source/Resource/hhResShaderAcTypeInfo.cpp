#include "pch.h"
#include "Hedgehog/Graphics/Resource/hhResShaderAcTypeInfo.h"
#include "Hedgehog/Graphics/Resource/hhResVertexShader.h"
#include "Hedgehog/Graphics/Resource/hhResFragmentShader.h"
#include "Hedgehog/Graphics/Resource/hhResShaderAc.h"

using namespace hh::ut;
using namespace hh::gfx::res;

LWAPI(0x03689818, TODO)
static IResourceLoader* CreateResVertexShaderResourceLoader()
{
    return new ResVertexShaderLoader();
}

LWAPI(0x03689850, TODO)
static IResourceLoader* CreateResFragmentShaderResourceLoader()
{
    return new ResFragmentShaderLoader();
}

LWAPI(0x03689888, TODO)
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

ResShaderLoader::~ResShaderLoader() {}

void* ResShaderLoader::ReplaceLoadedResource(const char* name,
    void* data, std::size_t* size, csl::fnd::IAllocator* allocator)
{
    ResShader shader(data);
    return shader.Replace(name, size, allocator);
}

bool ResShaderLoader::FinishLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator)
{
    ResShader shader(data);
    return shader.Setup(size, allocator);
}

bool ResShaderLoader::BindLoadedResource(void* data,
    std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile packfile)
{
    ResShader shader(data);
    return shader.Setup(size, allocator, packfile);
}

void ResShaderLoader::CleanupLoadedResource(void* data, std::size_t size)
{
    ResShader shader(data);
    shader.Cleanup(size);
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
