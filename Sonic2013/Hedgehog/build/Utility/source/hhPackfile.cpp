#include "Hedgehog/Utility/hhPackfile.h"
#include "Hedgehog/Utility/hhResDictionary.h"
#include "Hedgehog/Utility/hhResDependTypeInfo.h"
#include "Hedgehog/Utility/hhResourceTypeInfoRegistry.h"
#include <cstring>

using namespace hh::ut::pac;

namespace hh
{
namespace ut
{
const ResourceTypeInfo& ResDepend::staticTypeInfo()
{
    return ResDependTypeInfo;
}

unsigned int ResPackfileHeader::GetMajorVersion() const
{
    switch (ref().Version[0])
    {
    case '1':
        return 1;

    case '2':
        return 2;

    default:
        return 0;
    }
}

bool ResPackfileHeader::IsValidHeader() const
{
    return (IsValid() && CheckPacHeader(ptr()));
}

void ResPackfileHeader::ConvertEndian()
{
    // TODO
}

void* ResPackfileHeader::GetNextBlock(unsigned int version, void* block)
{
    if (!block)
    {
        if (version < 2)
        {
            ResPackfileBlockV1Header blockV1(ptr() + 1);
            return blockV1.ptr();
        }
        else
        {
            ResPackfileBlockV2Header blockV2(ptr() + 1);
            return blockV2.ptr();
        }
    }
    else
    {
        if (version < 2)
        {
            ResPackfileBlockV1Header blockV1;
            return (reinterpret_cast<u8*>(blockV1.ptr()) + blockV1.ref().Size);
        }
        else
        {
            ResPackfileBlockV2Header blockV2;
            return (reinterpret_cast<u8*>(blockV2.ptr()) + blockV2.ref().Size);
        }
    }
}

u32 ResPackfileBlockV1Header::GetSignature() const
{
    return ResFileCommon::GetReverseBigEndian(ref().Signature);
}

// TODO: This name was guessed.
// Wii U: 0x102c0690, PC: TODO
static const u32 PackfileBlockTypes[] = // TODO: Should this be moved somewhere else?
{
    HH_MAKE_SIG('D', 'A', 'T', 'A'),
    HH_MAKE_SIG('I', 'M', 'A', 'G')
};

int ResPackfileBlockV1Header::GetSignatureId() const
{
    for (int i = 0; i < HH_COUNT_OF(PackfileBlockTypes); ++i)
    {
        if (PackfileBlockTypes[i] == GetSignature())
        {
            return i;
        }
    }

    return -1;
}

void* ResPackfileBlockV1Header::GetDicAddress()
{
    return (ptr() + 1);
}

void* ResPackfileBlockV2Header::GetDicAddress()
{
    return (ptr() + 1);
}

void* ResPackfileBlockV2Header::GetDataAddress()
{
    return (static_cast<u8*>(GetDicAddress()) + ref().DicSize);
}

void* ResPackfileBlockV2Header::GetImportAddress()
{
    return (static_cast<u8*>(GetDataAddress()) + ref().DataSize);
}

void* ResPackfileBlockV2Header::GetStrAddress()
{
    return (static_cast<u8*>(GetImportAddress()) + ref().ImportSize);
}

void* ResPackfileBlockV2Header::GetPof0Address()
{
    return (static_cast<u8*>(GetStrAddress()) + ref().StrsSize);
}

Packfile::Packfile(void* data) :
    Handle(static_cast<ResPackfileHeaderDataTag*>(data))
{
    ResPackfileHeader header(data);
    if (header.IsValidHeader())
    {
        header.ConvertEndian();
    }
}

bool Packfile::IsImport() const
{
    ResPackfileHeader header(Handle);
    return ((header.ref().Status & PACKFILE_STATUS_IS_IMPORTED) != 0);
}

ResDepend Packfile::GetResDepend()
{
    return Get<ResDepend>(nullptr, nullptr);
}

void Packfile::Setup(csl::fnd::IAllocator* allocator,
    hh::mr::CRenderingInfrastructure* renderInfra)
{
    ResPackfileHeader header(Handle);
    if ((header.ref().Status & PACKFILE_STATUS_IS_IMPORTED) == 0)
    {
        ResourceTypeInfoRegistry* typeInfo = ResourceTypeInfoRegistry::GetInstance();
        unsigned int version = header.GetMajorVersion();
        Resolved(Handle);

        //CAllocationMeasure CStack68; // TODO: Un-comment this line!
        void* dataBlock;

        if (renderInfra && header.ref().NodeCount != 0 &&
            (dataBlock = header.GetNextBlock(version)))
        {
            ResDicLinear types(GetDicAddr(version, dataBlock));
            for (s32 i = 0; i < types.ref().Count; ++i)
            {
                unsigned int typeHash = typeInfo->CreateHash(GetDicRootName(types.GetName(i)));
                ResDicLinear files(types[i]);

                for (s32 i2 = 0; i2 < files.ref().Count; ++i2)
                {
                    const char* fileName = files.GetName(i2);

                    ResPackfileBlockDataHeaderDataTag* blockDataTag =
                        static_cast<ResPackfileBlockDataHeaderDataTag*>(files[i2]);

                    void* blockData = GetBlockData(version, &blockDataTag);
                    ResPackfileBlockDataHeaderData blockDataHeader(blockDataTag);

                    if ((blockDataHeader.ref().Status & PACKFILE_STATUS_IS_SWAPPED) == 0)
                    {
                        ResFileCommon::ChangeEndian32(
                            (header.ref().Status & PACKFILE_STATUS_IS_SWAPPED) != 0,
                            &blockDataHeader.ref().Size, &blockDataHeader.ref().Size);

                        blockDataHeader.ref().Status |= PACKFILE_STATUS_IS_SWAPPED;
                    }

                    if ((blockDataHeader.ref().Flags & 0x80) == 0) // TODO: Is this correct?
                    {
                        u32 dataSize = blockDataHeader.ref().Size;
                        SLoadedResourceParameter args =
                        {
                            nullptr, //&CStack68 // TODO: Un-comment the CStack68 part!!
                            nullptr,
                            nullptr,
                            fileName
                        };

                        typeInfo->PrepareReplaceLoadedResource(blockData, typeHash, &dataSize, &args);
                    }
                }
            }
        }

        // TODO: Un-comment this line:
        //CMeasuredMemory aCStack112(CStack68, renderInfra, allocator);
        bool hasDependencies = false;

        if (header.ref().NodeCount != 0 &&
            (dataBlock = header.GetNextBlock(version)))
        {
            ResDicLinear types(GetDicAddr(version, dataBlock));
            for (s32 i = 0; i < types.ref().Count; ++i)
            {
                unsigned int typeHash = typeInfo->CreateHash(GetDicRootName(types.GetName(i)));
                ResDicLinear files(types[i]);

                for (s32 i2 = 0; i2 < files.ref().Count; ++i2)
                {
                    const char* fileName = files.GetName(i2);

                    ResPackfileBlockDataHeaderDataTag* blockDataTag =
                        static_cast<ResPackfileBlockDataHeaderDataTag*>(files[i2]);

                    void* blockData = GetBlockData(version, &blockDataTag);
                    ResPackfileBlockDataHeaderData blockDataHeader(blockDataTag);

                    if ((blockDataHeader.ref().Status & PACKFILE_STATUS_IS_SWAPPED) == 0)
                    {
                        ResFileCommon::ChangeEndian32(
                            (header.ref().Status & PACKFILE_STATUS_IS_SWAPPED) != 0,
                            &blockDataHeader.ref().Size, &blockDataHeader.ref().Size);

                        blockDataHeader.ref().Status |= PACKFILE_STATUS_IS_SWAPPED;
                    }

                    if ((blockDataHeader.ref().Flags & 0x80) != 0) // TODO: Is this correct?
                    {
                        hasDependencies = true;
                    }
                    else
                    {
                        void* pvVar8;
                        u32 dataSize;

                        if (!renderInfra)
                        {
                            dataSize = blockDataHeader.ref().Size;
                            pvVar8 = typeInfo->ReplaceLoadedResource(fileName,
                                blockData, typeHash, &dataSize, allocator);

                            if (!pvVar8)
                            {
                                pvVar8 = blockData;
                            }
                        }
                        else
                        {
                            dataSize = blockDataHeader.ref().Size;
                            SLoadedResourceParameter args =
                            {
                                nullptr,
                                nullptr, //&aCStack112 // TODO: Un-comment the aCStack112 part!!
                                allocator,
                                fileName
                            };

                            if (!typeInfo->PrepareReplaceLoadedResource(blockData,
                                typeHash, &dataSize, &args))
                            {
                                dataSize = blockDataHeader.ref().Size;
                                pvVar8 = typeInfo->ReplaceLoadedResource(fileName,
                                    blockData, typeHash, &dataSize, allocator);

                                if (!pvVar8)
                                {
                                    pvVar8 = blockData;
                                }
                            }
                        }

                        blockDataHeader.ref().Data = pvVar8;
                        blockDataHeader.ref().Size = dataSize;

                        typeInfo->FinishLoadedResource(blockDataHeader.ref().Data,
                            typeHash, blockDataHeader.ref().Size, allocator);
                    }
                }
            }
        }

        header.ref().Status |= PACKFILE_STATUS_IS_IMPORTED;

        // Load dependencies as necessary.
        if (hasDependencies)
        {
            header.ref().Status |= PACKFILE_STATUS_UNKNOWN4;
            ResDepend dependencies = GetResDepend();
            header.ref().RemainingDepends = dependencies.ref().Count;
        }
        else
        {
            header.ref().Status |= PACKFILE_STATUS_IS_IMPORT_COMPLETED;
        }
    }
}

void Packfile::Bind(csl::fnd::IAllocator* allocator, Packfile param_2)
{
    ResPackfileHeader header(Handle);
    if ((header.ref().Status & PACKFILE_STATUS_IS_IMPORTED) != 0)
    {
        ResourceTypeInfoRegistry* typeInfo = ResourceTypeInfoRegistry::GetInstance();
        unsigned int version = header.GetMajorVersion();
        void* dataBlock;

        if (header.ref().NodeCount != 0 && (dataBlock = header.GetNextBlock(version)))
        {
            ResDicLinear types(GetDicAddr(version, dataBlock));
            for (s32 i = 0; i < types.ref().Count; ++i)
            {
                unsigned int typeHash = typeInfo->CreateHash(GetDicRootName(types.GetName(i)));
                ResDicLinear files(types[i]);

                for (s32 i2 = 0; i2 < files.ref().Count; ++i2)
                {
                    ResPackfileBlockDataHeaderDataTag* blockDataTag =
                        static_cast<ResPackfileBlockDataHeaderDataTag*>(files[i2]);

                    void* blockData = GetBlockData(version, &blockDataTag);
                    ResPackfileBlockDataHeaderData blockDataHeader(blockDataTag);

                    if ((blockDataHeader.ref().Status & PACKFILE_STATUS_IS_IMPORTED) == 0 &&
                        typeInfo->BindLoadedResource(blockDataHeader.ref().Data, typeHash,
                            blockDataHeader.ref().Size, param_2, allocator))
                    {
                        blockDataHeader.ref().Status |= PACKFILE_STATUS_IS_IMPORTED;
                    }
                }
            }
        }
    }
}

void* Packfile::GetResource(const ResourceTypeInfo& typeInfo,
    const char* param_2, std::size_t* param_3)
{
    if (param_3)
    {
        *param_3 = 0;
    }

    ResPackfileHeader header(Handle);
    if ((header.ref().Status & PACKFILE_STATUS_IS_IMPORTED) != 0)
    {
        return ResourceTypeInfo::FindLoadedResourceByName(
            header.GetMajorVersion(), typeInfo.Type,
            *this, param_2, param_3);
    }

    return nullptr;
}

std::size_t Packfile::GetNumberOfImport() const
{
    ResPackfileHeader header(Handle);
    return header.ref().RemainingDepends;
}

bool Packfile::IsImportCompleted() const
{
    ResPackfileHeader header(Handle);
    return ((header.ref().Status & PACKFILE_STATUS_IS_IMPORT_COMPLETED) != 0);
}

namespace pac
{
void* GetDicAddr(unsigned int version, void* data)
{
    if (version < 2)
    {
        ResPackfileBlockV1Header blockV1(data);
        return blockV1.GetDicAddress();
    }
    else
    {
        ResPackfileBlockV2Header blockV2(data);
        return blockV2.GetDicAddress();
    }
}

const char* GetDicRootName(const char* param_1)
{
    const char* sep = std::strchr(param_1, ':');
    return (sep != 0) ? (sep + 1) : param_1;
}

ResPackfileBlockDataHeaderDataTag* GetBlockData(unsigned int version,
    ResPackfileBlockDataHeaderDataTag** param_2)
{
    ResPackfileBlockDataHeaderDataTag* ptr = *param_2;
    if (version < 2)
    {
        *param_2 = (ptr - 1);
        return ptr;
    }
    else
    {
        return (ptr + 1);
    }
}

void ReplaceImport(unsigned int version, void* importAddress,
    u32 importSize, bool doSwap)
{
    ResPackfileImportHeaderData importHeader(importAddress);
    if (importSize != 0)
    {
        ResFileCommon::ChangeEndian32(doSwap, &importHeader.ref().Count, &importHeader.ref().Count);
        if (importHeader.ref().Count > 0)
        {
            for (u32 i = 0; i < importHeader.ref().Count; ++i)
            {
                if (version > 1)
                {
                    ResPackfileImportData& curImport = importHeader.ptr()->Imports[i];
                    ResFileCommon::ChangeEndian32(doSwap, &curImport.DicLinearEntryIndex,
                        &curImport.DicLinearEntryIndex);
                }
            }
        }
    }
}

void Resolved(void* data)
{
    ResPackfileHeader header(data);
    if ((header.ref().Status & PACKFILE_STATUS_IS_RESOLVED) == 0)
    {
        unsigned int version = header.GetMajorVersion();
        bool doSwap = ((header.ref().Status & PACKFILE_STATUS_IS_SWAPPED) != 0);
        void* dataBlock;

        if (header.ref().NodeCount != 0 && (dataBlock = header.GetNextBlock(version)))
        {
            if (version < 2)
            {
                // TODO
            }
            else
            {
                ResPackfileBlockV2Header blockV2(dataBlock);

                ResFileCommon::ReplacePof0(header.ptr(),
                    blockV2.GetPof0Address(),
                    blockV2.ref().Pof0Size, doSwap);

                ResFileCommon::ReplaceDic(version, header.ptr(),
                    blockV2.GetDicAddress(), blockV2.ref().DicDepth,
                    doSwap);

                ReplaceImport(version, blockV2.GetImportAddress(),
                    blockV2.ref().ImportSize, doSwap);
            }
        }

        header.ref().Status |= PACKFILE_STATUS_IS_RESOLVED;
    }
}

void* GetNodeDicPointer(unsigned int version, const char* type, void* data)
{
    void* dicPtr;
    if (version < 2)
    {
        ResPackfileBlockV1Header blockV1(data);
        int sigID = blockV1.GetSignatureId();
        dicPtr = blockV1.GetDicAddress();

        if (sigID != 0)
        {
            return nullptr;
        }
    }
    else
    {
        ResPackfileBlockV2Header blockV2(data);
        dicPtr = blockV2.GetDicAddress();

        if (blockV2.ref().SignatureId != 0)
        {
            return nullptr;
        }
    }

    ResDicLinear dic(dicPtr);
    s32 index = dic.GetIndex(type, ':');

    return (index != -1) ? dic[index] : nullptr;
}

bool CheckPacHeader(const ResPackfileHeaderDataTag* data)
{
    ResPackfileHeader header(data);
    return (data->Signature == ResFileCommon::GetReverseBigEndian(PACX_SIGNATURE) &&
        header.GetMajorVersion() == 1 || header.GetMajorVersion() == 2);
}
}
}
}
