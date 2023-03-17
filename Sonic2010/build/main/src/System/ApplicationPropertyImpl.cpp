// TODO: Both the name of this file and its path were guessed!
#include "ApplicationPropertyImpl.h"
#include "Singleton.h"
#include <csl/fnd/memory.h>
#include <csl/ut/string.h>

namespace app
{
void* ApplicationPropertyImpl::operator new(std::size_t size)
{
    // TODO: It doesn't seem to actually call GetSingletonAllocator here; it seems this value is passed
    // in via an argument or something instead? But the symbols say there is no allocator argument??
    csl::fnd::IAllocator* allocator = fnd::GetSingletonAllocator();
    ApplicationPropertyImpl* buf = static_cast<ApplicationPropertyImpl*>(
        allocator->Alloc(size + sizeof(allocator)));

    *reinterpret_cast<csl::fnd::IAllocator**>(buf + 1) = allocator;
    return buf;
}

ApplicationPropertyImpl::ApplicationPropertyImpl(csl::fnd::IAllocator* allocator) :
    field_0x4(0),
    field_0x8(0),
    field_0xc(0) {}

void ApplicationPropertyImpl::operator delete(void* ptr)
{
    if (ptr)
    {
        csl::fnd::IAllocator* allocator = reinterpret_cast<csl::fnd::IAllocator*>(
            static_cast<ApplicationPropertyImpl*>(ptr) + 1);

        allocator->Free(ptr);
    }
}

void ApplicationPropertyImpl::getMultiLanguageName(const char* param_1,
	unsigned int param_2, csl::ut::String* result)
{
    // TODO
}
}
