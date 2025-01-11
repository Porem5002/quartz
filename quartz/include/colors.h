/*
MIT License

Copyright (c) 2024-2025 Carlos Bandeira

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

#ifndef QUARTZ_COLORS_HEADER
#define QUARTZ_COLORS_HEADER

#include "api_compat.h"

QUARTZ_STRUCT_DEF(quartz_color)
{
    float r, g, b, a;
};

#ifdef QUARTZ_CPP

constexpr quartz_color QUARTZ_TRANSPARENT = { 0.0f, 0.0f, 0.0f, 0.0f };
constexpr quartz_color QUARTZ_BLACK = { 0.0f, 0.0f, 0.0f, 1.0f };
constexpr quartz_color QUARTZ_WHITE = { 1.0f, 1.0f, 1.0f, 1.0f };

constexpr quartz_color QUARTZ_RED = { 1.0f, 0.0f, 0.0f, 1.0f };
constexpr quartz_color QUARTZ_GREEN = { 0.0f, 1.0f, 0.0f, 1.0f };
constexpr quartz_color QUARTZ_BLUE = { 0.0f, 0.0f, 1.0f, 1.0f };

#else

#define QUARTZ_TRANSPARENT ((quartz_color) { 0.0f, 0.0f, 0.0f, 0.0f })
#define QUARTZ_BLACK ((quartz_color) { 0.0f, 0.0f, 0.0f, 1.0f })
#define QUARTZ_WHITE ((quartz_color) { 1.0f, 1.0f, 1.0f, 1.0f })

#define QUARTZ_RED ((quartz_color) { 1.0f, 0.0f, 0.0f, 1.0f })
#define QUARTZ_GREEN ((quartz_color) { 0.0f, 1.0f, 0.0f, 1.0f })
#define QUARTZ_BLUE ((quartz_color) { 0.0f, 0.0f, 1.0f, 1.0f })

#endif

#endif