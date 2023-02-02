#pragma once
#include "vector3.h"

namespace csl
{
namespace math
{
struct Quaternion;

#ifdef _WIN32
__declspec(align(16))
#endif
struct Matrix34
{
#ifdef _WIN32
    XMMATRIX Data;
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
        return Data.m[column][row];
#else
        // TODO: It seems on Wii U, they use column-major order?
        // return Data.m[row][column];
#endif
    }

    // Wii U: 0x02C9E3C4, PC: 0x00961130
    Vector3 GetRow(int index) const;

    // Wii U: 0x02C9E45C, PC: TODO
    Vector3 GetColumn(int index) const;

    // Wii U: Inlined, PC: Inlined
    inline Matrix34() {}

    // TODO: Is this constructor actually a thing?
    Matrix34(const Quaternion& rot);
};
}
}
