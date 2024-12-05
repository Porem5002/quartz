cmake_minimum_required(VERSION "3.15")

project(quartz)
option(DYNAMIC "Build as a dynamic library" OFF) 
option(EXAMPLES "Build examples" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if(MSVC)
    add_compile_options("/MT")
endif()

# Library
if(DYNAMIC)
    set(quartz "quartzdyn")
    add_library(${quartz} SHARED "quartz/quartz_impl.cpp")
    target_compile_options(${quartz} PRIVATE "-DQUARTZ_DYNAMIC_LIB_EXPORT")

    target_link_directories(${quartz} PRIVATE "third_party/freetype/lib")
    target_link_libraries(${quartz} PRIVATE "freetype.lib")
else()
    set(quartz "quartz")
    add_library(${quartz} STATIC "quartz/quartz_impl.cpp")

    # Link quartz and freetype into a single static library
    if(MSVC)
        set(QUARTZ_TARGET_PATH "${CMAKE_BINARY_DIR}/$<CONFIG>/${quartz}.lib")
        set(QUARTZ_FREETYPE_LIB_PATH "${CMAKE_SOURCE_DIR}/third_party/freetype/lib/freetype.lib")

        # TODO: Only execute when target is recompiled
        add_custom_command(
            TARGET ${quartz} POST_BUILD
            COMMAND "lib" "/nologo" ${QUARTZ_TARGET_PATH} ${QUARTZ_FREETYPE_LIB_PATH} "/OUT:${QUARTZ_TARGET_PATH}"
            VERBATIM
        )
    endif()
endif()

target_include_directories(${quartz} PRIVATE "third_party/" "third_party/GL/" "third_party/freetype/")

# Examples
if(EXAMPLES)
    function(make_example EXAMPLE_NAME)
        file(GLOB EXAMPLE_SRC "examples/${EXAMPLE_NAME}/*.cpp" "examples/${EXAMPLE_NAME}/*.c")
        add_executable(${EXAMPLE_NAME} ${EXAMPLE_SRC})
        target_include_directories(${EXAMPLE_NAME} PRIVATE "quartz")
        target_link_libraries(${EXAMPLE_NAME} PRIVATE ${quartz})

        if(DYNAMIC)
            target_compile_options(${EXAMPLE_NAME} PRIVATE "-DQUARTZ_DYNAMIC_LIB_IMPORT")
        endif()
    endfunction()

    make_example(pong)
    make_example(game_of_life)
endif()