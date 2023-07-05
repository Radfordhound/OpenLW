// TODO: Both the name of this file and its path were guessed!
#include "OpenLW/pch.h"
#include "StateManager.h"

namespace app
{
namespace ut
{
namespace internal
{
StateManagerImpl::~StateManagerImpl() {}

StateManagerImpl::StateManagerImpl(int stateDescCount) :
    m_stateDescImpls(stateDescCount, m_allocator)
{
    m_stateDescImpls.assign(stateDescCount, nullptr);
}

void StateManagerImpl::RegisterState(int stateID, const StateDescImpl* stateDescImpl)
{
    m_stateDescImpls[stateID] = stateDescImpl;
}

std::size_t StateManagerImpl::GetNumStateDesc() const
{
    return m_stateDescImpls.size();
}

const StateDescImpl* StateManagerImpl::GetStateDesc(int stateID) const
{
    return m_stateDescImpls[stateID];
}

StateImpl* StateManagerImpl::Create(int stateID)
{
    const auto stateDesc = m_stateDescImpls[stateID];
    const auto state = stateDesc->stateCreator(m_allocator);

    if (state)
    {
        state->stateID = stateID;
        state->className = stateDesc->className;
    }

    return state;
}

int StateManagerImpl::GetSuper(int stateID) const
{
    return m_stateDescImpls[stateID]->super;
}

bool StateManagerImpl::IsSuper(int stateID, int superID) const
{
    while (superID != -1)
    {
        // Return true if the current state is a super of the given state.
        if (stateID == superID)
        {
            return true;
        }

        // Recurse through super classes.
        superID = GetSuper(superID);
    }

    return false;
}
} // internal
} // ut
} // app
