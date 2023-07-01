// TODO: Both the name of this file and its path were guessed!
// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once
#include "PlayerPostureCommon.h"

namespace csl
{
namespace math
{
struct Vector3;
} // math
} // csl

namespace app
{
namespace Player
{
class CPhysics;

class CPostureAirCommon : public CPostureCommon
{
public:
    class CalcAutoRunInfo
    {
        // TODO
    };

    LWAPI(0x02951844, TODO)
    ~CPostureAirCommon() {}

    LWAPI(0x0295ab10, TODO)
    void CalcTranslateMoveForce(CPhysics& physics, float param_2, float param_3, csl::math::Vector3 const& param_4, float param_5, float param_6, float param_7) const;

    LWAPI(0x0295ac50, TODO)
    void CheckChangeModeToBrake(CPhysics& physics);

    LWAPI(0x0295ad00, TODO)
    void RotateVelocityByGravity(CPhysics& physics);

    LWAPI(0x0295af68, TODO)
    void CalcVelocityForAutoRun(CPhysics& physics, float param_2, CalcAutoRunInfo const& param_3);
};
} // Player
} // app
