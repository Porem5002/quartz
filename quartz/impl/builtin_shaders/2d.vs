R"(#version 400 core

layout (location = 0) in vec2 v_vertex;
layout (location = 1) in vec2 v_uvMult;
layout (location = 2) in vec2 v_position;
layout (location = 3) in vec2 v_uvOffset;
layout (location = 4) in vec2 v_uvSize;
layout (location = 5) in vec2 v_scale;
layout (location = 6) in vec4 v_color;
layout (location = 7) in float v_rotation;
layout (location = 8) in float v_textureIndex;

out vec2 f_texturePos;
out vec4 f_color;
out float f_textureIndex;

uniform mat4 u_projection;

void main()
{
    f_texturePos = v_uvOffset + v_uvMult * v_uvSize;
    f_texturePos.y = 1 - f_texturePos.y;
    f_color = v_color;
    f_textureIndex = v_textureIndex;

    mat4 rot_mat = mat4(cos(v_rotation), -sin(v_rotation), 0.0, 0.0,
                        sin(v_rotation), cos(v_rotation), 0.0, 0.0,
                        0.0, 0.0, 1.0, 0.0,
                        0.0, 0.0, 0.0, 1.0);

    vec4 final_pos = rot_mat * vec4(v_vertex * v_scale + v_position, 0.0, 1.0);
    gl_Position = u_projection * final_pos;
})"