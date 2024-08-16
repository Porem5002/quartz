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

    game_data game = {};

    auto screen_vp = quartz_get_screen_viewport();
    auto game_vp = quartz_make_viewport(quartz_viewport_calc_boxed(screen_vp, game.WORLD_WIDTH, game.WORLD_HEIGHT));

    quartz_camera2D cam = quartz_init_camera2D(game.WORLD_WIDTH, game.WORLD_HEIGHT);

    quartz_render_init();
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