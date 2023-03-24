#include "OpenLW/pch.h"
#include "Message.h"

namespace app
{
namespace fnd
{
Message* Message::Clone() const
{
    return new Message(*this);
}

Message::~Message() {}

Message::Message(const int id) :
    ID(id)
{
    Sender = 0;
    Receiver = 0;
    Received = false;
    Broadcasted = false;
    Mask = UINT_MAX;
}
}
}

