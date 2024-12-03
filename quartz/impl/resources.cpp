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

#include <ft2build.h>
#include FT_FREETYPE_H

#include "..\include\resources.h"
#include "..\include\common.h"
#include "..\include\gfx_info.h"

struct quartz_font_info
{
    FT_Face font;
    std::vector<quartz_glyph_info> cached_glyphs;
};

struct quartz_resources
{
    FT_Library ft_library;

    std::string shader_defines;

    std::vector<quartz_texture_info> textures;
    std::vector<quartz_font_info> fonts;
    std::vector<quartz_shader_info> shaders;
};

static quartz_resources resources_context;

static unsigned int quartz_partial_shader_from_source(unsigned int shader_type, const char* shader_src);
static unsigned int quartz_shader_from_partial_shaders(unsigned int vs_id, unsigned int fs_id);
static char* quartz_read_file(const char* path);

void quartz_resources_init()
{
    if(FT_Init_FreeType(&resources_context.ft_library) != FT_Err_Ok)
        QUARTZ_ASSERT(false, "Could not initialize FreeType!");

    // Setup defines for shaders so that they take into consideration the platforms capabilities
    std::stringstream s;
    s << "\n#define QUARTZ_TEXTURE_UNIT_CAP " << quartz_gfx_get_texture_unit_cap() << "\n";
    resources_context.shader_defines = s.str();
}

void quartz_resources_finish()
{
    FT_Done_FreeType(resources_context.ft_library);
}

quartz_shader quartz_load_shader(const char* vs_path, const char* fs_path)
{
    char* vs_code = quartz_read_file(vs_path);
    QUARTZ_ASSERT(vs_code != NULL, "Could not load vertex shader file");

    char* fs_code = quartz_read_file(fs_path);
    QUARTZ_ASSERT(fs_code != NULL, "Could not load fragment shader file");

    quartz_shader shader = quartz_make_shader(vs_code, fs_code);
    delete [] vs_code;
    delete [] fs_code;
    return shader;
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

quartz_font quartz_load_font(const char* font_path)
{
    FT_Face font;
    if(FT_New_Face(resources_context.ft_library, font_path, 0, &font) != FT_Err_Ok)
        QUARTZ_ASSERT(false, "Could not initialize font!");

    quartz_font_info font_info = {};
    font_info.font = font;

    size_t id = resources_context.fonts.size();
    resources_context.fonts.push_back(font_info);
    return { id };
}

quartz_vec2 quartz_font_get_text_size(quartz_font font, float font_size, const char* text)
{
    const quartz_font_info& font_info = resources_context.fonts[font.id];

    float scale = font_size / QUARTZ_BASE_FONT_SIZE;
    float height = quartz_font_get_ascender(font) * scale;
    float width = 0;

    size_t text_len = strlen(text);

    for(size_t i = 0; i < text_len; i++)
    {
        quartz_glyph_info glyph = quartz_font_get_glyph_info(font, text[i]);
        width += glyph.advance_x * scale;
    }

    return { width, height };
}

float quartz_font_get_ascender(quartz_font font)
{
    quartz_font_info& font_info = resources_context.fonts[font.id];
    return font_info.font->size->metrics.ascender >> 6;
}

float quartz_font_get_descender(quartz_font font)
{
    quartz_font_info& font_info = resources_context.fonts[font.id];
    return font_info.font->size->metrics.descender >> 6;
}

quartz_glyph_info quartz_font_get_glyph_info(quartz_font font, unsigned long codepoint)
{
    quartz_font_info& font_info = resources_context.fonts[font.id];

    auto glyph = std::find_if(font_info.cached_glyphs.begin(), 
                              font_info.cached_glyphs.end(),
                              [=](const auto& glyph) {
                                  return glyph.codepoint == codepoint;
                              });

    if(glyph == font_info.cached_glyphs.end())
    {
        FT_Face& face = font_info.font;

        FT_Set_Pixel_Sizes(face, 0, QUARTZ_BASE_FONT_SIZE);
        FT_Set_Char_Size(face, 0, QUARTZ_BASE_FONT_SIZE << 6, 72, 72);

        if(FT_Load_Char(face, codepoint, FT_LOAD_DEFAULT) != FT_Err_Ok)
            QUARTZ_ASSERT(false, "Could not load char from font!");

        if(FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL))
            QUARTZ_ASSERT(false, "Could not render glyph!");

        FT_Bitmap bitmap = face->glyph->bitmap;
        int width = bitmap.width;
        int height = bitmap.rows;
        unsigned char* buffer = bitmap.buffer;

        unsigned char* rgba_buffer = new unsigned char[width * height * 4];

        for(int i = 0, j = 0; i < width * height; i++, j+=4)
        {
            rgba_buffer[j] = 255;
            rgba_buffer[j+1] = 255;
            rgba_buffer[j+2] = 255;
            rgba_buffer[j+3] = buffer[i];
        }

        auto glyph_metrics = face->glyph->metrics;
        quartz_texture char_texture = quartz_make_texture(width, height, rgba_buffer);

        quartz_glyph_info char_glyph = {};
        char_glyph.codepoint = codepoint;
        
        // Metrics
        char_glyph.advance_x = glyph_metrics.horiAdvance >> 6;
        char_glyph.bearing_y = glyph_metrics.horiBearingY >> 6;

        // Sprite
        char_glyph.sprite.atlas = char_texture;
        char_glyph.sprite.offset = { 0, 0 };
        char_glyph.sprite.size = { (unsigned int)width, (unsigned int)height };
        
        delete[] rgba_buffer;

        font_info.cached_glyphs.push_back(char_glyph);
        return char_glyph;
    }

    return *glyph;
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

static char* quartz_read_file(const char* path)
{
    FILE* file = fopen(path, "r");
    if(file == NULL) return NULL;

    size_t size;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* data = new char[size + 1];

    // size is reassigned because text length might not be equal to byte count because of characters like '\r'
    // and the fact that they are removed when the file is in text mode
    size = fread(data, 1, size, file);

    data[size] = '\0';

    fclose(file);

    return data;
}