#pragma once
#include "WorldHH.h"
#include "ReferencedObject.h"
#include <csl/ut/noncopyable.h>
#include <boost/scoped_ptr.hpp>

namespace app
{
struct GameMode;

class GameDocument : public fnd::ReferencedObject, // size == 0xDC
    public csl::ut::NonCopyable
{
public:
    GameMode* gameModePtr;
    unsigned int gameModeID;
    boost::scoped_ptr<CWorld> world;
    // TODO: Other data members.

    LWAPI(0x02a7ec20, TODO)
    GameDocument(GameMode* gameMode);
};
}
