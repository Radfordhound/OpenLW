#pragma once
#include "ReferencedObject.h"
#include "Singleton.h"
#include <csl/ut/array.h>

namespace app
{
namespace fnd
{
class CMoviePlayer;

class CMovieSystem : public ReferencedObject, // size == 0x124
    public csl::fnd::Singleton<CMovieSystem>
{
    csl::ut::MoveArray<CMoviePlayer*> m_players;
    csl::fnd::IAllocator* m_playerAllocator;
    float field_0x20;
    char m_rootDir[256];

    // Wii U: 0x021a4300, PC: TODO
    void SetRootDirectory(const char* rootDir);

public:
    // Wii U: 0x021a43e8, PC: TODO
    void Initialize();

    // Wii U: 0x021a43ec, PC: TODO
    CMovieSystem();

    // Wii U: 0x021a4530, PC: TODO
    void Finalize();

    // Wii U: 0x021a462c, PC: TODO
    ~CMovieSystem();

    // Wii U: 0x021a4a68, PC: TODO
    CMoviePlayer* CreatePlayer();
};
}
}
