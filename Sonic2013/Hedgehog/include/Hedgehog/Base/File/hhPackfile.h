#pragma once
#include "../System/hhResCommon.h"
#include <cstddef>

namespace csl
{
namespace fnd
{
struct IAllocator;
}
}

namespace hh
{
namespace mr
{
class CRenderingInfrastructure;
}

namespace ut
{
enum ResPackfileStatus
{
    PACKFILE_STATUS_IS_IMPORTING = 1,
    PACKFILE_STATUS_IS_SWAPPED = 2, // TODO: Is this correct?
    PACKFILE_STATUS_IS_IMPORT_COMPLETED = 8,
    PACKFILE_STATUS_IS_RESOLVED = 16
};

struct ResPackfileHeaderDataTag
{
    u32 Signature;
    u8 Version[3];
    u8 EndianFlag;
    u32 FileSize;
    u16 NodeCount;
    u8 Status;
    u8 RemainingDepends;
};

struct ResPackfileHeader : public ResCommon<ResPackfileHeaderDataTag>
{
    // Wii U: 0x03695e08, PC: TODO
    unsigned int GetMajorVersion() const;

    // Wii U: 0x03695ecc, PC: TODO
    bool IsValidHeader() const;

    // Wii U: 0x036960ec, PC: TODO
    void ConvertEndian();

    // Wii U: 0x03696018, PC: TODO
    void* GetNextBlock(unsigned int version, void* block = nullptr);

    inline ResPackfileHeader(const void* data) :
        ResCommon<ResPackfileHeaderDataTag>(data) {}

    inline ResPackfileHeader(void* data = nullptr) :
        ResCommon<ResPackfileHeaderDataTag>(data) {}
};

struct ResPackfileBlockV1HeaderDataTag
{
    u32 Signature;
    u32 Size;
    // TODO
};

struct ResPackfileBlockV1Header : public ResCommon<ResPackfileBlockV1HeaderDataTag>
{
    // Wii U: 0x036964c4, PC: TODO
    void* GetDicAddress();

    inline ResPackfileBlockV1Header(const void* data) :
        ResCommon<ResPackfileBlockV1HeaderDataTag>(data) {}

    inline ResPackfileBlockV1Header(void* data = nullptr) :
        ResCommon<ResPackfileBlockV1HeaderDataTag>(data) {}
};

struct ResPackfileBlockV2HeaderDataTag
{
    u32 Signature;
    u32 Size;
    u32 DataSize;
    u32 DicSize; // wow, really funny! good job everyone
    u32 ImportSize;
    u32 StrsSize;
    u32 Pof0Size;
    u8 DicDepth;
    u8 Unknown2;
    u16 Unknown3;
};

struct ResPackfileBlockV2Header : public ResCommon<ResPackfileBlockV2HeaderDataTag>
{
    // Wii U: 0x03696670, PC: TODO
    void* GetDicAddress();

    // Wii U: 0x03696694, PC: TODO
    void* GetDataAddress();

    // Wii U: 0x036966cc, PC: TODO
    void* GetImportAddress();

    // Wii U: 0x03696704, PC: TODO
    void* GetStrAddress();

    // Wii U: 0x0369673c, PC: TODO
    void* GetPof0Address();

    inline ResPackfileBlockV2Header(const void* data) :
        ResCommon<ResPackfileBlockV2HeaderDataTag>(data) {}

    inline ResPackfileBlockV2Header(void* data = nullptr) :
        ResCommon<ResPackfileBlockV2HeaderDataTag>(data) {}
};

struct ResDicLinearEntry // TODO: This name was guessed!
{
    OFF32(char) Key;
    OFF32(void) Value;
};

struct ResDicLinearData
{
    s32 Count;
    OFF32(ResDicLinearEntry) Entries;
};

struct ResDicLinear : public ResCommon<ResDicLinearData>
{
    // Wii U: 0x036926a8, PC: TODO
    const char* GetName(int index) const;

    // Wii U: 0x03692748, PC: TODO
    const void* operator[](int index) const;

    // TODO: Is this function actually a thing?
    inline void* operator[](int index)
    {
        return const_cast<void*>(const_cast<const ResDicLinear*>(
            this)->operator[](index));
    }

    inline ResDicLinear(const void* data) :
        ResCommon<ResDicLinearData>(data) {}

    inline ResDicLinear(void* data = nullptr) :
        ResCommon<ResDicLinearData>(data) {}
};

struct ResPackfileBlockDataHeaderDataTag
{
    u32 Size;
    OFF32(void) Data;
    u32 Unknown1; // TODO: If this is unused, you might be able to use this as part of the Data pointer on x64??
    u8 Flags;
    u8 Status;
    u16 Unknown3;
};

struct ResPackfileBlockDataHeaderData : public ResCommon<ResPackfileBlockDataHeaderDataTag>
{
    // TODO

    inline ResPackfileBlockDataHeaderData(const void* data) :
        ResCommon<ResPackfileBlockDataHeaderDataTag>(data) {}

    inline ResPackfileBlockDataHeaderData(void* data = nullptr) :
        ResCommon<ResPackfileBlockDataHeaderDataTag>(data) {}
};

struct ResPackfileImportData // TODO: This name was guessed! Is it correct?
{
    OFF32(char) Type;
    OFF32(char) Name;
    u32 DicLinearEntryIndex;
};

struct ResPackfileImportHeaderDataTag
{
    u32 Count;
    OFF32(ResPackfileImportData) Imports;
};

struct ResPackfileImportHeaderData : public ResCommon<ResPackfileImportHeaderDataTag>
{
    // TODO: ?

    inline ResPackfileImportHeaderData(const void* data) :
        ResCommon<ResPackfileImportHeaderDataTag>(data) {}

    inline ResPackfileImportHeaderData(void* data = nullptr) :
        ResCommon<ResPackfileImportHeaderDataTag>(data) {}
};

class Packfile // size == 4
{
    ResPackfileHeaderDataTag* m_handle;

public:
    // Wii U: 0x03692454, PC: TODO
    Packfile(void* data);

    // Wii U: 0x0369257c, PC: TODO
    bool IsImport() const;

    // Wii U: 0x03692e1c, PC: 0x00c19560
    void Setup(csl::fnd::IAllocator* allocator, hh::mr::CRenderingInfrastructure* renderInfra);

    // Wii U: 0x03693dac, PC: TODO
    std::size_t GetNumberOfImport() const;

    // Wii U: 0x03693de0, PC: TODO
    bool IsImportCompleted() const;
};

namespace pac
{
#define PACX_SIGNATURE 0x50414378U

// Wii U: 0x03692648, PC: TODO
void* GetDicAddr(unsigned int version, void* data);

// Wii U: 0x03692710, PC: Inlined
const char* GetDicRootName(const char* param_1);

// Wii U: 0x036927b4, PC: TODO
ResPackfileBlockDataHeaderDataTag* GetBlockData(unsigned int version,
    ResPackfileBlockDataHeaderDataTag** param_2);

// Wii U: 0x03692980, PC: TODO
void ReplaceImport(unsigned int version, void* importAddress,
    u32 importSize, bool doSwap);

// Wii U: 0x03692a60, PC: TODO
void Resolved(void* data);

// Wii U: 0x03695e4c, PC: 0x00c1a770
bool CheckPacHeader(const ResPackfileHeaderDataTag* data);
}
}
}
