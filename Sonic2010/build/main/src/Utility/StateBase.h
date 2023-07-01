// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "Hsm.h"
#include "System/ReferencedObject.h"

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
class StateImpl : public fnd::ReferencedObject
{
    // TODO: This seems to be empty, is this correct?
};
} // internal

template<class T>
class StateBase : public internal::StateImpl
{
public:
    virtual bool Trigger(void* param_1, int param_2, internal::HsmEvent& param_3)
    {
        switch (param_2)
        {
        case 1:
            return Init(*static_cast<T*>(param_1));

        case 2:
            Enter(*static_cast<T*>(param_1), param_3.getInt());
            return true;

        case 3:
            Leave(*static_cast<T*>(param_1), param_3.getInt());
            return true;

        case 4:
            return Update(*static_cast<T*>(param_1), param_3.getDeltaTime());

        case 5:
            return ProcessMessage(*static_cast<T*>(param_1), param_3.getMessage());

        default:
            return false;
        }
    }

    virtual bool Init(T& obj)
    {
        return false;
    }

    virtual void Enter(T& obj, int param_2) {}

    virtual void Leave(T& obj, int param_2) {}

    virtual bool Update(T& obj, float dt)
    {
        return false;
    }

    virtual bool ProcessMessage(T& obj, fnd::Message& msg)
    {
        return false;
    }
};
} // ut
} // app
