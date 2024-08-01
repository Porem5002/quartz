#ifndef QUARTZ_DRAW_HEADER
#define QUARTZ_DRAW_HEADER

#include <cstdlib>

#include "glinclude.hpp"
#include "quartz_common.hpp"

struct quartz_camera2D
{
    float x, y;
    float width, height;
    float zoom;
};

quartz_mat4 quartz_camera2D_to_mat4(quartz_camera2D camera);
quartz_vec2 quartz_viewport_to_world2D(quartz_camera2D camera, quartz_ivec2 position, quartz_viewport viewport);

void quartz_render_init();
void quartz_render_set_mvp(quartz_mat4& mvp);
void quartz_render_clear(float r, float g, float b, float a);
void quartz_render_texture(quartz_texture texture, quartz_vec2 pos, quartz_vec2 scale = {1.0f, 1.0f}, float rotation = 0.0f, quartz_color tint = QUARTZ_WHITE);
void quartz_render_sprite(quartz_sprite sprite, quartz_vec2 pos, quartz_vec2 scale = {1.0f, 1.0f}, float rotation = 0.0f, quartz_color tint = QUARTZ_WHITE);
void quartz_render_flush();

#endif