#include "Hedgehog/Base/File/hhPackfile.h"
#include "Hedgehog/Base/System/hhResourceTypeInfoRegistry.h"
#include <cstring>

using namespace hh::ut::pac;

namespace hh
{
namespace ut
{
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

const char* ResDicLinear::GetName(int index) const
{
    if (IsValid() && index > -1 && index < ref().Count)
    {
        return ref().Entries[index].Key;
    }

    return nullptr;
}

const void* ResDicLinear::operator[](int index) const
{
    if (IsValid() && index > -1 && index < ref().Count)
    {
        return ref().Entries[index].Value;
    }

    return nullptr;
}

Packfile::Packfile(void* data) :
    m_handle(static_cast<ResPackfileHeaderDataTag*>(data))
{
    ResPackfileHeader header(data);
    if (header.IsValidHeader())
    {
        header.ConvertEndian();
    }
}

bool Packfile::IsImport() const
{
    ResPackfileHeader header(m_handle);
    return ((header.ref().Status & PACKFILE_STATUS_IS_IMPORTING) != 0);
}

void Packfile::Setup(csl::fnd::IAllocator* allocator,
    hh::mr::CRenderingInfrastructure* renderInfra)
{
    ResPackfileHeader header(m_handle);
    if ((header.ref().Status & PACKFILE_STATUS_IS_IMPORTING) == 0)
    {
        ResourceTypeInfoRegistry* typeInfo = ResourceTypeInfoRegistry::GetInstance();
        unsigned int version = header.GetMajorVersion();
        Resolved(m_handle);

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
                            0,
                            0,
                            fileName
                        };

                        typeInfo->PrepareReplaceLoadedResource(blockData, typeHash, &dataSize, &args);
                    }
                }
            }
        }

        // TODO
    }
}

std::size_t Packfile::GetNumberOfImport() const
{
    ResPackfileHeader header(m_handle);
    return header.ref().RemainingDepends;
}

bool Packfile::IsImportCompleted() const
{
    ResPackfileHeader header(m_handle);
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

bool CheckPacHeader(const ResPackfileHeaderDataTag* data)
{
    ResPackfileHeader header(data);
    return (data->Signature == ResFileCommon::GetReverseBigEndian(PACX_SIGNATURE) &&
        header.GetMajorVersion() == 1 || header.GetMajorVersion() == 2);
}
}
}
}
