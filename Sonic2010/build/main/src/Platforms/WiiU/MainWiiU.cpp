// TODO: The name of this file is correct, but the path was guessed!
#include "ApplicationWiiU.h"

// Wii U: 0x020028D4, PC: N/A
int main(int argc, const char* argv[])
{
    // Parse command-line arguments.
    app::CreationParameterWiiU creationParams =
    {
        1280,                                                           // Width
        720                                                             // Height
        // TODO
    };

    app::fw::ParseCmdLine(argc, argv, &creationParams);

    // Create instance of application.
    app::ApplicationWiiU app(&creationParams);
    app.Initialize();

    // Run application.
    app.Run();

    // Shutdown application and close.
    app.Shutdown();
    return 0;
}
