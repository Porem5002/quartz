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

#ifndef QUARTZ_INPUT_HEADER
#define QUARTZ_INPUT_HEADER

#include <stdlib.h>

#include "api_compat.h"

QUARTZ_ENUM_DEF(quartz_keycode, size_t)
{
    QUARTZ_KEY_NONE,

    // Mouse Buttons
    QUARTZ_KEY_L_MOUSE_BTN,
    QUARTZ_KEY_R_MOUSE_BTN,
    QUARTZ_KEY_M_MOUSE_BTN,
    QUARTZ_KEY_X1_MOUSE_BTN,
    QUARTZ_KEY_X2_MOUSE_BTN,

    QUARTZ_KEY_BACK,
    QUARTZ_KEY_ENTER,

    QUARTZ_KEY_ESC,
    QUARTZ_KEY_TAB,
    QUARTZ_KEY_CAPSLOCK,
    QUARTZ_KEY_SHIFT,
    QUARTZ_KEY_CTRL,
    QUARTZ_KEY_ALT,
    QUARTZ_KEY_SPACE,

    //Function keys
    QUARTZ_KEY_F1,
    QUARTZ_KEY_F2,
    QUARTZ_KEY_F3,
    QUARTZ_KEY_F4,
    QUARTZ_KEY_F5,
    QUARTZ_KEY_F6,
    QUARTZ_KEY_F7,
    QUARTZ_KEY_F8,
    QUARTZ_KEY_F9,
    QUARTZ_KEY_F10, // TODO: Check why F10 state is not received
    QUARTZ_KEY_F11,
    QUARTZ_KEY_F12,

    // Arrow Keys
    QUARTZ_KEY_ARROW_UP,
    QUARTZ_KEY_ARROW_DOWN,
    QUARTZ_KEY_ARROW_LEFT,
    QUARTZ_KEY_ARROW_RIGHT,

    // Number Keys
    QUARTZ_KEY_0 = '0',
    QUARTZ_KEY_1,
    QUARTZ_KEY_2,
    QUARTZ_KEY_3,
    QUARTZ_KEY_4,
    QUARTZ_KEY_5,
    QUARTZ_KEY_6,
    QUARTZ_KEY_7,
    QUARTZ_KEY_8,
    QUARTZ_KEY_9,

    // Letter Keys
    QUARTZ_KEY_A = 'A',
    QUARTZ_KEY_B,
    QUARTZ_KEY_C,
    QUARTZ_KEY_D,
    QUARTZ_KEY_E,
    QUARTZ_KEY_F,
    QUARTZ_KEY_G,
    QUARTZ_KEY_H,
    QUARTZ_KEY_I,
    QUARTZ_KEY_J,
    QUARTZ_KEY_K,
    QUARTZ_KEY_L,
    QUARTZ_KEY_M,
    QUARTZ_KEY_N,
    QUARTZ_KEY_O,
    QUARTZ_KEY_P,
    QUARTZ_KEY_Q,
    QUARTZ_KEY_R,
    QUARTZ_KEY_S,
    QUARTZ_KEY_T,
    QUARTZ_KEY_U,
    QUARTZ_KEY_V,
    QUARTZ_KEY_W,
    QUARTZ_KEY_X,
    QUARTZ_KEY_Y,
    QUARTZ_KEY_Z,

    // Numpad Number Keys
    QUARTZ_KEY_NUMPAD_0,
    QUARTZ_KEY_NUMPAD_1,
    QUARTZ_KEY_NUMPAD_2,
    QUARTZ_KEY_NUMPAD_3,
    QUARTZ_KEY_NUMPAD_4,
    QUARTZ_KEY_NUMPAD_5,
    QUARTZ_KEY_NUMPAD_6,
    QUARTZ_KEY_NUMPAD_7,
    QUARTZ_KEY_NUMPAD_8,
    QUARTZ_KEY_NUMPAD_9,

    QUARTZ_KEY_COUNT,
};

QUARTZ_DEF void quartz_update_key_states();
QUARTZ_DEF void quartz_register_key(quartz_keycode key, bool up);

QUARTZ_DEF bool quartz_is_key_down(quartz_keycode key);
QUARTZ_DEF bool quartz_is_key_held(quartz_keycode key);
QUARTZ_DEF bool quartz_is_key_up(quartz_keycode key);

#endif