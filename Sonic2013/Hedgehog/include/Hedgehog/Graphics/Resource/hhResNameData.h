#pragma once
#include <Hedgehog/Utility/hhResCommon.h>
#include <cstddef>

namespace hh
{
namespace gfx
{
namespace internal // TODO: MOVE THIS TO ANOTHER HEADER PLEASE!!!
{
LWAPI(0x0366dce4, 0x00c11e60)
char* GetUniqueString(const char* param_1);

LWAPI(0x0366dce8, 0x00c11e70)
unsigned int CalcHashKey(const char* str, std::size_t len, std::size_t param_3 = 0);
}

namespace res
{
struct ResNameData
{
    unsigned int Hash;
    const char* String;
};

struct ResName : public ut::ResCommon<ResNameData>
{
    unsigned int GetHash() const
    {
        return ptr()->Hash;
    }

    bool operator==(const ResName& other) const
    {
        return (ptr() == other.ptr() || GetHash() == other.GetHash());
    }

    bool operator!=(const ResName& other) const
    {
        return (ptr() != other.ptr() && GetHash() != other.GetHash());
    }

    inline operator const char*() const
    {
        return ptr()->String;
    }

    inline ResName(std::nullptr_t) :
        ResCommon<ResNameData>() {}

    inline ResName(const void* data) :
        ResCommon<ResNameData>(data) {}

    inline ResName(void* data = nullptr) :
        ResCommon<ResNameData>(data) {}
};

namespace detail
{
LWAPI(0x0367ad1c, 0x00c0d6f0)
ResName InitResNameData(ResNameData* param_1,
    const char* param_2, std::size_t param_3 = 0);
}
}
}
}
