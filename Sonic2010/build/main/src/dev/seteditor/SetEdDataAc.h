// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include <csl/math/quaternion.h>

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
