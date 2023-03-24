#include "OpenLW/pch.h"
#include "GOComponent.h"
#include "System/GameObject.h"

namespace app
{
namespace fnd
{
GOComponent* GOComponent::GetComponentByID(const char* id)
{
    return m_activeObject->GetGOC(id);
}

const GOComponent* GOComponent::GetComponentByID(const char* id) const
{
    return m_activeObject->GetGOC(id);
}
} // fnd
} // app
