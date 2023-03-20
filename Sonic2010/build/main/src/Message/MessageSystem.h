// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "Message.h"

namespace app
{
namespace xgame
{
struct MsgWarningEnd : fnd::Message
{
    LWAPI(0x022fd5dc, TODO)
    MsgWarningEnd* Clone() const;

    LWAPI(0x022fd650, TODO)
    ~MsgWarningEnd();

    LWAPI(0x022fd6a8, TODO)
    MsgWarningEnd();
};

struct MsgAdvanceSequence : fnd::Message
{
    LWAPI(0x022fd6fc, TODO)
    MsgAdvanceSequence* Clone() const;

    LWAPI(0x022fd7c8, TODO)
    ~MsgAdvanceSequence();

    LWAPI(0x022fd770, TODO)
    MsgAdvanceSequence();
};
}
}
