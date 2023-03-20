#include "pch.h"
#include "Hedgehog/Base/Thread/hhThread.h"
#include "Hedgehog/Base/hhBaseCommon.h"
#include "Hedgehog/Base/System/hhSharedString.h"
#include "Hedgehog/Base/System/hhMemoryAllocator.h"
#include <Hedgehog/Rsdx/System/RsdxThread.h>

using namespace hh::rsdx;

namespace hh
{
namespace base
{
#ifdef _WIN32
const DWORD MS_VC_EXCEPTION = 0x406D1388;

#pragma pack(push,8)
typedef struct tagTHREADNAME_INFO
{
    DWORD dwType; // Must be 0x1000.
    LPCSTR szName; // Pointer to name (in user addr space).
    DWORD dwThreadID; // Thread ID (-1=caller thread).
    DWORD dwFlags; // Reserved for future use, must be zero.
} THREADNAME_INFO;
#pragma pack(pop)
#endif

struct CThreadImpInternal : public CObject // size == 24
{
#ifdef _WIN32
    HANDLE field_0x0;
    unsigned int field_0x4;
#else
    CRsdxThreadEntryMain* field_0x0;
    RsdxNativeThread field_0x4;
#endif

    unsigned char field_0x8;
    // TODO: Other data members?
    CThreadImp* field_0xc;

#ifndef _WIN32
    CSharedString field_0x10;
#endif

public:
    LWAPI(0x03a0053c, 0x00d15730)
    static unsigned int RSDXSTDCALL ThreadProc(void* param_1)
    {
        SInitializeHHBaseSetting* baseSetting = GetHHBaseSetting();
        void* workerThread;

        if (baseSetting->InitializeWorkerThread)
        {
            workerThread = baseSetting->InitializeWorkerThread();
        }

        static_cast<CThreadImpInternal*>(param_1)->field_0xc->Process();
        
        if (baseSetting->FinalizeWorkerThread)
        {
            baseSetting->FinalizeWorkerThread(workerThread);
        }
        
        // TODO: Do we call __endthreadex explicitly here? Or is it called automatically by the compiler?
        return 1;
    }

    LWAPI(0x03a00614, NONE)
    void SetCPUID(int cpuID)
    {
#ifdef _WIN32
        ULONG_PTR processAffinityMask, systemAffinityMask;
        GetProcessAffinityMask(GetCurrentProcess(),
            &processAffinityMask, &systemAffinityMask);

        DWORD dwThreadAffinityMask = (1 << ((byte)cpuID & 0x1f));
        if ((systemAffinityMask & dwThreadAffinityMask) != 0)
        {
            SetThreadAffinityMask(field_0x0, dwThreadAffinityMask);
        }
#else
        RsdxSetThreadAffinityMask(field_0x0, 1 << cpuID);
#endif
    }

#ifdef _WIN32
    static void FUN_00d15780(unsigned int threadID, const CSharedString& name)
    {
        THREADNAME_INFO info;
        info.dwType = 0x1000;
        info.szName = name.c_str();
        info.dwThreadID = threadID;
        info.dwFlags = 0;

#pragma warning(push)
#pragma warning(disable: 6320 6322)
        __try
        {
            RaiseException(MS_VC_EXCEPTION, 0, sizeof(info) / sizeof(ULONG_PTR), (ULONG_PTR*)&info);
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
        }
#pragma warning(pop)
    }
#endif

    LWAPI(0x03a00624, 0x00d158a0)
    void Initialize(const CSharedString& name, int cpuID, std::size_t stackSize)
    {
        field_0x8 = 0;
        field_0xc = nullptr;

#ifdef _WIN32
        field_0x0 = (HANDLE)_beginthreadex(nullptr, stackSize, &ThreadProc, this,
            NORMAL_PRIORITY_CLASS | CREATE_SUSPENDED, &field_0x4);

        FUN_00d15780(field_0x4, name);
#else
        RsdxNativeThread thread;
        CRsdxThreadEntryMain* threadEntry = RsdxCreateThread(stackSize,
            &ThreadProc, this, true, &thread, 0xffffffff);

        if (threadEntry != nullptr)
        {
            field_0x4 = thread;
        }

        field_0x0 = threadEntry;
        field_0x10 = name;

        RsdxSetThreadName(field_0x0, field_0x10.c_str());
#endif

        SetCPUID(cpuID);
    }

    LWAPI(0x03a00824, NONE)
    void Join(unsigned int param_1)
    {
        if (field_0x0)
        {
#ifdef _WIN32
            WaitForSingleObject(field_0x0, (param_1 != 0) ?
                param_1 : INFINITE);
#else
            RsdxWaitSystemResource(field_0x0, (param_1 != 0) ?
                param_1 : -1);
#endif
        }
    }

    LWAPI(0x03a0088c, TODO)
    void SetPriority(EThreadPriority priority)
    {
        // TODO
    }

    inline CThreadImpInternal(const CSharedString& name,
        int cpuID, std::size_t stackSize)
    {
        Initialize(name, cpuID, stackSize);
    }

    LWAPI(0x03a00900, 0x00d15950)
    virtual ~CThreadImpInternal()
    {
#ifdef _WIN32
        WaitForSingleObject(field_0x0, INFINITE);
        CloseHandle(field_0x0);
#else
        RsdxWaitSystemResource(field_0x0, -1);
        RsdxCloseSystemResource(field_0x0);
#endif
    }
};

CThreadImp::CThreadImp(const CSharedString& name, int cpuID, std::size_t stackSize)
{
    CThreadImpInternal* impl = new (__HH_DBG_INFO, hhGetHeapHandle(0)) // line: 333
        CThreadImpInternal(name, cpuID, stackSize);

    impl->field_0xc = this;
    m_impl = impl;
    m_thread = nullptr;
}

CThreadImp::~CThreadImp()
{
    delete m_impl;
}

void CThreadImp::Start()
{
    m_impl->field_0x8 = 1;

#ifdef _WIN32
    ResumeThread(m_impl->field_0x0);
#else
    RsdxResumeThread(m_impl->field_0x0);
#endif
}

void CThreadImp::Join(unsigned int param_1)
{
    m_impl->Join(param_1);
}

void CThreadImp::SetPriority(EThreadPriority priority)
{
    m_impl->SetPriority(priority);
}

void CThreadImp::Process()
{
    if (m_thread)
    {
        m_thread->Process();
    }
}

void CThreadImp::SetThread(CThread* thread)
{
    m_thread = thread;
}
}
}
