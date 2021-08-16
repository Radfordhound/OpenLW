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
    // Wii U: TODO, PC: TODO
    CGPUInstanceMapper();

    // Wii U: 0x0370b1bc, PC: 0x00c54550
    ~CGPUInstanceMapper();
};
}
}
