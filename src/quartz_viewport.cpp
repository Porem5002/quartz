#include <cmath>

#include "include/quartz_math.hpp"
#include "include/quartz_viewport.hpp"

quartz_viewport_info quartz_viewport_calc_boxed(quartz_viewport container, int content_width, int content_height)
{ 
    quartz_viewport_info container_raw = container.get();

    float scale_x = (float)container_raw.width / content_width;
    float scale_y = (float)container_raw.height / content_height;

    quartz_viewport_info vp = container_raw;

    if(content_width * scale_y <= container_raw.width)
    {
        vp.width = content_width * scale_y;
        vp.x += (container_raw.width - vp.width) / 2;
    }
    else
    {
        vp.height = content_height * scale_x;
        vp.y += (container_raw.height - vp.height) / 2;
    }

    return vp;
}

quartz_ivec2 quartz_viewport_clamp_point(quartz_viewport container, quartz_ivec2 point)
{
    quartz_viewport_info container_raw = container.get();
    point.x = quartz_clamp(point.x, container_raw.x, container_raw.x + container_raw.width);
    point.y = quartz_clamp(point.y, container_raw.y, container_raw.y + container_raw.height);
    return point;
}