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

#ifndef QUARTZ_DRAW_HEADER
#define QUARTZ_DRAW_HEADER

#include <stdlib.h>
#include <stdint.h>

#include "common.h"
#include "viewport.h"
#include "resources.h"

QUARTZ_ENUM_DEF(quartz_primitive2D, uint16_t)
{
    QUARTZ_PRIMITIVE2D_QUAD,
    QUARTZ_PRIMITIVE2D_CIRCLE,
};

QUARTZ_STRUCT_DEF(quartz_camera2D)
{
    float x, y;
    float width, height;
    float zoom;
};

QUARTZ_DEF quartz_camera2D quartz_init_camera2D(int width, int height);
QUARTZ_DEF quartz_mat3 quartz_camera2D_get_projection(const quartz_camera2D* camera);
QUARTZ_DEF quartz_vec2 quartz_camera2D_to_world_through_viewport(const quartz_camera2D* camera, quartz_ivec2 position, quartz_viewport viewport);

QUARTZ_DEF void quartz_render2D_init();
QUARTZ_DEF void quartz_render2D_set_shader(quartz_shader shader);
QUARTZ_DEF quartz_shader quartz_render2D_get_shader();
QUARTZ_DEF void quartz_render2D_set_viewport(quartz_viewport viewport);
QUARTZ_DEF void quartz_render2D_set_camera(const quartz_camera2D* camera);
QUARTZ_DEF void quartz_render2D_sprite_ex(quartz_primitive2D primitive, quartz_sprite sprite, quartz_vec2 pos, quartz_vec2 scale QUARTZ_CPP_ONLY(= {1.0f, 1.0f}), float rotation QUARTZ_CPP_ONLY(= 0.0f), quartz_color tint QUARTZ_CPP_ONLY(= QUARTZ_WHITE));
QUARTZ_DEF void quartz_render2D_texture_ex(quartz_primitive2D primitive, quartz_texture texture, quartz_vec2 pos, quartz_vec2 scale QUARTZ_CPP_ONLY(= {1.0f, 1.0f}), float rotation QUARTZ_CPP_ONLY(= 0.0f), quartz_color tint QUARTZ_CPP_ONLY(= QUARTZ_WHITE));
QUARTZ_DEF void quartz_render2D_sprite(quartz_sprite sprite, quartz_vec2 pos, quartz_vec2 scale QUARTZ_CPP_ONLY(= {1.0f, 1.0f}), float rotation QUARTZ_CPP_ONLY(= 0.0f), quartz_color tint QUARTZ_CPP_ONLY(= QUARTZ_WHITE));
QUARTZ_DEF void quartz_render2D_texture(quartz_texture texture, quartz_vec2 pos, quartz_vec2 scale QUARTZ_CPP_ONLY(= {1.0f, 1.0f}), float rotation QUARTZ_CPP_ONLY(= 0.0f), quartz_color tint QUARTZ_CPP_ONLY(= QUARTZ_WHITE));
QUARTZ_DEF void quartz_render2D_quad(quartz_color color, quartz_vec2 pos, quartz_vec2 scale, float rotation QUARTZ_CPP_ONLY(= 0.0f));
QUARTZ_DEF void quartz_render2D_circle(quartz_color color, quartz_vec2 pos, float radius);
QUARTZ_DEF void quartz_render2D_text(quartz_font font, float font_size, const char* text, quartz_vec2 pos, quartz_color color);
QUARTZ_DEF void quartz_render2D_flush();

#endif