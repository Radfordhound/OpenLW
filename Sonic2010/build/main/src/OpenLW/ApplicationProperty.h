#pragma once
#include "fnd/ReferencedObject.h"
#include "fnd/Singleton.h"
#include <csl/ut/string.h>

namespace app
{
struct ApplicationPropertyImpl;

class ApplicationProperty : public fnd::ReferencedObject,
    public csl::fnd::Singleton<ApplicationProperty>
{
    DECLARE_SINGLETON

    ApplicationPropertyImpl* m_impl;

public:
    // Wii U: 0x021c7a50, PC: Inlined
    ApplicationProperty();
};
}
