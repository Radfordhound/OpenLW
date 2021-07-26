#include "Hedgehog/Database/hhCDatabaseData.h"

namespace hh
{
namespace db
{
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

bool CDatabaseData::CheckMadeAll()
{
    return true;
}
}
}
