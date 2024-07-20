#ifndef QUARTZ_MATH_HEADER
#define QUARTZ_MATH_HEADER

#include <cstdlib>

template<size_t Cols, size_t Rows>
struct quartz_mat
{
    float values [Cols][Rows];
};

using quartz_mat4 = quartz_mat<4, 4>;

quartz_mat4 quartz_orth_proj(float left, float right, float bottom, float top, float near, float far);

#endif