#pragma once
#include "SyncTimer.h"
#include "CGame.h"
#include "fnd/SUpdateInfo.h"

namespace app
{
class Application // size == 276??
{
protected:
    fnd::SUpdateInfo updateInfo;
    // TODO: Data Members
    const char* rootDirectory = nullptr;
    // TODO: Data Members
    void* gfxInstHandle = nullptr;
    void* gfxDeviceHandle = nullptr;
    // TODO: Data Members
    void* instHandle = nullptr;
    void* surfaceHandle = nullptr;
    // TODO: Data Members
    CGame* game = nullptr;
    // TODO: Data Members

public:
    /*
        @brief Constructor for Application.
        <b>Wii U: 0x021c713c, PC: 0x004ab0e0</b>
    */
    Application();

    /*
        @brief Destructor for Application.
        <b>Wii U: 0x021c71fc, PC: 0x004ab160</b>
    */
    virtual ~Application();

    virtual bool CreateDevice() = 0;
    virtual void DestroyDevice() = 0;

    /* <b>Wii U: 0x021c743c, PC: 0x004ab690</b> */
    void Initialize();
    
    /* <b>Wii U: 0x021c7210, PC: 0x004ab360</b> */
    void InitializeCommon();

    /* <b>Wii U: 0x021c75d8, PC: 0x004ab190</b> */
    virtual void InitializeBasic();

    /* <b>Wii U: 0x021c7608, PC: 0x004ab1b0</b> */
    virtual void ShutdownBasic();

    /* <b>Wii U: 0x021c76ec, PC: 0x004ab1c0</b> */
    virtual void InitializeMain();

    /* <b>Wii U: 0x021c77c8, PC: 0x004ab2e0</b> */
    virtual void ShutdownMain();

    /* <b>Wii U: 0x021c7830, PC: 0x00d626a8 (GENERIC RETURN VOID)</b> */
    virtual void RunCore(SyncTimer* timer);

    /* <b>Wii U: 0x021c78bc, PC: TODO</b> */
    void RunOnce(const fnd::SUpdateInfo& updateInfo);

    /* <b>Wii U: 0x021c7834, PC: TODO</b> */
    void Poll(const fnd::SUpdateInfo& updateInfo);

    /* <b>Wii U: 0x021c78a4, PC: TODO</b> */
    void Tick();

    /* <b>Wii U: 0x021c7584, PC: 0x004ab670</b> */
    void Run();

    /* <b>Wii U: 0x021c78f0, PC: TODO</b> */
    void Draw();

    /* <b>Wii U: 0x021c7508, PC: 0x004ab6e0</b> */
    void Shutdown();

    /* <b>Wii U: 0x021c74cc, PC: TODO</b> */
    void ShutdownCommon();
};
}
