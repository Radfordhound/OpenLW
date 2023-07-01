﻿// TODO: The name of this file is correct, but the path was guessed!
// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once
#include "GameObject.h"

namespace app
{
namespace fnd
{
class Message;
} // fnd

namespace xgame
{
class MsgDeactivate;
class MsgGetPosition;
class MsgGetRotation;
class MsgActivateObjectDebugWindow;
} // xgame

class GameObject3D : public GameObject
{
OPENLW_PROTECTED
    unsigned char m_padding1[0x250];

public:
    LWAPI(0x02220894, TODO)
    bool ProcessMessage(fnd::Message& msg);

    LWAPI(0x02a7eef0, TODO)
    ~GameObject3D();

    LWAPI(0x02a7eef8, TODO)
    void ProcMsgDeactivate(xgame::MsgDeactivate& msg);

    LWAPI(0x02a7ef18, TODO)
    void ProcMsgGetPosition(xgame::MsgGetPosition& msg);

    LWAPI(0x02a7ef3c, TODO)
    void ProcMsgGetRotation(xgame::MsgGetRotation& msg);

    LWAPI(0x02a7ef58, TODO)
    void ProcMsgActivateObjectDebugWindow(xgame::MsgActivateObjectDebugWindow& msg);

    LWAPI(0x02a7f0c8, TODO)
    GameObject3D();
};

LWAPI_STATIC_ASSERT_SIZE(GameObject3D, 0x320)
} // app
