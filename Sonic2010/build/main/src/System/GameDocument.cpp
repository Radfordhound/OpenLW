#include "pch.h"
#include "GameDocument.h"
#include "GameMode/GameMode.h"
#include "Game.h"

namespace app
{
GameDocument::GameDocument(GameMode* gameMode) :
    GameModePtr(gameMode),
    GameModeID(gameMode->Game->GetID())
    // TODO
{
    // TODO: Switch to the CHedgehogMemoryAllocatorHeap variant!!!
    World.reset(static_cast<CWorld*>(__HH_ALLOC_DBG(sizeof(CWorld)))); // line: 79

    // TODO
}
}
