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

void* ResVertexShaderLoader::ReplaceLoadedResource(const char* param_1,
    void* param_2, std::size_t* param_3, csl::fnd::IAllocator* allocator)
{
    ResVertexShader vtxShader(param_2);
    return vtxShader.Replace(param_3, allocator);
}

void ResVertexShaderLoader::FinishLoadedResource(void* param_1,
    std::size_t param_2, csl::fnd::IAllocator* allocator)
{
    ResVertexShader vtxShader(param_1);
    vtxShader.Setup(param_2, allocator);
}

void ResVertexShaderLoader::BindLoadedResource(void* param_1,
    std::size_t param_2, csl::fnd::IAllocator* allocator, Packfile packfile)
{
    ResVertexShader vtxShader(param_1);
    vtxShader.Setup(param_2, allocator, packfile);
}

void ResVertexShaderLoader::CleanupLoadedResource(void* param_1,
    std::size_t param_2)
{
    ResVertexShader vtxShader(param_1);
    vtxShader.Cleanup(param_2);
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
