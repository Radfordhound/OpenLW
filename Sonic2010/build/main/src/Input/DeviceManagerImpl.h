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

	LWAPI(0x02279328, TODO)
    void UserProcUIRelease();

	// TODO: This is almost surely static?
	LWAPI(0x022793b4, TODO)
    void UserProcUIReleaseCallback(void* param_1);
	
    LWAPI(0x022793d8, TODO)
    void UserProcUIAcquired();

	// TODO: This is almost surely static?
	LWAPI(0x02279470, TODO)
	void UserProcUIAcquiredCallback(void* param_1);

    LWAPI(0x02279494, 0x004f63e0)
    Impl(csl::fnd::IAllocator* allocator);

	LWAPI(0x02279c24, TODO)
    void ConvertProcData();

    LWAPI(0x02279cd4, 0x004f6480)
    void ConvertData();

	LWAPI(0x02279658, 0x004f5f70)
    void CreatePadData(const ResPadDeviceData& in, ResPadDeviceData& out);

    LWAPI(0x02279918, TODO)
    void SetPort(ResDeviceData* deviceData, std::size_t portIndex);

    LWAPI(0x0227997c, 0x004f61b0)
    void CreateData();

	LWAPI(0x02279e68, TODO)
    void connectCheck();

    LWAPI(0x0227a0ac, TODO)
    ResPadDeviceData& GetPadDevice(std::size_t index);

	LWAPI(0x0227a0bc, TODO)
    ResGyroDeviceData& GetGyroDevice(std::size_t index);

    LWAPI(0x0227a0d0, TODO)
    ResAccDeviceData& GetAccDevice(std::size_t index);

    LWAPI(0x0227a0e4, TODO)
    ResTouchDeviceData& GetTouchDevice(std::size_t index);

	LWAPI(0x0227a0f8, TODO)
    ResMotorDeviceData& GetMotorDevice(std::size_t index);
};
}
}
