// TODO: The name of this file is correct, but the path was guessed!
// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once
#include "ReferencedObject.h"
#include "LeafActor.h"

namespace app
{
class GameDocument;

namespace game
{
class LuaScript;
} // game

namespace fnd
{
class GameServiceClass;

class GameService : public ReferencedObject,
    public CLeafActor
{
OPENLW_PROTECTED
    friend GameServiceClass;

    GameDocument* m_owner;
    const GameServiceClass* m_class;
    void* m_unknown1;
    void* m_unknown2;
    unsigned int m_flags;

public:
    struct ServiceType
    {
        // TODO
    };

    LWAPI(0x02000c04, 0x004a1bf0)
    bool ActorProc(int id, void* data);

    LWAPI(0x02012f44, TODO)
    virtual void ResolveAccessibleService(GameDocument& param_1);

    LWAPI(0x02000c80, TODO)
    virtual void Load();

    LWAPI(0x02000c84, TODO)
    virtual void EndLoad();

    LWAPI(0x02000c88, TODO)
    virtual void PrepareToStartGame(bool param_1);

    LWAPI(0x02000c8c, TODO)
    virtual void StartGame(bool param_1);

    LWAPI(0x02000c90, TODO)
    virtual void InitByScript(game::LuaScript& param_1);

    LWAPI(0x020e8720, TODO)
    virtual void OnAddedToGame();

    LWAPI(0x0207a1e4, TODO)
    virtual void OnRemovedFromGame();

    LWAPI(0x02000c94, TODO)
    virtual void UpdateFinal(const SUpdateInfo& param_1);

    LWAPI(0x021b4680, 0x004a1cb0)
    ~GameService();

    LWAPI(0x021b47a4, TODO)
    GameService(ServiceType param_1);
};
} // fnd
} // app
