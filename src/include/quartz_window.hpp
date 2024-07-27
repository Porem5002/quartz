#ifndef QUARTZ_WINDOW_HEADER
#define QUARTZ_WINDOW_HEADER

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <cstdint>

#include "quartz_math.hpp"

struct quartz_window
{
    bool running;
    quartz_uvec2 size;
    quartz_uvec2 mouse_pos;

    #if _WIN32
        HWND win_window;
        HDC win_dc;
        HGLRC win_rc;
    #endif
};

quartz_window quartz_window_create(unsigned int width, unsigned int height, const char* title);
void quartz_window_update(quartz_window* window);
void quartz_window_swap_buffers(quartz_window* window);

#endif