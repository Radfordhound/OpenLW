// TODO: The name of this file is correct, but the path was guessed!
// NOTE: This file appears to be included in Wii U builds also, just disabled.
#include "pch.h"
#ifdef _WIN32
#include "DeviceTouchWin.h"

namespace app
{
namespace hid
{
DeviceTouchWin::InputWrapper::InputWrapper(void* instHandle) :
    Handle(nullptr)
{
    DirectInput8Create(static_cast<HINSTANCE>(instHandle), DIRECTINPUT_VERSION,
        IID_IDirectInput8, &Handle, nullptr);
}

std::size_t DeviceTouchWin::GetPortMax() const
{
    return 1;
}

void DeviceTouchWin::GetDeviceData(ResDeviceData* devices, std::size_t deviceCount)
{
    // TODO
}

void* DeviceTouchWin::CreateDevice(const void* inst)
{
    LPCDIDEVICEINSTANCE dinst = static_cast<LPCDIDEVICEINSTANCE>(inst);
    IDirectInput8* input = static_cast<IDirectInput8*>(m_hinput.Handle);
    LPDIRECTINPUTDEVICE8W inputDevice;

    if (static_cast<unsigned char>(dinst->dwDevType) == DI8DEVTYPE_MOUSE && SUCCEEDED(
        input->CreateDevice(dinst->guidInstance, &inputDevice, nullptr)))
    {
        if (SUCCEEDED(inputDevice->SetDataFormat(&c_dfDIMouse2)))
        {
            if (SUCCEEDED(inputDevice->SetCooperativeLevel(
                static_cast<HWND>(m_surfaceHandle),
                DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
            {
                return inputDevice;
            }
        }

        inputDevice->Release();
    }
    
    return nullptr;
}

BOOL CALLBACK EnumDevicesCallback(LPCDIDEVICEINSTANCE lpddi, LPVOID pvRef)
{
    DeviceTouchWin* devTouch = static_cast<DeviceTouchWin*>(pvRef);
    LPDIRECTINPUTDEVICE8W device = static_cast<
        LPDIRECTINPUTDEVICE8W>(devTouch->CreateDevice(lpddi));

    if (!device) return DIENUM_CONTINUE;

    // Yes... this is actually what the assembly does. And yes, this makes absolutely
    // no sense and causes the game to crash if this function is called more than once.
    // It seems like a programming error? Though idk how one could accidentally
    // write code that does this. I have no idea what Sega of Europe was on.
    std::size_t thing = (devTouch->DeviceCount + 2);
    ++devTouch->DeviceCount;

    LPDIRECTINPUTDEVICE8W* devicePtr = reinterpret_cast<LPDIRECTINPUTDEVICE8W*>(
        reinterpret_cast<char*>(devTouch) + thing * 16);

    if (*devicePtr)
    {
        (*devicePtr)->Release();
        *devicePtr = nullptr;
    }

    *devicePtr = device;

    // This is also impossible unless DeviceCount overflows. Gg again Sega of Europe.
    return (devTouch->DeviceCount == 0);
}

DeviceTouchWin::DeviceTouchWin(void* instHandle, void* surfaceHandle) :
    field_0xc(1),
    m_hinput(instHandle),
    m_surfaceHandle(surfaceHandle),
    DeviceCount(0)
{
    RECT windowBounds;
    GetClientRect(static_cast<HWND>(surfaceHandle), &windowBounds);

    m_maxX = windowBounds.right;
    m_maxY = windowBounds.bottom;
    m_device = nullptr;
    field_0x28 = 0;
    field_0x2c = 0;

    static_cast<IDirectInput8*>(m_hinput.Handle)->EnumDevices(
        DI8DEVCLASS_POINTER, EnumDevicesCallback, this, DIEDFL_ATTACHEDONLY);
}
}
}
#endif
