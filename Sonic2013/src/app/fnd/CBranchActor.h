#pragma once
#include "CActor.h"
#include "csl/ut/MoveArray.h"

namespace app
{
namespace fnd
{
class CBranchActor : public CActor // size == 0x5c?
{
    csl::ut::MoveArray<CActor*> fx1C;
    // TODO: Additional data members

public:
    /*
        @brief Constructor for CBranchActor.
        <b>Wii U: TODO, PC: TODO</b>
    */
    CBranchActor();

    /*
        @brief Destructor for CBranchActor.
        <b>Wii U: TODO, PC: TODO</b>
    */
    ~CBranchActor() override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    bool ForEach(CActorTraverser& traverser) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    bool ActorProc(int param_1, void* param_2) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    void AddChild(CActor* child);

    /* <b>Wii U: TODO, PC: TODO</b> */
    bool IsParentOf(CActor* actor) const;

    /* <b>Wii U: TODO, PC: TODO</b> */
    void PhasedUpdateHierarchy(UpdatingPhase phase, const SUpdateInfo& updateInfo);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void RemoveChild(CActor* child);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void UpdateChildren(const csl::ut::MoveArray<CActor*>& children,
        int param_2, void* param_3);
};
}
}
