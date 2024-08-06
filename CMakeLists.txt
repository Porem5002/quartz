cmake_minimum_required(VERSION "3.15")

project(quartz)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if(MSVC)
    add_compile_options("/MT")
endif()

# Library
add_library(quartz STATIC "quartz/quartz_impl.cpp")
target_include_directories(quartz PRIVATE "third_party/")
target_link_libraries(quartz PRIVATE user32 opengl32 gdi32)

# Examples
file(GLOB PONG_SRC "examples/pong/*.cpp")
add_executable(pong ${PONG_SRC})
target_include_directories(pong PRIVATE "quartz")
target_link_libraries(pong PRIVATE quartz)