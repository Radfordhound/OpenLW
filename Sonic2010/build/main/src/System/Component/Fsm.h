// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "TinyFsm.h"

namespace app
{
namespace Object
{
template<typename T>
class Event : public TTinyFsmEvent<T, Event<T>>
{
OPENLW_PRIVATE
    union
    {
        int m_integer;
        float m_float;
        fnd::Message* m_message;
        // TODO: m_object??
    };

    // TODO: Is this constructor actually a thing?
    inline Event(int signal) :
        TTinyFsmEvent<T, Event<T>>(signal) {}

    // TODO: Is this constructor actually a thing?
    inline Event(int signal, float deltaTime) :
        TTinyFsmEvent<T, Event<T>>(signal),
        m_float(deltaTime) {}

    // TODO: Is this constructor actually a thing?
    inline Event(int signal, fnd::Message& msg) :
        TTinyFsmEvent<T, Event<T>>(signal),
        m_message(&msg) {}

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

    // TODO: Is this function actually a thing?
    static inline Event<T> CreateSignal(int signal)
    {
        return Event<T>(signal);
    }

    // TODO: Is this function actually a thing?
    static inline Event<T> CreateSuper()
    {
        return CreateSignal(SIGNAL_SUPER);
    }

    // TODO: Is this function actually a thing?
    static inline Event<T> CreateInit()
    {
        return CreateSignal(SIGNAL_INIT);
    }

    // TODO: Is this function actually a thing?
    static inline Event<T> CreateEnter()
    {
        return CreateSignal(SIGNAL_ENTER);
    }

    // TODO: Is this function actually a thing?
    static inline Event<T> CreateLeave()
    {
        return CreateSignal(SIGNAL_LEAVE);
    }

    static inline Event<T> CreateUpdate(float deltaTime)
    {
        return Event<T>(SIGNAL_UPDATE, deltaTime);
    }

    static inline Event<T> CreateMessage(fnd::Message& msg)
    {
        return Event<T>(SIGNAL_MESSAGE, msg);
    }
};

// TODO: This class was guessed; does it actually exist?
template<typename T>
class Fsm
{
public:
    typedef TTinyFsm<T, Event<T>> Type;
};
} // Object

namespace GameModeUtil
{
template<typename T>
class Event : public TTinyFsmEvent<T, Event<T>>
{
OPENLW_PRIVATE
    union
    {
        int m_integer;
        float m_float;
        fnd::Message* m_message;
        // TODO: m_object??
    };

    // TODO: Is this constructor actually a thing?
    inline Event(int signal) :
        TTinyFsmEvent<T, Event<T>>(signal) {}

    // TODO: Is this constructor actually a thing?
    inline Event(int signal, float deltaTime) :
        TTinyFsmEvent<T, Event<T>>(signal),
        m_float(deltaTime) {}

    // TODO: Is this constructor actually a thing?
    inline Event(int signal, fnd::Message& msg) :
        TTinyFsmEvent<T, Event<T>>(signal),
        m_message(&msg) {}

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

    // TODO: Is this function actually a thing?
    static inline Event<T> CreateSignal(int signal)
    {
        return Event<T>(signal);
    }

    // TODO: Is this function actually a thing?
    static inline Event<T> CreateSuper()
    {
        return CreateSignal(SIGNAL_SUPER);
    }

    // TODO: Is this function actually a thing?
    static inline Event<T> CreateInit()
    {
        return CreateSignal(SIGNAL_INIT);
    }

    // TODO: Is this function actually a thing?
    static inline Event<T> CreateEnter()
    {
        return CreateSignal(SIGNAL_ENTER);
    }

    // TODO: Is this function actually a thing?
    static inline Event<T> CreateLeave()
    {
        return CreateSignal(SIGNAL_LEAVE);
    }

    static inline Event<T> CreateUpdate(float deltaTime)
    {
        return Event<T>(SIGNAL_UPDATE, deltaTime);
    }

    static inline Event<T> CreateMessage(fnd::Message& msg)
    {
        return Event<T>(SIGNAL_MESSAGE, msg);
    }
};

// TODO: This class was guessed; does it actually exist?
template<typename T>
class Fsm
{
public:
    typedef TTinyFsm<T, Event<T>> Type;
};
} // GameModeUtil
} // app
