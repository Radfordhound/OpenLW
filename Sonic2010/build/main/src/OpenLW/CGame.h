#pragma once
#include "GameBase.h"
#include "../System/GameMode/GameMode.h"

namespace app
{
struct Application;
class CGameSequence;

class CGame : public GameBase // size == 0x7c
{
    ut::RefPtr<GameMode> m_gameMode;
    CGameSequence* m_gameSeq;
    // TODO
    float m_aspectRatio;

public:
    // TODO: Does CGame need an explicit destructor?

    // Wii U: 0x021c857c, PC: 0x004ac1b0
    bool PreProcessMessage(fnd::Message& msg);

    // Wii U: 0x021c8610, PC: 0x004abff0
    bool ProcessMessage(fnd::Message& msg);

    // Wii U: TODO, PC: TODO
    void Config(Application& app);

    // Wii U: 0x021c895c, PC: 0x004ac0a0
    void OnSetup(Application& app);

    // Wii U: TODO, PC: TODO
    void OnShutdown(Application& app);

    // Wii U: 0x021c8dd4, PC: 0x004ac3a0
    void Tick(Application& app);

    // Wii U: 0x021c8f2c, PC: TODO
    void Draw(Application& app);

    // Wii U: TODO, PC: TODO
    void AdvanceFrame();

    // Wii U: TODO, PC: TODO
    void CheckSuspend();

    // Wii U: TODO, PC: TODO
    void DelayDestroy();

    // Wii U: TODO, PC: TODO
    void DrawSync();

    // Wii U: TODO, PC: TODO
    void FlushFileLoad();

    // Wii U: 0x021c8fb4, PC: 0x004ac240
    void InitGameMode(GameMode* gameMode);

    // Wii U: TODO, PC: TODO
    void Pause();

    // Wii U: 0x021c9034, PC: 0x004ac290
    void ShutdownGameMode();

    // Wii U: TODO, PC: TODO
    void UpdateFlag(bool param_1);

    // Wii U: TODO, PC: TODO
    CGame();
};

// Wii U: 0x021c9200, PC: 0x004ac490
CGame* CreateGame(Application& app);

// Wii U: TODO, PC: TODO
void DestroyGame(GameBase* game);
}
