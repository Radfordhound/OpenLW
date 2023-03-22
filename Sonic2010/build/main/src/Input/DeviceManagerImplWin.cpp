// TODO: Both the name of this file and its path were guessed!
#include "OpenLW/pch.h"
#include "DeviceManagerImpl.h"
#include "DeviceWin.h"

namespace app
{
namespace hid
{
void DeviceManager::Impl::UserProcUIRelease()
{
    // TODO
}

void DeviceManager::Impl::UserProcUIReleaseCallback(void* param_1)
{
    // TODO
}

void DeviceManager::Impl::UserProcUIAcquired()
{
    // TODO
}

void DeviceManager::Impl::UserProcUIAcquiredCallback(void* param_1)
{
    // TODO
}

DeviceManager::Impl::Impl(csl::fnd::IAllocator* allocator) :
    Device(nullptr),
    Allocator(allocator),
    field_0x8(0),
    field_0xc(0),
    PadDeviceCrossAndStick(false),
    field_0x11(false),
    field_0x12(false),
    field_0x1c(0),
    field_0x20(0),
    field_0x24(0)
{
    Device = &DeviceWin::GetInstance();
    std::size_t deviceCount = Device->GetPortMax();

    for (int i = 0; i < MAX_DEVICE_PORTS; ++i)
    {
        ConnectCheck[i] = false;
    }

    Devices2 = static_cast<ResDeviceData*>(Allocator->Alloc(
        deviceCount * sizeof(ResDeviceData)));

    DeviceBase::DeviceDataClear(Devices2, deviceCount, true);

    Devices1 = static_cast<ResDeviceData*>(Allocator->Alloc(
        deviceCount * sizeof(ResDeviceData)));

    DeviceBase::DeviceDataClear(Devices1, deviceCount, true);

    field_0x30 = 0;
}

void DeviceManager::Impl::ConvertProcData()
{
    // TODO
}

void DeviceManager::Impl::ConvertData()
{
    // TODO
}

void DeviceManager::Impl::CreatePadData(const ResPadDeviceData& in, ResPadDeviceData& out)
{
    unsigned char prevfield_0x24 = out.field_0x24;
    unsigned char prevfield_0x25 = out.field_0x25;

    out.field_0x24 = in.field_0x24;
    out.field_0x25 = in.field_0x25;

    if (in.field_0x24 == 0)
    {
        unsigned int prevfield_0x0 = out.field_0x0;
        out.field_0x0 = in.field_0x0;

        out.field_0xc = in.field_0xc;
        out.field_0x10 = in.field_0x10;
        out.field_0x14 = in.field_0x14;
        out.field_0x18 = in.field_0x18;
        out.field_0x1c = in.field_0x1c;
        out.field_0x20 = in.field_0x20;
        out.field_0x26 = in.field_0x26;

        if (!prevfield_0x24)
        {
            out.field_0x28 = in.field_0x28;
            out.field_0x2c = in.field_0x2c;
            out.field_0x2d = in.field_0x2d;

            unsigned int uvar7 = (prevfield_0x0 ^ in.field_0x0);
            out.field_0x4 = (uvar7 & in.field_0x0);
            out.field_0x8 = (uvar7 & prevfield_0x0);
            return;
        }
    }
    else if (in.field_0x24 != 2)
    {
        if (in.field_0x24 != 3)
        {
            out.Init();
        }

        out.field_0x28 = in.field_0x28;
        out.field_0x2c = in.field_0x2c;
        out.field_0x2d = in.field_0x2d;
        return;
    }
    else if (prevfield_0x24 == 0)
    {
        out.field_0x25 = prevfield_0x25;
    }

    out.InitDiff();
}

void DeviceManager::Impl::SetPort(ResDeviceData* deviceData, std::size_t portIndex)
{
    if (portIndex < Device->GetPortMax())
    {
        char pindx = static_cast<char>(portIndex);
        deviceData->PadData.PortIndex = pindx;
        // TODO
    }
}

void DeviceManager::Impl::CreateData()
{
    if (Device)
    {
        ResDeviceData deviceData[MAX_DEVICE_PORTS];
        std::size_t deviceCount = Device->GetPortMax();
        Device->GetDeviceData(deviceData, deviceCount);

        if (deviceCount)
        {
            for (std::size_t i = 0; i < deviceCount; ++i)
            {
                ResDeviceData* curDevice = (Devices1 + i);
                CreatePadData(deviceData[i].PadData, curDevice->PadData);
                // TODO
                SetPort(curDevice, i);
            }
        }
    }
}

void DeviceManager::Impl::connectCheck()
{
    // TODO
}

ResPadDeviceData& DeviceManager::Impl::GetPadDevice(std::size_t index)
{
    return Devices2[index].PadData;
}

ResGyroDeviceData& DeviceManager::Impl::GetGyroDevice(std::size_t index)
{
    return Devices2[index].GyroData;
}

ResAccDeviceData& DeviceManager::Impl::GetAccDevice(std::size_t index)
{
    return Devices2[index].AccData;
}

ResTouchDeviceData& DeviceManager::Impl::GetTouchDevice(std::size_t index)
{
    return Devices2[index].TouchData;
}

ResMotorDeviceData& DeviceManager::Impl::GetMotorDevice(std::size_t index)
{
    return Devices2[index].MotorData;
}
}
}
