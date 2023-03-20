// TODO: The name of this file is correct, but the path was guessed!
#include "pch.h"
#include "DeviceData.h"

namespace app
{
namespace hid
{
void ResPadDeviceData::Init()
{
    field_0x0 = 0;
    field_0x4 = 0;
    field_0x8 = 0;
    field_0xc = 0;
    field_0x10 = 0;
    field_0x14 = field_0xc;
    field_0x18 = field_0x10;
    field_0x1c = field_0xc;
    field_0x20 = field_0x10;
    field_0x24 = 1;
    field_0x25 = 0;
    field_0x26 = 7;
    PortIndex = -1;
    field_0x28 = 0;
    field_0x2c = false;
    field_0x2d = false;
}

void ResPadDeviceData::InitDiff()
{
    field_0x8 = 0;
    field_0x4 = 0;
}

void ResGyroDeviceData::Init()
{
    // TODO
}

void ResAccDeviceData::Init()
{
    // TODO
}

void ResTouchDeviceData::Init()
{
    // TODO
}

void ResMotorDeviceData::Init()
{
    // TODO
}

void ResDeviceData::Repeat::Init()
{
    field_0x0 = 0;
    field_0x4 = 0.40000001f;
    field_0x8 = 0.08000000f;
}

void ResDeviceData::Init(bool hasRepeat)
{
    PadData.Init();
    GyroData.Init();
    AccData.Init();
    TouchData.Init();
    MotorData.Init();

    if (hasRepeat)
    {
        RepeatData.Init();
    }
}
}
}
