// TODO: Both the name of this file and its path were guessed!
#include "OpenLW/pch.h"
#include "StateDesc.h"

namespace app
{
namespace ut
{
namespace internal
{
StateDescImpl::StateDescImpl(const char* name, StateCreatorFunc stateCreator, int super) :
    stateCreator(stateCreator),
    className(className),
    super(super) {}
} // internal
} // ut
} // app
