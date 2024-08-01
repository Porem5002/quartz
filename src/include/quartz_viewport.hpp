#ifndef QUARTZ_VIEWPORT_HEADER
#define QUARTZ_VIEWPORT_HEADER

struct quartz_viewport
{
    int x, y;
    int width, height;
};

quartz_viewport quartz_viewport_boxed(quartz_viewport container, int content_width, int content_height);
quartz_ivec2 quartz_viewport_clamp_point(quartz_viewport container, quartz_ivec2 point);

#endif