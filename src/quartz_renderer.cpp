#include <cstring>

#include "include/quartz_renderer.hpp"
#include "include/quartz_common.hpp"
#include "include/quartz.hpp"

struct quartz_vb_elem
{
    quartz_vec2 pos;
    quartz_vec2 uvs;
    float slot_index;
};

struct quartz_vb_unit
{
    static constexpr size_t VERTEX_COUNT = 4;

    quartz_vb_elem vertices [VERTEX_COUNT];
};

struct quartz_ib_unit
{
    static constexpr size_t INDEX_COUNT = 6;

    unsigned int indices [INDEX_COUNT];
};

struct quartz_renderer
{
    static constexpr size_t BATCH_CAP = 1000;

    unsigned int va_id;
    unsigned int buffer_id;

    size_t batch_size;
    quartz_vb_unit vbo [BATCH_CAP];
    quartz_ib_unit ibo [BATCH_CAP];

    static constexpr size_t TEXTURE_SLOT_CAP = 32;

    size_t texture_slot_index;
    quartz_texture texture_slots [TEXTURE_SLOT_CAP];
};

static quartz_renderer renderer;

static unsigned int quartz_render_push_new_texture(quartz_texture texture);

quartz_mat4 quartz_camera2D_to_mat4(quartz_camera2D camera)
{
    return quartz_orth_proj(camera.x - camera.width / 2,
                            camera.x + camera.width / 2,
                            camera.y - camera.height / 2,
                            camera.y + camera.height / 2,
                            -1.0, 1.0);
}

quartz_vec2 quartz_screen_to_world2D(quartz_camera2D camera, quartz_uvec2 position)
{
    float norm_x = (float)position.x / (float)quartz_get_screen_size().x - 0.5f;
    float norm_y = (float)position.y / (float)quartz_get_screen_size().y - 0.5f;

    float world_x = camera.x + norm_x * camera.width;
    float world_y = camera.y + norm_y * camera.height;

    return quartz_vec2 { world_x, world_y };
}

void quartz_render_init()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_MULTISAMPLE);
    
    renderer.batch_size = 0;
    renderer.texture_slot_index = 0;

    glGenVertexArrays(1, &renderer.va_id);
    glBindVertexArray(renderer.va_id);

    glGenBuffers(1, &renderer.buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, renderer.buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quartz_vb_unit) * quartz_renderer::BATCH_CAP, nullptr, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(quartz_vb_elem), (const void*)offsetof(quartz_vb_elem, pos));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(quartz_vb_elem), (const void*)offsetof(quartz_vb_elem, uvs));
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(quartz_vb_elem), (const void*)offsetof(quartz_vb_elem, slot_index));
}

void quartz_render_clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

static unsigned int quartz_render_push_new_texture(quartz_texture texture)
{
    unsigned int slot;
    bool found = false;

    for (size_t i = 0; i < renderer.texture_slot_index; i++)
    {
        if(renderer.texture_slots[i] == texture)
        {
            slot = i;
            found = true;
            break;
        }
    }

    if(!found)
    {
        QUARTZ_ASSERT(renderer.texture_slot_index < renderer.TEXTURE_SLOT_CAP, "Texture slot index exceeds capacity");

        if(renderer.texture_slot_index == renderer.TEXTURE_SLOT_CAP)
            quartz_render_draw();

        slot = renderer.texture_slot_index;

        quartz_bind_texture(texture, slot);
        
        renderer.texture_slots[renderer.texture_slot_index] = texture;
        renderer.texture_slot_index++;
    }

    return slot;
}

void quartz_render_texture(quartz_texture texture, quartz_vec2 pos)
{
    unsigned int slot = quartz_render_push_new_texture(texture);

    if(renderer.batch_size == renderer.BATCH_CAP)
        quartz_render_draw();

    quartz_vb_unit vb_unit = {
        quartz_vb_elem { { -0.5, -0.5 }, { 0, 0 }, (float)slot },
        quartz_vb_elem { { 0.5, -0.5 } , { 1, 0 }, (float)slot },
        quartz_vb_elem { { 0.5, 0.5 },   { 1, 1 }, (float)slot },
        quartz_vb_elem { { -0.5, 0.5 },  { 0, 1 }, (float)slot },
    };

    for(size_t i = 0; i < 4; i++)
    {
        float m_x = vb_unit.vertices[i].pos.x;
        float m_y = vb_unit.vertices[i].pos.y;
        vb_unit.vertices[i].pos = { pos.x + m_x * texture->width, pos.y + m_y * texture->height };

        auto m_uvx = vb_unit.vertices[i].uvs.x;
        auto m_uvy = vb_unit.vertices[i].uvs.y;
        vb_unit.vertices[i].uvs = { m_uvx * texture->width, m_uvy * texture->height };
    }

    unsigned int index_offset = quartz_vb_unit::VERTEX_COUNT * renderer.batch_size;

    quartz_ib_unit ib_unit = {
        index_offset, index_offset + 1, index_offset + 2,
        index_offset + 2, index_offset + 3, index_offset
    };

    memcpy(&renderer.vbo[renderer.batch_size], &vb_unit, sizeof(vb_unit));
    memcpy(&renderer.ibo[renderer.batch_size], &ib_unit, sizeof(ib_unit));
    renderer.batch_size++;
}

void quartz_render_sprite(quartz_sprite sprite, quartz_vec2 pos)
{
    unsigned int slot = quartz_render_push_new_texture(sprite.atlas);

    if(renderer.batch_size == renderer.BATCH_CAP)
        quartz_render_draw();

    quartz_vb_unit vb_unit = {
        quartz_vb_elem { { -0.5, -0.5 }, { 0, 0 }, (float)slot },
        quartz_vb_elem { { 0.5, -0.5 } , { 1, 0 }, (float)slot },
        quartz_vb_elem { { 0.5, 0.5 },   { 1, 1 }, (float)slot },
        quartz_vb_elem { { -0.5, 0.5 },  { 0, 1 }, (float)slot },
    };

    for(size_t i = 0; i < 4; i++)
    {
        float m_x = vb_unit.vertices[i].pos.x;
        float m_y = vb_unit.vertices[i].pos.y;
        vb_unit.vertices[i].pos = { pos.x + m_x * sprite.size.x, pos.y + m_y * sprite.size.y };

        auto m_uvx = vb_unit.vertices[i].uvs.x;
        auto m_uvy = vb_unit.vertices[i].uvs.y;
        vb_unit.vertices[i].uvs = {
            sprite.offset.x + m_uvx * sprite.size.x,
            sprite.atlas->height - (sprite.offset.y + (1 - m_uvy) * sprite.size.y),
        };
    }

    unsigned int index_offset = quartz_vb_unit::VERTEX_COUNT * renderer.batch_size;

    quartz_ib_unit ib_unit = {
        index_offset, index_offset + 1, index_offset + 2,
        index_offset + 2, index_offset + 3, index_offset
    };

    memcpy(&renderer.vbo[renderer.batch_size], &vb_unit, sizeof(vb_unit));
    memcpy(&renderer.ibo[renderer.batch_size], &ib_unit, sizeof(ib_unit));
    renderer.batch_size++;
}

void quartz_render_draw()
{
    if(renderer.batch_size == 0) return;

    glBindBuffer(GL_ARRAY_BUFFER, renderer.buffer_id);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quartz_vb_unit) * renderer.batch_size, renderer.vbo);
    glDrawElements(GL_TRIANGLES, quartz_ib_unit::INDEX_COUNT * renderer.batch_size, GL_UNSIGNED_INT, renderer.ibo);

    renderer.batch_size = 0;
}