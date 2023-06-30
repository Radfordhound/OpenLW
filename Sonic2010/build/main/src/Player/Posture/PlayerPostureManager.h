// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "Player/Base/PlayerPosture.h"
#include "System/ReferencedObject.h"
#include <csl/ut/array.h>
#include <boost/intrusive_ptr.hpp>

namespace app
{
namespace fnd
{
class Message;
} // fnd

namespace Player
{
class CPostureFactoryBase;
class CPlayer;
class CPhysics;

class CPostureManager : public fnd::ReferencedObject
{
OPENLW_PROTECTED
    csl::ut::ObjectMoveArray<boost::intrusive_ptr<CPostureFactoryBase>> field_0xc;
    CPlayer* m_player;
    CPhysics* m_physics;
    unsigned int field_0x24;
    unsigned int field_0x28;
    unsigned int field_0x2c;
    CBasePosture* field_0x30;
    boost::intrusive_ptr<CPostureFactoryBase> field_0x34;

public:
    LWAPI(0x0292B420, TODO)
    ~CPostureManager();

    LWAPI(0x0292B4A0, TODO)
    virtual void Update(float dt);

    LWAPI(0x0292BA0C, TODO)
    virtual void BeforCalculate(float param_1);

    template<class T>
    T* GetPosture()
    {
        return (field_0x30 && field_0x30->GetGroupID() == T::GroupID) ?
            static_cast<T*>(field_0x30) : nullptr;
    }

    LWAPI(0x0292B158, TODO)
    CPostureManager(CPlayer* player, CPhysics* physics);

    LWAPI(0x0292B238, TODO)
    void Finalize();

    LWAPI(0x0292B518, TODO)
    bool ProcessMessageToCurrentPosture(fnd::Message& msg);

    LWAPI(0x0292B54C, TODO)
    bool ProcessMessage(fnd::Message& msg);

    LWAPI(0x0292B550, TODO)
    void SetupForChangeDimension(bool param_1);

    LWAPI(0x0292B738, TODO)
    void RegisterFactory(boost::intrusive_ptr<CPostureFactoryBase> postureFactory);

    LWAPI(0x0292B7BC, TODO)
    void Renew();

    LWAPI(0x0292B8E8, TODO)
    void ChangePosture(const char* param_1);
};

LWAPI_STATIC_ASSERT_SIZE(CPostureManager, 0x38)
} // Player
} // app
