
#include <vector>
#include <chrono>
#include <malloc.h>

#include <stb_image.h>

#include "../include/quartz.hpp"
#include "../include/glload.hpp"
#include "../include/glinclude.hpp"
#include "../include/window.hpp"
#include "../include/input.hpp"

struct quartz_context
{
    static constexpr size_t TEXTURE_CAP = 10;

    float delta_time;

    std::vector<quartz_texture_info> textures;
    std::vector<quartz_viewport_info> viewports;
    
    quartz_viewport screen_viewport;

    quartz_window window;
};

quartz_context context;

quartz_texture_info quartz_texture::get() const
{
    return context.textures[this->id];
}

void quartz_viewport::set(quartz_viewport_info val)
{
    context.viewports[this->id] = val;
}

quartz_viewport_info quartz_viewport::get() const
{
    return context.viewports[this->id];
}

static void APIENTRY quartz_gl_debug_callback(GLenum source, GLenum type, 
                                GLuint id, GLenum severity,
                                GLsizei length, const GLchar *message,
                                const void *userParam);

void quartz_start(int width, int height, const char* title)
{
    context.window = quartz_window_create(width, height, title);

    load_gl_functions();

    glDebugMessageCallback(&quartz_gl_debug_callback, nullptr);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glEnable(GL_DEBUG_OUTPUT);

    // Default Config
    quartz_set_vsync(true);
    context.screen_viewport = quartz_make_viewport({ 0, 0, context.window.size.x, context.window.size.y });
}

bool quartz_update()
{
    bool running = quartz_is_running();

    if(running)
    {
        quartz_window_swap_buffers(&context.window);

        static auto last_time = std::chrono::system_clock::now();
        auto curr_time = std::chrono::system_clock::now();
        
        context.delta_time = std::chrono::duration<float>(curr_time - last_time).count();
        last_time = curr_time;

        quartz_update_key_states();
        quartz_window_update(&context.window);

        if(quartz_was_screen_resized())
        {
            auto screen_size = quartz_get_screen_size();
            context.screen_viewport.set({ 0, 0, screen_size.x, screen_size.y });
        }
    }

    return running;
}

void quartz_set_vsync(bool active)
{
    wglSwapIntervalEXT((int)active);
}

bool quartz_is_running()
{
    return context.window.running;
}

float quartz_get_delta_time()
{
    return context.delta_time;
}

bool quartz_was_screen_resized()
{
    return context.window.resized;
}

quartz_ivec2 quartz_get_screen_size()
{
    return context.window.size;
}

quartz_viewport quartz_get_screen_viewport()
{
    return context.screen_viewport;
}

quartz_ivec2 quartz_get_mouse_pos()
{
    return context.window.mouse_pos;
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
    stbi_set_flip_vertically_on_load(1);

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

    quartz_texture texture = { context.textures.size() };
    context.textures.push_back(texture_info);
    return texture;
}

void quartz_bind_texture(quartz_texture texture, unsigned int slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texture.get_glid());
}

quartz_viewport quartz_make_viewport(quartz_viewport_info init_val = { 0, 0, 0, 0 })
{
    quartz_viewport viewport = { context.viewports.size() };
    context.viewports.push_back(init_val);
    return viewport;
}

unsigned int quartz_shader_from_source(unsigned int shader_type, const char* shader_src)
{
    GLuint id = glCreateShader(shader_type);
    glShaderSource(id, 1, &shader_src, nullptr);
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