// TODO: The name of this file is correct, but the path was guessed!
#pragma once

namespace csl
{
namespace math
{
struct Vector2_
{
    float X;
    float Y;
};

struct Vector2
{
	float Data[2];

#ifdef _WIN32
    __forceinline
#else
    inline
#endif
    void Set(float x, float y)
    {
		Data[0] = x;
		Data[1] = y;
    }

    inline float GetX() const
    {
		return Data[0];
    }

    inline float GetY() const
    {
		return Data[1];
    }

    void Copy(const Vector2& other)
    {
        Data[0] = other.Data[0];
		Data[1] = other.Data[1];
    }

    inline Vector2 operator*(float scale) const
    {
        Vector2 result;
		result.Data[0] = (Data[0] * scale);
		result.Data[1] = (Data[1] * scale);
		return result;
    }

    inline float Length() const
    {
		// TODO
		return 0.0f;
    }

    inline Vector2 operator/(float scale) const
    {
        Vector2 result;
		result.Data[0] = (Data[0] / scale);
		result.Data[1] = (Data[1] / scale);
		return result;
    }

    inline Vector2 operator+(const Vector2& other) const
    {
        Vector2 result;
		result.Data[0] = (Data[0] + other.Data[0]);
		result.Data[1] = (Data[1] + other.Data[1]);
		return result;
    }

    inline Vector2 operator-(const Vector2& other) const
    {
        Vector2 result;
		result.Data[0] = (Data[0] - other.Data[0]);
		result.Data[1] = (Data[1] - other.Data[1]);
		return result;
    }

    inline void Normalize()
    {
		// TODO
    }

    inline Vector2() {}

    inline Vector2(float x, float y)
    {
        Set(x, y);
    }

    inline Vector2(const Vector2& other)
    {
        Copy(other);
    }
};

LWAPI_STATIC_ASSERT_SIZE(Vector2, 8)
} // math
} // csl
