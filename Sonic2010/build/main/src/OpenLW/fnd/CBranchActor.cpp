#include "CBranchActor.h"
#include "../game/GlobalAllocator.h"

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

bool CBranchActor::ActorProc(int param_1, void* param_2)
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
    // TODO
}

void CBranchActor::UpdateChildren(const csl::ut::MoveArray<CActor*>& children,
    int param_2, void* param_3)
{
    // TODO
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
