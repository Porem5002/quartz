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

#ifndef PONG_BALL_HEADER
#define PONG_BALL_HEADER

#include "player.hpp"

struct game_data;

struct ball
{
    static constexpr quartz_vec2 SIZE = {15.0f, 15.0f};
    static constexpr float IDLE_SPEED = 250;
    static constexpr float PLAYING_SPEED = 500;

    quartz_vec2 position = { 0, 0 };
    quartz_vec2 velocity = { IDLE_SPEED, 0 };
    quartz_color color = QUARTZ_WHITE;

    quartz_aabb2 get_aabb() const
    {
        return { position.x, position.y, SIZE.x / 2.0f, SIZE.y / 2.0f };
    }

    void fixed_update(game_data& game);

    void draw()
    {
        quartz_render2D_quad(color, position, SIZE);
    }
};

#endif