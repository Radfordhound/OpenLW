#include "OpenLW/pch.h"
#include "PlayerPosture.h"

namespace app
{
namespace Player
{
const char* CBasePosture::GroupID;

const char* CBasePosture::GetGroupID()
{
    return GroupID;
}

void CBasePosture::OnEnter(CPhysics& param_1)
{
    // TODO
}

void CBasePosture::OnLeave(CPhysics& param_1)
{
    // TODO
}

bool CBasePosture::ProcessMessage(CPhysics& param_1, fnd::Message& param_2)
{
    // TODO
    return false;
}

void CBasePosture::SetupForChangeDimension(bool param_1, CPhysics& param_2)
{
    // TODO
}

CBasePosture::CBasePosture()
{
    // TODO
}

CPlayer* CBasePosture::GetOwner()
{
    // TODO
    return nullptr;
}

const CPlayer* CBasePosture::GetOwner() const
{
    // TODO
    return nullptr;
}

void CBasePosture::GetBlackBoard()
{
    // TODO
}

void CBasePosture::GetBlackBoard() const
{
    // TODO
}

void CBasePosture::GetPathService()
{
    // TODO
}

void CBasePosture::GetPathService() const
{
    // TODO
}

void CBasePosture::GetCollision()
{
    // TODO
}

void CBasePosture::GetCollision() const
{
    // TODO
}

bool CBasePosture::Is2DMode() const
{
    // TODO
    return false;
}

bool CBasePosture::IsSpinDash() const
{
    // TODO
    return false;
}

bool CBasePosture::IsDash() const
{
    // TODO
    return false;
}

bool CBasePosture::IsNowSuperSonic() const
{
    // TODO
    return false;
}

bool CBasePosture::IsOnGround() const
{
    // TODO
    return false;
}

bool CBasePosture::IsDisableUpdateYaw() const
{
    // TODO
    return false;
}

bool CBasePosture::IsOutOfControl() const
{
    // TODO
    return false;
}

bool CBasePosture::IsDisableCollision() const
{
    // TODO
    return false;
}

void CBasePosture::GetPath(PathType param_1) const
{
    // TODO
}

bool CBasePosture::IsNowAutoRun() const
{
    // TODO
    return false;
}

void CBasePosture::SendMessageImmToCamera(fnd::Message& param_1)
{
    // TODO
}

void CBasePosture::SendMessageImm(unsigned int param_1, fnd::Message& param_2)
{
    // TODO
}

void CBasePosture::ProcessMessageToCurrentState(fnd::Message& param_1)
{
    // TODO
}

void CBasePosture::GetDocument()
{
    // TODO
}

void CBasePosture::GetPath(PathType param_1)
{
    // TODO
}

void CBasePosture::GetPhysicsWorld() const
{
    // TODO
}

void CBasePosture::GetParameter(Param::Index param_1) const
{
    // TODO
}

void CBasePosture::GetHomingService()
{
    // TODO
}

void CBasePosture::GetInputStickData() const
{
    // TODO
}

void CBasePosture::GetWorldPosition(const csl::math::Vector2& param_1, const csl::math::Vector3& param_2, csl::math::Vector3* param_3)
{
    // TODO
}

void CBasePosture::GetOnAirTime() const
{
    // TODO
}

void CBasePosture::GetOnGroundTime() const
{
    // TODO
}

bool CBasePosture::IsRunningLoopPath() const
{
    // TODO
    return false;
}

void CBasePosture::GetPhysicsCollisionFilter() const
{
    // TODO
}

void CBasePosture::CheckAndOffCollisionFilterForOneway(const csl::math::Vector3& param_1, const csl::math::Vector3& param_2)
{
    // TODO
}

void CBasePosture::OnCollisionFilterForOneway()
{
    // TODO
}

csl::fnd::IAllocator* CBasePosture::GetOwnerAllocator() const
{
    // TODO
    return nullptr;
}
} // Player
} // app
