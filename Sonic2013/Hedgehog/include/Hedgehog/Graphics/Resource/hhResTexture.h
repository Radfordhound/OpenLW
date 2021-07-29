#pragma once
#include "hhResNameData.h"
#include <Hedgehog/Utility/hhResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResTextureData
{
    // TODO
};

struct ResTexture : public ut::ResCommon<ResTextureData>
{
    inline ResTexture(std::nullptr_t) :
        ResCommon<ResTextureData>() {}

    inline ResTexture(const void* data) :
        ResCommon<ResTextureData>(data) {}

    inline ResTexture(void* data = nullptr) :
        ResCommon<ResTextureData>(data) {}
};
}
}
}
