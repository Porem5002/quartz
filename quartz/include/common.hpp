/*
MIT License

Copyright (c) 2024 Carlos Bandeira

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef QUARTZ_INTERNALS_HEADER
#define QUARTZ_INTERNALS_HEADER

#include <cstdio>
#include <cstdint>

#include "math.hpp"

struct quartz_texture_info
{
    unsigned int glid;
    int width, height, channels;
};

struct quartz_texture
{
    size_t id;

    quartz_texture_info get() const;
    unsigned int get_glid() const { return get().glid; }
    int get_width() const { return get().width; }
    int get_height() const { return get().height; }

    bool operator ==(quartz_texture other) const
    {
        return id == other.id;
    }

    bool operator !=(quartz_texture other) const
    {
        return id != other.id;
    }
};

using quartz_shader = unsigned int;

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