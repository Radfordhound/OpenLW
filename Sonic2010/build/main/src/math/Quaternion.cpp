#include "Quaternion.h"
#include "Matrix34.h"

// TODO: This file name is correct, but the path the file is stored at might
// not be, as it had to be guessed.

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
