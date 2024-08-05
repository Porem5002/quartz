#ifndef PONG_GAME_HEADER
#define PONG_GAME_HEADER

#include <quartz.hpp>

#include "player.hpp"
#include "ball.hpp"

enum class game_mode
{
    START,
    PLAYING,
    FINISHED,
};

struct game_data
{
    static constexpr int WORLD_WIDTH = 600;
    static constexpr int WORLD_HEIGHT = 400;
    
    static constexpr quartz_color BG_COLOR = {47/255.0f, 47/255.0f, 47/255.0f, 1.0};
    static constexpr quartz_color PAUSE_PANEL_COLOR = {0.0, 0.0, 0.0, 0.3};
    
    static constexpr quartz_color P1_COLOR = { 245/255.0f, 47/255.0f, 47/255.0f, 1.0f };
    static constexpr quartz_color P2_COLOR = { 47/255.0f, 144/255.0f, 255/255.0f, 1.0f };

    static constexpr int POINTS_TO_WIN = 10;

    game_mode mode = game_mode::START;
    player p1 = { {-250, 0}, P1_COLOR, QUARTZ_KEY_W, QUARTZ_KEY_S };
    player p2 = { {250, 0}, P2_COLOR, QUARTZ_KEY_U, QUARTZ_KEY_J };
    ball b = {};

    void update(float dt)
    {
        switch(mode)
        {
            case game_mode::START:  
                if(quartz_is_key_down(QUARTZ_KEY_SPACE))
                    mode = game_mode::PLAYING;
                break;
            case game_mode::PLAYING:
                p1.update(dt);
                p2.update(dt);
                b.update(dt, *this);
                break;
            case game_mode::FINISHED:
                if(quartz_is_key_down(QUARTZ_KEY_SPACE))
                    reset();
                break;
        }
    }

    void reset()
    {
        mode = game_mode::START;
        
        p1.position = {-250, 0};
        p1.points = 0;

        p2.position = {250, 0};
        p2.points = 0;

        b = {};
    }

    void add_point_to_p1()
    {
        if(++p1.points >= game_data::POINTS_TO_WIN)
            mode = game_mode::FINISHED;
    }

    void add_point_to_p2()
    {
        if(++p2.points >= game_data::POINTS_TO_WIN)
            mode = game_mode::FINISHED;
    }

    void draw(quartz_sprite quad)
    {
        quartz_render_sprite(quad, {0, 0}, {(float)WORLD_WIDTH, (float)WORLD_HEIGHT}, 0.0f, BG_COLOR);

        b.draw(quad);
        p1.draw(quad);
        p2.draw(quad);

        draw_points_for_player(quad, p1, -1);
        draw_points_for_player(quad, p2, 1);
        
        if(mode != game_mode::PLAYING)
            quartz_render_sprite(quad, {0, 0}, {(float)WORLD_WIDTH, (float)WORLD_HEIGHT}, 0.0f, PAUSE_PANEL_COLOR);
    }

    void draw_points_for_player(quartz_sprite quad, const player& p, float dir_x)
    {
        for(int i = 0; i < game_data::POINTS_TO_WIN; i++)
        {
            quartz_color color = p.points >= (i + 1) ? p.color : QUARTZ_WHITE;
            quartz_render_sprite(quad, { dir_x * (30.0f + 10.0f * (i + 1)), 180 }, { 5, 15 }, 0.0f, color);
        }
    }
};

#endif