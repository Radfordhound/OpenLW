// TODO: The name of this file is correct, but the path was guessed!
#include "OpenLW/pch.h"
#ifdef USE_CRIWARE
#include "CriSystem.h"

// TODO: REMOVE THIS TEMPORARY CODE
#include <cri_atom_pc.h>
#include <cri_atom.h>
#include <cri_file_system.h>
#include <cri_mana_pc.h>
// =========================================================================

#include <new>

// TODO: REMOVE THIS CODE PLEASE!!!!
extern "C"
{
    void __fload_withFB(void)
    {
        __asm
        {
            mov    eax,DWORD PTR [edx+0x4]
            and    eax,0x7ff00000
            cmp    eax,0x7ff00000
            je     0x00000012
            fld    QWORD PTR [edx]
            ret    
            mov    eax,DWORD PTR [edx+0x4]
            sub    esp,0xa
            or     eax,0x7fff0000
            mov    DWORD PTR [esp+0x6],eax
            mov    eax,DWORD PTR [edx+0x4]
            mov    ecx,DWORD PTR [edx]
            shld   eax,ecx,0xb
            shl    ecx,0xb
            mov    DWORD PTR [esp+0x4],eax
            mov    DWORD PTR [esp],ecx
            fld    TBYTE PTR [esp]
            add    esp,0xa
            test   eax,0x0
            mov    eax,DWORD PTR [edx+0x4]
            ret    
        }
    }

    void FUN_10153e9f(void)
    {
        __asm
        {
            lea edx,[esp+0x4]
            call __fload_withFB
        }
    }

    void _libm_sse2_cos_precise(void)
    {
        __asm
        {
            sub    esp,0x8
            stmxcsr DWORD PTR [esp+0x4]
            mov    eax,DWORD PTR [esp+0x4]
            and    eax,0x7f80
            cmp    eax,0x1f80
            jne    0x00000027
            fnstcw WORD PTR [esp]
            mov    ax,WORD PTR [esp]
            and    ax,0x7f
            cmp    ax,0x7f
            lea    esp,[esp+0x8]
            jne    0x0000019f
            pextrw eax,xmm0,0x3
            and    ax,0x7fff
            sub    ax,0x3030
            cmp    ax,0x10c5
            ja     0x0000017e
            movlpd xmm1,QWORD PTR ds:0x100402e0
            mulsd  xmm1,xmm0
            movlpd xmm2,QWORD PTR ds:0x100402e8
            cvtsd2si edx,xmm1
            addsd  xmm1,xmm2
            movlpd xmm3,QWORD PTR ds:0x10040300
            subsd  xmm1,xmm2
            movapd xmm2,XMMWORD PTR ds:0x100402f0
            mulsd  xmm3,xmm1
            unpcklpd xmm1,xmm1
            add    edx,0x1c7610
            movsd  xmm4,xmm0
            and    edx,0x3f
            movapd xmm5,XMMWORD PTR ds:0x100402d0
            lea    eax,ds:0x1003faa0
            shl    edx,0x5
            add    eax,edx
            mulpd  xmm2,xmm1
            subsd  xmm0,xmm3
            mulsd  xmm1,QWORD PTR ds:0x10040308
            subsd  xmm4,xmm3
            movlpd xmm7,QWORD PTR [eax+0x8]
            unpcklpd xmm0,xmm0
            movsd  xmm3,xmm4
            subsd  xmm4,xmm2
            mulpd  xmm5,xmm0
            subpd  xmm0,xmm2
            movapd xmm6,XMMWORD PTR ds:0x100402b0
            mulsd  xmm7,xmm4
            subsd  xmm3,xmm4
            mulpd  xmm5,xmm0
            mulpd  xmm0,xmm0
            subsd  xmm3,xmm2
            movapd xmm2,XMMWORD PTR [eax]
            subsd  xmm1,xmm3
            movlpd xmm3,QWORD PTR [eax+0x18]
            addsd  xmm2,xmm3
            subsd  xmm7,xmm2
            mulsd  xmm2,xmm4
            mulpd  xmm6,xmm0
            mulsd  xmm3,xmm4
            mulpd  xmm2,xmm0
            mulpd  xmm0,xmm0
            addpd  xmm5,XMMWORD PTR ds:0x100402c0
            mulsd  xmm4,QWORD PTR [eax]
            addpd  xmm6,XMMWORD PTR ds:0x100402a0
            mulpd  xmm5,xmm0
            movsd  xmm0,xmm3
            addsd  xmm3,QWORD PTR [eax+0x8]
            mulsd  xmm1,xmm7
            movsd  xmm7,xmm4
            addsd  xmm4,xmm3
            addpd  xmm6,xmm5
            movlpd xmm5,QWORD PTR [eax+0x8]
            subsd  xmm5,xmm3
            subsd  xmm3,xmm4
            addsd  xmm1,QWORD PTR [eax+0x10]
            mulpd  xmm6,xmm2
            addsd  xmm5,xmm0
            addsd  xmm3,xmm7
            addsd  xmm1,xmm5
            addsd  xmm1,xmm3
            addsd  xmm1,xmm6
            unpckhpd xmm6,xmm6
            addsd  xmm1,xmm6
            addsd  xmm4,xmm1
            movapd xmm0,xmm4
            ret    
            jg     0x0000019f
            pextrw eax,xmm0,0x3
            and    ax,0x7fff
            pinsrw xmm0,eax,0x3
            movlpd xmm1,QWORD PTR ds:0x10040330
            subsd  xmm1,xmm0
            movapd xmm0,xmm1
            ret    
            sub    esp,0x8
            movq   QWORD PTR [esp],xmm0
            call   FUN_10153e9f
            fstp   QWORD PTR [esp]
            movq   xmm0,QWORD PTR [esp]
            add    esp,0x8
            ret    
        }
    }
}
// ==================================================

namespace app
{
namespace cri
{
LWAPI(TODO, TODO)
void* CRIAPI CriUserAlloc(void* obj, CriUint32 size)
{
    return static_cast<csl::fnd::IAllocator*>(obj)->Alloc(size);
}

LWAPI(TODO, TODO)
void CRIAPI CriUserFree(void* obj, void* mem)
{
    static_cast<csl::fnd::IAllocator*>(obj)->Free(mem);
}
}

struct CriSystem::Impl
{
    csl::fnd::IAllocator* Allocator; // TODO: Is this right?
    // TODO: Data Members

    LWAPI(0x021cac74, TODO)
    void Cleanup()
    {
        // TODO
    }

    LWAPI(TODO, TODO)
    void ResetServerThread()
    {
        // TODO
    }

    LWAPI(0x021ca854, 0x004ad2c0)
    void Setup()
    {
        // TODO
        criFs_SetUserMallocFunction(cri::CriUserAlloc, Allocator); // TODO: Change this to use &PooledAllocator instead
        criFs_SetUserFreeFunction(cri::CriUserFree, Allocator); // TODO: Change this to use &PooledAllocator instead
        // TODO

        criAtom_SetUserMallocFunction(cri::CriUserAlloc, Allocator); // TODO: Change this to use &PooledAllocator instead
        criAtom_SetUserFreeFunction(cri::CriUserFree, Allocator); // TODO: Change this to use &PooledAllocator instead

        // TODO

        // ======================================
        // TODO: DO THIS ON A SEPARATE THREAD LIKE IN THE ORIGINAL GAME

        CriAtomExConfig_PC atomConfig;
        criAtomEx_SetDefaultConfig_PC(&atomConfig);

        criAtomEx_Initialize_PC(&atomConfig, nullptr, 0);
        CriBool isInitialized = criAtomEx_IsInitialized();
        // ======================================

        // Initialize Mana
        CriManaLibConfig manaConfig =
        {
            4,                          // max_decoder_handles
            CRIMANA_THREAD_MODEL_MULTI, // thread_model
            0                           // version
        };

        criMana_Initialize(&manaConfig, nullptr, 0);
    }

    LWAPI(0x021cae0c, TODO)
    void Update()
    {
        criAtomEx_ExecuteMain();
        criMana_SyncMasterTimer();
        criMana_ExecuteMain();
    }

    LWAPI(NONE, 0x004ad440)
    Impl(csl::fnd::IAllocator* allocator) :
        Allocator(allocator)
    {
        // TODO
        Setup();
    }

    LWAPI(NONE, TODO)
    ~Impl()
    {
        Cleanup();
        // TODO
    }

    // TODO: Functions
};

CriSystem::~CriSystem()
{
    delete m_impl;
    m_impl = nullptr;
}

void* CriSystem::GetClient() const
{
    // TODO
    return nullptr;
}

unsigned int CriSystem::GetErrorCode() const
{
    // TODO
    return 0;
}

bool CriSystem::IsASR() const
{
    // TODO
    return false;
}

void CriSystem::ResetErrorCode()
{
    // TODO
}

void CriSystem::ResetServerThread()
{
    // TODO
}

void CriSystem::SetDefaultServerThread()
{
    // TODO
}

void CriSystem::SetErrorCode()
{
    // TODO
}

void CriSystem::Update()
{
    if (m_impl)
    {
        m_impl->Update();
    }
}

CriSystem::CriSystem()
{
    m_impl = static_cast<Impl*>(m_allocator->Alloc(sizeof(Impl)));
    if (m_impl)
    {
        new (m_impl) Impl(m_allocator);
    }
}

LWAPI(0x021cb180, TODO)
static void* CriSystem_init()
{
    CriSystem* criSys = new (fnd::GetSingletonAllocator()) CriSystem();
    criSys->AddRef();
    return criSys;
}

LWAPI(0x021cb1d0, TODO)
static void CriSystem_destroy(void* ptr)
{
    static_cast<CriSystem*>(ptr)->Release();
}

DEFINE_SINGLETON(CriSystem, CriSystem_init, CriSystem_destroy);
}
#endif
