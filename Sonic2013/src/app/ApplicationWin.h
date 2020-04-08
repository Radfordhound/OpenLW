#pragma once
#include "Application.h"
#include <windows.h>

namespace app
{
struct CreationParameterWin
{
    HINSTANCE Instance;
    const char* ClassName;
    const char* WindowName;
    unsigned int Width;
    unsigned int Height;
    bool Fx14;
    bool Fx15;
    bool Fx16;
    bool Fx17;
};

enum APP_WIN_FLAGS
{
    APP_WIN_FLAGS_SHOULD_CLOSE = 2
    // TODO
};

class ApplicationWin : public Application // size == 292
{
public:
    unsigned int CursorTimer;
    unsigned int Flags;
    DWORD Style;
    CreationParameterWin* CreationParams;

    bool CreateWindowWin(HINSTANCE hInstance, int nCmdShow, const char* className,
        const char* windowName, int width, int height);

    /*
        @brief Constructor for ApplicationWin.
        <b>Wii U: N/A (ApplicationWiiU __ct: 0x02001b40), PC: 004010b0</b>
    */
    ApplicationWin(CreationParameterWin* creationParams);

    /* <b>Wii U: 0x02001c04, PC: 0x00401c80</b> */
    bool CreateDevice() override;

    /* <b>Wii U: 0x02001d1c, PC: 0x00402240</b> */
    void DestroyDevice() override;

    /* <b>Wii U: 0x02001fc0, PC: 0x00401360</b> */
    void InitializeBasic() override;

    /* <b>Wii U: 0x02002040, PC: 0x004013b0</b> */
    void ShutdownBasic() override;

    /* <b>Wii U: 0x0200208c, PC: 0x004013c0</b> */
    void InitializeMain() override;

    /* <b>Wii U: 0x020020b4, PC: 0x004013f0</b> */
    void ShutdownMain() override;

    /* <b>Wii U: 0x02002174, PC: 0x00401100</b> */
    void RunCore(SyncTimer* timer) override;
};

namespace fw
{
    /* <b>Wii U: TODO, PC: TODO</b> */
    void ParseCmdLine(const char* args, CreationParameterWin* creationParams);
}
}
