#include <quartz.hpp>

#include "include/player.hpp"
#include "include/game.hpp"
#include "include/ball.hpp"

constexpr float FIXED_DELTA_TIME = 1.0f / 144.0f;

int main()
{
    quartz_start(1280, 720, "Quartz Pong");

    quartz_set_vsync(true);
    quartz_set_fixed_delta_time(FIXED_DELTA_TIME);

    quartz_render_init();

    game_data game = {};

    auto screen_vp = quartz_get_screen_viewport();
    auto game_vp = quartz_make_viewport(quartz_viewport_calc_boxed(screen_vp, game.WORLD_WIDTH, game.WORLD_HEIGHT));

    quartz_camera2D cam = {};
    cam.width = game.WORLD_WIDTH;
    cam.height = game.WORLD_HEIGHT;
    cam.zoom = 1.0f;
    quartz_camera2D_recalc(&cam);

    quartz_render_set_viewport(game_vp);
    quartz_render_set_camera(&cam);

    while(quartz_update())
    {
        if(quartz_was_screen_resized())
            game_vp.set(quartz_viewport_calc_boxed(screen_vp, game.WORLD_WIDTH, game.WORLD_HEIGHT));

        game.update();

        while(quartz_fixed_update())
            game.fixed_update();

        quartz_clear(QUARTZ_BLACK);
        game.draw();
        quartz_render_flush();
    }

    return 0;
}