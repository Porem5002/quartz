#include <include/quartz.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#undef STB_IMAGE_IMPLEMENTATION

#include <quartz.cpp>
#include <quartz_math.cpp>
#include <quartz_renderer.cpp>
#include <quartz_window.cpp>
#include <quartz_input.cpp>
#include <glload.cpp>
#include <quartz_viewport.cpp>

#define GAME_WIDTH 320
#define GAME_HEIGHT 180

int main()
{
    quartz_start(1280, 720, "My Window");

    quartz_texture texture1 = quartz_load_texture("assets/TEXTURE_ATLAS.png");
    quartz_texture texture2 = quartz_load_texture("assets/terrain_atlas.png");

    quartz_render_init();

    auto screen_viewport = quartz_get_screen_viewport();

    quartz_camera2D cam = {};
    cam.width = GAME_WIDTH;
    cam.height = GAME_HEIGHT;
    cam.zoom = 1.0f;

    quartz_mat4 cam_proj = quartz_camera2D_to_mat4(cam);
    quartz_render_set_mvp(cam_proj);

    quartz_viewport viewport = quartz_viewport_boxed(screen_viewport, GAME_WIDTH, GAME_HEIGHT);
    quartz_set_viewport(viewport);

    quartz_sprite pixel = { texture1, {0, 0}, {1, 1} };
    quartz_sprite dice = { texture1, {16, 0}, {15, 16} };
    quartz_sprite tomatoes = { texture2, {388, 777}, {411 - 388, 797 - 777} };

    while(quartz_is_running())
    {
        quartz_update_events();

        if(quartz_was_screen_resized())
        {
            screen_viewport = quartz_get_screen_viewport();
            viewport = quartz_viewport_boxed(screen_viewport, GAME_WIDTH, GAME_HEIGHT);
            quartz_set_viewport(viewport);
        }

        quartz_ivec2 screen_mouse_pos = quartz_get_mouse_pos();
        quartz_vec2 mouse_pos = quartz_viewport_to_world2D(cam, screen_mouse_pos, viewport);

        quartz_color bg_color = {0.2, 0.2, 0.23, 1.0}; 

        quartz_render_clear(0.0, 0.0, 0.0, 1.0);
        
        quartz_render_sprite(pixel, {0,0}, {(float)screen_viewport.width, (float)screen_viewport.height}, 0.0f, bg_color);
        quartz_render_sprite(dice, mouse_pos, {1.0f, 1.0f}, 0.0f, QUARTZ_GREEN);
        quartz_render_flush();

        quartz_swap_buffers();
    }

    return 0;
}