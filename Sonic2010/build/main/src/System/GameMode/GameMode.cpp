#include "GameMode.h"
#include "../../OpenLW/CGame.h"
#include "../../OpenLW/game/GlobalAllocator.h"
#include "../../OpenLW/fnd/FileLoader.h"
#include "../../OpenLW/fnd/FileSystem.h"
#include "../../OpenLW/xgame/MessageSystem.h"

using namespace app::fnd;
using namespace app::game;
using namespace app::xgame;
using namespace csl::fnd;

namespace app
{
GameMode::~GameMode()
{
    // TODO
}

void GameMode::OnEnter(CGame& game)
{
    FileSystem& fileSystem = FileSystem::GetInstance();
    if (fileSystem.Cache)
    {
        fileSystem.Cache->OnEnterCache(Name);
    }

    // TODO
    //CreateService();
}

void GameMode::OnLeave(CGame& game)
{
    FileSystem& fileSystem = FileSystem::GetInstance();
    if (fileSystem.Cache)
    {
        fileSystem.Cache->OnLeaveCache();
    }
}

void GameMode::Update(CGame& game, const fnd::SUpdateInfo& updateInfo)
{
    // TODO
}

bool GameMode::ProcessMessage(CGame& game, fnd::Message& msg)
{
    return false;
}

bool GameMode::PreProcessMessage(CGame& game, fnd::Message& msg)
{
    return false;
}

void GameMode::InitializeGameMode(CGame& game)
{
    // TODO
}

bool GameMode::PreLoadFile(const char* filePath, int param_2)
{
    FileLoader& fileLoader = FileLoader::GetInstance();
    return fileLoader.PreLoadFile(filePath, param_2);
}

bool GameMode::LoadFile(const char* filePath, const fnd::FileLoaderParam& loaderParams)
{
    FileLoader& fileLoader = FileLoader::GetInstance();
    return fileLoader.LoadFile(filePath, loaderParams);
}

void GameMode::AdvanceSequence()
{
    MsgAdvanceSequence msg;
    Game->SendMessage(msg); // TODO: Does AdvanceSequence return this result?
}

void GameMode::ReleaseGameMode(CGame& game)
{
    // TODO
}

void GameMode::Destroy(CGame& game)
{
    // TODO
}

void* GameMode::operator new(std::size_t size)
{
    // Get a "default" allocator.
    IAllocator* allocator = GlobalAllocator::GetAllocator(ALLOCATOR_UNK_TWO);

    // Allocate a new GameMode of the given size.
    GameMode* obj = static_cast<GameMode*>(allocator->Alloc(size));

    // Construct the new GameMode if allocation succeeded and return.
    if (obj)
    {
        obj->m_size = static_cast<unsigned short>(size);
        obj->m_allocator = allocator;
    }

    return obj;
}

GameMode::GameMode() :
    Game(nullptr),
    field_0x10(0),
    Name("UnnamedMode"),
    field_0x18(0),
    SwitchListener(nullptr) {}
}
