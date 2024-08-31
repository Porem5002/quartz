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

#include <cstdlib>

#include "../include/shapes.h"

quartz_rect quartz_rect_calc_boxed(quartz_rect rect, float content_ratio)
{
    float rect_ratio = (float)rect.width / rect.height;

    quartz_rect boxed_rect = rect;

    if(rect_ratio >= content_ratio)
    {
        boxed_rect.width = boxed_rect.height * content_ratio;
        boxed_rect.x += (rect.width - boxed_rect.width) / 2;
    }
    else
    {
        boxed_rect.height = boxed_rect.width * 1.0f / content_ratio;
        boxed_rect.y += (rect.height - boxed_rect.height) / 2;
    }

    return boxed_rect;
}

quartz_ivec2 quartz_rect_clamp_point(quartz_rect rect, quartz_ivec2 point)
{
    point.x = quartz_clamp(point.x, rect.x, rect.x + rect.width);
    point.y = quartz_clamp(point.y, rect.y, rect.y + rect.height);
    return point;
}

bool quartz_aabb2_touches_point(quartz_vec2 p, quartz_aabb2 b)
{
    return fabs(p.x - b.x) <= b.hwidth &&
           fabs(p.y - b.y) <= b.hheight;
}

bool quartz_aabb2_touches_aabb2(quartz_aabb2 a, quartz_aabb2 b)
{
    return fabs(a.x - b.x) <= a.hwidth + b.hwidth &&
           fabs(a.y - b.y) <= a.hheight + b.hheight;
}

quartz_swept_info quartz_aabb2_swept_point(quartz_vec2 p, quartz_vec2 vp, quartz_aabb2 b, quartz_vec2 vb)
{
    constexpr quartz_swept_info NO_COLLISION_INFO = { false, 1.0f, { 0.0f, 0.0f } };

    quartz_vec2 v = vp;
    v.x -= vb.x;
    v.y -= vb.y;

    float nearx = (b.x - b.hwidth - p.x) / v.x;
    float neary = (b.y - b.hheight - p.y) / v.y;

    if(isnan(nearx) || isnan(neary)) return NO_COLLISION_INFO;

    float farx = (b.x + b.hwidth - p.x) / v.x;
    float fary = (b.y + b.hheight - p.y) / v.y;

    if(isnan(farx) || isnan(fary)) return NO_COLLISION_INFO;

    if(nearx > farx)
    {
        float tmp = nearx;
        nearx = farx;
        farx = tmp;
    }

    if(neary > fary)
    {
        float tmp = neary;
        neary = fary;
        fary = tmp;
    }

    if(nearx >= fary || neary >= farx) return NO_COLLISION_INFO;

    float t = nearx > neary ? nearx : neary;
    if(t >= 1.0f || t < 0.0f) return NO_COLLISION_INFO;

    quartz_swept_info info = {};
    info.collided = true;
    info.t = t;

    if(nearx > neary)
        info.normal = quartz_vec2 { v.x < 0.0f ? 1.0f : -1.0f, 0.0f };
    else
        info.normal = quartz_vec2 { 0.0f, v.y < 0.0f ? 1.0f : -1.0f };

    return info;
}

quartz_swept_info quartz_aabb2_swept_aabb2(quartz_aabb2 a, quartz_vec2 va, quartz_aabb2 b, quartz_vec2 vb)
{
    quartz_vec2 p = { a.x, a.y };

    quartz_aabb2 expanded = b;
    expanded.hwidth += a.hwidth;
    expanded.hheight += a.hheight;

    return quartz_aabb2_swept_point(p, va, expanded, vb);
}