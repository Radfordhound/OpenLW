// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "Message/Message.h"

namespace app
{
namespace xgame
{
class MsgAdvanceSequence : public fnd::Message
{
public:
    LWAPI(0x022fd6fc, TODO)
    MsgAdvanceSequence* Clone() const;

    LWAPI(0x022fd770, TODO)
    MsgAdvanceSequence();

    LWAPI(0x022fd7c8, TODO)
    ~MsgAdvanceSequence();
};

LWAPI_STATIC_ASSERT_SIZE(MsgAdvanceSequence, 0x18)

#ifdef MESSAGE_DEFINITION
MsgAdvanceSequence* MsgAdvanceSequence::Clone() const
{
    return new MsgAdvanceSequence(*this);
}

MsgAdvanceSequence::~MsgAdvanceSequence() {}

MsgAdvanceSequence::MsgAdvanceSequence() :
    Message(MESSAGE_ADVANCE_SEQUENCE) {}
#endif
} // xgame
} // app
