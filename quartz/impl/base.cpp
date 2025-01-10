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

#include <string>
#include <sstream>

#include <vector>
#include <chrono>

#include <stb_image.h>
#include <gapil.h>

#include "../include/base.h"
#include "../include/window.h"
#include "../include/input.h"
#include "../include/gfx_info.h"

enum quartz_lifetime_mode
{
    QUARTZ_LIFETIME_PRE_UPDATE,
    QUARTZ_LIFETIME_FIRST_UPDATE,
    QUARTZ_LIFETIME_ESTABLISHED_UPDATE,
};

struct quartz_base
{
    static constexpr float DEFAULT_FIXED_DELTA_TIME = 1.0f / 60.0f;

    quartz_lifetime_mode lifetime_mode;
    std::string shader_defines;

    float delta_time;

    bool is_fixed_update;
    float fixed_delta_time;
    float fixed_accumulator;

    std::vector<quartz_rect> viewports;
    
    quartz_viewport screen_viewport;

    quartz_window window;
};

static quartz_base base_context = {};

static void APIENTRY quartz_gl_debug_callback(GLenum source, GLenum type, 
                                GLuint id, GLenum severity,
                                GLsizei length, const GLchar *message,
                                const void *userParam);

void quartz_viewport_set_rect(quartz_viewport vp, quartz_rect rect)
{
    base_context.viewports[vp.id] = rect;
}

quartz_rect quartz_viewport_get_rect(quartz_viewport vp)
{
    return base_context.viewports[vp.id];
}

void quartz_resources_init();
void quartz_resources_finish();

void quartz_start(int width, int height, const char* title)
{
    base_context.window = quartz_window_create(width, height, title);

    gapil_load();

    glDebugMessageCallback(&quartz_gl_debug_callback, nullptr);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glEnable(GL_DEBUG_OUTPUT);

    base_context.lifetime_mode = QUARTZ_LIFETIME_PRE_UPDATE;
    quartz_resources_init();

    // Default Config
    quartz_set_vsync(true);
    base_context.is_fixed_update = false;
    base_context.fixed_delta_time = base_context.DEFAULT_FIXED_DELTA_TIME;
    base_context.fixed_accumulator = 0.0f;
    base_context.screen_viewport = quartz_make_viewport();
}

void quartz_finish()
{
    quartz_resources_finish();
}

bool quartz_update()
{
    bool running = quartz_is_running();

    if(running)
    {
        switch(base_context.lifetime_mode)
        {
            case QUARTZ_LIFETIME_PRE_UPDATE:
                base_context.lifetime_mode = QUARTZ_LIFETIME_FIRST_UPDATE;
                break;
            case QUARTZ_LIFETIME_FIRST_UPDATE:
                base_context.lifetime_mode = QUARTZ_LIFETIME_ESTABLISHED_UPDATE;
                break;
            case QUARTZ_LIFETIME_ESTABLISHED_UPDATE:
                break;
            default:
                QUARTZ_ASSERT(false, "Unreachable");
        }

        // End Last Frame
        quartz_window_swap_buffers(&base_context.window);

        // Start Current Frame
        static auto last_time = std::chrono::system_clock::now();
        auto curr_time = std::chrono::system_clock::now();

        float delta_time = std::chrono::duration<float>(curr_time - last_time).count();
        last_time = curr_time;

        base_context.delta_time = delta_time;
        base_context.fixed_accumulator += delta_time;

        quartz_update_key_states();
        quartz_window_update(&base_context.window);

        if(quartz_was_screen_resized())
        {
            auto screen_size = quartz_get_screen_size();
            base_context.screen_viewport.set_rect({ 0, 0, screen_size.x, screen_size.y });
        }
    }

    return running;
}

bool quartz_fixed_update()
{
    base_context.is_fixed_update = base_context.fixed_accumulator >= base_context.fixed_delta_time;

    if(base_context.is_fixed_update)
        base_context.fixed_accumulator -= base_context.fixed_delta_time;

    return base_context.is_fixed_update;
}

void quartz_set_vsync(bool active)
{
    wglSwapIntervalEXT((int)active);
}

void quartz_set_fixed_delta_time(float fixed_delta_time)
{
    base_context.fixed_delta_time = fixed_delta_time;
}

void quartz_quit()
{
    base_context.window.running = false;
}

bool quartz_is_startup()
{
    return base_context.lifetime_mode == QUARTZ_LIFETIME_PRE_UPDATE ||
           base_context.lifetime_mode == QUARTZ_LIFETIME_FIRST_UPDATE;
}

bool quartz_is_running()
{
    return base_context.window.running;
}

float quartz_get_delta_time()
{
    return base_context.is_fixed_update ? base_context.fixed_delta_time : base_context.delta_time;
}

bool quartz_was_screen_resized()
{
    return base_context.window.resized;
}

quartz_ivec2 quartz_get_screen_size()
{
    return base_context.window.size;
}

quartz_viewport quartz_get_screen_viewport()
{
    return base_context.screen_viewport;
}

quartz_ivec2 quartz_get_mouse_pos()
{
    return base_context.window.mouse_pos;
}

quartz_viewport quartz_make_viewport()
{
    quartz_viewport viewport = { base_context.viewports.size() };
    base_context.viewports.push_back({ 0, 0, quartz_get_screen_size().x, quartz_get_screen_size().y });
    return viewport;
}

void quartz_clear(quartz_color color)
{
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

static void APIENTRY quartz_gl_debug_callback(GLenum source, GLenum type, 
                                GLuint id, GLenum severity,
                                GLsizei length, const GLchar *message,
                                const void *userParam)
{
    (void)source;
    (void)type;
    (void)id;
    (void)length;
    (void)userParam;

    switch (severity)
    {
        case GL_DEBUG_SEVERITY_LOW:
        case GL_DEBUG_SEVERITY_MEDIUM:
            //TODO: Check why renderer causes shader recompilation on the first call to glClear, triggering this
            QUARTZ_LOG_INFO((const char*)message);
            break;
        case GL_DEBUG_SEVERITY_HIGH:
            QUARTZ_ASSERT(false, message);
            break;
        default:
            QUARTZ_LOG_INFO((const char*)message);
            break;
    }
}