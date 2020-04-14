#include "CriSystem.h"
#include "fnd/Allocators.h"
#include "cri_atom_pc.h"
#include "cri_atom.h"
#include "cri_file_system.h"
#include "cri_mana_pc.h"
#include <new>

namespace app
{
namespace cri
{
void* CRIAPI CriUserAlloc(void* obj, CriUint32 size)
{
    return static_cast<csl::fnd::IAllocator*>(obj)->Alloc(size);
}

void CRIAPI CriUserFree(void* obj, void* mem)
{
    static_cast<csl::fnd::IAllocator*>(obj)->Free(mem);
}
}

struct CriSystem::Impl
{
    csl::fnd::IAllocator* Allocator; // TODO: Is this right?
    // TODO: Data Members

    /* <b>Wii U: TODO, PC: TODO</b> */
    void Cleanup()
    {
        // TODO
    }

    /* <b>Wii U: TODO, PC: TODO</b> */
    void ResetServerThread()
    {
        // TODO
    }

    /* <b>Wii U: 0x021ca854, PC: TODO</b> */
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

    /* <b>Wii U: 0x021cae0c, PC: TODO</b> */
    void Update()
    {
        criAtomEx_ExecuteMain();
        criMana_SyncMasterTimer();
        criMana_ExecuteMain();
    }

    Impl(csl::fnd::IAllocator* allocator) : Allocator(allocator)
    {
        // TODO
        Setup();
    }

    // TODO: Functions
};

CriSystem::CriSystem()
{
    impl = static_cast<Impl*>(allocator->Alloc(sizeof(Impl)));
    if (impl)
    {
        new (impl) Impl(allocator);
    }
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
    // TODO
}

static void* CriSystem_init()
{
    CriSystem* v = new (fnd::GetSingletonAllocator()) CriSystem();
    v->AddRef();
    return v;
}

static void CriSystem_destroy(void* ptr)
{
    CriSystem* v = static_cast<CriSystem*>(ptr);
    v->Release();
}

DEFINE_SINGLETON_INIT(CriSystem);
}
