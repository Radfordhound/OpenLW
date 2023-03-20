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
}

class CGameSequence : public fnd::ReferencedObject,
    public TTinyFsm<CGameSequence, TiFsmBasicEvent<CGameSequence>, true> // size == 0xF0
{
LWAPI_PRIVATE
    CGame* m_game;
    GameMode* m_gameMode;
    csl::ut::FixedString<16> field_0x28;
    state_t::event_func m_nextState;
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
    state_t StateBoot(const event_t& e);

    LWAPI(0x02a83b38, TODO)
    state_t StateProduct(const event_t& e);

    LWAPI(0x02a83c00, TODO)
    state_t StateSegaLogo(const event_t& e);

    LWAPI(0x02a80ac8, TODO)
    void ChangeState(state_t::event_func newState);

    LWAPI(0x02a80970, 0x0090f240)
    void Start();

    LWAPI(0x02a80a24, 0x0090fab0)
    void Update(const fnd::SUpdateInfo& updateInfo);

    // TODO

    LWAPI(0x02a80808, 0x00910d10)
    CGameSequence(CGame& game);
};
}
