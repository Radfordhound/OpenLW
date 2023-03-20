#pragma once
#include "hhJobJoint.h"
#include <Hedgehog/Rsdx/System/RsdxIntrusivePtr.h>

namespace hh
{
namespace MTBase
{
LWAPI(0x036e63d8, 0x00c29a80)
void hhMTSimpleJobJointUnlock(SJobJoint* jobJoint);

LWAPI(0x036e6420, TODO)
void hhMTSimpleJobJointRelease(SJobJoint* jobJoint);

LWAPI(0x036e6464, 0x00c29da0)
void jobJointFinish(SJobJoint* jobJoint);

LWAPI(0x036e6544, TODO)
void hhMTSimpleJobDestroyDefault(SJobType256* job);

LWAPI(0x036e654c, TODO)
void hhMTExecuteJob(SJobExecParam* jobExecParam, bool param_2);

LWAPI(0x036e6f10, 0x00c29fa0)
void hhMTSimpleJobStart();

LWAPI(0x036e6fe4, NONE)
void hhMTSimpleJobEntry(SJobType256* job, unsigned int param_2);

LWAPI(0x036e7050, NONE)
SJobType256* hhMTSimpleJobCreateDefault();

LWAPI(0x036e70a0, 0x00c29ce0)
SJobJoint* hhMTSimpleJobJointCreate();

LWAPI(0x036e70f8, TODO)
SEventHolder* hhMTSimpleJobCreateFinishSignal();

LWAPI(0x036e712c, TODO)
SJobJoint* hhMTSimpleJobJointStaticCreate(const char* name = nullptr);

LWAPI(0x036e7198, 0x00c29d90)
SJobJoint* hhMTSimpleJobJointDynamicCreate(const char* name = nullptr);

LWAPI(0x036e71cc, 0x00c29a40)
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

LWAPI(0x036e7220, NONE)
void hhMTSimpleJobLinkNext(SJobExecParam* jobExecParam,
    SJobJoint* jobJoint, unsigned int param_3);

LWAPI(0x036e7274, NONE)
void hhMTSimpleJobLinkNext(SJobType256* job,
    SJobJoint* jobJoint, unsigned int param_3);

LWAPI(0x036e7278, NONE)
void hhMTSimpleJobBind(SJobExecParam* jobExecParam, SJobJoint* jobJoint);

LWAPI(0x036e72d8, NONE)
void hhMTSimpleJobBind(SJobType256* job, SJobJoint* jobJoint);

LWAPI(0x036e72dc, 0x00c29fe0)
void hhMTSimpleJobFunction(const boost::function<void()>& jobFunc,
    const SMTUpdateHint& updateHint);

LWAPI(0x036e73b8, 0x00c2a100)
void hhMTSimpleJobFunction2(
    const boost::function<void(unsigned int, unsigned int)>& jobFunc,
    unsigned int param_2, const SMTUpdateHint& updateHint);

LWAPI(0x036e76e0, 0x00c29f60)
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
