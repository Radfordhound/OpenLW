#pragma once
#include "System/Handle.h"
#include <csl/math/vector3.h>

namespace app
{
namespace game
{
class ColliShape;
} // game

namespace Player
{
enum ESurfaceDirection
{
    // TODO
};

enum BodyCollisionType
{
    // TODO
};

// TODO: Should this be part of PlayerPhysicalBehavior.h instead?
struct SGroundInfo
{
    bool isGrounded;
    unsigned char padding1[0xf];
    csl::math::Vector3 field_0x10;
    csl::math::Vector3 field_0x20;
    game::ColliShape* field_0x30;
    unsigned int field_0x34;
    fnd::Handle<game::ColliShape> field_0x38;
};

LWAPI_STATIC_ASSERT_SIZE(SGroundInfo, 0x40)
} // Player
} // app
