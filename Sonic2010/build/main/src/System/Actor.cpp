// TODO: The name of this file is correct, but the path was guessed!
#include "OpenLW/pch.h"
#include "Actor.h"
#include "Component/TinyFsm.h"
#include "Message/Message.h"
#include "Message/MessageManager.h"

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
    m_flags(1),
    m_enabled(true),
    m_allowedMessageFlags(UINT_MAX),
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
    msg.receiver = receiverID;
    msg.sender = m_ID;
}

void CActor::BroadcastMessageImm(unsigned int param_1, Message& msg)
{
    // TODO
}

void CActor::BroadcastMessage(unsigned int receiverID, Message& msg)
{
    if ((m_allowedMessageFlags & msg.mask) != 0)
    {
        MessageSetup(receiverID, msg);
        msg.broadcasted = true;
        m_msgMgr->AddMessage(msg);
    }
}

bool CActor::SendMessage(Message& msg)
{
    return ((m_allowedMessageFlags & msg.mask) != 0 &&
        ActorProc(SIGNAL_UPDATE, &msg)); // TODO: Is this correct?
}

void CActor::BroadcastMessage(Message& msg)
{
    // TODO
}

void CActor::SendMessage(unsigned int receiverID, Message& msg)
{
    if ((m_allowedMessageFlags & msg.mask) != 0)
    {
        MessageSetup(receiverID, msg);
        m_msgMgr->AddMessage(msg);
    }
}

bool CActor::SendMessageImm(unsigned int receiverID, Message& msg)
{
    if ((m_allowedMessageFlags & msg.mask) != 0)
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
} // fnd
} // app
