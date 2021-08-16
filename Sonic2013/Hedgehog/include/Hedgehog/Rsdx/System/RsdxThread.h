#pragma once
#include "../System/RsdxObject.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
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

    // Wii U: TODO, PC: 0x00464aa0 (GENERIC RETURN TRUE)
    bool CloseSystemResource();

    // Wii U: TODO, PC: 0x00c24e20
    bool WaitSystemResource();

    // Wii U: TODO, PC: 0x00c24f30
    ~CRsdxThreadEntryMain();

    // Wii U: 0x036c0e34, PC: Inlined
    unsigned int ThreadEntry();

#ifdef _WIN32
    // Wii U: N/A, PC: 0x00c24c50
    static DWORD WINAPI ThreadEntryStatic(void* threadParam);
#elif defined(__WIIU__)
    // Wii U: 0x036c0e9c, PC: N/A
    static int ThreadEntryStatic(int argc, const char** argv);
#endif

    // Wii U: 0x036c0ea4, PC: 0x00c24d00
    void SetThreadName(const char* name);

    // Wii U: TODO, PC: 0x00c24c90
    bool EndThread();

    // TODO

    // Wii U: 0x036c0eac, PC: 0x00c24e30
    static CRsdxThreadEntryMain* CreateThread(
        const RSDXTHREADTHREADCREATIONINFO* createInfo);

    // Wii U: 0x036c1180, PC: TODO
    bool SetThreadAffinity(unsigned int mask);

    // Wii U: TODO, PC: TODO
    CRsdxThreadEntryMain();
};

// Wii U: 0x036c11e4, PC: 0x00c24f60
CRsdxThreadEntryMain* RsdxCreateThread(std::size_t stackSize,
    RsdxThreadExecFunc threadFuncPtr, void* threadParam, bool startSuspended,
    RsdxNativeThread* nativeThread, unsigned int param_6);

// Wii U: 0x036c128c (THUNK), PC: TODO
void RsdxSetThreadAffinityMask(RsdxSystemResource* thread, unsigned int mask);

// Wii U: 0x036c1290, PC: TODO
void RsdxSetThreadName(RsdxSystemResource* thread, const char* name);

// Wii U: 0x036c12ac, PC: Inlined
void RsdxThreadSleep(unsigned int milliseconds);
}
}
