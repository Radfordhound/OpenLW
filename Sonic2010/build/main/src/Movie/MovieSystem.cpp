#include "OpenLW/pch.h"
#include "MovieSystem.h"
#include "MoviePlayer.h"
#include "System/FileSystem.h"

using namespace csl::ut;
using namespace csl::fnd;

namespace app
{
namespace fnd
{
void CMovieSystem::SetRootDirectory(const char* rootDir)
{
    StringBuf<256> local_228(rootDir);
    if (!local_228.empty())
    {
        StringBuf<256> local_11c("");
        local_11c.copyFrom(local_228, 1, local_228.length() - 1, local_11c.length());

        if (local_11c != "/" && local_11c != "\\")
        {
            local_228.append("/");
        }
    }

    StrLcpy(m_rootDir, local_228, 256);
}

void CMovieSystem::Initialize() {}

CMovieSystem::CMovieSystem() :
    m_playerAllocator(m_allocator),
    field_0x20(1.0f)
{
    SetRootDirectory("");
}

CMovieSystem* CMovieSystem::Create(csl::fnd::IAllocator* allocator)
{
    return new (allocator) CMovieSystem();
}

void CMovieSystem::Finalize()
{
    if (m_players.size() != 0)
    {
        for (auto it = m_players.begin(); it != m_players.end(); ++it)
        {
            (*it)->DestroyImmediately();
        }
    }
    
    m_players.clear();
}

CMovieSystem::~CMovieSystem()
{
    Finalize();
}

CMoviePlayer* CMovieSystem::CreatePlayer()
{
    CMoviePlayer* player = new (m_playerAllocator) CMoviePlayer();
    if (player)
    {
        m_players.push_back(player);
    }
    
    return player;
}

void CMovieSystem::Setup(const char* movieDirectory)
{
    m_players.Reset(nullptr, 0, 0, m_playerAllocator, false);
    m_players.reserve(2);

    // Set root directory.
    auto& fileSystem = FileSystem::GetInstance();
    csl::ut::StringBuf<256> rootDirectory(fileSystem.RootDirectory);

    rootDirectory += movieDirectory;

    SetRootDirectory(rootDirectory);
}
} // fnd
} // app
