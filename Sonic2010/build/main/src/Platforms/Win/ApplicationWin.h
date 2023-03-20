// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "System/Application.h"

namespace app
{
struct CreationParameterWin
{
    HINSTANCE Instance;
    const char* ClassName;
    const char* WindowName;
    unsigned int Width;
    unsigned int Height;
    bool field_0x14;
    bool field_0x15;
    bool field_0x16;
    bool field_0x17;
};

enum APP_WIN_FLAGS
{
    APP_WIN_FLAGS_SHOULD_CLOSE = 2
    // TODO
};

struct ApplicationWin : Application // size == 292
{
    unsigned int CursorTimer;
    unsigned int Flags;
    DWORD Style;
    CreationParameterWin* CreationParams;

    LWAPI(NONE, 0x004010b0)
    static ApplicationWin* Instance;

    LWAPI(NONE, 0x00401410)
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    LWAPI(NONE, 0x00401900)
    bool CreateWindowWin(HINSTANCE hInstance, int nCmdShow, const char* className,
        const char* windowName, int width, int height);

    LWAPI(NONE, 0x00401c80)
    bool CreateDevice();

    LWAPI(NONE, 0x00402240)
    void DestroyDevice();

    LWAPI(NONE, 0x00401360)
    void InitializeBasic();

    LWAPI(NONE, 0x004013b0)
    void ShutdownBasic();

    LWAPI(NONE, 0x004013c0)
    void InitializeMain();

    LWAPI(NONE, 0x004013f0)
    void ShutdownMain();

    LWAPI(NONE, 0x00401100)
    void RunCore(SyncTimer* timer);

    LWAPI(NONE, 0x004010b0)
    ApplicationWin(CreationParameterWin* creationParams);
};

namespace fw
{
LWAPI(NONE, 0x00402730)
void ParseCmdLine(const char* args, CreationParameterWin* creationParams);
}
}
