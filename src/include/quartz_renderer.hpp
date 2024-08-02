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

    quartz_mat4 projection;
};

void quartz_camera2D_recalc(quartz_camera2D* camera);
quartz_vec2 quartz_viewport_to_world2D(quartz_camera2D camera, quartz_ivec2 position, quartz_viewport viewport);

void quartz_render_init();
void quartz_render_set_viewport(const quartz_viewport* viewport);
void quartz_render_set_camera(const quartz_camera2D* camera);
void quartz_render_texture(quartz_texture texture, quartz_vec2 pos, quartz_vec2 scale = {1.0f, 1.0f}, float rotation = 0.0f, quartz_color tint = QUARTZ_WHITE);
void quartz_render_sprite(quartz_sprite sprite, quartz_vec2 pos, quartz_vec2 scale = {1.0f, 1.0f}, float rotation = 0.0f, quartz_color tint = QUARTZ_WHITE);
void quartz_render_flush();

#endif