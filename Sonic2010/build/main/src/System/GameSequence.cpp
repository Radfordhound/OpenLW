#include "OpenLW/pch.h"
#include "GameSequence.h"
#include "Game.h"
#include "UpdateInfo.h"
#include "GameMode/GameModeStartUp.h"
#include "GameMode/GameModeSegaLogo.h"
#include "Message/Message.h"
#include "Render/RenderManager.h"

using namespace app::gfx;
using namespace hh::mr;

namespace app
{
bool CGameSequence::ProcessMessage(fnd::Message& msg)
{
    DispatchFSM(EventType::CreateMessage(msg));
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

    RenderManager& renderMgr = RenderManager::GetInstance();
    CRenderingInfrastructure* renderInfra = renderMgr.GetRenderingDevice();
    // TODO: Call something on renderInfra, but only on Wii U???
}

void CGameSequence::StartLeakChecker() {}

CGameSequence::StateType CGameSequence::StateBoot(const EventType& e)
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

CGameSequence::StateType CGameSequence::StateProduct(const EventType& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_INIT:
        FSM_INIT(&CGameSequence::StateSegaLogo);
        return nullptr;
    }

    return FSM_TOP();
}

CGameSequence::StateType CGameSequence::StateSegaLogo(const EventType& e)
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
        InitGameMode(new GameModeSegalogo());
        return nullptr;
    }

    return &CGameSequence::StateProduct;
}

void CGameSequence::ChangeState(EventFunc state)
{
    m_nextState = state;
}

void CGameSequence::Start()
{
    InitFSM();
}

void CGameSequence::Update(const fnd::SUpdateInfo& updateInfo)
{
    if (m_nextState != nullptr)
    {
        FSM_SETSTATE(m_nextState);
        m_nextState = nullptr;
    }

    DispatchFSM(EventType::CreateUpdate(updateInfo.DeltaTime));
}

CGameSequence::CGameSequence(CGame& game) :
    TTinyFsm(&CGameSequence::StateBoot),
    m_game(&game),
    m_gameMode(nullptr),
    field_0x28("stg901"),
    m_nextState(nullptr)
{
    // TODO
}
}
