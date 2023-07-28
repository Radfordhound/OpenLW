#pragma once
#include "System/ReferencedObject.h"
#include "System/Singleton.h"
#include <csl/ut/array.h>

namespace app
{
namespace fnd
{
class CMoviePlayer;

class CMovieSystem : public ReferencedObject, // size == 0x124
    public csl::fnd::Singleton<CMovieSystem>
{
OPENLW_PRIVATE
    csl::ut::MoveArray<CMoviePlayer*> m_players;
    csl::fnd::IAllocator* m_playerAllocator;
    float field_0x20;
    char m_rootDir[256];

    LWAPI(0x021a4300, TODO)
    void SetRootDirectory(const char* rootDir);

public:
    LWAPI(0x021a43e8, TODO)
    void Initialize();

    LWAPI(0x021a43ec, TODO)
    CMovieSystem();

    LWAPI(0x021a4468, TODO)
    static CMovieSystem* Create(csl::fnd::IAllocator* allocator);

    LWAPI(0x021a4530, TODO)
    void Finalize();

    LWAPI(0x021a462c, TODO)
    ~CMovieSystem();

    LWAPI(0x021a4a68, TODO)
    CMoviePlayer* CreatePlayer();

    LWAPI(0x021a493c, TODO)
    void Setup(const char* movieDirectory);
};
} // fnd
} // app
