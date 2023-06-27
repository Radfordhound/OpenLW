// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "vector3.h"

namespace csl
{
namespace math
{
struct Quaternion;

struct Matrix34
{
#ifdef _WIN32
    DXMATH_NAMESPACE XMMATRIX Data;
#endif

    // TODO: Is this function actually a thing?
#ifdef _WIN32
    __forceinline
#else
    inline
#endif
    float GetValue(int row, int column) const
    {
#ifdef _WIN32
        return reinterpret_cast<const DXMATH_NAMESPACE XMFLOAT4X4&>(
            Data)(column, row);
#else
        // TODO: It seems on Wii U, they use column-major order?
        // return Data.m[row][column];
#endif
    }

    LWAPI(0x02C9E3C4, 0x00961130)
    Vector3 GetRow(int index) const;

    LWAPI(0x02C9E45C, TODO)
    Vector3 GetColumn(int index) const;

    inline Matrix34() {}

    // TODO: Is this constructor actually a thing?
    Matrix34(const Quaternion& rot)
    {
    #ifdef _WIN32
        Data = DXMATH_NAMESPACE XMMatrixRotationQuaternion(
            reinterpret_cast<const DXMATH_NAMESPACE XMVECTOR&>(Data));
    #else
        // TODO
    #endif
    }
};

LWAPI_STATIC_ASSERT_SIZE(Matrix34, 64)
} // math
} // csl
