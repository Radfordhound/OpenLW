// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "Message/Message.h"

namespace app
{
namespace xgame
{
class MsgIs2DMode : public fnd::Message
{
OPENLW_PRIVATE
    bool* m_is2DMode;

public:
    LWAPI(0x022f10f0, 0x005350a0)
    MsgIs2DMode* Clone() const;

    LWAPI(0x022f116c, 0x00534de0)
    MsgIs2DMode(bool& is2DMode);

    LWAPI(0x022f11d4, 0x0049a620)
    ~MsgIs2DMode();
};

LWAPI_STATIC_ASSERT_SIZE(MsgIs2DMode, 0x1C)

#ifdef MESSAGE_DEFINITION
MsgIs2DMode* MsgIs2DMode::Clone() const
{
    return new MsgIs2DMode(*this);
}

MsgIs2DMode::~MsgIs2DMode() {}

MsgIs2DMode::MsgIs2DMode(bool& is2DMode) :
    Message(MESSAGE_IS_2D_MODE),
    m_is2DMode(&is2DMode) {}
#endif
} // xgame
} // app
