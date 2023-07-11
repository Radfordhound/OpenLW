#include "OpenLW/pch.h"
#include "PlayerParameter.h"

namespace app
{
namespace Player
{
float CParameterGOC::Get(Param::Index i) const
{
    for (auto it = m_paramNodes.rbegin(); it != m_paramNodes.rend(); ++it)
    {
        if (it->values[i])
        {
            return *it->values[i];
        }
    }

    return 0.0f;
}
} // Player
} // app
