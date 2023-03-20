// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include <csl/math/matrix34.h>

namespace app
{
namespace math
{
struct Angle3;

LWAPI(0x022e866c, 0x00532490)
void Matrix34ToEulerAngleZXY(const csl::math::Matrix34& mtx, Angle3* eulerAngles);
}
}
