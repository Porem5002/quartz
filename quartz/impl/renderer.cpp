#include <cstring>

#include "../include/glinclude.hpp"
#include "../include/renderer.hpp"
#include "../include/common.hpp"
#include "../include/quartz.hpp"

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

    quartz_shader shader;
    unsigned int u_projection;

    unsigned int va_id;
    unsigned int vertex_buffer_id;
    unsigned int index_buffer_id;
    unsigned int instances_buffer_id;

    size_t batch_size;
    quartz_instance_data instances [BATCH_CAP];

    static constexpr size_t TEXTURE_SLOT_CAP = 32;

    size_t texture_slot_index;
    quartz_texture texture_slots [TEXTURE_SLOT_CAP];

    quartz_sprite quad_sprite;
    quartz_viewport viewport;
    quartz_mat4 projection;
};

static quartz_renderer renderer;

static unsigned int quartz_render_push_new_texture(quartz_texture texture);

quartz_camera2D quartz_init_camera2D(int width, int height)
{
    quartz_camera2D camera = {};
    camera.width = width;
    camera.height = height;
    camera.zoom = 1.0f;
    return camera;
}

quartz_mat4 quartz_camera2D_get_projection(const quartz_camera2D* camera)
{
    return quartz_orth_proj(camera->x - camera->width / (2 * camera->zoom),
                            camera->x + camera->width / (2 * camera->zoom),
                            camera->y - camera->height / (2 * camera->zoom),
                            camera->y + camera->height / (2 * camera->zoom),
                            -1.0, 1.0);
}

quartz_vec2 quartz_camera2D_to_world_through_viewport(const quartz_camera2D* camera, quartz_ivec2 position, quartz_viewport viewport)
{
    position = quartz_viewport_clamp_point(viewport, position);

    float norm_x = (float)(position.x - viewport.get_x()) / viewport.get_width() - 0.5f;
    float norm_y = (float)(position.y - viewport.get_y()) / viewport.get_height() - 0.5f;

    float world_x = camera->x + norm_x * camera->width / camera->zoom;
    float world_y = camera->y + norm_y * camera->height / camera->zoom;

    return quartz_vec2 { world_x, world_y };
}

void quartz_render_init()
{
    #if 1 // Section: Shader
    static const char* vertex_shader =
        #include "builtin_shaders\2d.vs"
    ;

    static const char* frag_shader = 
        #include "builtin_shaders\2d.fs"
    ;

    renderer.shader = quartz_make_shader(vertex_shader, frag_shader);
    renderer.u_projection = glGetUniformLocation(renderer.shader, "u_projection");
    #endif

    renderer.batch_size = 0;

    #if 1 // Section: Texture Slots
    renderer.texture_slot_index = 0;

    GLuint u_textures = glGetUniformLocation(renderer.shader, "u_textures");
    int samplers [32];

    for(size_t i = 0; i < quartz_renderer::TEXTURE_SLOT_CAP; i++)
        samplers[i] = (int)i;
    
    quartz_use_shader(renderer.shader);
    glUniform1iv(u_textures, 32, samplers);
    #endif

    #if 1 // Section: OpenGL Attributes
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
    #endif

    // White pixel texture
    unsigned char quad_pixel [] = { 255, 255, 255, 255 };
    quartz_texture quad_texture = quartz_make_texture(1, 1, quad_pixel);
    renderer.quad_sprite = { quad_texture, {0,0}, {1, 1} };

    quartz_viewport screen_vp = quartz_get_screen_viewport();
    renderer.viewport = screen_vp;

    quartz_camera2D default_camera = quartz_init_camera2D(screen_vp.get_width(), screen_vp.get_height());
    renderer.projection = quartz_camera2D_get_projection(&default_camera);
}

void quartz_render_set_viewport(quartz_viewport viewport)
{
    renderer.viewport = viewport;
}

void quartz_render_set_camera(const quartz_camera2D* camera)
{
    renderer.projection = quartz_camera2D_get_projection(camera);
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
            quartz_render_flush();

        slot = renderer.texture_slot_index;

        quartz_bind_texture(texture, slot);
        
        renderer.texture_slots[renderer.texture_slot_index] = texture;
        renderer.texture_slot_index++;
    }

    return slot;
}

void quartz_render_texture(quartz_texture texture, quartz_vec2 pos, quartz_vec2 scale, float rotation, quartz_color tint)
{
    unsigned int slot = quartz_render_push_new_texture(texture);

    if(renderer.batch_size == renderer.BATCH_CAP)
        quartz_render_flush();

    quartz_instance_data instance = {
        pos, {0,0}, {1,1}, { texture.get_width() * scale.x, texture.get_height() * scale.y}, tint, rotation, (float)slot
    };

    renderer.instances[renderer.batch_size] = instance;
    renderer.batch_size++;
}

void quartz_render_sprite(quartz_sprite sprite, quartz_vec2 pos, quartz_vec2 scale, float rotation, quartz_color tint)
{
    unsigned int slot = quartz_render_push_new_texture(sprite.atlas);

    if(renderer.batch_size == renderer.BATCH_CAP)
        quartz_render_flush();

    quartz_vec2 uv_offset = {
        (float)sprite.offset.x / (float)sprite.atlas.get_width(),
        (float)sprite.offset.y / (float)sprite.atlas.get_height()
    };

    quartz_vec2 uv_size = {
        (float)sprite.size.x / (float)sprite.atlas.get_width(),
        (float)sprite.size.y / (float)sprite.atlas.get_height()
    };

    quartz_instance_data instance = {
        pos, uv_offset, uv_size, {(float)sprite.size.x * scale.x, (float)sprite.size.y * scale.y}, tint, rotation, (float)slot
    };

    renderer.instances[renderer.batch_size] = instance;
    renderer.batch_size++;
}

void quartz_render_quad(quartz_color color, quartz_vec2 pos, quartz_vec2 scale, float rotation)
{
    quartz_render_sprite(renderer.quad_sprite, pos, scale, rotation, color);
}

void quartz_render_flush()
{
    if(renderer.batch_size == 0) return;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_MULTISAMPLE);

    glViewport(renderer.viewport.get_x(), renderer.viewport.get_y(),
               renderer.viewport.get_width(), renderer.viewport.get_height());

    quartz_use_shader(renderer.shader);
    glUniformMatrix4fv(renderer.u_projection, 1, GL_FALSE, &renderer.projection.values[0][0]);

    glBindBuffer(GL_ARRAY_BUFFER, renderer.instances_buffer_id);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quartz_instance_data) * renderer.batch_size, renderer.instances);

    glBindVertexArray(renderer.va_id);
    glDrawElementsInstanced(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, 0, renderer.batch_size);

    renderer.batch_size = 0;
}