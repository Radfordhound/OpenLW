#pragma once
#include "hhResource.h"
#include <csl/fnd/singleton.h>

namespace hh
{
namespace ut
{
class ResourceTypeInfoRegistry : public csl::fnd::Singleton<ResourceTypeInfoRegistry>
{
    // Wii U: 0x10031e40, PC: TODO
    static const ResourceTypeInfo* const ResourceTypes[];

    const ResourceTypeInfo* const* m_typeInfo;

public:
    // Wii U: 0x03695964, PC: 0x00c1a7f0
    unsigned int CreateHash(const char* type);

    // Wii U: 0x03695998, PC: TODO
    void RegisterList(const ResourceTypeInfo* const* typeInfo);

    // Wii U: 0x03695a2c, PC: TODO
    ResourceTypeInfoRegistry();
    
    // Wii U: 0x03695ae4, PC: TODO
    bool PrepareReplaceLoadedResource(void* data, unsigned int typeHash,
        std::size_t* size, SLoadedResourceParameter* param_4);

    // Wii U: 0x03695b5c, PC: TODO
    void* ReplaceLoadedResource(const char* resName, void* data,
        unsigned int typeHash, std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x03695be0, PC: TODO
    bool FinishLoadedResource(void* data, unsigned int typeHash,
        std::size_t size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x03695c58, PC: TODO
    bool BindLoadedResource(void* data, unsigned int typeHash,
        std::size_t size, Packfile pac, csl::fnd::IAllocator* allocator);
};
}
}
