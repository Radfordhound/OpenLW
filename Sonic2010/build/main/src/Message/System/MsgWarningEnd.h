// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "Message/Message.h"

namespace app
{
namespace xgame
{
class MsgWarningEnd : public fnd::Message
{
public:
    LWAPI(0x022fd5dc, TODO)
    MsgWarningEnd* Clone() const;

    LWAPI(0x022fd650, TODO)
    MsgWarningEnd();

    LWAPI(0x022fd6a8, TODO)
    ~MsgWarningEnd();
};

LWAPI_STATIC_ASSERT_SIZE(MsgWarningEnd, 0x18)

#ifdef MESSAGE_DEFINITION
MsgWarningEnd* MsgWarningEnd::Clone() const
{
    return new MsgWarningEnd(*this);
}

MsgWarningEnd::~MsgWarningEnd() {}

MsgWarningEnd::MsgWarningEnd() :
    Message(MESSAGE_WARNING_END) {}
#endif
} // xgame
} // app
