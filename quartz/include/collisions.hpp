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