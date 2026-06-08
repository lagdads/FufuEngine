add_executable(Sandbox)

file(GLOB_RECURSE FUFU_SANDBOX_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx"
)

file(GLOB FUFU_SANDBOX_MODULES CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/FufuEngine/modules/EntryPoint.cppm"
        "${CMAKE_CURRENT_SOURCE_DIR}/modules/*.cppm"
)

target_compile_features(Sandbox PRIVATE cxx_std_23)

target_sources(Sandbox
        PRIVATE
        ${FUFU_SANDBOX_SOURCES}
        PRIVATE
        FILE_SET CXX_MODULES
        BASE_DIRS
        ${PROJECT_SOURCE_DIR}/FufuEngine/modules
        FILES
        ${FUFU_SANDBOX_MODULES}
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
