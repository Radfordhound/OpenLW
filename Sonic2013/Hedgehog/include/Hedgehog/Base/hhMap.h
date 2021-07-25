#pragma once
#include "System/hhAllocator.h"
#include <map>
#include <functional>
#include <utility>

namespace hh
{
template<typename key_t, typename val_t,
    typename allocator_t = base::TAllocator<std::pair<const key_t, val_t>>>
class map : public std::map<key_t, val_t, std::less<key_t>, allocator_t>
{
public:
    map() : std::map<key_t, val_t, std::less<key_t>, allocator_t>() {}

    // TODO: Other constructors and such??
};

}
