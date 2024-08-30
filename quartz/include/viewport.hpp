/*
MIT License

Copyright (c) 2024 Carlos Bandeira

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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