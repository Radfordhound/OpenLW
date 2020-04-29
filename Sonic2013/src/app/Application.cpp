#pragma once
#include "Application.h"
#include "fnd/FileSystemCri.h"
#include "game/GlobalAllocator.h"
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

    // Setup FileSystem
    fnd::FileSystem* fileSystem = fnd::FileSystem::GetInstance();
    fnd::FileSystem::Info fsInfo = fnd::FileSystem::Info();
    fsInfo.RootDirectory = rootDirectory;

    fileSystem->Setup(fsInfo);

    // Bind file directories
    fnd::FileBinder* binder = fileSystem->GetDefaultBinder();
    if (binder)
    {
        if (!(fileSystem->Flags & fnd::FILE_SYSTEM_FLAG_USE_CPK))
        {
            binder->BindDirectory("raw", 0x100, false);
            binder->BindDirectory("", 0x300, false);
            binder->WaitSyncAll();
        }
        else
        {
            binder->BindCpk("disk/sonic2013_0.cpk", 0x1000, false);
            binder->BindCpk("disk/sonic2013_patch_0.cpk", 0x4000, false);
            binder->WaitSyncAll();
        }
    }

    // Set FileCache size
    fileSystem->SetFileCacheSize(0xC000000);

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
    csl::fnd::IAllocator* allocator = game::GlobalAllocator::GetAllocator(
        csl::fnd::AllocatorID::UkTwo);

    // TODO
    CreateDevice();

    // TODO
    fnd::FileSystem::ReplaceInstance(
        allocator->Create<fnd::FileSystemCri>());

    // TODO
}

void Application::ShutdownMain()
{
    // TODO
    fnd::FileSystem::ReplaceInstance(nullptr);
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
    ShutdownCommon();
    ShutdownMain();
    // TODO
    fnd::DestroySingletons();
    // TODO
}

void Application::ShutdownCommon()
{
    // TODO
}
}
