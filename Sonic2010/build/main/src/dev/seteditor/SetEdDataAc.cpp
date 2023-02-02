#include "SetEdDataAc.h"
#include "../../math/Angle3.h"
#include "../../OpenLW/Constants.h"

// TODO: This file name is correct, but the path the file is stored at might
// not be, as it had to be guessed from a combination of leftover paths from
// Lost World Wii U and Colors Ultimate Switch.

namespace app
{
namespace SetEd
{
csl::math::Quaternion CalcRotationByAngle(const math::Angle3& angle)
{
    // TODO: Generated machine code is not identical to original, but returns exact same results.
    csl::math::Quaternion rotRight(AXIS_RIGHT, angle.X);
    csl::math::Quaternion rotUp(AXIS_UP, angle.Y);
    csl::math::Quaternion v16 = (rotRight * rotUp); // var_80/var_88
    //csl::math::Quaternion v20 = v16; // var_58/var_60
    csl::math::Quaternion rotForward(AXIS_FORWARD, angle.Z);
    //csl::math::Quaternion v18 = (v16 * rotForward); // var_70/var_78
    //return v18; // var_48/var_50
    return (rotForward * v16);
}
}
}
