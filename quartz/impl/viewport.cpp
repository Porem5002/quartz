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

#include <cmath>

#include "../include/math.hpp"
#include "../include/viewport.hpp"

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