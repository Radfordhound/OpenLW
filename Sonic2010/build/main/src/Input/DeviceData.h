// TODO: The name of this file is correct, but the path was guessed!
#pragma once

namespace app
{
namespace hid
{
#ifndef MAX_DEVICE_PORTS
#define MAX_DEVICE_PORTS 8
#endif

struct ResSendDeviceData // size == 0xC
{
    // TODO
};

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

    LWAPI(0x02278f54, 0x004f5c80)
    void Init();

    LWAPI(0x02278fb8, 0x004f5cc0)
    void InitDiff();
};

struct ResGyroDeviceData // sizeof == 0x40
{
    // TODO

    LWAPI(TODO, TODO)
    void Init();
};

struct ResAccDeviceData // sizeof == 0x20
{
    // TODO

    LWAPI(TODO, TODO)
    void Init();

    // TODO?
};

struct ResTouchDeviceData // sizeof == 0x18
{
    // TODO

    LWAPI(TODO, TODO)
    void Init();

    // TODO
};

struct ResMotorDeviceData // sizeof == 0xC
{
    // TODO

    LWAPI(TODO, TODO)
    void Init();
};

struct ResDeviceData // sizeof == 0xC0
{
    struct Repeat // sizeof == 0xC
    {
        float field_0x0;
        float field_0x4;
        float field_0x8;

        LWAPI(0x022790c8, NONE)
        void Init();
    };

    ResPadDeviceData PadData;
    ResGyroDeviceData GyroData;
    ResAccDeviceData AccData;
    ResTouchDeviceData TouchData;
    ResMotorDeviceData MotorData;
    Repeat RepeatData;

    LWAPI(0x022790f0, 0x004f5d90)
    void Init(bool hasRepeat);
};
} // hid
} // app
