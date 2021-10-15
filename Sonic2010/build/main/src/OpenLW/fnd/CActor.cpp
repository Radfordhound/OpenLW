#include "CActor.h"
#include "Message.h"
#include "MessageManager.h"
#include "../../System/Component/TinyFsm.h"

namespace app
{
namespace fnd
{
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
    SetUpdateFlag(PHASE_ONE, true);
}

void CActor::RemoveFromAllParents()
{
    // TODO
}

CActor::~CActor()
{
    // TODO
}

void CActor::SetParent(CActor* parent)
{
    m_parent = parent;
}

void CActor::MessageSetup(unsigned int receiverID, Message& msg)
{
    msg.Receiver = receiverID;
    msg.Sender = m_ID;
}

void CActor::BroadcastMessageImm(unsigned int param_1, Message& msg)
{
    // TODO
}

void CActor::BroadcastMessage(unsigned int receiverID, Message& msg)
{
    if ((field_0x10 & msg.Mask) != 0)
    {
        MessageSetup(receiverID, msg);
        msg.Broadcasted = true;
        m_msgMgr->AddMessage(msg);
    }
}

bool CActor::SendMessage(Message& msg)
{
    return ((field_0x10 & msg.Mask) != 0 &&
        ActorProc(SIGNAL_UPDATE, &msg)); // TODO: Is this correct?
}

void CActor::BroadcastMessage(Message& msg)
{
    // TODO
}

void CActor::SendMessage(unsigned int receiverID, Message& msg)
{
    if ((field_0x10 & msg.Mask) != 0)
    {
        MessageSetup(receiverID, msg);
        m_msgMgr->AddMessage(msg);
    }
}

bool CActor::SendMessageImm(unsigned int receiverID, Message& msg)
{
    if ((field_0x10 & msg.Mask) != 0)
    {
        MessageSetup(receiverID, msg);
        
        CActor* receiver = m_msgMgr->GetActor(receiverID);
        if (receiver)
        {
            return receiver->ActorProc(SIGNAL_UPDATE, &msg);
        }
    }

    return false;
}

bool CActor::GetUpdateFlag(UpdatingPhase phase) const
{
    return m_updateFlags.test(phase);
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

void CActor::EndProfile(int param_1)
{
    // TODO
}
}
}
