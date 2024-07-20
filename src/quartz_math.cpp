#include "include/quartz_math.hpp"

quartz_mat4 quartz_orth_proj(float left, float right, float bottom, float top, float near_, float far_)
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