#pragma once
#include <Hedgehog/Base/System/hhObject.h>
#include <Hedgehog/Base/System/hhCSharedString.h>

namespace hh
{
namespace db
{
class CDatabaseData : public base::CObject
{
    unsigned char field_0x0;
    // TODO: Other data members? Or is it just padding?
    base::CSharedString field_0x4;

public:
    // Wii U: 0x036c4764, PC: TODO
    CDatabaseData();

    // Wii U: 0x036c47cc, PC: TODO
    virtual ~CDatabaseData();

    // Wii U: 0x036c4850, PC: TODO
    void SetMadeOne();

    // Wii U: 0x036c48c4, PC: TODO
    virtual bool CheckMadeAll();
};
}
}
