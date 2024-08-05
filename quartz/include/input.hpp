#ifndef QUARTZ_INPUT_HEADER
#define QUARTZ_INPUT_HEADER

#include <cstdlib>

enum  quartz_keycode : size_t
{
    QUARTZ_KEY_NONE,

    QUARTZ_KEY_L_MOUSE_BTN,
    QUARTZ_KEY_R_MOUSE_BTN,
    QUARTZ_KEY_M_MOUSE_BTN,

    QUARTZ_KEY_0,
    QUARTZ_KEY_1,
    QUARTZ_KEY_2,
    QUARTZ_KEY_3,
    QUARTZ_KEY_4,
    QUARTZ_KEY_5,
    QUARTZ_KEY_6,
    QUARTZ_KEY_7,
    QUARTZ_KEY_8,
    QUARTZ_KEY_9,

    QUARTZ_KEY_A,
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

    QUARTZ_KEY_BACK,
    QUARTZ_KEY_TAB,
    QUARTZ_KEY_SPACE,

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

void quartz_update_key_states();
void quartz_register_key(quartz_keycode key, bool up);

bool quartz_is_key_down(quartz_keycode key);
bool quartz_is_key_held(quartz_keycode key);
bool quartz_is_key_up(quartz_keycode key);

#endif