#include "Hedgehog/Database/hhCDatabaseData.h"

namespace hh
{
namespace db
{
CDatabaseData::CDatabaseData() :
    field_0x0(4),
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
    field_0x0 |= 1;
}

bool CDatabaseData::CheckMadeAll()
{
    return true;
}
}
}
