#pragma once
#include "GameMode.h"
#include "SaveData/SaveAuto.h"
#include "System/Component/TinyFsm.h"
#include <boost/intrusive_ptr.hpp>

namespace app
{
namespace xgame
{
struct MsgWarningEnd;
}

class GameModeStartUp : public GameMode, public TTinyFsm<GameModeStartUp,
    GameModeUtil::Event<GameModeStartUp>> // size == 0x3c
{
    bool m_isWarningEnd;
    boost::intrusive_ptr<SaveData::CSaveAuto> field_0x38;

public:
    // Wii U: TODO, PC: TODO
    ~GameModeStartUp();

    // Wii U: 0x02aa386c, PC: TODO
    void OnEnter(CGame& game);

    // Wii U: 0x02aa38b4, PC: TODO
    void OnLeave(CGame& game);

    // Wii U: 0x02aa392c, PC: TODO
    void Update(CGame& game, const fnd::SUpdateInfo& updateInfo);

    // Wii U: 0x02aa3994, PC: TODO
    bool ProcessMessage(CGame& game, fnd::Message& msg);

    // Wii U: 0x02aa3a7c, PC: TODO
    bool PreProcessMessage(CGame& game, fnd::Message& msg);

    // TODO: Other non-virtual member functions.

    // Wii U: 0x02aa3988, PC: TODO
    void ProcMsgWarningEnd(CGame& game, xgame::MsgWarningEnd& msg);

    // Wii U: 0x02aa3d14, PC: TODO
    bool IsWarningEnd();

    // Wii U: 0x02aa3ac8, PC: TODO
    void PreLoadGame();

    // Wii U: 0x02aa3b7c, PC: 0x0091b4f0
    void PreLoadResidentFile();

    // Wii U: 0x02aa3cb0, PC: TODO
    void LoadResidentFile();

    // Wii U: 0x02aa3d1c, PC: TODO
    void ChangeState(state_t::event_func newState);

    // Wii U: 0x02aa3d88, PC: TODO
    state_t StateFirstCpk(const event_t& e);

    // Wii U: 0x02aa3fdc, PC: TODO
    state_t StateLoadGame(const event_t& e);

    // Wii U: 0x02aa3e9c, PC: TODO
    state_t StateLoadResidentFile(const event_t& e);

    // Wii U: 0x02aa4114, PC: TODO
    state_t StateMain(const event_t& e);

    // Wii U: 0x02aa4458, PC: TODO
    state_t StateAfterLoad(const event_t& e);

    // Wii U: 0x02aa37b8, PC: 0x0091bd60
    GameModeStartUp();
};
}
