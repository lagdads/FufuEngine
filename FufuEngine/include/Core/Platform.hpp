#pragma once

// 宏：定义平台环境变量
#if defined(_WIN32)
#define FUFU_PLATFORM_WINDOWS 1
#else
#define FUFU_PLATFORM_WINDOWS 0
#endif

#if defined(__APPLE__)
#define FUFU_PLATFORM_MACOS 1
#else
#define FUFU_PLATFORM_MACOS 0
#endif

#if defined(__linux__)
#define FUFU_PLATFORM_LINUX 1
#else
#define FUFU_PLATFORM_LINUX 0
#endif
