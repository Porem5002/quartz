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

#include "../include/math.h"

quartz_mat3 quartz_orth2d_projection(float left, float right, float bottom, float top)
{
    quartz_mat3 m = {};

    m.values[2][0] = -(right + left) / (right - left);
    m.values[2][1] = -(top + bottom) / (top - bottom);
    
    m.values[0][0] = 2 / (right - left);
    m.values[1][1] = 2 / (top - bottom);
    m.values[2][2] = 1.0f;

    return m;
}

quartz_mat4 quartz_orth3d_projection(float left, float right, float bottom, float top, float near_, float far_)
{
    quartz_mat4 m = {};

    m.values[3][0] = -(right + left) / (right - left);
    m.values[3][1] = -(top + bottom) / (top - bottom);
    m.values[3][2] = -(far_ + near_) / (far_ - near_);

    m.values[0][0] = 2 / (right - left);
    m.values[1][1] = 2 / (top - bottom);
    m.values[2][2] = 2 / (far_ - near_);
    m.values[3][3] = 1.0f;

    return m;
}