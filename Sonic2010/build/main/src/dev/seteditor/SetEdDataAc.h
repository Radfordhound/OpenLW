#pragma once
#include <csl/math/quaternion.h>

// TODO: This file name is correct, but the path the file is stored at might
// not be, as it had to be guessed from a combination of leftover paths from
// Lost World Wii U and Colors Ultimate Switch.

namespace app
{
namespace math
{
struct Angle3;
}

namespace SetEd
{
// Wii U: 0x020fd9ec, PC: 0x00462080
csl::math::Quaternion CalcRotationByAngle(const math::Angle3& angle);
}
}
