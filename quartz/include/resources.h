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

#ifndef QUARTZ_RESOURCES_HEADER
#define QUARTZ_RESOURCES_HEADER

#include <stdlib.h>

#include "math.h"

QUARTZ_STRUCT_DEF(quartz_texture_info)
{
    unsigned int glid;
    int width, height, channels;
};

QUARTZ_STRUCT_DEF(quartz_texture)
{
    size_t id;

#ifdef QUARTZ_CPP
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
#endif

};

QUARTZ_STRUCT_DEF(quartz_sprite)
{
    quartz_texture atlas;
    quartz_uvec2 offset;
    quartz_uvec2 size;
};

#ifdef QUARTZ_CPP
constexpr unsigned int QUARTZ_BASE_FONT_SIZE = 128;
#else
#define QUARTZ_BASE_FONT_SIZE ((unsigned int)128)
#endif

QUARTZ_STRUCT_DEF(quartz_font)
{
    size_t id;
};

QUARTZ_STRUCT_DEF(quartz_glyph_info)
{
    unsigned long codepoint;
    float advance_x;
    float bearing_y;
    quartz_sprite sprite;
};

QUARTZ_STRUCT_DEF(quartz_shader_info)
{
    unsigned int program_id;
    unsigned int vs_id;
    unsigned int fs_id;
};

QUARTZ_STRUCT_DEF(quartz_shader)
{
    size_t id;

#ifdef QUARTZ_CPP
    quartz_shader_info get() const;
    unsigned int get_program_id() const { return get().program_id; }
    unsigned int get_vs_id() const { return get().vs_id; }
    unsigned int get_fs_id() const { return get().fs_id; }
#endif
};

QUARTZ_DEF quartz_shader quartz_load_shader(const char* vs_path, const char* fs_path);
QUARTZ_DEF quartz_shader quartz_make_shader(const char* vs_code, const char* fs_code);
QUARTZ_DEF void quartz_use_shader(quartz_shader shader);
QUARTZ_DEF quartz_shader_info quartz_shader_get_info(quartz_shader shader);

QUARTZ_DEF quartz_texture quartz_load_texture(const char* path);
QUARTZ_DEF quartz_texture quartz_make_texture(int width, int height, unsigned char* data);
QUARTZ_DEF void quartz_bind_texture(quartz_texture texture, unsigned int slot);
QUARTZ_DEF quartz_texture_info quartz_texture_get_info(quartz_texture texture);

QUARTZ_DEF quartz_font quartz_load_font(const char* font_path);
QUARTZ_DEF float quartz_font_get_ascender(quartz_font font);
QUARTZ_DEF float quartz_font_get_descender(quartz_font font);
QUARTZ_DEF quartz_vec2 quartz_font_get_text_size(quartz_font font, float font_size, const char* text);
QUARTZ_DEF quartz_glyph_info quartz_font_get_glyph_info(quartz_font font, unsigned long codepoint);

#endif
