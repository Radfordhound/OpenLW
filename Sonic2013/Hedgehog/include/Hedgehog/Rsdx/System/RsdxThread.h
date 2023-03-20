#pragma once
#include "../System/RsdxObject.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <process.h>
#elif defined(__WIIU__)
#include <coreinit/thread.h>
#endif

namespace hh
{
namespace rsdx
{
// TODO: This name was guessed, what's it actually called?
#ifdef _WIN32
typedef DWORD RsdxNativeThread;
#define RSDXSTDCALL __stdcall
#elif defined(__WIIU__)
typedef OSThread* RsdxNativeThread;
#define RSDXSTDCALL
#endif

typedef unsigned int (RSDXSTDCALL *RsdxThreadExecFunc)(void* threadParam);

struct RSDXTHREADTHREADCREATIONINFO
{
    RsdxThreadExecFunc ThreadFuncPtr;
    void* ThreadParam;
    const char* Name;
    int Priority;
    std::size_t StackSize;
    unsigned int field_0x14;
    bool StartSuspended;
};

enum RSDXTHREADSTATE // TODO: This name was guessed, what's it actually called?
{
    RSDX_THREAD_STATE_NONE = 0,
    RSDX_THREAD_STATE_SUSPENDED = 1,
    RSDX_THREAD_STATE_RUNNING = 2,
    RSDX_THREAD_STATE_STOPPED = 3
};

class CRsdxThreadEntryMain : public RsdxSystemResource
{
#ifdef _WIN32
    DWORD m_threadID;
#elif defined(__WIIU__)
    OSThread m_cafeThread;
#endif

    // TODO: The following data members are only correct on PC; this is incorrect on Wii U!
    RSDXTHREADSTATE m_state;
    unsigned int field_0x10;
    unsigned int field_0x14;
    RsdxThreadExecFunc m_threadFuncPtr;
    void* m_threadParam;

public:
    inline RsdxNativeThread GetThreadHandle()
    {
#ifdef _WIN32
        return m_threadID;
#elif defined(__WIIU__)
        return &m_cafeThread;
#endif
    }

    LWAPI(TODO, 0x00464aa0)
    bool CloseSystemResource();

    LWAPI(TODO, 0x00c24e20)
    bool WaitSystemResource();

    LWAPI(TODO, 0x00c24f30)
    ~CRsdxThreadEntryMain();

    LWAPI(0x036c0e34, NONE)
    unsigned int ThreadEntry();

#ifdef _WIN32
    LWAPI(NONE, 0x00c24c50)
    static DWORD WINAPI ThreadEntryStatic(void* threadParam);
#elif defined(__WIIU__)
    LWAPI(0x036c0e9c, NONE)
    static int ThreadEntryStatic(int argc, const char** argv);
#endif

    LWAPI(0x036c0ea4, 0x00c24d00)
    void SetThreadName(const char* name);

    LWAPI(TODO, 0x00c24c90)
    bool EndThread();

    // TODO

    LWAPI(0x036c0eac, 0x00c24e30)
    static CRsdxThreadEntryMain* CreateThread(
        const RSDXTHREADTHREADCREATIONINFO* createInfo);

    LWAPI(0x036c1180, TODO)
    bool SetThreadAffinity(unsigned int mask);

    LWAPI(TODO, TODO)
    CRsdxThreadEntryMain();
};

LWAPI(0x036c11e4, 0x00c24f60)
CRsdxThreadEntryMain* RsdxCreateThread(std::size_t stackSize,
    RsdxThreadExecFunc threadFuncPtr, void* threadParam, bool startSuspended,
    RsdxNativeThread* nativeThread, unsigned int param_6);

LWAPI(0x036c128c, TODO)
void RsdxSetThreadAffinityMask(RsdxSystemResource* thread, unsigned int mask);

LWAPI(0x036c1290, TODO)
void RsdxSetThreadName(RsdxSystemResource* thread, const char* name);

LWAPI(0x036c12ac, NONE)
void RsdxThreadSleep(unsigned int milliseconds);
}
}
