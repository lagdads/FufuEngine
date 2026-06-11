add_library(FufuEngine SHARED
        modules/Events/KeyEvent.cppm)

file(GLOB_RECURSE FUFU_ENGINE_HEADERS CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
)

file(GLOB_RECURSE FUFU_ENGINE_MODULES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/modules/*.cppm"
)

list(FILTER FUFU_ENGINE_MODULES EXCLUDE REGEX "/EntryPoint\\.cppm$")

file(GLOB_RECURSE FUFU_ENGINE_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx"
)

target_compile_features(FufuEngine PUBLIC cxx_std_23)

target_compile_definitions(FufuEngine PRIVATE FUFU_BUILD_DLL)

target_include_directories(FufuEngine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(FufuEngine
        PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        FILES
        ${FUFU_ENGINE_HEADERS}
        PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/modules
        FILES
        ${FUFU_ENGINE_MODULES}
        PRIVATE
        ${FUFU_ENGINE_SOURCES}
)

set_target_properties(FufuEngine PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${FUFU_OUTPUT_DIRECTORY}"
        LIBRARY_OUTPUT_DIRECTORY "${FUFU_OUTPUT_DIRECTORY}"
        RUNTIME_OUTPUT_DIRECTORY "${FUFU_OUTPUT_DIRECTORY}"
        CXX_EXTENSIONS OFF
        CXX_MODULE_STD ON
        CXX_SCAN_FOR_MODULES ON
)

target_link_libraries(FufuEngine
        PUBLIC
        glm::module
        spdlog::spdlog_header_only
)
