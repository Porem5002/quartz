#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <quartz.hpp>

#include "aabb.hpp"

struct player
{
    static constexpr quartz_vec2 SIZE = {15.0f, 50.0f};
    static constexpr float SPEED = 340.0f;

    quartz_vec2 position;
    quartz_color color;

    quartz_keycode up_key;
    quartz_keycode down_key;

    int points = 0;

    aabb get_aabb() const
    {
        return { position.x, position.y, SIZE.x / 2.0f, SIZE.y / 2.0f };
    }

    void update(float dt);

    void draw()
    {
        quartz_render_quad(color, position, SIZE);
    }
};

#endif