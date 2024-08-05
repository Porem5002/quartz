#include "include/player.hpp"
#include "include/game.hpp"

void player::update(float dt)
{
        float move_y = 0;

        if(quartz_is_key_down(up_key) || quartz_is_key_held(up_key))
            move_y++;

        if(quartz_is_key_down(down_key) || quartz_is_key_held(down_key))
            move_y--;

        position.y += move_y * dt * SPEED;

        position.y = quartz_clamp(position.y, -(game_data::WORLD_HEIGHT - SIZE.y) / 2.0f,
                                               (game_data::WORLD_HEIGHT - SIZE.y) / 2.0f);
}