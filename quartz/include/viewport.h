/*
MIT License

Copyright (c) 2024-2025 Carlos Bandeira

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

#include <stdlib.h>

#include "math.h"
#include "shapes.h"

QUARTZ_STRUCT_DEF(quartz_viewport)
{
    size_t id;
    
#ifdef QUARTZ_CPP
    void set_rect(quartz_rect rect);
    quartz_rect get_rect() const;

    int get_x() const { return get_rect().x; }
    int get_y() const { return get_rect().y; }
    int get_width() const { return get_rect().width; }
    int get_height() const { return get_rect().height; }

    bool operator ==(quartz_viewport other) const
    {
        return id == other.id;
    }

    bool operator !=(quartz_viewport other) const
    {
        return id != other.id;
    }
#endif
};

QUARTZ_DEF void quartz_viewport_set_rect(quartz_viewport vp, quartz_rect rect);
QUARTZ_DEF quartz_rect quartz_viewport_get_rect(quartz_viewport vp);

#ifdef QUARTZ_CPP
inline void quartz_viewport::set_rect(quartz_rect rect)
{
    quartz_viewport_set_rect(*this, rect);
}

inline quartz_rect quartz_viewport::get_rect() const
{
    return quartz_viewport_get_rect(*this);
}
#endif

#endif