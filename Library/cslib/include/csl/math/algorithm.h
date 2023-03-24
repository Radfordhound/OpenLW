// TODO: Both the name of this file and its path were guessed!
#pragma once
namespace csl
{
namespace math
{
template<typename T>
inline const T& Min(const T& a, const T& b)
{
    return (b < a) ? b : a;
}

template<typename T>
inline T& Min(T& a, T& b)
{
    return (b < a) ? b : a;
}

template<typename T>
inline const T& Max(const T& a, const T& b)
{
    return (a < b) ? b : a;
}

template<typename T>
inline T& Max(T& a, T& b)
{
    return (a < b) ? b : a;
}
} // math
} // csl
