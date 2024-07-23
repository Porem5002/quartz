#ifndef QUARTZ_DRAW_HEADER
#define QUARTZ_DRAW_HEADER

#include <cstdlib>

#include "glinclude.hpp"
#include "quartz_common.hpp"

struct quartz_camera2D
{
    float x, y;
    float width, height;
};

quartz_mat4 quartz_camera2D_to_mat4(quartz_camera2D camera);

void quartz_render_init();
void quartz_render_clear(float r, float g, float b, float a);
void quartz_render_texture(quartz_texture texture, quartz_vec2 pos);
void quartz_render_sprite(quartz_sprite sprite, quartz_vec2 pos);
void quartz_render_draw();

#endif