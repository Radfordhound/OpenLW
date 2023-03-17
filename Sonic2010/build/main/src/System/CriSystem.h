// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#ifdef USE_CRIWARE
#include "ReferencedObject.h"
#include "Singleton.h"

namespace app
{
class CriSystem : public fnd::ReferencedObject, public csl::fnd::Singleton<CriSystem> // size == 16
{
    DECLARE_SINGLETON

    struct Impl;
    Impl* m_impl;

public:
    // Wii U: 0x021cad54, PC: TODO
    ~CriSystem();

    // Wii U: 0x021cae44, PC: TODO
    void* GetClient() const;

    // Wii U: 0x021cae58, PC: TODO
    unsigned int GetErrorCode() const;

    // Wii U: 0x021caec8, PC: TODO
    bool IsASR() const;

    // Wii U: 0x021caeb0, PC: TODO
    void ResetErrorCode();

    // Wii U: 0x021caf44, PC: TODO
    void ResetServerThread();

    // Wii U: 0x021caee8, PC: TODO
    void SetDefaultServerThread();

    // Wii U: 0x021cae6c, PC: TODO
    void SetErrorCode();

    // Wii U: 0x021cae34, PC: TODO
    void Update();

    // Wii U: 0x021cab0c, PC: TODO
    CriSystem();
};
}
#endif
