#include "csl/fnd/String.h"

namespace csl
{
namespace fnd
{
void StrLcpy(char* dst, const char* src, std::size_t len)
{
    if (len != 1)
    {
        for (std::size_t i = 0; i < len - 1; ++i)
        {
            *dst++ = *src++;
        }
    }
    
    *dst = '\0';
}
}
}
