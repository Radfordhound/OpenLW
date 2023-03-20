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
LWAPI_PRIVATE
    bool m_isWarningEnd;
    boost::intrusive_ptr<SaveData::CSaveAuto> field_0x38;

public:
    LWAPI(TODO, TODO)
    ~GameModeStartUp();

    LWAPI(0x02aa386c, TODO)
    void OnEnter(CGame& game);

    LWAPI(0x02aa38b4, TODO)
    void OnLeave(CGame& game);

    LWAPI(0x02aa392c, TODO)
    void Update(CGame& game, const fnd::SUpdateInfo& updateInfo);

    LWAPI(0x02aa3994, TODO)
    bool ProcessMessage(CGame& game, fnd::Message& msg);

    LWAPI(0x02aa3a7c, TODO)
    bool PreProcessMessage(CGame& game, fnd::Message& msg);

    // TODO: Other non-virtual member functions.

    LWAPI(0x02aa3988, TODO)
    void ProcMsgWarningEnd(CGame& game, xgame::MsgWarningEnd& msg);

    LWAPI(0x02aa3d14, TODO)
    bool IsWarningEnd();

    LWAPI(0x02aa3ac8, TODO)
    void PreLoadGame();

    LWAPI(0x02aa3b7c, 0x0091b4f0)
    void PreLoadResidentFile();

    LWAPI(0x02aa3cb0, TODO)
    void LoadResidentFile();

    LWAPI(0x02aa3d1c, TODO)
    void ChangeState(state_t::event_func newState);

    LWAPI(0x02aa3d88, TODO)
    state_t StateFirstCpk(const event_t& e);

    LWAPI(0x02aa3fdc, TODO)
    state_t StateLoadGame(const event_t& e);

    LWAPI(0x02aa3e9c, TODO)
    state_t StateLoadResidentFile(const event_t& e);

    LWAPI(0x02aa4114, TODO)
    state_t StateMain(const event_t& e);

    LWAPI(0x02aa4458, TODO)
    state_t StateAfterLoad(const event_t& e);

    LWAPI(0x02aa37b8, 0x0091bd60)
    GameModeStartUp();
};
}
