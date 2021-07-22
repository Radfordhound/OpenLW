#include "Hedgehog/Base/Resource/hhResourceTypeInfoRegistry.h"
#include "Hedgehog/Base/Resource/hhResGeneralTypeInfo.h"
#include <climits>
#include <cstddef>

namespace hh
{
namespace ut
{
const ResourceTypeInfo* const ResourceTypeInfoRegistry::ResourceTypes[] =
{
    &ResRawDataTypeInfo,
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
    unsigned int typeHash, unsigned int* param_3, SLoadedResourceParameter* param_4)
{
    const ResourceTypeInfo* resTypeInfo;
    if (param_4 && (resTypeInfo = GetResourceTypeInfo(typeHash, m_typeInfo)) &&
        resTypeInfo->Loader)
    {
        return resTypeInfo->Loader->PrepareReplaceLoadedResource(data, typeHash, param_4); // TODO: Is this line correct??
    }

    return false;
}
}
}
