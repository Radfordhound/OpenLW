#pragma once
#include "CActor.h"
#include "csl/ut/array.h"

namespace app
{
namespace fnd
{
class CBranchActor : public CActor // size == 0x5c
{
protected:
    csl::ut::MoveArray<CActor*> m_childActors;
    csl::ut::MoveArray<CActor*> m_phasedActors[3];

public:
    // Wii U: TODO, PC: TODO
    ~CBranchActor();

    // Wii U: TODO, PC: TODO
    bool ForEach(CActorTraverser& traverser);

    // Wii U: TODO, PC: TODO
    bool ActorProc(int param_1, void* param_2);

    // Wii U: TODO, PC: TODO
    void AddChild(CActor* child);

    // Wii U: TODO, PC: TODO
    bool IsParentOf(CActor* actor) const;

    // Wii U: TODO, PC: TODO
    void PhasedUpdateHierarchy(UpdatingPhase phase, const SUpdateInfo& updateInfo);

    // Wii U: TODO, PC: TODO
    void RemoveChild(CActor* child);

    // Wii U: TODO, PC: TODO
    void UpdateChildren(const csl::ut::MoveArray<CActor*>& children,
        int param_2, void* param_3);

    // Wii U: TODO, PC: 0x0048cfb0
    CBranchActor();
};
}
}
