#include "include/quartz.hpp"
#include "include/glload.hpp"

static PFNGLCREATEPROGRAMPROC glCreateProgram_ptr;
static PFNGLDELETETEXTURESPROC glDeleteTextures_ptr;
static PFNGLGENTEXTURESPROC glGenTextures_ptr;
static PFNGLBINDTEXTUREPROC glBindTexture_ptr;
static PFNGLBINDTEXTUREUNITPROC glBindTextureUnit_ptr;
static PFNGLDRAWBUFFERPROC glDrawBuffer_ptr;
static PFNGLDRAWARRAYSPROC glDrawArrays_ptr;
static PFNGLCREATESHADERPROC glCreateShader_ptr;
static PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation_ptr;
static PFNGLUNIFORM1FPROC glUniform1f_ptr;
static PFNGLUNIFORM2FVPROC glUniform2fv_ptr;
static PFNGLUNIFORM3FVPROC glUniform3fv_ptr;
static PFNGLUNIFORM4FVPROC glUniform4fv_ptr;
static PFNGLUNIFORM1IPROC glUniform1i_ptr;
static PFNGLUNIFORM1IVPROC glUniform1iv_ptr;
static PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv_ptr;
static PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor_ptr;
static PFNGLACTIVETEXTUREPROC glActiveTexture_ptr;
static PFNGLBUFFERSUBDATAPROC glBufferSubData_ptr;
static PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced_ptr;
static PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer_ptr;
static PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus_ptr;
static PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers_ptr;
static PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D_ptr;
static PFNGLDRAWBUFFERSPROC glDrawBuffers_ptr;
static PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers_ptr;
static PFNGLBLENDFUNCIPROC glBlendFunci_ptr;
static PFNGLBLENDEQUATIONPROC glBlendEquation_ptr;
static PFNGLCLEARBUFFERFVPROC glClearBufferfv_ptr;
static PFNGLSHADERSOURCEPROC glShaderSource_ptr;
static PFNGLCOMPILESHADERPROC glCompileShader_ptr;
static PFNGLGETSHADERIVPROC glGetShaderiv_ptr;
static PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog_ptr;
static PFNGLATTACHSHADERPROC glAttachShader_ptr;
static PFNGLLINKPROGRAMPROC glLinkProgram_ptr;
static PFNGLVALIDATEPROGRAMPROC glValidateProgram_ptr;
static PFNGLGETPROGRAMIVPROC glGetProgramiv_ptr;
static PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog_ptr;
static PFNGLGENBUFFERSPROC glGenBuffers_ptr;
static PFNGLGENVERTEXARRAYSPROC glGenVertexArrays_ptr;
static PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation_ptr;
static PFNGLBINDVERTEXARRAYPROC glBindVertexArray_ptr;
static PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray_ptr;
static PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer_ptr;
static PFNGLBINDBUFFERPROC glBindBuffer_ptr;
static PFNGLBINDBUFFERBASEPROC glBindBufferBase_ptr;
static PFNGLBUFFERDATAPROC glBufferData_ptr;
static PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv_ptr;
static PFNGLUSEPROGRAMPROC glUseProgram_ptr;
static PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays_ptr;
static PFNGLDELETEBUFFERSPROC glDeleteBuffers_ptr;
static PFNGLDELETEPROGRAMPROC glDeleteProgram_ptr;
static PFNGLDETACHSHADERPROC glDetachShader_ptr;
static PFNGLDELETESHADERPROC glDeleteShader_ptr;
static PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced_ptr;
static PFNGLGENERATEMIPMAPPROC glGenerateMipmap_ptr;
static PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback_ptr;
static PFNGLGETINTEGERVPROC glGetIntegerv_ptr;

void load_gl_functions()
{
    glCreateProgram_ptr = (PFNGLCREATEPROGRAMPROC)load_gl_function_by_name("glCreateProgram");
    glDeleteTextures_ptr = (PFNGLDELETETEXTURESPROC)load_gl_function_by_name("glDeleteTextures");
    glGenTextures_ptr = (PFNGLGENTEXTURESPROC)load_gl_function_by_name("glGenTextures");
    glBindTexture_ptr = (PFNGLBINDTEXTUREPROC)load_gl_function_by_name("glBindTexture");
    glBindTextureUnit_ptr = (PFNGLBINDTEXTUREUNITPROC)load_gl_function_by_name("glBindTextureUnit");
    glDrawArrays_ptr = (PFNGLDRAWARRAYSPROC)load_gl_function_by_name("glDrawArrays");
    glCreateShader_ptr = (PFNGLCREATESHADERPROC) load_gl_function_by_name("glCreateShader");
    glGetUniformLocation_ptr = (PFNGLGETUNIFORMLOCATIONPROC) load_gl_function_by_name("glGetUniformLocation");
    glUniform1f_ptr = (PFNGLUNIFORM1FPROC) load_gl_function_by_name("glUniform1f");
    glUniform2fv_ptr = (PFNGLUNIFORM2FVPROC) load_gl_function_by_name("glUniform2fv");
    glUniform3fv_ptr = (PFNGLUNIFORM3FVPROC) load_gl_function_by_name("glUniform3fv");
    glUniform4fv_ptr = (PFNGLUNIFORM4FVPROC) load_gl_function_by_name("glUniform4fv");
    glUniform1i_ptr = (PFNGLUNIFORM1IPROC) load_gl_function_by_name("glUniform1i");
    glUniform1iv_ptr = (PFNGLUNIFORM1IVPROC) load_gl_function_by_name("glUniform1iv");
    glUniformMatrix4fv_ptr = (PFNGLUNIFORMMATRIX4FVPROC) load_gl_function_by_name("glUniformMatrix4fv");
    glVertexAttribDivisor_ptr = (PFNGLVERTEXATTRIBDIVISORPROC) load_gl_function_by_name("glVertexAttribDivisor");
    glActiveTexture_ptr = (PFNGLACTIVETEXTUREPROC) load_gl_function_by_name("glActiveTexture");
    glBufferSubData_ptr = (PFNGLBUFFERSUBDATAPROC) load_gl_function_by_name("glBufferSubData");
    glDrawArraysInstanced_ptr = (PFNGLDRAWARRAYSINSTANCEDPROC) load_gl_function_by_name("glDrawArraysInstanced");
    glBindFramebuffer_ptr = (PFNGLBINDFRAMEBUFFERPROC) load_gl_function_by_name("glBindFramebuffer");
    glCheckFramebufferStatus_ptr = (PFNGLCHECKFRAMEBUFFERSTATUSPROC) load_gl_function_by_name("glCheckFramebufferStatus");
    glGenFramebuffers_ptr = (PFNGLGENFRAMEBUFFERSPROC) load_gl_function_by_name("glGenFramebuffers");
    glFramebufferTexture2D_ptr = (PFNGLFRAMEBUFFERTEXTURE2DPROC) load_gl_function_by_name("glFramebufferTexture2D");
    glDrawBuffers_ptr = (PFNGLDRAWBUFFERSPROC) load_gl_function_by_name("glDrawBuffers");
    glDeleteFramebuffers_ptr = (PFNGLDELETEFRAMEBUFFERSPROC) load_gl_function_by_name("glDeleteFramebuffers");
    glBlendFunci_ptr = (PFNGLBLENDFUNCIPROC) load_gl_function_by_name("glBlendFunci");
    glBlendEquation_ptr = (PFNGLBLENDEQUATIONPROC) load_gl_function_by_name("glBlendEquation");
    glClearBufferfv_ptr = (PFNGLCLEARBUFFERFVPROC) load_gl_function_by_name("glClearBufferfv");
    glShaderSource_ptr = (PFNGLSHADERSOURCEPROC) load_gl_function_by_name("glShaderSource");
    glCompileShader_ptr = (PFNGLCOMPILESHADERPROC) load_gl_function_by_name("glCompileShader");
    glGetShaderiv_ptr = (PFNGLGETSHADERIVPROC) load_gl_function_by_name("glGetShaderiv");
    glGetShaderInfoLog_ptr = (PFNGLGETSHADERINFOLOGPROC) load_gl_function_by_name("glGetShaderInfoLog");
    glAttachShader_ptr = (PFNGLATTACHSHADERPROC) load_gl_function_by_name("glAttachShader");
    glLinkProgram_ptr = (PFNGLLINKPROGRAMPROC) load_gl_function_by_name("glLinkProgram");
    glValidateProgram_ptr = (PFNGLVALIDATEPROGRAMPROC) load_gl_function_by_name("glValidateProgram");
    glGetProgramiv_ptr = (PFNGLGETPROGRAMIVPROC) load_gl_function_by_name("glGetProgramiv");
    glGetProgramInfoLog_ptr = (PFNGLGETPROGRAMINFOLOGPROC) load_gl_function_by_name("glGetProgramInfoLog");
    glGenBuffers_ptr = (PFNGLGENBUFFERSPROC) load_gl_function_by_name("glGenBuffers");
    glGenVertexArrays_ptr = (PFNGLGENVERTEXARRAYSPROC) load_gl_function_by_name("glGenVertexArrays");
    glGetAttribLocation_ptr = (PFNGLGETATTRIBLOCATIONPROC) load_gl_function_by_name("glGetAttribLocation");
    glBindVertexArray_ptr = (PFNGLBINDVERTEXARRAYPROC) load_gl_function_by_name("glBindVertexArray");
    glEnableVertexAttribArray_ptr = (PFNGLENABLEVERTEXATTRIBARRAYPROC) load_gl_function_by_name("glEnableVertexAttribArray");
    glVertexAttribPointer_ptr = (PFNGLVERTEXATTRIBPOINTERPROC) load_gl_function_by_name("glVertexAttribPointer");
    glBindBuffer_ptr = (PFNGLBINDBUFFERPROC) load_gl_function_by_name("glBindBuffer");
    glBindBufferBase_ptr = (PFNGLBINDBUFFERBASEPROC) load_gl_function_by_name("glBindBufferBase");
    glBufferData_ptr = (PFNGLBUFFERDATAPROC) load_gl_function_by_name("glBufferData");
    glGetVertexAttribPointerv_ptr = (PFNGLGETVERTEXATTRIBPOINTERVPROC) load_gl_function_by_name("glGetVertexAttribPointerv");
    glUseProgram_ptr = (PFNGLUSEPROGRAMPROC) load_gl_function_by_name("glUseProgram");
    glDeleteVertexArrays_ptr = (PFNGLDELETEVERTEXARRAYSPROC) load_gl_function_by_name("glDeleteVertexArrays");
    glDeleteBuffers_ptr = (PFNGLDELETEBUFFERSPROC) load_gl_function_by_name("glDeleteBuffers");
    glDeleteProgram_ptr = (PFNGLDELETEPROGRAMPROC) load_gl_function_by_name("glDeleteProgram");
    glDetachShader_ptr = (PFNGLDETACHSHADERPROC) load_gl_function_by_name("glDetachShader");
    glDeleteShader_ptr = (PFNGLDELETESHADERPROC) load_gl_function_by_name("glDeleteShader");
    glDrawElementsInstanced_ptr = (PFNGLDRAWELEMENTSINSTANCEDPROC) load_gl_function_by_name("glDrawElementsInstanced");
    glGenerateMipmap_ptr = (PFNGLGENERATEMIPMAPPROC) load_gl_function_by_name("glGenerateMipmap");
    glDebugMessageCallback_ptr = (PFNGLDEBUGMESSAGECALLBACKPROC)load_gl_function_by_name("glDebugMessageCallback");
    glGetIntegerv_ptr = (PFNGLGETINTEGERVPROC)load_gl_function_by_name("glGetIntegerv");
}

any_func_ptr load_gl_function_by_name(const char* func_name)
{
    PROC proc1 = wglGetProcAddress(func_name);
    if(proc1 != NULL) return (any_func_ptr)proc1;

    static HMODULE opengl_dll = LoadLibraryA("opengl32.dll");

    FARPROC proc2 = GetProcAddress(opengl_dll, func_name);
    if(proc2 != NULL) return (any_func_ptr)proc2;
    
    QUARTZ_ASSERT(false, "Failed to load OpenGL function!");
}

bool try_load_gl_function_by_name(const char* func_name, any_func_ptr* out_gl_func)
{
    PROC proc1 = wglGetProcAddress(func_name);
    if(proc1 != NULL)
    {
        *out_gl_func = (any_func_ptr)proc1;
        return true;
    }

    static HMODULE opengl_dll = LoadLibraryA("opengl32.dll");

    FARPROC proc2 = GetProcAddress(opengl_dll, func_name);
    if(proc2 != NULL)
    {
        *out_gl_func = (any_func_ptr)proc2;
        return true;
    }

    return false;
}

GLAPI GLuint APIENTRY glCreateProgram (void)
{
  return glCreateProgram_ptr();
}

GLAPI void APIENTRY glDeleteTextures (GLsizei n, const GLuint *textures)
{
  glDeleteTextures_ptr(n, textures);
}

GLAPI void APIENTRY glGenTextures (GLsizei n, GLuint *textures)
{
  glGenTextures_ptr(n, textures);
}

GLAPI void APIENTRY glBindTexture (GLenum target, GLuint texture)
{
  glBindTexture_ptr(target, texture);
}

GLAPI void APIENTRY glBindTextureUnit(GLuint unit, GLuint texture)
{
  glBindTextureUnit_ptr(unit, texture);
}

void glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
    glDrawArrays_ptr(mode, first, count);
}

GLuint glCreateShader(GLenum shaderType)
{
    return glCreateShader_ptr(shaderType);
}

GLint glGetUniformLocation(GLuint program, const GLchar* name)
{
    return glGetUniformLocation_ptr(program, name);
}

void glUniform1f(GLint location, GLfloat v0)
{
    glUniform1f_ptr(location, v0);
}

void glUniform2fv(GLint location, GLsizei count, const GLfloat* value)
{
    glUniform2fv_ptr(location, count, value);
}

void glUniform3fv(GLint location, GLsizei count, const GLfloat* value)
{
    glUniform3fv_ptr(location, count, value);
}

void glUniform4fv(GLint location, GLsizei count, const GLfloat* value)
{
    glUniform4fv_ptr(location, count, value);
}

void glUniform1i(GLint location, GLint v0)
{
    glUniform1i_ptr(location, v0);
}

GLAPI void APIENTRY glUniform1iv(GLint location, GLsizei count, const GLint* value)
{
    glUniform1iv_ptr(location, count, value);
}

void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glUniformMatrix4fv_ptr(location, count, transpose, value);
}

void glVertexAttribDivisor(GLuint index, GLuint divisor)
{
    glVertexAttribDivisor_ptr(index, divisor);
}

void glActiveTexture(GLenum texture)
{
    glActiveTexture_ptr(texture);
}

void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data)
{
    glBufferSubData_ptr(target, offset, size, data);
}

void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instanceCount)
{
    glDrawArraysInstanced_ptr(mode, first, count, instanceCount);
}

void glBindFramebuffer(GLenum target, GLuint framebuffer)
{
    glBindFramebuffer_ptr(target, framebuffer);
}

GLenum glCheckFramebufferStatus(GLenum target)
{
    return glCheckFramebufferStatus_ptr(target);
}

void glGenFramebuffers(GLsizei n, GLuint* framebuffers)
{
    glGenFramebuffers_ptr(n, framebuffers);
}

void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    glFramebufferTexture2D_ptr(target, attachment, textarget, texture, level);
}

void glDrawBuffers(GLsizei n, const GLenum* bufs)
{
    glDrawBuffers_ptr(n, bufs);
}

void glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers)
{
    glDeleteFramebuffers_ptr(n, framebuffers);
}

void glBlendFunci(GLuint buf, GLenum src, GLenum dst)
{
    glBlendFunci_ptr(buf, src, dst);
}

void glBlendEquation(GLenum mode)
{
    glBlendEquation_ptr(mode);
}

void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value)
{
    glClearBufferfv_ptr(buffer, drawbuffer, value);
}

void glShaderSource(GLuint shader, GLsizei count, const GLchar* const* strings, const GLint* lengths)
{
    glShaderSource_ptr(shader, count, strings, lengths);
}

void glCompileShader(GLuint shader)
{
    glCompileShader_ptr(shader);
}

void glGetShaderiv(GLuint shader, GLenum pname, GLint* params)
{
    glGetShaderiv_ptr(shader, pname, params);
}

void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog)
{
    glGetShaderInfoLog_ptr(shader, bufSize, length, infoLog);
}

void glAttachShader(GLuint program, GLuint shader)
{
    glAttachShader_ptr(program, shader);
}

void glLinkProgram(GLuint program)
{
    glLinkProgram_ptr(program);
}

void glValidateProgram(GLuint program)
{
    glValidateProgram_ptr(program);
}

void glGetProgramiv(GLuint program, GLenum pname, GLint* params)
{
    glGetProgramiv_ptr(program, pname, params);
}

void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog)
{
    glGetProgramInfoLog_ptr(program, bufSize, length, infoLog);
}

void glGenBuffers(GLsizei n, GLuint* buffers)
{
    glGenBuffers_ptr(n, buffers);
}

void glGenVertexArrays(GLsizei n, GLuint* arrays)
{
    glGenVertexArrays_ptr(n, arrays);
}

GLint glGetAttribLocation(GLuint program, const GLchar* name)
{
    return glGetAttribLocation_ptr(program, name);
}

void glBindVertexArray(GLuint array)
{
    glBindVertexArray_ptr(array);
}

void glEnableVertexAttribArray(GLuint index)
{
    glEnableVertexAttribArray_ptr(index);
}

void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
{
    glVertexAttribPointer_ptr(index, size, type, normalized, stride, pointer);
}

void glBindBuffer(GLenum target, GLuint buffer)
{
    glBindBuffer_ptr(target, buffer);
}

void glBindBufferBase(GLenum target, GLuint index, GLuint buffer)
{
    glBindBufferBase_ptr(target, index, buffer);
}

void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage)
{
    glBufferData_ptr(target, size, data, usage);
}

void glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer)
{
    glGetVertexAttribPointerv_ptr(index, pname, pointer);
}

void glUseProgram(GLuint program)
{
    glUseProgram_ptr(program);
}

void glDeleteVertexArrays(GLsizei n, const GLuint* arrays)
{
    glDeleteVertexArrays_ptr(n, arrays);
}

void glDeleteBuffers(GLsizei n, const GLuint* buffers)
{
    glDeleteBuffers_ptr(n, buffers);
}

void glDeleteProgram(GLuint program)
{
    glDeleteProgram_ptr(program);
}

void glDetachShader (GLuint program, GLuint shader)
{
    glDetachShader_ptr(program, shader);
}

void glDeleteShader(GLuint shader)
{
    glDeleteShader_ptr(shader);
}

void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount)
{
    glDrawElementsInstanced_ptr(mode, count, type, indices, instancecount);
}

void glGenerateMipmap(GLenum target)
{
    glGenerateMipmap_ptr(target);
}

void glDebugMessageCallback (GLDEBUGPROC callback, const void *userParam)
{
  glDebugMessageCallback_ptr(callback, userParam);
}

GLAPI void APIENTRY glGetIntegerv(GLenum pname, GLint *data)
{
    glGetIntegerv_ptr(pname, data);
}