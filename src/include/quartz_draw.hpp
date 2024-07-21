#ifndef QUARTZ_DRAW_HEADER
#define QUARTZ_DRAW_HEADER

#include <cstdlib>

#include "quartz_math.hpp"

constexpr size_t QUARTZ_MAX_RENDER_BUF_CAP = 1000;

struct quartz_texture
{
    GLuint id;
    int width, height, channels;
};

struct quartz_texture_slice
{
    quartz_uvec2 offset;
    quartz_uvec2 size;
};

struct quartz_vb_elem
{
    quartz_vec2 pos;
    quartz_vec2 uvs;
};

struct quartz_vb_unit
{
    quartz_vb_elem vertices [4];
};

struct quartz_ib_unit
{
    unsigned int indices [6];
};

struct quartz_render_buffer
{
    unsigned int buffer_id;
    size_t size;
    quartz_vb_unit vbo [QUARTZ_MAX_RENDER_BUF_CAP];
    quartz_ib_unit ibo [QUARTZ_MAX_RENDER_BUF_CAP];
};

void quartz_draw_init();
void quartz_draw_texture(quartz_texture texture, quartz_vec2 pos);
void quartz_draw_texture_slice(quartz_texture texture, quartz_vec2 pos, quartz_texture_slice slice);
void quartz_flush_draws();

#endif