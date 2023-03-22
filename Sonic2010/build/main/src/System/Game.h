#pragma once
#include "GameBase.h"
#include "GameMode/GameMode.h"

namespace app
{
struct Application;
class CGameSequence;

/**
 * @brief The cslib allocator used for the game.
 *
 * NOTE: This data appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
*/
LWAPI(0x102e7f14, 0x00fd735c)
extern csl::fnd::IAllocator* GameAllocator;

class CGame : public GameBase // size == 0x7c
{
OPENLW_PRIVATE
    ut::RefPtr<GameMode> m_gameMode;
    CGameSequence* m_gameSeq;
    // TODO
    float m_aspectRatio;

public:
    // TODO: Does CGame need an explicit destructor?

    LWAPI(0x021c857c, 0x004ac1b0)
    bool PreProcessMessage(fnd::Message& msg);

    LWAPI(0x021c8610, 0x004abff0)
    bool ProcessMessage(fnd::Message& msg);

    LWAPI(TODO, TODO)
    void Config(Application& app);

    LWAPI(0x021c895c, 0x004ac0a0)
    void OnSetup(Application& app);

    LWAPI(TODO, TODO)
    void OnShutdown(Application& app);

    LWAPI(0x021c8dd4, 0x004ac3a0)
    void Tick(Application& app);

    LWAPI(0x021c8f2c, TODO)
    void Draw(Application& app);

    LWAPI(TODO, TODO)
    void AdvanceFrame();

    LWAPI(TODO, TODO)
    void CheckSuspend();

    LWAPI(TODO, TODO)
    void DelayDestroy();

    LWAPI(TODO, TODO)
    void DrawSync();

    LWAPI(TODO, TODO)
    void FlushFileLoad();

    LWAPI(0x021c8fb4, 0x004ac240)
    void InitGameMode(GameMode* gameMode);

    LWAPI(TODO, TODO)
    void Pause();

    LWAPI(0x021c9034, 0x004ac290)
    void ShutdownGameMode();

    LWAPI(TODO, TODO)
    void UpdateFlag(bool param_1);

    LWAPI(TODO, TODO)
    CGame();
};

LWAPI(0x021c9200, 0x004ac490)
CGame* CreateGame(Application& app);

LWAPI(TODO, TODO)
void DestroyGame(GameBase* game);
}
