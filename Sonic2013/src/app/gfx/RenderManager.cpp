#include "RenderManager.h"

namespace app
{
namespace gfx
{
struct RenderManager::Impl
{
    // TODO: Data Members

    void Setup(const SetupInfo& setupInfo)
    {
        // TODO
    }

    // TODO: Other Functions
};

void RenderManager::Setup(const SetupInfo& setupInfo)
{
    // TODO
}

static void* RenderManager_init()
{
    // TODO
    return nullptr;
}

static void RenderManager_destroy(void* ptr)
{
    // TODO
}

DEFINE_SINGLETON_INIT(RenderManager);
}
}
