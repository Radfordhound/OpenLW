#include "CGameSequence.h"
#include "CGame.h"
#include "gfx/RenderManager.h"
#include "fnd/Message.h"
#include "fnd/SUpdateInfo.h"
#include "../System/GameMode/GameModeStartUp.h"

namespace app
{
bool CGameSequence::ProcessMessage(fnd::Message& msg)
{
    DispatchFSM(event_t::CreateMessage(msg));
    return msg.Received;
}

void CGameSequence::InitGameMode(GameMode* gameMode)
{
    m_gameMode = gameMode;
    m_game->InitGameMode(gameMode);
}

void CGameSequence::ShutdownGameMode()
{
    m_game->ShutdownGameMode();
    m_gameMode = nullptr;

    gfx::RenderManager* renderMgr = gfx::RenderManager::GetInstance();
    hh::mr::CRenderingInfrastructure* renderDev = renderMgr->GetRenderingDevice();
    // TODO: Call something on renderDev, but only on Wii U???
}

void CGameSequence::StartLeakChecker() {}

CGameSequence::state_t CGameSequence::StateBoot(const event_t& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_MESSAGE:
        if (e.getMessage().ID == ADVANCE_SEQUENCE)
        {
            ChangeState(&CGameSequence::StateProduct);
            e.getMessage().Received = true;
            return nullptr;
        }
        break;

    case SIGNAL_LEAVE:
        ShutdownGameMode();
        return nullptr;

    case SIGNAL_ENTER:
        InitGameMode(new GameModeStartUp());
        return nullptr;
    }

    return FSM_TOP();
}

CGameSequence::state_t CGameSequence::StateProduct(const event_t& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_INIT:
        FSM_INIT(&CGameSequence::StateSegaLogo);
        return nullptr;
    }

    return FSM_TOP();
}

CGameSequence::state_t CGameSequence::StateSegaLogo(const event_t& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_MESSAGE:
        if (e.getMessage().ID == ADVANCE_SEQUENCE)
        {
            // TODO: Un-comment this line:
            //ChangeState(&CGameSequence::StateSaveInit);
            e.getMessage().Received = true;
            return nullptr;
        }
        break;

    case SIGNAL_LEAVE:
        ShutdownGameMode();
        return nullptr;

    case SIGNAL_ENTER:
        StartLeakChecker();
        // TODO: Un-comment this line:
        //InitGameMode(new GameModeSegalogo());
        return nullptr;
    }

    return &CGameSequence::StateProduct;
}

void CGameSequence::ChangeState(state_t newState)
{
    m_nextState = newState;
}

void CGameSequence::Start()
{
    InitFSM();
}

void CGameSequence::Update(const fnd::SUpdateInfo& updateInfo)
{
    if (m_nextState.IsValid())
    {
        FSM_SETSTATE(m_nextState);
        m_nextState.Clear();
    }

    DispatchFSM(event_t::CreateUpdate(updateInfo.DeltaTime));
}

CGameSequence::CGameSequence(CGame& game) :
    TTinyFsm(&CGameSequence::StateBoot),
    m_game(&game),
    m_gameMode(nullptr),
    field_0x28("stg901")
{
    // TODO
}
}
