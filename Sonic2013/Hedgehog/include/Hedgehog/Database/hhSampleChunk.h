#pragma once
#include <Hedgehog/Base/hhBase.h>

namespace hh
{
namespace db
{
class CSampleChunkResource
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

class CSampleChunkResource2
{
    u32 m_fileSize;
    u32 m_magic;
    u32 m_offsetTableOff;
    u32 m_offsetCount;

public:
    template<typename T>
    const T* GetData() const
    {
        return reinterpret_cast<const T*>(this + 1);
    }

    template<typename T>
    T* GetData()
    {
        return reinterpret_cast<T*>(this + 1);
    }

    // Wii U: 0x036c4b94, PC: TODO
    void ResolvePointer();
};
}
}
