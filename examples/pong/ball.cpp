#include <cmath>

#include "include/ball.hpp"
#include "include/game.hpp"

void ball::fixed_update(game_data& game)
{
    position.x += velocity.x * quartz_get_delta_time();
    position.y += velocity.y * quartz_get_delta_time();

    aabb collider = get_aabb();

    bool collided_y = collider.y + collider.hheight > game_data::WORLD_HEIGHT/2.0f ||
                      collider.y - collider.hheight < -game_data::WORLD_HEIGHT/2.0f;
    
    bool collided_p1 = aabb_is_colliding(collider, game.p1.get_aabb());
    bool collided_p2 = aabb_is_colliding(collider, game.p2.get_aabb());

    //TODO: Improve Collisions detection using Sweep AABB
    if(collided_p1 || collided_p2 || collided_y)
    {
        if(!colliding)
        {
            if(collided_p1)
            {
                quartz_vec2 diff;
                diff.x = position.x - game.p1.position.x;
                diff.y = position.y - game.p1.position.y; 

                float dist = sqrtf(diff.x * diff.x + diff.y * diff.y);

                quartz_vec2 dir = diff;
                dir.x /= dist;
                dir.y /= dist;

                velocity.x = dir.x * PLAYING_SPEED;
                velocity.y = dir.y * PLAYING_SPEED;
            }

            if(collided_p2)
            {
                quartz_vec2 diff;
                diff.x = position.x - game.p2.position.x;
                diff.y = position.y - game.p2.position.y; 

                float dist = sqrtf(diff.x * diff.x + diff.y * diff.y);

                quartz_vec2 dir = diff;
                dir.x /= dist;
                dir.y /= dist;

                velocity.x = dir.x * PLAYING_SPEED;
                velocity.y = dir.y * PLAYING_SPEED;
            }
            
            if(collided_y) velocity.y *= -1;
        }

        colliding = true;
    }
    else
    {
        colliding = false;
    }

    if(collider.x - collider.hwidth > game_data::WORLD_WIDTH/2.0f)
    {
        game.add_point_to_p1();
    
        if(game.mode != game_mode::FINISHED)
        {
            position = { 0, 0 };
            velocity = { -IDLE_SPEED, 0 };
        }
    }

    if(collider.x + collider.hwidth < -game_data::WORLD_WIDTH/2.0f)
    {
        game.add_point_to_p2();

        if(game.mode != game_mode::FINISHED)
        {
            position = { 0, 0 };
            velocity = { IDLE_SPEED, 0 };
        }
    }
}