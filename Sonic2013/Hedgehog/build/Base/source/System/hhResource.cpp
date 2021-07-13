#include "Hedgehog/Base/System/hhResource.h"

namespace hh
{
namespace ut
{
IResourceLoader::~IResourceLoader() {}

bool IResourceLoader::PrepareReplaceLoadedResource(void* param_1,
    std::size_t param_2, SLoadedResourceParameter* args)
{
    return false;
}

bool IResourceLoader::ReplaceLoadedResource(const char* param_1, void* param_2,
    std::size_t* param_3, csl::fnd::IAllocator* allocator)
{
    return false;
}

bool IResourceLoader::FinishLoadedResource(void* param_1, std::size_t param_2,
    csl::fnd::IAllocator* allocator)
{
    return false;
}

bool IResourceLoader::BindLoadedResource(void* param_1, std::size_t param_2,
    csl::fnd::IAllocator* allocator, Packfile packfile)
{
    return false;
}

void IResourceLoader::CleanupLoadedResource(void* param_1, std::size_t param_2) {}
}
}
