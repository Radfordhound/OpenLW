#pragma once
#include "RsdxDevCore.h"

// TODO: Move a lot of this stuff from here into its own headers.

namespace hh
{
namespace rsdx
{
#ifdef _WIN32
typedef IDirect3DDevice9Ex RsdxDevice;

typedef ::_D3DRENDERSTATETYPE _D3DRENDERSTATETYPE,
    D3DRENDERSTATETYPE;

typedef ::_D3DVERTEXELEMENT9 _D3DVERTEXELEMENT9,
    D3DVERTEXELEMENT9, *LPD3DVERTEXELEMENT9;

typedef IDirect3DVertexDeclaration9 RsdxVertexDeclaration9;

typedef ::_D3DPRIMITIVETYPE _D3DPRIMITIVETYPE,
    D3DPRIMITIVETYPE;

typedef IDirect3DBaseTexture9 RsdxBaseTexture9;

#define RSDX_RS_MAX             210
#else
#define MAXD3DDECLLENGTH        (GX2_MAX_ATTRIB_BUFFERS - 1)
#define RSDX_RS_MAX             48

typedef struct _D3DVERTEXELEMENT9
{
    short Stream;
    short Offset;
    unsigned int Type;
    unsigned char Method;
    unsigned char Usage;
    unsigned char UsageIndex;
}
D3DVERTEXELEMENT9, *LPD3DVERTEXELEMENT9;
#endif
}
}
