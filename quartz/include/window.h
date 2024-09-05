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

#ifndef QUARTZ_WINDOW_HEADER
#define QUARTZ_WINDOW_HEADER

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>

#include <stdint.h>

#include "math.h"

QUARTZ_STRUCT_DEF(quartz_window)
{
    bool running;
    bool resized;
    quartz_ivec2 size;
    quartz_ivec2 mouse_pos;

    #if _WIN32
        HWND win_window;
        HDC win_dc;
        HGLRC win_rc;
    #endif
};

QUARTZ_DEF quartz_window quartz_window_create(int width, int height, const char* title);
QUARTZ_DEF void quartz_window_update(quartz_window* window);
QUARTZ_DEF void quartz_window_swap_buffers(quartz_window* window);

#endif