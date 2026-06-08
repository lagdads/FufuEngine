cmake_minimum_required(VERSION 4.3.3...4.3.3)

# https://github.com/Kitware/CMake/blob/master/Help/dev/experimental.rst. 版本 4.3.3
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD 451f2fe2-a8a2-47c3-bc32-94786d8fc91b)
set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(FUFU_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FUFU_OUTPUT_DIRECTORY}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FUFU_OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FUFU_OUTPUT_DIRECTORY}")

project(FufuEngine)


# 第三方依赖
include(FetchContent)

FetchContent_Declare(spdlog
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/FufuEngine/thirdparty/spdlog
        OVERRIDE_FIND_PACKAGE
)

find_package(spdlog REQUIRED)


add_subdirectory(FufuEngine)
add_subdirectory(Sandbox)
