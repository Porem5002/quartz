#ifndef QUARTZ_ENGINE_HEADER
#define QUARTZ_ENGINE_HEADER

#include <cstdlib>
#include <cstdint>

#include "common.hpp"
#include "viewport.hpp"

void quartz_start(int width, int height, const char* title);
bool quartz_update();
void quartz_set_vsync(bool active);

bool quartz_is_running();
float quartz_get_delta_time();

bool quartz_was_screen_resized();
quartz_ivec2 quartz_get_screen_size();
quartz_viewport quartz_get_screen_viewport();
quartz_ivec2 quartz_get_mouse_pos();

quartz_shader quartz_make_shader(const char* vs_code, const char* fs_code);
void quartz_use_shader(quartz_shader shader);

quartz_texture quartz_load_texture(const char* path);
quartz_texture quartz_make_texture(int width, int height, unsigned char* data);
void quartz_bind_texture(quartz_texture texture, unsigned int slot);

quartz_viewport quartz_make_viewport(quartz_viewport_info init);

unsigned int quartz_shader_from_source(unsigned int shader_type, const char* shader_src);
unsigned int quartz_program_from_shaders(unsigned int vs_id, unsigned int fs_id);
void quartz_compile_shader(unsigned int shader_id);

void quartz_clear(quartz_color color);

#endif