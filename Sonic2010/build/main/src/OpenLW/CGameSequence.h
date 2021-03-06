#pragma once
#include "TinyFsm.h"
#include "fnd/ReferencedObject.h"
#include "csl/ut/string.h"

namespace app
{
class CGame;
struct GameMode;

namespace fnd
{
struct Message;
struct SUpdateInfo;
}

class CGameSequence : public fnd::ReferencedObject, public TTinyFsm<CGameSequence> // size == 0xF0
{
    CGame* m_game;
    GameMode* m_gameMode;
    csl::ut::FixedString<16> field_0x28;
    state_t m_nextState;
    // TODO

public:
    // Wii U: 0x02a809a8, PC: 0x0090e950
    bool ProcessMessage(fnd::Message& msg);

    // Wii U: 0x02a80adc, PC: TODO
    void InitGameMode(GameMode* gameMode);
    
    // Wii U: 0x02a80aec, PC: Inlined
    void ShutdownGameMode();

    // Wii U: 0x02a80b7c, PC: TODO
    void StartLeakChecker();

    // Wii U: 0x02a83998, PC: 0x00910c30
    state_t StateBoot(const event_t& e);

    // Wii U: 0x02a83b38, PC: TODO
    state_t StateProduct(const event_t& e);

    // Wii U: 0x02a83c00, PC: TODO
    state_t StateSegaLogo(const event_t& e);

    // TODO: I wasn't able to successfully demangle this function's symbol. Are the arguments, etc. all correct?
    // Symbol: __CPR226__ChangeState__Q2_3app13CGameSequenceFMQ2_3appJ20JFRCQ2_3app46TiFsmBasicEvent__tm__23_Q2_3appJ20J_Q2_3app99TTinyFsmState__tm__78_Q2_3appJ20JQ2_3appJ69J
    // Wii U: 0x02a80ac8, PC: TODO
    void ChangeState(state_t newState);

    // Wii U: 0x02a80970, PC: 0x0090f240
    void Start();

    // Wii U: 0x02a80a24, PC: 0x0090fab0
    void Update(const fnd::SUpdateInfo& updateInfo);

    // TODO

    // Wii U: 0x02a80808, PC: 0x00910d10
    CGameSequence(CGame& game);
};
}
