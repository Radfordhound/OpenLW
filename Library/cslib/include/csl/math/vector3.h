#pragma once
#include "math_includes.inl"

namespace csl
{
namespace math
{
struct Vector3_
{
    float X;
    float Y;
    float Z;
};

struct Vector3
{
#ifdef _WIN32
    DXMATH_NAMESPACE XMVECTOR Data;
#endif

    LWAPI(0x1038a440, 0x00feff90)
    static const Vector3 Zero;

    LWAPI(0x1038a450, TODO)
    static const Vector3 One;

    LWAPI(0x1038a460, TODO)
    static const Vector3 NegativeOne;

    LWAPI(0x1038a470, TODO)
    static const Vector3 Right;

    LWAPI(0x1038a480, TODO)
    static const Vector3 Up;

    LWAPI(0x1038a490, TODO)
    static const Vector3 Forward;

#ifdef _WIN32
    __forceinline
#else
    inline
#endif
    void Set(float x, float y, float z)
    {
#ifdef _WIN32
        Data = DXMATH_NAMESPACE XMVectorSet(x, y, z, 0.0f);
#else
        // TODO
#endif
    }

    inline float GetX() const
    {
#ifdef _WIN32
        return DXMATH_NAMESPACE XMVectorGetX(Data);
#else
        // TODO
#endif
    }

    inline float GetY() const
    {
#ifdef _WIN32
        return DXMATH_NAMESPACE XMVectorGetY(Data);
#else
        // TODO
#endif
    }

    inline float GetZ() const
    {
#ifdef _WIN32
        return DXMATH_NAMESPACE XMVectorGetZ(Data);
#else
        // TODO
#endif
    }

    void Copy(const Vector3& other)
    {
        Data = other.Data;
    }

    inline Vector3 operator*(float scale) const
    {
        Vector3 result;

#ifdef _WIN32
        // TODO: Is this correct?
        result.Data = DXMATH_NAMESPACE XMVectorScale(Data, scale);
#else
        // TODO
#endif

        return result;
    }

    //LWAPI(0x0203204C, NONE)
    inline float Length() const
    {
#ifdef _WIN32
        // TODO: Is this correct?
        return DXMATH_NAMESPACE XMVectorGetX(
            DXMATH_NAMESPACE XMVector3ReciprocalLength(Data));
#else
        // TODO: It basically works like this on Wii U, but doesn't actually use this exact code at all:
        //return std::sqrt((X * X) + (Y * Y) + (Z * Z));
#endif
    }

    inline Vector3 operator/(float scale) const
    {
        Vector3 result;

#ifdef _WIN32
        // TODO: Is this correct?
        result.Data = DXMATH_NAMESPACE XMVectorScale(
			Data, 1 / scale);
#else
        // TODO
        //result.Data = PSVECScale(1 / scale);
#endif

        return result;
    }

    inline Vector3 operator+(const Vector3& other) const
    {
        Vector3 result;

#ifdef _WIN32
        // TODO: Is this correct?
        result.Data = DXMATH_NAMESPACE XMVectorAdd(
			Data, other.Data);
#else
        // TODO
#endif

        return result;
    }

    inline Vector3 operator-(const Vector3& other) const
    {
        Vector3 result;

#ifdef _WIN32
        // TODO: Is this correct?
        result.Data = DXMATH_NAMESPACE XMVectorSubtract(
			Data, other.Data);
#else
        // TODO
#endif

        return result;
    }

    inline void Normalize()
    {
#ifdef _WIN32
        Data = DXMATH_NAMESPACE XMVector3Normalize(Data);
#else
        // TODO: Is this correct?
        Copy(*this / Length());
#endif
    }

    inline Vector3() {}

    inline Vector3(float x, float y, float z)
    {
        Set(x, y, z);
    }

    inline Vector3(const Vector3& other)
    {
        Copy(other);
    }
};
}
}
