#pragma once
namespace app
{
// TODO: Move this to another header?
enum ID // TODO: These were taken from a Runners decompilation. It seems most of these are accurate from a quick glance, but some are not.
{
    SYSTEM = 0x1000,
    GAME = 0x3000,
    COMMON = 0x4000,
    PLAYER = 0x5000,
    CHAO = 0x5500, // TODO: This one is probably not in LW lol
    OBJECT = 0x6000,
    ENEMY = 0x7000,
    CAMERA = 0x8000,
    COLLISION = 0x9000,
    PATH = 0xA000,
    TERRAIN = 0xB000,
    HUD = 0xC000,
    SOUND = 0xD000,
    MENU = 0xE000,
    NET = 0xF000,
    SOCIAL = 0xF800 // TODO: This one is probably not in LW lol
};

// TODO: Move this to another header?
enum SystemID
{
    // TODO: Are these correct?
    /*START_PAUSE = SYSTEM,
    END_PAUSE,
    END_PAUSE_EXIT_STAGE,
    ENABLE_PAUSE*/

    WARNING_END = (SYSTEM | 3),
    ADVANCE_SEQUENCE
};

namespace fnd
{
struct Message // size == 0x18
{
    const int ID;
    unsigned int Sender;
    unsigned int Receiver;
    bool Received;
    bool Broadcasted;
    unsigned int Mask;

    // Wii U: 0x021a0bb4, PC: TODO
    virtual Message* Clone() const;

    // Wii U: 0x021a0c94, PC: TODO
    virtual ~Message();

    // Wii U: 0x021a0c28, PC: 0x0049a5f0
    Message(const int id);
};
}
}
