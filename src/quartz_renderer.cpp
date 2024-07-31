#include <cstring>

#include "include/quartz_renderer.hpp"
#include "include/quartz_common.hpp"
#include "include/quartz.hpp"

struct quartz_instance_data
{
    quartz_vec2 pos;
    quartz_vec2 uv_offset;
    quartz_vec2 uv_size;
    quartz_vec2 scale;
    quartz_color color;
    float rotation;
    float slot_index;
};

struct quartz_renderer
{
    static constexpr size_t BATCH_CAP = 1000;

    unsigned int va_id;
    unsigned int vertex_buffer_id;
    unsigned int index_buffer_id;
    unsigned int instances_buffer_id;

    size_t batch_size;
    quartz_instance_data instances [BATCH_CAP];

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
    
    float vertex_data [] = {
        -0.5, -0.5, 0, 1,
        0.5, -0.5, 1, 1,
        0.5, 0.5, 1, 0,
        -0.5, 0.5, 0, 0
    };

    unsigned int index_data [] = {
        0, 1, 2,
        2, 3, 0
    };

    renderer.batch_size = 0;
    renderer.texture_slot_index = 0;

    glGenVertexArrays(1, &renderer.va_id);
    glGenBuffers(1, &renderer.vertex_buffer_id);
    glGenBuffers(1, &renderer.index_buffer_id);
    glGenBuffers(1, &renderer.instances_buffer_id);

    glBindVertexArray(renderer.va_id);

    glBindBuffer(GL_ARRAY_BUFFER, renderer.vertex_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer.index_buffer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_data), index_data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, nullptr);
    
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)(sizeof(float) * 2));
    
    glBindBuffer(GL_ARRAY_BUFFER, renderer.instances_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quartz_instance_data) * renderer.BATCH_CAP, nullptr, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(quartz_instance_data), (const void*)offsetof(quartz_instance_data, pos));
    glVertexAttribDivisor(2, 1);

    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(quartz_instance_data), (const void*)offsetof(quartz_instance_data, uv_offset));
    glVertexAttribDivisor(3, 1);

    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 2, GL_FLOAT, GL_FALSE, sizeof(quartz_instance_data), (const void*)offsetof(quartz_instance_data, uv_size));
    glVertexAttribDivisor(4, 1);
    
    glEnableVertexAttribArray(5);
    glVertexAttribPointer(5, 2, GL_FLOAT, GL_FALSE, sizeof(quartz_instance_data), (const void*)offsetof(quartz_instance_data, scale));
    glVertexAttribDivisor(5, 1);

    glEnableVertexAttribArray(6);
    glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(quartz_instance_data), (const void*)offsetof(quartz_instance_data, color));
    glVertexAttribDivisor(6, 1);

    glEnableVertexAttribArray(7);
    glVertexAttribPointer(7, 1, GL_FLOAT, GL_FALSE, sizeof(quartz_instance_data), (const void*)offsetof(quartz_instance_data, rotation));
    glVertexAttribDivisor(7, 1);

    glEnableVertexAttribArray(8);
    glVertexAttribPointer(8, 1, GL_FLOAT, GL_FALSE, sizeof(quartz_instance_data), (const void*)offsetof(quartz_instance_data, slot_index));
    glVertexAttribDivisor(8, 1);

    glBindVertexArray(0);
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

void quartz_render_texture(quartz_texture texture, quartz_vec2 pos, float rotation, quartz_color tint)
{
    unsigned int slot = quartz_render_push_new_texture(texture);

    if(renderer.batch_size == renderer.BATCH_CAP)
        quartz_render_draw();

    quartz_instance_data instance = {
        pos, {0,0}, {1,1}, {(float)texture->width, (float)texture->height}, tint, rotation, (float)slot
    };

    renderer.instances[renderer.batch_size] = instance;
    renderer.batch_size++;
}

void quartz_render_sprite(quartz_sprite sprite, quartz_vec2 pos, float rotation, quartz_color tint)
{
    unsigned int slot = quartz_render_push_new_texture(sprite.atlas);

    if(renderer.batch_size == renderer.BATCH_CAP)
        quartz_render_draw();

    quartz_vec2 uv_offset = {
        (float)sprite.offset.x / (float)sprite.atlas->width,
        (float)sprite.offset.y / (float)sprite.atlas->height
    };

    quartz_vec2 uv_size = {
        (float)sprite.size.x / (float)sprite.atlas->width,
        (float)sprite.size.y / (float)sprite.atlas->height
    };

    quartz_instance_data instance = {
        pos, uv_offset, uv_size, {(float)sprite.size.x, (float)sprite.size.y}, tint, rotation, (float)slot
    };

    renderer.instances[renderer.batch_size] = instance;
    renderer.batch_size++;
}

void quartz_render_draw()
{
    if(renderer.batch_size == 0) return;

    glBindBuffer(GL_ARRAY_BUFFER, renderer.instances_buffer_id);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quartz_instance_data) * renderer.batch_size, renderer.instances);

    glBindVertexArray(renderer.va_id);
    glDrawElementsInstanced(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, 0, renderer.batch_size);

    renderer.batch_size = 0;
}