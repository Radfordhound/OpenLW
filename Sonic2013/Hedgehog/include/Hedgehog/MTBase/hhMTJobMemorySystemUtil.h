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
    // Wii U: 0x1031f92c, PC: TODO
    static SJobJoint* DAT_1031f92c;

    // Wii U: 0x1031f930, PC: 0x011d797c
    static std::size_t DAT_1031f930;

    // Wii U: 0x1031f934, PC: 0x011d7980
    static SJobJoint* DAT_1031f934;

    // Wii U: 0x1031f938, PC: 0x011d7988
    static rsdx::RsdxSListHeader EventHolders;

public:
    // Wii U: 0x036e60a4 (THUNK), PC: Inlined
    static void PushListOne(void* param_1, void* param_2);

    // Wii U: 0x036e60a8 (THUNK), PC: TODO
    static void* PopListOne(void* param_1);

    // Wii U: 0x036e60ac, PC: Inlined
    static void InitializeList(void* param_1);

    // Wii U: 0x036e60b8, PC: TODO
    static rsdx::RsdxSListEntry* PeekListOne(void* param_1);

    // Wii U: 0x036e60d0, PC: 0x00c297b0
    static void InitializeJobMemory(std::size_t param_1);

    // Wii U: 0x036e6174, PC: TODO
    static void FinalizeJobMemory();

    // Wii U: 0x036e61bc, PC: TODO
    static void* Allocate(std::size_t size);

    // Wii U: 0x036e61d4, PC: TODO
    static void Free(void* param_1, std::size_t size);

    // Wii U: 0x036e61e8, PC: Inlined
    static void FreeEventHolder(SEventHolder* eventHolder);

    // Wii U: 0x036e61f8, PC: Inlined
    static void InitializeEventHolder(std::size_t count);

    // Wii U: 0x036e6274, PC: Inlined
    static SEventHolder* AllocEventHolder();

    // Wii U: 0x036e6280, PC: Inlined
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
