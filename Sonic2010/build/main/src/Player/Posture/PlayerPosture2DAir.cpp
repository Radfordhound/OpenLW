#include "OpenLW/pch.h"
#include "PlayerPosture2DAir.h"

namespace app
{
namespace Player
{
const char* CPosture2DAir::GroupID = "CPosture2DAir";

const char* CPosture2DAir::GetGroupID()
{
    return GroupID;
}

void CPosture2DAir::Calculate(CPhysics& physics, float dt)
{
    // TODO
}

void CPosture2DAir::OnEnter(CPhysics& physics)
{
    // TODO
}

void CPosture2DAir::OnLeave(CPhysics& physics)
{
    // TODO
}

CPosture2DAir::CPosture2DAir()
{
    // TODO
}

void CPosture2DAir::SetIgnoreWallJumpTimer(bool param_1)
{
    // TODO
}

void CPosture2DAir::SetInternalForceMode(EInternalMode param_1)
{
    // TODO
}

void CPosture2DAir::CheckEnableWallJump(CPhysics& physics, float param_2, csl::math::Vector3 const& param_3)
{
    // TODO
}

void CPosture2DAir::UpdateFrontIgnoreInput(CPhysics& physics, float param_2, float param_3)
{
    // TODO
}

void CPosture2DAir::UpadateYaw(CPhysics& physics, float param_2, float param_3, float param_4)
{
    // TODO
}

void CPosture2DAir::calcInternalForNormal(CPhysics& physics, float param_2)
{
    // TODO
}

void CPosture2DAir::calcInternalForBrake(CPhysics& physics, float param_2)
{
    // TODO
}

void CPosture2DAir::UpdateInternalForce(CPhysics& physics, float param_2)
{
    // TODO
}
} // Player
} // app
