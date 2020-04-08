#include "CGame.h"
#include "Application.h"
#include "game/GlobalAllocator.h"

namespace app
{
/* <b>Wii U: TODO, PC: TODO</b> */
static csl::fnd::IAllocator* GameAllocator;

CGame::CGame()
{
    // TODO
}

void CGame::Config(Application& app)
{
    // TODO
}

void CGame::OnSetup(Application& app)
{
    // TODO
}

void CGame::OnShutdown(Application& app)
{
    // TODO
}

void CGame::Tick(Application& app)
{
    // TODO
}

void CGame::Draw(Application& app)
{
    // TODO
}

unsigned int CGame::ProcessMessage(fnd::Message& msg)
{
    // TODO
    return 0;
}

unsigned int CGame::PreProcessMessage(fnd::Message& msg)
{
    // TODO
    return 0;
}

void CGame::AdvanceFrame()
{
    // TODO
}

void CGame::CheckSuspend()
{
    // TODO
}

void CGame::DelayDestroy()
{
    // TODO
}

void CGame::DrawSync()
{
    // TODO
}

void CGame::FlushFileLoad()
{
    // TODO
}

void CGame::InitGameMode(GameMode* gameMode)
{
    // TODO
}

void CGame::Pause()
{
    // TODO
}

void CGame::ShutdownGameMode()
{
    // TODO
}

void CGame::UpdateFlag(bool param_1)
{
    // TODO
}

CGame* CreateGame(Application& app)
{
    GameAllocator = game::GlobalAllocator::GetAllocator(csl::fnd::AllocatorID::UkZero);

    CGame* game = new (GameAllocator) CGame();
    game->AddRef();
    return game;
}
}
