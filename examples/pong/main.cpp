/*
MIT License

Copyright (c) 2024-2025 Carlos Bandeira

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <quartz.h>

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
    auto game_vp = quartz_make_viewport();

    quartz_camera2D cam = quartz_init_camera2D(game.WORLD_WIDTH, game.WORLD_HEIGHT);

    quartz_render2D_init();
    quartz_render2D_set_viewport(game_vp);
    quartz_render2D_set_camera(&cam);

    while(quartz_update())
    {
        if(quartz_is_startup() || quartz_was_screen_resized())
        {
            quartz_rect r = quartz_rect_calc_boxed(screen_vp.get_rect(), (float)game.WORLD_WIDTH / game.WORLD_HEIGHT);
            quartz_viewport_set_rect(game_vp, r);
        }

        game.update();

        while(quartz_fixed_update())
            game.fixed_update();

        quartz_clear(QUARTZ_BLACK);
        game.draw();
        quartz_render2D_flush();
    }

    quartz_finish();

    return 0;
}