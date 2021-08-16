#pragma once
#include "hhJob.h"
#include "hhEventHolder.h"

namespace hh
{
namespace MTBase
{
struct SJobJoint : public rsdx::RsdxSListHeader // size == 256?
{
    rsdx::RsdxAtomic field_0x4;
    SEventHolder* field_0x8;
    rsdx::RsdxAtomic field_0xc;
    unsigned short field_0x10;
    unsigned short field_0x12;
    const char* Name;
    // TODO

    char padding[228]; // TODO: REMOVE THIS
};
}
}
