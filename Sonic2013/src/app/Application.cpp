#pragma once
#include "Application.h"
#include "gfx/RenderManager.h"
#include "hid/DeviceManager.h"

namespace app
{
Application::Application() : updateInfo()
{
    updateInfo.RefreshRate = (1 / 60.0f);
    // TODO
}

Application::~Application()
{
    // TODO
}

void Application::Initialize()
{
    InitializeBasic();
    fnd::InitSingletons();
    
    game = CreateGame(*this);
    game->Config(*this);

    InitializeMain();
    InitializeCommon();

    game->OnSetup(*this);
}

void Application::InitializeCommon()
{
    // TODO

    // Setup RenderManager
    gfx::RenderManager::SetupInfo setupInfo = {};
    setupInfo.SetAspect(1280 / 720.0f);
    setupInfo.SetShaderName("shader.pac");

    gfx::RenderManager::GetInstance()->Setup(setupInfo);

    // TODO
}

void Application::InitializeBasic()
{
    // TODO
}

void Application::ShutdownBasic()
{
    // TODO
}

void Application::InitializeMain()
{
    // TODO
    CreateDevice();
    // TODO
}

void Application::ShutdownMain()
{
    // TODO
    DestroyDevice();
    // TODO
}

void Application::RunCore(SyncTimer* timer) {}
void Application::RunOnce(const fnd::SUpdateInfo& updateInfo)
{
    Poll(updateInfo);
    Tick();
}

void Application::Poll(const fnd::SUpdateInfo& updateInfo)
{
    //hid::DeviceManager::GetInstance()->Poll(updateInfo.);
    // TODO
}

void Application::Tick()
{
    game->Tick(*this);
}

void Application::Run()
{
    SyncTimer* syncTimer = SyncTimer::GetInstance();
    syncTimer->Reset();
    RunCore(syncTimer);
}

void Application::Draw()
{
    // TODO
}

void Application::Shutdown()
{
    // TODO
    ShutdownMain();
    // TODO
}

void Application::ShutdownCommon()
{
    // TODO
}
}
