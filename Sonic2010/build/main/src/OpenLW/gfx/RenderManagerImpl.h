#pragma once
#include "RenderManager.h"
#include "../fnd/FileLoader.h"
#include <Hedgehog/Utility/hhPackfile.h>
#include <Hedgehog/MTBase/Thread/hhMTJobThreadFactory.h>
#include <boost/scoped_ptr.hpp>

namespace app
{
namespace gfx
{
struct RenderManager::Impl // TODO: Inherit from the appropriate classes. // size == 114448
{
    typedef void (Impl::*UpdateFunc)(const fnd::SUpdateInfo& updateInfo,
        unsigned int param_2);

    // TODO: Other Data Members

    unsigned int Unknown1; // TODO: Is this a uint?
    fnd::SUpdateInfo UpdateInfo;

    // TODO: Other Data Members

    UpdateFunc UpdatePtr;

    bool SkipPresent; // TODO: Is this a good name for this?
    // TODO: Other Data Members
    RenderManager* RenderMgr;
    csl::fnd::com_ptr<fnd::FileHandleObj> field_0xac;
    boost::scoped_ptr<hh::mr::CRenderingInfrastructure> RenderingInfrastructure;
    // TODO: Other Data Members
    hh::MTBase::SJobJoint* JobJoint1;
    hh::MTBase::SJobJoint* JobJoint2;
    // TODO: Other Data Members
    SetupInfo Info;
    // TODO: Other Data Members

    // Wii U: 0x022587fc, PC: 0x004e7a00
    Impl(RenderManager& renderMgr);

    // Wii U: 0x02258d20, PC: TODO
    void LoadShader();

    // Wii U: 0x02258d94, PC: TODO
    void Initialize();

    // Wii U: 0x02258eac, PC: TODO
    void Setup(const SetupInfo& setupInfo);

    // Wii U: 0x02258f08, PC: TODO
    void Finalize();

    // Wii U: 0x02258fc4 (THUNK), PC: TODO
    void Shutdown();

    // Wii U: 0x02259ea8, PC: TODO
    void Update(const fnd::SUpdateInfo& updateInfo, unsigned int param_2);

    // Wii U: 0x0225a020, PC: TODO
    hh::ut::Packfile GetShaderFileResource() const;

    // Wii U: 0x0225a670, PC: TODO
    void PrepareRenderSchedule();

    // Wii U: 0x02261fdc, PC: TODO
    void Update_RunOnRenderInternal(const fnd::SUpdateInfo& updateInfo,
        unsigned int param_2);

    // Wii U: 0x0226349c, PC: 0x004edf40
    void RenderNoPresent();

    // Wii U: 0x02263cc0, PC: TODO
    void Present();

    // Wii U: 0x0226bd5c, PC: TODO
    bool SetupShader();

    // Wii U: 0x0226bf5c, PC: TODO
    void Update_Init(const fnd::SUpdateInfo& updateInfo, unsigned int param_2);

    // Wii U: 0x0226bfd0, PC: TODO
    void Update_Run(const fnd::SUpdateInfo& updateInfo, unsigned int param_2);
};
}
}