#include "pch.h"
#include "MovieSystem.h"
#include "MoviePlayer.h"

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
}
}
