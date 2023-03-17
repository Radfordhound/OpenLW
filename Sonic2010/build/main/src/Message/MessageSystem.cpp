// TODO: The name of this file is correct, but the path was guessed!
#include "MessageSystem.h"

namespace app
{
namespace xgame
{
MsgWarningEnd* MsgWarningEnd::Clone() const
{
    return new MsgWarningEnd(*this);
}

MsgWarningEnd::~MsgWarningEnd() {}

MsgWarningEnd::MsgWarningEnd() :
    fnd::Message(WARNING_END) {}

MsgAdvanceSequence* MsgAdvanceSequence::Clone() const
{
    return new MsgAdvanceSequence(*this);
}

MsgAdvanceSequence::~MsgAdvanceSequence() {}

MsgAdvanceSequence::MsgAdvanceSequence() :
    fnd::Message(ADVANCE_SEQUENCE) {}
}
}
