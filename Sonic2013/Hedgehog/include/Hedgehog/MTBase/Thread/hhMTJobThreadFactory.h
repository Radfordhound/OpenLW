#pragma once
#include <Hedgehog/Rsdx/System/RsdxAtomic.h>
#include <Hedgehog/Rsdx/System/RsdxEvent.h>
#include <cstddef>

namespace hh
{
namespace MTBase
{
struct SEventHolder : public rsdx::RsdxSListEntry // size == 8
{
    rsdx::RsdxEventHandle Event;
};

struct SJobType256 // size == 256???
{
    // TODO
};

struct SJobJoint : public rsdx::RsdxSListHeader // size == 256???
{
    //rsdx::RsdxSListHeader SListHeader;
    volatile unsigned int field_0x4;
    SEventHolder* field_0x8;
    volatile unsigned int field_0xc;
    unsigned short field_0x10;
    // TODO: Anything here?
    const char* Name;
    // TODO

    char padding[224]; // TODO: REMOVE THIS
};

class CMTJobMemorySystemUtil
{
    // Wii U: 0x1031f92c, PC: TODO
    static SJobJoint* DAT_1031f92c;

    // Wii U: 0x1031f930, PC: 0x011d797c
    static std::size_t DAT_1031f930;

    // Wii U: 0x1031f934, PC: 0x011d7980
    static SJobJoint* DAT_1031f934;

    // Wii U: 0x1031f938, PC: 0x011d7988
    static rsdx::RsdxSListHeader EventHolder;

public:
    // Wii U: 0x036e60a4 (THUNK), PC: TODO
    static void PushListOne(void* param_1, void* param_2);

    // Wii U: 0x036e60a8 (THUNK), PC: TODO
    static void* PopListOne(rsdx::RsdxSListHeader* param_1);

    // Wii U: 0x036e60ac, PC: Inlined
    static void InitializeList(void* param_1);

    // Wii U: 0x036e60d0, PC: 0x00c297b0
    static void InitializeJobMemory(std::size_t param_1);

    // Wii U: 0x036e61bc, PC: TODO
    static void* Allocate(std::size_t size = 256);

    // Wii U: 0x036e61e8, PC: Inlined
    static void FreeEventHolder(SEventHolder* eventHolder);

    // Wii U: 0x036e61f8, PC: Inlined
    static void InitializeEventHolder(std::size_t count);

    // Wii U: 0x036e6274, PC: Inlined
    static SEventHolder* AllocEventHolder();
};

class CMTSimpleJobInternal
{
    // TODO

public:
    // Wii U: 0x036e67d0, PC: TODO
    CMTSimpleJobInternal(std::size_t param_1);
    
    // Wii U: 0x036e6b3c, PC: 0x00c2a590
    void MTSimpleJobBlockUntilSignal(SEventHolder* param1,
        bool param2, unsigned int param3);
};

// Wii U: 0x036e6f10, PC: 0x00c29fa0
void hhMTSimpleJobStart();

// Wii U: 0x036e7050, PC: TODO
SJobType256* hhMTSimpleJobCreateDefault();

// Wii U: 0x036e70a0, PC: TODO
SJobJoint* hhMTSimpleJobJointCreate();

// Wii U: 0x036e70f8, PC: TODO
SEventHolder* hhMTSimpleJobCreateFinishSignal();

// Wii U: 0x036e712c, PC: TODO
SJobJoint* hhMTSimpleJobJointStaticCreate(const char* name);

// Wii U: 0x036e76e0, PC: 0x00c29f60
void hhMTSimpleJobBlockUntilSignal(SJobJoint* jobJoint, unsigned int signal);
}
}
