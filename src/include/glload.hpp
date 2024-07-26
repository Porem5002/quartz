#ifndef GLLOAD_HEADER
#define GLLOAD_HEADER

#include "glinclude.hpp"

using any_func_ptr = void (*) ();

void load_gl_functions();
any_func_ptr load_gl_function_by_name(const char* func_name);

#endif