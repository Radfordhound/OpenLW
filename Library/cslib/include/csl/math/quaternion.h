#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <xnamath.h>
#endif

namespace csl
{
namespace math
{
struct Vector3;

struct Quaternion
{
#ifdef _WIN32
    XMVECTOR Data;
#endif

    // Wii U: Inlined, PC: Inlined
    void Copy(const Quaternion& other)
    {
        Data = other.Data;
    }

    // Wii U: Inlined, PC: Inlined
    void Set(float x, float y, float z, float w)
    {
#ifdef _WIN32
        Data = XMVectorSet(x, y, z, w);
#else
        // TODO
#endif
    }

    // Wii U: 0x020E7238, PC: TODO
    Quaternion operator*(const Quaternion& other) const
    {
        Quaternion result;

#ifdef _WIN32
        // TODO: Is this correct?
        result.Data = XMQuaternionMultiply(Data, other.Data);
#else
        // TODO
#endif

        return result;
    }

    // Wii U: Inlined, PC: Inlined
    inline Quaternion() {}

    // Wii U: 0x022F16D0, PC: Inlined
    Quaternion(const Quaternion& other)
    {
        Copy(other);
    }

    // Wii U: 0x02CA2338, PC: 0x00964060
    Quaternion(const Vector3& axis, float angle);
};
}
}
