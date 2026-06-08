#pragma once

// 定义导出 API 宏
#include <FufuEngine/Core/Compiler.hpp>
#include <FufuEngine/Core/Platform.hpp>

#if defined(FUFU_STATIC)
#define FUFU_API
#elif FUFU_PLATFORM_WINDOWS
#if defined(FUFU_BUILD_DLL)
#define FUFU_API __declspec(dllexport)
#else
#define FUFU_API __declspec(dllimport)
#endif
#elif FUFU_COMPILER_CLANG || FUFU_COMPILER_GCC
#define FUFU_API __attribute__((visibility("default")))
#else
#define FUFU_API
#endif
