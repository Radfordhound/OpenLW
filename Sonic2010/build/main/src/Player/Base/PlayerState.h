// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once
#include "PlayerPath.h"
#include "PlayerInput.h"
#include "PlayerCollision.h"
#include "Player/Posture/PlayerPostureManager.h"
#include "System/Component/Goc.h"
#include "Sound/SoundHandle.h"
#include "Utility/StateBase.h"
#include "Utility/StateManager.h"
#include <csl/ut/bitset.h>

namespace csl
{
namespace math
{
struct Vector3;
struct Matrix34;
} // math
} // csl

namespace app
{
class GameObject;

namespace fnd
{
class Message;
} // fnd

namespace game
{
class ResPathObject;
class ColliShape;
} // game

namespace Player
{
class CPlayer;
struct SStateParameter;
class CStateGOC;
class CPhysics;

// TODO: Should this be in another header?
enum EAbility
{
    // TODO
};

// TODO: Should this be in another header?
enum BodyMode
{
    Human,
    Spin,
    SuperSonic,
    PhantomSpin,
    PhantomLaser,
    PhantomRocket,
    PhantomAsteroid,
    PhantomEagle,
    Unknown8,
    PhantomRhythm,
    PhantomBomb,
    PhantomHover,
    PhantomQuake,
};

class CState : public ut::StateBase<CStateGOC>
{
OPENLW_PROTECTED
    csl::ut::Bitset<unsigned int> field_0x14;
    int m_curSeq;
    int m_nextSeq;
    float m_alarmTimer;
    float m_sleepTimer;
    float field_0x28;

public:
    LWAPI(0x029307d4, 0x0085c1e0)
    ~CState();

    LWAPI(0x029308bc, 0x0085c250)
    void Enter(CStateGOC& goc, int param_2);

    LWAPI(0x02930914, 0x006f8ac0)
    void Leave(CStateGOC& goc, int param_2);

    LWAPI(0x02930924, 0x0085c280)
    bool Update(CStateGOC& goc, float dt);

    LWAPI(0x02930828, 0x0070a480)
    virtual void OnEnter(CStateGOC& goc, int param_2);

    LWAPI(0x0293082c, 0x0070a480)
    virtual void OnLeave(CStateGOC& goc, int param_2);

    LWAPI(0x02930830, 0x004a34e0)
    virtual void Transit(CStateGOC& goc);

    LWAPI(0x02930838, 0x005dd780)
    virtual bool Step(CStateGOC& goc, float dt);

    LWAPI(0x02930764, 0x0085d3c0)
    CState();

    LWAPI(0x02930840, 0x0085aa50)
    void GotoSeq(int param_1);

    LWAPI(0x02930848, TODO)
    void Sleep(float param_1, int param_2);

    LWAPI(0x02930880, 0x0085c230)
    void SetAlarm(float param_1);
};

LWAPI_STATIC_ASSERT_SIZE(CState, 0x2C)

class CStateGOC : public CGOComponent
{
OPENLW_PRIVATE
    void* field_0x10;
    void* field_0x14;
    unsigned char padding1[40];
    unsigned char padding2[12];
    fnd::SoundHandle m_soundHnd;
    CPlayer* m_player;
    unsigned char padding3[4];
    ut::StateManager<CStateGOC>* m_stateManager;
    unsigned char padding4[88];

public:
    LWAPI(0x02931034, 0x0085e110)
    ~CStateGOC();

    LWAPI(0x02934464, 0x0085e140)
    void Update(float param_1);

    LWAPI(0x029333F4, 0x0085c320)
    virtual void Initialize();

    LWAPI(0x02933494, 0x0085b3e0)
    virtual void Finalize();

    LWAPI(0x02930CA4, TODO)
    CStateGOC(CPlayer* param_1);

    LWAPI(0x02931130, 0x0085b400)
    void ChangeState(int param_1);

    LWAPI(0x029311A8, 0x0085b450)
    void ChangeStateAlways(int param_1);

    LWAPI(0x02931208, TODO)
    void GetPluginManager() const;

    LWAPI(0x02931210, TODO)
    void PausePlugin(bool param_1);

    LWAPI(0x02931234, 0x0085aa60)
    float GetParameter(unsigned int paramType) const;

    LWAPI(0x02931244, 0x0085b6d0)
    CPostureManager* GetPostureManager();

    LWAPI(0x02931258, TODO)
    void GetPostureInputManager();

    LWAPI(0x02931264, TODO)
    void AddStatePlugin(unsigned int param_1);

    LWAPI(0x02931288, TODO)
    void RemoveStatePlugin(unsigned int param_1);

    LWAPI(0x029312B4, TODO)
    void GetBlackBoard();

    LWAPI(0x029312C0, TODO)
    void AddPhantomEnergy(float param_1, bool param_2);

    LWAPI(0x02931334, TODO)
    void UsePhantomEnergy(float param_1);

    LWAPI(0x02931370, TODO)
    void IsPhantomEnergyRemain();

    LWAPI(0x029313A4, TODO)
    void SetPhantomEnergyMax();

    LWAPI(0x029313CC, TODO)
    void GetBlackBoard() const;

    LWAPI(0x029313D8, TODO)
    void IsNowSuperSonic() const;

    LWAPI(0x02931404, TODO)
    void GetRingNum() const;

    LWAPI(0x0293142C, TODO)
    void IsAbilityEnable(EAbility param_1) const;

    LWAPI(0x02931454, TODO)
    void SetAbility(EAbility param_1);

    LWAPI(0x02931480, TODO)
    void GetInputGOC() const;

    LWAPI(0x02931488, TODO)
    void SetEnableTouchPanel(bool param_1);

    LWAPI(0x02931498, 0x0085b490)
    CPhysics* GetPhysics();

    LWAPI(0x029314A4, TODO)
    void GetPhysics() const;

    LWAPI(0x029314C0, TODO)
    void GetVisualGoc();

    LWAPI(0x029314D8, TODO)
    void GetEffect();

    LWAPI(0x029314F0, TODO)
    void GetVisualGoc() const;

    LWAPI(0x02931508, TODO)
    void GetEffect() const;

    LWAPI(0x02931520, TODO)
    void GetCollision() const;

    LWAPI(0x02931538, TODO)
    void GetCollision();

    LWAPI(0x02931548, TODO)
    void GetPathService() const;

    LWAPI(0x02931554, TODO)
    void GetPathService();

    LWAPI(0x02931560, TODO)
    void GetPath(PathType param_1);

    LWAPI(0x02931584, TODO)
    void GetPath(PathType param_1) const;

    LWAPI(0x029315A8, TODO)
    void GetActorID() const;

    LWAPI(0x029315B4, TODO)
    void GetDocument() const;

    LWAPI(0x029315C0, TODO)
    void GetPhysicsWorld() const;

    LWAPI(0x029315C8, TODO)
    void GetCollisionWorld() const;

    LWAPI(0x029315D0, TODO)
    void GetWorld() const;

    LWAPI(0x029315D8, TODO)
    void GetLevelInfo() const;

    LWAPI(0x029315E0, TODO)
    void GetPlayerNo() const;

    LWAPI(0x02931604, TODO)
    void GetToHudPlayerNumber() const;

    LWAPI(0x02931608, TODO)
    void GetPosition() const;

    LWAPI(0x0293162C, TODO)
    void GetRotation() const;

    LWAPI(0x02931650, TODO)
    void GetFront() const;

    LWAPI(0x02931674, TODO)
    void GetUpDirection() const;

    LWAPI(0x029316C8, TODO)
    void GetRight() const;

    LWAPI(0x029316EC, TODO)
    void GetMatrix() const;

    LWAPI(0x02931710, TODO)
    void GetVelocity() const;

    LWAPI(0x02931734, TODO)
    void GetHorzVelocity() const;

    LWAPI(0x02931758, TODO)
    void GetVertVelocity() const;

    LWAPI(0x0293177C, TODO)
    void GetVertVelocityScalar() const;

    LWAPI(0x029317A0, TODO)
    void GetPostureInputForce() const;

    LWAPI(0x029317C4, TODO)
    void IsControlMode2D() const;

    LWAPI(0x029317F4, 0x0085bb50)
    bool IsOnGround() const;

    LWAPI(0x02931818, TODO)
    void IsSpinDash() const;

    LWAPI(0x02931844, TODO)
    void IsDash() const;

    LWAPI(0x02931870, TODO)
    void IsWaterRun() const;

    LWAPI(0x0293189C, TODO)
    void IsIceRun() const;

    LWAPI(0x029318C8, TODO)
    void IsEnableIceRun() const;

    LWAPI(0x02931940, TODO)
    void IsEnableSquat() const;

    LWAPI(0x029319A8, TODO)
    void GetAttackStatus();

    LWAPI(0x029319CC, TODO)
    void GetAttackStatus() const;

    LWAPI(0x029319F0, TODO)
    void StartOutOfControl(float param_1, bool param_2);

    LWAPI(0x02931A08, TODO)
    void EndOutOfControl(unsigned int param_1);

    LWAPI(0x02931A10, 0x0085ab00)
    bool IsOutOfControl() const;

    LWAPI(0x02931A3C, TODO)
    void ClearOutOfControl();

    LWAPI(0x02931A44, TODO)
    void SetMoveCylinderTimer(float param_1);

    LWAPI(0x02931A50, TODO)
    void IsMoveCylinderEnable() const;

    LWAPI(0x02931A6C, TODO)
    void SetEndAvoidWallTimer(float param_1);

    LWAPI(0x02931A80, TODO)
    void GetAvoidWallContinueNum() const;

    LWAPI(0x02931A88, TODO)
    void GetOnGroundTime() const;

    LWAPI(0x02931AAC, TODO)
    void GetOnAirTime() const;

    LWAPI(0x02931AD0, TODO)
    void SetDisableTime(EDisableTimer param_1, float param_2);

    LWAPI(0x02931AE8, TODO)
    void SetDisableTime(EDisableTimer param_1, float param_2, unsigned int param_3);

    LWAPI(0x02931AFC, TODO)
    void IsTimerDisable(EDisableTimer param_1) const;

    LWAPI(0x02931B08, TODO)
    void IsTimerDisable(EDisableTimer param_1, unsigned int param_2) const;

    LWAPI(0x02931B10, TODO)
    void Is2DMode() const;

    LWAPI(0x02931B40, TODO)
    void SendMessage(unsigned int param_1, fnd::Message& param_2);

    LWAPI(0x02931B54, TODO)
    void SendMessageImm(unsigned int param_1, fnd::Message& param_2);

    LWAPI(0x02931B70, TODO)
    void SendMessageImm(unsigned int param_1, unsigned int param_2, fnd::Message& param_3);

    LWAPI(0x02931B94, 0x0085ABB0)
    void SendMessageImmToCamera(fnd::Message& param_1);

    LWAPI(0x02931BE0, TODO)
    void SendMessageToCamera(fnd::Message& param_1);

    LWAPI(0x02931C2C, TODO)
    void SendMessageImmToHud(fnd::Message& param_1);

    LWAPI(0x02931C84, TODO)
    void SendMessageToHud(fnd::Message& param_1);

    LWAPI(0x02931CDC, TODO)
    void SendMessageImmToGame(fnd::Message& param_1);

    LWAPI(0x02931D34, TODO)
    void SendMessageImmToGame(fnd::Message& param_1, unsigned int param_2);

    LWAPI(0x02931D9C, TODO)
    void SendMessageToGame(fnd::Message& param_1);

    LWAPI(0x02931DF4, TODO)
    void SendMessageToGame(fnd::Message& param_1, unsigned int param_2);

    LWAPI(0x02931E58, TODO)
    void SendMessageImm(GameObject* param_1, fnd::Message& param_2);

    LWAPI(0x02931E60, TODO)
    void SendMessageToRival(fnd::Message& param_1);

    LWAPI(0x02931EB8, TODO)
    void SendMessageImmToRival(fnd::Message& param_1);

    LWAPI(0x02932648, TODO)
    void ChangeVisual(BodyMode param_1);

    LWAPI(0x02932934, 0x0085b7b0)
    void ChangeAnimation(const char* animName, float blendTime);

    LWAPI(0x02932968, TODO)
    void SetAnimation(const char* animName);

    LWAPI(0x029329A0, 0x0085b780)
    void PushAnimation(const char* animName);

    LWAPI(0x029329D4, TODO)
    void GetCurrentAnimationName() const;

    LWAPI(0x029329F8, TODO)
    bool IsCurrentAnimation(const char* animName) const;

    LWAPI(0x02932A2C, TODO)
    void SetAnimationProportionRate(float param_1);

    LWAPI(0x02932A74, TODO)
    void IsAnimationInterpolate() const;

    LWAPI(0x02932AA4, TODO)
    void IsCurrentSingleAnimation(const char* param_1) const;

    LWAPI(0x02932AE4, TODO)
    void IsAnimationFinished() const;

    LWAPI(0x02932B0C, TODO)
    void IsAnimationFinishedEdge() const;

    LWAPI(0x02932B3C, TODO)
    void GetAnimationSpeed();

    LWAPI(0x02932B64, TODO)
    void SetAnimationSpeed(float param_1);

    LWAPI(0x02932BAC, TODO)
    void SetAnimationFrame(float param_1);

    LWAPI(0x02932BF4, TODO)
    void GetAnimationFrame();

    LWAPI(0x02932C1C, TODO)
    void SetNextAnimation(const char* param_1, float param_2);

    LWAPI(0x02932C50, TODO)
    void ExitLoopAnimation();

    LWAPI(0x02932C78, TODO)
    void SetBlendEnable(const char* param_1, bool param_2);

    LWAPI(0x02932CDC, TODO)
    void SetBlendWeight(const char* param_1, float param_2);

    LWAPI(0x02932D34, TODO)
    void CreateEffect(const char* param_1);

    LWAPI(0x02932D38, TODO)
    void IsEnableMaterialEffect() const;

    LWAPI(0x02932D6C, 0x0085c420)
    fnd::SoundHandle PlaySE(const char* param_1, bool param_2);

    LWAPI(0x02932EEC, TODO)
    fnd::SoundHandle PlaySE(const char* param_1, fnd::SoundDeviceTag param_2);

    LWAPI(0x02932FAC, TODO)
    void PlaySE_3D(const char* param_1);

    LWAPI(0x02932FBC, TODO)
    fnd::SoundHandle PlaySE(const char* param_1, float param_2, bool param_3);

    LWAPI(0x029330C0, TODO)
    void StopSE(fnd::SoundHandle param_1);

    LWAPI(0x029330D0, 0x0085ba50)
    void ChangeBodyCollision(BodyCollisionType type);

    LWAPI(0x02933100, TODO)
    void ProcessMessage(fnd::Message& param_1);

    LWAPI(0x02933194, TODO)
    void ProcessMessageToCurrentState(fnd::Message& param_1);

    LWAPI(0x029331F8, TODO)
    void ProcessMessageToCurrentPosture(fnd::Message& param_1);

    LWAPI(0x02933290, 0x0085b620)
    void RegisterCommonStates();

    LWAPI(0x029332FC, TODO)
    void InitHSM();

    LWAPI(0x02933340, TODO)
    void RegisterCommonPluginBefore();

    LWAPI(0x029334E8, TODO)
    void GetCurrentState() const;

    LWAPI(0x02933518, TODO)
    void CheckGrindPathToRide(const game::ResPathObject& param_1, float param_2) const;

    LWAPI(0x029337E0, TODO)
    void StartGrind();

    LWAPI(0x02933A54, TODO)
    void CheckChangeToGrind();

    LWAPI(0x02933CFC, TODO)
    void CheckAndChangePathSideView();

    LWAPI(0x02934148, TODO)
    void UpdateCounter(float param_1);

    LWAPI(0x02934384, TODO)
    void UpdateFlags(float param_1);

    LWAPI(0x0293445C, TODO)
    void ClearDamagedShapeList();

    LWAPI(0x0293450C, TODO)
    void GetContextParameter();

    LWAPI(0x02934514, TODO)
    void GetContextParameter() const;

    LWAPI(0x0293451C, TODO)
    void AddStateContextParameter(const SStateParameter& param_1);

    LWAPI(0x02934540, TODO)
    void CheckRequestJump() const;

    LWAPI(0x029345A4, TODO)
    void GetRequestStateForGround();

    LWAPI(0x0293462C, TODO)
    void CheckRequestSpinDash(bool param_1) const;

    LWAPI(0x02934720, TODO)
    void GetRequestStateForAir(bool param_1);

    LWAPI(0x02934B34, TODO)
    void CheckRequestBrake();

    LWAPI(0x02934C94, TODO)
    void CheckRequestDash() const;

    LWAPI(0x02934CF8, TODO)
    void CheckRequestBallMove(bool param_1) const;

    LWAPI(0x02934DE4, TODO)
    void ChangeTo2DMode(const csl::math::Vector3& param_1, bool param_2);

    LWAPI(0x02934F2C, TODO)
    void ChangeTo3DMode(bool param_1);

    template<typename T>
    T* ChangePostureInput()
    {
        __debugbreak();
        return nullptr; // TODO!!!
    }

    LWAPI(0x02934F74, TODO)
    void FinishGrind(bool param_1);

    LWAPI(0x029350FC, TODO)
    void FinishQuickStepMode();

    LWAPI(0x02935108, TODO)
    void GetVisualLocaterManager();

    LWAPI(0x02935130, TODO)
    void VisualLocaterStartInterporation(const csl::math::Matrix34& param_1, float param_2, unsigned int param_3);

    LWAPI(0x029351A4, TODO)
    void VisualLocaterStartInterporation(float param_1, unsigned int param_2);

    LWAPI(0x0293520C, TODO)
    void SetVisualLocaterMatrix(const csl::math::Matrix34& param_1);

    LWAPI(0x02935240, TODO)
    void GetVisualLocaterMatrix();

    template<typename T>
    T* ChangeVisualLocater(float param_1, unsigned int param_2)
    {
        __debugbreak();
        return nullptr; // TODO!!!
    }

    LWAPI(0x029352C0, TODO)
    void ChangeNormalVisualLocater(float param_1, unsigned int param_2);

    LWAPI(0x02935320, TODO)
    void ChangeExternalVisualLocater(float param_1, unsigned int param_2);

    LWAPI(0x02935324, TODO)
    void ProcessGravitySwitched();

    LWAPI(0x0293536C, TODO)
    void SetParkourEffect();

    LWAPI(0x029353DC, TODO)
    void DeleteParkourEffect();

    LWAPI(0x029355E0, TODO)
    void AddDamagedShape(const game::ColliShape* param_1);

    LWAPI(0x02935784, TODO)
    void IsDamagedShape(const game::ColliShape* param_1);

    LWAPI(0x029357D0, TODO)
    void GetState(const CState* param_1, int param_2) const;

    LWAPI(0x029357D8, TODO)
    void GetState(int param_1) const;

    LWAPI(0x029357E0, TODO)
    void GetStatePluginPtr(const char* param_1);

    template<typename T>
    T* GetStatePlugin()
    {
        __debugbreak();
        return nullptr; // TODO!!!
    }

    template<typename T>
    T* GetStateContextParameter()
    {
        __debugbreak();
        return nullptr; // TODO!!!
    }

    template<typename T>
    T* ChangePosture()
    {
        return static_cast<T*>(GetPostureManager()->ChangePosture(T::GroupID));
    }

    template<typename T>
    T* GetPosture()
    {
        __debugbreak();
        return nullptr; // TODO!!!
    }

    template<typename T>
    T* CreateStateContextParameter()
    {
        __debugbreak();
        return nullptr; // TODO!!!
    }

    template<typename T>
    T* GetVisualLocater()
    {
        __debugbreak();
        return nullptr; // TODO!!!
    }
};

LWAPI_STATIC_ASSERT_SIZE(CStateGOC, 0xbc)
} // Player
} // app
