// TODO: The name of this file is correct, but the path was guessed!
#include "OpenLW/pch.h"
#include "BranchActor.h"
#include "Component/TinyFsm.h"
#include "Message/Message.h"
#include "Memory/GlobalAllocator.h"

namespace app
{
namespace fnd
{
CBranchActor::~CBranchActor()
{
    // TODO
}

bool CBranchActor::ForEach(CActorTraverser& traverser)
{
    // TODO
    return false;
}

void CBranchActor::AddChild(CActor* child)
{
    // TODO
}

bool CBranchActor::IsParentOf(CActor* actor) const
{
    // TODO
    return false;
}

void CBranchActor::PhasedUpdateHierarchy(UpdatingPhase phase, const SUpdateInfo& updateInfo)
{
    // TODO
}

void CBranchActor::RemoveChild(CActor* child)
{
    m_childActors.erase_unstable(std::find(m_childActors.begin(),
        m_childActors.end(), child));

    for (int phase = PHASE_ONE; phase < PHASE_COUNT; ++phase)
    {
        if (child->GetUpdateFlag(static_cast<UpdatingPhase>(phase)))
        {
            m_phasedActors[phase].erase_unstable(std::find(
                m_phasedActors[phase].begin(), m_phasedActors[phase].end(),
                child));
        }
    }

    child->SetParent(nullptr);
}

void CBranchActor::UpdateChildren(const csl::ut::MoveArray<CActor*>& children,
    int param_2, void* param_3)
{
    for (auto it = children.begin(); it != children.end(); ++it)
    {
        if ((*it)->GetFlags())
        {
            (*it)->ActorProc(param_2, param_3);
        }
    }
}

bool CBranchActor::ActorProc(int param_1, void* param_2)
{
    switch (param_1)
    {
    case SIGNAL_UPDATE:
    {
        Message* msg = static_cast<Message*>(param_2);
        return (m_enabled && ProcessMessage(*msg));
    }

    case SIGNAL_MESSAGE:
    {
        Message* msg = static_cast<Message*>(param_2);
        ProcessMessage(*msg);

        for (auto it = m_childActors.begin(); it != m_childActors.end(); ++it)
        {
            if (((*it)->GetAllowedMessageFlags() & msg->mask) != 0)
            {
                (*it)->ActorProc(SIGNAL_MESSAGE, msg);
            }
        }
        break;
    }

    case 3: // TODO: What is this signal type??
        if (!m_flags)
        {
            return false;
        }

        Update(*static_cast<const SUpdateInfo*>(param_2));
        UpdateChildren(m_phasedActors[PHASE_ONE], param_1, param_2);
        break;

    case 4: // TODO: What is this signal type??
        if (!m_flags)
        {
            return false;
        }

        UpdateChildren(m_phasedActors[PHASE_TWO], param_1, param_2);
        break;

    case 5: // TODO: What is this signal type??
        if (!m_flags)
        {
            return false;
        }

        UpdateChildren(m_phasedActors[PHASE_THREE], param_1, param_2);
        break;

    default:
        RemoveChild(static_cast<CActor*>(param_2));
        break;
    }

    return true;
}

CBranchActor::CBranchActor() :
    m_childActors(1024, game::GlobalAllocator::GetAllocator(ALLOCATOR_UNK_TWO)),
    m_phasedActors() // TODO: I assume this is correct?
{
    for (std::size_t i = 0; i < 3; ++i)
    {
        csl::fnd::IAllocator* allocator = game::GlobalAllocator::GetAllocator(ALLOCATOR_UNK_TWO);
        m_phasedActors[i].Reset(nullptr, 0, 0, allocator, false);
        m_phasedActors[i].reserve(1024);
    }
}
}
}
