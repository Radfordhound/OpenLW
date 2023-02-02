#pragma once
#include <csl/math/matrix34.h>

// TODO: This file name is correct, but the path the file is stored at might
// not be, as it had to be guessed.

namespace app
{
namespace math
{
struct Angle3;

// Wii U: 0x022e866c, PC: 0x00532490
void Matrix34ToEulerAngleZXY(const csl::math::Matrix34& mtx, Angle3* eulerAngles);
}
}
