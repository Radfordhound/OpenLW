// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "DeviceManager.h"
#include "DeviceData.h"

namespace app
{
namespace hid
{
class DeviceBase;

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

	// Wii U: 0x02279328, PC: TODO
    void UserProcUIRelease();

	// TODO: This is almost surely static?
	// Wii U: 0x022793b4, PC: TODO
    void UserProcUIReleaseCallback(void* param_1);
	
    // Wii U: 0x022793d8, PC: TODO
    void UserProcUIAcquired();

	// TODO: This is almost surely static?
	// Wii U: 0x02279470, PC: TODO
	void UserProcUIAcquiredCallback(void* param_1);

    // Wii U: 0x02279494, PC: 0x004f63e0
    Impl(csl::fnd::IAllocator* allocator);

	// Wii U: 0x02279c24, PC: TODO
    void ConvertProcData();

    // Wii U: 0x02279cd4, PC: 0x004f6480
    void ConvertData();

	// Wii U: 0x02279658, PC: 0x004f5f70
    void CreatePadData(const ResPadDeviceData& in, ResPadDeviceData& out);

    // Wii U: 0x02279918, PC: TODO
    void SetPort(ResDeviceData* deviceData, std::size_t portIndex);

    // Wii U: 0x0227997c, PC: 0x004f61b0
    void CreateData();

	// Wii U: 0x02279e68, PC: TODO
    void connectCheck();

    // Wii U: 0x0227a0ac, PC: TODO
    ResPadDeviceData& GetPadDevice(std::size_t index);

	// Wii U: 0x0227a0bc, PC: TODO
    ResGyroDeviceData& GetGyroDevice(std::size_t index);

    // Wii U: 0x0227a0d0, PC: TODO
    ResAccDeviceData& GetAccDevice(std::size_t index);

    // Wii U: 0x0227a0e4, PC: TODO
    ResTouchDeviceData& GetTouchDevice(std::size_t index);

	// Wii U: 0x0227a0f8, PC: TODO
    ResMotorDeviceData& GetMotorDevice(std::size_t index);
};
}
}
