#pragma once
#include "Component/TinyFsm.h"
#include "ReferencedObject.h"
#include <csl/ut/string.h>

namespace app
{
class CGame;
struct GameMode;

namespace fnd
{
struct Message;
struct SUpdateInfo;
} // fnd

class CGameSequence : public fnd::ReferencedObject,
    public TTinyFsm<CGameSequence, TiFsmBasicEvent<CGameSequence>, true>
{
OPENLW_PRIVATE
    CGame* m_game;
    GameMode* m_gameMode;
    csl::ut::FixedString<16> field_0x28;
    EventFunc m_nextState;
    // TODO

public:
    LWAPI(0x02a809a8, 0x0090e950)
    bool ProcessMessage(fnd::Message& msg);

    LWAPI(0x02a80adc, TODO)
    void InitGameMode(GameMode* gameMode);
    
    LWAPI(0x02a80aec, NONE)
    void ShutdownGameMode();

    LWAPI(0x02a80b7c, TODO)
    void StartLeakChecker();

    LWAPI(0x02a83998, 0x00910c30)
    StateType StateBoot(const EventType& e);

    LWAPI(0x02a83b38, TODO)
    StateType StateProduct(const EventType& e);

    LWAPI(0x02a83c00, TODO)
    StateType StateSegaLogo(const EventType& e);

    LWAPI(0x02a80ac8, TODO)
    void ChangeState(EventFunc state);

    LWAPI(0x02a80970, 0x0090f240)
    void Start();

    LWAPI(0x02a80a24, 0x0090fab0)
    void Update(const fnd::SUpdateInfo& updateInfo);

    // TODO

    LWAPI(0x02a80808, 0x00910d10)
    CGameSequence(CGame& game);
};

// TODO: Uncomment once all fields have been added.
//LWAPI_STATIC_ASSERT_SIZE(CGameSequence, 0xF0)
} // app
