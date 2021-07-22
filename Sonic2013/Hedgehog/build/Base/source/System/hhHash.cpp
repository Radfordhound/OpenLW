#include "Hedgehog/Base/System/hhHash.h"
#include <cstdint>

namespace hh
{
namespace base
{
std::size_t hash_value_str(const char* str)
{
    std::size_t iVar3 = 0;
    std::size_t uVar4 = 0;
    const unsigned char* curByte = reinterpret_cast<const unsigned char*>(str);

    while (*curByte != '\0')
    {
        iVar3 += (static_cast<std::size_t>(*curByte) << uVar4);
        ++curByte;
        uVar4 = (uVar4 + 8 & 31);
    }

    return reinterpret_cast<std::size_t>(curByte + iVar3 +
        (1 - reinterpret_cast<std::intptr_t>(str)));
}
}
}
