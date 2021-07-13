#include "Hedgehog/Base/System/hhResourceTypeInfoRegistry.h"
#include "Hedgehog/Base/System/hhResGeneralTypeInfo.h"
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
}
}
