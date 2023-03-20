// TODO: The name of this file is correct, but the path was guessed!
// NOTE: This file appears to be included in Wii U builds also, just disabled.
#include "pch.h"
#ifdef _WIN32
#include "DevicePadWin.h"

namespace app
{
namespace hid
{
DevicePadWin::~DevicePadWin()
{
    // TODO
}

std::size_t DevicePadWin::GetPortMax() const
{
    return 4;
}

void DevicePadWin::GetDeviceData(ResDeviceData* devices, std::size_t deviceCount)
{
    // TODO
}

DevicePadWin::DevicePadWin(void* instHandle, void* surfaceHandle)
{
    // TODO
}
}
}
#endif
