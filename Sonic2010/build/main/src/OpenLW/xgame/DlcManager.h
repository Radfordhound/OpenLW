#pragma once
#include "../fnd/ReferencedObject.h"
#include "../fnd/Singleton.h"

namespace app
{
namespace xgame
{
class DlcManagerImpl; // size == 228

class DlcManager : public fnd::ReferencedObject,
    public csl::fnd::Singleton<DlcManager> // size == 16
{
    DECLARE_SINGLETON

    DlcManagerImpl* m_impl;

public:
    // Wii U: 0x02b3f714, PC: TODO
    ~DlcManager();

    // Wii U: 0x02b3fe10, PC: TODO
    bool IsComplete() const;

    // Wii U: 0x02b3feac, PC: TODO
    bool IsPurchase(unsigned short param_1) const;

    // Wii U: 0x02b3fde4, PC: TODO
    void Update();

    // Wii U: 0x02b3f868, PC: TODO
    void Cleanup();

    // Wii U: 0x02b3f44c, PC: TODO
    DlcManager();
};
}
}
