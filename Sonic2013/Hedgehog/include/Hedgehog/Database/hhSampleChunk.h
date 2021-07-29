#pragma once
#include <Hedgehog/Base/hhBase.h>
#include <cstring>

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

enum CSampleChunkResource2Flags
{
    /* Masks */
    SAMPLE_CHUNK_FLAGS_MASK = 0xE0000000U,
    SAMPLE_CHUNK_SIZE_MASK = 0x1FFFFFFFU,

    /* Flags */
    SAMPLE_CHUNK_FLAG_NONE = 0,

#ifdef HH_IS_BIG_ENDIAN
    SAMPLE_CHUNK_FLAG_IS_LEAF = 0x20000000U,
    SAMPLE_CHUNK_FLAG_IS_LAST_CHILD = 0x40000000U,
    SAMPLE_CHUNK_FLAG_IS_ROOT = 0x80000000U,
#else
    SAMPLE_CHUNK_FLAG_IS_LEAF = 0x20U,
    SAMPLE_CHUNK_FLAG_IS_LAST_CHILD = 0x40U,
    SAMPLE_CHUNK_FLAG_IS_ROOT = 0x80U,
#endif

    SAMPLE_CHUNK_FLAG_IS_LAST_OR_ROOT = (
        SAMPLE_CHUNK_FLAG_IS_ROOT |
        SAMPLE_CHUNK_FLAG_IS_LAST_CHILD)
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

    // TODO: Is this function actually a thing?
    inline bool IsV2() const
    {
        return ((m_fileSize & SAMPLE_CHUNK_FLAG_IS_ROOT) != 0);
    }

    // Wii U: 0x036c4b94, PC: TODO
    void ResolvePointer();
};

class CSampleChunkNode
{
    u32 m_flags;
    u32 m_value;
    char m_name[8];

public:
    // Wii U: 0x03674140, PC: TODO
    bool IsLeaf() const;

    u32 GetChunkSize(u32 flags)
    {
        return ((flags & SAMPLE_CHUNK_FLAG_IS_ROOT) == 0) ?
            (flags + 15 & 0x1ffffff0) : flags;
    }

    template<typename T>
    T* GetData()
    {
        return reinterpret_cast<T*>(this + 1);
    }

    // TODO: Is this function actually a thing?
    inline u32 GetValue() const
    {
        return HH_ENDIAN_FIX_U32(m_value);
    }

    // TODO: Is this function actually a thing?
    inline bool NameEquals(const char(&name)[9]) const
    {
        return (std::memcmp(m_name, name, sizeof(m_name)) == 0);
    }

    // TODO: Is this function actually a thing?
    inline CSampleChunkNode* GetNext()
    {
        return ((m_flags & SAMPLE_CHUNK_FLAG_IS_LAST_CHILD) == 0) ?
            PtrAdd<CSampleChunkNode>(this, GetChunkSize(HH_ENDIAN_FIX_U32(m_flags))) :
            nullptr;
    }
};
}
}
