#pragma once

// Moon Engine has been converted to be a static library so the following is legacy code.

//#ifdef MOON_PLATFORM_WIN
//  #ifdef MOON_BUILD_DLL
//    #define MOON_API _declspec(dllexport)
//  #else 
//    #define MOON_API _declspec(dllimport)
//  #endif // MOON_BUILD_DLL
//#else
//  #error Moon Engine currently does not support non-Windows platforms.
//#endif // MOON_PLATFORM_WIN

#define BIT_MASK(x) 1 << x
