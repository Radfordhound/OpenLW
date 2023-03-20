// TODO: The name of this file is correct, but the path was guessed!
#include "pch.h"
#include "Quaternion.h"
#include "Matrix34.h"

namespace app
{
namespace math
{
void QuaternionToEulerAngleZXY(const csl::math::Quaternion& quat, Angle3* eulerAngles)
{
    Matrix34ToEulerAngleZXY(csl::math::Matrix34(quat), eulerAngles);
}
}
}
