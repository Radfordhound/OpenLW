// TODO: Both the name of this file and its path were guessed!
#include "OpenLW/pch.h"
#include "Property.h"

namespace app
{
namespace fnd
{
unsigned int Property::MapStringToKey(char const* str)
{
    // Sonic Team's favorite hash function.
    unsigned int key = 0;
    while (*str != '\0')
    {
        key = ((key * 31) + *str);
        ++str;
    }

    return (key & INT_MAX);
}
} // fnd
} // app
