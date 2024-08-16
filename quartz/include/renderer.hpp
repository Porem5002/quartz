#ifndef QUARTZ_DRAW_HEADER
#define QUARTZ_DRAW_HEADER

#include <cstdlib>

#include "common.hpp"
#include "viewport.hpp"

struct quartz_camera2D
{
    float x, y;
    float width, height;
    float zoom;
};

quartz_camera2D quartz_init_camera2D(int width, int height);
quartz_mat3 quartz_camera2D_get_projection(const quartz_camera2D* camera);
quartz_vec2 quartz_camera2D_to_world_through_viewport(const quartz_camera2D* camera, quartz_ivec2 position, quartz_viewport viewport);

void quartz_render_init();
void quartz_render_set_viewport(quartz_viewport viewport);
void quartz_render_set_camera(const quartz_camera2D* camera);
void quartz_render_texture(quartz_texture texture, quartz_vec2 pos, quartz_vec2 scale = {1.0f, 1.0f}, float rotation = 0.0f, quartz_color tint = QUARTZ_WHITE);
void quartz_render_sprite(quartz_sprite sprite, quartz_vec2 pos, quartz_vec2 scale = {1.0f, 1.0f}, float rotation = 0.0f, quartz_color tint = QUARTZ_WHITE);
void quartz_render_quad(quartz_color color, quartz_vec2 pos, quartz_vec2 scale, float rotation = 0.0f);
void quartz_render_flush();

#endif