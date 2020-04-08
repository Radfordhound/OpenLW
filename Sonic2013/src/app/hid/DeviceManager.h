#pragma once
#include "../fnd/ReferencedObject.h"
#include "../fnd/Singleton.h"

namespace app
{
namespace hid
{
class DeviceManager : public fnd::ReferencedObject, public csl::fnd::Singleton<DeviceManager>
{
    DECLARE_SINGLETON_INIT

    struct Impl;
    Impl* impl = nullptr;

public:
    // TODO: Explicit destructor?

    /* <b>Wii U: TODO, PC: TODO</b> */
    void Setup();

    /* <b>Wii U: 0x02279dbc, PC: 0x004f6750</b> */
    void Poll(float param_1);
    // TODO
};
}
}
