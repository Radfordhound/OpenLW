#pragma once
#include <Hedgehog/Rsdx/System/RsdxAtomic.h>
#include <boost/function.hpp>

namespace hh
{
namespace MTBase
{
struct SJobJoint;

typedef void (*SJobExecFunc)(void* param_1);

struct SJobExecParam : public rsdx::RsdxSListEntry
{
    SJobExecFunc JobExecFunc;
    unsigned int field_0x8;
    SJobJoint* JobJoint;

    // TODO: Other data members?
};

typedef unsigned int (*SJobFunc)(void* param_1);

struct SJobExecuteHeader : public rsdx::RsdxSListHeader // TODO: Is this correct?
{
    unsigned int field_0x4;
    SJobFunc JobFunc;
    void* JobParam;
};

struct SJobEasyData // TODO: This name was guessed.
{
    boost::function<void()> JobFunc;
};

struct SJobEasyData2 // TODO: This name was guessed.
{
    boost::function<void(unsigned int, unsigned int)> JobFunc;
    unsigned int Param2;
    unsigned int Param1;
};

struct SJobType256 // size == 256???
{
    SJobExecParam JobExecParam;
    char Data[256 - (sizeof(SJobExecParam) + sizeof(const char*))]; // TODO: Is this correct?
    const char* Name;
};
}
}
