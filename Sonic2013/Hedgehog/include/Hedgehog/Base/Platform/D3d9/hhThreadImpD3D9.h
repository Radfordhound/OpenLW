#pragma once
#include "../../System/hhObject.h"

namespace hh
{
namespace base
{
class CThread;
class CSharedString;
struct CThreadImpInternal;

enum EThreadPriority
{
    THREAD_PRIORITY_UNKNOWN2 = 2
};

class CThreadImp : public CObject // size == 12
{
    CThreadImpInternal* m_impl;
    CThread* m_thread;

public:
    struct IFactory
    {
        virtual CThreadImp* MakeInstance(const CSharedString& name,
            int cpuID, std::size_t stackSize) = 0;
    };

    LWAPI(0x03a006d0, 0x00d156b0)
    CThreadImp(const CSharedString& name, int cpuID,
        std::size_t stackSize);

    LWAPI(0x03a0079c, 0x00d15910)
    virtual ~CThreadImp();

    LWAPI(0x03a00810, 0x00d155e0)
    void Start();

    LWAPI(0x03a00848, 0x00d15600)
    void Join(unsigned int param_1 = 0);

    LWAPI(0x03a008e0, TODO)
    void SetPriority(EThreadPriority priority);

    LWAPI(0x03a009c0, TODO)
    virtual void Process();

    LWAPI(0x03a009d0, TODO)
    void SetThread(CThread* thread);
};
}
}
