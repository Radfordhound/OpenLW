// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once
#include "PlayerStateBase.h"
#include "Sound/SoundHandle.h"
#include <csl/ut/bitset.h>

namespace csl
{
namespace math
{
struct Vector3;
} // math
} // csl

namespace app
{
namespace fnd
{
class Message;
} // fnd

namespace Player
{
class CStateGOC;
class MsgHitDamage;
class MsgSetupDamageAndBonus;

class CStateJumpCommon : public CStateSonicBase
{
public:
    LWAPI(0x029ca030, NONE)
    ~CStateJumpCommon() {}

    LWAPI(0x029c9b7c, TODO)
    void CheckChangeState(CStateGOC& goc, bool param_2, bool param_3, bool param_4);

    LWAPI(0x029c9d08, TODO)
    void CheckGoOutWaterJump(CStateGOC& goc);

    LWAPI(0x029c9d10, TODO)
    void GetJumpParameter(CStateGOC& goc);

    LWAPI(0x029c9d18, TODO)
    void GetJumpParameter(CStateGOC& goc) const;

    LWAPI(0x029c9d20, TODO)
    void CheckAddUpForce(CStateGOC& goc, float param_2);

    LWAPI(0x029c9e5c, 0x008ac640)
    void DoJump(CStateGOC& goc, csl::math::Vector3 const* param_2);

    LWAPI(0x029c9fd8, TODO)
    void AttenuateJumpForce(CStateGOC& goc);
};

class CStateJump : public CStateJumpCommon
{
OPENLW_PROTECTED
    // TODO: Are these fields actually a part of CStateJumpCommon?
    csl::ut::Bitset<unsigned char> field_0x2c;
    float field_0x30;
    float field_0x34;
    fnd::SoundHandle field_0x38;

public:
    typedef void* context_type; // TODO

    LWAPI(0x029ca650, TODO)
    ~CStateJump();

    LWAPI(0x029ca19c, TODO)
    bool ProcessMessage(CStateGOC& goc, fnd::Message& msg);

    LWAPI(0x029ca1bc, 0x008ac7c0)
    void OnEnter(CStateGOC& goc, int param_2);

    LWAPI(0x029ca5a0, 0x008ac8f0)
    void OnLeave(CStateGOC& goc, int param_2);

    LWAPI(0x029ca340, 0x008ac960)
    bool Step(CStateGOC& goc, float dt);

    LWAPI(0x029c9668, TODO)
    CStateJump();

    LWAPI(0x029ca104, TODO)
    void ProcMsgHitDamage(CStateGOC& goc, MsgHitDamage& msg);

    LWAPI(0x029ca180, TODO)
    void ProcMsgSetupDamageAndBonus(CStateGOC& goc, MsgSetupDamageAndBonus& msg);
};

LWAPI_STATIC_ASSERT_SIZE(CStateJump, 0x44)
} // Player
} // app
