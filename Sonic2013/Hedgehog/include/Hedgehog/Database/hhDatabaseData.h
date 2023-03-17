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

    // Wii U: 0x036c46ec, PC: TODO
    bool IsMadeAllInternal() const;

public:
    // Wii U: 0x036c4764, PC: TODO
    CDatabaseData();

    bool IsMadeAll() const
    {
        return ((m_flags & DB_MADE_ALL) != 0 ||
            IsMadeAllInternal());
    }

    // Wii U: 0x036c47cc, PC: TODO
    virtual ~CDatabaseData();

    // Wii U: 0x036c4850, PC: TODO
    void SetMadeOne();

    // Wii U: 0x036c489c, PC: TODO
    void SetMadeAllFlag();

    // Wii U: 0x036c48c4, PC: TODO
    virtual bool CheckMadeAll();
};
}
}
