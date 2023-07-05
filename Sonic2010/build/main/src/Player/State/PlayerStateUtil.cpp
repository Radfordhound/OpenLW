#include "OpenLW/pch.h"
#include "PlayerStateUtil.h"

namespace app
{
namespace Player
{
namespace StateUtil
{
#ifndef LWAPI_EXPOSE_INTERNAL_LINKAGE
namespace
{
#endif
void GetCurrentGOCUnit(CStateGOC& goc)
{
    // TODO
}

void GetGOCUnit(CStateGOC& goc, int param_2)
{
    // TODO
}
#ifndef LWAPI_EXPOSE_INTERNAL_LINKAGE
} // <unnamed>
#endif

void ResetVelocity(CStateGOC& param_1)
{
    // TODO
}

void SetVelocity(CStateGOC& param_1, const csl::math::Vector3& param_2)
{
    // TODO
}

void AddVelocity(CStateGOC& param_1, const csl::math::Vector3& param_2)
{
    // TODO
}

void SetHorzVelocity(CStateGOC& param_1, const csl::math::Vector3& param_2)
{
    // TODO
}

void SetVertVelocity(CStateGOC& param_1, const csl::math::Vector3& param_2)
{
    // TODO
}

void SetPosition(CStateGOC& param_1, const csl::math::Vector3& param_2, bool param_3)
{
    // TODO
}

void ResetPosition(CStateGOC& param_1, const csl::math::Vector3& param_2, const csl::math::Quaternion& param_3)
{
    // TODO
}

void ResetPosition(CStateGOC& param_1, const csl::math::Vector3& param_2)
{
    // TODO
}

void ResetCollisionPushoutRaycastPosition(CStateGOC& param_1, const csl::math::Vector3& param_2, const csl::math::Quaternion& param_3)
{
    // TODO
}

void SetUpDirection(CStateGOC& param_1, const csl::math::Vector3& param_2)
{
    // TODO
}

void ClearAirOnceAction(CStateGOC& param_1)
{
    // TODO
}

void OnGround(CStateGOC& param_1)
{
    // TODO
}

void ForceOnGround(CStateGOC& param_1)
{
    // TODO
}

void ForceMoveToGround(CStateGOC& param_1, const csl::math::Vector3& param_2, bool param_3)
{
    // TODO
}

void RotateCollision(CStateGOC& param_1, const csl::math::Quaternion& param_2, bool param_3)
{
    // TODO
}

void SetRotation(CStateGOC& param_1, const csl::math::Quaternion& param_2, bool param_3, bool param_4)
{
    // TODO
}

void SetRotation(CStateGOC& param_1, const csl::math::Vector3& param_2, const csl::math::Vector3& param_3, bool param_4, bool param_5)
{
    // TODO
}

void IsInputForceSizeLarger(CStateGOC& param_1, float param_2)
{
    // TODO
}

void IsNoInput(CStateGOC& param_1)
{
    // TODO
}

void SetRotateToInput(CStateGOC& param_1)
{
    // TODO
}

void DoneAirOnceAction(CStateGOC& param_1)
{
    // TODO
}

void IsAirOnceActionEnable(const CStateGOC& param_1)
{
    // TODO
}

void ResetOnGround(CStateGOC& param_1)
{
    // TODO
}

void GetCenterPosition(CStateGOC& param_1)
{
    // TODO
}

void GetGroundAttribute(CStateGOC& param_1)
{
    // TODO
}

void GetGroundMaterial(CStateGOC& param_1)
{
    // TODO
}

void GetGroundNormal(CStateGOC& param_1)
{
    // TODO
}

void GetGroundPosition(CStateGOC& param_1)
{
    // TODO
}

bool IsLandOnMovableGround(CStateGOC& goc)
{
    // TODO
    return false;
}

void GetGroundInfo(CStateGOC& param_1)
{
    // TODO
}

void IsButtonPress(const CStateGOC& param_1, game::InputButtonID param_2)
{
    // TODO
}

void IsButtonDown(const CStateGOC& param_1, game::InputButtonID param_2)
{
    // TODO
}

bool IsButtonUp(const CStateGOC& param_1, game::InputButtonID param_2)
{
    // TODO
    return false;
}

void IsButtonRelease(const CStateGOC& param_1, game::InputButtonID param_2)
{
    // TODO
}

void IsButtonPressInTime(const CStateGOC& param_1, game::InputButtonID param_2, float param_3)
{
    // TODO
}

void GetInputStickData(const CStateGOC& param_1)
{
    // TODO
}

void CheckRequestJumpPrecede(const CStateGOC& param_1)
{
    // TODO
}

void IsButtonPressDash(CStateGOC& param_1)
{
    // TODO
}

void IsButtonDownDash(CStateGOC& param_1)
{
    // TODO
}

void IsButtonUpDash(CStateGOC& param_1)
{
    // TODO
}

void SetInputEnable(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void StartTouchPanel(CStateGOC& param_1)
{
    // TODO
}

void EndTouchPanel(CStateGOC& param_1)
{
    // TODO
}

void GetPanelInputStatus(const CStateGOC& param_1, game::InputStatus* param_2)
{
    // TODO
}

void GetPanelTouchStatus(const CStateGOC& param_1, game::TouchStatus* param_2)
{
    // TODO
}

void GetPanelAccelStatus(const CStateGOC& param_1, game::AccStatus* param_2)
{
    // TODO
}

void GetPanelGyroStatus(const CStateGOC& param_1, game::GyroStatus* param_2)
{
    // TODO
}

void CalibrateController(CStateGOC& param_1)
{
    // TODO
}

void ResetPanelDirection(CStateGOC& param_1, csl::math::Matrix34& param_2)
{
    // TODO
}

void RefleshPanelDirection(CStateGOC& param_1, csl::math::Matrix34* param_2)
{
    // TODO
}

void SetOnAttack(CStateGOC& param_1, EAttackType param_2, bool param_3)
{
    // TODO
}

void AddAttackFlag(CStateGOC& param_1, unsigned int param_2)
{
    // TODO
}

void Enable2ndDefCollision(CStateGOC& param_1)
{
    // TODO
}

void SetOffAttack(CStateGOC& param_1)
{
    // TODO
}

void SetAttackType(CStateGOC& param_1, EAttackType param_2, bool param_3, unsigned int param_4)
{
    // TODO
}

void SetDisableBreakableDash(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetDisableBreakableStomping(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void IsNowOnAttack(CStateGOC& param_1)
{
    // TODO
}

void IsInvincible(CStateGOC& param_1)
{
    // TODO
}

void SetInvincible(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void TerminateInvincibleByItem(CStateGOC& param_1)
{
    // TODO
}

void IsBarrier(CStateGOC& param_1)
{
    // TODO
}

void ReduceBarrier(CStateGOC& param_1)
{
    // TODO
}

void TerminateBarrierByItem(CStateGOC& param_1)
{
    // TODO
}

void PauseItemBarrier(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void IsHeartLife(CStateGOC& param_1)
{
    // TODO
}

void GetPixieParameter(CStateGOC& param_1)
{
    // TODO
}

bool IsNowPhantom(CStateGOC& goc)
{
    // TODO
    return false;
}

void ReduceHeartLife(CStateGOC& param_1)
{
    // TODO
}

void RecoveryHeartLife(CStateGOC& param_1)
{
    // TODO
}

void AllRecoveryHeartLife(CStateGOC& param_1)
{
    // TODO
}

void IncrementMaxHeartLife(CStateGOC& param_1)
{
    // TODO
}

void GetNowPhantomType(CStateGOC& param_1)
{
    // TODO
}

void GetStockPixieType(CStateGOC& param_1)
{
    // TODO
}

void GetPhantomLevel(CStateGOC& param_1)
{
    // TODO
}

void SetMaxPhantomEnergy(CStateGOC& param_1, float param_2)
{
    // TODO
}

void SetPhantomEnergy(CStateGOC& param_1, float param_2)
{
    // TODO
}

void SetPhantomEnergy(CStateGOC& param_1, float param_2, float param_3)
{
    // TODO
}

void GetPhantomEnergy(CStateGOC& param_1)
{
    // TODO
}

void GetMaxPhantomEnergy(CStateGOC& param_1)
{
    // TODO
}

void GetPhantomEnergyType(CStateGOC& param_1, Game::EPhantomType param_2)
{
    // TODO
}

void UsePixie(CStateGOC& param_1, Game::EPhantomType param_2)
{
    // TODO
}

void LostPhantom(CStateGOC& param_1)
{
    // TODO
}

void AbortPhantom(CStateGOC& param_1, const xgame::MsgPhantomCancel& param_2)
{
    // TODO
}

void AbortPhantom(CStateGOC& param_1)
{
    // TODO
}

void IsDisableAbortPhantomForAutoRun(CStateGOC& param_1)
{
    // TODO
}

void LostPixie(CStateGOC& param_1, Game::EPhantomType param_2)
{
    // TODO
}

void SetWaitChangePhantom(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void IsWaitChangePhantom(CStateGOC& param_1)
{
    // TODO
}

void SetDisableChangePhantom(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetPhantomEndAction(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void IsPhantomEndAction(CStateGOC& param_1)
{
    // TODO
}

void StartOutOfControl(CStateGOC& param_1, float param_2, bool param_3)
{
    // TODO
}

void EndOutOfControl(CStateGOC& param_1, unsigned int param_2)
{
    // TODO
}

void IsOutOfControl(CStateGOC& param_1)
{
    // TODO
}

void ClearOutOfControl(CStateGOC& param_1)
{
    // TODO
}

void SearchAndSet2DPathToBottom(CStateGOC& param_1, const csl::math::Vector3& param_2, float param_3, bool param_4)
{
    // TODO
}

void SearchAndSet2DPathToBottom50M(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void GetPathBinormal(CStateGOC& param_1, csl::math::Vector3& param_2, const game::PathEvaluator& param_3)
{
    // TODO
}

void RequestChangeBodyCollision(CStateGOC& param_1, BodyCollisionType param_2)
{
    // TODO
}

void SetRingCollisionSize(CStateGOC& param_1, float param_2, const csl::math::Vector3& param_3)
{
    // TODO
}

void SetRingCollisionSizeToDefault(CStateGOC& param_1)
{
    // TODO
}

void UpdateRingCollisionSizeBySpeed(CStateGOC& param_1, float param_2)
{
    // TODO
}

void SetBodyCollisionSizeToDefault(CStateGOC& param_1)
{
    // TODO
}

void CreateBlowCollision(CStateGOC& param_1, unsigned int param_2, float param_3, const csl::math::Vector3& param_4, bool param_5)
{
    // TODO
}

void DestroyBlowCollision(CStateGOC& param_1, unsigned int param_2)
{
    // TODO
}

void CreateSphereAttackCollision(CStateGOC& param_1, unsigned int param_2, unsigned short param_3, float param_4, const csl::math::Vector3& param_5)
{
    // TODO
}

void CreateSphereDefenceCollision(CStateGOC& param_1, unsigned int param_2, unsigned short param_3, float param_4, const csl::math::Vector3& param_5)
{
    // TODO
}

void DestroyAttackCollision(CStateGOC& param_1, unsigned int param_2)
{
    // TODO
}

void SetSphereAttackCollisionSize(CStateGOC& param_1, unsigned int param_2, float param_3)
{
    // TODO
}

void SetSphereAttackCollisionOffset(CStateGOC& param_1, unsigned int param_2, const csl::math::Vector3& param_3)
{
    // TODO
}

void GetSphereAttackCollisionSize(CStateGOC& param_1, unsigned int param_2)
{
    // TODO
}

void GetSphereAttackCollisionPosition(CStateGOC& param_1, unsigned int param_2)
{
    // TODO
}

void IsSphereAttackCollisionEnable(CStateGOC& param_1, unsigned int param_2)
{
    // TODO
}

void IsSphereAttackCollisionExist(CStateGOC& param_1, unsigned int param_2)
{
    // TODO
}

void SetSphereAttackCollisionEnable(CStateGOC& param_1, unsigned int param_2, bool param_3)
{
    // TODO
}

void CreateAsteroidAttackCollision(CStateGOC& param_1, unsigned int param_2, unsigned short param_3, float param_4, float param_5, const csl::math::Vector3& param_6)
{
    // TODO
}

void SetAsteroidAttackCollisionSize(CStateGOC& param_1, unsigned int param_2, float param_3, float param_4)
{
    // TODO
}

void SetAsteroidAttackCollisionOffset(CStateGOC& param_1, unsigned int param_2, const csl::math::Vector3& param_3, const csl::math::Quaternion& param_4)
{
    // TODO
}

void CreateRingSearchCollision(CStateGOC& param_1, unsigned int param_2, float param_3, const csl::math::Vector3& param_4)
{
    // TODO
}

void CreateInletCollision(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void DestroyInletCollision(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void GetCollisionSurfaceInfo(CStateGOC& param_1, ESurfaceDirection param_2)
{
    // TODO
}

void GetCollisionSurfaceInfo(CStateGOC& param_1, unsigned int param_2)
{
    // TODO
}

void GetCollisionSurfaceNum(CStateGOC& param_1)
{
    // TODO
}

void GetCollisionOffsetPosition(CStateGOC& param_1)
{
    // TODO
}

void SetIntegrateMoveMinimumMoveLength(CStateGOC& param_1, float param_2)
{
    // TODO
}

void ResetIntegrateMoveMinimumMoveLength(CStateGOC& param_1)
{
    // TODO
}

void GetPhysicsCollisionFilter(CStateGOC& param_1)
{
    // TODO
}

void SetTerrainCollisionDisable(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void IsTerrainCollisionDisable(CStateGOC& param_1)
{
    // TODO
}

void SetHideRC(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetDead(CStateGOC& param_1)
{
    // TODO
}

bool IsDead(CStateGOC& goc)
{
    // TODO
    return false;
}

void IsDisableTime(CStateGOC& param_1, EDisableTimer param_2)
{
    // TODO
}

void IsDamaged(CStateGOC& param_1)
{
    // TODO
}

void IsDrawningSand(CStateGOC& param_1)
{
    // TODO
}

void IsNowBossBattle(CStateGOC& param_1)
{
    // TODO
}

void SetGravityDisable(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void IsGravityDisable(CStateGOC& param_1)
{
    // TODO
}

void SetUpdateYawDisable(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void IsUpdateYawDisable(CStateGOC& param_1)
{
    // TODO
}

void SetIgnoreFallingDeadCollision(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetInWater(CStateGOC& param_1)
{
    // TODO
}

void SetInWater(CStateGOC& param_1, float param_2)
{
    // TODO
}

void SetOutWater(CStateGOC& param_1)
{
    // TODO
}

void IsInWater(CStateGOC& param_1)
{
    // TODO
}

void ChangeStateOutWater(CStateGOC& param_1)
{
    // TODO
}

void RequestWaterGravityChange(CStateGOC& param_1)
{
    // TODO
}

void SinkInWater(CStateGOC& param_1, unsigned int* param_2)
{
    // TODO
}

void GetRippleInfo(CStateGOC& param_1, csl::math::Vector3* param_2, csl::math::Vector3* param_3, int* param_4)
{
    // TODO
}

void IsEnableDoubleJump(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void GetLockOnPlugin(CStateGOC& param_1)
{
    // TODO
}

void EnableHoming(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void EnableHomingSearch(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void NowHoming(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void EnableSingleHomingSearch(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetHomingSearchCameraDirection(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetHomingSearchEnableOutOfControl(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void ReleaseAllLockonTarget(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void GetMultipleHomingAttackPoint(CStateGOC& param_1)
{
    // TODO
}

void IsThisHomingAttackingTarget(CStateGOC& param_1, const game::ColliShape* param_2)
{
    // TODO
}

void IsNowMultipleAttaking(CStateGOC& param_1)
{
    // TODO
}

void IsEnableHomingAttack(CStateGOC& param_1)
{
    // TODO
}

void ChangeStateToLandingStand(CStateGOC& param_1)
{
    // TODO
}

void SetSpeedParameterFlagSpinDash(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void StartSpinDash(CStateGOC& param_1)
{
    // TODO
}

void EndSpinDash(CStateGOC& param_1)
{
    // TODO
}

void SetSpeedParameterFlagDash(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void StartDash(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void EndDash(CStateGOC& param_1)
{
    // TODO
}

void IsNowAutoRun(const CStateGOC& param_1)
{
    // TODO
}

void SetActionNowJumping(CStateGOC& param_1, bool param_2, bool param_3)
{
    // TODO
}

void SetActionNowStomping(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void IsNowStomping(CStateGOC& param_1)
{
    // TODO
}

void SetActionFlag(CStateGOC& param_1, EActionFlag param_2, bool param_3)
{
    // TODO
}

void TestActionFlag(CStateGOC& param_1, EActionFlag param_2)
{
    // TODO
}

void SetOnLargeAreaGimmick(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetDisableTime(CStateGOC& param_1, EDisableTimer param_2, float param_3)
{
    // TODO
}

void SetDisableTime(CStateGOC& param_1, EDisableTimer param_2, float param_3, unsigned int param_4)
{
    // TODO
}

void IsDisableTime(CStateGOC& param_1, EDisableTimer param_2, unsigned int param_3)
{
    // TODO
}

void SetSpeedParameterFlagBallMove(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void GetMaxDesiredVelocity(CStateGOC& param_1)
{
    // TODO
}

void GetMaxDesiredRate(CStateGOC& param_1)
{
    // TODO
}

void TerminateSpeedUpByItem(CStateGOC& param_1)
{
    // TODO
}

void IsNowSpeedUp(CStateGOC& param_1)
{
    // TODO
}

void IsNowSpeedDown(CStateGOC& param_1)
{
    // TODO
}

void CreateScatterRing(CStateGOC& param_1, bool param_2, int param_3)
{
    // TODO
}

void SetRingNum(CStateGOC& param_1, int param_2, bool param_3)
{
    // TODO
}

void LostRing(CStateGOC& param_1, int param_2)
{
    // TODO
}

void ScatterRingForDamage(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void GetRingNum(CStateGOC& param_1)
{
    // TODO
}

void SubRingNum(CStateGOC& param_1, int param_2, bool param_3)
{
    // TODO
}

void ScatterRingForDamage(CStateGOC& param_1, bool param_2, int param_3)
{
    // TODO
}

unsigned int AddRingNum(CStateGOC& goc, int amount, bool param_3)
{
    // TODO
    return 0;
}

void SendMission(CStateGOC& goc, xgame::MissionEventID::Type param_2)
{
    // TODO
}

void SendDeadMessage(CStateGOC& param_1)
{
    // TODO
}

void SuspendWorld(CStateGOC& param_1)
{
    // TODO
}

void ResumeWorld(CStateGOC& param_1)
{
    // TODO
}

void SetPositionInterpolate(CStateGOC& param_1, const csl::math::Vector3& param_2, const csl::math::Vector3& param_3, float param_4)
{
    // TODO
}

void EndPositionInterpolate(CStateGOC& param_1)
{
    // TODO
}

void UpdateGravityForLaunch(CStateGOC& param_1, const csl::math::Vector3& param_2)
{
    // TODO
}

void SetupSpecialJumpVelAndPos(CStateGOC& param_1, const csl::math::Vector3* param_2, const csl::math::Vector3* param_3, bool param_4)
{
    // TODO
}

void DoSpringJump(CStateGOC& param_1, const csl::math::Vector3* param_2, const csl::math::Vector3* param_3, float param_4, float param_5, const csl::ut::Bitset<unsigned int>& param_6, bool param_7, bool param_8, bool param_9, float param_10, const csl::math::Vector3* param_11, float param_12)
{
    // TODO
}

void DoSpecialJump(CStateGOC& param_1, char const* param_2, float param_3, bool param_4, bool param_5)
{
    // TODO
}

void DoSpinAttackSuccess(CStateGOC& param_1)
{
    // TODO
}

void ChangeStateToSpinDash(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void ChangeToChangePathMode(CStateGOC& param_1, float param_2, bool param_3)
{
    // TODO
}

void ChangeRunSpeedOnLanding(CStateGOC& param_1, float param_2)
{
    // TODO
}

void SetCameraUpdatedFromProxy(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetAvoidWallFlag(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetHomingAttackFlag(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetSingleHomingAttackFlag(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetSquatFlag(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void IsNowSquat(CStateGOC& param_1)
{
    // TODO
}

void SendNextStateToDontChangeAnim(CStateGOC& param_1)
{
    // TODO
}

void RecieveRequestDontChangeAnim(CStateGOC& param_1, bool* param_2)
{
    // TODO
}

void SendNextStateToEnableDoubleJump(CStateGOC& param_1)
{
    // TODO
}

void RecieveRequestEnableDoubleJump(CStateGOC& param_1, bool* param_2)
{
    // TODO
}

void SendNextStateToContinueRunAnimation(CStateGOC& param_1)
{
    // TODO
}

void RecieveRequestContinueRunAnimation(CStateGOC& param_1, bool* param_2)
{
    // TODO
}

void SendNextStateToWaiteInterpolate(CStateGOC& param_1)
{
    // TODO
}

void RecieveRequestWaitInterpolate(CStateGOC& param_1, bool* param_2)
{
    // TODO
}

void SendNextStateToEndGrind(CStateGOC& param_1)
{
    // TODO
}

void RecieveRequestEndGrind(CStateGOC& param_1, bool* param_2)
{
    // TODO
}

void SendNextStateToSeachSingleHoming(CStateGOC& param_1)
{
    // TODO
}

void RecieveRequestSearchSingleHoming(CStateGOC& param_1, bool* param_2)
{
    // TODO
}

void SendNextStateToHeadToVelocity(CStateGOC& param_1)
{
    // TODO
}

void RecieveRequestHeadToVelocity(CStateGOC& param_1, bool* param_2)
{
    // TODO
}

void SendNextStateToNotVisible(CStateGOC& param_1)
{
    // TODO
}

void RecieveRequestNotVisible(CStateGOC& param_1, bool* param_2)
{
    // TODO
}

void SendNextStateToJumpAfterSpinDash(CStateGOC& param_1)
{
    // TODO
}

void RecieveRequestJumpAfterSpinDash(CStateGOC& param_1, bool* param_2)
{
    // TODO
}

void GetPlaneTornado(CStateGOC& param_1)
{
    // TODO
}

void TryRidePlane(CStateGOC& param_1)
{
    // TODO
}

void SetPlaneFall(CStateGOC& param_1)
{
    // TODO
}

void GetSnowBall(CStateGOC& param_1)
{
    // TODO
}

void TestSnowBall(CStateGOC& param_1)
{
    // TODO
}

void RemoveSnowBall(CStateGOC& param_1)
{
    // TODO
}

void SyncSnowBallPosition(CStateGOC& param_1)
{
    // TODO
}

void CannotDashAndSpindash(CStateGOC& param_1)
{
    // TODO
}

void CheckSlopeEnableSpindash(CStateGOC& param_1)
{
    // TODO
}

void CheckChangeIceRun(CStateGOC& param_1)
{
    // TODO
}

void CheckSpinDashOnWater(CStateGOC& param_1, float param_2)
{
    // TODO
}

bool CheckChangeToHomingAction(CStateGOC& param_1, STATE_ID* param_2)
{
    // TODO
    return false;
}

void CheckChangeToSingleHomingAction(CStateGOC& param_1, STATE_ID* param_2)
{
    // TODO
}

void SetFallFromParkour(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void IsFallFromParkour(CStateGOC& param_1)
{
    // TODO
}

void IsNowOnFallingSlope(CStateGOC& param_1)
{
    // TODO
}

void CheckChangeToFallSlope(CStateGOC& param_1, SSurfaceInfo* param_2)
{
    // TODO
}

void IsNowOnFallingSlopeAndZeroSpeed(CStateGOC& param_1)
{
    // TODO
}

void IsNowOnSlideSpindashGround(CStateGOC& param_1)
{
    // TODO
}

void CheckChangeToIceRunOnSlidingFloor(CStateGOC& param_1)
{
    // TODO
}

void IgnoreCheckDeadOnCylinderInside(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetLocalScale(CStateGOC& param_1, const csl::math::Vector3& param_2)
{
    // TODO
}

void SetLocalScale(CStateGOC& param_1, int param_2, const csl::math::Vector3& param_3)
{
    // TODO
}

void IsLeft(CStateGOC& param_1)
{
    // TODO
}

void IsLeft(CStateGOC& param_1, const csl::math::Vector3& param_2)
{
    // TODO
}

void IsVisible(CStateGOC& param_1)
{
    // TODO
}

void SetVisible(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetVisible(CStateGOC& param_1, int param_2, bool param_3)
{
    // TODO
}

void SetZOffset(CStateGOC& param_1, float param_2)
{
    // TODO
}

void SetStealth(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void IsStealth(CStateGOC& param_1)
{
    // TODO
}

void TakePhantomPixie(CStateGOC& param_1, Game::EPhantomType param_2, int param_3)
{
    // TODO
}

void StartPhantomInfo(CStateGOC& param_1)
{
    // TODO
}

void EndPhantomInfo(CStateGOC& param_1)
{
    // TODO
}

void StartPhantomGauge(CStateGOC& param_1)
{
    // TODO
}

void SetHoverDashInformation(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetParkourInformation(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetBarrierEffectOffset(CStateGOC& param_1, const csl::math::Vector3* param_2, const csl::math::Quaternion* param_3)
{
    // TODO
}

void SetBarrierEffectOffset(CStateGOC& param_1, const csl::math::Vector3* param_2, const csl::math::Quaternion* param_3, const csl::math::Vector3* param_4, const csl::math::Quaternion* param_5)
{
    // TODO
}

void ResetBarrierEffectOffset(CStateGOC& param_1)
{
    // TODO
}

void SetBarrierEffectToModel(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SendMission(CStateGOC& param_1, xgame::MissionEventID::Type param_2, int param_3)
{
    // TODO
}

void SendMissionGetRing(CStateGOC& param_1, int param_2)
{
    // TODO
}

void CalcRunningAnimationBlendWeight(CStateGOC& param_1, float param_2, float param_3, float param_4, float param_5, float param_6)
{
    // TODO
}

void IsBattleMode(CStateGOC& param_1)
{
    // TODO
}

void SetRCLockCombineAbility(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetRCLockHoverAbility(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetRCLockAbility(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void IsDisableRCHoverAbility(CStateGOC& param_1)
{
    // TODO
}

void SetItemDisableSpeedUp(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetItemDisableBarrier(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetItemDisableBarrierSpeedInvincible(CStateGOC& param_1, bool param_2, bool param_3)
{
    // TODO
}

void SetItemDisableWarp(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetDisableItemAndTransformForPauseAct(CStateGOC& param_1, bool param_2, bool param_3)
{
    // TODO
}

void SetItemDisableItemBagRing(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void GetTransformNDC(CStateGOC& param_1, csl::math::Vector3& param_2)
{
    // TODO
}

void SetDisableSandHole(CStateGOC& param_1, bool param_2)
{
    // TODO
}

void SetBodyRadius(CStateGOC& param_1, float param_2)
{
    // TODO
}

void ResetBodyRadius(CStateGOC& param_1)
{
    // TODO
}

void SetDisableItemBag(CStateGOC& param_1, bool param_2)
{
    // TODO
}
} // StateUtil
} // Player
} // app
