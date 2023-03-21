#pragma once
#include "math_includes.inl"

namespace csl
{
namespace math
{
struct Vector3;

struct Quaternion
{
#ifdef _WIN32
    DXMATH_NAMESPACE XMVECTOR Data;
#endif

    void Copy(const Quaternion& other)
    {
        Data = other.Data;
    }

    void Set(float x, float y, float z, float w)
    {
#ifdef _WIN32
        Data = DXMATH_NAMESPACE XMVectorSet(x, y, z, w);
#else
        // TODO
#endif
    }

    LWAPI(0x020E7238, TODO)
    Quaternion operator*(const Quaternion& other) const
    {
        Quaternion result;

#ifdef _WIN32
        // TODO: Is this correct?
        result.Data = DXMATH_NAMESPACE XMQuaternionMultiply(
			Data, other.Data);
#else
        // TODO
#endif

        return result;
    }

    inline Quaternion() {}

    LWAPI(0x022F16D0, NONE)
    Quaternion(const Quaternion& other)
    {
        Copy(other);
    }

    LWAPI(0x02CA2338, 0x00964060)
    Quaternion(const Vector3& axis, float angle);
};
}
}
