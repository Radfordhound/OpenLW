#pragma once
#include "MoveArray.h"

namespace csl
{
namespace ut
{
template<typename T, std::size_t bufferSize>
class InplaceMoveArray : public MoveArray<T>
{
    T buffer[bufferSize];

public:
    inline InplaceMoveArray(std::size_t count = 0) : MoveArray<T>(
        buffer, count, bufferSize, nullptr) {}
};
}
}
