#pragma once
#include "fnd/ReferencedObject.h"
#include "fnd/Singleton.h"

namespace app
{
class CriSystem : public fnd::ReferencedObject, public csl::fnd::Singleton<CriSystem>
{
    DECLARE_SINGLETON_INIT

    struct Impl;
    Impl* impl = nullptr;

public:
    /*
        @brief Constructor for CriSystem.
        <b>Wii U: TODO, PC: TODO</b>
    */
    CriSystem();

    /* <b>Wii U: 0x021cae44, PC: TODO</b> */
    void* GetClient() const;

    /* <b>Wii U: 0x021cae58, PC: TODO</b> */
    unsigned int GetErrorCode() const;

    /* <b>Wii U: 0x021caec8, PC: TODO</b> */
    bool IsASR() const;

    /* <b>Wii U: 0x021caeb0, PC: TODO</b> */
    void ResetErrorCode();

    /* <b>Wii U: 0x021caf44, PC: TODO</b> */
    void ResetServerThread();

    /* <b>Wii U: 0x021caee8, PC: TODO</b> */
    void SetDefaultServerThread();

    /* <b>Wii U: 0x021cae6c, PC: TODO</b> */
    void SetErrorCode();

    /* <b>Wii U: 0x021cae34, PC: TODO</b> */
    void Update();
};
}
