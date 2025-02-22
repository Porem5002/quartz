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

// Windows Dependencies
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "gdi32.lib")

#include "impl/notify.cpp"
#include "impl/base.cpp"
#include "impl/math.cpp"
#include "impl/resources.cpp"
#include "impl/gfx_info.cpp"
#include "impl/render2D.cpp"
#include "impl/window.cpp"
#include "impl/input.cpp"
#include "impl/shapes.cpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define GAPIL_IMPLEMENTATION
#include <gapil.h>