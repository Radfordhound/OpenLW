#include "DeviceManager.h"
#include <new>

namespace app
{
namespace hid
{
struct DeviceManager::Impl // sizeof == 0x38
{
    void* fx00;
    csl::fnd::IAllocator* allocator;
    // TODO: Data Members

    Impl(csl::fnd::IAllocator* allocator)
    {
        // TODO
    }

    // TODO: Other Functions
};

void DeviceManager::Setup()
{
    impl = static_cast<Impl*>(allocator->Alloc(sizeof(Impl)));
    if (impl)
    {
        new (impl) Impl(allocator);
    }
}

void DeviceManager::Poll(float param_1)
{
    if (impl)
    {
        // TODO
    }
}

static void* DeviceManager_init()
{
    // TODO
    return nullptr;
}

static void DeviceManager_destroy(void* ptr)
{
    // TODO
}

DEFINE_SINGLETON_INIT(DeviceManager);
}
}
