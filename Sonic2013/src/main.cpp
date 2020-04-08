#ifdef _WIN32
#include "app/ApplicationWin.h"

// =======================================================
// == Windows entry-point
// =======================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR pCmdLine, int nCmdShow)
{
    // Create mutex
    HANDLE hMutex = CreateMutex(nullptr, true, TEXT("Sonic2013Mutex"));
    if (GetLastError() != ERROR_ALREADY_EXISTS)
    {
        // Parse command-line arguments
        static const char* appName = "Sonic Lost World";
        app::CreationParameterWin creationParams =
        {
            hInstance,      // Instance
            appName,        // TODO
            appName,        // TODO
            1280,           // Width
            720,            // Height
            true            // TODO
        };

        app::fw::ParseCmdLine(pCmdLine, &creationParams);

        // Create instance of application
        app::ApplicationWin app = app::ApplicationWin(&creationParams);
        app.Initialize();

        // Run application
        app.Run();

        // Shutdown application and close
        app.Shutdown();
        ReleaseMutex(hMutex);
        return 0;
    }

    // If another instance is already running, focus it and shut this instance down
    HWND hWnd = FindWindowA("Sonic Lost World", nullptr);
    if (hWnd)
    {
        if (IsIconic(hWnd))
        {
            OpenIcon(hWnd);
            ReleaseMutex(hMutex);
            return -1;
        }

        SetForegroundWindow(hWnd);
    }

    ReleaseMutex(hMutex);
    return -1;
}
#else

// =======================================================
// == Non-Windows entry-point
// =======================================================
#error Non-Windows platforms are not currently supported
#endif
