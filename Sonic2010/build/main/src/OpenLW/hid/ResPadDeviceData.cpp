#include "ResPadDeviceData.h"

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
}
}
