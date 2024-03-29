#include "pch.h"
#include "Hedgehog/Utility/hhResource.h"
#include "Hedgehog/Utility/hhResDictionary.h"

using namespace hh::ut::pac;

namespace hh
{
namespace ut
{
IResourceLoader::~IResourceLoader() {}

bool IResourceLoader::PrepareReplaceLoadedResource(void* data,
    unsigned int typeHash, SLoadedResourceParameter* args)
{
    return false;
}

void* IResourceLoader::ReplaceLoadedResource(const char* name, void* data,
    std::size_t* size, csl::fnd::IAllocator* allocator)
{
    return nullptr;
}

bool IResourceLoader::FinishLoadedResource(void* data, std::size_t size,
    csl::fnd::IAllocator* allocator)
{
    return false;
}

bool IResourceLoader::BindLoadedResource(void* data, std::size_t size,
    csl::fnd::IAllocator* allocator, Packfile packfile)
{
    return false;
}

void IResourceLoader::CleanupLoadedResource(void* data, std::size_t size) {}

void* ResourceTypeInfo::GetLoadedResourceHeaderByName(unsigned int version,
    const char* type, Packfile pac, const char* name)
{
    ResPackfileHeader header(pac.Handle);
    if (header.ref().NodeCount != 0)
    {
        void* nextBlock = header.GetNextBlock(version);
        if (nextBlock)
        {
            void* nodeDicPtr = GetNodeDicPointer(version, type, nextBlock);
            if (nodeDicPtr)
            {
                ResDicLinear dic(nodeDicPtr);
                int index = dic.GetIndex(name);

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
    const char* type, Packfile pac, const char* name,
    std::size_t* size)
{
    void* resHeader = GetLoadedResourceHeaderByName(
        version, type, pac, name);

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

void* ResourceTypeInfo::GetLoadedResourceHeaderByIndex(unsigned int version,
    const char* type, Packfile pac, int index)
{
    ResPackfileHeader header(pac.Handle);
    if (header.ref().NodeCount != 0)
    {
        void* nextBlock = header.GetNextBlock(version);
        if (nextBlock)
        {
            void* nodeDicPtr = GetNodeDicPointer(version, type, nextBlock);
            if (nodeDicPtr)
            {
                ResDicLinear dic(nodeDicPtr);

                return (version >= 2) ? dic[index] : (static_cast<u8*>(
                    dic[index]) - sizeof(ResPackfileBlockDataHeaderDataTag));
            }
        }
    }

    return nullptr;
}

void* ResourceTypeInfo::FindLoadedResourceByIndex(unsigned int version,
    const char* type, Packfile pac, int index,
    std::size_t* size)
{
    void* resHeader = GetLoadedResourceHeaderByIndex(
        version, type, pac, index);

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

std::size_t ResourceTypeInfo::GetLoadedResourceCount(
    unsigned int version, const char* type, Packfile pac)
{
    ResPackfileHeader header(pac.Handle);
    if (header.ref().NodeCount != 0)
    {
        void* dataBlock = header.GetNextBlock(version);
        if (dataBlock)
        {
            void* dicPtr = GetNodeDicPointer(version, type, dataBlock);
            if (dicPtr)
            {
                ResDicLinear dic(dicPtr);
                return dic.ref().Count;
            }
        }
    }

    return 0;
}
}
}
