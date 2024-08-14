#include <utility>

#include "../include/collisions.hpp"

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