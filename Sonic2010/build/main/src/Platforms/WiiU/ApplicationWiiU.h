// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "../../System/Application.h"
#include "../../System/ReferencedObject.h"

namespace app
{
struct CreationParameterWiiU
{
    unsigned int Width;
    unsigned int Height;
    // TODO
};

struct ApplicationWiiU : Application // size == 216
{
    class SystemProcess : public fnd::ReferencedObject // size == 32
    {
        // TODO

        // Wii U: 0x020020bc, PC: N/A
        unsigned int Process(); // TODO: Is this return type correct?

        // Wii U: 0x02001e90, PC: N/A
        void UserExit();

        // Wii U: 0x02001e88, PC: N/A
        void UserForground();

        // Wii U: 0x02001dbc, PC: N/A
        void UserProcUIAcquired();

        // Wii U: 0x020022b8, PC: N/A
        void UserProcUIExit();

        // Wii U: 0x02001e14, PC: N/A
        void UserProcUIHBdenied();

        // Wii U: 0x02001d8c, PC: N/A
        void UserProcUIRelease();

        // Wii U: 0x02001e44, PC: N/A
        void UserReleasing();

        // Wii U: 0x02001eec, PC: N/A
        SystemProcess();

        // Wii U: 0x02002214, PC: N/A
        ~SystemProcess() override;
    };

    CreationParameterWiiU* CreationParams;
    SystemProcess* SysProc;
    // TODO

    //static ApplicationWiiU* Instance; // TODO: Is this a thing?

    // Wii U: 0x02001b40, PC: N/A
    ApplicationWiiU(const CreationParameterWiiU* creationParams);

    // Wii U: 0x02001c04, PC: N/A
    bool CreateDevice() override;

    // Wii U: 0x02001d1c, PC: N/A
    void DestroyDevice() override;

    // Wii U: 0x02001fc0, PC: N/A
    void InitializeBasic() override;

    // Wii U: 0x02002040, PC: N/A
    void ShutdownBasic() override;

    // Wii U: 0x0200208c, PC: N/A
    void InitializeMain() override;

    // Wii U: 0x020020b4, PC: N/A
    void ShutdownMain() override;

    // Wii U: 0x02002174, PC: N/A
    void RunCore(SyncTimer* timer) override;
};

namespace fw
{
// Wii U: 0x02002850, PC: N/A
void ParseCmdLine(int argc, char** argv, CreationParameterWiiU* creationParams);
}
}
