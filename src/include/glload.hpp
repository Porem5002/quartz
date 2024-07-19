#ifndef GLLOAD_HEADER
#define GLLOAD_HEADER

#define GL_GLEXT_PROTOTYPES
#include <glcorearb.h>

using any_func_ptr = void (*) ();

void load_gl_functions();
any_func_ptr load_gl_function_by_name(const char* func_name);

GLAPI GLuint APIENTRY glCreateProgram (void);
GLAPI void APIENTRY glDeleteTextures (GLsizei n, const GLuint *textures);
GLAPI void APIENTRY glGenTextures (GLsizei n, GLuint *textures);
GLAPI void APIENTRY glBindTexture (GLenum target, GLuint texture);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
GLuint glCreateShader(GLenum shaderType);
GLint glGetUniformLocation(GLuint program, const GLchar* name);
void glUniform1f(GLint location, GLfloat v0);
void glUniform2fv(GLint location, GLsizei count, const GLfloat* value);
void glUniform3fv(GLint location, GLsizei count, const GLfloat* value);
void glUniform1i(GLint location, GLint v0);
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glVertexAttribDivisor(GLuint index, GLuint divisor);
void glActiveTexture(GLenum texture);
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instanceCount);
void glBindFramebuffer(GLenum target, GLuint framebuffer);
GLenum glCheckFramebufferStatus(GLenum target);
void glGenFramebuffers(GLsizei n, GLuint* framebuffers);
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glDrawBuffers(GLsizei n, const GLenum* bufs);
void glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers);
void glBlendFunci(GLuint buf, GLenum src, GLenum dst);
void glBlendEquation(GLenum mode);
void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value);
void glShaderSource(GLuint shader, GLsizei count, const GLchar* const* strings, const GLint* lengths);
void glCompileShader(GLuint shader);
void glGetShaderiv(GLuint shader, GLenum pname, GLint* params);
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
void glAttachShader(GLuint program, GLuint shader);
void glLinkProgram(GLuint program);
void glValidateProgram(GLuint program);
void glGetProgramiv(GLuint program, GLenum pname, GLint* params);
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
void glGenBuffers(GLsizei n, GLuint* buffers);
void glGenVertexArrays(GLsizei n, GLuint* arrays);
GLint glGetAttribLocation(GLuint program, const GLchar* name);
void glBindVertexArray(GLuint array);
void glEnableVertexAttribArray(GLuint index);
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
void glBindBuffer(GLenum target, GLuint buffer);
void glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer);
void glUseProgram(GLuint program);
void glDeleteVertexArrays(GLsizei n, const GLuint* arrays);
void glDeleteBuffers(GLsizei n, const GLuint* buffers);
void glDeleteProgram(GLuint program);
void glDetachShader (GLuint program, GLuint shader);
void glDeleteShader(GLuint shader);
void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
void glGenerateMipmap(GLenum target);
void glDebugMessageCallback (GLDEBUGPROC callback, const void *userParam);

#endif