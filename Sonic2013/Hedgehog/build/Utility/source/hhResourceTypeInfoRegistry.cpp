#include "Hedgehog/Utility/hhResourceTypeInfoRegistry.h"
#include "Hedgehog/Utility/hhResGeneralTypeInfo.h"
#include "Hedgehog/Utility/hhResDependTypeInfo.h"
#include "Hedgehog/Utility/hhResShaderAcTypeInfo.h"
#include <Hedgehog/Graphics/Resource/hhResMirageVertexShaderCodeTypeInfo.h>
#include <Hedgehog/Graphics/Resource/hhResMirageVertexShaderParameterTypeInfo.h>
#include <Hedgehog/Graphics/Resource/hhResMiragePixelShaderCodeTypeInfo.h>
#include <Hedgehog/Graphics/Resource/hhResMiragePixelShaderParameterTypeInfo.h>
#include <climits>
#include <cstddef>

using namespace hh::gfx::res;

namespace hh
{
namespace ut
{
const ResourceTypeInfo* const ResourceTypeInfoRegistry::ResourceTypes[] =
{
    &ResRawDataTypeInfo,
    &ResDependTypeInfo,
    // TODO
    &ResFragmentShaderTypeInfo,
    // TODO
    &ResVertexShaderTypeInfo,
    // TODO
    &ResMiragePixelShaderCodeTypeInfo,
    &ResMiragePixelShaderParameterTypeInfo,
    // TODO
    &ResMirageVertexShaderCodeTypeInfo,
    &ResMirageVertexShaderParameterTypeInfo,
    // TODO
    nullptr
};

unsigned int ResourceTypeInfoRegistry::CreateHash(const char* type)
{
    unsigned int hash = 0;
    while (*type != '\0')
    {
        hash = ((hash * 31) + static_cast<unsigned int>(*type));
        ++type;
    }

    return (hash & INT_MAX);
}

void ResourceTypeInfoRegistry::RegisterList(const ResourceTypeInfo* const* typeInfo)
{
    m_typeInfo = typeInfo;

    ResourceTypeInfo* curTypeInfo = const_cast<ResourceTypeInfo*>(*typeInfo);
    std::size_t i = 0;

    while (curTypeInfo)
    {
        if (curTypeInfo->CreateLoader)
        {
            curTypeInfo->Loader = curTypeInfo->CreateLoader();
        }

        curTypeInfo->Hash = CreateHash(curTypeInfo->Type);
        curTypeInfo = const_cast<ResourceTypeInfo*>(typeInfo[++i]);
    }
}

ResourceTypeInfoRegistry::ResourceTypeInfoRegistry() :
    m_typeInfo(nullptr)
{
    RegisterList(ResourceTypes);
};

namespace detail
{
// Wii U: 0x03695aa0, PC: TODO
static const ResourceTypeInfo* GetResourceTypeInfo(unsigned int hash,
    const ResourceTypeInfo* const* typeInfo)
{
    for (std::size_t i = 0; typeInfo[i]; ++i)
    {
        if (typeInfo[i]->Hash == hash)
        {
            return typeInfo[i];
        }
    }

    return nullptr;
}
}

using namespace detail;

bool ResourceTypeInfoRegistry::PrepareReplaceLoadedResource(void* data,
    unsigned int typeHash, std::size_t* size, SLoadedResourceParameter* param_4)
{
    if (param_4)
    {
        const ResourceTypeInfo* resTypeInfo = GetResourceTypeInfo(typeHash, m_typeInfo);
        if (resTypeInfo && resTypeInfo->Loader)
        {
            return resTypeInfo->Loader->PrepareReplaceLoadedResource(data, typeHash, param_4); // TODO: Is this line correct??
        }
    }

    return false;
}

void* ResourceTypeInfoRegistry::ReplaceLoadedResource(const char* resName, void* data,
    unsigned int typeHash, std::size_t* size, csl::fnd::IAllocator* allocator)
{
    if (data)
    {
        const ResourceTypeInfo* resTypeInfo = GetResourceTypeInfo(typeHash, m_typeInfo);
        if (resTypeInfo && resTypeInfo->Loader)
        {
            return resTypeInfo->Loader->ReplaceLoadedResource(resName, data, size, allocator); // TODO: Is this line correct??
        }
    }

    return nullptr;
}

bool ResourceTypeInfoRegistry::FinishLoadedResource(void* data, unsigned int typeHash,
    std::size_t size, csl::fnd::IAllocator* allocator)
{
    if (data)
    {
        const ResourceTypeInfo* resTypeInfo = GetResourceTypeInfo(typeHash, m_typeInfo);
        if (resTypeInfo && resTypeInfo->Loader)
        {
            return resTypeInfo->Loader->FinishLoadedResource(data, size, allocator); // TODO: Is this line correct??
        }
    }

    return false;
}

bool ResourceTypeInfoRegistry::BindLoadedResource(void* data, unsigned int typeHash,
    std::size_t size, Packfile pac, csl::fnd::IAllocator* allocator)
{
    if (data)
    {
        const ResourceTypeInfo* resTypeInfo = GetResourceTypeInfo(typeHash, m_typeInfo);
        if (resTypeInfo && resTypeInfo->Loader)
        {
            return resTypeInfo->Loader->BindLoadedResource(data, size, allocator, pac);
        }
    }

    return false;
}
}
}
