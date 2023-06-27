// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "Message/Message.h"

namespace app
{
namespace xgame
{
class MsgBeginBoost : public fnd::Message
{
public:
    LWAPI(NONE, NONE)
    MsgBeginBoost* Clone() const;

    LWAPI(NONE, NONE)
    MsgBeginBoost();

    LWAPI(NONE, NONE)
    ~MsgBeginBoost();
};

LWAPI_STATIC_ASSERT_SIZE(MsgBeginBoost, 0x18)

#ifdef MESSAGE_DEFINITION
MsgBeginBoost* MsgBeginBoost::Clone() const
{
    return new MsgBeginBoost(*this);
}

MsgBeginBoost::~MsgBeginBoost() {}

MsgBeginBoost::MsgBeginBoost() :
    Message(MESSAGE_BEGIN_BOOST) {}
#endif
} // xgame
} // app
