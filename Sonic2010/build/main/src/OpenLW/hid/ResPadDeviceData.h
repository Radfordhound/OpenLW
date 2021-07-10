#pragma once

namespace app
{
namespace hid
{
struct ResPadDeviceData // sizeof == 0x30
{
    unsigned int field_0x0;
    unsigned int field_0x4;
    unsigned int field_0x8;
    float field_0xc;
    float field_0x10;
    float field_0x14;
    float field_0x18;
    float field_0x1c;
    float field_0x20;
    unsigned char field_0x24;
    unsigned char field_0x25;
    unsigned char field_0x26;
    char PortIndex;
    unsigned int field_0x28;
    bool field_0x2c;
    bool field_0x2d;

    // Wii U: 0x02278f54, PC: 0x004f5c80
    void Init();

    // Wii U: 0x02278fb8, PC: 0x004f5cc0
    void InitDiff();
};
}
}
