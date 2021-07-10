#pragma once
#include "../System/hhResource.h"
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
struct ResPackfileHeaderDataTag
{
    u32 Signature;
    u8 Version[3];
    u8 EndianFlag;
    u32 FileSize;
    u16 NodeCount;
    u8 Status;
    u8 RemainingDepends;

    // TODO
};

enum ResPackfileStatus
{
    PACKFILE_STATUS_IS_IMPORTING = 1,
    PACKFILE_STATUS_IS_IMPORT_COMPLETED = 8
};

struct ResPackfileHeader : public ResCommon<ResPackfileHeaderDataTag>
{
    // Wii U: 0x036960ec, PC: TODO
    void ConvertEndian();

    // Wii U: 0x03695ecc, PC: TODO
    bool IsValidHeader() const;

    // Wii U: 0x03695e08, PC: TODO
    unsigned int GetMajorVersion() const;

    inline ResPackfileHeader(const void* data) :
        ResCommon<ResPackfileHeaderDataTag>(data) {}

    inline ResPackfileHeader(void* data) :
        ResCommon<ResPackfileHeaderDataTag>(data) {}
};

class Packfile // size == 4
{
    ResPackfileHeaderDataTag* m_handle;

public:
    // Wii U: 0x03692454, PC: TODO
    Packfile(void* data);

    // Wii U: 0x0369257c, PC: TODO
    bool IsImport() const;

    // Wii U: 0x03692e1c, PC: TODO
    void Setup(csl::fnd::IAllocator* allocator, hh::mr::CRenderingInfrastructure* renderInfra);

    // Wii U: 0x03693dac, PC: TODO
    std::size_t GetNumberOfImport() const;

    // Wii U: 0x03693de0, PC: TODO
    bool IsImportCompleted() const;
};

namespace pac
{
#define PACX_SIGNATURE 0x50414378U

// Wii U: 0x03695e4c, PC: 0x00c1a770
bool CheckPacHeader(const ResPackfileHeaderDataTag* data);
}
}
}
