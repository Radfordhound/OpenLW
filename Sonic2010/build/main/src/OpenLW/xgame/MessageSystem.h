#pragma once
#include "../fnd/Message.h"

namespace app
{
namespace xgame
{
struct MsgWarningEnd : fnd::Message
{
    // Wii U: 0x022fd5dc, PC: TODO
    MsgWarningEnd* Clone() const;

    // Wii U: 0x022fd650, PC: TODO
    ~MsgWarningEnd();

    // Wii U: 0x022fd6a8, PC: TODO
    MsgWarningEnd();
};

struct MsgAdvanceSequence : fnd::Message
{
    // Wii U: 0x022fd6fc, PC: TODO
    MsgAdvanceSequence* Clone() const;

    // Wii U: 0x022fd7c8, PC: TODO
    ~MsgAdvanceSequence();

    // Wii U: 0x022fd770, PC: TODO
    MsgAdvanceSequence();
};
}
}
