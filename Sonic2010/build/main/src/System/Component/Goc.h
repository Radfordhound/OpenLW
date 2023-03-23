// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once
#include <vector>
#include <cstddef>
#include <boost/intrusive_ptr.hpp>

namespace app
{
class CGOComponent;

namespace fnd
{
struct SUpdateInfo;
} // fnd

class CGOCCollectionImpl
{
OPENLW_PRIVATE
    OPENLW_STD_NAMESPACE vector<boost::intrusive_ptr<CGOComponent>> m_Components;

public:
    LWAPI(0x02a91f0c, 0x00914510)
    CGOCCollectionImpl(std::size_t capacity);

    LWAPI(0x02A925E4, TODO)
    void SetGOC(CGOComponent* param_1);

    LWAPI(0x02A926C0, TODO)
    void id_equal(const boost::intrusive_ptr<CGOComponent>& param_1, const char* param_2);

    LWAPI(0x02A92748, TODO)
    void GetGOC(const char* param_1) const;

    LWAPI(0x02A92810, NONE)
    std::size_t GetNumGOCs() const
    {
        return m_Components.size();
    }

    LWAPI(0x02A92824, TODO)
    void GetGOC(unsigned int param_1) const;

    LWAPI(0x02A92848, TODO)
    void Update(float param_1);

    LWAPI(0x02A928FC, TODO)
    void Update(const fnd::SUpdateInfo& param_1);
};

LWAPI_STATIC_ASSERT_SIZE(CGOCCollectionImpl, 16)

template<std::size_t Capacity>
class CGOCCollection : public CGOCCollectionImpl
{
public:
    inline CGOCCollection() :
        CGOCCollectionImpl(Capacity) {}
};

LWAPI_STATIC_ASSERT_SIZE(CGOCCollection<20>, 16)
} // app
