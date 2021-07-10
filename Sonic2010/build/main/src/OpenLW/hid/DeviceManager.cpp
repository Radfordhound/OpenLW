#include "DeviceManager.h"
#include "../fnd/Allocators.h"

#ifdef _WIN32
#include "../Platform/Win32/DeviceManagerImplWin.h"
#endif

#include <new>

namespace app
{
namespace hid
{
DeviceManager::~DeviceManager()
{
    Cleanup();
}

void DeviceManager::Cleanup()
{
    if (m_impl)
    {
        if (m_impl->Devices1)
        {
            m_impl->Allocator->Free(m_impl->Devices1);
        }

        if (m_impl->Devices2)
        {
            m_impl->Allocator->Free(m_impl->Devices2);
        }

        m_allocator->Free(m_impl);
        m_impl = nullptr;
    }
}

void DeviceManager::ConnectCheck()
{
    if (!m_impl) return;
    m_impl->connectCheck();
}

std::size_t DeviceManager::GetPortMax() const
{
    return (m_impl) ? m_impl->Device->GetPortMax() : 0;
}

void DeviceManager::Poll(float param_1)
{
    if (m_impl)
    {
        m_impl->field_0xc = param_1;

        if (m_impl->Device)
        {
            m_impl->Device->Poll(param_1);
        }

        m_impl->CreateData();
        m_impl->ConvertData();
    }
}

void DeviceManager::SetConnectCheck(std::size_t portIndex, bool value)
{
    if (!m_impl) return;
    m_impl->ConnectCheck[portIndex] = value;
}

void DeviceManager::SetPadDeviceCrossAndStick(bool value)
{
    if (!m_impl) return;
    m_impl->PadDeviceCrossAndStick = value;
}

void DeviceManager::Setup()
{
    m_impl = static_cast<Impl*>(m_allocator->Alloc(sizeof(Impl)));
    if (m_impl)
    {
        new (m_impl) Impl(m_allocator);
    }
}

// Wii U: 0x0227a10c, PC: TODO
static void* DeviceManager_init()
{
    DeviceManager* dmgr = new (fnd::GetSingletonAllocator()) DeviceManager();
    dmgr->AddRef();
    return dmgr;
}

// Wii U: 0x0227a15c, PC: TODO
static void DeviceManager_destroy(void* ptr)
{
    static_cast<DeviceManager*>(ptr)->Release();
}

DEFINE_SINGLETON(DeviceManager, DeviceManager_init, DeviceManager_destroy);
}
}
