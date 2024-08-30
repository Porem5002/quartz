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

#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <quartz.hpp>

struct player
{
    static constexpr quartz_vec2 SIZE = {15.0f, 50.0f};
    static constexpr float SPEED = 340.0f;

    quartz_vec2 position;
    quartz_color color;

    quartz_keycode up_key;
    quartz_keycode down_key;

    int points = 0;
    float move_y = 0.0f;

    quartz_aabb2 get_aabb() const
    {
        return { position.x, position.y, SIZE.x / 2.0f, SIZE.y / 2.0f };
    }

    quartz_vec2 get_velocity() const
    {
        return { 0, move_y * SPEED * quartz_get_delta_time() };
    }

    void update();

    void fixed_update();

    void draw()
    {
        quartz_render2D_quad(color, position, SIZE);
    }
};

#endif