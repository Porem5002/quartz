R"(#version 400 core

layout (location = 0) in vec2 v_vertex;
layout (location = 1) in vec2 v_uvMult;

layout (location = 2) in float v_mode;
layout (location = 3) in vec2 v_position;
layout (location = 4) in vec2 v_uvOffset;
layout (location = 5) in vec2 v_uvSize;
layout (location = 6) in vec2 v_scale;
layout (location = 7) in vec4 v_color;
layout (location = 8) in float v_rotation;
layout (location = 9) in float v_textureIndex;

out float f_mode;
out vec2 f_innerCoords;
out vec4 f_color;
out float f_textureIndex;
out vec2 f_texturePos;

uniform mat3 u_projection;

void main()
{
    f_mode = v_mode;
    f_innerCoords = v_uvMult;
    f_color = v_color;

    f_textureIndex = v_textureIndex;
    f_texturePos = v_uvOffset + v_uvMult * v_uvSize;
    f_texturePos.y = 1 - f_texturePos.y;

    mat3 rot_mat = mat3(cos(v_rotation), -sin(v_rotation), 0.0,
                        sin(v_rotation), cos(v_rotation), 0.0,
                        0.0, 0.0, 1.0);

    vec3 final_pos = rot_mat * vec3(v_vertex * v_scale, 1.0) + vec3(v_position, 0.0);
    gl_Position = vec4(u_projection * final_pos, 1.0);
})"