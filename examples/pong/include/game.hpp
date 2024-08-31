/*
MIT License

Copyright (c) 2024 Carlos Bandeira

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

#ifndef PONG_GAME_HEADER
#define PONG_GAME_HEADER

#include <quartz.h>

#include "player.hpp"
#include "ball.hpp"

enum class game_mode
{
    START,
    PLAYING,
    FINISHED,
};

struct game_data
{
    static constexpr int WORLD_WIDTH = 600;
    static constexpr int WORLD_HEIGHT = 400;
    
    static constexpr quartz_color BG_COLOR = {47/255.0f, 47/255.0f, 47/255.0f, 1.0};
    static constexpr quartz_color PAUSE_PANEL_COLOR = {0.0, 0.0, 0.0, 0.3};
    
    static constexpr quartz_color P1_COLOR = { 245/255.0f, 47/255.0f, 47/255.0f, 1.0f };
    static constexpr quartz_color P2_COLOR = { 47/255.0f, 144/255.0f, 255/255.0f, 1.0f };

    static constexpr int POINTS_TO_WIN = 10;

    game_mode mode = game_mode::START;
    player p1 = { {-250, 0}, P1_COLOR, QUARTZ_KEY_W, QUARTZ_KEY_S };
    player p2 = { {250, 0}, P2_COLOR, QUARTZ_KEY_ARROW_UP, QUARTZ_KEY_ARROW_DOWN };
    ball b = {};

    void update()
    {
        switch(mode)
        {
            case game_mode::START:  
                if(quartz_is_key_down(QUARTZ_KEY_SPACE))
                    mode = game_mode::PLAYING;
                break;
            case game_mode::PLAYING:
                p1.update();
                p2.update();
                break;
            case game_mode::FINISHED:
                if(quartz_is_key_down(QUARTZ_KEY_SPACE))
                    reset();
                break;
        }
    }

    void fixed_update()
    {
        if(mode == game_mode::PLAYING)
        {
            b.fixed_update(*this);
            p1.fixed_update();
            p2.fixed_update();
        }
    }

    void reset()
    {
        mode = game_mode::START;
        
        p1.position = {-250, 0};
        p1.points = 0;

        p2.position = {250, 0};
        p2.points = 0;

        b = {};
    }

    void add_point_to_p1()
    {
        if(++p1.points >= game_data::POINTS_TO_WIN)
            mode = game_mode::FINISHED;
    }

    void add_point_to_p2()
    {
        if(++p2.points >= game_data::POINTS_TO_WIN)
            mode = game_mode::FINISHED;
    }

    void draw()
    {
        quartz_render2D_quad(BG_COLOR, {0, 0}, {(float)WORLD_WIDTH, (float)WORLD_HEIGHT});

        b.draw();
        p1.draw();
        p2.draw();

        draw_points_for_player(p1, -1);
        draw_points_for_player(p2, 1);
        
        if(mode != game_mode::PLAYING)
            quartz_render2D_quad(PAUSE_PANEL_COLOR, {0, 0}, {(float)WORLD_WIDTH, (float)WORLD_HEIGHT});
    }

    void draw_points_for_player(const player& p, float dir_x)
    {
        for(int i = 0; i < game_data::POINTS_TO_WIN; i++)
        {
            quartz_color color = p.points >= (i + 1) ? p.color : QUARTZ_WHITE;
            quartz_render2D_quad(color, { dir_x * (30.0f + 10.0f * (i + 1)), 180 }, { 5, 15 });
        }
    }
};

#endif