// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "Actor.h"
#include <csl/ut/array.h>

namespace app
{
namespace fnd
{
class CBranchActor : public CActor // size == 0x5c
{
LWAPI_PROTECTED
    csl::ut::MoveArray<CActor*> m_childActors;
    csl::ut::MoveArray<CActor*> m_phasedActors[PHASE_COUNT];

public:
    LWAPI(TODO, TODO)
    ~CBranchActor();

    LWAPI(TODO, TODO)
    bool ForEach(CActorTraverser& traverser);

    LWAPI(TODO, TODO)
    void AddChild(CActor* child);

    LWAPI(TODO, TODO)
    bool IsParentOf(CActor* actor) const;

    LWAPI(TODO, TODO)
    void PhasedUpdateHierarchy(UpdatingPhase phase, const SUpdateInfo& updateInfo);

    LWAPI(0x021837c8, TODO)
    void RemoveChild(CActor* child);

    LWAPI(0x021839e4, TODO)
    void UpdateChildren(const csl::ut::MoveArray<CActor*>& children,
        int param_2, void* param_3);

    LWAPI(0x02183a7c, TODO)
    bool ActorProc(int param_1, void* param_2);

    LWAPI(TODO, 0x0048cfb0)
    CBranchActor();
};
}
}
