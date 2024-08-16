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