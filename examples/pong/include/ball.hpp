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