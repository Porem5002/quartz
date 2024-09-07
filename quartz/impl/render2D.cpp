/*
MIT License

Copyright (c) 2024 Carlos Bandeira

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <cstring>
#include <vector>

#include <gapil.h>

#include "../include/render2D.h"
#include "../include/common.h"
#include "../include/base.h"
#include "../include/gfx_info.h"

struct quartz_render2D
{
    static constexpr size_t INSTANCE_CAP = 1000;

    struct instance_data
    {
        float mode;
        quartz_vec2 pos;
        quartz_vec2 uv_offset;
        quartz_vec2 uv_size;
        quartz_vec2 scale;
        quartz_color color;
        float rotation;
        float slot_index;
    };

    quartz_shader shader;
    unsigned int u_projection;

    unsigned int va_id;
    unsigned int vertex_buffer_id;
    unsigned int index_buffer_id;
    unsigned int instances_buffer_id;

    size_t instance_count;
    instance_data instances [INSTANCE_CAP];

    size_t texture_slot_cap;
    std::vector<quartz_texture> texture_slots;

    quartz_sprite quad_sprite;
    quartz_viewport viewport;
    quartz_mat3 projection;
};

static quartz_render2D render2D_context;

static unsigned int quartz_render2D_push_new_texture(quartz_texture texture);

quartz_camera2D quartz_init_camera2D(int width, int height)
{
    quartz_camera2D camera = {};
    camera.width = width;
    camera.height = height;
    camera.zoom = 1.0f;
    return camera;
}

quartz_mat3 quartz_camera2D_get_projection(const quartz_camera2D* camera)
{
    return quartz_orth2d_projection(camera->x - camera->width / (2 * camera->zoom),
                                    camera->x + camera->width / (2 * camera->zoom),
                                    camera->y - camera->height / (2 * camera->zoom),
                                    camera->y + camera->height / (2 * camera->zoom));
}

quartz_vec2 quartz_camera2D_to_world_through_viewport(const quartz_camera2D* camera, quartz_ivec2 position, quartz_viewport viewport)
{
    position = quartz_rect_clamp_point(viewport.get_rect(), position);

    float norm_x = (float)(position.x - viewport.get_x()) / viewport.get_width() - 0.5f;
    float norm_y = (float)(position.y - viewport.get_y()) / viewport.get_height() - 0.5f;

    float world_x = camera->x + norm_x * camera->width / camera->zoom;
    float world_y = camera->y + norm_y * camera->height / camera->zoom;

    return quartz_vec2 { world_x, world_y };
}

void quartz_render2D_init()
{
    #if 1 // Setup Shader
    static const char* vertex_shader =
        #include "builtin_shaders\2d.vs"
    ;

    static const char* frag_shader = 
        #include "builtin_shaders\2d.fs"
    ;

    render2D_context.shader = quartz_make_shader(vertex_shader, frag_shader);
    render2D_context.u_projection = glGetUniformLocation(render2D_context.shader.get_program_id(), "u_projection");
    #endif

    render2D_context.instance_count = 0;

    // Setup texture slots
    render2D_context.texture_slot_cap = quartz_gfx_get_texture_unit_cap();
    render2D_context.texture_slots.reserve(render2D_context.texture_slot_cap);

    // Setup shader samplers for texture slots
    std::vector<int> samplers;
    samplers.resize(render2D_context.texture_slot_cap);

    for(size_t i = 0; i < render2D_context.texture_slot_cap; i++)
        samplers[i] = (int)i;
    
    GLuint u_textures = glGetUniformLocation(render2D_context.shader.get_program_id(), "u_textures");
    quartz_use_shader(render2D_context.shader);
    glUniform1iv(u_textures, render2D_context.texture_slot_cap, samplers.data());
    
    #if 1 // Setup OpenGL Attributes
    float vertex_data [] = {
        -0.5, -0.5, 0, 1, // Bottom Left
        0.5, -0.5, 1, 1,  // Bottom Right
        0.5, 0.5, 1, 0,   // Top Right
        -0.5, 0.5, 0, 0   // Top Left
    };

    unsigned int index_data [] = {
        0, 1, 2,
        2, 3, 0
    };

    glGenVertexArrays(1, &render2D_context.va_id);
    glGenBuffers(1, &render2D_context.vertex_buffer_id);
    glGenBuffers(1, &render2D_context.index_buffer_id);
    glGenBuffers(1, &render2D_context.instances_buffer_id);

    glBindVertexArray(render2D_context.va_id);

    glBindBuffer(GL_ARRAY_BUFFER, render2D_context.vertex_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, render2D_context.index_buffer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_data), index_data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, nullptr);
    
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)(sizeof(float) * 2));
    
    using instance_data = quartz_render2D::instance_data;

    glBindBuffer(GL_ARRAY_BUFFER, render2D_context.instances_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(instance_data) * render2D_context.INSTANCE_CAP, nullptr, GL_DYNAMIC_DRAW);
    
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(instance_data), (const void*)offsetof(instance_data, mode));
    glVertexAttribDivisor(2, 1);

    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(instance_data), (const void*)offsetof(instance_data, pos));
    glVertexAttribDivisor(3, 1);

    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 2, GL_FLOAT, GL_FALSE, sizeof(instance_data), (const void*)offsetof(instance_data, uv_offset));
    glVertexAttribDivisor(4, 1);

    glEnableVertexAttribArray(5);
    glVertexAttribPointer(5, 2, GL_FLOAT, GL_FALSE, sizeof(instance_data), (const void*)offsetof(instance_data, uv_size));
    glVertexAttribDivisor(5, 1);
    
    glEnableVertexAttribArray(6);
    glVertexAttribPointer(6, 2, GL_FLOAT, GL_FALSE, sizeof(instance_data), (const void*)offsetof(instance_data, scale));
    glVertexAttribDivisor(6, 1);

    glEnableVertexAttribArray(7);
    glVertexAttribPointer(7, 4, GL_FLOAT, GL_FALSE, sizeof(instance_data), (const void*)offsetof(instance_data, color));
    glVertexAttribDivisor(7, 1);

    glEnableVertexAttribArray(8);
    glVertexAttribPointer(8, 1, GL_FLOAT, GL_FALSE, sizeof(instance_data), (const void*)offsetof(instance_data, rotation));
    glVertexAttribDivisor(8, 1);

    glEnableVertexAttribArray(9);
    glVertexAttribPointer(9, 1, GL_FLOAT, GL_FALSE, sizeof(instance_data), (const void*)offsetof(instance_data, slot_index));
    glVertexAttribDivisor(9, 1);

    glBindVertexArray(0);
    #endif

    // White pixel texture
    unsigned char quad_pixel [] = { 255, 255, 255, 255 };
    quartz_texture quad_texture = quartz_make_texture(1, 1, quad_pixel);
    render2D_context.quad_sprite = { quad_texture, {0,0}, {1, 1} };

    quartz_viewport screen_vp = quartz_get_screen_viewport();
    render2D_context.viewport = screen_vp;

    quartz_camera2D default_camera = quartz_init_camera2D(screen_vp.get_width(), screen_vp.get_height());
    render2D_context.projection = quartz_camera2D_get_projection(&default_camera);
}

void quartz_render2D_set_viewport(quartz_viewport viewport)
{
    render2D_context.viewport = viewport;
}

void quartz_render2D_set_camera(const quartz_camera2D* camera)
{
    render2D_context.projection = quartz_camera2D_get_projection(camera);
}

void quartz_render2D_sprite_ex(quartz_primitive2D primitive, quartz_sprite sprite, quartz_vec2 pos, quartz_vec2 scale, float rotation, quartz_color tint)
{
    unsigned int slot = quartz_render2D_push_new_texture(sprite.atlas);

    if(render2D_context.instance_count == render2D_context.INSTANCE_CAP)
        quartz_render2D_flush();

    quartz_vec2 uv_offset = {
        (float)sprite.offset.x / (float)sprite.atlas.get_width(),
        (float)sprite.offset.y / (float)sprite.atlas.get_height()
    };

    quartz_vec2 uv_size = {
        (float)sprite.size.x / (float)sprite.atlas.get_width(),
        (float)sprite.size.y / (float)sprite.atlas.get_height()
    };

    quartz_render2D::instance_data instance = {
        (float)primitive, pos, uv_offset, uv_size,
        {(float)sprite.size.x * scale.x, (float)sprite.size.y * scale.y},
        tint, rotation, (float)slot
    };

    render2D_context.instances[render2D_context.instance_count] = instance;
    render2D_context.instance_count++;
}

void quartz_render2D_texture_ex(quartz_primitive2D primitive, quartz_texture texture, quartz_vec2 pos, quartz_vec2 scale, float rotation, quartz_color tint)
{
    quartz_sprite sprite = {};
    sprite.atlas = texture;
    sprite.offset = {0,0};
    sprite.size = {(unsigned int)texture.get_width(), (unsigned int)texture.get_height()};
    quartz_render2D_sprite_ex(primitive, sprite, pos, scale, rotation, tint);
}

void quartz_render2D_sprite(quartz_sprite sprite, quartz_vec2 pos, quartz_vec2 scale, float rotation, quartz_color tint)
{
    quartz_render2D_sprite_ex(QUARTZ_PRIMITIVE2D_QUAD, sprite, pos, scale, rotation, tint);
}

void quartz_render2D_texture(quartz_texture texture, quartz_vec2 pos, quartz_vec2 scale, float rotation, quartz_color tint)
{
    quartz_render2D_texture_ex(QUARTZ_PRIMITIVE2D_QUAD, texture, pos, scale, rotation, tint);
}

void quartz_render2D_quad(quartz_color color, quartz_vec2 pos, quartz_vec2 scale, float rotation)
{
    quartz_render2D_sprite_ex(QUARTZ_PRIMITIVE2D_QUAD, render2D_context.quad_sprite, pos, scale, rotation, color);
}

void quartz_render2D_circle(quartz_color color, quartz_vec2 pos, float radius)
{
    float diameter = radius * 2.0f;
    quartz_render2D_sprite_ex(QUARTZ_PRIMITIVE2D_CIRCLE, render2D_context.quad_sprite, pos, {diameter, diameter}, 0.0f, color);
}

void quartz_render2D_flush()
{
    if(render2D_context.instance_count == 0) return;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_MULTISAMPLE);

    glViewport(render2D_context.viewport.get_x(), render2D_context.viewport.get_y(),
               render2D_context.viewport.get_width(), render2D_context.viewport.get_height());

    quartz_use_shader(render2D_context.shader);
    glUniformMatrix3fv(render2D_context.u_projection, 1, GL_FALSE, &render2D_context.projection.values[0][0]);

    glBindBuffer(GL_ARRAY_BUFFER, render2D_context.instances_buffer_id);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quartz_render2D::instance_data) * render2D_context.instance_count, render2D_context.instances);

    glBindVertexArray(render2D_context.va_id);
    glDrawElementsInstanced(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, 0, render2D_context.instance_count);

    // Prepare for next render
    render2D_context.instance_count = 0;
    render2D_context.texture_slots.clear();
}

static unsigned int quartz_render2D_push_new_texture(quartz_texture texture)
{
    unsigned int slot;
    bool found = false;

    for (size_t i = 0; i < render2D_context.texture_slots.size(); i++)
    {
        if(render2D_context.texture_slots[i] == texture)
        {
            slot = i;
            found = true;
            break;
        }
    }

    if(!found)
    {
        QUARTZ_ASSERT(render2D_context.texture_slots.size() <= render2D_context.texture_slot_cap, "Texture slot index exceeds capacity");

        if(render2D_context.texture_slots.size() == render2D_context.texture_slot_cap)
            quartz_render2D_flush();

        slot = (unsigned int)render2D_context.texture_slots.size();
        quartz_bind_texture(texture, slot);
        render2D_context.texture_slots.push_back(texture);
    }

    return slot;
}