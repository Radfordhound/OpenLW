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
struct Vector3_
{
    float X;
    float Y;
    float Z;
};

struct Vector3
{
#ifdef _WIN32
    XMVECTOR Data;
#endif

    // Wii U: 0x1038a440, PC: 0x00feff90
    static const Vector3 Zero;

    // Wii U: 0x1038a450, PC: TODO
    static const Vector3 One;

    // Wii U: 0x1038a460, PC: TODO
    static const Vector3 NegativeOne;

    // Wii U: 0x1038a470, PC: TODO
    static const Vector3 Right;

    // Wii U: 0x1038a480, PC: TODO
    static const Vector3 Up;

    // Wii U: 0x1038a490, PC: TODO
    static const Vector3 Forward;

    // Wii U: Inlined, PC: Inlined
#ifdef _WIN32
    __forceinline
#else
    inline
#endif
    void Set(float x, float y, float z)
    {
#ifdef _WIN32
        Data = XMVectorSet(x, y, z, 0.0f);
#else
        // TODO
#endif
    }

    // Wii U: Inlined, PC: Inlined
    inline float GetX() const
    {
#ifdef _WIN32
        return XMVectorGetX(Data);
#else
        // TODO
#endif
    }

    // Wii U: Inlined, PC: Inlined
    inline float GetY() const
    {
#ifdef _WIN32
        return XMVectorGetY(Data);
#else
        // TODO
#endif
    }

    // Wii U: Inlined, PC: Inlined
    inline float GetZ() const
    {
#ifdef _WIN32
        return XMVectorGetZ(Data);
#else
        // TODO
#endif
    }

    // Wii U: Inlined, PC: Inlined
    void Copy(const Vector3& other)
    {
        Data = other.Data;
    }

    // Wii U: 0x020235AC, PC: Inlined
    Vector3 operator*(float scale) const
    {
        Vector3 result;

#ifdef _WIN32
        // TODO: Is this correct?
        result.Data = XMVectorScale(Data, scale);
#else
        // TODO
#endif

        return result;
    }

    // Wii U: 0x0203204C, PC: Inlined
    float Length() const
    {
#ifdef _WIN32
        // TODO: Is this correct?
        return XMVectorGetX(XMVector3ReciprocalLength(Data));
#else
        // TODO: It basically works like this on Wii U, but doesn't actually use this exact code at all:
        //return std::sqrt((X * X) + (Y * Y) + (Z * Z));
#endif
    }

    // Wii U: 0x02032050, PC: Inlined
    Vector3 operator/(float scale) const
    {
        Vector3 result;

#ifdef _WIN32
        // TODO: Is this correct?
        result.Data = XMVectorScale(Data, 1 / scale);
#else
        // TODO
        //result.Data = PSVECScale(1 / scale);
#endif

        return result;
    }

    // Wii U: Inlined, PC: Inlined
    inline void Normalize()
    {
#ifdef _WIN32
        Data = XMVector3Normalize(Data);
#else
        // TODO: Is this correct?
        Copy(*this / Length());
#endif
    }

    // Wii U: Inlined, PC: Inlined
    inline Vector3() {}

    // Wii U: Inlined, PC: Inlined
    inline Vector3(float x, float y, float z)
    {
        Set(x, y, z);
    }

    // Wii U: Inlined, PC: Inlined
    inline Vector3(const Vector3& other)
    {
        Copy(other);
    }
};
}
}
