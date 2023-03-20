#pragma once
#include <Hedgehog/Base/System/hhObject.h>
#include <Hedgehog/Base/System/hhSharedString.h>

namespace hh
{
namespace db
{
enum DatabaseFlags
{
    DB_MADE_ONE = 1,
    DB_MADE_ALL = 2,
    DB_UNKNOWN_FLAG4 = 4
};

class CDatabaseData : public base::CObject
{
    unsigned char m_flags;
    // TODO: Other data members? Or is it just padding?
    base::CSharedString field_0x4;

    LWAPI(0x036c46ec, TODO)
    bool IsMadeAllInternal() const;

public:
    LWAPI(0x036c4764, TODO)
    CDatabaseData();

    bool IsMadeAll() const
    {
        return ((m_flags & DB_MADE_ALL) != 0 ||
            IsMadeAllInternal());
    }

    LWAPI(0x036c47cc, TODO)
    virtual ~CDatabaseData();

    LWAPI(0x036c4850, TODO)
    void SetMadeOne();

    LWAPI(0x036c489c, TODO)
    void SetMadeAllFlag();

    LWAPI(0x036c48c4, TODO)
    virtual bool CheckMadeAll();
};
}
}
