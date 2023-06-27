// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "Message/Message.h"

namespace app
{
namespace xgame
{
class MsgEndBoost : public fnd::Message
{
public:
    LWAPI(NONE, NONE)
    MsgEndBoost* Clone() const;

    LWAPI(NONE, NONE)
    MsgEndBoost();

    LWAPI(NONE, NONE)
    ~MsgEndBoost();
};

LWAPI_STATIC_ASSERT_SIZE(MsgEndBoost, 0x18)

#ifdef MESSAGE_DEFINITION
MsgEndBoost* MsgEndBoost::Clone() const
{
    return new MsgEndBoost(*this);
}

MsgEndBoost::~MsgEndBoost() {}

MsgEndBoost::MsgEndBoost() :
    Message(MESSAGE_END_BOOST) {}
#endif
} // xgame
} // app
