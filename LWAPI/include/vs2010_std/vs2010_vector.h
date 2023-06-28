#pragma once
#include <vector>

namespace lwapi
{
namespace vs2010_std
{
namespace detail
{
class DummyVectorPadding
{
    char m_DummyVal;
};
} // detail

template<class T, class Allocator = std::allocator<T>>
class vector : public std::vector<T, Allocator>,
    public detail::DummyVectorPadding
{
    using std::vector<T, Allocator>::vector;
};

LWAPI_STATIC_ASSERT_SIZE(vector<int>, 16)
} // vs2010_std
} // lwapi

