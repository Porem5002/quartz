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
else()
    set(quartz "quartz")
    add_library(${quartz} STATIC "quartz/quartz_impl.cpp")
endif()

target_include_directories(${quartz} PRIVATE "third_party/" "third_party/GL/" "third_party/freetype/")
target_link_libraries(${quartz} PRIVATE user32 opengl32 gdi32)

target_link_directories(${quartz} PUBLIC "third_party/freetype/lib")
target_link_libraries(${quartz} PUBLIC "freetype.lib")

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
    make_example(test)
endif()