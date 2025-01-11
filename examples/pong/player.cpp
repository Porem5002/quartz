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

void player::update()
{
    move_y = 0.0f;

    if(quartz_is_key_down(up_key) || quartz_is_key_held(up_key))
        move_y++;

    if(quartz_is_key_down(down_key) || quartz_is_key_held(down_key))
        move_y--;
}

void player::fixed_update()
{
    position.y += get_velocity().y;
    position.y = quartz_clamp(position.y, -(game_data::WORLD_HEIGHT - SIZE.y) / 2.0f,
                                           (game_data::WORLD_HEIGHT - SIZE.y) / 2.0f);
}