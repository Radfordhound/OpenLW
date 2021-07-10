#include "CGame.h"
#include "CGameSequence.h"
#include "Application.h"
#include "fnd/FileLoader.h"
#include "game/GlobalAllocator.h"
#include "gfx/RenderManager.h"

namespace app
{
// Wii U: TODO, PC: TODO
static csl::fnd::IAllocator* GameAllocator;

bool CGame::PreProcessMessage(fnd::Message& msg)
{
    if ((!m_gameSeq || !m_gameSeq->ProcessMessage(msg)) && m_gameMode)
    {
        return m_gameMode->ProcessMessage(*this, msg);
    }

    return false;
}

bool CGame::ProcessMessage(fnd::Message& msg)
{
    if (PreProcessMessage(msg))
    {
        return true;
    }
    
    return CActor::ProcessMessage(msg);
}

void CGame::Config(Application& app)
{
    m_aspectRatio = (1280.0f / 720.0f);
}

void CGame::OnSetup(Application& app)
{
    // TODO

    // Setup game sequence.
    m_gameSeq = new (m_allocator) CGameSequence(*this);
    m_gameSeq->AddRef();
    m_gameSeq->Start();
}

void CGame::OnShutdown(Application& app)
{
    // TODO
}

void CGame::Tick(Application& app)
{
    // Update FileLoader.
    fnd::FileLoader* fileLoader = fnd::FileLoader::GetInstance();
    fileLoader->Update();

    // TODO

    // Update game sequence.
    if (m_gameSeq)
    {
        m_gameSeq->Update(app.UpdateInfo);
    }

    if (m_gameMode)
    {
        bool doFrame = true;
        // TODO

        if (doFrame)
        {
            gfx::RenderManager* renderMgr = gfx::RenderManager::GetInstance();
            renderMgr->Update(app.UpdateInfo, -1);
            // TODO
        }
    }

    // TODO

    // Render scene.
    gfx::RenderManager* renderMgr = gfx::RenderManager::GetInstance();
    renderMgr->Render();

    // TODO
}

void CGame::Draw(Application& app)
{
    gfx::RenderManager* renderMgr = gfx::RenderManager::GetInstance();
    renderMgr->Render();
}

void CGame::AdvanceFrame()
{
    // TODO
}

void CGame::CheckSuspend()
{
    // TODO
}

void CGame::DelayDestroy() {}

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
    m_gameMode = gameMode;
    if (m_gameMode)
    {
        m_gameMode->Game = this;
        m_gameMode->InitializeGameMode(*this);
        m_gameMode->OnEnter(*this);
    }
}

void CGame::Pause()
{
    // TODO
}

void CGame::ShutdownGameMode()
{
    if (m_gameMode)
    {
        m_gameMode->OnLeave(*this);
        m_gameMode->Destroy(*this);

        // TODO

        m_gameMode->ReleaseGameMode(*this);
        m_gameMode = nullptr;
    }
}

void CGame::UpdateFlag(bool param_1)
{
    // TODO
}

CGame::CGame() :
    m_gameMode(new GameMode()),
    m_gameSeq(nullptr),
    // TODO: Initialize field_0x70 to 0.
    m_aspectRatio(1280.0f / 720.0f)
    // TODO: Initialize field_0x74 to 0.
{
    SetUpdateFlag(fnd::PHASE_NORMAL, false);
    SetUpdateFlag(fnd::PHASE_UNK_ONE, false);
    SetUpdateFlag(fnd::PHASE_UNK_TWO, false);
}

CGame* CreateGame(Application& app)
{
    GameAllocator = game::GlobalAllocator::GetAllocator(ALLOCATOR_UNK_ZERO);

    CGame* game = new (GameAllocator) CGame();
    game->AddRef();
    return game;
}

void DestroyGame(GameBase* game)
{
    game->Release();
    GameAllocator = nullptr;
}
}
