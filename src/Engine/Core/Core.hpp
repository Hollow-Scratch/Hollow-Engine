#pragma once

// Platform detection
#if defined(_WIN32) || defined(_WIN64)
#define HOLLOW_PLATFORM_WINDOWS
#elif defined(__linux__)
#define HOLLOW_PLATFORM_LINUX
#elif defined(__APPLE__)
#define HOLLOW_PLATFORM_MAC
#else
#error "Unsupported platform!"
#endif

// DLL / Shared library export
#if defined(HOLLOW_PLATFORM_WINDOWS)

#ifdef HOLLOW_BUILD_DLL
#define HOLLOW_API __declspec(dllexport)
#else
#define HOLLOW_API __declspec(dllimport)
#endif

#else

#if defined(__GNUC__) && __GNUC__ >= 4
#define HOLLOW_API __attribute__((visibility("default")))
#else
#define HOLLOW_API
#endif

#endif