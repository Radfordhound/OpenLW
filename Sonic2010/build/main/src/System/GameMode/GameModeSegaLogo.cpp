#include "OpenLW/pch.h"
#include "GameModeSegaLogo.h"
#include "Memory/MemoryRouter.h"
#include "Movie/MoviePlayer.h"
#include "System/FileLoader.h"
#include "System/GameDocument.h"

using namespace app::fnd;
using namespace app::Render;
using namespace csl::ut;

namespace app
{
GameModeSegalogo::GameModeSegalogo() :
    TTinyFsm(&GameModeSegalogo::StateLoad),
    m_player(nullptr),
    field_0x38(0),
    field_0x3c(0),
    field_0x40(0.0f),
    field_0x44(0),
    field_0x48(0),
    field_0x4c(0.0f),
    field_0x54()
{
    // TODO
}

void GameModeSegalogo::OnEnter(CGame& game)
{
    GameMode::OnEnter(game);
    // TODO

    InitFSM();

    field_0x54 = new MyRenderable(this, field_0x50);
    if (field_0x54)
    {
        (*GameDoc->world).AddRenderable(field_0x54.get(),
            SceneGroupType::UNKNOWN_800);
    }
}

void GameModeSegalogo::Update(CGame& game, const fnd::SUpdateInfo& updateInfo)
{
    field_0x40 = updateInfo.DeltaTime;
    GameMode::Update(game, updateInfo);

    DispatchFSM(EventType::CreateUpdate(updateInfo.DeltaTime));
}

void GameModeSegalogo::LoadData()
{
    FileLoaderParam param;
    param.SetMultiLanguageAttr(true, 0);

    LoadFile("ui/ui_common.pac", param);
    LoadFile("ui/ui_segalogo_all.pac", param);

    param.SetMultiLanguageAttr(false, 0);
}

void GameModeSegalogo::ChangeState(EventFunc state)
{
    FSM_TRAN(state);
}

GameModeSegalogo::StateType GameModeSegalogo::StateLoad(const EventType& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_UPDATE:
        if (IsLoadEnd())
        {
            if (field_0x44 == 0)
            {
                field_0x44 = 1;
                return nullptr;
            }
            
            ChangeState(&GameModeSegalogo::StateExec);
        }
        return nullptr;

    case SIGNAL_ENTER:
        LoadData();
        return nullptr;

    case SIGNAL_LEAVE:
        return nullptr;
    }

    return FSM_TOP();
}

GameModeSegalogo::StateType GameModeSegalogo::StateExec(const EventType& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_UPDATE:
        if (field_0x48 == 0)
        {
            if (!field_0x50)
            {
                // TODO
            }

            // TODO
        }

        // TODO
        return nullptr;

    case SIGNAL_ENTER:
    {
    {
        StringBuf<128> local_a8(GetTempAllocator());

        // TODO: Un-comment the following line:
        //ApplicationProperty::GetMultiLanguageName("segalogo.usm", 16, local_a8);

        m_player = CMoviePlayer::Create(local_a8, -1, false, false, false);
        if (m_player)
        {
            m_player->DrawPrepare();
            // TODO
        }
    }

        // TODO
        return nullptr;
    }

    case SIGNAL_LEAVE:
        return nullptr;
    }

    return FSM_TOP();
}

void GameModeSegalogo::Draw()
{
    if (m_player)
    {
        m_player->Draw(true);
    }
}

void GameModeSegalogo::MyRenderable::Render(const hh::gfx::RenderEventParam* params)
{
    GameMode->Draw();
}
} // app
