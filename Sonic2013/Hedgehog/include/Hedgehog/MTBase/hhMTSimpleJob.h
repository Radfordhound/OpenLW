#pragma once
#include "hhJobJoint.h"
#include <Hedgehog/Rsdx/System/RsdxIntrusivePtr.h>

namespace hh
{
namespace MTBase
{
// Wii U: 0x036e63d8, PC: 0x00c29a80
void hhMTSimpleJobJointUnlock(SJobJoint* jobJoint);

// Wii U: 0x036e6420, PC: TODO
void hhMTSimpleJobJointRelease(SJobJoint* jobJoint);

// Wii U: 0x036e6464, PC: 0x00c29da0
void jobJointFinish(SJobJoint* jobJoint);

// Wii U: 0x036e6544, PC: TODO
void hhMTSimpleJobDestroyDefault(SJobType256* job);

// Wii U: 0x036e654c, PC: TODO
void hhMTExecuteJob(SJobExecParam* jobExecParam, bool param_2);

// Wii U: 0x036e6f10, PC: 0x00c29fa0
void hhMTSimpleJobStart();

// Wii U: 0x036e6fe4, PC: Inlined
void hhMTSimpleJobEntry(SJobType256* job, unsigned int param_2);

// Wii U: 0x036e7050, PC: Inlined
SJobType256* hhMTSimpleJobCreateDefault();

// Wii U: 0x036e70a0, PC: 0x00c29ce0
SJobJoint* hhMTSimpleJobJointCreate();

// Wii U: 0x036e70f8, PC: TODO
SEventHolder* hhMTSimpleJobCreateFinishSignal();

// Wii U: 0x036e712c, PC: TODO
SJobJoint* hhMTSimpleJobJointStaticCreate(const char* name = nullptr);

// Wii U: 0x036e7198, PC: 0x00c29d90
SJobJoint* hhMTSimpleJobJointDynamicCreate(const char* name = nullptr);

// Wii U: 0x036e71cc, PC: 0x00c29a40
void hhMTSimpleJobJointLock(SJobJoint* jobJoint);

struct SJobJointLockUnlock // TODO: Move this to another header?
{
    // TODO: Any data members?

    // TODO: Is this correct?
    static inline void Lock(SJobJoint* ptr)
    {
        if (ptr)
        {
            hhMTSimpleJobJointLock(ptr);
        }
    }

    // TODO: Is this correct?
    static inline void Unlock(SJobJoint* ptr)
    {
        if (ptr)
        {
            hhMTSimpleJobJointUnlock(ptr);
        }
    }
};

struct SMTUpdateHint // TODO: Move this to another header?
{
    unsigned int field_0x0;
    rsdx::rsdx_intrusive_ptr<SJobJoint, SJobJointLockUnlock> field_0x4;
    rsdx::rsdx_intrusive_ptr<SJobJoint, SJobJointLockUnlock> field_0x8;
    const char* JobName;
    // TODO: Other data members?

    inline SMTUpdateHint(unsigned int param_1,
        SJobJoint* param_2, SJobJoint* param_3 = nullptr,
        const char* jobName = nullptr)
    {
        field_0x4 = param_2;
        field_0x8 = param_3;
        field_0x0 = param_1;
        JobName = jobName;
    }
};

// Wii U: 0x036e7220, PC: Inlined
void hhMTSimpleJobLinkNext(SJobExecParam* jobExecParam,
    SJobJoint* jobJoint, unsigned int param_3);

// Wii U: 0x036e7274 (THUNK), PC: Inlined
void hhMTSimpleJobLinkNext(SJobType256* job,
    SJobJoint* jobJoint, unsigned int param_3);

// Wii U: 0x036e7278, PC: Inlined
void hhMTSimpleJobBind(SJobExecParam* jobExecParam, SJobJoint* jobJoint);

// Wii U: 0x036e72d8 (THUNK), PC: Inlined
void hhMTSimpleJobBind(SJobType256* job, SJobJoint* jobJoint);

// Wii U: 0x036e72dc, PC: 0x00c29fe0
void hhMTSimpleJobFunction(const boost::function<void()>& jobFunc,
    const SMTUpdateHint& updateHint);

// Wii U: 0x036e73b8, PC: 0x00c2a100
void hhMTSimpleJobFunction2(
    const boost::function<void(unsigned int, unsigned int)>& jobFunc,
    unsigned int param_2, const SMTUpdateHint& updateHint);

// Wii U: 0x036e76e0, PC: 0x00c29f60
void hhMTSimpleJobBlockUntilSignal(SJobJoint* jobJoint, unsigned int signal);

class CMTJobJointEntity // TODO: Move this to another header?
{
    SJobJoint* m_ptr;

public:
    inline CMTJobJointEntity(SJobJoint* ptr) :
        m_ptr(ptr) {}

    void BlockUntilSignal()
    {
        hhMTSimpleJobBlockUntilSignal(m_ptr, 0);
    }

    inline void Lock() // TODO: Does this function actually exist?
    {
        hhMTSimpleJobJointLock(m_ptr);
    }

    inline void Unlock() // TODO: Does this function actually exist?
    {
        hhMTSimpleJobJointUnlock(m_ptr);
    }

    inline operator bool() const // TODO: Does this function actually exist?
    {
        return (m_ptr != nullptr);
    }

    inline operator SJobJoint*() // TODO: Does this function actually exist?
    {
        return m_ptr;
    }
};
}
}
