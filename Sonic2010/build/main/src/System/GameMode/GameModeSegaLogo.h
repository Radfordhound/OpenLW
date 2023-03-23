#pragma once
#include "GameMode.h"
#include "System/Component/Fsm.h"
#include "Render/gfx_Renderable.h"
#include <boost/intrusive_ptr.hpp>

namespace app
{
namespace fnd
{
class CMoviePlayer;
} // fnd

class GameModeSegalogo : public GameMode,
	public GameModeUtil::Fsm<GameModeSegalogo>::Type
{
OPENLW_PRIVATE
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
    LWAPI(0x02add174, TODO)
    GameModeSegalogo();

    LWAPI(0x02add314, 0x00930ba0)
    void OnEnter(CGame& game);

    LWAPI(0x02add578, TODO)
    void LoadData();

    LWAPI(0x02add5f4, TODO)
    void ChangeState(EventFunc state);

    LWAPI(0x02add660, TODO)
    StateType StateLoad(const EventType& e);

    LWAPI(0x02add844, 0x00930c90)
    StateType StateExec(const EventType& e);

    LWAPI(0x02adde2c, TODO)
    void Draw();

    struct MyRenderable : public gfx::Renderable
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

        LWAPI(0x02adde94, 0x009309a0)
        void Render(const hh::gfx::RenderEventParam* params);
    };

    LWAPI_STATIC_ASSERT_SIZE(MyRenderable, 0x60)
};

// TODO: Uncomment once all fields have been added.
//LWAPI_STATIC_ASSERT_SIZE(GameModeSegalogo, 0x58)
} // app
