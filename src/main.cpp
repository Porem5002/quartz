#include "include/quartz.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "quartz.cpp"
#include "glload.cpp"

static void APIENTRY gl_debug_callback(GLenum source, GLenum type, 
                                GLuint id, GLenum severity,
                                GLsizei length, const GLchar *message,
                                const void *userParam);

int main()
{
    quartz_start(1200, 720, "My Window");

    load_gl_functions();

    glDebugMessageCallback(&gl_debug_callback, nullptr);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glEnable(GL_DEBUG_OUTPUT);

    const char* vertex_shader = "#version 430 core\n"
                                "layout (location = 0) in vec4 vertexPos;\n"
                                "void main()\n"
                                "{\n"
                                    "gl_Position = vertexPos;\n"
                                "}\n";
    
    const char* frag_shader = "#version 430 core\n"
                            "out vec4 fragColor;\n"
                            "void main()\n"
                            "{\n"
                                "fragColor = vec4(0.5, 1.0, 0.0, 1.0);\n"
                            "}\n";

    GLuint vs_id = quartz_shader_from_source(GL_VERTEX_SHADER, vertex_shader);
    GLuint fs_id = quartz_shader_from_source(GL_FRAGMENT_SHADER, frag_shader);
    GLuint program_id = quartz_program_from_shaders(vs_id, fs_id, true);

    glEnable(GL_FRAMEBUFFER_SRGB);
    glDisable(GL_MULTISAMPLE);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_GREATER);

    float vertices [] = {
        -0.5, -0.5,
        0.5, -0.5,
        0.5, 0.5,
        -0.5, 0.5,
    };

    unsigned int indices [] = {
        0, 1, 2,
        2, 3, 0,
    };

    GLuint va;
    glGenVertexArrays(1, &va);
    glBindVertexArray(va);

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);

    while(quartz_is_running())
    {
        quartz_update_events();

        glClearColor(0.2, 0.2, 0.23, 1.0);
        glClearDepth(0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glViewport(0, 0, quartz_get_screen_width(), quartz_get_screen_height());

        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, indices);

        quartz_swap_buffers();
    }

    return 0;
}

static void APIENTRY gl_debug_callback(GLenum source, GLenum type, 
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

/*#include "include/engine_core.hpp"
#include "include/platform.hpp"
#include "include/input.hpp"

//#include "include/impl.hpp"

#include 

struct quartz_window
{
    bool is_open;
};

quartz_window quartz_window_open(int width, int height, const char* title)
{
    return { false };
}

int main()
{
    BumpAllocator transientStorage = make_bump_allocator(MB(50));

    quartz_start(1200, 720, "My Window");

    while(quartz_is_running())
    {
        quartz_update_events();

        quartz_swap_buffers();
    }

    return 0;
}*/