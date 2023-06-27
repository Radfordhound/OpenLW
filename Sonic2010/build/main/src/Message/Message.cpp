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
    id(id),
    sender(0),
    receiver(0),
    received(false),
    broadcasted(false),
    mask(UINT_MAX) {}
} // fnd
} // app

