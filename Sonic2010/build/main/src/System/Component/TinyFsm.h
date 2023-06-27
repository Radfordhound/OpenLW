#pragma once
#include <cstddef>

namespace app
{
namespace fnd
{
class Message;
} // fnd

template<typename T, typename _EventType>
class TTinyFsmEvent
{
OPENLW_PRIVATE
    int m_sig;

public:
    typedef _EventType EventType;

    int getSignal() const
    {
        return m_sig;
    }

    // TODO: Is this constructor actually a thing?
    inline TTinyFsmEvent(int signal) : m_sig(signal) {}
};

enum TiFsmBasicEventSignal // TODO: This name was guessed. Is it good?
{
    // TODO: These names were guessed. Are they good?

    SIGNAL_SUPER = -1,
    SIGNAL_INIT = -2,
    SIGNAL_ENTER = -3,
    SIGNAL_LEAVE = -4,

    SIGNAL_UPDATE = 0,
    SIGNAL_MESSAGE = 1
};

template<typename T>
class TiFsmBasicEvent : public TTinyFsmEvent<T, TiFsmBasicEvent<T>>
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
    inline TiFsmBasicEvent(int signal) :
        TTinyFsmEvent<T, TiFsmBasicEvent<T>>(signal) {}

    // TODO: Is this constructor actually a thing?
    inline TiFsmBasicEvent(int signal, float deltaTime) :
        TTinyFsmEvent<T, TiFsmBasicEvent<T>>(signal),
        m_float(deltaTime) {}

    // TODO: Is this constructor actually a thing?
    inline TiFsmBasicEvent(int signal, fnd::Message& msg) :
        TTinyFsmEvent<T, TiFsmBasicEvent<T>>(signal),
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
    static inline TiFsmBasicEvent<T> CreateSignal(int signal)
    {
        return TiFsmBasicEvent<T>(signal);
    }

    // TODO: Is this function actually a thing?
    static inline TiFsmBasicEvent<T> CreateSuper()
    {
        return CreateSignal(SIGNAL_SUPER);
    }

    // TODO: Is this function actually a thing?
    static inline TiFsmBasicEvent<T> CreateInit()
    {
        return CreateSignal(SIGNAL_INIT);
    }

    // TODO: Is this function actually a thing?
    static inline TiFsmBasicEvent<T> CreateEnter()
    {
        return CreateSignal(SIGNAL_ENTER);
    }

    // TODO: Is this function actually a thing?
    static inline TiFsmBasicEvent<T> CreateLeave()
    {
        return CreateSignal(SIGNAL_LEAVE);
    }

    static inline TiFsmBasicEvent<T> CreateUpdate(float deltaTime)
    {
        return TiFsmBasicEvent<T>(SIGNAL_UPDATE, deltaTime);
    }

    static inline TiFsmBasicEvent<T> CreateMessage(fnd::Message& msg)
    {
        return TiFsmBasicEvent<T>(SIGNAL_MESSAGE, msg);
    }
};

template<typename T, typename _EventType = TiFsmBasicEvent<T>, bool IsHierarchical = false>
class TTinyFsm;

template<typename T, typename _EventType = TiFsmBasicEvent<T>>
class TTinyFsmState
{
public:
    typedef _EventType EventType;
    typedef TTinyFsmState<T, EventType> ThisType;
    typedef ThisType (T::*EventFunc)(const EventType& e);

OPENLW_PRIVATE
    EventFunc m_delegate;

public:
    //// TODO: Is this function actually a thing?
    //inline bool IsValid() const
    //{
    //    return (m_delegate != nullptr);
    //}

    //// TODO: Is this function actually a thing?
    //inline void Clear()
    //{
    //    m_delegate = nullptr;
    //}

    //// TODO: Is this function actually a thing?
    //inline ThisType Call(T* obj, const EventType& e)
    //{
    //    return (obj->*m_delegate)(e);
    //}

    inline operator EventFunc() const
    {
        return m_delegate;
    }

    //// TODO: Is this function actually a thing?
    //inline bool operator==(const ThisType& other) const
    //{
    //    return (m_delegate == other.m_delegate);
    //}

    //// TODO: Is this function actually a thing?
    //inline bool operator!=(const ThisType& other) const
    //{
    //    return (m_delegate != other.m_delegate);
    //}

    //// TODO: Is this function actually a thing?
    //inline bool operator==(const EventFunc& eventFunc) const
    //{
    //    return (m_delegate == eventFunc);
    //}

    //// TODO: Is this function actually a thing?
    //inline bool operator!=(const EventFunc& eventFunc) const
    //{
    //    return (m_delegate != eventFunc);
    //}
    
    inline TTinyFsmState() :
        m_delegate(nullptr) {}

    inline TTinyFsmState(EventFunc eventFunc) :
        m_delegate(eventFunc) {}
};

template<typename T, typename _EventType, bool IsHierarchical>
class TTinyFsm
{
public:
    typedef _EventType EventType;
    typedef TTinyFsm<T, EventType, IsHierarchical> ThisType;
    typedef TTinyFsmState<T, EventType> StateType;
    typedef typename StateType::EventFunc EventFunc;

OPENLW_PRIVATE
    // TODO: I might have gotten the m_cur and m_src names mixed up actually lol.
    // Regardless this is functionally still accurate to what LW actually does.
    StateType m_cur;
    StateType m_src;

    // TODO: Is this function actually a thing?
    inline StateType Trigger(EventFunc state, const EventType& e)
    {
        return (static_cast<T*>(this)->*state)(e);
    }

    // TODO: Is this function actually a thing?
    inline StateType Super(EventFunc state)
    {
        return Trigger(state, EventType::CreateSuper());
    }

    // TODO: Is this function actually a thing?
    inline StateType Init(EventFunc state)
    {
        return Trigger(state, EventType::CreateInit());
    }

    // TODO: Is this function actually a thing?
    inline void Enter(EventFunc state)
    {
        Trigger(state, EventType::CreateEnter());
    }

    // TODO: Is this function actually a thing?
    inline void Leave(EventFunc state)
    {
        Trigger(state, EventType::CreateLeave());
    }

    StateType _top(const EventType& e) // TODO: Is this actually defined by the user of this class?
    {
        return StateType();
    }

    // TODO: Is this function actually a thing? It appears to
    // always be inlined in the Wii U version but is present on
    // PC, so we have no symbols for it.
    inline void UnknownFunc()
    {
        while (Init(m_src) == nullptr)
        {
            Enter(m_src);
        }
    }

public:
    StateType FSM_TOP() const
    {
        return StateType(&ThisType::_top); // TODO: Is this correct?
    }

    void FSM_INIT(StateType initialState)
    {
        m_src = initialState;
    }

    void FSM_TRAN(StateType state)
    {
        if (IsHierarchical)
        {
            // Leave all events from all states.
            for (EventFunc e = m_cur; e != m_src; e = Super(e))
            {
                Leave(e);
            }

            if (m_cur == state)
            {
                Leave(m_cur);
                Enter(state);
            }
            else
            {
                // TODO: It seems the "stateStack" stuff is actually, like, a csl implace move array or something??

                // Call the current state and all of its base states.
                StateType stateStack[5];
                StateType tinyFsmState = m_cur;
                int i = 0;

                while (tinyFsmState != FSM_TOP())
                {
                    stateStack[i++] = tinyFsmState;
                    tinyFsmState = Super(tinyFsmState);
                }

                // Call the new state and all of its base states.
                StateType stateStack2[5];
                StateType tinyFsmState2 = state;
                int i2 = 0;

                while (tinyFsmState2 != FSM_TOP())
                {
                    stateStack2[i2++] = tinyFsmState2;
                    tinyFsmState2 = Super(tinyFsmState2);
                }

                StateType* firstUnique1 = &stateStack[i];
                StateType* firstUnique2 = &stateStack2[i2];

                while (firstUnique1 != stateStack && firstUnique2 != stateStack2 &&
                    *firstUnique1 == nullptr || firstUnique1 == firstUnique2)
                {
                    --firstUnique1;
                    --firstUnique2;
                }

                StateType* curPtr = stateStack;
                while (curPtr != firstUnique1)
                {
                    Leave(*(curPtr++));
                }

                while (firstUnique2 != stateStack2)
                {
                    Enter(*(firstUnique2--));
                }

                // TODO: Destructor of the implace move array or whatever goes here.
            }

            m_src = state;
            UnknownFunc();
        }
        else
        {
            Leave(m_src);
            Enter(state);
            m_src = state;
        }
    }

    void FSM_SETSTATE(StateType state)
    {
        m_cur = m_src;
        FSM_TRAN(state);
    }

    void InitFSM()
    {
        if (IsHierarchical)
        {
            // Call super event on all source states.
            StateType stateStack[5];
            StateType tinyFsmState = m_src;
            int i = 0;

            while (tinyFsmState != FSM_TOP())
            {
                stateStack[i++] = tinyFsmState;
                tinyFsmState = Super(tinyFsmState);
            }

            // Call enter event on all source states in reverse order.
            StateType* curPtr = &stateStack[i];
            while (curPtr-- != stateStack)
            {
                Enter(*curPtr);
            }

            UnknownFunc();
        }
        else
        {
            Enter(m_src);
        }
    }

    void DispatchFSM(const EventType& e)
    {
        if (IsHierarchical)
        {
            m_cur = m_src;
            while (m_cur)
            {
                StateType tinyFsmState = Trigger(m_cur, e);
                if (!tinyFsmState) break;

                m_cur = Super(m_cur);
            }
        }
        else
        {
            Trigger(m_src, e);
        }
    }

    void ShutdownFSM()
    {
        if (IsHierarchical)
        {
            // TODO (Check 0x02a7f190 to implement this)
            __debugbreak();
        }
        else
        {
            if (m_src != FSM_TOP())
            {
                Leave(m_src);
                m_src = FSM_TOP();
            }
        }
    }

    TTinyFsm(StateType param_1) :
        m_cur(FSM_TOP()),
        m_src(param_1) {}

    virtual ~TTinyFsm()
    {
        // TODO: Does the "default" virtual destructor have a body?
    }
};
} // app
