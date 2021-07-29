#pragma once
#include "DeviceWin.h"

namespace app
{
namespace hid
{
struct DeviceManager::Impl // sizeof == 0x38
{
    DeviceBase* Device;
    csl::fnd::IAllocator* Allocator;
    unsigned int field_0x8;
    float field_0xc;
    bool PadDeviceCrossAndStick;
    bool field_0x11;
    bool field_0x12;
    bool ConnectCheck[MAX_DEVICE_PORTS];
    unsigned int field_0x1c;
    unsigned int field_0x20;
    unsigned int field_0x24;
    ResDeviceData* Devices1;
    ResDeviceData* Devices2;
    unsigned long long field_0x30; // TODO: Is this actually another bool array of MAX_DEVICE_PORTS?

    // Wii U: 0x02279494, PC: 0x004f63e0
    Impl(csl::fnd::IAllocator* allocator) :
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

    // Wii U: 0x02279e68, PC: TODO
    void connectCheck()
    {
        // TODO
    }

    // Wii U: 0x02279cd4, PC: 0x004f6480
    void ConvertData()
    {
        // TODO
    }

    // Wii U: TODO, PC: TODO
    void ConvertProcData()
    {
        // TODO
    }

    // Wii U: TODO, PC: TODO
    void SetPort(ResDeviceData* deviceData, std::size_t portIndex)
    {
        if (portIndex < Device->GetPortMax())
        {
            char pindx = static_cast<char>(portIndex);
            deviceData->PadData.PortIndex = pindx;
            // TODO
        }
    }

    // Wii U: 0x02279658, PC: 0x004f5f70
    void CreatePadData(const ResPadDeviceData& in, ResPadDeviceData& out)
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

    // Wii U: 0x0227997c, PC: 0x004f61b0
    void CreateData()
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

    // Wii U: 0x0227a0d0, PC: TODO
    ResAccDeviceData& GetAccDevice(std::size_t index)
    {
        return Devices2[index].AccData;
    }

    // Wii U: 0x0227a0bc, PC: TODO
    ResGyroDeviceData& GetGyroDevice(std::size_t index)
    {
        return Devices2[index].GyroData;
    }

    // Wii U: 0x0227a0f8, PC: TODO
    ResMotorDeviceData& GetMotorDevice(std::size_t index)
    {
        return Devices2[index].MotorData;
    }

    // Wii U: 0x0227a0ac, PC: TODO
    ResPadDeviceData& GetPadDevice(std::size_t index)
    {
        return Devices2[index].PadData;
    }

    // Wii U: 0x0227a0e4, PC: TODO
    ResTouchDeviceData& GetTouchDevice(std::size_t index)
    {
        return Devices2[index].TouchData;
    }

    // Wii U: TODO, PC: TODO
    void UserProcUIAcquired()
    {
        // TODO
    }

    // Wii U: TODO, PC: TODO
    void UserProcUIRelease()
    {
        // TODO
    }
};
}
}
