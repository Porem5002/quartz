#ifndef QUARTZ_ENGINE_HEADER
#define QUARTZ_ENGINE_HEADER

#include <cstdlib>
#include <cstdint>

#include "glinclude.hpp"
#include "quartz_common.hpp"
#include "quartz_viewport.hpp"

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
void quartz_bind_texture(quartz_texture texture, unsigned int slot);

quartz_viewport quartz_make_viewport(quartz_viewport_info init);

GLuint quartz_shader_from_source(GLenum shader_type, const char* shader_src);
GLuint quartz_program_from_shaders(GLuint vs_id, GLuint fs_id);
void quartz_compile_shader(GLuint shader_id);

void quartz_clear(quartz_color color);

#endif

