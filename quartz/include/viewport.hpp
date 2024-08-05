#ifndef QUARTZ_VIEWPORT_HEADER
#define QUARTZ_VIEWPORT_HEADER

#include <cstdlib>

#include "math.hpp"

struct quartz_viewport_info
{
    int x, y;
    int width, height;
};

struct quartz_viewport
{
    size_t id;
    
    void set(quartz_viewport_info val);
    quartz_viewport_info get() const;

    int get_x() const { return get().x; }
    int get_y() const { return get().y; }
    int get_width() const { return get().width; }
    int get_height() const { return get().height; }

    bool operator ==(quartz_viewport other) const
    {
        return id == other.id;
    }

    bool operator !=(quartz_viewport other) const
    {
        return id != other.id;
    }
};

quartz_viewport_info quartz_viewport_calc_boxed(quartz_viewport container, int content_width, int content_height);
quartz_ivec2 quartz_viewport_clamp_point(quartz_viewport container, quartz_ivec2 point);

#endif