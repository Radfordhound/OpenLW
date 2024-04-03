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

Param::Type::EType__ CParameterGOC::GetParamType(Param::Level::ELevel__ level) const
{
    if (level < m_paramNodes.size())
    {
        Param::Type::EType__ type = 0;
        for (auto it = m_paramNodes.begin(); it != m_paramNodes.end(); ++it)
        {
            if (type == level)
            {
                return type;
            }

            ++type;
        }
    }

    return -1;
}
} // Player
} // app
