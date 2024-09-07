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

#include <vector>
#include <string>
#include <sstream>

#include <gapil.h>
#include <stb_image.h>

#include "..\include\resources.h"
#include "..\include\common.h"
#include "..\include\gfx_info.h"

struct quartz_resources
{
    std::string shader_defines;

    std::vector<quartz_texture_info> textures;
    std::vector<quartz_shader_info> shaders;
};

static quartz_resources resources_context;

static unsigned int quartz_partial_shader_from_source(unsigned int shader_type, const char* shader_src);
static unsigned int quartz_shader_from_partial_shaders(unsigned int vs_id, unsigned int fs_id);

void quartz_resources_init()
{
    // Setup defines for shaders so that they take into consideration the platforms capabilities
    std::stringstream s;
    s << "\n#define QUARTZ_TEXTURE_UNIT_CAP " << quartz_gfx_get_texture_unit_cap() << "\n";
    resources_context.shader_defines = s.str();
}

quartz_shader quartz_load_shader(const char* vs_path, const char* fs_path)
{
    return {};
}

quartz_shader quartz_make_shader(const char* vs_code, const char* fs_code)
{
    unsigned int vs_id = quartz_partial_shader_from_source(GL_VERTEX_SHADER, vs_code);
    unsigned int fs_id = quartz_partial_shader_from_source(GL_FRAGMENT_SHADER, fs_code);
    unsigned int prog_id = quartz_shader_from_partial_shaders(vs_id, fs_id);
    glValidateProgram(prog_id);
    
    quartz_shader_info shader_info = {};
    shader_info.program_id = prog_id;
    shader_info.vs_id = vs_id;
    shader_info.fs_id = fs_id;

    size_t id = resources_context.shaders.size();
    resources_context.shaders.push_back(shader_info);
    return { id };
}

void quartz_use_shader(quartz_shader shader)
{
    glUseProgram(shader.get_program_id());
}

quartz_shader_info quartz_shader_get_info(quartz_shader shader)
{
    return resources_context.shaders[shader.id];
}

quartz_shader_info quartz_shader::get() const
{
    return quartz_shader_get_info(*this);
}

quartz_texture quartz_load_texture(const char* path)
{
    int w, h, channels;
    unsigned char* data = stbi_load(path, &w, &h, &channels, 4);
    QUARTZ_ASSERT(data != nullptr, "Could not load texture from the path");
    
    quartz_texture texture = quartz_make_texture(w, h, data);
    stbi_image_free(data);

    return texture;
}

quartz_texture quartz_make_texture(int width, int height, unsigned char* data)
{
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);

    quartz_texture_info texture_info;
    texture_info.glid = id;
    texture_info.width = width;
    texture_info.height = height;
    texture_info.channels = 4;

    quartz_texture texture = { resources_context.textures.size() };
    resources_context.textures.push_back(texture_info);
    return texture;
}

void quartz_bind_texture(quartz_texture texture, unsigned int slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texture.get_glid());
}

quartz_texture_info quartz_texture_get_info(quartz_texture texture)
{
    return resources_context.textures[texture.id];
}

quartz_texture_info quartz_texture::get() const
{
    return quartz_texture_get_info(*this);
}

static unsigned int quartz_partial_shader_from_source(unsigned int type, const char* code)
{
    const char* usage_symbol = "QUARTZ_USE_DEFINES";
    std::string src_with_defines = code;

    // Inserts quartz specific macros into shader if QUARTZ_USE_DEFINES exists, replacing it with the defines
    size_t replacement_index = src_with_defines.find(usage_symbol);
    if(replacement_index != std::string::npos)
        src_with_defines.replace(replacement_index, strlen(usage_symbol), resources_context.shader_defines);

    const char* final_shader_src = src_with_defines.c_str();
 
    GLuint id = glCreateShader(type);
    glShaderSource(id, 1, &final_shader_src, nullptr);
    glCompileShader(id);

    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    if(success == GL_FALSE)
    {
        int log_length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &log_length);

        char* log_msg = new char[log_length + 1];
        glGetShaderInfoLog(id, log_length, 0, log_msg);
        QUARTZ_ASSERT(false, log_msg);
        delete[] log_msg;
    }

    return id;
}

static unsigned int quartz_shader_from_partial_shaders(unsigned int vs_id, unsigned int fs_id)
{
    unsigned int id = glCreateProgram();
    glAttachShader(id, vs_id);
    glAttachShader(id, fs_id);
    glLinkProgram(id);

    int success;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    
    if(success == GL_FALSE)
    {
        int log_length;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &log_length);

        char* log_msg = new char[log_length + 1];
        glGetProgramInfoLog(id, log_length, &log_length, log_msg);
        QUARTZ_ASSERT(false, log_msg);
        delete[] log_msg;
    }

    return id;
}