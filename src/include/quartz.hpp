#ifndef QUARTZ_ENGINE_HEADER
#define QUARTZ_ENGINE_HEADER

#include <cstdlib>
#include <cstdio>

#ifdef _WIN32
#ifndef WIN_LEAN_AND_MEAN
#define WIN_LEAN_AND_MEAN 1
#include <windows.h>
#endif

#define GL_GLEXT_PROTOTYPES
#include <glcorearb.h>

#include "quartz_math.hpp"

struct quartz_window
{
    int width;
    int height;

    HWND window;
    HDC dc;
    HGLRC rc;
};

#endif

struct quartz_context
{
    bool running;
    quartz_window window;
};

struct quartz_texture
{
    GLuint id;
    int width, height, channels;
};

extern quartz_context quartz_implicit_context;

struct quartz_camera2D
{
    float x, y;
    float width, height;
};

void quartz_start(int width, int height, const char* title);
void quartz_update_events();
void quartz_swap_buffers();

bool quartz_is_running();
int quartz_get_screen_width();
int quartz_get_screen_height();

quartz_texture quartz_texture_from_file(const char* path);
void quartz_texture_bind_slot(quartz_texture texture, GLuint slot);

GLuint quartz_shader_from_source(GLenum shader_type, const char* shader_src);
GLuint quartz_program_from_shaders(GLuint vs_id, GLuint fs_id, bool use_program_now);
void quartz_compile_shader(GLuint shader_id);

quartz_mat4 quartz_camera2D_to_mat4(quartz_camera2D camera);

#define QUARTZ_DEBUG_BREAK() __debugbreak()

#define QUARTZ_LOG_INFO(MSG) do { fprintf(stderr, "INFO: %s", (MSG)); } while(0)
#define QUARTZ_LOG_WARNING(MSG) do { fprintf(stderr, "WARNING: %s", (MSG)); } while(0)
#define QUARTZ_LOG_ERROR(MSG) do { fprintf(stderr, "ERROR: %s", (MSG)); } while(0)

#define QUARTZ_ASSERT(COND, MSG) do {\
    if(!(COND))\
    {\
        fprintf(stderr, "ASSERTION FAILED: %s", (MSG));\
        QUARTZ_DEBUG_BREAK();\
        abort();\
    }\
} while(0)

#endif

