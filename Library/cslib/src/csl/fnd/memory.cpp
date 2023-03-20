#include "pch.h"
#include "csl/fnd/memory.h"

namespace csl
{
namespace fnd
{
std::size_t StrLcpy(char* dst, const char* src, std::size_t len)
{
    std::size_t copiedLen = 0;
    if (len != 1)
    {
        do
        {
            *(dst++) = *(src++);
            ++copiedLen;
            if (*src == '\0') break;
        }
        while (copiedLen < (len - 1));
    }

    *dst = '\0';
    return copiedLen;
}
}
}
