#include "Hedgehog/Utility/hhResource.h"
#include "Hedgehog/Utility/hhResDictionary.h"

using namespace hh::ut::pac;

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

void* IResourceLoader::ReplaceLoadedResource(const char* param_1, void* param_2,
    std::size_t* param_3, csl::fnd::IAllocator* allocator)
{
    return nullptr;
}

void IResourceLoader::FinishLoadedResource(void* param_1, std::size_t param_2,
    csl::fnd::IAllocator* allocator) {}

void IResourceLoader::BindLoadedResource(void* param_1, std::size_t param_2,
    csl::fnd::IAllocator* allocator, Packfile packfile) {}

void IResourceLoader::CleanupLoadedResource(void* param_1, std::size_t param_2) {}

void* ResourceTypeInfo::GetLoadedResourceHeaderByName(unsigned int version,
    const char* param_2, Packfile pac, const char* param_4)
{
    ResPackfileHeader header(pac.Handle);
    if (header.ref().NodeCount != 0)
    {
        void* nextBlock = header.GetNextBlock(version);
        if (nextBlock)
        {
            void* nodeDicPtr = GetNodeDicPointer(version, param_2, nextBlock);
            if (nodeDicPtr)
            {
                ResDicLinear dic(nodeDicPtr);
                int index = dic.GetIndex(param_4);

                if (index != -1)
                {
                    return (version >= 2) ? dic[index] : (static_cast<u8*>(
                        dic[index]) - sizeof(ResPackfileBlockDataHeaderDataTag));
                }
            }
        }
    }

    return nullptr;
}

void* ResourceTypeInfo::FindLoadedResourceByName(unsigned int version,
    const char* param_2, Packfile pac, const char* param_4,
    std::size_t* size)
{
    void* resHeader = GetLoadedResourceHeaderByName(
        version, param_2, pac, param_4);

    if (resHeader)
    {
        ResPackfileBlockDataHeaderData blockHeader(resHeader);

        if (size)
        {
            *size = blockHeader.ref().Size;
        }

        return blockHeader.ref().Data;
    }

    return nullptr;
}
}
}
