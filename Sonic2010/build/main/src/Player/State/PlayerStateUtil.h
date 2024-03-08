// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once
#include "game/GameDefs.h"
#include "Player/Base/PlayerCollision.h"
#include "Player/Base/PlayerInput.h"
#include <csl/ut/bitset.h>

namespace csl
{
namespace math
{
struct Vector3;
struct Quaternion;
struct Matrix34;
} // math
} // csl

namespace app
{
namespace game
{
struct InputStatus;
struct TouchStatus;
struct AccStatus;
struct GyroStatus;
class PathEvaluator;
class ColliShape;

// TODO: Move this to another header?
enum InputButtonID
{
    INPUT_BUTTON_JUMP = 0,
    // TODO
};
} // game

namespace xgame
{
class MsgPhantomCancel;

// TODO: Please move this to another header!
namespace MissionEventID
{
enum Type
{
    // TODO
};
} // MissionEventID
} // xgame

namespace Player
{
class CStateGOC;
struct SSurfaceInfo;

// TODO: Move this to another header?
enum STATE_ID
{
    // TODO
};

// TODO: Move this to another header?
enum EAttackType
{
    // TODO
};

// TODO: Move this to another header?
enum EActionFlag
{
    // TODO
};

namespace StateUtil
{
#ifdef LWAPI_EXPOSE_INTERNAL_LINKAGE
LWAPI(0x02a16fe0, TODO)
void GetCurrentGOCUnit(CStateGOC& goc);

LWAPI(0x02a17010, TODO)
void GetGOCUnit(CStateGOC& goc, int param_2);
#endif

LWAPI(0x02a1704c, TODO)
void ResetVelocity(CStateGOC& param_1);

LWAPI(0x02a17078, TODO)
void SetVelocity(CStateGOC& param_1, const csl::math::Vector3& param_2);

LWAPI(0x02a170ac, TODO)
void AddVelocity(CStateGOC& param_1, const csl::math::Vector3& param_2);

LWAPI(0x02a170e0, TODO)
void SetHorzVelocity(CStateGOC& param_1, const csl::math::Vector3& param_2);

LWAPI(0x02a17114, TODO)
void SetVertVelocity(CStateGOC& param_1, const csl::math::Vector3& param_2);

LWAPI(0x02a17148, TODO)
void SetPosition(CStateGOC& param_1, const csl::math::Vector3& param_2, bool param_3);

LWAPI(0x02a17224, TODO)
void ResetPosition(CStateGOC& param_1, const csl::math::Vector3& param_2, const csl::math::Quaternion& param_3);

LWAPI(0x02a17300, TODO)
void ResetPosition(CStateGOC& param_1, const csl::math::Vector3& param_2);

LWAPI(0x02a17348, TODO)
void ResetCollisionPushoutRaycastPosition(CStateGOC& param_1, const csl::math::Vector3& param_2, const csl::math::Quaternion& param_3);

LWAPI(0x02a1744c, TODO)
void SetUpDirection(CStateGOC& param_1, const csl::math::Vector3& param_2);

LWAPI(0x02a17484, TODO)
void ClearAirOnceAction(CStateGOC& param_1);

LWAPI(0x02a174b0, TODO)
void OnGround(CStateGOC& param_1);

LWAPI(0x02a174b4, TODO)
void ForceOnGround(CStateGOC& param_1);

LWAPI(0x02a174f0, TODO)
void ForceMoveToGround(CStateGOC& param_1, const csl::math::Vector3& param_2, bool param_3);

LWAPI(0x02a17664, TODO)
void RotateCollision(CStateGOC& param_1, const csl::math::Quaternion& param_2, bool param_3);

LWAPI(0x02a176ac, TODO)
void SetRotation(CStateGOC& param_1, const csl::math::Quaternion& param_2, bool param_3, bool param_4);

LWAPI(0x02a1771c, TODO)
void SetRotation(CStateGOC& param_1, const csl::math::Vector3& param_2, const csl::math::Vector3& param_3, bool param_4, bool param_5);

LWAPI(0x02a1778c, TODO)
void IsInputForceSizeLarger(CStateGOC& param_1, float param_2);

LWAPI(0x02a177dc, TODO)
void IsNoInput(CStateGOC& param_1);

LWAPI(0x02a1780c, TODO)
void SetRotateToInput(CStateGOC& param_1);

LWAPI(0x02a17894, TODO)
void DoneAirOnceAction(CStateGOC& param_1);

LWAPI(0x02a178c0, TODO)
void IsAirOnceActionEnable(const CStateGOC& param_1);

LWAPI(0x02a178ec, 0x008d6490)
void ResetOnGround(CStateGOC& goc);

LWAPI(0x02a17910, TODO)
void GetCenterPosition(CStateGOC& param_1);

LWAPI(0x02a179ec, TODO)
void GetGroundAttribute(CStateGOC& param_1);

LWAPI(0x02a17a14, TODO)
void GetGroundMaterial(CStateGOC& param_1);

LWAPI(0x02a17a3c, TODO)
void GetGroundNormal(CStateGOC& param_1);

LWAPI(0x02a17a60, TODO)
void GetGroundPosition(CStateGOC& param_1);

LWAPI(0x02a17a84, 0x008D6510)
bool IsLandOnMovableGround(CStateGOC& goc);

LWAPI(0x02a17aa8, TODO)
void GetGroundInfo(CStateGOC& param_1);

LWAPI(0x02a17acc, TODO)
void IsButtonPress(const CStateGOC& param_1, game::InputButtonID param_2);

LWAPI(0x02a17b10, TODO)
void IsButtonDown(const CStateGOC& param_1, game::InputButtonID param_2);

LWAPI(0x02a17b54, 0x008d6590)
bool IsButtonUp(const CStateGOC& goc, game::InputButtonID btnID);

LWAPI(0x02a17ba0, TODO)
void IsButtonRelease(const CStateGOC& param_1, game::InputButtonID param_2);

LWAPI(0x02a17be4, TODO)
void IsButtonPressInTime(const CStateGOC& param_1, game::InputButtonID param_2, float param_3);

LWAPI(0x02a17c48, TODO)
void GetInputStickData(const CStateGOC& param_1);

LWAPI(0x02a17cc0, TODO)
void CheckRequestJumpPrecede(const CStateGOC& param_1);

LWAPI(0x02a17cf8, TODO)
void IsButtonPressDash(CStateGOC& param_1);

LWAPI(0x02a17d14, TODO)
void IsButtonDownDash(CStateGOC& param_1);

LWAPI(0x02a17d30, TODO)
void IsButtonUpDash(CStateGOC& param_1);

LWAPI(0x02a17d4c, TODO)
void SetInputEnable(CStateGOC& param_1, bool param_2);

LWAPI(0x02a17d8c, TODO)
void StartTouchPanel(CStateGOC& param_1);

LWAPI(0x02a17d94, TODO)
void EndTouchPanel(CStateGOC& param_1);

LWAPI(0x02a17d9c, TODO)
void GetPanelInputStatus(const CStateGOC& param_1, game::InputStatus* param_2);

LWAPI(0x02a17e58, TODO)
void GetPanelTouchStatus(const CStateGOC& param_1, game::TouchStatus* param_2);

LWAPI(0x02a17ed4, TODO)
void GetPanelAccelStatus(const CStateGOC& param_1, game::AccStatus* param_2);

LWAPI(0x02a17f54, TODO)
void GetPanelGyroStatus(const CStateGOC& param_1, game::GyroStatus* param_2);

LWAPI(0x02a18000, TODO)
void CalibrateController(CStateGOC& param_1);

LWAPI(0x02a18030, TODO)
void ResetPanelDirection(CStateGOC& param_1, csl::math::Matrix34& param_2);

LWAPI(0x02a181b8, TODO)
void RefleshPanelDirection(CStateGOC& param_1, csl::math::Matrix34* param_2);

LWAPI(0x02a18498, TODO)
void SetOnAttack(CStateGOC& param_1, EAttackType param_2, bool param_3);

LWAPI(0x02a18598, TODO)
void AddAttackFlag(CStateGOC& param_1, unsigned int param_2);

LWAPI(0x02a18630, TODO)
void Enable2ndDefCollision(CStateGOC& param_1);

LWAPI(0x02a1865c, TODO)
void SetOffAttack(CStateGOC& param_1);

LWAPI(0x02a186f0, TODO)
void SetAttackType(CStateGOC& param_1, EAttackType param_2, bool param_3, unsigned int param_4);

LWAPI(0x02a18758, TODO)
void SetDisableBreakableDash(CStateGOC& param_1, bool param_2);

LWAPI(0x02a18790, TODO)
void SetDisableBreakableStomping(CStateGOC& param_1, bool param_2);

LWAPI(0x02a187c8, TODO)
void IsNowOnAttack(CStateGOC& param_1);

LWAPI(0x02a187ec, TODO)
void IsInvincible(CStateGOC& param_1);

LWAPI(0x02a18844, TODO)
void SetInvincible(CStateGOC& param_1, bool param_2);

LWAPI(0x02a188c4, TODO)
void TerminateInvincibleByItem(CStateGOC& param_1);

LWAPI(0x02a18948, TODO)
void IsBarrier(CStateGOC& param_1);

LWAPI(0x02a18994, TODO)
void ReduceBarrier(CStateGOC& param_1);

LWAPI(0x02a189d0, TODO)
void TerminateBarrierByItem(CStateGOC& param_1);

LWAPI(0x02a18a0c, TODO)
void PauseItemBarrier(CStateGOC& param_1, bool param_2);

LWAPI(0x02a18a58, TODO)
void IsHeartLife(CStateGOC& param_1);

LWAPI(0x02a18a98, TODO)
void GetPixieParameter(CStateGOC& param_1);

LWAPI(0x02a18abc, 0x008D68F0)
bool IsNowPhantom(CStateGOC& goc);

LWAPI(0x02a18aec, TODO)
void ReduceHeartLife(CStateGOC& param_1);

LWAPI(0x02a18b6c, TODO)
void RecoveryHeartLife(CStateGOC& param_1);

LWAPI(0x02a18ba4, TODO)
void AllRecoveryHeartLife(CStateGOC& param_1);

LWAPI(0x02a18bdc, TODO)
void IncrementMaxHeartLife(CStateGOC& param_1);

LWAPI(0x02a18c08, TODO)
void GetNowPhantomType(CStateGOC& param_1);

LWAPI(0x02a18c2c, TODO)
void GetStockPixieType(CStateGOC& param_1);

LWAPI(0x02a18c50, TODO)
void GetPhantomLevel(CStateGOC& param_1);

LWAPI(0x02a18c74, TODO)
void SetMaxPhantomEnergy(CStateGOC& param_1, float param_2);

LWAPI(0x02a18cb4, TODO)
void SetPhantomEnergy(CStateGOC& param_1, float param_2);

LWAPI(0x02a18cf4, TODO)
void SetPhantomEnergy(CStateGOC& param_1, float param_2, float param_3);

LWAPI(0x02a18d48, TODO)
void GetPhantomEnergy(CStateGOC& param_1);

LWAPI(0x02a18d6c, TODO)
void GetMaxPhantomEnergy(CStateGOC& param_1);

LWAPI(0x02a18d90, TODO)
void GetPhantomEnergyType(CStateGOC& param_1, Game::EPhantomType param_2);

LWAPI(0x02a18e60, TODO)
void UsePixie(CStateGOC& param_1, Game::EPhantomType param_2);

LWAPI(0x02a18ebc, TODO)
void LostPhantom(CStateGOC& param_1);

LWAPI(0x02a18ee0, TODO)
void AbortPhantom(CStateGOC& param_1, const xgame::MsgPhantomCancel& param_2);

LWAPI(0x02a18f6c, TODO)
void AbortPhantom(CStateGOC& param_1);

LWAPI(0x02a18fcc, TODO)
void IsDisableAbortPhantomForAutoRun(CStateGOC& param_1);

LWAPI(0x02a18fd4, TODO)
void LostPixie(CStateGOC& param_1, Game::EPhantomType param_2);

LWAPI(0x02a19080, TODO)
void SetWaitChangePhantom(CStateGOC& param_1, bool param_2);

LWAPI(0x02a190bc, TODO)
void IsWaitChangePhantom(CStateGOC& param_1);

LWAPI(0x02a190e8, TODO)
void SetDisableChangePhantom(CStateGOC& param_1, bool param_2);

LWAPI(0x02a19154, TODO)
void SetPhantomEndAction(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1918c, TODO)
void IsPhantomEndAction(CStateGOC& param_1);

LWAPI(0x02a191b8, TODO)
void StartOutOfControl(CStateGOC& param_1, float param_2, bool param_3);

LWAPI(0x02a191bc, TODO)
void EndOutOfControl(CStateGOC& param_1, unsigned int param_2);

LWAPI(0x02a191c0, TODO)
void IsOutOfControl(CStateGOC& param_1);

LWAPI(0x02a191c4, TODO)
void ClearOutOfControl(CStateGOC& param_1);

LWAPI(0x02a191c8, TODO)
void SearchAndSet2DPathToBottom(CStateGOC& param_1, const csl::math::Vector3& param_2, float param_3, bool param_4);

LWAPI(0x02a19390, TODO)
void SearchAndSet2DPathToBottom50M(CStateGOC& param_1, bool param_2);

LWAPI(0x02a193e0, TODO)
void GetPathBinormal(CStateGOC& param_1, csl::math::Vector3& param_2, const game::PathEvaluator& param_3);

LWAPI(0x02a19424, TODO)
void RequestChangeBodyCollision(CStateGOC& param_1, BodyCollisionType param_2);

LWAPI(0x02a19454, TODO)
void SetRingCollisionSize(CStateGOC& param_1, float param_2, const csl::math::Vector3& param_3);

LWAPI(0x02a19498, TODO)
void SetRingCollisionSizeToDefault(CStateGOC& param_1);

LWAPI(0x02a19548, TODO)
void UpdateRingCollisionSizeBySpeed(CStateGOC& param_1, float param_2);

LWAPI(0x02a195f4, TODO)
void SetBodyCollisionSizeToDefault(CStateGOC& param_1);

LWAPI(0x02a1961c, TODO)
void CreateBlowCollision(CStateGOC& param_1, unsigned int param_2, float param_3, const csl::math::Vector3& param_4, bool param_5);

LWAPI(0x02a196f8, TODO)
void DestroyBlowCollision(CStateGOC& param_1, unsigned int param_2);

LWAPI(0x02a1972c, TODO)
void CreateSphereAttackCollision(CStateGOC& param_1, unsigned int param_2, unsigned short param_3, float param_4, const csl::math::Vector3& param_5);

LWAPI(0x02a19810, TODO)
void CreateSphereDefenceCollision(CStateGOC& param_1, unsigned int param_2, unsigned short param_3, float param_4, const csl::math::Vector3& param_5);

LWAPI(0x02a198f4, TODO)
void DestroyAttackCollision(CStateGOC& param_1, unsigned int param_2);

LWAPI(0x02a19928, TODO)
void SetSphereAttackCollisionSize(CStateGOC& param_1, unsigned int param_2, float param_3);

LWAPI(0x02a199a8, TODO)
void SetSphereAttackCollisionOffset(CStateGOC& param_1, unsigned int param_2, const csl::math::Vector3& param_3);

LWAPI(0x02a19a48, TODO)
void GetSphereAttackCollisionSize(CStateGOC& param_1, unsigned int param_2);

LWAPI(0x02a19aa4, TODO)
void GetSphereAttackCollisionPosition(CStateGOC& param_1, unsigned int param_2);

LWAPI(0x02a19b38, TODO)
void IsSphereAttackCollisionEnable(CStateGOC& param_1, unsigned int param_2);

LWAPI(0x02a19b84, TODO)
void IsSphereAttackCollisionExist(CStateGOC& param_1, unsigned int param_2);

LWAPI(0x02a19bc0, TODO)
void SetSphereAttackCollisionEnable(CStateGOC& param_1, unsigned int param_2, bool param_3);

LWAPI(0x02a19c10, TODO)
void CreateAsteroidAttackCollision(CStateGOC& param_1, unsigned int param_2, unsigned short param_3, float param_4, float param_5, const csl::math::Vector3& param_6);

LWAPI(0x02a19cf0, TODO)
void SetAsteroidAttackCollisionSize(CStateGOC& param_1, unsigned int param_2, float param_3, float param_4);

LWAPI(0x02a19d70, TODO)
void SetAsteroidAttackCollisionOffset(CStateGOC& param_1, unsigned int param_2, const csl::math::Vector3& param_3, const csl::math::Quaternion& param_4);

LWAPI(0x02a19e10, TODO)
void CreateRingSearchCollision(CStateGOC& param_1, unsigned int param_2, float param_3, const csl::math::Vector3& param_4);

LWAPI(0x02a19f08, TODO)
void CreateInletCollision(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a0ac, TODO)
void DestroyInletCollision(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a0ec, TODO)
void GetCollisionSurfaceInfo(CStateGOC& param_1, ESurfaceDirection param_2);

LWAPI(0x02a1a120, TODO)
void GetCollisionSurfaceInfo(CStateGOC& param_1, unsigned int param_2);

LWAPI(0x02a1a158, TODO)
void GetCollisionSurfaceNum(CStateGOC& param_1);

LWAPI(0x02a1a180, TODO)
void GetCollisionOffsetPosition(CStateGOC& param_1);

LWAPI(0x02a1a1bc, TODO)
void SetIntegrateMoveMinimumMoveLength(CStateGOC& param_1, float param_2);

LWAPI(0x02a1a1fc, TODO)
void ResetIntegrateMoveMinimumMoveLength(CStateGOC& param_1);

LWAPI(0x02a1a224, TODO)
void GetPhysicsCollisionFilter(CStateGOC& param_1);

LWAPI(0x02a1a248, TODO)
void SetTerrainCollisionDisable(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a284, TODO)
void IsTerrainCollisionDisable(CStateGOC& param_1);

LWAPI(0x02a1a2b0, TODO)
void SetHideRC(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a31c, TODO)
void SetDead(CStateGOC& param_1);

LWAPI(0x02a1a38c, 0x008D8C10)
bool IsDead(CStateGOC& goc);

LWAPI(0x02a1a3b8, TODO)
void IsDisableTime(CStateGOC& param_1, EDisableTimer param_2);

LWAPI(0x02a1a3bc, TODO)
void IsDamaged(CStateGOC& param_1);

LWAPI(0x02a1a3c4, TODO)
void IsDrawningSand(CStateGOC& param_1);

LWAPI(0x02a1a3f0, TODO)
void IsNowBossBattle(CStateGOC& param_1);

LWAPI(0x02a1a41c, TODO)
void SetGravityDisable(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a450, TODO)
void IsGravityDisable(CStateGOC& param_1);

LWAPI(0x02a1a474, TODO)
void SetUpdateYawDisable(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a4b0, TODO)
void IsUpdateYawDisable(CStateGOC& param_1);

LWAPI(0x02a1a4dc, TODO)
void SetIgnoreFallingDeadCollision(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a518, TODO)
void SetInWater(CStateGOC& param_1);

LWAPI(0x02a1a520, TODO)
void SetInWater(CStateGOC& param_1, float param_2);

LWAPI(0x02a1a528, TODO)
void SetOutWater(CStateGOC& param_1);

LWAPI(0x02a1a530, TODO)
void IsInWater(CStateGOC& param_1);

LWAPI(0x02a1a55c, TODO)
void ChangeStateOutWater(CStateGOC& param_1);

LWAPI(0x02a1a5a0, TODO)
void RequestWaterGravityChange(CStateGOC& param_1);

LWAPI(0x02a1a5a4, TODO)
void SinkInWater(CStateGOC& param_1, unsigned int* param_2);

LWAPI(0x02a1a624, TODO)
void GetRippleInfo(CStateGOC& param_1, csl::math::Vector3* param_2, csl::math::Vector3* param_3, int* param_4);

LWAPI(0x02a1a6ac, 0x008d6b90)
bool IsEnableDoubleJump(CStateGOC& goc, bool ignoreOutOfControl);

LWAPI(0x02a1a738, TODO)
void GetLockOnPlugin(CStateGOC& param_1);

LWAPI(0x02a1a73c, 0x008d79d0)
void EnableHoming(CStateGOC& goc, bool param_2);

LWAPI(0x02a1a784, TODO)
void EnableHomingSearch(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a7bc, TODO)
void NowHoming(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a804, TODO)
void EnableSingleHomingSearch(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a84c, TODO)
void SetHomingSearchCameraDirection(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a888, TODO)
void SetHomingSearchEnableOutOfControl(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a8c4, TODO)
void ReleaseAllLockonTarget(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1a930, TODO)
void GetMultipleHomingAttackPoint(CStateGOC& param_1);

LWAPI(0x02a1a974, TODO)
void IsThisHomingAttackingTarget(CStateGOC& param_1, const game::ColliShape* param_2);

LWAPI(0x02a1a9a0, TODO)
void IsNowMultipleAttaking(CStateGOC& param_1);

LWAPI(0x02a1a9cc, TODO)
void IsEnableHomingAttack(CStateGOC& param_1);

LWAPI(0x02a1a9f8, TODO)
void ChangeStateToLandingStand(CStateGOC& param_1);

LWAPI(0x02a1aa4c, TODO)
void SetSpeedParameterFlagSpinDash(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1aa98, TODO)
void StartSpinDash(CStateGOC& param_1);

LWAPI(0x02a1aae0, TODO)
void EndSpinDash(CStateGOC& param_1);

LWAPI(0x02a1ab24, TODO)
void SetSpeedParameterFlagDash(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1ab70, TODO)
void StartDash(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1abec, TODO)
void EndDash(CStateGOC& param_1);

LWAPI(0x02a1ac50, TODO)
void IsNowAutoRun(const CStateGOC& param_1);

LWAPI(0x02a1ac7c, TODO)
void SetActionNowJumping(CStateGOC& param_1, bool param_2, bool param_3);

LWAPI(0x02a1ad14, TODO)
void SetActionNowStomping(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1ad50, TODO)
void IsNowStomping(CStateGOC& param_1);

LWAPI(0x02a1ad7c, TODO)
void SetActionFlag(CStateGOC& param_1, EActionFlag param_2, bool param_3);

LWAPI(0x02a1adc4, TODO)
void TestActionFlag(CStateGOC& param_1, EActionFlag param_2);

LWAPI(0x02a1adfc, TODO)
void SetOnLargeAreaGimmick(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1ae34, TODO)
void SetDisableTime(CStateGOC& param_1, EDisableTimer param_2, float param_3);

LWAPI(0x02a1ae3c, TODO)
void SetDisableTime(CStateGOC& param_1, EDisableTimer param_2, float param_3, unsigned int param_4);

LWAPI(0x02a1ae40, TODO)
void IsDisableTime(CStateGOC& param_1, EDisableTimer param_2, unsigned int param_3);

LWAPI(0x02a1ae44, TODO)
void SetSpeedParameterFlagBallMove(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1ae90, TODO)
void GetMaxDesiredVelocity(CStateGOC& param_1);

LWAPI(0x02a1aeb8, TODO)
void GetMaxDesiredRate(CStateGOC& param_1);

LWAPI(0x02a1aee0, TODO)
void TerminateSpeedUpByItem(CStateGOC& param_1);

LWAPI(0x02a1af1c, TODO)
void IsNowSpeedUp(CStateGOC& param_1);

LWAPI(0x02a1af44, TODO)
void IsNowSpeedDown(CStateGOC& param_1);

LWAPI(0x02a1af6c, TODO)
void CreateScatterRing(CStateGOC& param_1, bool param_2, int param_3);

LWAPI(0x02a1b0ec, TODO)
void SetRingNum(CStateGOC& param_1, int param_2, bool param_3);

LWAPI(0x02a1b134, TODO)
void LostRing(CStateGOC& param_1, int param_2);

LWAPI(0x02a1b1a0, TODO)
void ScatterRingForDamage(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1b23c, TODO)
void GetRingNum(CStateGOC& param_1);

LWAPI(0x02a1b240, TODO)
void SubRingNum(CStateGOC& param_1, int param_2, bool param_3);

LWAPI(0x02a1b288, TODO)
void ScatterRingForDamage(CStateGOC& param_1, bool param_2, int param_3);

LWAPI(0x02a1b358, 0x008D7BA0)
unsigned int AddRingNum(CStateGOC& goc, int amount, bool param_3);

LWAPI(0x02a1b44c, 0x008D70C0)
void SendMission(CStateGOC& goc, xgame::MissionEventID::Type param_2);

LWAPI(0x02a1b4c4, TODO)
void SendDeadMessage(CStateGOC& param_1);

LWAPI(0x02a1b520, TODO)
void SuspendWorld(CStateGOC& param_1);

LWAPI(0x02a1b57c, TODO)
void ResumeWorld(CStateGOC& param_1);

LWAPI(0x02a1b5c4, TODO)
void SetPositionInterpolate(CStateGOC& param_1, const csl::math::Vector3& param_2, const csl::math::Vector3& param_3, float param_4);

LWAPI(0x02a1b5c8, TODO)
void EndPositionInterpolate(CStateGOC& param_1);

LWAPI(0x02a1b5cc, TODO)
void UpdateGravityForLaunch(CStateGOC& param_1, const csl::math::Vector3& param_2);

LWAPI(0x02a1b61c, TODO)
void SetupSpecialJumpVelAndPos(CStateGOC& param_1, const csl::math::Vector3* param_2, const csl::math::Vector3* param_3, bool param_4);

LWAPI(0x02a1b774, TODO)
void DoSpringJump(CStateGOC& param_1, const csl::math::Vector3* param_2, const csl::math::Vector3* param_3, float param_4, float param_5, const csl::ut::Bitset<unsigned int>& param_6, bool param_7, bool param_8, bool param_9, float param_10, const csl::math::Vector3* param_11, float param_12);

LWAPI(0x02a1bb34, TODO)
void DoSpecialJump(CStateGOC& param_1, char const* param_2, float param_3, bool param_4, bool param_5);

LWAPI(0x02a1bb38, TODO)
void DoSpinAttackSuccess(CStateGOC& param_1);

LWAPI(0x02a1bb40, TODO)
void ChangeStateToSpinDash(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1bb94, TODO)
void ChangeToChangePathMode(CStateGOC& param_1, float param_2, bool param_3);

LWAPI(0x02a1bc24, TODO)
void ChangeRunSpeedOnLanding(CStateGOC& param_1, float param_2);

LWAPI(0x02a1beb4, TODO)
void SetCameraUpdatedFromProxy(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1beec, TODO)
void SetAvoidWallFlag(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1bf24, TODO)
void SetHomingAttackFlag(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1bf5c, TODO)
void SetSingleHomingAttackFlag(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1bfb0, TODO)
void SetSquatFlag(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1bfec, TODO)
void IsNowSquat(CStateGOC& param_1);

LWAPI(0x02a1c018, TODO)
void SendNextStateToDontChangeAnim(CStateGOC& param_1);

LWAPI(0x02a1c048, TODO)
void RecieveRequestDontChangeAnim(CStateGOC& param_1, bool* param_2);

LWAPI(0x02a1c084, TODO)
void SendNextStateToEnableDoubleJump(CStateGOC& param_1);

LWAPI(0x02a1c0b4, TODO)
void RecieveRequestEnableDoubleJump(CStateGOC& param_1, bool* param_2);

LWAPI(0x02a1c0f0, TODO)
void SendNextStateToContinueRunAnimation(CStateGOC& param_1);

LWAPI(0x02a1c120, TODO)
void RecieveRequestContinueRunAnimation(CStateGOC& param_1, bool* param_2);

LWAPI(0x02a1c15c, TODO)
void SendNextStateToWaiteInterpolate(CStateGOC& param_1);

LWAPI(0x02a1c18c, TODO)
void RecieveRequestWaitInterpolate(CStateGOC& param_1, bool* param_2);

LWAPI(0x02a1c1c8, TODO)
void SendNextStateToEndGrind(CStateGOC& param_1);

LWAPI(0x02a1c1f8, TODO)
void RecieveRequestEndGrind(CStateGOC& param_1, bool* param_2);

LWAPI(0x02a1c234, TODO)
void SendNextStateToSeachSingleHoming(CStateGOC& param_1);

LWAPI(0x02a1c264, TODO)
void RecieveRequestSearchSingleHoming(CStateGOC& param_1, bool* param_2);

LWAPI(0x02a1c2a0, TODO)
void SendNextStateToHeadToVelocity(CStateGOC& param_1);

LWAPI(0x02a1c2d0, TODO)
void RecieveRequestHeadToVelocity(CStateGOC& param_1, bool* param_2);

LWAPI(0x02a1c30c, TODO)
void SendNextStateToNotVisible(CStateGOC& param_1);

LWAPI(0x02a1c33c, TODO)
void RecieveRequestNotVisible(CStateGOC& param_1, bool* param_2);

LWAPI(0x02a1c378, TODO)
void SendNextStateToJumpAfterSpinDash(CStateGOC& param_1);

LWAPI(0x02a1c3a8, TODO)
void RecieveRequestJumpAfterSpinDash(CStateGOC& param_1, bool* param_2);

LWAPI(0x02a1c3e4, TODO)
void GetPlaneTornado(CStateGOC& param_1);

LWAPI(0x02a1c434, TODO)
void TryRidePlane(CStateGOC& param_1);

LWAPI(0x02a1c4fc, TODO)
void SetPlaneFall(CStateGOC& param_1);

LWAPI(0x02a1c54c, TODO)
void GetSnowBall(CStateGOC& param_1);

LWAPI(0x02a1c59c, TODO)
void TestSnowBall(CStateGOC& param_1);

LWAPI(0x02a1c6e4, TODO)
void RemoveSnowBall(CStateGOC& param_1);

LWAPI(0x02a1c734, TODO)
void SyncSnowBallPosition(CStateGOC& param_1);

LWAPI(0x02a1c844, TODO)
void CannotDashAndSpindash(CStateGOC& param_1);

LWAPI(0x02a1c8d0, TODO)
void CheckSlopeEnableSpindash(CStateGOC& param_1);

LWAPI(0x02a1c9f4, TODO)
void CheckChangeIceRun(CStateGOC& param_1);

LWAPI(0x02a1ca50, TODO)
void CheckSpinDashOnWater(CStateGOC& param_1, float param_2);

LWAPI(0x02a1ccb0, TODO)
bool CheckChangeToHomingAction(CStateGOC& param_1, STATE_ID* param_2);

LWAPI(0x02a1ce18, TODO)
void CheckChangeToSingleHomingAction(CStateGOC& param_1, STATE_ID* param_2);

LWAPI(0x02a1cf74, TODO)
void SetFallFromParkour(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1cfac, TODO)
void IsFallFromParkour(CStateGOC& param_1);

LWAPI(0x02a1cfd8, TODO)
void IsNowOnFallingSlope(CStateGOC& param_1);

LWAPI(0x02a1d0fc, TODO)
void CheckChangeToFallSlope(CStateGOC& param_1, SSurfaceInfo* param_2);

LWAPI(0x02a1d2b0, TODO)
void IsNowOnFallingSlopeAndZeroSpeed(CStateGOC& param_1);

LWAPI(0x02a1d35c, TODO)
void IsNowOnSlideSpindashGround(CStateGOC& param_1);

LWAPI(0x02a1d48c, TODO)
void CheckChangeToIceRunOnSlidingFloor(CStateGOC& param_1);

LWAPI(0x02a1d650, TODO)
void IgnoreCheckDeadOnCylinderInside(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1d68c, TODO)
void SetLocalScale(CStateGOC& param_1, const csl::math::Vector3& param_2);

LWAPI(0x02a1d6d0, TODO)
void SetLocalScale(CStateGOC& param_1, int param_2, const csl::math::Vector3& param_3);

LWAPI(0x02a1d714, TODO)
void IsLeft(CStateGOC& param_1);

LWAPI(0x02a1d79c, TODO)
void IsLeft(CStateGOC& param_1, const csl::math::Vector3& param_2);

LWAPI(0x02a1d820, TODO)
void IsVisible(CStateGOC& param_1);

LWAPI(0x02a1d85c, TODO)
void SetVisible(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1d890, TODO)
void SetVisible(CStateGOC& param_1, int param_2, bool param_3);

LWAPI(0x02a1d8c4, TODO)
void SetZOffset(CStateGOC& param_1, float param_2);

LWAPI(0x02a1d918, TODO)
void SetStealth(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1d990, TODO)
void IsStealth(CStateGOC& param_1);

LWAPI(0x02a1d9bc, TODO)
void TakePhantomPixie(CStateGOC& param_1, Game::EPhantomType param_2, int param_3);

LWAPI(0x02a1da28, TODO)
void StartPhantomInfo(CStateGOC& param_1);

LWAPI(0x02a1daa4, TODO)
void EndPhantomInfo(CStateGOC& param_1);

LWAPI(0x02a1dafc, TODO)
void StartPhantomGauge(CStateGOC& param_1);

LWAPI(0x02a1db54, TODO)
void SetHoverDashInformation(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1dbb4, TODO)
void SetParkourInformation(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1dc14, TODO)
void SetBarrierEffectOffset(CStateGOC& param_1, const csl::math::Vector3* param_2, const csl::math::Quaternion* param_3);

LWAPI(0x02a1dc90, TODO)
void SetBarrierEffectOffset(CStateGOC& param_1, const csl::math::Vector3* param_2, const csl::math::Quaternion* param_3, const csl::math::Vector3* param_4, const csl::math::Quaternion* param_5);

LWAPI(0x02a1dd04, TODO)
void ResetBarrierEffectOffset(CStateGOC& param_1);

LWAPI(0x02a1ddd8, TODO)
void SetBarrierEffectToModel(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1de40, TODO)
void SendMission(CStateGOC& param_1, xgame::MissionEventID::Type param_2, int param_3);

LWAPI(0x02a1deb8, TODO)
void SendMissionGetRing(CStateGOC& param_1, int param_2);

LWAPI(0x02a1df90, TODO)
void CalcRunningAnimationBlendWeight(CStateGOC& param_1, float param_2, float param_3, float param_4, float param_5, float param_6);

LWAPI(0x02a1e290, TODO)
void IsBattleMode(CStateGOC& param_1);

LWAPI(0x02a1e2c4, TODO)
void SetRCLockCombineAbility(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1e400, TODO)
void SetRCLockHoverAbility(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1e53c, TODO)
void SetRCLockAbility(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1e66c, TODO)
void IsDisableRCHoverAbility(CStateGOC& param_1);

LWAPI(0x02a1e6a8, TODO)
void SetItemDisableSpeedUp(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1e710, TODO)
void SetItemDisableBarrier(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1e778, TODO)
void SetItemDisableBarrierSpeedInvincible(CStateGOC& param_1, bool param_2, bool param_3);

LWAPI(0x02a1e824, TODO)
void SetItemDisableWarp(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1e864, TODO)
void SetDisableItemAndTransformForPauseAct(CStateGOC& param_1, bool param_2, bool param_3);

LWAPI(0x02a1e8dc, TODO)
void SetItemDisableItemBagRing(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1e91c, TODO)
void GetTransformNDC(CStateGOC& param_1, csl::math::Vector3& param_2);

LWAPI(0x02a1e9d8, TODO)
void SetDisableSandHole(CStateGOC& param_1, bool param_2);

LWAPI(0x02a1ea1c, TODO)
void SetBodyRadius(CStateGOC& param_1, float param_2);

LWAPI(0x02a1ea60, TODO)
void ResetBodyRadius(CStateGOC& param_1);

LWAPI(0x02a1ea90, TODO)
void SetDisableItemBag(CStateGOC& param_1, bool param_2);
} // StateUtil
} // Player
} // app
