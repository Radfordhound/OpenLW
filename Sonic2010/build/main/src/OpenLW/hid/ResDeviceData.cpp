#include "ResDeviceData.h"

namespace app
{
namespace hid
{
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
