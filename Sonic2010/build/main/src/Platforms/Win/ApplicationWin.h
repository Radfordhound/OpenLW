// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "System/Application.h"

#define WIN32_LEAN_AND_MEAN
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

    // Wii U: N/A, PC: TODO
    static ApplicationWin* Instance;

    // Wii U: N/A, PC: 0x00401900
    bool CreateWindowWin(HINSTANCE hInstance, int nCmdShow, const char* className,
        const char* windowName, int width, int height);

    // Wii U: N/A, PC: 0x00401c80
    bool CreateDevice();

    // Wii U: N/A, PC: 0x00402240
    void DestroyDevice();

    // Wii U: N/A, PC: 0x00401360
    void InitializeBasic();

    // Wii U: N/A, PC: 0x004013b0
    void ShutdownBasic();

    // Wii U: N/A, PC: 0x004013c0
    void InitializeMain();

    // Wii U: N/A, PC: 0x004013f0
    void ShutdownMain();

    // Wii U: N/A, PC: 0x00401100
    void RunCore(SyncTimer* timer);

    // Wii U: N/A, PC: 0x004010b0
    ApplicationWin(CreationParameterWin* creationParams);
};

namespace fw
{
// Wii U: N/A, PC: 0x00402730
void ParseCmdLine(const char* args, CreationParameterWin* creationParams);
}
}
