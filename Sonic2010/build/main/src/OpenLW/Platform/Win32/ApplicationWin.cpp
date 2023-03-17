#include "ApplicationWin.h"
#include "DeviceWin.h"
#include "../../SyncTimer.h"
#include "csl/fnd/thread.h"
#include <cstring>
#include <d3d9.h>

using namespace app::hid;
using namespace csl::fnd;

namespace app
{
ApplicationWin* ApplicationWin::Instance = nullptr;

// Wii U: N/A, PC: 0x00401410
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Get HINSTANCE.
    static ApplicationWin* inst = nullptr;
    HINSTANCE hInst = reinterpret_cast<HINSTANCE>(
        GetWindowLongA(hWnd, GWL_HINSTANCE));

    // Switch based on message type.
    HANDLE icon16, icon32;
    switch (uMsg)
    {
    case WM_CREATE:
        inst = static_cast<ApplicationWin*>(
            reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);

        icon16 = LoadImageA(hInst, MAKEINTRESOURCEA(0x66), IMAGE_ICON, 16, 16, 0);
        icon32 = LoadImageA(hInst, MAKEINTRESOURCEA(0x66), IMAGE_ICON, 32, 32, 0);
        PostMessageA(hWnd, WM_SETICON, 0, reinterpret_cast<LPARAM>(icon16));
        PostMessageA(hWnd, WM_SETICON, 1, reinterpret_cast<LPARAM>(icon32));
        break;

    case WM_DESTROY:
        inst->Flags |= APP_WIN_FLAGS_SHOULD_CLOSE;
        PostQuitMessage(0);
        break;

    //case WM_SIZE:
    //    // TODO
    //    break;

    case WM_ACTIVATE:
        if (wParam == WA_INACTIVE)
        {
            inst->Flags &= 0xfffffffe;
            // TODO
        }
        else
        {
            inst->Flags |= 1;
            // TODO
        }
        break;

    //case WM_MOUSEFIRST:
    //    // TODO
    //    break;

        // TODO
    }

    // TODO
    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

bool ApplicationWin::CreateWindowWin(HINSTANCE hInstance, int nCmdShow,
    const char* className, const char* windowName, int width, int height)
{
    // Register window class.
    const WNDCLASSA wndClass =
    {
        CS_DBLCLKS,                                                     // Style
        WndProc,                                                        // lpfnWndProc
        0,                                                              // cbClsExtra
        0,                                                              // cbWndExtra
        hInstance,                                                      // hInstance
        LoadIcon(nullptr, IDI_APPLICATION),                             // hIcon
        LoadCursor(nullptr, IDC_ARROW),                                 // hCursor
        reinterpret_cast<HBRUSH>(GetStockObject(BLACK_BRUSH)),          // hbrBackground
        nullptr,                                                        // lpszMenuName
        className                                                       // lpszClassName
    };

    if (RegisterClassA(&wndClass))
    {
        // Setup window.
        RECT rect;
        Style = (WS_VISIBLE | WS_CAPTION | WS_SYSMENU | WS_GROUP | WS_TABSTOP);
        SetRect(&rect, 0, 0, width, height);
        AdjustWindowRect(&rect, Style, false);

        // Create window.
        HWND hWnd = CreateWindowExA(0, className, windowName, Style,
            CW_USEDEFAULT, CW_USEDEFAULT, rect.right - rect.left,
            rect.bottom - rect.top, nullptr, nullptr, hInstance, this);

        SurfaceHandle = hWnd;

        // Show window.
        if (hWnd)
        {
            ShowWindow(hWnd, nCmdShow);
            UpdateWindow(hWnd);
            InstHandle = hInstance;
            return true;
        }
    }

    // Window creation failed.
    return false;
}

bool ApplicationWin::CreateDevice()
{
    // Attempt to create window.
    if (!CreateWindowWin(CreationParams->Instance, 1, CreationParams->ClassName,
        CreationParams->WindowName, CreationParams->Width, CreationParams->Height))
    {
        MessageBoxA(nullptr, "Cannot create window", nullptr, MB_OK);
        return false;
    }

    // Attempt to create a D3D9 instance.
    if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &RsdxDevCore)))
    {
        MessageBoxA(nullptr, "Unable to initialize DirectX9", nullptr, MB_OK);
        return false;
    }

    // Attempt to get D3D9 device caps.
    UINT adapterToUse = 0;
    D3DDEVTYPE deviceType = D3DDEVTYPE_HAL;
    D3DCAPS9 caps;

    if (RsdxDevCore->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps) != D3D_OK)
    {
        MessageBoxA(nullptr, "Unable to get DirectX9 Caps", nullptr, MB_OK);
        return false;
    }

    // Ensure pixel shader version is 3.0 or higher.
    if (caps.PixelShaderVersion < D3DPS_VERSION(3, 0))
    {
        MessageBoxA(nullptr, "Version 3.0 or higher graphics card pixel shader required",
            nullptr, MB_OK);

        return false;
    }

    // Get adapter to use.
    UINT adapterCount = RsdxDevCore->GetAdapterCount();
    if (adapterCount)
    {
        for (UINT i = 0; i < adapterCount; ++i)
        {
            D3DADAPTER_IDENTIFIER9 identifier;
            RsdxDevCore->GetAdapterIdentifier(i, 0, &identifier);

            // Nvidia PerfHUD support
            if (std::strstr(identifier.Description, "NVPerfHUD") ||
                std::strstr(identifier.Description, "PerfHUD"))
            {
                deviceType = D3DDEVTYPE_REF;
                adapterToUse = i;
                break;
            }
        }
    }

    // Get display mode.
    D3DDISPLAYMODE displayMode;
    RsdxDevCore->GetAdapterDisplayMode(adapterToUse, &displayMode);

    // Get format.
    D3DFORMAT formats[] =
    {
        D3DFMT_X8R8G8B8,
        D3DFMT_A8R8G8B8,
        D3DFMT_R5G6B5
    };

    UINT formatToUse;
    UINT displayModes;

    for (formatToUse = 0; formatToUse < (sizeof(formats) / sizeof(D3DFORMAT)); ++formatToUse)
    {
        displayModes = RsdxDevCore->GetAdapterModeCount(
            adapterToUse, formats[formatToUse]);

        if (displayModes) break;
    }

    // TODO

    if (displayModes)
    {
        D3DDISPLAYMODE displayMode;
        RsdxDevCore->EnumAdapterModes(adapterToUse,
            formats[formatToUse], --displayModes,
            &displayMode);

        // TODO
    }

    // Create device.
    D3DPRESENT_PARAMETERS presentParams =
    {
        2,                                                              // BackBufferWidth
        2,                                                              // BackBufferHeight
        D3DFMT_A8R8G8B8,                                                // BackBufferFormat
        2,                                                              // BackBufferCount
        D3DMULTISAMPLE_NONE,                                            // MultiSampleType
        0,                                                              // MultiSampleQuality
        D3DSWAPEFFECT_DISCARD,                                          // SwapEffect
        reinterpret_cast<HWND>(SurfaceHandle),                          // hDeviceWindow
        true,                                                           // Windowed
        false,                                                          // EnableAutoDepthStencil
        D3DFMT_D24S8,                                                   // AutoDepthStencilFormat
        0,                                                              // Flags
        0,                                                              // FullScreen_RefreshRateInHz
        1                                                               // PresentationInterval
    };

    if (FAILED(RsdxDevCore->CreateDeviceEx(adapterToUse, deviceType,
        presentParams.hDeviceWindow, D3DCREATE_MULTITHREADED |
        D3DCREATE_HARDWARE_VERTEXPROCESSING, &presentParams,
        nullptr, &RsdxDevice)))
    {
        MessageBoxA(nullptr, "Cannot create Device", nullptr, MB_OK);
        return false;
    }

    // TODO
    return true;
}

void ApplicationWin::DestroyDevice()
{
    // TODO

    // Release device.
    if (RsdxDevice)
    {
        RsdxDevice->Release();
    }

    // Release device core.
    if (RsdxDevCore)
    {
        RsdxDevCore->Release();
    }

    // Free cursor from window and show it.
    ClipCursor(nullptr);
    ShowCursor(1);
}

void ApplicationWin::InitializeBasic()
{
    // TODO
}

void ApplicationWin::ShutdownBasic()
{
    // TODO
}

void ApplicationWin::InitializeMain()
{
    // Initialize base application.
    Application::InitializeMain();

    // Setup Windows Device.
    DeviceWin& devWin = DeviceWin::GetInstance();
    devWin.Setup(InstHandle, SurfaceHandle);
}

void ApplicationWin::ShutdownMain()
{
    Application::ShutdownMain();
}

void ApplicationWin::RunCore(SyncTimer* timer)
{
    while (!(Flags & APP_WIN_FLAGS_SHOULD_CLOSE))
    {
        UpdateInfo.DeltaTime = timer->Sync();
        ++UpdateInfo.CurFrameIndex;

        if (!(Flags & 4) || !(Flags & 1) || !(Flags & 8))
        {
            RunOnce(UpdateInfo);
        }
        else
        {
            ThreadSleep(10);
        }

        MSG msg;
        while (PeekMessageA(&msg, reinterpret_cast<HWND>(SurfaceHandle), 0, 0, 1))
        {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }

        CURSORINFO cursorInfo = { sizeof(CURSORINFO) };
        if (GetCursorInfo(&cursorInfo))
        {
            int r;
            if (--CursorTimer < 0)
            {
                if (Flags & 1)
                {
                    do
                    {
                        r = ShowCursor(false);
                    }
                    while (-1 < r);
                }
            }
            else if (Flags == 0)
            {
                do
                {
                    r = ShowCursor(true);
                }
                while (r < 0);
            }
        }

        // TODO: SteamAPI_RunCallbacks
    }
}

ApplicationWin::ApplicationWin(CreationParameterWin* creationParams) :
    Flags(0),
    Style(0),
    CreationParams(creationParams)
{
    CursorTimer = 120;
    Instance = this;
}

namespace fw
{
void ParseCmdLine(const char* args, CreationParameterWin* creationParams)
{
    // TODO
}
}
}
