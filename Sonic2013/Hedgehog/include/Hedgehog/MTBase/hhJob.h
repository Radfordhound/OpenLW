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
    SJobExecFunc JobExec;
    unsigned int field_0x8;
    SJobJoint* JobJoint;
    boost::function<void()> Job;
    unsigned int field_0x20;
    unsigned int field_0x24;

    // TODO: Other data members?
};

typedef unsigned int (*SJobFunc)(void* param_1);

struct SJobExecuteHeader : public rsdx::RsdxSListHeader // TODO: Is this correct?
{
    unsigned int field_0x4;
    SJobFunc Job;
    void* JobParam;
};

struct SJobType256 // size == 256???
{
    SJobExecParam JobExecParam;

    // TODO: Other data members.
    const char* Name;
    // TODO: Other data members?

    char Padding[224]; // TODO
};
}
}
