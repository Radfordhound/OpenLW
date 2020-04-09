#pragma once

namespace app
{
namespace fnd
{
namespace file
{
/*
    @brief Converts backslashes in the given path to forward slashes.
    @param[in] path     The path to convert.
    <b>Wii U: 0x0218eed0, PC: TODO</b>
*/
void ConvertPath(char* path);
}
}
}
