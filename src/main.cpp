#include "include/quartz.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#undef STB_IMAGE_IMPLEMENTATION

#include "quartz.cpp"
#include "quartz_math.cpp"
#include "quartz_renderer.cpp"
#include "quartz_window.cpp"
#include "quartz_input.cpp"
#include "glload.cpp"


static const char* vertex_shader = "#version 430 core\n"
                                    "layout (location = 0) in vec2 v_vertexPos;\n"
                                    "layout (location = 1) in vec2 v_texturePos;\n"
                                    "layout (location = 2) in float v_textureIndex;\n"
                                    "out vec2 f_texturePos;\n"
                                    "out float f_textureIndex;\n"
                                    "uniform mat4 u_mvp;\n"
                                    "void main()\n"
                                    "{\n"
                                        "f_texturePos = v_texturePos;\n"
                                        "f_textureIndex = v_textureIndex;\n"
                                        "gl_Position = u_mvp * vec4(v_vertexPos, 0, 1.0);\n"
                                    "}\n";

static const char* frag_shader = "#version 430 core\n"
                                "in vec2 f_texturePos;\n"
                                "in float f_textureIndex;\n"
                                "uniform sampler2D u_textures [32];\n"
                                "out vec4 fragColor;\n"
                                "void main()\n"
                                "{\n"
                                    "fragColor = texelFetch(u_textures[int(f_textureIndex)], ivec2(f_texturePos), 0);\n"
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

    GLuint u_mvp = glGetUniformLocation(shader, "u_mvp");
    GLuint u_textures = glGetUniformLocation(shader, "u_textures");

    quartz_mat4 proj = quartz_camera2D_to_mat4(cam);
    glUniformMatrix4fv(u_mvp, 1, GL_FALSE, &proj.values[0][0]);

    // Assign all texture slots to shader
    int samplers [32];

    for(size_t i = 0; i < quartz_renderer::TEXTURE_SLOT_CAP; i++)
        samplers[i] = (int)i;
    
    glUniform1iv(u_textures, 32, samplers);

    quartz_sprite dice = { texture1, {16, 0}, {15, 16} };
    quartz_sprite tomatoes = { texture2, {388, 777}, {411 - 388, 797 - 777} };

    bool selector = true;

    while(quartz_is_running())
    {
        quartz_update_events();

        printf("FPS: %f\n", 1.0f / quartz_get_delta_time());

        quartz_render_clear(0.2, 0.2, 0.23, 1.0);

        quartz_uvec2 screen_mouse_pos = quartz_get_mouse_pos();
        quartz_vec2 mouse_pos = quartz_screen_to_world2D(cam, screen_mouse_pos);

        if(quartz_is_key_down(QUARTZ_KEY_L_MOUSE_BTN))
            selector = !selector;

        quartz_render_sprite(selector ? dice : tomatoes, mouse_pos);
        
        quartz_render_draw();

        quartz_swap_buffers();
    }

    return 0;
}