#include "pch.h"
#include "Extra/Util/hhGPUInstanceMapper.h"

namespace Extra
{
namespace fx
{
class CGPUInstanceMapperInternal // TODO: Inheritance
{
    // TODO
};

CGPUInstanceMapper::CGPUInstanceMapper() :
    m_impl(new CGPUInstanceMapperInternal()) {}

CGPUInstanceMapper::~CGPUInstanceMapper()
{
    delete m_impl;
}
}
}
