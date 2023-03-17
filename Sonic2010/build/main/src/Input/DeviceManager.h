// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "System/ReferencedObject.h"
#include "System/Singleton.h"

namespace app
{
namespace hid
{
class DeviceManager : public fnd::ReferencedObject, public csl::fnd::Singleton<DeviceManager>
{
    DECLARE_SINGLETON

    struct Impl;
    Impl* m_impl;

public:
    // Wii U: 0x022792c0, PC: 0x004f6790
    ~DeviceManager();

    // Wii U: 0x02279218, PC: TODO
    void Cleanup();

    // Wii U: TODO, PC: TODO
    void ConnectCheck();

    // Wii U: 0x02279e1c, PC: TODO
    std::size_t GetPortMax() const;

    // Wii U: 0x02279dbc, PC: 0x004f6750
    void Poll(float param_1);

    // Wii U: TODO, PC: TODO
    void SetConnectCheck(std::size_t portIndex, bool value);

    // Wii U: TODO, PC: TODO
    void SetPadDeviceCrossAndStick(bool value);
    
    // Wii U: 0x022795f4, PC: 0x004f66a0
    void Setup();
};
}
}
