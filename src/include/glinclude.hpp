#ifndef QUARTZ_GLINCLUDE_HEADER
#define QUARTZ_GLINCLUDE_HEADER

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#define GL_GLEXT_PROTOTYPES
#include <glcorearb.h>

#define WGL_WGLEXT_PROTOTYPES
#include <wglext.h>

#endif