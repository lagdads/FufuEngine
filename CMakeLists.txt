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

set(GLM_BUILD_LIBRARY OFF CACHE BOOL "Build GLM as a header-only dependency" FORCE)

FetchContent_Declare(spdlog
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/FufuEngine/thirdparty/spdlog
        OVERRIDE_FIND_PACKAGE
)

FetchContent_Declare(glm
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/FufuEngine/thirdparty/glm
        OVERRIDE_FIND_PACKAGE
)

find_package(spdlog REQUIRED)
find_package(glm REQUIRED)

add_library(glm-module STATIC)
add_library(glm::module ALIAS glm-module)

target_compile_features(glm-module PUBLIC cxx_std_23)

target_compile_options(glm-module
        PUBLIC
        $<$<CXX_COMPILER_ID:MSVC>:/utf-8>
)

target_sources(glm-module
        PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/FufuEngine/thirdparty/glm/glm
        FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/FufuEngine/thirdparty/glm/glm/glm.cppm
)

target_link_libraries(glm-module PUBLIC glm::glm)


add_subdirectory(FufuEngine)
add_subdirectory(Sandbox)
