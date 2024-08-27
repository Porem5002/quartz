#include <gapil.h>

#include "../include/gfx_info.hpp"

int quartz_gfx_get_texture_unit_cap()
{
    int value;
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &value);
    return value;
}