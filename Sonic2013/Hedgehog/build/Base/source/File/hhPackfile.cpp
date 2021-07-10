#include "Hedgehog/Base/File/hhPackfile.h"

namespace hh
{
namespace ut
{
void ResPackfileHeader::ConvertEndian()
{
    // TODO
}

bool ResPackfileHeader::IsValidHeader() const
{
    return (IsValid() && pac::CheckPacHeader(ptr()));
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
bool CheckPacHeader(const ResPackfileHeaderDataTag* data)
{
    ResPackfileHeader header(data);
    return (data->Signature == ResFileCommon::GetReverseBigEndian(PACX_SIGNATURE) &&
        header.GetMajorVersion() == 1 || header.GetMajorVersion() == 2);
}
}
}
}
