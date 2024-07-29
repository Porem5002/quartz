#ifndef GLLOAD_HEADER
#define GLLOAD_HEADER

#include "glinclude.hpp"

using any_func_ptr = void (*) ();

void load_gl_functions();
void load_wgl_functions();

bool try_load_gl_function_by_name(const char* func_name, any_func_ptr* out_gl_func);
any_func_ptr load_gl_function_by_name(const char* func_name);

#endif