#include "include/quartz.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#undef STB_IMAGE_IMPLEMENTATION

#include "quartz.cpp"
#include "quartz_math.cpp"
#include "quartz_renderer.cpp"
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
                                "layout (location = 0) in vec2 vertexPos;\n"
                                "layout (location = 1) in vec2 texturePos;\n"
                                "layout (location = 0) out vec2 out_texturePos;\n"
                                "uniform mat4 u_mvp;\n"
                                "void main()\n"
                                "{\n"
                                    "out_texturePos = texturePos;\n"
                                    "gl_Position = u_mvp * vec4(vertexPos, 0, 1.0);\n"
                                "}\n";
    
    const char* frag_shader = "#version 430 core\n"
                            "layout (location = 0) in vec2 texturePos;\n"
                            "layout (binding = 0) uniform sampler2D u_Texture;\n"
                            "out vec4 fragColor;\n"
                            "void main()\n"
                            "{\n"
                                "fragColor = texelFetch(u_Texture, ivec2(texturePos), 0);\n"
                            "}\n";

    GLuint vs_id = quartz_shader_from_source(GL_VERTEX_SHADER, vertex_shader);
    GLuint fs_id = quartz_shader_from_source(GL_FRAGMENT_SHADER, frag_shader);
    GLuint program_id = quartz_program_from_shaders(vs_id, fs_id, true);

    glDisable(GL_MULTISAMPLE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    quartz_render_init();

    quartz_texture texture = quartz_texture_from_file("assets/TEXTURE_ATLAS.png");
    quartz_texture_bind_slot(texture, 0);

    quartz_camera2D cam = {};
    cam.width = 320;
    cam.height = 180;

    quartz_mat4 proj = quartz_camera2D_to_mat4(cam);
    GLuint u_mvp = glGetUniformLocation(program_id, "u_mvp");
    glUniformMatrix4fv(u_mvp, 1, GL_FALSE, &proj.values[0][0]);

    while(quartz_is_running())
    {
        quartz_update_events();

        quartz_render_clear(0.2, 0.2, 0.23, 1.0);

        quartz_render_texture_slice(texture, {0, 0}, {{16, 0}, {15, 16}});
        quartz_render_texture_slice(texture, {-10, 1}, {{16, 0}, {15, 16}});
        quartz_render_draw();

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