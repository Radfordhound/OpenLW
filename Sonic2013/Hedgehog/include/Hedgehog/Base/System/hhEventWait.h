#pragma once
#include "hhObject.h"
#include "hhPluginable.h"

namespace hh
{
namespace base
{
class CEventWait : public TPluginable1<CEventWait, bool>, public CObject // size == 4
{
public:
    // Wii U: 0x03698268, PC: TODO
    virtual ~CEventWait();

    virtual void Set() = 0;
    virtual void Reset() = 0;
    virtual bool WaitOne(unsigned int param_1) = 0;
    virtual void WaitOne() = 0;
    virtual bool IsSignal() = 0;
};
}
}
