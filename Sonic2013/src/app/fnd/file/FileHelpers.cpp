#include "FileHelpers.h"

namespace app
{
namespace fnd
{
namespace file
{
void ConvertPath(char* path)
{
    while (*path)
    {
        if (*path == '\\')
        {
            *path = '/';
        }

        ++path;
    }
}
}
}
}
