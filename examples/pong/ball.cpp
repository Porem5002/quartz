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

#include <cmath>

#include "include/ball.hpp"
#include "include/game.hpp"

void ball::fixed_update(game_data& game)
{
    quartz_vec2 v = velocity;
    v.x *= quartz_get_delta_time();
    v.y *= quartz_get_delta_time();

    quartz_aabb2 ball_box = get_aabb();

    struct obstacle_info { quartz_vec2 v; quartz_aabb2 box; };

    // NOTE: Taking velocity of the players into account leading to more accurate collisions
    obstacle_info obstacles [4] = {
        { game.p1.get_velocity(), game.p1.get_aabb() },
        { game.p2.get_velocity(), game.p2.get_aabb() },
        { {0,0}, { 0, game.WORLD_HEIGHT / 2.0f + 5.0f, game.WORLD_WIDTH/2.0f, 5.0f } },
        { {0,0}, { 0, -game.WORLD_HEIGHT / 2.0f - 5.0f, game.WORLD_WIDTH/2.0f, 5.0f } },
    };
 
    size_t col_index = 0;
    quartz_swept_info col = {false, 1.0, {0.0,0.0}};

    // NOTE: Find the collision that limits the movement the most (min t)
    for(size_t i = 0; i < 4; i++)
    {
        quartz_swept_info curr_col = quartz_aabb2_swept_aabb2(ball_box, v, obstacles[i].box, obstacles[i].v);

        if(curr_col.collided && curr_col.t < col.t)
        {
            col = curr_col;
            col_index = i;
        }
    }
    
    position.x += v.x * col.t;
    position.y += v.y * col.t;

    if(col.collided)
    {
        if(col_index == 0 || col_index == 1)
        {
            quartz_vec2 diff;
            diff.x = position.x - obstacles[col_index].box.x;
            diff.y = position.y - obstacles[col_index].box.y;

            float dist = sqrtf(diff.x * diff.x + diff.y * diff.y);

            quartz_vec2 dir = diff;
            dir.x /= dist;
            dir.y /= dist;

            velocity.x = dir.x * PLAYING_SPEED;
            velocity.y = dir.y * PLAYING_SPEED;
        }
        else
        {
            velocity.y *= -1;
        }
    }

    if(ball_box.x - ball_box.hwidth > game_data::WORLD_WIDTH/2.0f)
    {
        game.add_point_to_p1();
    
        if(game.mode != game_mode::FINISHED)
        {
            position = { 0, 0 };
            velocity = { -IDLE_SPEED, 0 };
        }
    }

    if(ball_box.x + ball_box.hwidth < -game_data::WORLD_WIDTH/2.0f)
    {
        game.add_point_to_p2();

        if(game.mode != game_mode::FINISHED)
        {
            position = { 0, 0 };
            velocity = { IDLE_SPEED, 0 };
        }
    }
}