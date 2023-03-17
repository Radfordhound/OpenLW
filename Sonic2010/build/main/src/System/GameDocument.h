#pragma once
#include "WorldHH.h"
#include "ReferencedObject.h"
#include <csl/ut/noncopyable.h>
#include <boost/scoped_ptr.hpp>

namespace app
{
struct GameMode;

struct GameDocument : public fnd::ReferencedObject, // size == 0xDC
    public csl::ut::NonCopyable
{
    GameMode* GameModePtr;
    unsigned int GameModeID;
    boost::scoped_ptr<CWorld> World;
    // TODO: Other data members.

    // Wii U: 0x02a7ec20, PC: TODO
    GameDocument(GameMode* gameMode);
};
}
