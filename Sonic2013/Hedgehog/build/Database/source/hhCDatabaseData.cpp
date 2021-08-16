#include "Hedgehog/Database/hhCDatabaseData.h"

namespace hh
{
namespace db
{
bool CDatabaseData::IsMadeAllInternal() const
{
    // TODO: Why is this function marked const in the symbols, yet does non-const stuff??

    if ((m_flags & DB_MADE_ONE) != 0 &&
        const_cast<CDatabaseData*>(this)->CheckMadeAll())
    {
        const_cast<CDatabaseData*>(this)->m_flags |= DB_MADE_ALL;
        return true;
    }
    
    return false;
}

CDatabaseData::CDatabaseData() :
    m_flags(DB_UNKNOWN_FLAG4),
    field_0x4()
{
    // TODO
}

CDatabaseData::~CDatabaseData()
{
    // TODO
}

void CDatabaseData::SetMadeOne()
{
    m_flags |= DB_MADE_ONE;
}

void CDatabaseData::SetMadeAllFlag()
{
    m_flags |= DB_MADE_ALL;
}

bool CDatabaseData::CheckMadeAll()
{
    return true;
}
}
}
