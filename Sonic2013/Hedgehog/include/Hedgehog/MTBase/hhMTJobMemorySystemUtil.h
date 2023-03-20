#pragma once
#include "hhEventHolder.h"
#include <cstddef>

namespace hh
{
namespace MTBase
{
struct SJobJoint;

class CMTJobMemorySystemUtil
{
    LWAPI(0x1031f92c, TODO)
    static SJobJoint* DAT_1031f92c;

    LWAPI(0x1031f930, 0x011d797c)
    static std::size_t DAT_1031f930;

    LWAPI(0x1031f934, 0x011d7980)
    static SJobJoint* DAT_1031f934;

    LWAPI(0x1031f938, 0x011d7988)
    static rsdx::RsdxSListHeader EventHolders;

public:
    LWAPI(0x036e60a4, NONE)
    static void PushListOne(void* param_1, void* param_2);

    LWAPI(0x036e60a8, TODO)
    static void* PopListOne(void* param_1);

    LWAPI(0x036e60ac, NONE)
    static void InitializeList(void* param_1);

    LWAPI(0x036e60b8, TODO)
    static rsdx::RsdxSListEntry* PeekListOne(void* param_1);

    LWAPI(0x036e60d0, 0x00c297b0)
    static void InitializeJobMemory(std::size_t param_1);

    LWAPI(0x036e6174, TODO)
    static void FinalizeJobMemory();

    LWAPI(0x036e61bc, TODO)
    static void* Allocate(std::size_t size);

    LWAPI(0x036e61d4, TODO)
    static void Free(void* param_1, std::size_t size);

    LWAPI(0x036e61e8, NONE)
    static void FreeEventHolder(SEventHolder* eventHolder);

    LWAPI(0x036e61f8, NONE)
    static void InitializeEventHolder(std::size_t count);

    LWAPI(0x036e6274, NONE)
    static SEventHolder* AllocEventHolder();

    LWAPI(0x036e6280, NONE)
    static void FinalizeEventHolder();
};

class CMTJobMemorySystemUtilLocal : public CMTJobMemorySystemUtil // size == 8??
{
public:
    unsigned int field_0x4;

    // TODO
};
}
}
