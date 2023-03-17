// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include <csl/math/quaternion.h>

namespace app
{
namespace math
{
struct Angle3;

// Wii U: 0x022e8e64, PC: 0x00532af0
void QuaternionToEulerAngleZXY(const csl::math::Quaternion& quat, Angle3* eulerAngles);
}
}
