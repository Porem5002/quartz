#include "../include/input.hpp"

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