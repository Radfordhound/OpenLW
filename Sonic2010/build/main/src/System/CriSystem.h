// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#ifdef USE_CRIWARE
#include "ReferencedObject.h"
#include "Singleton.h"

namespace app
{
class CriSystem : public fnd::ReferencedObject, public csl::fnd::Singleton<CriSystem> // size == 16
{
LWAPI_PRIVATE
    DECLARE_SINGLETON

    struct Impl;
    Impl* m_impl;

public:
    LWAPI(0x021cad54, TODO)
    ~CriSystem();

    LWAPI(0x021cae44, TODO)
    void* GetClient() const;

    LWAPI(0x021cae58, TODO)
    unsigned int GetErrorCode() const;

    LWAPI(0x021caec8, TODO)
    bool IsASR() const;

    LWAPI(0x021caeb0, TODO)
    void ResetErrorCode();

    LWAPI(0x021caf44, TODO)
    void ResetServerThread();

    LWAPI(0x021caee8, TODO)
    void SetDefaultServerThread();

    LWAPI(0x021cae6c, TODO)
    void SetErrorCode();

    LWAPI(0x021cae34, TODO)
    void Update();

    LWAPI(0x021cab0c, TODO)
    CriSystem();
};
}
#endif
