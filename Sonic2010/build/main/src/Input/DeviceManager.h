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
OPENLW_PRIVATE
    DECLARE_SINGLETON

    struct Impl;
    Impl* m_impl;

public:
    LWAPI(0x022792c0, 0x004f6790)
    ~DeviceManager();

    LWAPI(0x02279218, TODO)
    void Cleanup();

    LWAPI(TODO, TODO)
    void ConnectCheck();

    LWAPI(0x02279e1c, TODO)
    std::size_t GetPortMax() const;

    LWAPI(0x02279dbc, 0x004f6750)
    void Poll(float param_1);

    LWAPI(TODO, TODO)
    void SetConnectCheck(std::size_t portIndex, bool value);

    LWAPI(TODO, TODO)
    void SetPadDeviceCrossAndStick(bool value);
    
    LWAPI(0x022795f4, 0x004f66a0)
    void Setup();

    LWAPI(0x02279F9C, TODO)
    void* GetDeviceData(unsigned int port, unsigned int dataTypeID);

    template<class T>
    T GetDevice(unsigned int port)
    {
        return T(GetDeviceData(port, T::DataTypeID));
    }
};

/**
 * @brief Initializes the DeviceManager Singleton.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
*/
LWAPI(0x0227a10c, TODO)
void* DeviceManager_init();

/**
 * @brief Destroys the DeviceManager Singleton.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
 *
 * @param[in] ptr The pointer to the Singleton.
*/
LWAPI(0x0227a15c, TODO)
void DeviceManager_destroy(void* ptr);
}
}
