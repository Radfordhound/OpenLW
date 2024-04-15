#pragma once
#include "System/Handle.h"
#include "System/Component/Goc.h"
#include <csl/math/vector3.h>
#include <csl/ut/array.h>
#include <csl/ut/bitset.h>

namespace csl
{
namespace fnd
{
struct IAllocator;
} // fnd

namespace math
{
struct Quaternion;
struct Matrix34;
} // math
} // csl

namespace app
{
namespace game
{
class ColliShapeCInfo;
class ColliShape;
class CollisionCache;
class PhysicsRaycastOutput;
class PhysicsOverlapOutput;
} // game

namespace Player
{
class CPlayer;

enum ESurfaceDirection
{
    // TODO
};

enum BodyCollisionType
{
    BODY_COLLISION_TYPE_NORMAL = 0,
    BODY_COLLISION_TYPE_SQUAT = 1,
    BODY_COLLISION_TYPE_BALL = 3,
};

enum CollisionID
{
    // TODO
};

// TODO: Should this be part of PlayerPhysicalBehavior.h instead?
struct SGroundInfo
{
    bool isGrounded;
    unsigned char padding1[0xf];
    csl::math::Vector3 groundNormal;
    csl::math::Vector3 field_0x20;
    game::ColliShape* field_0x30;
    unsigned int field_0x34;
    fnd::Handle<game::ColliShape> field_0x38;
};

LWAPI_STATIC_ASSERT_SIZE(SGroundInfo, 0x40)

struct SSurfaceInfo
{
    csl::math::Vector3              field_0x0;
    csl::math::Vector3              field_0x10;
    unsigned int                    field_0x20;
    fnd::Handle<game::ColliShape>   field_0x24;
};

class CCollision
{
    // TODO

public:
    class SCheckOnGroundPacket
    {
        // TODO
    };

    LWAPI(0x0293cc80, TODO)
    CCollision(csl::fnd::IAllocator* param_1);

    LWAPI(0x0293ce00, TODO)
    ~CCollision();

    LWAPI(0x0293ce54, TODO)
    void Initialize(CPlayer* param_1, csl::math::Vector3 const& param_2, float param_3, float param_4);

    LWAPI(0x0293cecc, TODO)
    void GetPosition() const;

    LWAPI(0x0293ced4, TODO)
    void GetVelocity() const;

    LWAPI(0x0293cedc, TODO)
    void GetRotation() const;

    LWAPI(0x0293cee4, TODO)
    void GetUpVector() const;

    LWAPI(0x0293cf90, TODO)
    void GetMaxSlopeAngle() const;

    LWAPI(0x0293cf98, TODO)
    void GetOffset() const;

    LWAPI(0x0293d000, TODO)
    void GetOffsetLength() const;

    LWAPI(0x0293d008, TODO)
    void SetPosition(csl::math::Vector3 const& param_1);

    LWAPI(0x0293d010, TODO)
    void SetRotation(csl::math::Quaternion const& param_1, bool param_2);

    LWAPI(0x0293d018, TODO)
    void ReorientRotation(csl::math::Quaternion const& param_1, csl::math::Quaternion* param_2);

    LWAPI(0x0293d044, TODO)
    void SetMaxSlope(float param_1);

    LWAPI(0x0293d074, TODO)
    void GetRadius() const;

    LWAPI(0x0293d07c, TODO)
    void GetHeight() const;

    LWAPI(0x0293d084, TODO)
    void GetSkinWidth() const;

    LWAPI(0x0293d08c, TODO)
    void SetDisableBreakableSpindash(bool param_1);

    LWAPI(0x0293d09c, TODO)
    void SetDisableBreakableStomping(bool param_1);

    LWAPI(0x0293d0ac, TODO)
    void SetDieableBreakableOff();

    LWAPI(0x0293d0e8, TODO)
    void TestRotate(csl::math::Quaternion const& param_1, csl::math::Quaternion const& param_2, csl::math::Quaternion* param_3);

    LWAPI(0x0293d114, TODO)
    void TestRotateDirection(csl::math::Vector3 const& param_1, csl::math::Vector3 const& param_2, csl::math::Vector3* param_3);

    LWAPI(0x0293d270, TODO)
    void GetPhysicsWorld();

    LWAPI(0x0293d3c0, TODO)
    void SweepCapsule(csl::math::Vector3& param_1, csl::math::Vector3 const& param_2, csl::math::Vector3 const& param_3, csl::math::Quaternion const& param_4, unsigned int param_5, bool param_6, bool param_7);

    LWAPI(0x0293d6b8, TODO)
    void Raycast(csl::math::Vector3 const& param_1, csl::math::Vector3 const& param_2, unsigned int param_3, game::PhysicsRaycastOutput* param_4) const;

    LWAPI(0x0293d7e4, TODO)
    void UpdateSurfaceInfoFromRaycast(game::PhysicsRaycastOutput const& param_1, bool param_2);

    LWAPI(0x0293d8ac, 0x00861fb0)
    unsigned int GetSurfaceNum() const;

    LWAPI(0x0293d8c4, 0x00862210)
    SSurfaceInfo* GetSurfaceInfo(unsigned int index) const;

    LWAPI(0x0293d9cc, TODO)
    void GetSurfaceInfo(ESurfaceDirection param_1, csl::math::Matrix34 const& param_2) const;

    LWAPI(0x0293dc78, TODO)
    void OverlapTestForPushOut(csl::math::Vector3& param_1, csl::math::Vector3 const& param_2, csl::math::Vector3 const& param_3, csl::math::Vector3 const& param_4, unsigned int param_5);

    LWAPI(0x0293ddc0, TODO)
    void CheckPushOutByOlerlapAndSweep(csl::math::Vector3& param_1, csl::math::Vector3& param_2, csl::math::Vector3 const& param_3, csl::math::Vector3 const& param_4, unsigned int param_5);

    LWAPI(0x0293deac, TODO)
    void OverlapTestPhantom(csl::math::Vector3 const& param_1, float param_2, unsigned int param_3, csl::ut::MoveArray<game::PhysicsOverlapOutput>& param_4);

    LWAPI(0x0293df50, TODO)
    void CheckOverlapPhantom(csl::math::Vector3 const& param_1, csl::math::Vector3 const& param_2, unsigned int param_3);

    LWAPI(0x0293e044, TODO)
    void CheckOverlap(csl::math::Vector3 const& param_1, csl::math::Vector3 const& param_2, unsigned int param_3);

    LWAPI(0x0293e268, TODO)
    void CheckOverlap(csl::math::Vector3 const& param_1, csl::math::Quaternion const& param_2, unsigned int param_3);

    LWAPI(0x0293e3b0, TODO)
    void CheckOverlapAttribute(csl::math::Vector3 const& param_1, csl::math::Quaternion const& param_2, unsigned int param_3, bool* param_4, unsigned int param_5);

    LWAPI(0x0293e610, TODO)
    void CheckOverlapMovableObject(csl::math::Vector3 const& param_1, csl::math::Quaternion const& param_2, game::ColliShape** param_3, unsigned int param_4);

    LWAPI(0x0293e9e0, TODO)
    void CheckPushoutByRaycast(csl::math::Vector3* param_1, csl::math::Vector3 const& param_2, csl::math::Vector3 const& param_3);

    LWAPI(0x0293ec1c, TODO)
    void MoveForSweepMove(csl::math::Vector3 const& param_1, csl::math::Quaternion const& param_2, csl::math::Vector3 const& param_3, float param_4, bool param_5, bool param_6, float const* param_7);

    LWAPI(0x0293f0f0, TODO)
    void CheckGroundHit(game::PhysicsRaycastOutput& param_1, csl::math::Vector3 const& param_2, float param_3, bool param_4);

    LWAPI(0x0293f264, TODO)
    void CheckOnGroundByHitInfo(SGroundInfo* param_1, csl::math::Vector3 const& param_2, float param_3, bool param_4);

    LWAPI(0x0293f394, TODO)
    void CheckOnGround(SGroundInfo* param_1, SCheckOnGroundPacket const& param_2);

    LWAPI(0x0293f864, TODO)
    void CheckHitSurfaceByRaycast(csl::math::Matrix34 const& param_1, csl::math::Vector3 const* param_2);

    LWAPI(0x0293fb40, TODO)
    void IsHit() const;

    LWAPI(0x0293fb68, TODO)
    void ResetMinimumMoveLength();

    LWAPI(0x0293fb78, TODO)
    void SetEnableCollision(bool param_1);

    LWAPI(0x0293fb7c, TODO)
    void SetFilterEnale(unsigned int param_1, bool param_2);

    LWAPI(0x0293fba0, TODO)
    void ClearSurfaceInfo();

    LWAPI(0x0293fba8, TODO)
    void GetCharacterProxy() const;

    LWAPI(0x0293fbb0, TODO)
    void GetCharacterProxy();

    LWAPI(0x0293fbb8, TODO)
    void UpdateRayacstKeeperPosition(csl::math::Vector3 const& param_1, csl::math::Vector3 const& param_2, bool param_3);

    LWAPI(0x0293fc88, TODO)
    void SetPhantom(game::CollisionCache* param_1);
};

class CCollisionGOC : public CGOComponent
{
OPENLW_PRIVATE
    unsigned int                    m_field_0x10;
    unsigned char                   m_field_0x14;
    CPlayer*                        m_player;
    csl::ut::Bitset<unsigned int>   m_field_0x1c;

public:
    CCollision                      collision;

OPENLW_PRIVATE
    // TODO

public:
    LWAPI(0x102ffe70, 0x00fb0330)
    static const char* ID;

    LWAPI(0x0293fe00, TODO)
    CCollisionGOC(CPlayer* param_1);

    LWAPI(0x02940028, TODO)
    void Initialize();

    LWAPI(0x029402ac, TODO)
    void CreateTriggerShape(game::ColliShapeCInfo const& param_1, bool param_2, bool param_3);

    LWAPI(0x02940484, TODO)
    void SetUpGOCCollider(bool param_1);

    LWAPI(0x0294087c, TODO)
    void UpdatePosition(float param_1);

    LWAPI(0x029409a8, TODO)
    void CheckRequsetAndDestroyTriggerShape();

    LWAPI(0x02940ab4, TODO)
    void RequestRaycastJobFromQueue();

    LWAPI(0x02940b74, TODO)
    void ChangeRigidCollisionSize(BodyCollisionType param_1);

    LWAPI(0x02940b78, TODO)
    void ChangeBodyTriggerCollisionSize(BodyCollisionType param_1);

    LWAPI(0x02940d9c, TODO)
    void ChangeBodyCollision(BodyCollisionType param_1);

    LWAPI(0x02940dd8, TODO)
    void GetShape(unsigned int param_1);

    LWAPI(0x02940e04, TODO)
    void Disable2ndDefCollision();

    LWAPI(0x02940e90, TODO)
    void Update(float param_1);

    LWAPI(0x02940fe4, TODO)
    void RequestDestroyTriggerShape(game::ColliShape* param_1);

    LWAPI(0x0294109c, TODO)
    void RequestDestroyTriggerShape(unsigned int param_1);

    LWAPI(0x029410dc, TODO)
    void GetShape(unsigned int param_1) const;

    LWAPI(0x02941198, TODO)
    void GetShapeData(game::ColliShape const* param_1) const;

    LWAPI(0x02941238, TODO)
    void GetShapeData(unsigned int param_1) const;

    LWAPI(0x02941278, TODO)
    void SetTriggerEnable(CollisionID param_1, bool param_2);

    LWAPI(0x029412c0, TODO)
    void IsTrrigerEnable(CollisionID param_1) const;

    LWAPI(0x02941314, TODO)
    void SetAllTriggerEnable(bool param_1);

    LWAPI(0x02941370, TODO)
    void SetPhysicsEnable(bool param_1);

    LWAPI(0x02941380, TODO)
    void ChangeTriggerColilsionSize(unsigned int param_1, float const* param_2, csl::math::Vector3 const* param_3, csl::math::Quaternion const* param_4);

    LWAPI(0x02941508, TODO)
    void ChangeBodyTriggerCollisionSize(float param_1, csl::math::Vector3 const& param_2);

    LWAPI(0x02941690, TODO)
    void ResetPosition(csl::math::Vector3 const& param_1, csl::math::Quaternion const& param_2);

    LWAPI(0x02941720, TODO)
    void ResetRaycastKeepPosition(csl::math::Vector3 const& param_1, csl::math::Quaternion const& param_2);

    LWAPI(0x0294179c, TODO)
    void GetRigidSurfaceInfo(ESurfaceDirection param_1) const;

    LWAPI(0x029417e8, TODO)
    void CheckOverlapMaterial(csl::math::Vector3 const& param_1, csl::math::Quaternion const& param_2, unsigned int const* param_3, unsigned int param_4, unsigned int param_5, float param_6, game::PhysicsOverlapOutput* param_7);

    LWAPI(0x02941ac8, TODO)
    void RequestRaycast(csl::math::Vector3 const& param_1, csl::math::Vector3 const& param_2, unsigned int param_3, unsigned int param_4);

    LWAPI(0x02941b54, TODO)
    void RequestRaycast(csl::math::Vector3 const& param_1, csl::math::Vector3 const& param_2, unsigned int param_3, unsigned int param_4, int param_5);

    LWAPI(0x02941bf4, TODO)
    void GetRaycastHit(int param_1, game::PhysicsRaycastOutput& param_2) const;

    LWAPI(0x02941ca4, TODO)
    void GetRaycastHitByUserID(unsigned int param_1, game::PhysicsRaycastOutput& param_2) const;

    LWAPI(0x02941d74, TODO)
    void GetRaycastHitMultiply(int param_1, int* param_2) const;

    LWAPI(0x02941de4, TODO)
    void Enable2ndDefCollision();

    LWAPI(0x02941e20, TODO)
    void GetPhysicsWorld();

    LWAPI(0x02941fb4, TODO)
    ~CCollisionGOC();
};
} // Player
} // app
