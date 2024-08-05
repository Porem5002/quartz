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
    unsigned int u_mvp;

    unsigned int va_id;
    unsigned int vertex_buffer_id;
    unsigned int index_buffer_id;
    unsigned int instances_buffer_id;

    size_t batch_size;
    quartz_instance_data instances [BATCH_CAP];

    static constexpr size_t TEXTURE_SLOT_CAP = 32;

    size_t texture_slot_index;
    quartz_texture texture_slots [TEXTURE_SLOT_CAP];

    quartz_viewport viewport;
};

static quartz_renderer renderer;

static unsigned int quartz_render_push_new_texture(quartz_texture texture);

void quartz_camera2D_recalc(quartz_camera2D* camera)
{
    camera->projection = quartz_orth_proj(camera->x - camera->width / (2 * camera->zoom),
                                          camera->x + camera->width / (2 * camera->zoom),
                                          camera->y - camera->height / (2 * camera->zoom),
                                          camera->y + camera->height / (2 * camera->zoom),
                                          -1.0, 1.0);
}

quartz_vec2 quartz_viewport_to_world2D(quartz_camera2D camera, quartz_ivec2 position, quartz_viewport viewport)
{
    position = quartz_viewport_clamp_point(viewport, position); 

    float norm_x = (float)(position.x - viewport.get_x()) / viewport.get_width() - 0.5f;
    float norm_y = (float)(position.y - viewport.get_y()) / viewport.get_height() - 0.5f;

    float world_x = camera.x + norm_x * camera.width / camera.zoom;
    float world_y = camera.y + norm_y * camera.height / camera.zoom;

    return quartz_vec2 { world_x, world_y };
}

void quartz_render_init()
{
    #if 1 // Section: Shader
    static const char* vertex_shader = "#version 330 core\n"
                                    "layout (location = 0) in vec2 v_vertex;\n"
                                    "layout (location = 1) in vec2 v_uvMult;\n"
                                    "layout (location = 2) in vec2 v_position;\n"
                                    "layout (location = 3) in vec2 v_uvOffset;\n"
                                    "layout (location = 4) in vec2 v_uvSize;\n"
                                    "layout (location = 5) in vec2 v_scale;\n"
                                    "layout (location = 6) in vec4 v_color;\n"
                                    "layout (location = 7) in float v_rotation;\n"
                                    "layout (location = 8) in float v_textureIndex;\n"
                                    "out vec2 f_texturePos;\n"
                                    "out vec4 f_color;\n"
                                    "out float f_textureIndex;\n"
                                    "uniform mat4 u_mvp;\n"
                                    "void main()\n"
                                    "{\n"
                                        "f_texturePos = v_uvOffset + v_uvMult * v_uvSize;\n"
                                        "f_texturePos.y = 1 - f_texturePos.y;\n"
                                        "f_color = v_color;\n"
                                        "f_textureIndex = v_textureIndex;\n"

                                        "mat4 rot_mat = mat4(cos(v_rotation), -sin(v_rotation), 0, 0,"
                                                            "sin(v_rotation), cos(v_rotation), 0, 0,"
                                                            "0, 0, 1, 0,"
                                                            "0, 0, 0, 1);\n"

                                        "vec4 final_pos = rot_mat * vec4(v_vertex * v_scale, 0, 1) + vec4(v_position, 0, 0);\n"
                                        "gl_Position = u_mvp * final_pos;\n"
                                    "}\n";

    static const char* frag_shader = "#version 330 core\n"
                                    "in vec2 f_texturePos;\n"
                                    "in vec4 f_color;\n"
                                    "in float f_textureIndex;\n"
                                    "uniform sampler2D u_textures [32];\n"
                                    "out vec4 fragColor;\n"
                                    "void main()\n"
                                    "{\n"
                                        "fragColor = texture(u_textures[int(f_textureIndex)], f_texturePos) * f_color;\n"
                                    "}\n";

    renderer.shader = quartz_make_shader(vertex_shader, frag_shader);
    renderer.u_mvp = glGetUniformLocation(renderer.shader, "u_mvp");
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
}

void quartz_render_set_viewport(quartz_viewport viewport)
{
    renderer.viewport = viewport;
}

void quartz_render_set_camera(const quartz_camera2D* camera)
{
    quartz_use_shader(renderer.shader);
    glUniformMatrix4fv(renderer.u_mvp, 1, GL_FALSE, &camera->projection.values[0][0]);
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

void quartz_render_flush()
{
    if(renderer.batch_size == 0) return;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_MULTISAMPLE);

    glViewport(renderer.viewport.get_x(), renderer.viewport.get_y(),
               renderer.viewport.get_width(), renderer.viewport.get_height());

    quartz_use_shader(renderer.shader);

    glBindBuffer(GL_ARRAY_BUFFER, renderer.instances_buffer_id);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quartz_instance_data) * renderer.batch_size, renderer.instances);

    glBindVertexArray(renderer.va_id);
    glDrawElementsInstanced(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, 0, renderer.batch_size);

    renderer.batch_size = 0;
}