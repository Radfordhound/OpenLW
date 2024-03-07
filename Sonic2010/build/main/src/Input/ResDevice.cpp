// TODO: The name of this file is correct, but the path was guessed!
#include "OpenLW/pch.h"
#include "Input/ResDevice.h"

namespace app
{
namespace hid
{
const unsigned int ResPadDevice::DataTypeID = 0;

bool ResPadDevice::IsValid() const
{
    if (ResCommon::IsValid())
    {
        return (ref().field_0x24 != 1);
    }

    return false;
}
} // hid
} // app
