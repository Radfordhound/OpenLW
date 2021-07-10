#include "Application.h"
#include "CriSystem.h"
#include "CGame.h"
#include "SyncTimer.h"
#include "hid/DeviceManager.h"
#include "game/GlobalAllocator.h"
#include "gfx/RenderManager.h"
#include "fnd/FileSystemCri.h"
#include <Hedgehog/MirageCore/hhMirageCore.h>

using namespace hh;
using namespace mr;

namespace app
{
Application::~Application()
{
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
    csl::fnd::IAllocator* allocator = game::GlobalAllocator::GetAllocator(ALLOCATOR_UNK_TWO);

    // TODO
    InitializeHHMirage();

    CreateDevice();

    // TODO

    // Create FileSystemCri instance and use it as the FileSystem.
    fnd::FileSystem::ReplaceInstance(
        fnd::FileSystemCri::Create(allocator));

    // Create RenderManager instance and use it as the RenderManager.
    gfx::RenderManager::ReplaceInstance(
        gfx::RenderManager::Create(allocator));

    // Set rendering device.
    gfx::RenderManager* renderMgr = gfx::RenderManager::GetInstance();
    CRenderingInfrastructure* renderInfrs = renderMgr->GetRenderingDevice();

    renderInfrs->Device = RsdxDevice;

    // TODO
}

void Application::ShutdownMain()
{
    // TODO
    gfx::RenderManager::ReplaceInstance(nullptr);
    fnd::FileSystem::ReplaceInstance(nullptr);
    // TODO
    DestroyDevice();
    // TODO
}

void Application::RunCore(SyncTimer* timer) {}

void Application::Initialize()
{
    InitializeBasic();
    fnd::InitSingletons();

    Game = CreateGame(*this);
    Game->Config(*this);

    InitializeMain();
    InitializeCommon();

    Game->OnSetup(*this);
}

void Application::InitializeCommon()
{
    // TODO

    // Setup FileSystem.
    fnd::FileSystem* fileSystem = fnd::FileSystem::GetInstance();
    fnd::FileSystem::Info fsInfo = fnd::FileSystem::Info();
    fsInfo.RootDirectory = RootDirectory;

    fileSystem->Setup(fsInfo);

    // Bind file directories.
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

    // Set FileCache size.
    fileSystem->SetFileCacheSize(0xC000000);

    // Setup RenderManager.
    gfx::RenderManager::SetupInfo setupInfo = gfx::RenderManager::SetupInfo();
    setupInfo.SetAspect(1280 / 720.0f);
    setupInfo.SetShaderName("shader.pac");

    gfx::RenderManager* renderMgr = gfx::RenderManager::GetInstance();
    renderMgr->Setup(setupInfo);

    // TODO

    // Setup DeviceManager.
    hid::DeviceManager* dmgr = hid::DeviceManager::GetInstance();
    dmgr->Setup();

    // TODO
}

void Application::RunOnce(const fnd::SUpdateInfo& updateInfo)
{
    Poll(updateInfo);
    Tick();
}

void Application::Poll(const fnd::SUpdateInfo& updateInfo)
{
    // Poll devices.
    hid::DeviceManager* devMgr = hid::DeviceManager::GetInstance();
    devMgr->Poll(updateInfo.DeltaTime);

    // Update CriSystem.
    CriSystem* criSystem = CriSystem::GetInstance();
    criSystem->Update();

    // Update FileSystem.
    fnd::FileSystem* fileSystem = fnd::FileSystem::GetInstance();
    fileSystem->Update();

    // TODO
}

void Application::Tick()
{
    Game->Tick(*this);
}

void Application::Run()
{
    SyncTimer* syncTimer = SyncTimer::GetInstance();
    syncTimer->Reset();
    RunCore(syncTimer);
}

void Application::Draw()
{
    Game->Draw(*this);
}

void Application::Shutdown()
{
    Game->OnShutdown(*this);
    ShutdownCommon();
    ShutdownMain();
    DestroyGame(Game);
    fnd::DestroySingletons();
    ShutdownBasic();
}

void Application::ShutdownCommon()
{
    // TODO

    gfx::RenderManager* renderMgr = gfx::RenderManager::GetInstance();
    renderMgr->Shutdown();

    // TODO
}

Application::Application()
{
    RsdxDevCore = nullptr;
    RsdxDevice = nullptr;
    InstHandle = nullptr;
    SurfaceHandle = nullptr;
    // TODO
    Width = 1280;
    Height = 720;
    // TODO
    Game = nullptr;
    RootDirectory[0] = '\0';
    UpdateInfo = fnd::SUpdateInfo();
    UpdateInfo.DeltaTime = (1 / 60.0f);
    UpdateInfo.field_0x8 = 1;
}
}
