// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "PlayerPostureManager.h"

namespace app
{
namespace Player
{
class CPostureMoveManager : public CPostureManager
{
public:
    LWAPI(0x0292CFFC, TODO)
    ~CPostureMoveManager();

    LWAPI(0x0292CF80, TODO)
    void Update(float dt);

    LWAPI(0x0292CFF8, TODO)
    void BeforCalculate(float param_1);

    LWAPI(0x0292BAA0, TODO)
    CPostureMoveManager(CPlayer* player, CPhysics* physics);

    LWAPI(0x0292C0DC, 0x00859360)
    void RegisterCommonPosture();

    LWAPI(0x0292CF7C, TODO)
    void AfterCalculate(float param_1);

    LWAPI(0x0292CF48, TODO)
    void SetupPosture();
};

LWAPI_STATIC_ASSERT_SIZE(CPostureMoveManager, 0x38)
} // Player
} // app
