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

#include "../include/input.h"

struct quartz_key_state
{
    bool down;
    bool pressed;
    bool up;
};

static quartz_key_state key_states [QUARTZ_KEY_COUNT];

void quartz_update_key_states()
{
    for(size_t i = 0; i < QUARTZ_KEY_COUNT; i++)
    {
        if(key_states[i].down)
        {
            key_states[i].down = false;
            key_states[i].pressed = true;
        }

        if(key_states[i].up)
        {
            key_states[i].up = false;
            key_states[i].pressed = false;
        }

        // FIXME: If the user moves the window while a key is down and if during the movement the key is released,
        // then the up event won't be detected so we should check manually here using GetKeyState()
    }   
}

void quartz_register_key(quartz_keycode key, bool up)
{
    if(up)
        key_states[key].up = key_states[key].down || key_states[key].pressed;
    else
        key_states[key].down = !key_states[key].pressed;
}

bool quartz_is_key_down(quartz_keycode key)
{
    return key_states[(size_t)key].down;
}

bool quartz_is_key_held(quartz_keycode key)
{
    return key_states[(size_t)key].pressed;
}

bool quartz_is_key_up(quartz_keycode key)
{
    return key_states[(size_t)key].up;
}