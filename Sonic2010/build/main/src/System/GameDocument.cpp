#include "OpenLW/pch.h"
#include "GameDocument.h"
#include "GameMode/GameMode.h"
#include "Game.h"

namespace app
{
GameDocument::~GameDocument()
{
    // TODO
}

GameDocument::GameDocument(GameMode* gameMode) :
    gameModePtr(gameMode),
    gameModeID(gameMode->Game->GetID())
    // TODO
{
    // TODO: Switch to the CHedgehogMemoryAllocatorHeap variant!!!
    world.reset(static_cast<CWorld*>(__HH_ALLOC_DBG(sizeof(CWorld)))); // line: 79

    // TODO
}
} // app
