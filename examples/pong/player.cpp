#include <quartz.hpp>

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