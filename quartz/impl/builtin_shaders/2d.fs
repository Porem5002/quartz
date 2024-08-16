R"(#version 400 core

in vec2 f_texturePos;
in vec4 f_color;
in float f_textureIndex;

uniform sampler2D u_textures [32];

out vec4 fragColor;

void main()
{
    fragColor = texture(u_textures[int(f_textureIndex)], f_texturePos) * f_color;
})"