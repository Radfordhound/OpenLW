#include "DeviceWin.h"
#include "DevicePadWin.h"
#include "DevicePadKB.h"
#include "../../fnd/Allocators.h"
#include "csl/math/math.h"

namespace app
{
namespace hid
{
DeviceTouchWin* DeviceWin::TouchDevice;

std::size_t DeviceWin::GetPortMax() const
{
    return m_portMax;
}

void DeviceWin::GetDeviceData(ResDeviceData* devices, std::size_t deviceCount)
{
    // TODO
}

void DeviceWin::Setup(void* instHandle, void* surfaceHandle)
{
    // Setup keyboard.
    DevicePadKB* padKB = new (m_allocator)
        DevicePadKB(instHandle, surfaceHandle);

    padKB->AddRef();
    m_platforms.push_back_unchecked(padKB);

    // Setup gamepad.
    DevicePadWin* padWin = new (m_allocator)
        DevicePadWin(instHandle, surfaceHandle);

    padWin->AddRef();
    m_platforms.push_back_unchecked(padWin);

    // Setup mouse/touch input.
    TouchDevice = new (m_allocator) DeviceTouchWin(instHandle, surfaceHandle);
    TouchDevice->AddRef();
    m_platforms.push_back_unchecked(TouchDevice);

    // Compute maximum number of ports.
    for (std::size_t i = 0; i < m_platforms.size(); ++i)
    {
        m_portMax = csl::math::Max(m_portMax, m_platforms[i]->GetPortMax());
    }
}

DeviceWin::DeviceWin() :
    m_portMax(0)
{
    TouchDevice = nullptr;
}

// Wii U: N/A, PC: 0x004f7f40
static void* DeviceWin_init()
{
    DeviceWin* dev = new (fnd::GetSingletonAllocator()) DeviceWin();
    dev->AddRef();
    return dev;
}

// Wii U: N/A, PC: 0x0095fa00
static void DeviceWin_destroy(void* ptr)
{
    static_cast<DeviceWin*>(ptr)->Release();
}

DEFINE_SINGLETON(DeviceWin, DeviceWin_init, DeviceWin_destroy);
}
}
