#pragma once
#include "../System/hhFxObject.h"

namespace Extra
{
namespace fx
{
class CGPUInstanceMapperInternal;

class CGPUInstanceMapper : public CFxRefcountObject
{
    CGPUInstanceMapperInternal* m_impl;

public:
    LWAPI(TODO, TODO)
    CGPUInstanceMapper();

    LWAPI(0x0370b1bc, 0x00c54550)
    ~CGPUInstanceMapper();
};
}
}
