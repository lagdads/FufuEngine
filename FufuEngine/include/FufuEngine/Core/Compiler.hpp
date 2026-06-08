#pragma once


// 定义编译器宏
#if defined(_MSC_VER)
#define FUFU_COMPILER_MSVC 1
#else
#define FUFU_COMPILER_MSVC 0
#endif

#if defined(__clang__)
#define FUFU_COMPILER_CLANG 1
#else
#define FUFU_COMPILER_CLANG 0
#endif

#if defined(__GNUC__) && !defined(__clang__)
#define FUFU_COMPILER_GCC 1
#else
#define FUFU_COMPILER_GCC 0
#endif
