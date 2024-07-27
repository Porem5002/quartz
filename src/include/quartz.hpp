#ifndef QUARTZ_ENGINE_HEADER
#define QUARTZ_ENGINE_HEADER

#include <cstdlib>
#include <cstdint>

#include "glinclude.hpp"
#include "quartz_common.hpp"

void quartz_start(int width, int height, const char* title);
void quartz_update_events();
void quartz_swap_buffers();

bool quartz_is_running();
quartz_uvec2 quartz_get_screen_size();
quartz_uvec2 quartz_get_mouse_pos();

quartz_shader quartz_make_shader(const char* vs_code, const char* fs_code, bool use_now);
void quartz_use_shader(quartz_shader shader);

quartz_texture quartz_load_texture(const char* path);
void quartz_bind_texture(quartz_texture texture, unsigned int slot);

GLuint quartz_shader_from_source(GLenum shader_type, const char* shader_src);
GLuint quartz_program_from_shaders(GLuint vs_id, GLuint fs_id, bool use_program_now);
void quartz_compile_shader(GLuint shader_id);

#endif

