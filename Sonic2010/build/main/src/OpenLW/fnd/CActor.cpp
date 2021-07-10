#include "CActor.h"
#include "Message.h"
#include "MessageManager.h"

namespace app
{
namespace fnd
{
CActor::~CActor()
{
    // TODO
}

bool CActor::PreProcessMessage(Message& msg)
{
    return false;
}

bool CActor::ProcessMessage(Message& msg)
{
    return PreProcessMessage(msg);
}

void CActor::Update(const SUpdateInfo& updateInfo) {}

void CActor::BeginProfile(int param_1)
{
    // TODO
}

void CActor::BroadcastMessage(unsigned int receiverID, Message& msg)
{
    if ((field_0x10 & msg.Mask) != 0)
    {
        CActor* actor = MessageSetup(receiverID, msg);
        msg.Broadcasted = true;
        actor->m_msgMgr->AddMessage(msg);
    }
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

CActor* CActor::MessageSetup(unsigned int receiverID, Message& msg)
{
    msg.Receiver = receiverID;
    msg.Sender = m_ID;
    return this;
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
    m_updateFlags.Set(phase, isUpdating);
}

CActor::CActor() :
    m_ID(0),
    m_msgMgr(nullptr),
    m_parent(nullptr),
    m_updateFlags(),
    field_0xd(false),
    field_0xe(true),
    field_0xf(true),
    field_0x10(-1),
    field_0x14(nullptr)
{
    SetUpdateFlag(PHASE_NORMAL, true);
}
}
}
