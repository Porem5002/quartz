#include "include/quartz.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#undef STB_IMAGE_IMPLEMENTATION

#include "quartz.cpp"
#include "quartz_math.cpp"
#include "quartz_renderer.cpp"
#include "quartz_window.cpp"
#include "glload.cpp"


static const char* vertex_shader = "#version 430 core\n"
                                    "layout (location = 0) in vec2 vertexPos;\n"
                                    "layout (location = 1) in vec2 texturePos;\n"
                                    "layout (location = 0) out vec2 out_texturePos;\n"
                                    "uniform mat4 u_mvp;\n"
                                    "void main()\n"
                                    "{\n"
                                        "out_texturePos = texturePos;\n"
                                        "gl_Position = u_mvp * vec4(vertexPos, 0, 1.0);\n"
                                    "}\n";

static const char* frag_shader = "#version 430 core\n"
                                "layout (location = 0) in vec2 texturePos;\n"
                                "layout (binding = 0) uniform sampler2D u_Texture;\n"
                                "out vec4 fragColor;\n"
                                "void main()\n"
                                "{\n"
                                    "fragColor = texelFetch(u_Texture, ivec2(texturePos), 0);\n"
                                "}\n";

int main()
{
    quartz_start(1200, 720, "My Window");

    quartz_shader shader = quartz_make_shader(vertex_shader, frag_shader, true);
    quartz_texture texture1 = quartz_load_texture("assets/TEXTURE_ATLAS.png");
    quartz_texture texture2 = quartz_load_texture("assets/terrain_atlas.png");

    quartz_render_init();

    quartz_camera2D cam = {};
    cam.width = 320;
    cam.height = 180;

    quartz_mat4 proj = quartz_camera2D_to_mat4(cam);
    GLuint u_mvp = glGetUniformLocation(shader, "u_mvp");
    glUniformMatrix4fv(u_mvp, 1, GL_FALSE, &proj.values[0][0]);

    while(quartz_is_running())
    {
        quartz_update_events();

        quartz_render_clear(0.2, 0.2, 0.23, 1.0);

        quartz_sprite dice = { texture1, {16, 0}, {15, 16} };
        quartz_sprite tomatoes = { texture2, {388, 777}, {411 - 388, 797 - 777} };

        for(size_t i = 0; i < 15; i++)
            quartz_render_sprite(dice, {(float)(i * tomatoes.size.x) - 100, 0});

        for(size_t i = 0; i < 15; i++)
            quartz_render_sprite(tomatoes, {(float)(i * tomatoes.size.x) - 100, 20});
        
        quartz_render_draw();

        quartz_swap_buffers();
    }

    return 0;
}