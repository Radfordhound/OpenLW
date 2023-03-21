// Helper header for including platform-specific math libraries.
#pragma once

#ifdef _WIN32
#ifndef DXMATH_NAMESPACE 
#if defined(_MSC_VER) && _MSC_VER == 1600

// XNA Math (for Visual Studio 2010 builds)
#define WIN32_LEAN_AND_MEAN
#include <Windows.h> // NOTE: Required for xnamath.h
#include <xnamath.h>
#ifndef DXMATH_NAMESPACE
#define DXMATH_NAMESPACE
#endif

#else

// DirectXMath (for modern Visual Studio builds)
#include <DirectXMath.h>
#ifndef DXMATH_NAMESPACE
#define DXMATH_NAMESPACE ::DirectX::
#endif

#endif
#endif
#endif
