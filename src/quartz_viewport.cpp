#include <cmath>

#include "include/quartz_math.hpp"
#include "include/quartz_viewport.hpp"

quartz_viewport quartz_viewport_boxed(quartz_viewport container, int content_width, int content_height)
{
    float scale_x = (float)container.width / content_width;
    float scale_y = (float)container.height / content_height;

    quartz_viewport vp = container;

    if(content_width * scale_y <= container.width)
    {
        vp.width = content_width * scale_y;
        vp.x += (container.width - vp.width) / 2;
    }
    else
    {
        vp.height = content_height * scale_x;
        vp.y += (container.height - vp.height) / 2;
    }

    return vp;
}

quartz_ivec2 quartz_viewport_clamp_point(quartz_viewport container, quartz_ivec2 point)
{
    point.x = quartz_clamp(point.x, container.x, container.x + container.width);
    point.y = quartz_clamp(point.y, container.y, container.y + container.height);
    return point;
}