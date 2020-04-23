#include "csl/fnd/String.h"

namespace csl
{
namespace fnd
{
void StrLcpy(char* dst, const char* src, std::size_t bufLen)
{
    if (bufLen != 1)
    {
        for (std::size_t i = 0; i < bufLen - 1; ++i)
        {
            *dst++ = *src++;
            if (*src == '\0') break;
        }
    }
    
    *dst = '\0';
}
}
}
