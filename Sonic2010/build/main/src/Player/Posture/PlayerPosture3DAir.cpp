#include "OpenLW/pch.h"
#include "PlayerPosture3DAir.h"

namespace app
{
namespace Player
{
const char* CPosture3DAir::GroupID = "CPosture3DAir";

const char* CPosture3DAir::GetGroupID()
{
    return GroupID;
}

void CPosture3DAir::Calculate(CPhysics& physics, float dt)
{
    // TODO
}

void CPosture3DAir::OnEnter(CPhysics& physics)
{
    // TODO
}

CPosture3DAir::CPosture3DAir()
{
    // TODO
}

void CPosture3DAir::SetInternalForceMode(CPhysics& physics, int param_2)
{
    // TODO
}

void CPosture3DAir::RotateFrontDirection(CPhysics& physics, float param_2, csl::math::Vector3 const& param_3, float param_4, float param_5);
{
    // TODO
}

void CPosture3DAir::calcInternalForNormal(CPhysics& physics, float param_2)
{
    // TODO
}

void CPosture3DAir::calcInternalForBrake(CPhysics& physics, float param_2)
{
    // TODO
}

void CPosture3DAir::calcInternalForAuto(CPhysics& physics, float param_2)
{
    // TODO
}

void CPosture3DAir::UpdateInternalForce(CPhysics& physics, float param_2)
{
    // TODO
}
} // Player
} // app
