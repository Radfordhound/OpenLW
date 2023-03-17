// TODO: The name of this file is correct, but the path was guessed!
#include "ApplicationWiiU.h"
#include "../../Memory/GlobalAllocator.h"
#include <coreinit/filesystem.h>
#include <cstring>

namespace app
{
unsigned int ApplicationWiiU::SystemProcess::Process()
{
    // TODO
    return 0;
}

void ApplicationWiiU::SystemProcess::UserExit()
{
    // TODO
}

void ApplicationWiiU::SystemProcess::UserForground()
{
    // TODO
}

void ApplicationWiiU::SystemProcess::UserProcUIAcquired()
{
    // TODO
}

void ApplicationWiiU::SystemProcess::UserProcUIExit()
{
    // TODO
}

void ApplicationWiiU::SystemProcess::UserProcUIHBdenied()
{
    // TODO
}

void ApplicationWiiU::SystemProcess::UserProcUIRelease()
{
    // TODO
}

void ApplicationWiiU::SystemProcess::UserReleasing()
{
    // TODO
}

ApplicationWiiU::SystemProcess::SystemProcess()
{
    // TODO
}

ApplicationWiiU::SystemProcess::~SystemProcess()
{
    // TODO
}

ApplicationWiiU::ApplicationWiiU(const CreationParameterWiiU* creationParams)
{
    // TODO
}

bool ApplicationWiiU::CreateDevice()
{
    // TODO
    return false;
}

void ApplicationWiiU::DestroyDevice()
{
    // TODO
}

void ApplicationWiiU::InitializeBasic()
{
    Application::InitializeBasic();
    FSInit();
    SAVEInit();
    nn::act::Initialize();

    std::strcpy(m_rootDir, "/vol/content");

    // TODO
}

void ApplicationWiiU::ShutdownBasic()
{
    // TODO
}

void ApplicationWiiU::InitializeMain()
{
    // TODO
}

void ApplicationWiiU::ShutdownMain()
{
    // TODO
}

void ApplicationWiiU::RunCore(SyncTimer* timer)
{
    // TODO
}

namespace fw
{
void ParseCmdLine(int argc, char** argv, CreationParameterWiiU* creationParams)
{
    // TODO
}
}
}
