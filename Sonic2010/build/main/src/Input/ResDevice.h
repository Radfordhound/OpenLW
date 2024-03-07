// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "DeviceData.h"
#include <Hedgehog/Utility/hhResCommon.h>

namespace app
{
namespace hid
{
class ResPadDevice : public hh::ut::ResCommon<ResPadDeviceData>
{
public:
    LWAPI(TODO, TODO)
    static const unsigned int DataTypeID;

    LWAPI(0x0227a1d4, TODO)
    bool IsValid() const;

    inline ResPadDevice(void* ptr) :
        ResCommon(ptr) {}
};
} // hid
} // app
