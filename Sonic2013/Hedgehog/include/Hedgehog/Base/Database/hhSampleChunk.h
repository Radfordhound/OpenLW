#pragma once
#include "../System/hhTypes.h"

namespace hh
{
namespace db
{
class CSampleChunkResource // TODO: Inheritance?
{
    u32 m_fileSize;
    u32 m_version;
    u32 m_dataSize;
    u32 m_dataOff;
    u32 m_offsetTableOff;
    u32 m_fileNameOff;

public:
    template<typename T>
    const T* GetData() const
    {
        return PtrAdd<T>(this, HH_ENDIAN_FIX_U32(m_dataOff));
    }

    template<typename T>
    T* GetData()
    {
        return PtrAdd<T>(this, HH_ENDIAN_FIX_U32(m_dataOff));
    }

    // Wii U: 0x036c4924, PC: 0x00c27c30
    void ResolvePointer();
};
}
}
