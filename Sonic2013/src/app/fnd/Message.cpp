#include "Message.h"

namespace app
{
namespace fnd
{
Message* Message::Clone() const
{
    return new Message(*this);
}

Message::Message(unsigned int type) : Type(type) {}
}
}

