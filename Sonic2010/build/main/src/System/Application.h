#pragma once
#include "UpdateInfo.h"
#include <Hedgehog/Rsdx/Graphics/Device/RsdxDevCore.h>

namespace app
{
class CGame;
class SyncTimer;

struct Application // size == 276??
{
    fnd::SUpdateInfo UpdateInfo;
    char RootDirectory[128];
    hh::rsdx::RsdxDevCore* RsdxDevCore;
    hh::rsdx::RsdxDevice* RsdxDevice;
    // TODO
    void* InstHandle;
    void* SurfaceHandle;
    // TODO
    unsigned int Width;
    unsigned int Height;
    CGame* Game;
    // TODO

    LWAPI(0x021c71fc, 0x004ab160)
    virtual ~Application();

    virtual bool CreateDevice() = 0;

    virtual void DestroyDevice() = 0;

    LWAPI(0x021c75d8, 0x004ab190)
    virtual void InitializeBasic();

    LWAPI(0x021c7608, 0x004ab1b0)
    virtual void ShutdownBasic();

    LWAPI(0x021c76ec, 0x004ab1c0)
    virtual void InitializeMain();

    LWAPI(0x021c77c8, 0x004ab2e0)
    virtual void ShutdownMain();

    LWAPI(0x021c7830, 0x00d626a8)
    virtual void RunCore(SyncTimer* timer);

    LWAPI(0x021c743c, 0x004ab690)
    void Initialize();

    LWAPI(0x021c7210, 0x004ab360)
    void InitializeCommon();

    LWAPI(0x021c78bc, 0x004ab600)
    void RunOnce(const fnd::SUpdateInfo& updateInfo);

    LWAPI(0x021c7834, TODO)
    void Poll(const fnd::SUpdateInfo& updateInfo);

    LWAPI(0x021c78a4, TODO)
    void Tick();

    LWAPI(0x021c7584, 0x004ab670)
    void Run();

    LWAPI(0x021c78f0, TODO)
    void Draw();

    LWAPI(0x021c7508, 0x004ab6e0)
    void Shutdown();

    LWAPI(0x021c74cc, TODO)
    void ShutdownCommon();

    LWAPI(0x021c713c, 0x004ab0e0)
    Application();
};
}
