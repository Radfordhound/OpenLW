#include "pch.h"
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
    const auto& xmMtx = reinterpret_cast<const DXMATH_NAMESPACE XMFLOAT4X4&>(Data);
    return Vector3(xmMtx(0, index), xmMtx(1, index), xmMtx(2, index));
#else
    // TODO: On Wii U, it seems they use column-major order?
#endif
}

Vector3 Matrix34::GetColumn(int index) const
{
    Vector3 result;

#ifdef _WIN32
    // TODO: This was guessed; is this correct?
    const auto& xmMtx = reinterpret_cast<const DXMATH_NAMESPACE XMFLOAT4X4&>(Data);
    return Vector3(xmMtx(index, 0), xmMtx(index, 1), xmMtx(index, 2));
#else
    // TODO: On Wii U, it seems they use column-major order?
#endif

    return result;
}

Matrix34::Matrix34(const Quaternion& rot)
{
#ifdef _WIN32
    Data = DXMATH_NAMESPACE XMMatrixRotationQuaternion(rot.Data);
#else
    // TODO
#endif
}
}
}
