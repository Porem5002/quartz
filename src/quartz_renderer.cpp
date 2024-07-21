#include <cstring>

#include "include/quartz.hpp"
#include "include/quartz_renderer.hpp"
#include "include/quartz_math.hpp"

void quartz_render_init()
{
    auto& render_buffer = quartz_implicit_context.render_buffer;
    render_buffer.size = 0;

    glGenVertexArrays(1, &render_buffer.va_id);
    glBindVertexArray(render_buffer.va_id);

    glGenBuffers(1, &render_buffer.buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, render_buffer.buffer_id);
    glBufferData(GL_ARRAY_BUFFER, QUARTZ_MAX_RENDER_BUF_CAP * sizeof(quartz_vb_unit), nullptr, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(quartz_vb_elem), (const void*)offsetof(quartz_vb_elem, pos));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(quartz_vb_elem), (const void*)offsetof(quartz_vb_elem, uvs));
}

void quartz_render_clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void quartz_render_texture(quartz_texture texture, quartz_vec2 pos)
{
    auto& render_buffer = quartz_implicit_context.render_buffer;

    quartz_vb_unit vb_unit = {
        quartz_vb_elem { { -0.5, -0.5 }, { 0, 0 } },
        quartz_vb_elem { { 0.5, -0.5 } , { 1, 0 } },
        quartz_vb_elem { { 0.5, 0.5 },   { 1, 1 } },
        quartz_vb_elem { { -0.5, 0.5 },  { 0, 1 } },
    };

    for(size_t i = 0; i < 4; i++)
    {
        float m_x = vb_unit.vertices[i].pos.x;
        float m_y = vb_unit.vertices[i].pos.y;
        vb_unit.vertices[i].pos = { pos.x + m_x * texture.width, pos.y + m_y * texture.height };

        auto m_uvx = vb_unit.vertices[i].uvs.x;
        auto m_uvy = vb_unit.vertices[i].uvs.y;
        vb_unit.vertices[i].uvs = { m_uvx * texture.width, m_uvy * texture.height };
    }

    unsigned int index_offset = (sizeof(quartz_vb_unit)/sizeof(quartz_vb_elem)) * render_buffer.size;

    quartz_ib_unit ib_unit = {
        index_offset, index_offset + 1, index_offset + 2,
        index_offset + 2, index_offset + 3, index_offset
    };

    memcpy(&render_buffer.vbo[render_buffer.size], &vb_unit, sizeof(vb_unit));
    memcpy(&render_buffer.ibo[render_buffer.size], &ib_unit, sizeof(ib_unit));
    render_buffer.size++;
}

void quartz_render_texture_slice(quartz_texture texture, quartz_vec2 pos, quartz_texture_slice slice)
{
    auto& render_buffer = quartz_implicit_context.render_buffer;

    quartz_vb_unit vb_unit = {
        quartz_vb_elem { { -0.5, -0.5 }, { 0, 0 } },
        quartz_vb_elem { { 0.5, -0.5 } , { 1, 0 } },
        quartz_vb_elem { { 0.5, 0.5 },   { 1, 1 } },
        quartz_vb_elem { { -0.5, 0.5 },  { 0, 1 } },
    };

    for(size_t i = 0; i < 4; i++)
    {
        float m_x = vb_unit.vertices[i].pos.x;
        float m_y = vb_unit.vertices[i].pos.y;
        vb_unit.vertices[i].pos = { pos.x + m_x * slice.size.x, pos.y + m_y * slice.size.y };

        auto m_uvx = vb_unit.vertices[i].uvs.x;
        auto m_uvy = vb_unit.vertices[i].uvs.y;
        vb_unit.vertices[i].uvs = {
            slice.offset.x + m_uvx * slice.size.x,
            texture.height - (slice.offset.y + (1 - m_uvy) * slice.size.y),
        };
    }

    unsigned int index_offset = (sizeof(quartz_vb_unit)/sizeof(quartz_vb_elem)) * render_buffer.size;

    quartz_ib_unit ib_unit = {
        index_offset, index_offset + 1, index_offset + 2,
        index_offset + 2, index_offset + 3, index_offset
    };

    memcpy(&render_buffer.vbo[render_buffer.size], &vb_unit, sizeof(vb_unit));
    memcpy(&render_buffer.ibo[render_buffer.size], &ib_unit, sizeof(ib_unit));
    render_buffer.size++;
}

void quartz_render_draw()
{
    auto& render_buffer = quartz_implicit_context.render_buffer;

    glBindBuffer(GL_ARRAY_BUFFER, render_buffer.buffer_id);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quartz_vb_unit) * render_buffer.size, render_buffer.vbo);
    glDrawElements(GL_TRIANGLES, sizeof(quartz_ib_unit)/sizeof(unsigned int) * render_buffer.size, GL_UNSIGNED_INT, render_buffer.ibo);

    render_buffer.size = 0;
}