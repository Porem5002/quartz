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

#ifndef QUARTZ_API_COMPAT_HEADER
#define QUARTZ_API_COMPAT_HEADER

#ifdef __cplusplus
#define QUARTZ_CPP
#define QUARTZ_DEF_LINKAGE extern "C"
#define QUARTZ_CPP_ONLY(...) __VA_ARGS__

#define QUARTZ_ENUM_DEF(NAME, TYPE) enum NAME : TYPE

#define QUARTZ_STRUCT_LIT(TYPE, ...) (TYPE __VA_ARGS__)
#define QUARTZ_STRUCT_LIT_ZERO(TYPE) (TYPE {})

#else
#define QUARTZ_C
#define QUARTZ_DEF_LINKAGE extern
#define QUARTZ_CPP_ONLY(...)

#include <stdbool.h>

#define QUARTZ_ENUM_DEF(NAME, TYPE) typedef TYPE NAME; enum

#define QUARTZ_STRUCT_LIT(TYPE, ...) ((TYPE) __VA_ARGS__) 
#define QUARTZ_STRUCT_LIT_ZERO(TYPE) ((TYPE) {0}) 

#endif

#ifdef _WIN32
    #ifdef QUARTZ_DYNAMIC_LIB_EXPORT
        #define QUARTZ_DEF QUARTZ_DEF_LINKAGE __declspec(dllexport)
    #elif defined(QUARTZ_DYNAMIC_LIB_IMPORT)
        #define QUARTZ_DEF QUARTZ_DEF_LINKAGE __declspec(dllimport)
    #else
        #define QUARTZ_DEF QUARTZ_DEF_LINKAGE
    #endif
#else
    #error "QUARTZ_DEF not defined for this platform"
#endif

#define QUARTZ_STRUCT_DEF(NAME) typedef struct NAME NAME; struct NAME

#endif