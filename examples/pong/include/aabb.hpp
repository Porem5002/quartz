#ifndef AABB_HEADER
#define AABB_HEADER

struct aabb
{
    float x, y;
    float hwidth, hheight;
};

bool aabb_is_colliding(aabb a, aabb b);

#endif