// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once
#include "game/GameDefs.h"
#include "Player/Base/PlayerState.h"

namespace app
{
namespace fnd
{
class Message;
} // fnd

namespace xgame
{
class MsgEndSign;
class MsgHudStartFallDead;
class MsgGetCenterPosition;
class MsgHitEventCollision;
class MsgHitTriggerBase;
class MsgStayTrigger;
class MsgPLStartSleepMode;
class MsgTakeObject;
class MsgTakePixie;
class MsgLossRing;
class MsgPLIsDead;
class MsgPLGetUserNo;
class MsgPLIsDisableChangePhantomArea;
class MsgPLGetPhantomRestTime;
class MsgPlayerReachGoal;
class MsgPLGetHistoryPosition;
class MsgBeginGPathMode;
class MsgEndGPathMode;
class MsgCylinderSpeedDown;
class MsgGetDeathTornadoInfo;
class MsgNotifyBossStart;
class MsgPLBeginAutorun;
class MsgPLFinishAutorun;
class MsgPLHoldOn;
class MsgPLReleaseHold;
class MsgPLEnableSearchAllDirections;
class MsgNotifySilhouetteState;
class MsgPLStealth;
class MsgPLVisibleItemEffect;
class MsgPlayerPassPointMarker;
class MsgRestrictWarp;
class MsgRestrictWarpCancel;
class MsgPLGetRingNum;
class MsgWarpNewArea;
class MsgExitLoop;
class MsgDlcZeldaHeartAllRecovery;
class MsgFlipBoostAnytimeBoost;
class MsgStopForGoal;
class MsgChange2DMode;
class MsgChange3DMode;
class MsgDamage;
class MsgDead;
class MsgPLStartDiving;
class MsgPLEnterDivingVolume;
class MsgWarp;
class MsgPLChangeAreaTopView;
class MsgPLSetNumRing;
class MsgEnterLoop;
class MsgGetPLLoopInfo;
class MsgSetLoopFilter;
class MsgCatchPlayer;
class MsgAppeareKnockback;
class MsgLaunchPathSpring;
class MsgPLStartAlongPathMode;
class MsgSheepBumperImpulse;
class MsgSheepTargetImpulse;
class MsgSheepRollingImpulse;
class MsgItemTreeWobblePoint;
class MsgQuicksandImpulse;
class MsgDroppingSand;
class MsgOnRunningSand;
class MsgSandHoleDrawIn;
class MsgBumperImpulse;
class MsgFlipperImpulse;
class MsgPinBallStarter;
class MsgSeaMineStream;
class MsgWaterWorks;
class MsgWarpOtherSide;
class MsgKekkoBlow;
class MsgGetSuckedIntoPipe;
class MsgHitUpdraftCollision;
class MsgPLJumpToTargetPosition;
class MsgSandDriveStarter;
class MsgBakubakuJump;
class MsgPLStagger;
class MsgPLQuake;
class MsgNotifyMidBossDMEvent;
class MsgHoverImpulse;
class MsgDlcZeldaTakeHeart;
class MsgDlcZeldaTakeHeartContainer;
class MsgStartPhantomSign;
class MsgHudStartHoming;
class MsgHudStartStomping;
class MsgOnGroundImpulse;
class MsgSpringImpulse;
} // xgame

namespace Player
{
class CStateGOC;
class MsgPLChangeStateGetBubble;
class MsgPLCheckPhantomStart;
class MsgChangeDamageState;
class MsgChangeDeadState;
class MsgGravitySwitched;
class MsgNotifyFinishAutoRun;

class CStateBase : public CState
{
public:
    LWAPI(0x029a3d30, NONE)
    ~CStateBase() {}

    LWAPI(0x029a3648, 0x008981a0)
    bool ProcessMessage(CStateGOC& goc, fnd::Message& msg);

    LWAPI(0x029a0e9c, NONE)
    virtual bool ProcMsgStartPhantomSign(CStateGOC& goc, xgame::MsgStartPhantomSign& msg)
    {
        return true;
    }

    LWAPI(0x029a0f14, NONE)
    virtual bool ProcMsgHudStartHoming(CStateGOC& goc, xgame::MsgHudStartHoming& msg)
    {
        return true;
    }

    LWAPI(0x029a0f0c, NONE)
    virtual bool ProcMsgHudStartStomping(CStateGOC& goc, xgame::MsgHudStartStomping& msg)
    {
        return true;
    }

    LWAPI(0x029a0ea4, TODO)
    void ProcMsgEndSign(CStateGOC& goc, xgame::MsgEndSign& msg);

    LWAPI(0x029a0f1c, TODO)
    void ProcMsgHudStartFallDead(CStateGOC& goc, xgame::MsgHudStartFallDead& msg);

    LWAPI(0x029a0f5c, TODO)
    void ProcMsgGetCenterPosition(CStateGOC& goc, xgame::MsgGetCenterPosition& msg);

    LWAPI(0x029a101c, TODO)
    void CheckHitDeadCollision(CStateGOC& goc, xgame::MsgHitEventCollision const& msg);

    LWAPI(0x029a10cc, TODO)
    void CheckHitHighJumpCollision(CStateGOC& goc, xgame::MsgHitEventCollision const& msg);

    LWAPI(0x029a1170, TODO)
    void CheckHitInletCollision(CStateGOC& goc, xgame::MsgHitEventCollision const& msg);

    LWAPI(0x029a1234, TODO)
    void CheckEnableAttackByHitCollision(CStateGOC& goc, xgame::MsgHitEventCollision const& msg) const;

    LWAPI(0x029a12c4, TODO)
    void CheckHitDamage(CStateGOC& goc, bool* param_2) const;

    LWAPI(0x029a1414, TODO)
    void ChangeStateForMsgDamageReply(CStateGOC& goc, xgame::MsgDamage const& msg);

    LWAPI(0x029a1690, TODO)
    void CheckHitCollisionAttackStatus(CStateGOC& goc, xgame::MsgHitEventCollision const& msg);

    LWAPI(0x029a18a0, TODO)
    void CheckHitEventCollision(CStateGOC& goc, xgame::MsgHitEventCollision& msg);

    LWAPI(0x029a1948, TODO)
    void ProcMsgHitEventCollision(CStateGOC& goc, xgame::MsgHitEventCollision& msg);

    LWAPI(0x029a196c, TODO)
    void CheckHitPressDeadCollision(CStateGOC& goc, xgame::MsgHitTriggerBase& msg);

    LWAPI(0x029a19ec, TODO)
    void CheckHitTargetSearchCollision(CStateGOC& goc, xgame::MsgHitTriggerBase& msg);

    LWAPI(0x029a1a78, TODO)
    void CheckMsgStayTrigger(CStateGOC& goc, xgame::MsgStayTrigger& msg);

    LWAPI(0x029a1afc, TODO)
    void ProcMsgStayTrigger(CStateGOC& goc, xgame::MsgStayTrigger& msg);

    LWAPI(0x029a1b20, TODO)
    void ProcMsgPLStartSleepMode(CStateGOC& goc, xgame::MsgPLStartSleepMode& msg);

    LWAPI(0x029a1c54, TODO)
    void ProcMsgTakeObject(CStateGOC& goc, xgame::MsgTakeObject& msg);

    LWAPI(0x029a2a2c, TODO)
    void TakePixie(CStateGOC& goc, Game::EPhantomType param_2, int param_3);

    LWAPI(0x029a2acc, TODO)
    void ProcMsgTakePixie(CStateGOC& goc, xgame::MsgTakePixie& msg);

    LWAPI(0x029a2b3c, TODO)
    void ProcMsgLossRing(CStateGOC& goc, xgame::MsgLossRing& msg);

    LWAPI(0x029a2be8, TODO)
    void ProcMsgPLIsDead(CStateGOC& goc, xgame::MsgPLIsDead& msg);

    LWAPI(0x029a2c20, TODO)
    void ProcMsgPLGetUserNo(CStateGOC& goc, xgame::MsgPLGetUserNo& msg);

    LWAPI(0x029a2c58, TODO)
    void ProcMsgPLIsDisableChangePhantomArea(CStateGOC& goc, xgame::MsgPLIsDisableChangePhantomArea& msg);

    LWAPI(0x029a2cfc, TODO)
    void ProcMsgPLGetPhantomRestTime(CStateGOC& goc, xgame::MsgPLGetPhantomRestTime& msg);

    LWAPI(0x029a2d54, TODO)
    void ProcMsgPlayerReachGoal(CStateGOC& goc, xgame::MsgPlayerReachGoal& msg);

    LWAPI(0x029a2e70, TODO)
    void ProcMsgPLGetHistoryPosition(CStateGOC& goc, xgame::MsgPLGetHistoryPosition& msg);

    LWAPI(0x029a2ee0, TODO)
    void ProcMsgBeginGPathMode(CStateGOC& goc, xgame::MsgBeginGPathMode& msg);

    LWAPI(0x029a2f78, TODO)
    void ProcMsgEndGPathMode(CStateGOC& goc, xgame::MsgEndGPathMode& msg);

    LWAPI(0x029a2ff4, TODO)
    void ProcMsgCylinderSpeedDown(CStateGOC& goc, xgame::MsgCylinderSpeedDown& msg);

    LWAPI(0x029a3084, TODO)
    void ProcMsgGetDeathTornadoInfo(CStateGOC& goc, xgame::MsgGetDeathTornadoInfo& msg);

    LWAPI(0x029a30cc, TODO)
    void ProcMsgNotifyBossStart(CStateGOC& goc, xgame::MsgNotifyBossStart& msg);

    LWAPI(0x029a3100, TODO)
    void ProcMsgPLBeginAutorun(CStateGOC& goc, xgame::MsgPLBeginAutorun& msg);

    LWAPI(0x029a3228, TODO)
    void ProcMsgPLFinishAutorun(CStateGOC& goc, xgame::MsgPLFinishAutorun& msg);

    LWAPI(0x029a3254, TODO)
    void SetPLHoldOn(CStateGOC& goc, xgame::MsgPLHoldOn& msg);

    LWAPI(0x029a331c, TODO)
    void ProcMsgPLHoldOn(CStateGOC& goc, xgame::MsgPLHoldOn& msg);

    LWAPI(0x029a3340, TODO)
    void ProcMsgPLReleaseHold(CStateGOC& goc, xgame::MsgPLReleaseHold& msg);

    LWAPI(0x029a3374, TODO)
    void ProcMsgPLEnableSearchAllDirections(CStateGOC& goc, xgame::MsgPLEnableSearchAllDirections& msg);

    LWAPI(0x029a33b8, TODO)
    void ProcMsgNotifySilhouetteState(CStateGOC& goc, xgame::MsgNotifySilhouetteState& msg);

    LWAPI(0x029a33fc, TODO)
    void ProcMsgPLStealth(CStateGOC& goc, xgame::MsgPLStealth& msg);

    LWAPI(0x029a345c, TODO)
    void ProcMsgPLVisibleItemEffect(CStateGOC& goc, xgame::MsgPLVisibleItemEffect& msg);

    LWAPI(0x029a3490, TODO)
    void ProcMsgPlayerPassPointMarker(CStateGOC& goc, xgame::MsgPlayerPassPointMarker& msg);

    LWAPI(0x029a34bc, TODO)
    void ProcMsgRestrictWarp(CStateGOC& goc, xgame::MsgRestrictWarp& msg);

    LWAPI(0x029a34f0, TODO)
    void ProcMsgRestrictWarpCancel(CStateGOC& goc, xgame::MsgRestrictWarpCancel& msg);

    LWAPI(0x029a3524, TODO)
    void ProcMsgPLGetRingNum(CStateGOC& goc, xgame::MsgPLGetRingNum& msg);

    LWAPI(0x029a3564, TODO)
    void ProcMsgWarpNewArea(CStateGOC& goc, xgame::MsgWarpNewArea& msg);

    LWAPI(0x029a35b8, TODO)
    void ProcMsgExitLoop(CStateGOC& goc, xgame::MsgExitLoop& msg);

    LWAPI(0x029a3620, TODO)
    void ProcMsgDlcZeldaHeartAllRecovery(CStateGOC& goc, xgame::MsgDlcZeldaHeartAllRecovery& msg);

    LWAPI(0x029a3878, TODO)
    void StartDiving(CStateGOC& goc, xgame::MsgPLStartDiving& msg);

    LWAPI(0x029a3920, TODO)
    void WarpOtherSide(CStateGOC& goc, xgame::MsgWarpOtherSide& msg);

    LWAPI(0x029a3b00, TODO)
    void Change2DMode(CStateGOC& goc, xgame::MsgChange2DMode& msg);

    LWAPI(0x029a3cc8, TODO)
    void Change3DMode(CStateGOC& goc, xgame::MsgChange3DMode& msg);

    LWAPI(0x029a3d10, TODO)
    void ChangeAreaTopView(CStateGOC& goc, xgame::MsgPLChangeAreaTopView& msg);

    LWAPI(0x029a3d20, TODO)
    void ProcMsgNotifyFinishAutoRun(CStateGOC& goc, MsgNotifyFinishAutoRun& msg);

    LWAPI(0x029a3d28, TODO)
    void ProcMsgFlipBoostAnytimeBoost(CStateGOC& goc, xgame::MsgFlipBoostAnytimeBoost& msg);
};

class CStateActionBase : public CStateBase
{
public:
    LWAPI(0x029a53cc, NONE)
    ~CStateActionBase() {}

    LWAPI(0x029a52c0, 0x00898660)
    bool ProcessMessage(CStateGOC& goc, fnd::Message& msg);

    LWAPI(0x029a3d84, TODO)
    void ChangeToDamageState(CStateGOC& goc);

    LWAPI(0x029a3df8, TODO)
    void ProcMsgChangeDamageState(CStateGOC& goc, MsgChangeDamageState& msg);

    LWAPI(0x029a3f48, TODO)
    void ProcMsgChangeDeadState(CStateGOC& goc, MsgChangeDeadState& msg);

    LWAPI(0x029a3f74, TODO)
    void ProcMsgStopForGoal(CStateGOC& goc, xgame::MsgStopForGoal& msg);

    LWAPI(0x029a3fa0, TODO)
    void ProcMsgChange2DMode(CStateGOC& goc, xgame::MsgChange2DMode& msg);

    LWAPI(0x029a3fc4, TODO)
    void ProcMsgChange3DMode(CStateGOC& goc, xgame::MsgChange3DMode& msg);

    LWAPI(0x029a4070, TODO)
    void ProcMsgDamage(CStateGOC& goc, xgame::MsgDamage& msg);

    LWAPI(0x029a4310, TODO)
    void ProcMsgDead(CStateGOC& goc, xgame::MsgDead& msg);

    LWAPI(0x029a4554, TODO)
    void ProcMsgPLStartDiving(CStateGOC& goc, xgame::MsgPLStartDiving& msg);

    LWAPI(0x029a4578, TODO)
    void EnterDivingVolume(CStateGOC& goc, xgame::MsgPLEnterDivingVolume& msg);

    LWAPI(0x029a4628, TODO)
    void ProcMsgPLEnterDivingVolume(CStateGOC& goc, xgame::MsgPLEnterDivingVolume& msg);

    LWAPI(0x029a464c, TODO)
    void ProcMsgGravitySwitched(CStateGOC& goc, MsgGravitySwitched& msg);

    LWAPI(0x029a4704, TODO)
    void ProcMsgWarp(CStateGOC& goc, xgame::MsgWarp& msg);

    LWAPI(0x029a4b18, TODO)
    void ProcMsgPLChangeAreaTopView(CStateGOC& goc, xgame::MsgPLChangeAreaTopView& msg);

    LWAPI(0x029a4b3c, TODO)
    void ProcMsgPLSetNumRing(CStateGOC& goc, xgame::MsgPLSetNumRing& msg);

    LWAPI(0x029a4b70, TODO)
    void EnterLoop(CStateGOC& goc, xgame::MsgEnterLoop& msg);

    LWAPI(0x029a4d64, TODO)
    void ProcMsgEnterLoop(CStateGOC& goc, xgame::MsgEnterLoop& msg);

    LWAPI(0x029a4d88, TODO)
    void ProcMsgGetPLLoopInfo(CStateGOC& goc, xgame::MsgGetPLLoopInfo& msg);

    LWAPI(0x029a4e30, TODO)
    void ProcMsgSetLoopFilter(CStateGOC& goc, xgame::MsgSetLoopFilter& msg);

    LWAPI(0x029a4ed4, TODO)
    void SetCatchPlayer(CStateGOC& goc, xgame::MsgCatchPlayer& msg);

    LWAPI(0x029a51cc, TODO)
    void ProcMsgCatchPlayer(CStateGOC& goc, xgame::MsgCatchPlayer& msg);

    LWAPI(0x029a51f0, TODO)
    void ProcMsgAppeareKnockback(CStateGOC& goc, xgame::MsgAppeareKnockback& msg);
};

class CStateSonicBase : public CStateActionBase
{
public:
    LWAPI(0x029a72e4, NONE)
    ~CStateSonicBase() {}

    LWAPI(0x029a6788, 0x00898960)
    bool ProcessMessage(CStateGOC& goc, fnd::Message& msg);

    LWAPI(0x029a6d84, 0x00893f90)
    bool ProcMsgStartPhantomSign(CStateGOC& goc, xgame::MsgStartPhantomSign& msg);

    LWAPI(0x029a6de8, 0x00893fd0)
    bool ProcMsgHudStartHoming(CStateGOC& goc, xgame::MsgHudStartHoming& msg);

    LWAPI(0x029a6e28, 0x00893fd0)
    bool ProcMsgHudStartStomping(CStateGOC& goc, xgame::MsgHudStartStomping& msg);

    LWAPI(0x029a6e68, 0x00896990)
    virtual bool ProcMsgOnGroundImpulse(CStateGOC& goc, xgame::MsgOnGroundImpulse& msg);

    LWAPI(0x029a70ec, 0x00895fe0)
    virtual bool ProcMsgSpringImpulse(CStateGOC& goc, xgame::MsgSpringImpulse& msg);

    LWAPI(0x029a7280, 0x008974b0)
    virtual bool ProcMsgPLCheckPhantomStart(CStateGOC& goc, MsgPLCheckPhantomStart& msg);

    LWAPI(0x029a5420, TODO)
    void ProcMsgLaunchPathSpring(CStateGOC& goc, xgame::MsgLaunchPathSpring& msg);

    LWAPI(0x029a55f4, TODO)
    void ProcMsgPLChangeStateGetBubble(CStateGOC& goc, MsgPLChangeStateGetBubble& msg);

    LWAPI(0x029a56a4, TODO)
    void ProcMsgPLStartAlongPathMode(CStateGOC& goc, xgame::MsgPLStartAlongPathMode& msg);

    LWAPI(0x029a5894, TODO)
    void ProcMsgSheepBumperImpulse(CStateGOC& goc, xgame::MsgSheepBumperImpulse& msg);

    LWAPI(0x029a5a04, TODO)
    void ProcMsgSheepTargetImpulse(CStateGOC& goc, xgame::MsgSheepTargetImpulse& msg);

    LWAPI(0x029a5b14, TODO)
    void ProcMsgSheepRollingImpulse(CStateGOC& goc, xgame::MsgSheepRollingImpulse& msg);

    LWAPI(0x029a5bd0, TODO)
    void ProcMsgItemTreeWobblePoint(CStateGOC& goc, xgame::MsgItemTreeWobblePoint& msg);

    LWAPI(0x029a5d0c, TODO)
    void ProcMsgQuicksandImpulse(CStateGOC& goc, xgame::MsgQuicksandImpulse& msg);

    LWAPI(0x029a5d7c, TODO)
    void ProcMsgDroppingSand(CStateGOC& goc, xgame::MsgDroppingSand& msg);

    LWAPI(0x029a5dd4, TODO)
    void ProcMsgOnRunningSand(CStateGOC& goc, xgame::MsgOnRunningSand& msg);

    LWAPI(0x029a5e64, TODO)
    void ProcMsgSandHoleDrawIn(CStateGOC& goc, xgame::MsgSandHoleDrawIn& msg);

    LWAPI(0x029a5edc, TODO)
    void BumperImpulse(CStateGOC& goc, xgame::MsgBumperImpulse& msg);

    LWAPI(0x029a5fa8, TODO)
    void ProcMsgBumperImpulse(CStateGOC& goc, xgame::MsgBumperImpulse& msg);

    LWAPI(0x029a5fcc, TODO)
    void ProcMsgFlipperImpulse(CStateGOC& goc, xgame::MsgFlipperImpulse& msg);

    LWAPI(0x029a6088, TODO)
    void ProcMsgPinBallStarter(CStateGOC& goc, xgame::MsgPinBallStarter& msg);

    LWAPI(0x029a60d8, TODO)
    void ProcMsgSeaMineStream(CStateGOC& goc, xgame::MsgSeaMineStream& msg);

    LWAPI(0x029a61dc, TODO)
    void ProcMsgWaterWorks(CStateGOC& goc, xgame::MsgWaterWorks& msg);

    LWAPI(0x029a6244, TODO)
    void ProcMsgWarpOtherSide(CStateGOC& goc, xgame::MsgWarpOtherSide& msg);

    LWAPI(0x029a6268, TODO)
    void ProcMsgKekkoBlow(CStateGOC& goc, xgame::MsgKekkoBlow& msg);

    LWAPI(0x029a62ec, TODO)
    void ProcMsgGetSuckedIntoPipe(CStateGOC& goc, xgame::MsgGetSuckedIntoPipe& msg);

    LWAPI(0x029a6354, TODO)
    void ProcMsgHitUpdraftCollision(CStateGOC& goc, xgame::MsgHitUpdraftCollision& msg);

    LWAPI(0x029a63a8, TODO)
    void ProcMsgPLJumpToTargetPosition(CStateGOC& goc, xgame::MsgPLJumpToTargetPosition& msg);

    LWAPI(0x029a6468, TODO)
    void ProcMsgSandDriveStarter(CStateGOC& goc, xgame::MsgSandDriveStarter& msg);

    LWAPI(0x029a6494, TODO)
    void ProcMsgBakubakuJump(CStateGOC& goc, xgame::MsgBakubakuJump& msg);

    LWAPI(0x029a6500, TODO)
    void ProcMsgPLStagger(CStateGOC& goc, xgame::MsgPLStagger& msg);

    LWAPI(0x029a6578, TODO)
    void ProcMsgPLQuake(CStateGOC& goc, xgame::MsgPLQuake& msg);

    LWAPI(0x029a65f4, TODO)
    void ProcMsgNotifyMidBossDMEvent(CStateGOC& goc, xgame::MsgNotifyMidBossDMEvent& msg);

    LWAPI(0x029a6648, TODO)
    void ProcMsgHoverImpulse(CStateGOC& goc, xgame::MsgHoverImpulse& msg);

    LWAPI(0x029a6738, TODO)
    void ProcMsgDlcZeldaTakeHeart(CStateGOC& goc, xgame::MsgDlcZeldaTakeHeart& msg);

    LWAPI(0x029a6760, TODO)
    void ProcMsgDlcZeldaTakeHeartContainer(CStateGOC& goc, xgame::MsgDlcZeldaTakeHeartContainer& msg);

    LWAPI(0x029a69d8, TODO)
    void CheckSpinPhantomStart(CStateGOC& goc, MsgPLCheckPhantomStart& msg);

    LWAPI(0x029a6bd4, TODO)
    void CheckPhantomStart(CStateGOC& goc, MsgPLCheckPhantomStart& msg);
};
} // Player
} // app
