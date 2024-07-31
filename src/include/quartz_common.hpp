#ifndef QUARTZ_INTERNALS_HEADER
#define QUARTZ_INTERNALS_HEADER

#include <cstdio>
#include <cstdint>

#include "glinclude.hpp"
#include "quartz_math.hpp"

struct quartz_texture_info
{
    unsigned int id;
    int width, height, channels;
};

using quartz_texture = const quartz_texture_info*;
using quartz_shader = GLuint;

struct quartz_sprite
{
    quartz_texture atlas;
    quartz_uvec2 offset;
    quartz_uvec2 size;
};

struct quartz_color
{
    float r, g, b, a;
};

constexpr quartz_color QUARTZ_TRANSPARENT = { 0.0f, 0.0f, 0.0f, 0.0f };
constexpr quartz_color QUARTZ_BLACK = { 0.0f, 0.0f, 0.0f, 1.0f };
constexpr quartz_color QUARTZ_WHITE = { 1.0f, 1.0f, 1.0f, 1.0f };

constexpr quartz_color QUARTZ_RED = { 1.0f, 0.0f, 0.0f, 1.0f };
constexpr quartz_color QUARTZ_GREEN = { 0.0f, 1.0f, 0.0f, 1.0f };
constexpr quartz_color QUARTZ_BLUE = { 0.0f, 0.0f, 1.0f, 1.0f };

#define QUARTZ_DEBUG_BREAK() __debugbreak()

#define QUARTZ_LOG_INFO(MSG) do { fprintf(stderr, "INFO: %s\n", (MSG)); } while(0)
#define QUARTZ_LOG_WARNING(MSG) do { fprintf(stderr, "WARNING: %s\n", (MSG)); } while(0)
#define QUARTZ_LOG_ERROR(MSG) do { fprintf(stderr, "ERROR: %s\n", (MSG)); } while(0)

#define QUARTZ_ASSERT(COND, MSG) do {\
    if(!(COND))\
    {\
        fprintf(stderr, "ASSERTION FAILED: %s\n", (MSG));\
        QUARTZ_DEBUG_BREAK();\
        abort();\
    }\
} while(0)

#endif