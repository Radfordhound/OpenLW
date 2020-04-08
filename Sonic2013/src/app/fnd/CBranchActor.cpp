#include "CBranchActor.h"

namespace app
{
namespace fnd
{
CBranchActor::CBranchActor()
{
    // TODO
}

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
}
}
