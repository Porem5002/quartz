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
#include <malloc.h>

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

    std::vector<quartz_texture_info> textures;
    std::vector<quartz_rect> viewports;
    
    quartz_viewport screen_viewport;

    quartz_window window;
};

static quartz_base base_context = {};

static void APIENTRY quartz_gl_debug_callback(GLenum source, GLenum type, 
                                GLuint id, GLenum severity,
                                GLsizei length, const GLchar *message,
                                const void *userParam);

quartz_texture_info quartz_texture::get() const
{
    return base_context.textures[this->id];
}

void quartz_viewport_set_rect(quartz_viewport vp, quartz_rect rect)
{
    base_context.viewports[vp.id] = rect;
}

quartz_rect quartz_viewport_get_rect(quartz_viewport vp)
{
    return base_context.viewports[vp.id];
}

void quartz_start(int width, int height, const char* title)
{
    base_context.window = quartz_window_create(width, height, title);

    gapil_load();

    glDebugMessageCallback(&quartz_gl_debug_callback, nullptr);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glEnable(GL_DEBUG_OUTPUT);

    base_context.lifetime_mode = QUARTZ_LIFETIME_PRE_UPDATE;

    // Setup defines for shaders so that they take into consideration the platforms capabilities
    std::stringstream s;
    s << "\n#define QUARTZ_TEXTURE_UNIT_CAP " << quartz_gfx_get_texture_unit_cap() << "\n";
    base_context.shader_defines = s.str();

    // Default Config
    quartz_set_vsync(true);
    base_context.is_fixed_update = false;
    base_context.fixed_delta_time = base_context.DEFAULT_FIXED_DELTA_TIME;
    base_context.fixed_accumulator = 0.0f;
    base_context.screen_viewport = quartz_make_viewport();
}

void quartz_finish()
{
    // In the future, cleanup will be done here if required
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

quartz_shader quartz_make_shader(const char* vs_code, const char* fs_code)
{
    GLuint vs_id = quartz_shader_from_source(GL_VERTEX_SHADER, vs_code);
    GLuint fs_id = quartz_shader_from_source(GL_FRAGMENT_SHADER, fs_code);
    GLuint prog_id = quartz_program_from_shaders(vs_id, fs_id);
    glValidateProgram(prog_id);
    return prog_id;
}

void quartz_use_shader(quartz_shader shader)
{
    glUseProgram(shader);
}

quartz_texture quartz_load_texture(const char* path)
{
    int w, h, channels;
    auto data = stbi_load(path, &w, &h, &channels, 4);
    QUARTZ_ASSERT(data != nullptr, "Could not load texture from the path");
    
    quartz_texture texture = quartz_make_texture(w, h, data);
    stbi_image_free(data);

    return texture;
}

quartz_texture quartz_make_texture(int width, int height, unsigned char* data)
{
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);

    quartz_texture_info texture_info;
    texture_info.glid = id;
    texture_info.width = width;
    texture_info.height = height;
    texture_info.channels = 4;

    quartz_texture texture = { base_context.textures.size() };
    base_context.textures.push_back(texture_info);
    return texture;
}

void quartz_bind_texture(quartz_texture texture, unsigned int slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texture.get_glid());
}

quartz_viewport quartz_make_viewport()
{
    quartz_viewport viewport = { base_context.viewports.size() };
    base_context.viewports.push_back({ 0, 0, quartz_get_screen_size().x, quartz_get_screen_size().y });
    return viewport;
}

unsigned int quartz_shader_from_source(unsigned int shader_type, const char* shader_src)
{
    const char* usage_symbol = "QUARTZ_USE_DEFINES";
    std::string src_with_defines = shader_src;

    // Inserts quartz specific macros into shader if QUARTZ_USE_DEFINES exists, replacing it with the defines
    size_t replacement_index = src_with_defines.find(usage_symbol);
    if(replacement_index != std::string::npos)
        src_with_defines.replace(replacement_index, strlen(usage_symbol), base_context.shader_defines);

    const char* final_shader_src = src_with_defines.c_str();

    GLuint id = glCreateShader(shader_type);
    glShaderSource(id, 1, &final_shader_src, nullptr);
    quartz_compile_shader(id);
    return id;
}

unsigned int quartz_program_from_shaders(unsigned int vs_id, unsigned int fs_id)
{
    GLuint id = glCreateProgram();
    glAttachShader(id, vs_id);
    glAttachShader(id, fs_id);
    glLinkProgram(id);

    GLint linkStatus;
    glGetProgramiv(id, GL_LINK_STATUS, &linkStatus);
    
    //TODO: Improve error logging
    if(linkStatus == GL_FALSE)
    {
        GLint log_length;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &log_length);

        char* log_msg = (char*)malloc(log_length * sizeof(char));
        glGetProgramInfoLog(id, log_length, &log_length, log_msg);

        QUARTZ_ASSERT(false, log_msg);
    }

    return id;
}

void quartz_compile_shader(unsigned int shader_id)
{
    glCompileShader(shader_id);

    int success;
    char shaderLog[2048];
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(shader_id, 2048, 0, shaderLog);
        QUARTZ_ASSERT(false, shaderLog);
    }
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