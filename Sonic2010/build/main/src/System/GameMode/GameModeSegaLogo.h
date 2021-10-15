#pragma once
#include "GameMode.h"
#include "../Component/TinyFsm.h"
#include "../../OpenLW/gfx/Renderable.h"
#include <boost/intrusive_ptr.hpp>

namespace app
{
namespace fnd
{
class CMoviePlayer;
}

class GameModeSegalogo : public GameMode, public TTinyFsm<GameModeSegalogo,
    GameModeUtil::Event<GameModeSegalogo>, false> // size == 0x58
{
    fnd::CMoviePlayer* m_player;
    unsigned int field_0x38;
    unsigned int field_0x3c;
    float field_0x40;
    unsigned int field_0x44;
    unsigned int field_0x48;
    float field_0x4c;
    bool field_0x50;
    boost::intrusive_ptr<gfx::Renderable> field_0x54;

public:
    // Wii U: 0x02add174, PC: TODO
    GameModeSegalogo();

    // Wii U: 0x02add314, PC: 0x00930ba0
    void OnEnter(CGame& game);

    // Wii U: 0x02add578, PC: TODO
    void LoadData();

    // TODO: I wasn't able to successfully demangle this function's symbol. Are the arguments, etc. all correct?
    // Symbol: __CPR250__ChangeState__Q2_3app16GameModeSegalogoFMQ2_3appJ20JFRCQ3_3app12GameModeUtil39Event__tm__26_Q2_3appJ20J_Q2_3app109TTinyFsmState__tm__88_Q2_3appJ20JQ3_3appJ75JJ89J
    // Wii U: 0x02add5f4, PC: TODO
    void ChangeState(state_t newState);

    // Wii U: 0x02add660, PC: TODO
    state_t StateLoad(const event_t& e);

    // Wii U: 0x02add844, PC: 0x00930c90
    state_t StateExec(const event_t& e);

    // Wii U: 0x02adde2c, PC: TODO
    void Draw();

    struct MyRenderable : public gfx::Renderable // size == 0x60
    {
        GameModeSegalogo* GameMode;

        inline MyRenderable(GameModeSegalogo* gameMode, bool param_1) :
            GameMode(gameMode)
        {
            SetName("GameModeSegalogo");
            SetOption(1);
            SetPriorityDrawOpa(8);
            field_0x54 = (param_1) ? 1 : 3;
        }

        // Wii U: 0x02adde94, PC: 0x009309a0
        void Render(const hh::gfx::RenderEventParam* params);
    };
};
}
