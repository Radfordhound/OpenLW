#include "pch.h"
#include "csl/math/quaternion.h"
#include "csl/math/vector3.h"

namespace csl
{
namespace math
{
Quaternion::Quaternion(const Vector3& axis, float angle)
{
    Vector3 normalizedAxis = axis;
    normalizedAxis.Normalize();

    float sine = sinf(angle * 0.5f);
    float cosine = cosf(angle * 0.5f);

    // TODO: Generated machine code is not identical to original, but returns exact same results.
    Set(normalizedAxis.GetX() * sine, normalizedAxis.GetY() * sine,
        normalizedAxis.GetZ() * sine, cosine);
}
}
}
