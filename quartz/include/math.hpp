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

#ifndef QUARTZ_MATH_HEADER
#define QUARTZ_MATH_HEADER

#include <cstdlib>

struct quartz_ivec2
{
    int x, y;
};

struct quartz_uvec2
{
    unsigned int x, y;
};

struct quartz_vec2
{
    float x, y;
};

template<size_t Cols, size_t Rows>
struct quartz_mat
{
    float values [Cols][Rows];
};

using quartz_mat3 = quartz_mat<3, 3>;
using quartz_mat4 = quartz_mat<4, 4>;

template<typename TNumber>
TNumber quartz_clamp(TNumber v, TNumber min, TNumber max)
{
    if(v > max) return max;
    if(v < min) return min;
    return v;
}

quartz_mat3 quartz_orth2d_projection(float left, float right, float bottom, float top);
quartz_mat4 quartz_orth3d_projection(float left, float right, float bottom, float top, float near_, float far_);

#endif