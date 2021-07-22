#pragma once
#include <Hedgehog/Base/hhBase.h>

namespace hh
{
namespace mr
{
class CVertexShaderV2Resource // TODO: Inheritance?
{
    OFF32(const char) m_codeResName;
    u32 m_paramsCount;

    // TODO: Other data members

public:
    // TODO: Is this function actually a thing?
    inline const char* CodeResName() const
    {
        return m_codeResName;
    }

    // TODO: Is this function actually a thing?
    inline u32 ParamsCount() const
    {
        return HH_ENDIAN_FIX_U32(m_paramsCount);
    }
};
}
}
