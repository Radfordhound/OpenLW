#pragma once
#include "ReferencedObject.h"
#include "Singleton.h"

namespace app
{
struct ApplicationPropertyImpl;

class ApplicationProperty : public fnd::ReferencedObject,
    public csl::fnd::Singleton<ApplicationProperty>
{
LWAPI_PRIVATE
    DECLARE_SINGLETON

    ApplicationPropertyImpl* m_impl;

public:
    LWAPI(0x021c7a50, NONE)
    ApplicationProperty();
};

/**
 * @brief Initializes the ApplicationProperty Singleton.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
*/
LWAPI(0x021c8354, TODO)
void* ApplicationProperty_init();

/**
 * @brief Destroys the ApplicationProperty Singleton.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
 *
 * @param[in] ptr The pointer to the Singleton.
*/
LWAPI(0x021c83a4, TODO)
void ApplicationProperty_destroy(void* ptr);
}
