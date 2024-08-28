R"(#version 400 core

QUARTZ_USE_DEFINES

in float f_mode;
in vec2 f_innerCoords;
in vec4 f_color;
in float f_textureIndex;
in vec2 f_texturePos;

uniform sampler2D u_textures [QUARTZ_TEXTURE_UNIT_CAP];

out vec4 fragColor;

const float MODE_QUAD = 0.0;
const float MODE_CIRCLE = 1.0;

// TODO: Calculate fade based on the on screen size of the circle to make it even smoother overall
// Recommended values:
//    big circles -> 0.01
//    small circles -> 0.1 
const float CIRCLE_FADE = 0.01;

void main()
{
    fragColor = texture(u_textures[int(f_textureIndex)], f_texturePos) * f_color;

    if(f_mode == MODE_CIRCLE)
    {
        float d = 1.0 - 2.0 * length(f_innerCoords - 0.5);
        float t = smoothstep(0.0, CIRCLE_FADE, d);
        fragColor.a *= t;
    }
})"