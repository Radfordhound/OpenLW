#pragma once
#include "fnd/SUpdateInfo.h"
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

    // Wii U: 0x021c71fc, PC: 0x004ab160
    virtual ~Application();

    virtual bool CreateDevice() = 0;
    virtual void DestroyDevice() = 0;

    // Wii U: 0x021c75d8, PC: 0x004ab190
    virtual void InitializeBasic();

    // Wii U: 0x021c7608, PC: 0x004ab1b0
    virtual void ShutdownBasic();

    // Wii U: 0x021c76ec, PC: 0x004ab1c0
    virtual void InitializeMain();

    // Wii U: 0x021c77c8, PC: 0x004ab2e0
    virtual void ShutdownMain();

    // Wii U: 0x021c7830, PC: 0x00d626a8 (GENERIC RETURN VOID)
    virtual void RunCore(SyncTimer* timer);

    // Wii U: 0x021c743c, PC: 0x004ab690
    void Initialize();

    // Wii U: 0x021c7210, PC: 0x004ab360
    void InitializeCommon();

    // Wii U: 0x021c78bc, PC: 0x004ab600
    void RunOnce(const fnd::SUpdateInfo& updateInfo);

    // Wii U: 0x021c7834, PC: TODO
    void Poll(const fnd::SUpdateInfo& updateInfo);

    // Wii U: 0x021c78a4, PC: TODO
    void Tick();

    // Wii U: 0x021c7584, PC: 0x004ab670
    void Run();

    // Wii U: 0x021c78f0, PC: TODO
    void Draw();

    // Wii U: 0x021c7508, PC: 0x004ab6e0
    void Shutdown();

    // Wii U: 0x021c74cc, PC: TODO
    void ShutdownCommon();

    // Wii U: 0x021c713c, PC: 0x004ab0e0
    Application();
};
}
