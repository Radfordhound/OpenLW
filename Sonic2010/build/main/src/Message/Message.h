#pragma once

namespace app
{
// TODO: These names were guessed based on information from a
// Runners decompilation and information from Lost World.
enum EMessageID
{
    CATEGORY_SYSTEM = 0x1000,
    CATEGORY_GAME_OBJECT_3D = 0x2000,
    CATEGORY_GAME = 0x3000,
    CATEGORY_DAMAGE = 0x4000,
    CATEGORY_PLAYER = 0x5000,
    CATEGORY_OBJECT = 0x6000,
    CATEGORY_CAMERA = 0x8000,
    CATEGORY_COLLISION = 0x9000,
    CATEGORY_PATH = 0xA000,
    CATEGORY_TERRAIN = 0xB000,
    CATEGORY_HUD = 0xC000,
};

namespace fnd
{
class Message
{
public:
    const int id;
    unsigned int sender;
    unsigned int receiver;
    bool received;
    bool broadcasted;
    unsigned int mask;

    LWAPI(0x021A0BB4, 0x0049A630)
    virtual Message* Clone() const;

    LWAPI(0x021A0C28, 0x0049A620)
    virtual ~Message();

    LWAPI(0x021A0C94, 0x0049A5F0)
    Message(const int id);
};

LWAPI_STATIC_ASSERT_SIZE(Message, 0x18)
} // fnd
} // app
