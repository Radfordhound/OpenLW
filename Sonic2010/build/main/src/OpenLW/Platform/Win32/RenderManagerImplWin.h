#pragma once
#include "../../fnd/FileLoader.h"
#include "../../fnd/ResourceManager.h"
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
    csl::fnd::com_ptr<fnd::FileHandleObj> field_0xac;
    boost::scoped_ptr<hh::mr::CRenderingInfrastructure> RenderingInfrastructure;
    // TODO: Other Data Members
    hh::MTBase::SJobJoint* JobJoint1;
    hh::MTBase::SJobJoint* JobJoint2;
    // TODO: Other Data Members
    SetupInfo Info;
    // TODO: Other Data Members

    // Wii U: 0x02263cc0, PC: TODO
    void Present()
    {
        if (!SkipPresent)
        {
            RenderingInfrastructure->Present();
        }
    }

    // Wii U: TODO, PC: 0x004edf40
    void RenderNoPresent()
    {
        if (SkipPresent) return;

        Update_RunOnRenderInternal(UpdateInfo, Unknown1);
        // TODO
    }

    // Wii U: 0x02258d20, PC: TODO
    void LoadShader()
    {
        fnd::FileLoader* fileLoader = fnd::FileLoader::GetInstance();

        fnd::FileLoaderParam fileLoadParams;
        fileLoadParams.field_0xc = 0x1000;

        field_0xac = fileLoader->LoadFile(Info.ShaderName, fileLoadParams);
    }

    // Wii U: 0x02258d94, PC: TODO
    void Initialize()
    {
        // TODO
        LoadShader();
        // TODO
    }

    // Wii U: 0x02258eac, PC: TODO
    void Setup(const SetupInfo& setupInfo)
    {
        Info = setupInfo;
        Initialize();
    }

    // Wii U: 0x0225a020, PC: TODO
    hh::ut::Packfile GetShaderFileResource() const
    {
        fnd::ResourceManager* resMgr = fnd::ResourceManager::GetInstance();
        return hh::ut::Packfile(resMgr->Get<fnd::ResRawData>(Info.ShaderName).GetAddress());
    }

    // Wii U: 0x0226bd5c, PC: TODO
    bool SetupShader()
    {
        fnd::FileLoader* fileLoader = fnd::FileLoader::GetInstance();
        if (fileLoader->IsSyncComplete(field_0xac))
        {
            fileLoader->WaitSync(field_0xac);

            hh::ut::Packfile shaderFileRes = GetShaderFileResource();

            // TODO
            return true;
        }

        return false;
    }

    // Wii U: 0x02259ea8, PC: TODO
    void Update(const fnd::SUpdateInfo& updateInfo, unsigned int param_2)
    {
        // TODO
        (this->*UpdatePtr)(updateInfo, param_2); // TODO: This isn't correct!!
    }

    // Wii U: 0x0226bf5c, PC: TODO
    void Update_Init(const fnd::SUpdateInfo& updateInfo, unsigned int param_2)
    {
        if (SetupShader())
        {
            // TODO
            UpdatePtr = &Impl::Update_Run;
        }
    }

    // Wii U: 0x0226bfd0, PC: TODO
    void Update_Run(const fnd::SUpdateInfo& updateInfo, unsigned int param_2)
    {
        // TODO
        SkipPresent = false;
        // TODO
    }

    // Wii U: 0x02261fdc, PC: TODO
    void Update_RunOnRenderInternal(const fnd::SUpdateInfo& updateInfo,
        unsigned int param_2)
    {
        // TODO
        PrepareRenderSchedule();
        // TODO
    }

    // Wii U: 0x0225a670, PC: TODO
    void PrepareRenderSchedule()
    {
        hh::MTBase::hhMTSimpleJobBlockUntilSignal(JobJoint1, 0);
        hh::MTBase::hhMTSimpleJobBlockUntilSignal(JobJoint2, 0);
    }

    // TODO: Other Functions

    // Wii U: 0x02258f08, PC: TODO
    void Finalize()
    {
        // TODO
    }

    // Wii U: 0x02258fc4 (THUNK), PC: TODO
    void Shutdown()
    {
        Finalize();
    }

    // Wii U: 0x022587fc, PC: 0x004e7a00
    Impl(RenderManager& renderMgr)
    {
        // TODO
        SkipPresent = true;
        UpdatePtr = &Impl::Update_Init;
        // TODO

        JobJoint1 = hh::MTBase::hhMTSimpleJobJointStaticCreate(
            "m_evehtJointSchedulerHandle");

        JobJoint2 = hh::MTBase::hhMTSimpleJobJointStaticCreate(
            "m_evehtJointPostFrameHandle");

        // TODO
        RenderingInfrastructure.reset(new hh::mr::CRenderingInfrastructure());
        // TODO
    }
};
}
}
