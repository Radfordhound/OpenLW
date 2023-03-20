#pragma once
#include "hhResource.h"
#include <csl/fnd/singleton.h>

namespace hh
{
namespace ut
{
class ResourceTypeInfoRegistry : public csl::fnd::Singleton<ResourceTypeInfoRegistry>
{
    LWAPI(0x10031e40, TODO)
    static const ResourceTypeInfo* const ResourceTypes[];

    const ResourceTypeInfo* const* m_typeInfo;

public:
    LWAPI(0x03695964, 0x00c1a7f0)
    unsigned int CreateHash(const char* type);

    LWAPI(0x03695998, TODO)
    void RegisterList(const ResourceTypeInfo* const* typeInfo);

    LWAPI(0x03695a2c, TODO)
    ResourceTypeInfoRegistry();
    
    LWAPI(0x03695ae4, TODO)
    bool PrepareReplaceLoadedResource(void* data, unsigned int typeHash,
        std::size_t* size, SLoadedResourceParameter* param_4);

    LWAPI(0x03695b5c, TODO)
    void* ReplaceLoadedResource(const char* resName, void* data,
        unsigned int typeHash, std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x03695be0, TODO)
    bool FinishLoadedResource(void* data, unsigned int typeHash,
        std::size_t size, csl::fnd::IAllocator* allocator);

    LWAPI(0x03695c58, TODO)
    bool BindLoadedResource(void* data, unsigned int typeHash,
        std::size_t size, Packfile pac, csl::fnd::IAllocator* allocator);
};
}
}
