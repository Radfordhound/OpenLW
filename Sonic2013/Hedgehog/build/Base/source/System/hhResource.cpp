#include "Hedgehog/Base/System/hhResource.h"
#include "csl/ut/number.h"

namespace hh
{
namespace ut
{
u32 ResFileCommon::GetReverseBigEndian(u32 val)
{
    u32 result;
    csl::ut::NativeFromBig32(&result, &val, 1);
    return result;
}
}
}
