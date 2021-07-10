#pragma once
#include "ResPadDeviceData.h"
#include "ResGyroDeviceData.h"
#include "ResAccDeviceData.h"
#include "ResTouchDeviceData.h"
#include "ResMotorDeviceData.h"

namespace app
{
namespace hid
{
struct ResDeviceData // sizeof == 0xC0
{
    struct Repeat // sizeof == 0xC
    {
        float field_0x0;
        float field_0x4;
        float field_0x8;

        // Wii U: 0x022790c8, PC: Inlined
        void Init();
    };

    ResPadDeviceData PadData;
    ResGyroDeviceData GyroData;
    ResAccDeviceData AccData;
    ResTouchDeviceData TouchData;
    ResMotorDeviceData MotorData;
    Repeat RepeatData;

    // Wii U: 0x022790f0, PC: 0x004f5d90
    void Init(bool hasRepeat);
};
}
}
