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

#ifndef QUARTZ_ENGINE_HEADER
#define QUARTZ_ENGINE_HEADER

#include <cstdlib>
#include <cstdint>

#include "common.hpp"
#include "viewport.hpp"

void quartz_start(int width, int height, const char* title);
bool quartz_update();
bool quartz_fixed_update();

void quartz_set_vsync(bool active);
void quartz_set_fixed_delta_time(float fixed_delta_time);

bool quartz_is_running();
float quartz_get_delta_time();

bool quartz_was_screen_resized();
quartz_ivec2 quartz_get_screen_size();
quartz_viewport quartz_get_screen_viewport();
quartz_ivec2 quartz_get_mouse_pos();

quartz_shader quartz_make_shader(const char* vs_code, const char* fs_code);
void quartz_use_shader(quartz_shader shader);

quartz_texture quartz_load_texture(const char* path);
quartz_texture quartz_make_texture(int width, int height, unsigned char* data);
void quartz_bind_texture(quartz_texture texture, unsigned int slot);

quartz_viewport quartz_make_viewport(quartz_viewport_info init);

unsigned int quartz_shader_from_source(unsigned int shader_type, const char* shader_src);
unsigned int quartz_program_from_shaders(unsigned int vs_id, unsigned int fs_id);
void quartz_compile_shader(unsigned int shader_id);

void quartz_clear(quartz_color color);

#endif