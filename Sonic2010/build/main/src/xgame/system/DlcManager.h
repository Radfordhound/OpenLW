// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "System/ReferencedObject.h"
#include "System/Singleton.h"

namespace app
{
namespace xgame
{
class DlcManagerImpl; // size == 228

class DlcManager : public fnd::ReferencedObject,
    public csl::fnd::Singleton<DlcManager> // size == 16
{
OPENLW_PRIVATE
    DECLARE_SINGLETON

    DlcManagerImpl* m_impl;

public:
    LWAPI(0x02b3f714, TODO)
    ~DlcManager();

    LWAPI(0x02b3fe10, TODO)
    bool IsComplete() const;

    LWAPI(0x02b3feac, TODO)
    bool IsPurchase(unsigned short param_1) const;

    LWAPI(0x02b3fde4, TODO)
    void Update();

    LWAPI(0x02b3f868, TODO)
    void Cleanup();

    LWAPI(0x02b3f44c, TODO)
    DlcManager();
};
}
}
