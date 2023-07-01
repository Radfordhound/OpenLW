// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once
#include "PlayerPostureCommon.h"
#include "Utility/RefPtr.h"

namespace app
{
namespace Player
{
class CPhysics;

class CPostureBridgeBase : public CPostureCommon
{
OPENLW_PROTECTED
    ut::RefPtr<CBasePosture> m_innerPosture;

public:
    LWAPI(0x0295d838, TODO)
    ~CPostureBridgeBase();

    LWAPI(0x0292d4b0, TODO)
    const char* GetGroupID();

    LWAPI(0x0295d898, TODO)
    void OnEnter(CPhysics& physics);

    LWAPI(0x0295d9cc, TODO)
    void OnLeave(CPhysics& physics);

    LWAPI(0x0295d9d0, TODO)
    void Calculate(CPhysics& param_1, float param_2);

    LWAPI(0x0295da18, TODO)
    void SetupForChangeDimension(bool param_1, CPhysics& physics);

    LWAPI(0x0295da80, TODO)
    virtual void CreateInnerPosture(bool is2D, CPhysics& physics) {}

    template<class T>
    T* GetInnerPosture()
    {
        return (m_innerPosture && m_innerPosture->GetGroupID() == T::GroupID) ?
            m_innerPosture.get() : nullptr;
    }

    LWAPI(0x0295d970, TODO)
    void EndInnerPosture(CPhysics& physics);

    LWAPI(0x0295da84, TODO)
    void StartInnerPosture(CPhysics& physics);
};

LWAPI_STATIC_ASSERT_SIZE(CPostureBridgeBase, 0x14)

template<class Posture2D, class Posture3D>
class CPostureBridge : public CPostureBridgeBase
{
public:
    void CreateInnerPosture(bool is2D, CPhysics& physics)
    {
        if (is2D)
        {
            m_innerPosture.reset(new (GetOwnerAllocator()) Posture2D());
        }
        else
        {
            m_innerPosture.reset(new (GetOwnerAllocator()) Posture3D());
        }

        StartInnerPosture(physics);
    }
};
} // Player
} // app
