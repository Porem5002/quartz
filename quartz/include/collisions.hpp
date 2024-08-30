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

#ifndef QUARTZ_SHAPES_HEADER
#define QUARTZ_SHAPES_HEADER

#include "math.hpp"

struct quartz_aabb2
{
    float x, y;
    float hwidth, hheight;
};

struct quartz_swept_info
{
    bool collided;
    float t;
    quartz_vec2 normal;
};
 
bool quartz_aabb2_touches_point(quartz_vec2 p, quartz_aabb2 b);
bool quartz_aabb2_touches_aabb2(quartz_aabb2 a, quartz_aabb2 b);

quartz_swept_info quartz_aabb2_swept_point(quartz_vec2 p, quartz_vec2 vp, quartz_aabb2 b, quartz_vec2 vb = {0.0,0.0});
quartz_swept_info quartz_aabb2_swept_aabb2(quartz_aabb2 a, quartz_vec2 va, quartz_aabb2 b, quartz_vec2 vb = {0.0,0.0});

#endif