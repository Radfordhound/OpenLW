#include "ApplicationProperty.h"
#include "ApplicationPropertyImpl.h"

using namespace app::fnd;

namespace app
{
ApplicationProperty::ApplicationProperty()
{
    m_impl = new ApplicationPropertyImpl(m_allocator);
}

// Wii U: 0x021c8354, PC: TODO
void* ApplicationProperty_init()
{
    ApplicationProperty* appProperty = new (GetSingletonAllocator()) ApplicationProperty();
    appProperty->AddRef();
    return appProperty;
}

// Wii U: 0x021c83a4 (THUNK), PC: TODO
void ApplicationProperty_destroy(void* ptr)
{
    static_cast<ApplicationProperty*>(ptr)->Release();
}

DEFINE_SINGLETON(ApplicationProperty,
    ApplicationProperty_init,
    ApplicationProperty_destroy);
}
