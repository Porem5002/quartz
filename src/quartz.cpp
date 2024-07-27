#include <stb_image.h>
#include <malloc.h>

#include "include/quartz.hpp"
#include "include/glload.hpp"
#include "include/glinclude.hpp"
#include "include/quartz_window.hpp"
#include "include/quartz_input.hpp"

struct quartz_context
{
    static constexpr size_t TEXTURE_CAP = 10;

    size_t textures_size;
    quartz_texture_info textures [TEXTURE_CAP];

    quartz_window window;
};

quartz_context context;

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
}

void quartz_update_events()
{
    quartz_update_key_states();
    quartz_window_update(&context.window);
}

void quartz_swap_buffers()
{
    quartz_window_swap_buffers(&context.window);
}

bool quartz_is_running()
{
    return context.window.running;
}

quartz_uvec2 quartz_get_screen_size()
{
    return context.window.size;
}

quartz_uvec2 quartz_get_mouse_pos()
{
    return context.window.mouse_pos;
}

quartz_shader quartz_make_shader(const char* vs_code, const char* fs_code, bool use_now)
{
    GLuint vs_id = quartz_shader_from_source(GL_VERTEX_SHADER, vs_code);
    GLuint fs_id = quartz_shader_from_source(GL_FRAGMENT_SHADER, fs_code);
    return quartz_program_from_shaders(vs_id, fs_id, use_now);
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

    GLuint texture_id;
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(data);

    QUARTZ_ASSERT(context.textures_size < context.TEXTURE_CAP, "Exceeded max textures allowed!");
    quartz_texture_info* texture = &context.textures[context.textures_size++];
    
    texture->id = texture_id;
    texture->width = w;
    texture->height = h;
    texture->channels = channels;
    
    return texture;
}

void quartz_bind_texture(quartz_texture texture, unsigned int slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texture->id);
}

GLuint quartz_shader_from_source(GLenum shader_type, const char* shader_src)
{
    GLuint id = glCreateShader(shader_type);
    glShaderSource(id, 1, &shader_src, nullptr);
    quartz_compile_shader(id);
    return id;
}

GLuint quartz_program_from_shaders(GLuint vs_id, GLuint fs_id, bool use_program_now)
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

    if(use_program_now)
        glUseProgram(id);

    return id;
}

void quartz_compile_shader(GLuint shader_id)
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
        case GL_DEBUG_SEVERITY_HIGH:
            QUARTZ_ASSERT(false, message);
            break;
        default:
            QUARTZ_LOG_INFO((const char*)message);
            break;
    }
}