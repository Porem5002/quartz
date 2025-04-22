R"(#version 400 core

QUARTZ_USE_DEFINES

in float f_mode;
in vec2 f_innerCoords;
in vec4 f_color;
in float f_textureIndex;
in vec2 f_texturePos;

uniform int u_textureCount;
uniform sampler2D u_textures [QUARTZ_TEXTURE_UNIT_CAP];

out vec4 fragColor;

const float MODE_QUAD = 0.0;
const float MODE_CIRCLE = 1.0;
const float MODE_SDF = 2.0;

void main()
{
    int index = int(f_textureIndex);
    fragColor = vec4(0);

    // Workaround to avoid undefined behaviour when indexing sampler2D[] with non dynamically uniform expression
    for(int i = 0; i < u_textureCount; i++)
    {
        vec4 color = texture(u_textures[i], f_texturePos);
        fragColor += color * float(i == index);
    }

    fragColor *= f_color;

    if(f_mode == MODE_CIRCLE)
    {
        float d = 1.0 - 2.0 * length(f_innerCoords - 0.5);
        // fwidth is used to calculate a better fade value for the specific circle size
        float fade = fwidth(d);
        float t = smoothstep(0.0, fade, d);
        fragColor.a *= t;
    }
    else if(f_mode == MODE_SDF)
    {
        float d = fragColor.a / f_color.a;
        float fade = fwidth(d);
        float t = smoothstep(0.5 - fade, 0.5 + fade, d);
        fragColor.a = t * f_color.a;
    }
})"