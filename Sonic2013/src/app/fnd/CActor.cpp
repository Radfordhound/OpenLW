#include "CActor.h"

namespace app
{
namespace fnd
{
CActor::~CActor()
{
    // TODO
}

unsigned int CActor::PreProcessMessage(Message& msg)
{
    // TODO
    return 0;
}

unsigned int CActor::ProcessMessage(Message& msg)
{
    // TODO
    return 0;
}

void CActor::Update(const SUpdateInfo& updateInfo)
{
    // TODO
}

CActor::CActor()
{
    SetUpdateFlag(UpdatingPhase::Normal, true);
}

void CActor::BeginProfile(int param_1)
{
    // TODO
}

void CActor::BroadcastMessage(unsigned int param_1, Message& msg)
{
    // TODO
}

void CActor::BroadcastMessage(Message& msg)
{
    // TODO
}

void CActor::BroadcastMessageImm(unsigned int param_1, Message& msg)
{
    // TODO
}

void CActor::EndProfile(int param_1)
{
    // TODO
}

bool CActor::GetUpdateFlag(UpdatingPhase phase) const
{
    // TODO
    return false;
}

void CActor::MessageSetup(unsigned int param_1, Message& msg)
{
    // TODO
}

void CActor::RemoveFromAllParents()
{
    // TODO
}

bool CActor::SendMessage(Message& msg)
{
    // TODO
    return false;
}

void CActor::SendMessage(unsigned int param_1, Message& msg)
{
    // TODO
}

bool CActor::SendMessageImm(unsigned int param_1, Message& msg)
{
    // TODO
    return false;
}

void CActor::SetParent(CActor* parent)
{
    // TODO
}

void CActor::SetUpdateFlag(UpdatingPhase phase, bool isUpdating)
{
    // TODO
}
}
}
