#pragma once
#include <csl/math/quaternion.h>

// TODO: This file name is correct, but the path the file is stored at might
// not be, as it had to be guessed.

namespace app
{
namespace math
{
struct Angle3;

// Wii U: 0x022e8e64, PC: 0x00532af0
void QuaternionToEulerAngleZXY(const csl::math::Quaternion& quat, Angle3* eulerAngles);
}
}
