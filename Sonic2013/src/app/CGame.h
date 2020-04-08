#pragma once
#include "GameBase.h"
#include "GameMode.h"

namespace app
{
class Application;
class CGame : public GameBase // size == 0x7c
{
    // TODO: Data Members
public:
    /*
        @brief Constructor for CGame.
        <b>Wii U: TODO, PC: TODO</b>
    */
    CGame();

    // TODO: Does CGame need an explicit destructor?

    /* <b>Wii U: TODO, PC: TODO</b> */
    void Config(Application& app) override;

    /* <b>Wii U: TODO, PC: 0x004ac0a0</b> */
    void OnSetup(Application& app) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    void OnShutdown(Application& app) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    void Tick(Application& app) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    void Draw(Application& app) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    // TODO: Is return type correct?
    unsigned int ProcessMessage(fnd::Message& msg) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    // TODO: Is return type correct?
    unsigned int PreProcessMessage(fnd::Message& msg) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    void AdvanceFrame();

    /* <b>Wii U: TODO, PC: TODO</b> */
    void CheckSuspend();

    /* <b>Wii U: TODO, PC: TODO</b> */
    void DelayDestroy();

    /* <b>Wii U: TODO, PC: TODO</b> */
    void DrawSync();

    /* <b>Wii U: TODO, PC: TODO</b> */
    void FlushFileLoad();

    /* <b>Wii U: TODO, PC: TODO</b> */
    void InitGameMode(GameMode* gameMode);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void Pause();

    /* <b>Wii U: TODO, PC: TODO</b> */
    void ShutdownGameMode();

    /* <b>Wii U: TODO, PC: TODO</b> */
    void UpdateFlag(bool param_1);
};

/* <b>Wii U: 0x021c9200, PC: 0x004ac490</b> */
CGame* CreateGame(Application& app);
}
