/*
MIT License

Copyright (c) 2024-2025 Carlos Bandeira

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

#ifndef QUARTZ_BASE_HEADER
#define QUARTZ_BASE_HEADER

#include <stdlib.h>
#include <stdint.h>

#include "colors.h"
#include "viewport.h"

QUARTZ_DEF void quartz_start(int width, int height, const char* title);
QUARTZ_DEF void quartz_finish();

QUARTZ_DEF bool quartz_update();
QUARTZ_DEF bool quartz_fixed_update();

QUARTZ_DEF void quartz_set_vsync(bool active);
QUARTZ_DEF void quartz_set_fixed_delta_time(float fixed_delta_time);

QUARTZ_DEF void quartz_quit();
QUARTZ_DEF bool quartz_is_startup();
QUARTZ_DEF bool quartz_is_running();
QUARTZ_DEF float quartz_get_delta_time();

QUARTZ_DEF bool quartz_was_screen_resized();
QUARTZ_DEF quartz_ivec2 quartz_get_screen_size();
QUARTZ_DEF quartz_viewport quartz_get_screen_viewport();
QUARTZ_DEF quartz_ivec2 quartz_get_mouse_pos();

QUARTZ_DEF quartz_viewport quartz_make_viewport();

QUARTZ_DEF void quartz_clear(quartz_color color);

#endif