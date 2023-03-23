// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once
#include <csl/ut/bitset.h>
#include <csl/math/vector3.h>
#include <csl/math/vector2.h>
#include <Hedgehog/Base/System/hhObject.h>
#include <Hedgehog/Base/System/hhMemory.h>

namespace csl
{
namespace fnd
{
struct IAllocator;
} // fnd
} // csl

namespace app
{
namespace fnd
{
struct SUpdateInfo;
struct Message;
} // fnd

namespace Camera
{
class CCamera;
struct EnterEventArgs;
struct SPlayer3DCameraParam;
struct SPlayer3DCameraParamDashMode;

struct CCameraController : hh::base::CRefCountObject
{
    CCamera* m_camera;
    float m_fovy;
    csl::math::Vector3 m_pos;
    csl::math::Vector3 m_up;
    csl::math::Vector3 m_targetPos;
    void* field_0x40;
    csl::fnd::IAllocator* m_debugAllocator;
    csl::math::Vector2 field_0x48;
    bool field_0x50;
    bool m_isActive;
    csl::ut::Bitset<unsigned int> m_flags;
    char padding1[8]; // TODO

    // Wii U: 0x02035DD0, PC: TODO
    static void* operator new(std::size_t size);

    // Wii U: 0x02035E0C, PC: TODO
    static void operator delete(void* ptr);

    // Wii U: 0x02035E44, PC: TODO
    static void* operator new(std::size_t size, const CHedgehogMemoryAllocatorFileLine& param_2, CHedgehogMemoryAllocatorHeap param_3);

    // Wii U: 0x02035EC8, PC: TODO
    CCameraController();

    // Wii U: 0x02035FB4, PC: TODO
    ~CCameraController();

    // Wii U: 0x02036008, PC: TODO
    virtual void ResetCamera(csl::math::Vector3& param_1, csl::math::Vector3& param_2);

    // Wii U: 0x0203600C, PC: TODO
    virtual void RestartCamera();

    // Wii U: 0x02036010, PC: TODO
    virtual void Update(const fnd::SUpdateInfo& param_1);

    // Wii U: 0x02036014, PC: TODO
    void SetActive(bool param_1);

    // Wii U: 0x0203601C, PC: 0x00419BA0
    virtual void OnEnter(EnterEventArgs& param_1);

    // Wii U: 0x02036024, PC: TODO
    virtual void OnLeave();

    // Wii U: 0x0203602C, PC: TODO
    virtual void BeginBoostCamera();

    // Wii U: 0x02036030, PC: TODO
    virtual void EndBoostCamera();

    // Wii U: 0x02036034, PC: TODO
    virtual void BeginQuickStep();

    // Wii U: 0x02036038, PC: TODO
    virtual void EndQuickStep();

    // Wii U: 0x0203603C, PC: TODO
    virtual void Set3DCameraParam(const SPlayer3DCameraParam& param_1);

    // Wii U: 0x02036040, PC: TODO
    virtual void Set3DCameraParamDashMode(const SPlayer3DCameraParamDashMode& param_1);

    // Wii U: 0x02036044, PC: TODO
    virtual void SetCameraReset(const csl::math::Vector3& param_1, const csl::math::Vector3& param_2);

    // Wii U: 0x02036048, PC: TODO
    virtual bool IsDistFar();

    // Wii U: 0x02036050, PC: TODO
    virtual void FocusChange();

    // Wii U: 0x02036054, PC: TODO
    void GetFovy() const;

    // Wii U: 0x0203605C, PC: TODO
    void GetCameraParam(csl::math::Vector3& param_1, csl::math::Vector3& param_2, csl::math::Vector3& param_3);

    // Wii U: 0x020360D0, PC: TODO
    void SetCollisionEnable(bool param_1);

    // Wii U: 0x02036104, PC: TODO
    void IsCollisionEnable() const;

    // Wii U: 0x02036110, PC: TODO
    void SetPhantomCamera();

    // Wii U: 0x0203611C, PC: TODO
    void IsPhantomCamera() const;

    // Wii U: 0x02036128, PC: TODO
    void SetDebugCamera();

    // Wii U: 0x02036134, PC: TODO
    void IsDebugCamera() const;

    // Wii U: 0x02036140, PC: TODO
    void SetMultiCamera();

    // Wii U: 0x0203614C, PC: TODO
    void IsMultiCamera() const;

    // Wii U: 0x02036158, PC: TODO
    void SetPreview();

    // Wii U: 0x02036164, PC: TODO
    void IsPreview() const;

    // Wii U: 0x02036170, PC: TODO
    virtual bool ProcessMessage(fnd::Message& param_1);

    // Wii U: 0x02036178, PC: TODO
    void SetFovy(float param_1);

    // Wii U: 0x02036180, PC: TODO
    void SetCameraParam(const csl::math::Vector3& param_1, const csl::math::Vector3& param_2, const csl::math::Vector3& param_3);

    // Wii U: 0x020361C0, PC: TODO
    void GetCameraTargetPositionForPlayer(bool param_1);

    // Wii U: 0x02036220, PC: TODO
    void GetCameraVelocityForPlayer(csl::math::Vector3& param_1);

    // Wii U: 0x02036238, PC: TODO
    void GetCameraDirectionForPlayer(csl::math::Vector3& param_1, csl::math::Vector3& param_2, csl::math::Vector3& param_3);
};
} // Camera
} // app
