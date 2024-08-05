#include "include/aabb.hpp"

bool aabb_is_colliding(aabb a, aabb b)
{
    float dist_x = a.x - b.x;
    float dist_y = a.y - b.y;

    if(dist_x < 0) dist_x = -dist_x;
    if(dist_y < 0) dist_y = -dist_y;

    return dist_x <= a.hwidth + b.hwidth &&
           dist_y <= a.hheight + b.hheight;
}