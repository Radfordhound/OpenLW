// TODO: The name of this file is correct, but the path was guessed!
#include "OpenLW/pch.h"
#include "DlcManager.h"

namespace app
{
namespace xgame
{
DlcManager::~DlcManager()
{
    // TODO
}

bool DlcManager::IsComplete() const
{
    // TODO
    return true;
}

bool DlcManager::IsPurchase(unsigned short param_1) const
{
    // TODO
    return false;
}

void DlcManager::Update()
{
    // TODO
}

void DlcManager::Cleanup()
{
    // TODO
}

DlcManager::DlcManager()
{
    // TODO
}

namespace dlc
{
LWAPI(0x02b3ff2c, TODO)
static void* DlcManagerCreate()
{
    // TODO: Un-comment this block once AocManager is implemented:
    /*if (!AocManager::IsInitialized())
        return nullptr;*/

    DlcManager* dlcMgr = new (fnd::GetSingletonAllocator()) DlcManager();
    dlcMgr->AddRef();
    return dlcMgr;
}
}

LWAPI(0x02b3ffb0, TODO)
static void DlcManager_destroy(void* ptr)
{
    static_cast<DlcManager*>(ptr)->Release();
}

DEFINE_SINGLETON(DlcManager, dlc::DlcManagerCreate, DlcManager_destroy);
}
}
