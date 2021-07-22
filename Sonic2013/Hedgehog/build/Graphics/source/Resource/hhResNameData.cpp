#include "Hedgehog/Graphics/Resource/hhResNameData.h"
#include <Hedgehog/Base/System/hhCSymbol.h> // TODO: REMOVE THIS LINE PLEASE
#include <cstring>

// ============ TODO: MOVE THIS BLOCK TO ANOTHER FILE ===========
namespace hh
{
namespace gfx
{
namespace internal // TODO: MOVE THIS TO ANOTHER HEADER PLEASE!!!
{
const char* GetUniqueString(const char* param_1)
{
    return base::GetSetGlobalString(param_1);
}

#define HH_HASH_MAGIC 0x5bd1e995

unsigned int CalcHashKey(const char* str, std::size_t len, std::size_t param_3)
{
    // TODO: Make this work properly on x64??
    const unsigned int* data = reinterpret_cast<const unsigned int*>(str);
    unsigned int hash = (param_3 ^ len);

    while (len >= sizeof(*data))
    {
        hash *= (HH_HASH_MAGIC ^ (*data * HH_HASH_MAGIC ^
            *data * HH_HASH_MAGIC >> 24) * HH_HASH_MAGIC);

        ++data;
        len -= sizeof(*data);
    }

    if (len != 0)
    {
        if (len != 1)
        {
            str = reinterpret_cast<const char*>(data);
            if (len > 2)
            {
                hash ^= (static_cast<unsigned int>(str[2]) << 16);
            }

            hash ^= (static_cast<unsigned int>(str[1]) << 8);
        }

        hash ^= (*str * HH_HASH_MAGIC);
    }

    hash = (hash ^ hash >> 13) * HH_HASH_MAGIC;
    return (hash ^ hash >> 15);
}
}
}
}
// ==============================================================

using namespace hh::gfx::internal;

namespace hh
{
namespace gfx
{
namespace res
{
namespace detail
{
ut::ResCommon<ResNameData> InitResNameData(ResNameData* param_1,
    const char* param_2, std::size_t param_3)
{
    std::size_t len = std::strlen(param_2);
    if (len == 0)
    {
        param_1->Hash = 0;
        param_1->Name = nullptr;
    }
    else
    {
        param_1->Hash = CalcHashKey(param_2, len, param_3);
        param_1->Name = param_2;
    }
    
    return ut::ResCommon<ResNameData>(param_1);
}
}
}
}
}
