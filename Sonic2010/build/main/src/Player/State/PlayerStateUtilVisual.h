// TODO: The name of this file is correct, but the path was guessed!
// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once

namespace csl
{
namespace math
{
struct Vector3;
struct Matrix34;
} // math

namespace ut
{
struct ColorF;
} // ut
} // csl

namespace app
{
namespace Player
{
class CStateGOC;

namespace StateUtil
{
LWAPI(0x02a27fa8, TODO)
void StartHeadToVelocity(CStateGOC& param_1, const csl::math::Vector3& param_2, bool param_3);

LWAPI(0x02a282c8, TODO)
void EndHeadToVelocity(CStateGOC& param_1, float param_2);

LWAPI(0x02a28318, TODO)
void StartVisualMatrixExternally(CStateGOC& param_1, const csl::math::Matrix34& param_2);

LWAPI(0x02a28374, TODO)
void EndVisualMatrixExternally(CStateGOC& param_1, float param_2, bool param_3, bool param_4);

LWAPI(0x02a2841c, TODO)
void SetVisualMatrix(CStateGOC& param_1, const csl::math::Matrix34& param_2);

LWAPI(0x02a28458, TODO)
void GetVisualMatrix(CStateGOC& param_1, csl::math::Matrix34* param_2);

LWAPI(0x02a2849c, TODO)
void SetVisualMatrixModeNormal(CStateGOC& param_1);

LWAPI(0x02a284d4, TODO)
void StartVisualMatrixModeFlatStand(CStateGOC& param_1);

LWAPI(0x02a2850c, TODO)
void EndVisualMatrixModeFlatStand(CStateGOC& param_1);

LWAPI(0x02a28544, TODO)
void ResetLocater(CStateGOC& param_1, const csl::math::Matrix34& param_2);

LWAPI(0x02a285a8, TODO)
void ResetVisualLocaterInterPoration(CStateGOC& param_1);

LWAPI(0x02a285e0, TODO)
void SetDraw(CStateGOC& param_1, bool param_2, bool param_3);

LWAPI(0x02a28614, TODO)
void SetDrawStandOut(CStateGOC& param_1, bool param_2);

LWAPI(0x02a2864c, TODO)
void SetCulling(CStateGOC& param_1, bool param_2);

LWAPI(0x02a28650, TODO)
void IsVisualSpinBall(CStateGOC& param_1);

LWAPI(0x02a2867c, TODO)
void SetVisualToBodyMain(CStateGOC& param_1);

LWAPI(0x02a286cc, TODO)
void SetDrawBall(CStateGOC& param_1, bool param_2);

LWAPI(0x02a2873c, 0x008df830)
void SetDrawJumpBall(CStateGOC& goc, bool val);

LWAPI(0x02a287ac, TODO)
void SetDrawChargeBall(CStateGOC& param_1, bool param_2);

LWAPI(0x02a2880c, TODO)
void ChangeBallVisualToSuperSonic(CStateGOC& param_1, bool param_2);

LWAPI(0x02a2884c, TODO)
void CheckPassChargeFrame(CStateGOC& param_1);

LWAPI(0x02a288c0, TODO)
void SetBallDeformationRatio(CStateGOC& param_1, float param_2);

LWAPI(0x02a28934, TODO)
void SetBankMode(CStateGOC& param_1, bool param_2);

LWAPI(0x02a289dc, TODO)
void SetBallMatrix(CStateGOC& param_1, const csl::math::Matrix34& param_2);

LWAPI(0x02a28a54, TODO)
void GetBallMatrix(CStateGOC& param_1, csl::math::Matrix34& param_2);

LWAPI(0x02a28adc, TODO)
void StartDamageBlink(CStateGOC& param_1, float param_2);

LWAPI(0x02a28b20, TODO)
void EndDamageBlink(CStateGOC& param_1);

LWAPI(0x02a28b44, TODO)
void ForeceCancelPersistence(CStateGOC& param_1);

LWAPI(0x02a28b94, TODO)
void SetPersistenceDelay(CStateGOC& param_1, unsigned int param_2);

LWAPI(0x02a28bd4, TODO)
void SetPersistenceNum(CStateGOC& param_1, unsigned int param_2);

LWAPI(0x02a28c14, TODO)
void ChangeAnimationCurrentVisual(CStateGOC& param_1, const char* param_2);

LWAPI(0x02a28c70, TODO)
void ChangeAnimationCurrentVisual(CStateGOC& param_1, int param_2, const char* param_3);

LWAPI(0x02a28cd8, TODO)
void ChangeAnimationSpeedCurrentVisual(CStateGOC& param_1, float param_2);

LWAPI(0x02a28d44, TODO)
void IsFinishedAnimationCurrentVisual(CStateGOC& param_1);

LWAPI(0x02a28da4, TODO)
void ForcedStopFootPlacement(CStateGOC& param_1);

LWAPI(0x02a28de8, TODO)
void SetModelMaterialColor(CStateGOC& param_1, const csl::ut::ColorF& param_2);

LWAPI(0x02a28e7c, TODO)
void ResetModelMaterialColor(CStateGOC& param_1);

LWAPI(0x02a28ecc, TODO)
void SetSyncMouseAnimationToNodeAnimation(CStateGOC& param_1, const char* param_2);

LWAPI(0x02a28f20, TODO)
void IsAnimationExist(CStateGOC& param_1, const char* param_2);

LWAPI(0x02a28fa8, TODO)
void GetHumanVisualModel(CStateGOC& param_1);
} // StateUtil
} // Player
} // app
