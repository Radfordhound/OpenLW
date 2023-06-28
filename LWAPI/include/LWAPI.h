#ifndef LWAPI_H_INCLUDED
#define LWAPI_H_INCLUDED

/* Macros */
#ifndef LWAPI
#ifdef _WIN32

// Setup LWAPI macro such that it expands to __declspec(dllimport)
// unless addrPC is NONE or TODO, in which case, it expands to nothing.
#define LWAPI_DETAIL_EXPAND(x) x
#define LWAPI_DETAIL_NOTHING()

#define LWAPI_DETAIL2(dummy, attrib, ...) attrib
#define LWAPI_DETAIL(...) LWAPI_DETAIL_EXPAND(LWAPI_DETAIL2(__VA_ARGS__, __declspec(dllimport)))

#define LWAPI_DETAIL_SPECIAL_ADDR_NONE DUMMY, LWAPI_DETAIL_NOTHING(),
#define LWAPI_DETAIL_SPECIAL_ADDR_TODO DUMMY, LWAPI_DETAIL_NOTHING(),

#define LWAPI(addrWiiU, addrPC) LWAPI_DETAIL(LWAPI_DETAIL_SPECIAL_ADDR_##addrPC)

#else
#error "Unsupported target platform"
#endif
#endif

#ifndef LWAPI_STATIC_ASSERT_SIZE
#define LWAPI_STATIC_ASSERT_SIZE(type, size) \
    static_assert(sizeof(type) == (size),\
        "sizeof(" #type ") != expected size (" #size ")");
#endif

#ifndef OPENLW_PRIVATE
#define OPENLW_PRIVATE public:
#endif

#ifndef OPENLW_PROTECTED
#define OPENLW_PROTECTED public:
#endif

#ifndef OPENLW_STD_NAMESPACE
#ifndef _MSC_VER // Non-MSVC

#error "Unknown compiler; cannot provide STL types with LW binary compatibility"

#elif _MSC_VER == 1600 // MSVC 1600 (VS2010)

// Force release-mode iterators even in debug builds, for slw.exe compatibility.
#define _ITERATOR_DEBUG_LEVEL 0
#define OPENLW_STD_NAMESPACE ::std::

#else // Other MSVC

// Force release-mode iterators even in debug builds, for slw.exe compatibility.
#define _ITERATOR_DEBUG_LEVEL 0
#include "vs2010_std/vs2010_vector.h"
//#include "vs2010_std/vs2010_string.h"

#define OPENLW_STD_NAMESPACE ::lwapi::vs2010_std::

#endif
#endif

/* Other standard library includes */
// NOTE: We need to do this after the above block, to
// ensure that _ITERATOR_DEBUG_LEVEL is defined properly.
#include <cstdint>

namespace lwapi
{
/* ASLR helpers */
#define LWAPI_BASE_ADDRESS 0x400000U
extern const std::uintptr_t ModuleAddress;

#define LWAPI_ASLR(address) (\
    ::lwapi::ModuleAddress + ((address) - LWAPI_BASE_ADDRESS))

namespace detail
{
/* Patches */
using PatchFunc = void (*)();

class PatchLinkedListNode
{
    PatchFunc m_installPatchPtr;
    PatchLinkedListNode* m_next;

    static PatchLinkedListNode* _begin;

public:
    static inline PatchLinkedListNode* Begin()
    {
        return _begin;
    }

    inline void Install() const
    {
        m_installPatchPtr();
    }

    inline PatchLinkedListNode* Next() const
    {
        return m_next;
    }

    PatchLinkedListNode(PatchFunc installPatchPtr) :
        m_installPatchPtr(installPatchPtr),
        m_next(_begin)
    {
        _begin = this;
    }
};
}

#define LWAPI_DEFINE_PATCH(name)\
    static ::lwapi::detail::PatchLinkedListNode name##_patch =\
        ::lwapi::detail::PatchLinkedListNode(&name);

void ApplyPatches();
}

#endif
