#include "GameModeStartUp.h"
#include "../../OpenLW/fnd/Message.h"
#include "../../OpenLW/fnd/SUpdateInfo.h"
#include "../../OpenLW/fnd/FileSystem.h"
#include "../../OpenLW/fnd/FileLoader.h"
#include "../../OpenLW/xgame/DlcManager.h"

namespace app
{
GameModeStartUp::~GameModeStartUp()
{
    // TODO
}

void GameModeStartUp::OnEnter(CGame& game)
{
    GameMode::OnEnter(game);
    //GameMode::BlackOut(); // TODO: Un-comment this line
    InitFSM();
}

void GameModeStartUp::OnLeave(CGame& game)
{
    ShutdownFSM();
    GameMode::OnLeave(game);
}

void GameModeStartUp::Update(CGame& game, const fnd::SUpdateInfo& updateInfo)
{
    GameMode::Update(game, updateInfo);

    xgame::DlcManager* dlcMgr = xgame::DlcManager::GetInstance();
    dlcMgr->Update();

    DispatchFSM(event_t::CreateUpdate(updateInfo.DeltaTime));
}

bool GameModeStartUp::ProcessMessage(CGame& game, fnd::Message& msg)
{
    if (PreProcessMessage(game, msg))
        return true;

    if (msg.ID == WARNING_END)
    {
        ProcMsgWarningEnd(game, reinterpret_cast<xgame::MsgWarningEnd&>(msg));
        return true;
    }
    
    return GameMode::ProcessMessage(game, msg);
}

bool GameModeStartUp::PreProcessMessage(CGame& game, fnd::Message& msg)
{
    DispatchFSM(event_t::CreateMessage(msg));
    return msg.Received;
}

void GameModeStartUp::ProcMsgWarningEnd(CGame& game, xgame::MsgWarningEnd& msg)
{
    m_isWarningEnd = true;
}

bool GameModeStartUp::IsWarningEnd()
{
    return m_isWarningEnd;
}

bool GameModeStartUp::IsLoadEnd()
{
    fnd::FileLoader* fileLoader = fnd::FileLoader::GetInstance();
    return fileLoader->IsSyncCompleteAll();
}

void GameModeStartUp::PreLoadGame()
{
    // TODO
}

// TODO: This name was guessed. Is it good?
// TODO: Is this actually a uint??
static bool LoadLuaFiles = false;

// TODO: This name was guessed. Is it good?
static const char* ResidentFilePaths[] =
{
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    "sound/sonic2013.acf",
    "sound/bgm.acb",
    "sound/se_enemy_common.acb",
    "sound/se_object_common.acb",
    "sound/se_player_sonic.acb",
    "sound/se_system_2prace.acb",
    "sound/se_system_act.acb",
    "sound/se_system_common.acb",
    "sound/se_system_worldmap.acb",
    "fontdata.pac",
    "ui/ui_icon_pda.pac"
};

void GameModeStartUp::PreLoadResidentFile()
{
    // Add lua files to resident file paths if necessary.
    if (!LoadLuaFiles)
    {
        LoadLuaFiles = true;
        ResidentFilePaths[0] = "testmission.lua";
        ResidentFilePaths[1] = "actstgmission.lua";
        ResidentFilePaths[2] = "actstgdata.lua";
        ResidentFilePaths[3] = "omochaomission.lua";
    }

    // Load all resident files.
    for (int i = 0; i < (sizeof(ResidentFilePaths) / sizeof(*ResidentFilePaths)); ++i)
    {
        fnd::FileLoaderParam loaderParams;
        loaderParams.field_0xc = 0x1000;
        LoadFile(ResidentFilePaths[i], loaderParams);
    }

    // Pre-load text data for all languages.
    PreLoadFile("ui/text_common_e.pac", 0x4000);
    PreLoadFile("ui/text_common_f.pac", 0x4000);
    PreLoadFile("ui/text_common_g.pac", 0x4000);
    PreLoadFile("ui/text_common_i.pac", 0x4000);
    PreLoadFile("ui/text_common_j.pac", 0x4000);
    PreLoadFile("ui/text_common_s.pac", 0x4000);
}

void GameModeStartUp::LoadResidentFile()
{
    fnd::FileLoader* fileLoader = fnd::FileLoader::GetInstance();
    fileLoader->SetHintCache(nullptr);

    // TODO
}

void GameModeStartUp::ChangeState(state_t newState)
{
    FSM_TRAN(newState);
}

GameModeStartUp::state_t GameModeStartUp::StateFirstCpk(const event_t& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_UPDATE:
    {
        fnd::FileSystem* fileSystem = fnd::FileSystem::GetInstance();
        fnd::FileBinder* fileBinder = fileSystem->GetDefaultBinder();

        if (fileBinder->IsSyncCompleteAll())
        {
            ChangeState(&GameModeStartUp::StateLoadGame);
        }

        return nullptr;
    }

    case SIGNAL_ENTER:
    case SIGNAL_LEAVE:
        return nullptr;
    }

    return FSM_TOP();
}

GameModeStartUp::state_t GameModeStartUp::StateLoadGame(const event_t& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_UPDATE:
        if (IsLoadEnd())
        {
            ChangeState(&GameModeStartUp::StateLoadResidentFile);
        }
        return nullptr;

    case SIGNAL_ENTER:
        PreLoadGame();
        return nullptr;

    case SIGNAL_LEAVE:
        return nullptr;
    }

    return FSM_TOP();
}

GameModeStartUp::state_t GameModeStartUp::StateLoadResidentFile(const event_t& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_UPDATE:
        if (IsLoadEnd())
        {
            LoadResidentFile();
            ChangeState(&GameModeStartUp::StateMain);
        }
        return nullptr;

    case SIGNAL_ENTER:
        PreLoadResidentFile();
        return nullptr;

    case SIGNAL_LEAVE:
        return nullptr;
    }
    
    return FSM_TOP();
}

GameModeStartUp::state_t GameModeStartUp::StateMain(const event_t& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_UPDATE:
        if (IsLoadEnd())
        {
            LoadResidentFile();
            ChangeState(&GameModeStartUp::StateAfterLoad);
        }
        return nullptr;

    case SIGNAL_ENTER:
    case SIGNAL_LEAVE:
        return nullptr;
    }

    return FSM_TOP();
}

GameModeStartUp::state_t GameModeStartUp::StateAfterLoad(const event_t& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_UPDATE:
    {
        xgame::DlcManager* dlcMgr = xgame::DlcManager::GetInstance();
        if (dlcMgr->IsComplete() && IsLoadEnd())
        {
            AdvanceSequence();
        }
        return nullptr;
    }

    case SIGNAL_ENTER:
    case SIGNAL_LEAVE:
        return nullptr;
    }

    return FSM_TOP();
}

GameModeStartUp::GameModeStartUp() :
    TTinyFsm(&GameModeStartUp::StateFirstCpk),
    m_isWarningEnd(false)
{
    field_0x38 = nullptr;
}
}
