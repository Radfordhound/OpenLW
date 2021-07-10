#include "Hedgehog/Rsdx/System/RsdxThread.h"
#include "Hedgehog/Rsdx/HeapMemory/Allocator/hhRsdxMemoryMain.h"
#include <cstring>

namespace hh
{
namespace rsdx
{
bool CRsdxThreadEntryMain::CloseSystemResource()
{
    return true;
}

bool CRsdxThreadEntryMain::WaitSystemResource()
{
    return EndThread();
}

CRsdxThreadEntryMain::~CRsdxThreadEntryMain()
{
    EndThread();
}

unsigned int CRsdxThreadEntryMain::ThreadEntry()
{
    if (m_state != RSDX_THREAD_STATE_RUNNING)
    {
        return static_cast<unsigned int>(-1);
    }

    unsigned int r = m_threadFuncPtr(m_threadParam);
    field_0x10 = r;
    field_0x14 = 0;
    return r;
}

#ifdef _WIN32
DWORD WINAPI CRsdxThreadEntryMain::ThreadEntryStatic(void* threadParam)
{
    CRsdxThreadEntryMain* thread = static_cast<CRsdxThreadEntryMain*>(threadParam);
    return thread->ThreadEntry();
}
#elif defined(__WIIU__)
int CRsdxThreadEntryMain::ThreadEntryStatic(int argc, const char** argv)
{
    CRsdxThreadEntryMain* thread = (CRsdxThreadEntryMain*)argv;
    return thread->ThreadEntry();
}
#endif

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

void CRsdxThreadEntryMain::SetThreadName(const char* name)
{
#ifdef _WIN32
    THREADNAME_INFO info;
    info.dwType = 0x1000;
    info.szName = name;
    info.dwThreadID = ThreadID;
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
#elif defined(__WIIU__)
    OSSetThreadName(&CafeThread);
#endif
}

bool CRsdxThreadEntryMain::EndThread()
{
#ifdef _WIN32
    // If the thread has already been stopped, return false.
    RSDXTHREADSTATE state = m_state;
    if (state == RSDX_THREAD_STATE_STOPPED)
    {
        return false;
    }

    // Set the thread state to indicate that the thread is now stopped.
    m_state = RSDX_THREAD_STATE_STOPPED;

    // If the thread was suspended leading up to this function call, resume it.
    if (state == RSDX_THREAD_STATE_SUSPENDED)
    {
        ResumeThread(ThreadHandle);
    }

    // Wait for the thread to finish.
    WaitForSingleObject(ThreadHandle, INFINITE);

    // Store the thread's exit code.
    DWORD exitCode = 0;
    GetExitCodeThread(ThreadHandle, &exitCode);

    field_0x10 = exitCode;
    field_0x14 = 0;

    // Close the thread's handle and return true.
    CloseHandle(ThreadHandle);
    return true;
#elif defined(__WIIU__)
    // TODO
#endif
}

CRsdxThreadEntryMain* CRsdxThreadEntryMain::CreateThread(
    const RSDXTHREADTHREADCREATIONINFO* createInfo)
{
#ifdef _WIN32
    // Allocate buffer for thread.
    void* ptr = RsdxAllocateDefaultMemory(0, sizeof(CRsdxThreadEntryMain));
    std::memset(ptr, 0, sizeof(CRsdxThreadEntryMain));

    // Construct thread object.
    CRsdxThreadEntryMain* thread = new (ptr) CRsdxThreadEntryMain();
    thread->m_threadFuncPtr = createInfo->ThreadFuncPtr;
    thread->m_threadParam = createInfo->ThreadParam;

    // Create Win32 thread.
    DWORD threadID;
    HANDLE threadHandle = ::CreateThread(NULL, createInfo->StackSize,
        ThreadEntryStatic, thread, CREATE_SUSPENDED, &threadID);

    if (threadHandle == NULL)
    {
        thread->~CRsdxThreadEntryMain();
        RsdxFreeDefaultMemory(0, thread);
        return nullptr;
    }

    thread->ThreadHandle = threadHandle;
    thread->ThreadID = threadID;

    // Set thread name if requested.
    if (createInfo->Name)
    {
        thread->SetThreadName(createInfo->Name);
    }

    // Set thread priority.
    SetThreadPriority(threadHandle, createInfo->Priority);

    // Setup thread state and return.
    if (createInfo->StartSuspended)
    {
        thread->m_state = RSDX_THREAD_STATE_SUSPENDED;
        return thread;
    }
    else
    {
        thread->m_state = RSDX_THREAD_STATE_RUNNING;
        ResumeThread(threadHandle);
        return thread;
    }
#elif defined(__WIIU__)
    // TODO
#endif
}

#ifdef _WIN32
CRsdxThreadEntryMain::CRsdxThreadEntryMain() :
    ThreadID(0),
    m_state(RSDX_THREAD_STATE_NONE),
    field_0x10(0x10000),
    field_0x14(0),
    m_threadFuncPtr(nullptr),
    m_threadParam(nullptr)
{
    // TODO?
}
#elif defined(__WIIU__)
CRsdxThreadEntryMain::CRsdxThreadEntryMain()
{
    // TODO
}
#endif

CRsdxThreadEntryMain* RsdxCreateThread(std::size_t stackSize,
    RsdxThreadExecFunc threadFuncPtr, void* threadParam, bool startSuspended,
    RsdxNativeThread* nativeThread, unsigned int param_6)
{
    RSDXTHREADTHREADCREATIONINFO createInfo =
    {
        threadFuncPtr,                                                  // ThreadFuncPtr
        threadParam,                                                    // ThreadParam
        "RsdxThread",                                                   // Name
        0x10,                                                           // Priority
        stackSize,                                                      // StackSize
        param_6,                                                        // field_0x14   TODO
        startSuspended                                                  // StartSuspended
    };
    
    CRsdxThreadEntryMain* thread = CRsdxThreadEntryMain::CreateThread(&createInfo);
    if (thread && nativeThread)
    {
#ifdef _WIN32
        *nativeThread = thread->ThreadID;
#elif defined(__WIIU__)
        *nativeThread = &thread->CafeThread;
#endif
    }

    return thread;
}

void RsdxThreadSleep(unsigned int milliseconds)
{
#ifdef _WIN32
    Sleep(milliseconds);
#elif defined(__WIIU__)
    // TODO
#endif
}
}
}
