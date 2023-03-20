#include "pch.h"
#include "csl/ut/number.h"

namespace csl
{
namespace ut
{
void NativeFromBig32(void* output, void* input, int count)
{
    u32* big = (static_cast<u32*>(output) - 1);
    u32* native = (static_cast<u32*>(input) - 1);

    for (int i = 0; i < count; ++i)
    {
#ifdef CSL_IS_BIG_ENDIAN
        *(++big) = *(++native);
#else
        *(++big) = CSL_SWAP_U32(*(++native));
#endif
    }
}

void NativeFromLittle32(void* param_1, void* param_2, int count)
{
    // TODO
}
}
}
