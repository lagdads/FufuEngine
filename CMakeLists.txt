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


# Engine Libary
add_library(FufuEngine SHARED)

target_compile_features(FufuEngine PUBLIC cxx_std_23)

target_compile_definitions(FufuEngine PRIVATE FUFU_BUILD_DLL)

target_include_directories(FufuEngine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/FufuEngine/include
)

target_sources(FufuEngine
        PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/FufuEngine/modules
        FILES
        FufuEngine/modules/FufuEngine.cppm
        FufuEngine/modules/Application.cppm
        PRIVATE
        FufuEngine/src/Application.cpp
)

set_target_properties(FufuEngine PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${FUFU_OUTPUT_DIRECTORY}"
        LIBRARY_OUTPUT_DIRECTORY "${FUFU_OUTPUT_DIRECTORY}"
        RUNTIME_OUTPUT_DIRECTORY "${FUFU_OUTPUT_DIRECTORY}"
        CXX_EXTENSIONS OFF
        CXX_MODULE_STD ON
        CXX_SCAN_FOR_MODULES ON
)

# game libary
add_executable(Sandbox)

target_compile_features(Sandbox PRIVATE cxx_std_23)

target_sources(Sandbox
        PRIVATE
        Sandbox/src/SandboxApp.cpp
        PRIVATE
        FILE_SET CXX_MODULES
        BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/FufuEngine/modules
        FILES
        FufuEngine/modules/EntryPoint.cppm
)

set_target_properties(Sandbox PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${FUFU_OUTPUT_DIRECTORY}"
        LIBRARY_OUTPUT_DIRECTORY "${FUFU_OUTPUT_DIRECTORY}"
        RUNTIME_OUTPUT_DIRECTORY "${FUFU_OUTPUT_DIRECTORY}"
        CXX_EXTENSIONS OFF
        CXX_MODULE_STD ON
        CXX_SCAN_FOR_MODULES ON
)


target_link_libraries(Sandbox PRIVATE FufuEngine)
