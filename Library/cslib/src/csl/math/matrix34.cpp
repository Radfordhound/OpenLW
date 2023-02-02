#include "csl/math/matrix34.h"
#include "csl/math/quaternion.h"

namespace csl
{
namespace math
{
Vector3 Matrix34::GetRow(int index) const
{
#ifdef _WIN32
    // TODO: Generated machine code is not identical to original, but returns exact same results.
    return Vector3(Data.m[0][index], Data.m[1][index], Data.m[2][index]);
#else
    // TODO: On Wii U, it seems they use column-major order?
#endif
}

Vector3 Matrix34::GetColumn(int index) const
{
    Vector3 result;

#ifdef _WIN32
    // TODO: This was guessed; is this correct?
    return Vector3(Data.m[index][0], Data.m[index][1], Data.m[index][2]);
#else
    // TODO: On Wii U, it seems they use column-major order?
#endif

    return result;
}

Matrix34::Matrix34(const Quaternion& rot)
{
#ifdef _WIN32
    Data = XMMatrixRotationQuaternion(rot.Data);
#else
    // TODO
#endif
}
}
}
