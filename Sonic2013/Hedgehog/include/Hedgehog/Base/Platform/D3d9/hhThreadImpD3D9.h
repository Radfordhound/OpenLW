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

    // Wii U: 0x03a006d0, PC: 0x00d156b0
    CThreadImp(const CSharedString& name, int cpuID,
        std::size_t stackSize);

    // Wii U: 0x03a0079c, PC: 0x00d15910
    virtual ~CThreadImp();

    // Wii U: 0x03a00810, PC: 0x00d155e0
    void Start();

    // Wii U: 0x03a00848, PC: 0x00d15600
    void Join(unsigned int param_1 = 0);

    // Wii U: 0x03a008e0, PC: TODO
    void SetPriority(EThreadPriority priority);

    // Wii U: 0x03a009c0, PC: TODO
    virtual void Process();

    // Wii U: 0x03a009d0, PC: TODO
    void SetThread(CThread* thread);
};
}
}
