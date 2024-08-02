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

    auto screen_vp = quartz_get_screen_viewport();
    auto game_vp = quartz_make_viewport(quartz_viewport_calc_boxed(screen_vp, GAME_WIDTH, GAME_HEIGHT));

    quartz_camera2D cam = {};
    cam.width = GAME_WIDTH;
    cam.height = GAME_HEIGHT;
    cam.zoom = 1.0f;
    quartz_camera2D_recalc(&cam);

    quartz_sprite pixel = { texture1, {0, 0}, {1, 1} };
    quartz_sprite dice = { texture1, {16, 0}, {15, 16} };
    quartz_sprite tomatoes = { texture2, {388, 777}, {411 - 388, 797 - 777} };

    while(quartz_update())
    {
        if(quartz_was_screen_resized())
            game_vp.set(quartz_viewport_calc_boxed(screen_vp, GAME_WIDTH, GAME_HEIGHT));

        quartz_ivec2 screen_mouse_pos = quartz_get_mouse_pos();
        quartz_vec2 mouse_pos = quartz_viewport_to_world2D(cam, screen_mouse_pos, game_vp);

        quartz_clear(QUARTZ_BLACK);
        
        quartz_color bg_color = {0.2, 0.2, 0.23, 1.0};

        quartz_render_set_viewport(game_vp);
        quartz_render_set_camera(&cam);
        quartz_render_sprite(pixel, {cam.x, cam.y}, {(float)screen_vp.get_width(), (float)screen_vp.get_height()}, 0.0f, bg_color);
        quartz_render_sprite(dice, mouse_pos, {1.0f, 1.0f}, 0.0f, QUARTZ_GREEN);
        quartz_render_flush();
    }

    return 0;
}