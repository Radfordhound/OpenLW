// TODO: The name of this file is correct, but the path was guessed!
#pragma once

namespace app
{
namespace fnd
{
class Message;
} // fnd

namespace ut
{
namespace internal
{
class HsmEvent
{
OPENLW_PRIVATE
    union
    {
        int m_integer;
        float m_float;
        fnd::Message* m_message;
        // TODO: m_object??
    };

public:
    // TODO: Is this function actually a thing?
    inline int getInt() const
    {
        return m_integer;
    }

    // TODO: Is this function actually a thing?
    inline float getDeltaTime() const
    {
        return m_float;
    }

    // TODO: Is this function actually a thing?
    inline fnd::Message& getMessage() const
    {
        return *m_message;
    }

    // TODO: Is this constructor actually a thing?
    inline HsmEvent(int integer) :
        m_integer(integer) {}

    // TODO: Is this constructor actually a thing?
    inline HsmEvent(float deltaTime) :
        m_float(deltaTime) {}

    // TODO: Is this constructor actually a thing?
    inline HsmEvent(fnd::Message& msg) :
        m_message(&msg) {}
};
} // internal
} // ut
} // app
