// TODO: The name of this file is correct, but the path was guessed!
#include "OpenLW/pch.h"
#include "Matrix34.h"
#include "Angle3.h"
#include "System/Constants.h"

namespace app
{
namespace math
{
void Matrix34ToEulerAngleZXY(const csl::math::Matrix34& mtx, Angle3* eulerAngles)
{
    // TODO: Generated machine code is not identical to original, but returns exact same results.
    float v14 = atan2f(mtx.GetValue(0, 2), mtx.GetValue(2, 2));
    float sine = sinf(v14); // TODO: Somehow we want to ACTUALLY call ___libm_sse2_sinf, not ___libm_sse2_sin
    float cosine = cosf(v14); // TODO: Somehow we want to ACTUALLY call ___libm_sse2_cosf, not ___libm_sse2_cos
    float v20;

    if (fabs(mtx.GetValue(2, 2)) <= fabs(mtx.GetValue(0, 2)))
    {
        float v23 = atan2f(-(mtx.GetValue(1, 2) * sine), mtx.GetValue(0, 2));
        v20 = (sine < 0.0f) ?
            (v23 + ((v23 < 0.0f) ? MATH_PI : -MATH_PI)) :
            v23;
    }
    else
    {
        float v19 = atan2f(-(mtx.GetValue(1, 2) * cosine), mtx.GetValue(2, 2));
        v20 = (cosine < 0.0f) ?
            (v19 + ((v19 < 0.0f) ? MATH_PI : -MATH_PI)) :
            v19;
    }

    eulerAngles->X = v20;
    eulerAngles->Y = v14;
    eulerAngles->Z = atan2f(
        (mtx.GetValue(2, 1) * sine) - (mtx.GetValue(0, 1) * cosine),
        (mtx.GetValue(0, 0) * cosine) - (mtx.GetValue(2, 0) * sine));
}
}
}
