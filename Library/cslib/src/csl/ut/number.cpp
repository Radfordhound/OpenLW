#include "csl/ut/number.h"

namespace csl
{
namespace ut
{
void NativeFromBig32(void* param_1, void* param_2, int count)
{
    u32* puVar1 = (static_cast<u32*>(param_1) - 1);
    u32* puVar2 = (static_cast<u32*>(param_2) - 1);

    for (int i = 0; i < count; ++i)
    {
#ifdef CSL_IS_BIG_ENDIAN
        *(++puVar1) = *(++puVar2);
#else
        *(++puVar1) = CSL_SWAP_U32(*(++puVar2));
#endif
    }
}
}
}
