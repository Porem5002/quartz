#ifndef GAPIL_HEADER
#define GAPIL_HEADER

#ifdef __cplusplus
extern "C" {
#endif

#include <assert.h>

#define GL_GLEXT_PROTOTYPES
#include <glcorearb.h>

#define WGL_WGLEXT_PROTOTYPES
#include <wglext.h>

typedef void (*gapil_func)(void);
void gapil_load();

#ifdef __cplusplus
}
#endif

#endif

#if defined(GAPIL_IMPLEMENTATION) && !defined(GAPIL_ALREADY_IMPLEMENTED)
#define GAPIL_ALREADY_IMPLEMENTED

#ifdef __cplusplus
extern "C" {
#endif

static gapil_func gapil_gl_func_table [1279] = {0};
static gapil_func gapil_load_function(const char* name);
static void gapil_load_extensions();

void gapil_load()
{
	gapil_gl_func_table[0] = gapil_load_function("glCullFace");
	gapil_gl_func_table[1] = gapil_load_function("glFrontFace");
	gapil_gl_func_table[2] = gapil_load_function("glHint");
	gapil_gl_func_table[3] = gapil_load_function("glLineWidth");
	gapil_gl_func_table[4] = gapil_load_function("glPointSize");
	gapil_gl_func_table[5] = gapil_load_function("glPolygonMode");
	gapil_gl_func_table[6] = gapil_load_function("glScissor");
	gapil_gl_func_table[7] = gapil_load_function("glTexParameterf");
	gapil_gl_func_table[8] = gapil_load_function("glTexParameterfv");
	gapil_gl_func_table[9] = gapil_load_function("glTexParameteri");
	gapil_gl_func_table[10] = gapil_load_function("glTexParameteriv");
	gapil_gl_func_table[11] = gapil_load_function("glTexImage1D");
	gapil_gl_func_table[12] = gapil_load_function("glTexImage2D");
	gapil_gl_func_table[13] = gapil_load_function("glDrawBuffer");
	gapil_gl_func_table[14] = gapil_load_function("glClear");
	gapil_gl_func_table[15] = gapil_load_function("glClearColor");
	gapil_gl_func_table[16] = gapil_load_function("glClearStencil");
	gapil_gl_func_table[17] = gapil_load_function("glClearDepth");
	gapil_gl_func_table[18] = gapil_load_function("glStencilMask");
	gapil_gl_func_table[19] = gapil_load_function("glColorMask");
	gapil_gl_func_table[20] = gapil_load_function("glDepthMask");
	gapil_gl_func_table[21] = gapil_load_function("glDisable");
	gapil_gl_func_table[22] = gapil_load_function("glEnable");
	gapil_gl_func_table[23] = gapil_load_function("glFinish");
	gapil_gl_func_table[24] = gapil_load_function("glFlush");
	gapil_gl_func_table[25] = gapil_load_function("glBlendFunc");
	gapil_gl_func_table[26] = gapil_load_function("glLogicOp");
	gapil_gl_func_table[27] = gapil_load_function("glStencilFunc");
	gapil_gl_func_table[28] = gapil_load_function("glStencilOp");
	gapil_gl_func_table[29] = gapil_load_function("glDepthFunc");
	gapil_gl_func_table[30] = gapil_load_function("glPixelStoref");
	gapil_gl_func_table[31] = gapil_load_function("glPixelStorei");
	gapil_gl_func_table[32] = gapil_load_function("glReadBuffer");
	gapil_gl_func_table[33] = gapil_load_function("glReadPixels");
	gapil_gl_func_table[34] = gapil_load_function("glGetBooleanv");
	gapil_gl_func_table[35] = gapil_load_function("glGetDoublev");
	gapil_gl_func_table[36] = gapil_load_function("glGetError");
	gapil_gl_func_table[37] = gapil_load_function("glGetFloatv");
	gapil_gl_func_table[38] = gapil_load_function("glGetIntegerv");
	gapil_gl_func_table[39] = gapil_load_function("glGetString");
	gapil_gl_func_table[40] = gapil_load_function("glGetTexImage");
	gapil_gl_func_table[41] = gapil_load_function("glGetTexParameterfv");
	gapil_gl_func_table[42] = gapil_load_function("glGetTexParameteriv");
	gapil_gl_func_table[43] = gapil_load_function("glGetTexLevelParameterfv");
	gapil_gl_func_table[44] = gapil_load_function("glGetTexLevelParameteriv");
	gapil_gl_func_table[45] = gapil_load_function("glIsEnabled");
	gapil_gl_func_table[46] = gapil_load_function("glDepthRange");
	gapil_gl_func_table[47] = gapil_load_function("glViewport");
	gapil_gl_func_table[48] = gapil_load_function("glDrawArrays");
	gapil_gl_func_table[49] = gapil_load_function("glDrawElements");
	gapil_gl_func_table[50] = gapil_load_function("glGetPointerv");
	gapil_gl_func_table[51] = gapil_load_function("glPolygonOffset");
	gapil_gl_func_table[52] = gapil_load_function("glCopyTexImage1D");
	gapil_gl_func_table[53] = gapil_load_function("glCopyTexImage2D");
	gapil_gl_func_table[54] = gapil_load_function("glCopyTexSubImage1D");
	gapil_gl_func_table[55] = gapil_load_function("glCopyTexSubImage2D");
	gapil_gl_func_table[56] = gapil_load_function("glTexSubImage1D");
	gapil_gl_func_table[57] = gapil_load_function("glTexSubImage2D");
	gapil_gl_func_table[58] = gapil_load_function("glBindTexture");
	gapil_gl_func_table[59] = gapil_load_function("glDeleteTextures");
	gapil_gl_func_table[60] = gapil_load_function("glGenTextures");
	gapil_gl_func_table[61] = gapil_load_function("glIsTexture");
	gapil_gl_func_table[62] = gapil_load_function("glDrawRangeElements");
	gapil_gl_func_table[63] = gapil_load_function("glTexImage3D");
	gapil_gl_func_table[64] = gapil_load_function("glTexSubImage3D");
	gapil_gl_func_table[65] = gapil_load_function("glCopyTexSubImage3D");
	gapil_gl_func_table[66] = gapil_load_function("glActiveTexture");
	gapil_gl_func_table[67] = gapil_load_function("glSampleCoverage");
	gapil_gl_func_table[68] = gapil_load_function("glCompressedTexImage3D");
	gapil_gl_func_table[69] = gapil_load_function("glCompressedTexImage2D");
	gapil_gl_func_table[70] = gapil_load_function("glCompressedTexImage1D");
	gapil_gl_func_table[71] = gapil_load_function("glCompressedTexSubImage3D");
	gapil_gl_func_table[72] = gapil_load_function("glCompressedTexSubImage2D");
	gapil_gl_func_table[73] = gapil_load_function("glCompressedTexSubImage1D");
	gapil_gl_func_table[74] = gapil_load_function("glGetCompressedTexImage");
	gapil_gl_func_table[75] = gapil_load_function("glBlendFuncSeparate");
	gapil_gl_func_table[76] = gapil_load_function("glMultiDrawArrays");
	gapil_gl_func_table[77] = gapil_load_function("glMultiDrawElements");
	gapil_gl_func_table[78] = gapil_load_function("glPointParameterf");
	gapil_gl_func_table[79] = gapil_load_function("glPointParameterfv");
	gapil_gl_func_table[80] = gapil_load_function("glPointParameteri");
	gapil_gl_func_table[81] = gapil_load_function("glPointParameteriv");
	gapil_gl_func_table[82] = gapil_load_function("glBlendColor");
	gapil_gl_func_table[83] = gapil_load_function("glBlendEquation");
	gapil_gl_func_table[84] = gapil_load_function("glGenQueries");
	gapil_gl_func_table[85] = gapil_load_function("glDeleteQueries");
	gapil_gl_func_table[86] = gapil_load_function("glIsQuery");
	gapil_gl_func_table[87] = gapil_load_function("glBeginQuery");
	gapil_gl_func_table[88] = gapil_load_function("glEndQuery");
	gapil_gl_func_table[89] = gapil_load_function("glGetQueryiv");
	gapil_gl_func_table[90] = gapil_load_function("glGetQueryObjectiv");
	gapil_gl_func_table[91] = gapil_load_function("glGetQueryObjectuiv");
	gapil_gl_func_table[92] = gapil_load_function("glBindBuffer");
	gapil_gl_func_table[93] = gapil_load_function("glDeleteBuffers");
	gapil_gl_func_table[94] = gapil_load_function("glGenBuffers");
	gapil_gl_func_table[95] = gapil_load_function("glIsBuffer");
	gapil_gl_func_table[96] = gapil_load_function("glBufferData");
	gapil_gl_func_table[97] = gapil_load_function("glBufferSubData");
	gapil_gl_func_table[98] = gapil_load_function("glGetBufferSubData");
	gapil_gl_func_table[99] = gapil_load_function("glMapBuffer");
	gapil_gl_func_table[100] = gapil_load_function("glUnmapBuffer");
	gapil_gl_func_table[101] = gapil_load_function("glGetBufferParameteriv");
	gapil_gl_func_table[102] = gapil_load_function("glGetBufferPointerv");
	gapil_gl_func_table[103] = gapil_load_function("glBlendEquationSeparate");
	gapil_gl_func_table[104] = gapil_load_function("glDrawBuffers");
	gapil_gl_func_table[105] = gapil_load_function("glStencilOpSeparate");
	gapil_gl_func_table[106] = gapil_load_function("glStencilFuncSeparate");
	gapil_gl_func_table[107] = gapil_load_function("glStencilMaskSeparate");
	gapil_gl_func_table[108] = gapil_load_function("glAttachShader");
	gapil_gl_func_table[109] = gapil_load_function("glBindAttribLocation");
	gapil_gl_func_table[110] = gapil_load_function("glCompileShader");
	gapil_gl_func_table[111] = gapil_load_function("glCreateProgram");
	gapil_gl_func_table[112] = gapil_load_function("glCreateShader");
	gapil_gl_func_table[113] = gapil_load_function("glDeleteProgram");
	gapil_gl_func_table[114] = gapil_load_function("glDeleteShader");
	gapil_gl_func_table[115] = gapil_load_function("glDetachShader");
	gapil_gl_func_table[116] = gapil_load_function("glDisableVertexAttribArray");
	gapil_gl_func_table[117] = gapil_load_function("glEnableVertexAttribArray");
	gapil_gl_func_table[118] = gapil_load_function("glGetActiveAttrib");
	gapil_gl_func_table[119] = gapil_load_function("glGetActiveUniform");
	gapil_gl_func_table[120] = gapil_load_function("glGetAttachedShaders");
	gapil_gl_func_table[121] = gapil_load_function("glGetAttribLocation");
	gapil_gl_func_table[122] = gapil_load_function("glGetProgramiv");
	gapil_gl_func_table[123] = gapil_load_function("glGetProgramInfoLog");
	gapil_gl_func_table[124] = gapil_load_function("glGetShaderiv");
	gapil_gl_func_table[125] = gapil_load_function("glGetShaderInfoLog");
	gapil_gl_func_table[126] = gapil_load_function("glGetShaderSource");
	gapil_gl_func_table[127] = gapil_load_function("glGetUniformLocation");
	gapil_gl_func_table[128] = gapil_load_function("glGetUniformfv");
	gapil_gl_func_table[129] = gapil_load_function("glGetUniformiv");
	gapil_gl_func_table[130] = gapil_load_function("glGetVertexAttribdv");
	gapil_gl_func_table[131] = gapil_load_function("glGetVertexAttribfv");
	gapil_gl_func_table[132] = gapil_load_function("glGetVertexAttribiv");
	gapil_gl_func_table[133] = gapil_load_function("glGetVertexAttribPointerv");
	gapil_gl_func_table[134] = gapil_load_function("glIsProgram");
	gapil_gl_func_table[135] = gapil_load_function("glIsShader");
	gapil_gl_func_table[136] = gapil_load_function("glLinkProgram");
	gapil_gl_func_table[137] = gapil_load_function("glShaderSource");
	gapil_gl_func_table[138] = gapil_load_function("glUseProgram");
	gapil_gl_func_table[139] = gapil_load_function("glUniform1f");
	gapil_gl_func_table[140] = gapil_load_function("glUniform2f");
	gapil_gl_func_table[141] = gapil_load_function("glUniform3f");
	gapil_gl_func_table[142] = gapil_load_function("glUniform4f");
	gapil_gl_func_table[143] = gapil_load_function("glUniform1i");
	gapil_gl_func_table[144] = gapil_load_function("glUniform2i");
	gapil_gl_func_table[145] = gapil_load_function("glUniform3i");
	gapil_gl_func_table[146] = gapil_load_function("glUniform4i");
	gapil_gl_func_table[147] = gapil_load_function("glUniform1fv");
	gapil_gl_func_table[148] = gapil_load_function("glUniform2fv");
	gapil_gl_func_table[149] = gapil_load_function("glUniform3fv");
	gapil_gl_func_table[150] = gapil_load_function("glUniform4fv");
	gapil_gl_func_table[151] = gapil_load_function("glUniform1iv");
	gapil_gl_func_table[152] = gapil_load_function("glUniform2iv");
	gapil_gl_func_table[153] = gapil_load_function("glUniform3iv");
	gapil_gl_func_table[154] = gapil_load_function("glUniform4iv");
	gapil_gl_func_table[155] = gapil_load_function("glUniformMatrix2fv");
	gapil_gl_func_table[156] = gapil_load_function("glUniformMatrix3fv");
	gapil_gl_func_table[157] = gapil_load_function("glUniformMatrix4fv");
	gapil_gl_func_table[158] = gapil_load_function("glValidateProgram");
	gapil_gl_func_table[159] = gapil_load_function("glVertexAttrib1d");
	gapil_gl_func_table[160] = gapil_load_function("glVertexAttrib1dv");
	gapil_gl_func_table[161] = gapil_load_function("glVertexAttrib1f");
	gapil_gl_func_table[162] = gapil_load_function("glVertexAttrib1fv");
	gapil_gl_func_table[163] = gapil_load_function("glVertexAttrib1s");
	gapil_gl_func_table[164] = gapil_load_function("glVertexAttrib1sv");
	gapil_gl_func_table[165] = gapil_load_function("glVertexAttrib2d");
	gapil_gl_func_table[166] = gapil_load_function("glVertexAttrib2dv");
	gapil_gl_func_table[167] = gapil_load_function("glVertexAttrib2f");
	gapil_gl_func_table[168] = gapil_load_function("glVertexAttrib2fv");
	gapil_gl_func_table[169] = gapil_load_function("glVertexAttrib2s");
	gapil_gl_func_table[170] = gapil_load_function("glVertexAttrib2sv");
	gapil_gl_func_table[171] = gapil_load_function("glVertexAttrib3d");
	gapil_gl_func_table[172] = gapil_load_function("glVertexAttrib3dv");
	gapil_gl_func_table[173] = gapil_load_function("glVertexAttrib3f");
	gapil_gl_func_table[174] = gapil_load_function("glVertexAttrib3fv");
	gapil_gl_func_table[175] = gapil_load_function("glVertexAttrib3s");
	gapil_gl_func_table[176] = gapil_load_function("glVertexAttrib3sv");
	gapil_gl_func_table[177] = gapil_load_function("glVertexAttrib4Nbv");
	gapil_gl_func_table[178] = gapil_load_function("glVertexAttrib4Niv");
	gapil_gl_func_table[179] = gapil_load_function("glVertexAttrib4Nsv");
	gapil_gl_func_table[180] = gapil_load_function("glVertexAttrib4Nub");
	gapil_gl_func_table[181] = gapil_load_function("glVertexAttrib4Nubv");
	gapil_gl_func_table[182] = gapil_load_function("glVertexAttrib4Nuiv");
	gapil_gl_func_table[183] = gapil_load_function("glVertexAttrib4Nusv");
	gapil_gl_func_table[184] = gapil_load_function("glVertexAttrib4bv");
	gapil_gl_func_table[185] = gapil_load_function("glVertexAttrib4d");
	gapil_gl_func_table[186] = gapil_load_function("glVertexAttrib4dv");
	gapil_gl_func_table[187] = gapil_load_function("glVertexAttrib4f");
	gapil_gl_func_table[188] = gapil_load_function("glVertexAttrib4fv");
	gapil_gl_func_table[189] = gapil_load_function("glVertexAttrib4iv");
	gapil_gl_func_table[190] = gapil_load_function("glVertexAttrib4s");
	gapil_gl_func_table[191] = gapil_load_function("glVertexAttrib4sv");
	gapil_gl_func_table[192] = gapil_load_function("glVertexAttrib4ubv");
	gapil_gl_func_table[193] = gapil_load_function("glVertexAttrib4uiv");
	gapil_gl_func_table[194] = gapil_load_function("glVertexAttrib4usv");
	gapil_gl_func_table[195] = gapil_load_function("glVertexAttribPointer");
	gapil_gl_func_table[196] = gapil_load_function("glUniformMatrix2x3fv");
	gapil_gl_func_table[197] = gapil_load_function("glUniformMatrix3x2fv");
	gapil_gl_func_table[198] = gapil_load_function("glUniformMatrix2x4fv");
	gapil_gl_func_table[199] = gapil_load_function("glUniformMatrix4x2fv");
	gapil_gl_func_table[200] = gapil_load_function("glUniformMatrix3x4fv");
	gapil_gl_func_table[201] = gapil_load_function("glUniformMatrix4x3fv");
	gapil_gl_func_table[202] = gapil_load_function("glColorMaski");
	gapil_gl_func_table[203] = gapil_load_function("glGetBooleani_v");
	gapil_gl_func_table[204] = gapil_load_function("glGetIntegeri_v");
	gapil_gl_func_table[205] = gapil_load_function("glEnablei");
	gapil_gl_func_table[206] = gapil_load_function("glDisablei");
	gapil_gl_func_table[207] = gapil_load_function("glIsEnabledi");
	gapil_gl_func_table[208] = gapil_load_function("glBeginTransformFeedback");
	gapil_gl_func_table[209] = gapil_load_function("glEndTransformFeedback");
	gapil_gl_func_table[210] = gapil_load_function("glBindBufferRange");
	gapil_gl_func_table[211] = gapil_load_function("glBindBufferBase");
	gapil_gl_func_table[212] = gapil_load_function("glTransformFeedbackVaryings");
	gapil_gl_func_table[213] = gapil_load_function("glGetTransformFeedbackVarying");
	gapil_gl_func_table[214] = gapil_load_function("glClampColor");
	gapil_gl_func_table[215] = gapil_load_function("glBeginConditionalRender");
	gapil_gl_func_table[216] = gapil_load_function("glEndConditionalRender");
	gapil_gl_func_table[217] = gapil_load_function("glVertexAttribIPointer");
	gapil_gl_func_table[218] = gapil_load_function("glGetVertexAttribIiv");
	gapil_gl_func_table[219] = gapil_load_function("glGetVertexAttribIuiv");
	gapil_gl_func_table[220] = gapil_load_function("glVertexAttribI1i");
	gapil_gl_func_table[221] = gapil_load_function("glVertexAttribI2i");
	gapil_gl_func_table[222] = gapil_load_function("glVertexAttribI3i");
	gapil_gl_func_table[223] = gapil_load_function("glVertexAttribI4i");
	gapil_gl_func_table[224] = gapil_load_function("glVertexAttribI1ui");
	gapil_gl_func_table[225] = gapil_load_function("glVertexAttribI2ui");
	gapil_gl_func_table[226] = gapil_load_function("glVertexAttribI3ui");
	gapil_gl_func_table[227] = gapil_load_function("glVertexAttribI4ui");
	gapil_gl_func_table[228] = gapil_load_function("glVertexAttribI1iv");
	gapil_gl_func_table[229] = gapil_load_function("glVertexAttribI2iv");
	gapil_gl_func_table[230] = gapil_load_function("glVertexAttribI3iv");
	gapil_gl_func_table[231] = gapil_load_function("glVertexAttribI4iv");
	gapil_gl_func_table[232] = gapil_load_function("glVertexAttribI1uiv");
	gapil_gl_func_table[233] = gapil_load_function("glVertexAttribI2uiv");
	gapil_gl_func_table[234] = gapil_load_function("glVertexAttribI3uiv");
	gapil_gl_func_table[235] = gapil_load_function("glVertexAttribI4uiv");
	gapil_gl_func_table[236] = gapil_load_function("glVertexAttribI4bv");
	gapil_gl_func_table[237] = gapil_load_function("glVertexAttribI4sv");
	gapil_gl_func_table[238] = gapil_load_function("glVertexAttribI4ubv");
	gapil_gl_func_table[239] = gapil_load_function("glVertexAttribI4usv");
	gapil_gl_func_table[240] = gapil_load_function("glGetUniformuiv");
	gapil_gl_func_table[241] = gapil_load_function("glBindFragDataLocation");
	gapil_gl_func_table[242] = gapil_load_function("glGetFragDataLocation");
	gapil_gl_func_table[243] = gapil_load_function("glUniform1ui");
	gapil_gl_func_table[244] = gapil_load_function("glUniform2ui");
	gapil_gl_func_table[245] = gapil_load_function("glUniform3ui");
	gapil_gl_func_table[246] = gapil_load_function("glUniform4ui");
	gapil_gl_func_table[247] = gapil_load_function("glUniform1uiv");
	gapil_gl_func_table[248] = gapil_load_function("glUniform2uiv");
	gapil_gl_func_table[249] = gapil_load_function("glUniform3uiv");
	gapil_gl_func_table[250] = gapil_load_function("glUniform4uiv");
	gapil_gl_func_table[251] = gapil_load_function("glTexParameterIiv");
	gapil_gl_func_table[252] = gapil_load_function("glTexParameterIuiv");
	gapil_gl_func_table[253] = gapil_load_function("glGetTexParameterIiv");
	gapil_gl_func_table[254] = gapil_load_function("glGetTexParameterIuiv");
	gapil_gl_func_table[255] = gapil_load_function("glClearBufferiv");
	gapil_gl_func_table[256] = gapil_load_function("glClearBufferuiv");
	gapil_gl_func_table[257] = gapil_load_function("glClearBufferfv");
	gapil_gl_func_table[258] = gapil_load_function("glClearBufferfi");
	gapil_gl_func_table[259] = gapil_load_function("glGetStringi");
	gapil_gl_func_table[260] = gapil_load_function("glIsRenderbuffer");
	gapil_gl_func_table[261] = gapil_load_function("glBindRenderbuffer");
	gapil_gl_func_table[262] = gapil_load_function("glDeleteRenderbuffers");
	gapil_gl_func_table[263] = gapil_load_function("glGenRenderbuffers");
	gapil_gl_func_table[264] = gapil_load_function("glRenderbufferStorage");
	gapil_gl_func_table[265] = gapil_load_function("glGetRenderbufferParameteriv");
	gapil_gl_func_table[266] = gapil_load_function("glIsFramebuffer");
	gapil_gl_func_table[267] = gapil_load_function("glBindFramebuffer");
	gapil_gl_func_table[268] = gapil_load_function("glDeleteFramebuffers");
	gapil_gl_func_table[269] = gapil_load_function("glGenFramebuffers");
	gapil_gl_func_table[270] = gapil_load_function("glCheckFramebufferStatus");
	gapil_gl_func_table[271] = gapil_load_function("glFramebufferTexture1D");
	gapil_gl_func_table[272] = gapil_load_function("glFramebufferTexture2D");
	gapil_gl_func_table[273] = gapil_load_function("glFramebufferTexture3D");
	gapil_gl_func_table[274] = gapil_load_function("glFramebufferRenderbuffer");
	gapil_gl_func_table[275] = gapil_load_function("glGetFramebufferAttachmentParameteriv");
	gapil_gl_func_table[276] = gapil_load_function("glGenerateMipmap");
	gapil_gl_func_table[277] = gapil_load_function("glBlitFramebuffer");
	gapil_gl_func_table[278] = gapil_load_function("glRenderbufferStorageMultisample");
	gapil_gl_func_table[279] = gapil_load_function("glFramebufferTextureLayer");
	gapil_gl_func_table[280] = gapil_load_function("glMapBufferRange");
	gapil_gl_func_table[281] = gapil_load_function("glFlushMappedBufferRange");
	gapil_gl_func_table[282] = gapil_load_function("glBindVertexArray");
	gapil_gl_func_table[283] = gapil_load_function("glDeleteVertexArrays");
	gapil_gl_func_table[284] = gapil_load_function("glGenVertexArrays");
	gapil_gl_func_table[285] = gapil_load_function("glIsVertexArray");
	gapil_gl_func_table[286] = gapil_load_function("glDrawArraysInstanced");
	gapil_gl_func_table[287] = gapil_load_function("glDrawElementsInstanced");
	gapil_gl_func_table[288] = gapil_load_function("glTexBuffer");
	gapil_gl_func_table[289] = gapil_load_function("glPrimitiveRestartIndex");
	gapil_gl_func_table[290] = gapil_load_function("glCopyBufferSubData");
	gapil_gl_func_table[291] = gapil_load_function("glGetUniformIndices");
	gapil_gl_func_table[292] = gapil_load_function("glGetActiveUniformsiv");
	gapil_gl_func_table[293] = gapil_load_function("glGetActiveUniformName");
	gapil_gl_func_table[294] = gapil_load_function("glGetUniformBlockIndex");
	gapil_gl_func_table[295] = gapil_load_function("glGetActiveUniformBlockiv");
	gapil_gl_func_table[296] = gapil_load_function("glGetActiveUniformBlockName");
	gapil_gl_func_table[297] = gapil_load_function("glUniformBlockBinding");
	gapil_gl_func_table[298] = gapil_load_function("glDrawElementsBaseVertex");
	gapil_gl_func_table[299] = gapil_load_function("glDrawRangeElementsBaseVertex");
	gapil_gl_func_table[300] = gapil_load_function("glDrawElementsInstancedBaseVertex");
	gapil_gl_func_table[301] = gapil_load_function("glMultiDrawElementsBaseVertex");
	gapil_gl_func_table[302] = gapil_load_function("glProvokingVertex");
	gapil_gl_func_table[303] = gapil_load_function("glFenceSync");
	gapil_gl_func_table[304] = gapil_load_function("glIsSync");
	gapil_gl_func_table[305] = gapil_load_function("glDeleteSync");
	gapil_gl_func_table[306] = gapil_load_function("glClientWaitSync");
	gapil_gl_func_table[307] = gapil_load_function("glWaitSync");
	gapil_gl_func_table[308] = gapil_load_function("glGetInteger64v");
	gapil_gl_func_table[309] = gapil_load_function("glGetSynciv");
	gapil_gl_func_table[310] = gapil_load_function("glGetInteger64i_v");
	gapil_gl_func_table[311] = gapil_load_function("glGetBufferParameteri64v");
	gapil_gl_func_table[312] = gapil_load_function("glFramebufferTexture");
	gapil_gl_func_table[313] = gapil_load_function("glTexImage2DMultisample");
	gapil_gl_func_table[314] = gapil_load_function("glTexImage3DMultisample");
	gapil_gl_func_table[315] = gapil_load_function("glGetMultisamplefv");
	gapil_gl_func_table[316] = gapil_load_function("glSampleMaski");
	gapil_gl_func_table[317] = gapil_load_function("glBindFragDataLocationIndexed");
	gapil_gl_func_table[318] = gapil_load_function("glGetFragDataIndex");
	gapil_gl_func_table[319] = gapil_load_function("glGenSamplers");
	gapil_gl_func_table[320] = gapil_load_function("glDeleteSamplers");
	gapil_gl_func_table[321] = gapil_load_function("glIsSampler");
	gapil_gl_func_table[322] = gapil_load_function("glBindSampler");
	gapil_gl_func_table[323] = gapil_load_function("glSamplerParameteri");
	gapil_gl_func_table[324] = gapil_load_function("glSamplerParameteriv");
	gapil_gl_func_table[325] = gapil_load_function("glSamplerParameterf");
	gapil_gl_func_table[326] = gapil_load_function("glSamplerParameterfv");
	gapil_gl_func_table[327] = gapil_load_function("glSamplerParameterIiv");
	gapil_gl_func_table[328] = gapil_load_function("glSamplerParameterIuiv");
	gapil_gl_func_table[329] = gapil_load_function("glGetSamplerParameteriv");
	gapil_gl_func_table[330] = gapil_load_function("glGetSamplerParameterIiv");
	gapil_gl_func_table[331] = gapil_load_function("glGetSamplerParameterfv");
	gapil_gl_func_table[332] = gapil_load_function("glGetSamplerParameterIuiv");
	gapil_gl_func_table[333] = gapil_load_function("glQueryCounter");
	gapil_gl_func_table[334] = gapil_load_function("glGetQueryObjecti64v");
	gapil_gl_func_table[335] = gapil_load_function("glGetQueryObjectui64v");
	gapil_gl_func_table[336] = gapil_load_function("glVertexAttribDivisor");
	gapil_gl_func_table[337] = gapil_load_function("glVertexAttribP1ui");
	gapil_gl_func_table[338] = gapil_load_function("glVertexAttribP1uiv");
	gapil_gl_func_table[339] = gapil_load_function("glVertexAttribP2ui");
	gapil_gl_func_table[340] = gapil_load_function("glVertexAttribP2uiv");
	gapil_gl_func_table[341] = gapil_load_function("glVertexAttribP3ui");
	gapil_gl_func_table[342] = gapil_load_function("glVertexAttribP3uiv");
	gapil_gl_func_table[343] = gapil_load_function("glVertexAttribP4ui");
	gapil_gl_func_table[344] = gapil_load_function("glVertexAttribP4uiv");
	gapil_gl_func_table[345] = gapil_load_function("glMinSampleShading");
	gapil_gl_func_table[346] = gapil_load_function("glBlendEquationi");
	gapil_gl_func_table[347] = gapil_load_function("glBlendEquationSeparatei");
	gapil_gl_func_table[348] = gapil_load_function("glBlendFunci");
	gapil_gl_func_table[349] = gapil_load_function("glBlendFuncSeparatei");
	gapil_gl_func_table[350] = gapil_load_function("glDrawArraysIndirect");
	gapil_gl_func_table[351] = gapil_load_function("glDrawElementsIndirect");
	gapil_gl_func_table[352] = gapil_load_function("glUniform1d");
	gapil_gl_func_table[353] = gapil_load_function("glUniform2d");
	gapil_gl_func_table[354] = gapil_load_function("glUniform3d");
	gapil_gl_func_table[355] = gapil_load_function("glUniform4d");
	gapil_gl_func_table[356] = gapil_load_function("glUniform1dv");
	gapil_gl_func_table[357] = gapil_load_function("glUniform2dv");
	gapil_gl_func_table[358] = gapil_load_function("glUniform3dv");
	gapil_gl_func_table[359] = gapil_load_function("glUniform4dv");
	gapil_gl_func_table[360] = gapil_load_function("glUniformMatrix2dv");
	gapil_gl_func_table[361] = gapil_load_function("glUniformMatrix3dv");
	gapil_gl_func_table[362] = gapil_load_function("glUniformMatrix4dv");
	gapil_gl_func_table[363] = gapil_load_function("glUniformMatrix2x3dv");
	gapil_gl_func_table[364] = gapil_load_function("glUniformMatrix2x4dv");
	gapil_gl_func_table[365] = gapil_load_function("glUniformMatrix3x2dv");
	gapil_gl_func_table[366] = gapil_load_function("glUniformMatrix3x4dv");
	gapil_gl_func_table[367] = gapil_load_function("glUniformMatrix4x2dv");
	gapil_gl_func_table[368] = gapil_load_function("glUniformMatrix4x3dv");
	gapil_gl_func_table[369] = gapil_load_function("glGetUniformdv");
	gapil_gl_func_table[370] = gapil_load_function("glGetSubroutineUniformLocation");
	gapil_gl_func_table[371] = gapil_load_function("glGetSubroutineIndex");
	gapil_gl_func_table[372] = gapil_load_function("glGetActiveSubroutineUniformiv");
	gapil_gl_func_table[373] = gapil_load_function("glGetActiveSubroutineUniformName");
	gapil_gl_func_table[374] = gapil_load_function("glGetActiveSubroutineName");
	gapil_gl_func_table[375] = gapil_load_function("glUniformSubroutinesuiv");
	gapil_gl_func_table[376] = gapil_load_function("glGetUniformSubroutineuiv");
	gapil_gl_func_table[377] = gapil_load_function("glGetProgramStageiv");
	gapil_gl_func_table[378] = gapil_load_function("glPatchParameteri");
	gapil_gl_func_table[379] = gapil_load_function("glPatchParameterfv");
	gapil_gl_func_table[380] = gapil_load_function("glBindTransformFeedback");
	gapil_gl_func_table[381] = gapil_load_function("glDeleteTransformFeedbacks");
	gapil_gl_func_table[382] = gapil_load_function("glGenTransformFeedbacks");
	gapil_gl_func_table[383] = gapil_load_function("glIsTransformFeedback");
	gapil_gl_func_table[384] = gapil_load_function("glPauseTransformFeedback");
	gapil_gl_func_table[385] = gapil_load_function("glResumeTransformFeedback");
	gapil_gl_func_table[386] = gapil_load_function("glDrawTransformFeedback");
	gapil_gl_func_table[387] = gapil_load_function("glDrawTransformFeedbackStream");
	gapil_gl_func_table[388] = gapil_load_function("glBeginQueryIndexed");
	gapil_gl_func_table[389] = gapil_load_function("glEndQueryIndexed");
	gapil_gl_func_table[390] = gapil_load_function("glGetQueryIndexediv");
	gapil_gl_func_table[391] = gapil_load_function("glReleaseShaderCompiler");
	gapil_gl_func_table[392] = gapil_load_function("glShaderBinary");
	gapil_gl_func_table[393] = gapil_load_function("glGetShaderPrecisionFormat");
	gapil_gl_func_table[394] = gapil_load_function("glDepthRangef");
	gapil_gl_func_table[395] = gapil_load_function("glClearDepthf");
	gapil_gl_func_table[396] = gapil_load_function("glGetProgramBinary");
	gapil_gl_func_table[397] = gapil_load_function("glProgramBinary");
	gapil_gl_func_table[398] = gapil_load_function("glProgramParameteri");
	gapil_gl_func_table[399] = gapil_load_function("glUseProgramStages");
	gapil_gl_func_table[400] = gapil_load_function("glActiveShaderProgram");
	gapil_gl_func_table[401] = gapil_load_function("glCreateShaderProgramv");
	gapil_gl_func_table[402] = gapil_load_function("glBindProgramPipeline");
	gapil_gl_func_table[403] = gapil_load_function("glDeleteProgramPipelines");
	gapil_gl_func_table[404] = gapil_load_function("glGenProgramPipelines");
	gapil_gl_func_table[405] = gapil_load_function("glIsProgramPipeline");
	gapil_gl_func_table[406] = gapil_load_function("glGetProgramPipelineiv");
	gapil_gl_func_table[407] = gapil_load_function("glProgramUniform1i");
	gapil_gl_func_table[408] = gapil_load_function("glProgramUniform1iv");
	gapil_gl_func_table[409] = gapil_load_function("glProgramUniform1f");
	gapil_gl_func_table[410] = gapil_load_function("glProgramUniform1fv");
	gapil_gl_func_table[411] = gapil_load_function("glProgramUniform1d");
	gapil_gl_func_table[412] = gapil_load_function("glProgramUniform1dv");
	gapil_gl_func_table[413] = gapil_load_function("glProgramUniform1ui");
	gapil_gl_func_table[414] = gapil_load_function("glProgramUniform1uiv");
	gapil_gl_func_table[415] = gapil_load_function("glProgramUniform2i");
	gapil_gl_func_table[416] = gapil_load_function("glProgramUniform2iv");
	gapil_gl_func_table[417] = gapil_load_function("glProgramUniform2f");
	gapil_gl_func_table[418] = gapil_load_function("glProgramUniform2fv");
	gapil_gl_func_table[419] = gapil_load_function("glProgramUniform2d");
	gapil_gl_func_table[420] = gapil_load_function("glProgramUniform2dv");
	gapil_gl_func_table[421] = gapil_load_function("glProgramUniform2ui");
	gapil_gl_func_table[422] = gapil_load_function("glProgramUniform2uiv");
	gapil_gl_func_table[423] = gapil_load_function("glProgramUniform3i");
	gapil_gl_func_table[424] = gapil_load_function("glProgramUniform3iv");
	gapil_gl_func_table[425] = gapil_load_function("glProgramUniform3f");
	gapil_gl_func_table[426] = gapil_load_function("glProgramUniform3fv");
	gapil_gl_func_table[427] = gapil_load_function("glProgramUniform3d");
	gapil_gl_func_table[428] = gapil_load_function("glProgramUniform3dv");
	gapil_gl_func_table[429] = gapil_load_function("glProgramUniform3ui");
	gapil_gl_func_table[430] = gapil_load_function("glProgramUniform3uiv");
	gapil_gl_func_table[431] = gapil_load_function("glProgramUniform4i");
	gapil_gl_func_table[432] = gapil_load_function("glProgramUniform4iv");
	gapil_gl_func_table[433] = gapil_load_function("glProgramUniform4f");
	gapil_gl_func_table[434] = gapil_load_function("glProgramUniform4fv");
	gapil_gl_func_table[435] = gapil_load_function("glProgramUniform4d");
	gapil_gl_func_table[436] = gapil_load_function("glProgramUniform4dv");
	gapil_gl_func_table[437] = gapil_load_function("glProgramUniform4ui");
	gapil_gl_func_table[438] = gapil_load_function("glProgramUniform4uiv");
	gapil_gl_func_table[439] = gapil_load_function("glProgramUniformMatrix2fv");
	gapil_gl_func_table[440] = gapil_load_function("glProgramUniformMatrix3fv");
	gapil_gl_func_table[441] = gapil_load_function("glProgramUniformMatrix4fv");
	gapil_gl_func_table[442] = gapil_load_function("glProgramUniformMatrix2dv");
	gapil_gl_func_table[443] = gapil_load_function("glProgramUniformMatrix3dv");
	gapil_gl_func_table[444] = gapil_load_function("glProgramUniformMatrix4dv");
	gapil_gl_func_table[445] = gapil_load_function("glProgramUniformMatrix2x3fv");
	gapil_gl_func_table[446] = gapil_load_function("glProgramUniformMatrix3x2fv");
	gapil_gl_func_table[447] = gapil_load_function("glProgramUniformMatrix2x4fv");
	gapil_gl_func_table[448] = gapil_load_function("glProgramUniformMatrix4x2fv");
	gapil_gl_func_table[449] = gapil_load_function("glProgramUniformMatrix3x4fv");
	gapil_gl_func_table[450] = gapil_load_function("glProgramUniformMatrix4x3fv");
	gapil_gl_func_table[451] = gapil_load_function("glProgramUniformMatrix2x3dv");
	gapil_gl_func_table[452] = gapil_load_function("glProgramUniformMatrix3x2dv");
	gapil_gl_func_table[453] = gapil_load_function("glProgramUniformMatrix2x4dv");
	gapil_gl_func_table[454] = gapil_load_function("glProgramUniformMatrix4x2dv");
	gapil_gl_func_table[455] = gapil_load_function("glProgramUniformMatrix3x4dv");
	gapil_gl_func_table[456] = gapil_load_function("glProgramUniformMatrix4x3dv");
	gapil_gl_func_table[457] = gapil_load_function("glValidateProgramPipeline");
	gapil_gl_func_table[458] = gapil_load_function("glGetProgramPipelineInfoLog");
	gapil_gl_func_table[459] = gapil_load_function("glVertexAttribL1d");
	gapil_gl_func_table[460] = gapil_load_function("glVertexAttribL2d");
	gapil_gl_func_table[461] = gapil_load_function("glVertexAttribL3d");
	gapil_gl_func_table[462] = gapil_load_function("glVertexAttribL4d");
	gapil_gl_func_table[463] = gapil_load_function("glVertexAttribL1dv");
	gapil_gl_func_table[464] = gapil_load_function("glVertexAttribL2dv");
	gapil_gl_func_table[465] = gapil_load_function("glVertexAttribL3dv");
	gapil_gl_func_table[466] = gapil_load_function("glVertexAttribL4dv");
	gapil_gl_func_table[467] = gapil_load_function("glVertexAttribLPointer");
	gapil_gl_func_table[468] = gapil_load_function("glGetVertexAttribLdv");
	gapil_gl_func_table[469] = gapil_load_function("glViewportArrayv");
	gapil_gl_func_table[470] = gapil_load_function("glViewportIndexedf");
	gapil_gl_func_table[471] = gapil_load_function("glViewportIndexedfv");
	gapil_gl_func_table[472] = gapil_load_function("glScissorArrayv");
	gapil_gl_func_table[473] = gapil_load_function("glScissorIndexed");
	gapil_gl_func_table[474] = gapil_load_function("glScissorIndexedv");
	gapil_gl_func_table[475] = gapil_load_function("glDepthRangeArrayv");
	gapil_gl_func_table[476] = gapil_load_function("glDepthRangeIndexed");
	gapil_gl_func_table[477] = gapil_load_function("glGetFloati_v");
	gapil_gl_func_table[478] = gapil_load_function("glGetDoublei_v");
	gapil_gl_func_table[479] = gapil_load_function("glDrawArraysInstancedBaseInstance");
	gapil_gl_func_table[480] = gapil_load_function("glDrawElementsInstancedBaseInstance");
	gapil_gl_func_table[481] = gapil_load_function("glDrawElementsInstancedBaseVertexBaseInstance");
	gapil_gl_func_table[482] = gapil_load_function("glGetInternalformativ");
	gapil_gl_func_table[483] = gapil_load_function("glGetActiveAtomicCounterBufferiv");
	gapil_gl_func_table[484] = gapil_load_function("glBindImageTexture");
	gapil_gl_func_table[485] = gapil_load_function("glMemoryBarrier");
	gapil_gl_func_table[486] = gapil_load_function("glTexStorage1D");
	gapil_gl_func_table[487] = gapil_load_function("glTexStorage2D");
	gapil_gl_func_table[488] = gapil_load_function("glTexStorage3D");
	gapil_gl_func_table[489] = gapil_load_function("glDrawTransformFeedbackInstanced");
	gapil_gl_func_table[490] = gapil_load_function("glDrawTransformFeedbackStreamInstanced");
	gapil_gl_func_table[491] = gapil_load_function("glClearBufferData");
	gapil_gl_func_table[492] = gapil_load_function("glClearBufferSubData");
	gapil_gl_func_table[493] = gapil_load_function("glDispatchCompute");
	gapil_gl_func_table[494] = gapil_load_function("glDispatchComputeIndirect");
	gapil_gl_func_table[495] = gapil_load_function("glCopyImageSubData");
	gapil_gl_func_table[496] = gapil_load_function("glFramebufferParameteri");
	gapil_gl_func_table[497] = gapil_load_function("glGetFramebufferParameteriv");
	gapil_gl_func_table[498] = gapil_load_function("glGetInternalformati64v");
	gapil_gl_func_table[499] = gapil_load_function("glInvalidateTexSubImage");
	gapil_gl_func_table[500] = gapil_load_function("glInvalidateTexImage");
	gapil_gl_func_table[501] = gapil_load_function("glInvalidateBufferSubData");
	gapil_gl_func_table[502] = gapil_load_function("glInvalidateBufferData");
	gapil_gl_func_table[503] = gapil_load_function("glInvalidateFramebuffer");
	gapil_gl_func_table[504] = gapil_load_function("glInvalidateSubFramebuffer");
	gapil_gl_func_table[505] = gapil_load_function("glMultiDrawArraysIndirect");
	gapil_gl_func_table[506] = gapil_load_function("glMultiDrawElementsIndirect");
	gapil_gl_func_table[507] = gapil_load_function("glGetProgramInterfaceiv");
	gapil_gl_func_table[508] = gapil_load_function("glGetProgramResourceIndex");
	gapil_gl_func_table[509] = gapil_load_function("glGetProgramResourceName");
	gapil_gl_func_table[510] = gapil_load_function("glGetProgramResourceiv");
	gapil_gl_func_table[511] = gapil_load_function("glGetProgramResourceLocation");
	gapil_gl_func_table[512] = gapil_load_function("glGetProgramResourceLocationIndex");
	gapil_gl_func_table[513] = gapil_load_function("glShaderStorageBlockBinding");
	gapil_gl_func_table[514] = gapil_load_function("glTexBufferRange");
	gapil_gl_func_table[515] = gapil_load_function("glTexStorage2DMultisample");
	gapil_gl_func_table[516] = gapil_load_function("glTexStorage3DMultisample");
	gapil_gl_func_table[517] = gapil_load_function("glTextureView");
	gapil_gl_func_table[518] = gapil_load_function("glBindVertexBuffer");
	gapil_gl_func_table[519] = gapil_load_function("glVertexAttribFormat");
	gapil_gl_func_table[520] = gapil_load_function("glVertexAttribIFormat");
	gapil_gl_func_table[521] = gapil_load_function("glVertexAttribLFormat");
	gapil_gl_func_table[522] = gapil_load_function("glVertexAttribBinding");
	gapil_gl_func_table[523] = gapil_load_function("glVertexBindingDivisor");
	gapil_gl_func_table[524] = gapil_load_function("glDebugMessageControl");
	gapil_gl_func_table[525] = gapil_load_function("glDebugMessageInsert");
	gapil_gl_func_table[526] = gapil_load_function("glDebugMessageCallback");
	gapil_gl_func_table[527] = gapil_load_function("glGetDebugMessageLog");
	gapil_gl_func_table[528] = gapil_load_function("glPushDebugGroup");
	gapil_gl_func_table[529] = gapil_load_function("glPopDebugGroup");
	gapil_gl_func_table[530] = gapil_load_function("glObjectLabel");
	gapil_gl_func_table[531] = gapil_load_function("glGetObjectLabel");
	gapil_gl_func_table[532] = gapil_load_function("glObjectPtrLabel");
	gapil_gl_func_table[533] = gapil_load_function("glGetObjectPtrLabel");
	gapil_gl_func_table[534] = gapil_load_function("glBufferStorage");
	gapil_gl_func_table[535] = gapil_load_function("glClearTexImage");
	gapil_gl_func_table[536] = gapil_load_function("glClearTexSubImage");
	gapil_gl_func_table[537] = gapil_load_function("glBindBuffersBase");
	gapil_gl_func_table[538] = gapil_load_function("glBindBuffersRange");
	gapil_gl_func_table[539] = gapil_load_function("glBindTextures");
	gapil_gl_func_table[540] = gapil_load_function("glBindSamplers");
	gapil_gl_func_table[541] = gapil_load_function("glBindImageTextures");
	gapil_gl_func_table[542] = gapil_load_function("glBindVertexBuffers");
	gapil_gl_func_table[543] = gapil_load_function("glClipControl");
	gapil_gl_func_table[544] = gapil_load_function("glCreateTransformFeedbacks");
	gapil_gl_func_table[545] = gapil_load_function("glTransformFeedbackBufferBase");
	gapil_gl_func_table[546] = gapil_load_function("glTransformFeedbackBufferRange");
	gapil_gl_func_table[547] = gapil_load_function("glGetTransformFeedbackiv");
	gapil_gl_func_table[548] = gapil_load_function("glGetTransformFeedbacki_v");
	gapil_gl_func_table[549] = gapil_load_function("glGetTransformFeedbacki64_v");
	gapil_gl_func_table[550] = gapil_load_function("glCreateBuffers");
	gapil_gl_func_table[551] = gapil_load_function("glNamedBufferStorage");
	gapil_gl_func_table[552] = gapil_load_function("glNamedBufferData");
	gapil_gl_func_table[553] = gapil_load_function("glNamedBufferSubData");
	gapil_gl_func_table[554] = gapil_load_function("glCopyNamedBufferSubData");
	gapil_gl_func_table[555] = gapil_load_function("glClearNamedBufferData");
	gapil_gl_func_table[556] = gapil_load_function("glClearNamedBufferSubData");
	gapil_gl_func_table[557] = gapil_load_function("glMapNamedBuffer");
	gapil_gl_func_table[558] = gapil_load_function("glMapNamedBufferRange");
	gapil_gl_func_table[559] = gapil_load_function("glUnmapNamedBuffer");
	gapil_gl_func_table[560] = gapil_load_function("glFlushMappedNamedBufferRange");
	gapil_gl_func_table[561] = gapil_load_function("glGetNamedBufferParameteriv");
	gapil_gl_func_table[562] = gapil_load_function("glGetNamedBufferParameteri64v");
	gapil_gl_func_table[563] = gapil_load_function("glGetNamedBufferPointerv");
	gapil_gl_func_table[564] = gapil_load_function("glGetNamedBufferSubData");
	gapil_gl_func_table[565] = gapil_load_function("glCreateFramebuffers");
	gapil_gl_func_table[566] = gapil_load_function("glNamedFramebufferRenderbuffer");
	gapil_gl_func_table[567] = gapil_load_function("glNamedFramebufferParameteri");
	gapil_gl_func_table[568] = gapil_load_function("glNamedFramebufferTexture");
	gapil_gl_func_table[569] = gapil_load_function("glNamedFramebufferTextureLayer");
	gapil_gl_func_table[570] = gapil_load_function("glNamedFramebufferDrawBuffer");
	gapil_gl_func_table[571] = gapil_load_function("glNamedFramebufferDrawBuffers");
	gapil_gl_func_table[572] = gapil_load_function("glNamedFramebufferReadBuffer");
	gapil_gl_func_table[573] = gapil_load_function("glInvalidateNamedFramebufferData");
	gapil_gl_func_table[574] = gapil_load_function("glInvalidateNamedFramebufferSubData");
	gapil_gl_func_table[575] = gapil_load_function("glClearNamedFramebufferiv");
	gapil_gl_func_table[576] = gapil_load_function("glClearNamedFramebufferuiv");
	gapil_gl_func_table[577] = gapil_load_function("glClearNamedFramebufferfv");
	gapil_gl_func_table[578] = gapil_load_function("glClearNamedFramebufferfi");
	gapil_gl_func_table[579] = gapil_load_function("glBlitNamedFramebuffer");
	gapil_gl_func_table[580] = gapil_load_function("glCheckNamedFramebufferStatus");
	gapil_gl_func_table[581] = gapil_load_function("glGetNamedFramebufferParameteriv");
	gapil_gl_func_table[582] = gapil_load_function("glGetNamedFramebufferAttachmentParameteriv");
	gapil_gl_func_table[583] = gapil_load_function("glCreateRenderbuffers");
	gapil_gl_func_table[584] = gapil_load_function("glNamedRenderbufferStorage");
	gapil_gl_func_table[585] = gapil_load_function("glNamedRenderbufferStorageMultisample");
	gapil_gl_func_table[586] = gapil_load_function("glGetNamedRenderbufferParameteriv");
	gapil_gl_func_table[587] = gapil_load_function("glCreateTextures");
	gapil_gl_func_table[588] = gapil_load_function("glTextureBuffer");
	gapil_gl_func_table[589] = gapil_load_function("glTextureBufferRange");
	gapil_gl_func_table[590] = gapil_load_function("glTextureStorage1D");
	gapil_gl_func_table[591] = gapil_load_function("glTextureStorage2D");
	gapil_gl_func_table[592] = gapil_load_function("glTextureStorage3D");
	gapil_gl_func_table[593] = gapil_load_function("glTextureStorage2DMultisample");
	gapil_gl_func_table[594] = gapil_load_function("glTextureStorage3DMultisample");
	gapil_gl_func_table[595] = gapil_load_function("glTextureSubImage1D");
	gapil_gl_func_table[596] = gapil_load_function("glTextureSubImage2D");
	gapil_gl_func_table[597] = gapil_load_function("glTextureSubImage3D");
	gapil_gl_func_table[598] = gapil_load_function("glCompressedTextureSubImage1D");
	gapil_gl_func_table[599] = gapil_load_function("glCompressedTextureSubImage2D");
	gapil_gl_func_table[600] = gapil_load_function("glCompressedTextureSubImage3D");
	gapil_gl_func_table[601] = gapil_load_function("glCopyTextureSubImage1D");
	gapil_gl_func_table[602] = gapil_load_function("glCopyTextureSubImage2D");
	gapil_gl_func_table[603] = gapil_load_function("glCopyTextureSubImage3D");
	gapil_gl_func_table[604] = gapil_load_function("glTextureParameterf");
	gapil_gl_func_table[605] = gapil_load_function("glTextureParameterfv");
	gapil_gl_func_table[606] = gapil_load_function("glTextureParameteri");
	gapil_gl_func_table[607] = gapil_load_function("glTextureParameterIiv");
	gapil_gl_func_table[608] = gapil_load_function("glTextureParameterIuiv");
	gapil_gl_func_table[609] = gapil_load_function("glTextureParameteriv");
	gapil_gl_func_table[610] = gapil_load_function("glGenerateTextureMipmap");
	gapil_gl_func_table[611] = gapil_load_function("glBindTextureUnit");
	gapil_gl_func_table[612] = gapil_load_function("glGetTextureImage");
	gapil_gl_func_table[613] = gapil_load_function("glGetCompressedTextureImage");
	gapil_gl_func_table[614] = gapil_load_function("glGetTextureLevelParameterfv");
	gapil_gl_func_table[615] = gapil_load_function("glGetTextureLevelParameteriv");
	gapil_gl_func_table[616] = gapil_load_function("glGetTextureParameterfv");
	gapil_gl_func_table[617] = gapil_load_function("glGetTextureParameterIiv");
	gapil_gl_func_table[618] = gapil_load_function("glGetTextureParameterIuiv");
	gapil_gl_func_table[619] = gapil_load_function("glGetTextureParameteriv");
	gapil_gl_func_table[620] = gapil_load_function("glCreateVertexArrays");
	gapil_gl_func_table[621] = gapil_load_function("glDisableVertexArrayAttrib");
	gapil_gl_func_table[622] = gapil_load_function("glEnableVertexArrayAttrib");
	gapil_gl_func_table[623] = gapil_load_function("glVertexArrayElementBuffer");
	gapil_gl_func_table[624] = gapil_load_function("glVertexArrayVertexBuffer");
	gapil_gl_func_table[625] = gapil_load_function("glVertexArrayVertexBuffers");
	gapil_gl_func_table[626] = gapil_load_function("glVertexArrayAttribBinding");
	gapil_gl_func_table[627] = gapil_load_function("glVertexArrayAttribFormat");
	gapil_gl_func_table[628] = gapil_load_function("glVertexArrayAttribIFormat");
	gapil_gl_func_table[629] = gapil_load_function("glVertexArrayAttribLFormat");
	gapil_gl_func_table[630] = gapil_load_function("glVertexArrayBindingDivisor");
	gapil_gl_func_table[631] = gapil_load_function("glGetVertexArrayiv");
	gapil_gl_func_table[632] = gapil_load_function("glGetVertexArrayIndexediv");
	gapil_gl_func_table[633] = gapil_load_function("glGetVertexArrayIndexed64iv");
	gapil_gl_func_table[634] = gapil_load_function("glCreateSamplers");
	gapil_gl_func_table[635] = gapil_load_function("glCreateProgramPipelines");
	gapil_gl_func_table[636] = gapil_load_function("glCreateQueries");
	gapil_gl_func_table[637] = gapil_load_function("glGetQueryBufferObjecti64v");
	gapil_gl_func_table[638] = gapil_load_function("glGetQueryBufferObjectiv");
	gapil_gl_func_table[639] = gapil_load_function("glGetQueryBufferObjectui64v");
	gapil_gl_func_table[640] = gapil_load_function("glGetQueryBufferObjectuiv");
	gapil_gl_func_table[641] = gapil_load_function("glMemoryBarrierByRegion");
	gapil_gl_func_table[642] = gapil_load_function("glGetTextureSubImage");
	gapil_gl_func_table[643] = gapil_load_function("glGetCompressedTextureSubImage");
	gapil_gl_func_table[644] = gapil_load_function("glGetGraphicsResetStatus");
	gapil_gl_func_table[645] = gapil_load_function("glGetnCompressedTexImage");
	gapil_gl_func_table[646] = gapil_load_function("glGetnTexImage");
	gapil_gl_func_table[647] = gapil_load_function("glGetnUniformdv");
	gapil_gl_func_table[648] = gapil_load_function("glGetnUniformfv");
	gapil_gl_func_table[649] = gapil_load_function("glGetnUniformiv");
	gapil_gl_func_table[650] = gapil_load_function("glGetnUniformuiv");
	gapil_gl_func_table[651] = gapil_load_function("glReadnPixels");
	gapil_gl_func_table[652] = gapil_load_function("glTextureBarrier");
	gapil_gl_func_table[653] = gapil_load_function("glSpecializeShader");
	gapil_gl_func_table[654] = gapil_load_function("glMultiDrawArraysIndirectCount");
	gapil_gl_func_table[655] = gapil_load_function("glMultiDrawElementsIndirectCount");
	gapil_gl_func_table[656] = gapil_load_function("glPolygonOffsetClamp");
	gapil_gl_func_table[657] = gapil_load_function("glPrimitiveBoundingBoxARB");
	gapil_gl_func_table[658] = gapil_load_function("glGetTextureHandleARB");
	gapil_gl_func_table[659] = gapil_load_function("glGetTextureSamplerHandleARB");
	gapil_gl_func_table[660] = gapil_load_function("glMakeTextureHandleResidentARB");
	gapil_gl_func_table[661] = gapil_load_function("glMakeTextureHandleNonResidentARB");
	gapil_gl_func_table[662] = gapil_load_function("glGetImageHandleARB");
	gapil_gl_func_table[663] = gapil_load_function("glMakeImageHandleResidentARB");
	gapil_gl_func_table[664] = gapil_load_function("glMakeImageHandleNonResidentARB");
	gapil_gl_func_table[665] = gapil_load_function("glUniformHandleui64ARB");
	gapil_gl_func_table[666] = gapil_load_function("glUniformHandleui64vARB");
	gapil_gl_func_table[667] = gapil_load_function("glProgramUniformHandleui64ARB");
	gapil_gl_func_table[668] = gapil_load_function("glProgramUniformHandleui64vARB");
	gapil_gl_func_table[669] = gapil_load_function("glIsTextureHandleResidentARB");
	gapil_gl_func_table[670] = gapil_load_function("glIsImageHandleResidentARB");
	gapil_gl_func_table[671] = gapil_load_function("glVertexAttribL1ui64ARB");
	gapil_gl_func_table[672] = gapil_load_function("glVertexAttribL1ui64vARB");
	gapil_gl_func_table[673] = gapil_load_function("glGetVertexAttribLui64vARB");
	gapil_gl_func_table[674] = gapil_load_function("glCreateSyncFromCLeventARB");
	gapil_gl_func_table[675] = gapil_load_function("glDispatchComputeGroupSizeARB");
	gapil_gl_func_table[676] = gapil_load_function("glDebugMessageControlARB");
	gapil_gl_func_table[677] = gapil_load_function("glDebugMessageInsertARB");
	gapil_gl_func_table[678] = gapil_load_function("glDebugMessageCallbackARB");
	gapil_gl_func_table[679] = gapil_load_function("glGetDebugMessageLogARB");
	gapil_gl_func_table[680] = gapil_load_function("glBlendEquationiARB");
	gapil_gl_func_table[681] = gapil_load_function("glBlendEquationSeparateiARB");
	gapil_gl_func_table[682] = gapil_load_function("glBlendFunciARB");
	gapil_gl_func_table[683] = gapil_load_function("glBlendFuncSeparateiARB");
	gapil_gl_func_table[684] = gapil_load_function("glDrawArraysInstancedARB");
	gapil_gl_func_table[685] = gapil_load_function("glDrawElementsInstancedARB");
	gapil_gl_func_table[686] = gapil_load_function("glProgramParameteriARB");
	gapil_gl_func_table[687] = gapil_load_function("glFramebufferTextureARB");
	gapil_gl_func_table[688] = gapil_load_function("glFramebufferTextureLayerARB");
	gapil_gl_func_table[689] = gapil_load_function("glFramebufferTextureFaceARB");
	gapil_gl_func_table[690] = gapil_load_function("glSpecializeShaderARB");
	gapil_gl_func_table[691] = gapil_load_function("glUniform1i64ARB");
	gapil_gl_func_table[692] = gapil_load_function("glUniform2i64ARB");
	gapil_gl_func_table[693] = gapil_load_function("glUniform3i64ARB");
	gapil_gl_func_table[694] = gapil_load_function("glUniform4i64ARB");
	gapil_gl_func_table[695] = gapil_load_function("glUniform1i64vARB");
	gapil_gl_func_table[696] = gapil_load_function("glUniform2i64vARB");
	gapil_gl_func_table[697] = gapil_load_function("glUniform3i64vARB");
	gapil_gl_func_table[698] = gapil_load_function("glUniform4i64vARB");
	gapil_gl_func_table[699] = gapil_load_function("glUniform1ui64ARB");
	gapil_gl_func_table[700] = gapil_load_function("glUniform2ui64ARB");
	gapil_gl_func_table[701] = gapil_load_function("glUniform3ui64ARB");
	gapil_gl_func_table[702] = gapil_load_function("glUniform4ui64ARB");
	gapil_gl_func_table[703] = gapil_load_function("glUniform1ui64vARB");
	gapil_gl_func_table[704] = gapil_load_function("glUniform2ui64vARB");
	gapil_gl_func_table[705] = gapil_load_function("glUniform3ui64vARB");
	gapil_gl_func_table[706] = gapil_load_function("glUniform4ui64vARB");
	gapil_gl_func_table[707] = gapil_load_function("glGetUniformi64vARB");
	gapil_gl_func_table[708] = gapil_load_function("glGetUniformui64vARB");
	gapil_gl_func_table[709] = gapil_load_function("glGetnUniformi64vARB");
	gapil_gl_func_table[710] = gapil_load_function("glGetnUniformui64vARB");
	gapil_gl_func_table[711] = gapil_load_function("glProgramUniform1i64ARB");
	gapil_gl_func_table[712] = gapil_load_function("glProgramUniform2i64ARB");
	gapil_gl_func_table[713] = gapil_load_function("glProgramUniform3i64ARB");
	gapil_gl_func_table[714] = gapil_load_function("glProgramUniform4i64ARB");
	gapil_gl_func_table[715] = gapil_load_function("glProgramUniform1i64vARB");
	gapil_gl_func_table[716] = gapil_load_function("glProgramUniform2i64vARB");
	gapil_gl_func_table[717] = gapil_load_function("glProgramUniform3i64vARB");
	gapil_gl_func_table[718] = gapil_load_function("glProgramUniform4i64vARB");
	gapil_gl_func_table[719] = gapil_load_function("glProgramUniform1ui64ARB");
	gapil_gl_func_table[720] = gapil_load_function("glProgramUniform2ui64ARB");
	gapil_gl_func_table[721] = gapil_load_function("glProgramUniform3ui64ARB");
	gapil_gl_func_table[722] = gapil_load_function("glProgramUniform4ui64ARB");
	gapil_gl_func_table[723] = gapil_load_function("glProgramUniform1ui64vARB");
	gapil_gl_func_table[724] = gapil_load_function("glProgramUniform2ui64vARB");
	gapil_gl_func_table[725] = gapil_load_function("glProgramUniform3ui64vARB");
	gapil_gl_func_table[726] = gapil_load_function("glProgramUniform4ui64vARB");
	gapil_gl_func_table[727] = gapil_load_function("glMultiDrawArraysIndirectCountARB");
	gapil_gl_func_table[728] = gapil_load_function("glMultiDrawElementsIndirectCountARB");
	gapil_gl_func_table[729] = gapil_load_function("glVertexAttribDivisorARB");
	gapil_gl_func_table[730] = gapil_load_function("glMaxShaderCompilerThreadsARB");
	gapil_gl_func_table[731] = gapil_load_function("glGetGraphicsResetStatusARB");
	gapil_gl_func_table[732] = gapil_load_function("glGetnTexImageARB");
	gapil_gl_func_table[733] = gapil_load_function("glReadnPixelsARB");
	gapil_gl_func_table[734] = gapil_load_function("glGetnCompressedTexImageARB");
	gapil_gl_func_table[735] = gapil_load_function("glGetnUniformfvARB");
	gapil_gl_func_table[736] = gapil_load_function("glGetnUniformivARB");
	gapil_gl_func_table[737] = gapil_load_function("glGetnUniformuivARB");
	gapil_gl_func_table[738] = gapil_load_function("glGetnUniformdvARB");
	gapil_gl_func_table[739] = gapil_load_function("glFramebufferSampleLocationsfvARB");
	gapil_gl_func_table[740] = gapil_load_function("glNamedFramebufferSampleLocationsfvARB");
	gapil_gl_func_table[741] = gapil_load_function("glEvaluateDepthValuesARB");
	gapil_gl_func_table[742] = gapil_load_function("glMinSampleShadingARB");
	gapil_gl_func_table[743] = gapil_load_function("glNamedStringARB");
	gapil_gl_func_table[744] = gapil_load_function("glDeleteNamedStringARB");
	gapil_gl_func_table[745] = gapil_load_function("glCompileShaderIncludeARB");
	gapil_gl_func_table[746] = gapil_load_function("glIsNamedStringARB");
	gapil_gl_func_table[747] = gapil_load_function("glGetNamedStringARB");
	gapil_gl_func_table[748] = gapil_load_function("glGetNamedStringivARB");
	gapil_gl_func_table[749] = gapil_load_function("glBufferPageCommitmentARB");
	gapil_gl_func_table[750] = gapil_load_function("glNamedBufferPageCommitmentEXT");
	gapil_gl_func_table[751] = gapil_load_function("glNamedBufferPageCommitmentARB");
	gapil_gl_func_table[752] = gapil_load_function("glTexPageCommitmentARB");
	gapil_gl_func_table[753] = gapil_load_function("glTexBufferARB");
	gapil_gl_func_table[754] = gapil_load_function("glDepthRangeArraydvNV");
	gapil_gl_func_table[755] = gapil_load_function("glDepthRangeIndexeddNV");
	gapil_gl_func_table[756] = gapil_load_function("glBlendBarrierKHR");
	gapil_gl_func_table[757] = gapil_load_function("glMaxShaderCompilerThreadsKHR");
	gapil_gl_func_table[758] = gapil_load_function("glRenderbufferStorageMultisampleAdvancedAMD");
	gapil_gl_func_table[759] = gapil_load_function("glNamedRenderbufferStorageMultisampleAdvancedAMD");
	gapil_gl_func_table[760] = gapil_load_function("glGetPerfMonitorGroupsAMD");
	gapil_gl_func_table[761] = gapil_load_function("glGetPerfMonitorCountersAMD");
	gapil_gl_func_table[762] = gapil_load_function("glGetPerfMonitorGroupStringAMD");
	gapil_gl_func_table[763] = gapil_load_function("glGetPerfMonitorCounterStringAMD");
	gapil_gl_func_table[764] = gapil_load_function("glGetPerfMonitorCounterInfoAMD");
	gapil_gl_func_table[765] = gapil_load_function("glGenPerfMonitorsAMD");
	gapil_gl_func_table[766] = gapil_load_function("glDeletePerfMonitorsAMD");
	gapil_gl_func_table[767] = gapil_load_function("glSelectPerfMonitorCountersAMD");
	gapil_gl_func_table[768] = gapil_load_function("glBeginPerfMonitorAMD");
	gapil_gl_func_table[769] = gapil_load_function("glEndPerfMonitorAMD");
	gapil_gl_func_table[770] = gapil_load_function("glGetPerfMonitorCounterDataAMD");
	gapil_gl_func_table[771] = gapil_load_function("glEGLImageTargetTexStorageEXT");
	gapil_gl_func_table[772] = gapil_load_function("glEGLImageTargetTextureStorageEXT");
	gapil_gl_func_table[773] = gapil_load_function("glLabelObjectEXT");
	gapil_gl_func_table[774] = gapil_load_function("glGetObjectLabelEXT");
	gapil_gl_func_table[775] = gapil_load_function("glInsertEventMarkerEXT");
	gapil_gl_func_table[776] = gapil_load_function("glPushGroupMarkerEXT");
	gapil_gl_func_table[777] = gapil_load_function("glPopGroupMarkerEXT");
	gapil_gl_func_table[778] = gapil_load_function("glMatrixLoadfEXT");
	gapil_gl_func_table[779] = gapil_load_function("glMatrixLoaddEXT");
	gapil_gl_func_table[780] = gapil_load_function("glMatrixMultfEXT");
	gapil_gl_func_table[781] = gapil_load_function("glMatrixMultdEXT");
	gapil_gl_func_table[782] = gapil_load_function("glMatrixLoadIdentityEXT");
	gapil_gl_func_table[783] = gapil_load_function("glMatrixRotatefEXT");
	gapil_gl_func_table[784] = gapil_load_function("glMatrixRotatedEXT");
	gapil_gl_func_table[785] = gapil_load_function("glMatrixScalefEXT");
	gapil_gl_func_table[786] = gapil_load_function("glMatrixScaledEXT");
	gapil_gl_func_table[787] = gapil_load_function("glMatrixTranslatefEXT");
	gapil_gl_func_table[788] = gapil_load_function("glMatrixTranslatedEXT");
	gapil_gl_func_table[789] = gapil_load_function("glMatrixFrustumEXT");
	gapil_gl_func_table[790] = gapil_load_function("glMatrixOrthoEXT");
	gapil_gl_func_table[791] = gapil_load_function("glMatrixPopEXT");
	gapil_gl_func_table[792] = gapil_load_function("glMatrixPushEXT");
	gapil_gl_func_table[793] = gapil_load_function("glClientAttribDefaultEXT");
	gapil_gl_func_table[794] = gapil_load_function("glPushClientAttribDefaultEXT");
	gapil_gl_func_table[795] = gapil_load_function("glTextureParameterfEXT");
	gapil_gl_func_table[796] = gapil_load_function("glTextureParameterfvEXT");
	gapil_gl_func_table[797] = gapil_load_function("glTextureParameteriEXT");
	gapil_gl_func_table[798] = gapil_load_function("glTextureParameterivEXT");
	gapil_gl_func_table[799] = gapil_load_function("glTextureImage1DEXT");
	gapil_gl_func_table[800] = gapil_load_function("glTextureImage2DEXT");
	gapil_gl_func_table[801] = gapil_load_function("glTextureSubImage1DEXT");
	gapil_gl_func_table[802] = gapil_load_function("glTextureSubImage2DEXT");
	gapil_gl_func_table[803] = gapil_load_function("glCopyTextureImage1DEXT");
	gapil_gl_func_table[804] = gapil_load_function("glCopyTextureImage2DEXT");
	gapil_gl_func_table[805] = gapil_load_function("glCopyTextureSubImage1DEXT");
	gapil_gl_func_table[806] = gapil_load_function("glCopyTextureSubImage2DEXT");
	gapil_gl_func_table[807] = gapil_load_function("glGetTextureImageEXT");
	gapil_gl_func_table[808] = gapil_load_function("glGetTextureParameterfvEXT");
	gapil_gl_func_table[809] = gapil_load_function("glGetTextureParameterivEXT");
	gapil_gl_func_table[810] = gapil_load_function("glGetTextureLevelParameterfvEXT");
	gapil_gl_func_table[811] = gapil_load_function("glGetTextureLevelParameterivEXT");
	gapil_gl_func_table[812] = gapil_load_function("glTextureImage3DEXT");
	gapil_gl_func_table[813] = gapil_load_function("glTextureSubImage3DEXT");
	gapil_gl_func_table[814] = gapil_load_function("glCopyTextureSubImage3DEXT");
	gapil_gl_func_table[815] = gapil_load_function("glBindMultiTextureEXT");
	gapil_gl_func_table[816] = gapil_load_function("glMultiTexCoordPointerEXT");
	gapil_gl_func_table[817] = gapil_load_function("glMultiTexEnvfEXT");
	gapil_gl_func_table[818] = gapil_load_function("glMultiTexEnvfvEXT");
	gapil_gl_func_table[819] = gapil_load_function("glMultiTexEnviEXT");
	gapil_gl_func_table[820] = gapil_load_function("glMultiTexEnvivEXT");
	gapil_gl_func_table[821] = gapil_load_function("glMultiTexGendEXT");
	gapil_gl_func_table[822] = gapil_load_function("glMultiTexGendvEXT");
	gapil_gl_func_table[823] = gapil_load_function("glMultiTexGenfEXT");
	gapil_gl_func_table[824] = gapil_load_function("glMultiTexGenfvEXT");
	gapil_gl_func_table[825] = gapil_load_function("glMultiTexGeniEXT");
	gapil_gl_func_table[826] = gapil_load_function("glMultiTexGenivEXT");
	gapil_gl_func_table[827] = gapil_load_function("glGetMultiTexEnvfvEXT");
	gapil_gl_func_table[828] = gapil_load_function("glGetMultiTexEnvivEXT");
	gapil_gl_func_table[829] = gapil_load_function("glGetMultiTexGendvEXT");
	gapil_gl_func_table[830] = gapil_load_function("glGetMultiTexGenfvEXT");
	gapil_gl_func_table[831] = gapil_load_function("glGetMultiTexGenivEXT");
	gapil_gl_func_table[832] = gapil_load_function("glMultiTexParameteriEXT");
	gapil_gl_func_table[833] = gapil_load_function("glMultiTexParameterivEXT");
	gapil_gl_func_table[834] = gapil_load_function("glMultiTexParameterfEXT");
	gapil_gl_func_table[835] = gapil_load_function("glMultiTexParameterfvEXT");
	gapil_gl_func_table[836] = gapil_load_function("glMultiTexImage1DEXT");
	gapil_gl_func_table[837] = gapil_load_function("glMultiTexImage2DEXT");
	gapil_gl_func_table[838] = gapil_load_function("glMultiTexSubImage1DEXT");
	gapil_gl_func_table[839] = gapil_load_function("glMultiTexSubImage2DEXT");
	gapil_gl_func_table[840] = gapil_load_function("glCopyMultiTexImage1DEXT");
	gapil_gl_func_table[841] = gapil_load_function("glCopyMultiTexImage2DEXT");
	gapil_gl_func_table[842] = gapil_load_function("glCopyMultiTexSubImage1DEXT");
	gapil_gl_func_table[843] = gapil_load_function("glCopyMultiTexSubImage2DEXT");
	gapil_gl_func_table[844] = gapil_load_function("glGetMultiTexImageEXT");
	gapil_gl_func_table[845] = gapil_load_function("glGetMultiTexParameterfvEXT");
	gapil_gl_func_table[846] = gapil_load_function("glGetMultiTexParameterivEXT");
	gapil_gl_func_table[847] = gapil_load_function("glGetMultiTexLevelParameterfvEXT");
	gapil_gl_func_table[848] = gapil_load_function("glGetMultiTexLevelParameterivEXT");
	gapil_gl_func_table[849] = gapil_load_function("glMultiTexImage3DEXT");
	gapil_gl_func_table[850] = gapil_load_function("glMultiTexSubImage3DEXT");
	gapil_gl_func_table[851] = gapil_load_function("glCopyMultiTexSubImage3DEXT");
	gapil_gl_func_table[852] = gapil_load_function("glEnableClientStateIndexedEXT");
	gapil_gl_func_table[853] = gapil_load_function("glDisableClientStateIndexedEXT");
	gapil_gl_func_table[854] = gapil_load_function("glGetFloatIndexedvEXT");
	gapil_gl_func_table[855] = gapil_load_function("glGetDoubleIndexedvEXT");
	gapil_gl_func_table[856] = gapil_load_function("glGetPointerIndexedvEXT");
	gapil_gl_func_table[857] = gapil_load_function("glEnableIndexedEXT");
	gapil_gl_func_table[858] = gapil_load_function("glDisableIndexedEXT");
	gapil_gl_func_table[859] = gapil_load_function("glIsEnabledIndexedEXT");
	gapil_gl_func_table[860] = gapil_load_function("glGetIntegerIndexedvEXT");
	gapil_gl_func_table[861] = gapil_load_function("glGetBooleanIndexedvEXT");
	gapil_gl_func_table[862] = gapil_load_function("glCompressedTextureImage3DEXT");
	gapil_gl_func_table[863] = gapil_load_function("glCompressedTextureImage2DEXT");
	gapil_gl_func_table[864] = gapil_load_function("glCompressedTextureImage1DEXT");
	gapil_gl_func_table[865] = gapil_load_function("glCompressedTextureSubImage3DEXT");
	gapil_gl_func_table[866] = gapil_load_function("glCompressedTextureSubImage2DEXT");
	gapil_gl_func_table[867] = gapil_load_function("glCompressedTextureSubImage1DEXT");
	gapil_gl_func_table[868] = gapil_load_function("glGetCompressedTextureImageEXT");
	gapil_gl_func_table[869] = gapil_load_function("glCompressedMultiTexImage3DEXT");
	gapil_gl_func_table[870] = gapil_load_function("glCompressedMultiTexImage2DEXT");
	gapil_gl_func_table[871] = gapil_load_function("glCompressedMultiTexImage1DEXT");
	gapil_gl_func_table[872] = gapil_load_function("glCompressedMultiTexSubImage3DEXT");
	gapil_gl_func_table[873] = gapil_load_function("glCompressedMultiTexSubImage2DEXT");
	gapil_gl_func_table[874] = gapil_load_function("glCompressedMultiTexSubImage1DEXT");
	gapil_gl_func_table[875] = gapil_load_function("glGetCompressedMultiTexImageEXT");
	gapil_gl_func_table[876] = gapil_load_function("glMatrixLoadTransposefEXT");
	gapil_gl_func_table[877] = gapil_load_function("glMatrixLoadTransposedEXT");
	gapil_gl_func_table[878] = gapil_load_function("glMatrixMultTransposefEXT");
	gapil_gl_func_table[879] = gapil_load_function("glMatrixMultTransposedEXT");
	gapil_gl_func_table[880] = gapil_load_function("glNamedBufferDataEXT");
	gapil_gl_func_table[881] = gapil_load_function("glNamedBufferSubDataEXT");
	gapil_gl_func_table[882] = gapil_load_function("glMapNamedBufferEXT");
	gapil_gl_func_table[883] = gapil_load_function("glUnmapNamedBufferEXT");
	gapil_gl_func_table[884] = gapil_load_function("glGetNamedBufferParameterivEXT");
	gapil_gl_func_table[885] = gapil_load_function("glGetNamedBufferPointervEXT");
	gapil_gl_func_table[886] = gapil_load_function("glGetNamedBufferSubDataEXT");
	gapil_gl_func_table[887] = gapil_load_function("glProgramUniform1fEXT");
	gapil_gl_func_table[888] = gapil_load_function("glProgramUniform2fEXT");
	gapil_gl_func_table[889] = gapil_load_function("glProgramUniform3fEXT");
	gapil_gl_func_table[890] = gapil_load_function("glProgramUniform4fEXT");
	gapil_gl_func_table[891] = gapil_load_function("glProgramUniform1iEXT");
	gapil_gl_func_table[892] = gapil_load_function("glProgramUniform2iEXT");
	gapil_gl_func_table[893] = gapil_load_function("glProgramUniform3iEXT");
	gapil_gl_func_table[894] = gapil_load_function("glProgramUniform4iEXT");
	gapil_gl_func_table[895] = gapil_load_function("glProgramUniform1fvEXT");
	gapil_gl_func_table[896] = gapil_load_function("glProgramUniform2fvEXT");
	gapil_gl_func_table[897] = gapil_load_function("glProgramUniform3fvEXT");
	gapil_gl_func_table[898] = gapil_load_function("glProgramUniform4fvEXT");
	gapil_gl_func_table[899] = gapil_load_function("glProgramUniform1ivEXT");
	gapil_gl_func_table[900] = gapil_load_function("glProgramUniform2ivEXT");
	gapil_gl_func_table[901] = gapil_load_function("glProgramUniform3ivEXT");
	gapil_gl_func_table[902] = gapil_load_function("glProgramUniform4ivEXT");
	gapil_gl_func_table[903] = gapil_load_function("glProgramUniformMatrix2fvEXT");
	gapil_gl_func_table[904] = gapil_load_function("glProgramUniformMatrix3fvEXT");
	gapil_gl_func_table[905] = gapil_load_function("glProgramUniformMatrix4fvEXT");
	gapil_gl_func_table[906] = gapil_load_function("glProgramUniformMatrix2x3fvEXT");
	gapil_gl_func_table[907] = gapil_load_function("glProgramUniformMatrix3x2fvEXT");
	gapil_gl_func_table[908] = gapil_load_function("glProgramUniformMatrix2x4fvEXT");
	gapil_gl_func_table[909] = gapil_load_function("glProgramUniformMatrix4x2fvEXT");
	gapil_gl_func_table[910] = gapil_load_function("glProgramUniformMatrix3x4fvEXT");
	gapil_gl_func_table[911] = gapil_load_function("glProgramUniformMatrix4x3fvEXT");
	gapil_gl_func_table[912] = gapil_load_function("glTextureBufferEXT");
	gapil_gl_func_table[913] = gapil_load_function("glMultiTexBufferEXT");
	gapil_gl_func_table[914] = gapil_load_function("glTextureParameterIivEXT");
	gapil_gl_func_table[915] = gapil_load_function("glTextureParameterIuivEXT");
	gapil_gl_func_table[916] = gapil_load_function("glGetTextureParameterIivEXT");
	gapil_gl_func_table[917] = gapil_load_function("glGetTextureParameterIuivEXT");
	gapil_gl_func_table[918] = gapil_load_function("glMultiTexParameterIivEXT");
	gapil_gl_func_table[919] = gapil_load_function("glMultiTexParameterIuivEXT");
	gapil_gl_func_table[920] = gapil_load_function("glGetMultiTexParameterIivEXT");
	gapil_gl_func_table[921] = gapil_load_function("glGetMultiTexParameterIuivEXT");
	gapil_gl_func_table[922] = gapil_load_function("glProgramUniform1uiEXT");
	gapil_gl_func_table[923] = gapil_load_function("glProgramUniform2uiEXT");
	gapil_gl_func_table[924] = gapil_load_function("glProgramUniform3uiEXT");
	gapil_gl_func_table[925] = gapil_load_function("glProgramUniform4uiEXT");
	gapil_gl_func_table[926] = gapil_load_function("glProgramUniform1uivEXT");
	gapil_gl_func_table[927] = gapil_load_function("glProgramUniform2uivEXT");
	gapil_gl_func_table[928] = gapil_load_function("glProgramUniform3uivEXT");
	gapil_gl_func_table[929] = gapil_load_function("glProgramUniform4uivEXT");
	gapil_gl_func_table[930] = gapil_load_function("glNamedProgramLocalParameters4fvEXT");
	gapil_gl_func_table[931] = gapil_load_function("glNamedProgramLocalParameterI4iEXT");
	gapil_gl_func_table[932] = gapil_load_function("glNamedProgramLocalParameterI4ivEXT");
	gapil_gl_func_table[933] = gapil_load_function("glNamedProgramLocalParametersI4ivEXT");
	gapil_gl_func_table[934] = gapil_load_function("glNamedProgramLocalParameterI4uiEXT");
	gapil_gl_func_table[935] = gapil_load_function("glNamedProgramLocalParameterI4uivEXT");
	gapil_gl_func_table[936] = gapil_load_function("glNamedProgramLocalParametersI4uivEXT");
	gapil_gl_func_table[937] = gapil_load_function("glGetNamedProgramLocalParameterIivEXT");
	gapil_gl_func_table[938] = gapil_load_function("glGetNamedProgramLocalParameterIuivEXT");
	gapil_gl_func_table[939] = gapil_load_function("glEnableClientStateiEXT");
	gapil_gl_func_table[940] = gapil_load_function("glDisableClientStateiEXT");
	gapil_gl_func_table[941] = gapil_load_function("glGetFloati_vEXT");
	gapil_gl_func_table[942] = gapil_load_function("glGetDoublei_vEXT");
	gapil_gl_func_table[943] = gapil_load_function("glGetPointeri_vEXT");
	gapil_gl_func_table[944] = gapil_load_function("glNamedProgramStringEXT");
	gapil_gl_func_table[945] = gapil_load_function("glNamedProgramLocalParameter4dEXT");
	gapil_gl_func_table[946] = gapil_load_function("glNamedProgramLocalParameter4dvEXT");
	gapil_gl_func_table[947] = gapil_load_function("glNamedProgramLocalParameter4fEXT");
	gapil_gl_func_table[948] = gapil_load_function("glNamedProgramLocalParameter4fvEXT");
	gapil_gl_func_table[949] = gapil_load_function("glGetNamedProgramLocalParameterdvEXT");
	gapil_gl_func_table[950] = gapil_load_function("glGetNamedProgramLocalParameterfvEXT");
	gapil_gl_func_table[951] = gapil_load_function("glGetNamedProgramivEXT");
	gapil_gl_func_table[952] = gapil_load_function("glGetNamedProgramStringEXT");
	gapil_gl_func_table[953] = gapil_load_function("glNamedRenderbufferStorageEXT");
	gapil_gl_func_table[954] = gapil_load_function("glGetNamedRenderbufferParameterivEXT");
	gapil_gl_func_table[955] = gapil_load_function("glNamedRenderbufferStorageMultisampleEXT");
	gapil_gl_func_table[956] = gapil_load_function("glNamedRenderbufferStorageMultisampleCoverageEXT");
	gapil_gl_func_table[957] = gapil_load_function("glCheckNamedFramebufferStatusEXT");
	gapil_gl_func_table[958] = gapil_load_function("glNamedFramebufferTexture1DEXT");
	gapil_gl_func_table[959] = gapil_load_function("glNamedFramebufferTexture2DEXT");
	gapil_gl_func_table[960] = gapil_load_function("glNamedFramebufferTexture3DEXT");
	gapil_gl_func_table[961] = gapil_load_function("glNamedFramebufferRenderbufferEXT");
	gapil_gl_func_table[962] = gapil_load_function("glGetNamedFramebufferAttachmentParameterivEXT");
	gapil_gl_func_table[963] = gapil_load_function("glGenerateTextureMipmapEXT");
	gapil_gl_func_table[964] = gapil_load_function("glGenerateMultiTexMipmapEXT");
	gapil_gl_func_table[965] = gapil_load_function("glFramebufferDrawBufferEXT");
	gapil_gl_func_table[966] = gapil_load_function("glFramebufferDrawBuffersEXT");
	gapil_gl_func_table[967] = gapil_load_function("glFramebufferReadBufferEXT");
	gapil_gl_func_table[968] = gapil_load_function("glGetFramebufferParameterivEXT");
	gapil_gl_func_table[969] = gapil_load_function("glNamedCopyBufferSubDataEXT");
	gapil_gl_func_table[970] = gapil_load_function("glNamedFramebufferTextureEXT");
	gapil_gl_func_table[971] = gapil_load_function("glNamedFramebufferTextureLayerEXT");
	gapil_gl_func_table[972] = gapil_load_function("glNamedFramebufferTextureFaceEXT");
	gapil_gl_func_table[973] = gapil_load_function("glTextureRenderbufferEXT");
	gapil_gl_func_table[974] = gapil_load_function("glMultiTexRenderbufferEXT");
	gapil_gl_func_table[975] = gapil_load_function("glVertexArrayVertexOffsetEXT");
	gapil_gl_func_table[976] = gapil_load_function("glVertexArrayColorOffsetEXT");
	gapil_gl_func_table[977] = gapil_load_function("glVertexArrayEdgeFlagOffsetEXT");
	gapil_gl_func_table[978] = gapil_load_function("glVertexArrayIndexOffsetEXT");
	gapil_gl_func_table[979] = gapil_load_function("glVertexArrayNormalOffsetEXT");
	gapil_gl_func_table[980] = gapil_load_function("glVertexArrayTexCoordOffsetEXT");
	gapil_gl_func_table[981] = gapil_load_function("glVertexArrayMultiTexCoordOffsetEXT");
	gapil_gl_func_table[982] = gapil_load_function("glVertexArrayFogCoordOffsetEXT");
	gapil_gl_func_table[983] = gapil_load_function("glVertexArraySecondaryColorOffsetEXT");
	gapil_gl_func_table[984] = gapil_load_function("glVertexArrayVertexAttribOffsetEXT");
	gapil_gl_func_table[985] = gapil_load_function("glVertexArrayVertexAttribIOffsetEXT");
	gapil_gl_func_table[986] = gapil_load_function("glEnableVertexArrayEXT");
	gapil_gl_func_table[987] = gapil_load_function("glDisableVertexArrayEXT");
	gapil_gl_func_table[988] = gapil_load_function("glEnableVertexArrayAttribEXT");
	gapil_gl_func_table[989] = gapil_load_function("glDisableVertexArrayAttribEXT");
	gapil_gl_func_table[990] = gapil_load_function("glGetVertexArrayIntegervEXT");
	gapil_gl_func_table[991] = gapil_load_function("glGetVertexArrayPointervEXT");
	gapil_gl_func_table[992] = gapil_load_function("glGetVertexArrayIntegeri_vEXT");
	gapil_gl_func_table[993] = gapil_load_function("glGetVertexArrayPointeri_vEXT");
	gapil_gl_func_table[994] = gapil_load_function("glMapNamedBufferRangeEXT");
	gapil_gl_func_table[995] = gapil_load_function("glFlushMappedNamedBufferRangeEXT");
	gapil_gl_func_table[996] = gapil_load_function("glNamedBufferStorageEXT");
	gapil_gl_func_table[997] = gapil_load_function("glClearNamedBufferDataEXT");
	gapil_gl_func_table[998] = gapil_load_function("glClearNamedBufferSubDataEXT");
	gapil_gl_func_table[999] = gapil_load_function("glNamedFramebufferParameteriEXT");
	gapil_gl_func_table[1000] = gapil_load_function("glGetNamedFramebufferParameterivEXT");
	gapil_gl_func_table[1001] = gapil_load_function("glProgramUniform1dEXT");
	gapil_gl_func_table[1002] = gapil_load_function("glProgramUniform2dEXT");
	gapil_gl_func_table[1003] = gapil_load_function("glProgramUniform3dEXT");
	gapil_gl_func_table[1004] = gapil_load_function("glProgramUniform4dEXT");
	gapil_gl_func_table[1005] = gapil_load_function("glProgramUniform1dvEXT");
	gapil_gl_func_table[1006] = gapil_load_function("glProgramUniform2dvEXT");
	gapil_gl_func_table[1007] = gapil_load_function("glProgramUniform3dvEXT");
	gapil_gl_func_table[1008] = gapil_load_function("glProgramUniform4dvEXT");
	gapil_gl_func_table[1009] = gapil_load_function("glProgramUniformMatrix2dvEXT");
	gapil_gl_func_table[1010] = gapil_load_function("glProgramUniformMatrix3dvEXT");
	gapil_gl_func_table[1011] = gapil_load_function("glProgramUniformMatrix4dvEXT");
	gapil_gl_func_table[1012] = gapil_load_function("glProgramUniformMatrix2x3dvEXT");
	gapil_gl_func_table[1013] = gapil_load_function("glProgramUniformMatrix2x4dvEXT");
	gapil_gl_func_table[1014] = gapil_load_function("glProgramUniformMatrix3x2dvEXT");
	gapil_gl_func_table[1015] = gapil_load_function("glProgramUniformMatrix3x4dvEXT");
	gapil_gl_func_table[1016] = gapil_load_function("glProgramUniformMatrix4x2dvEXT");
	gapil_gl_func_table[1017] = gapil_load_function("glProgramUniformMatrix4x3dvEXT");
	gapil_gl_func_table[1018] = gapil_load_function("glTextureBufferRangeEXT");
	gapil_gl_func_table[1019] = gapil_load_function("glTextureStorage1DEXT");
	gapil_gl_func_table[1020] = gapil_load_function("glTextureStorage2DEXT");
	gapil_gl_func_table[1021] = gapil_load_function("glTextureStorage3DEXT");
	gapil_gl_func_table[1022] = gapil_load_function("glTextureStorage2DMultisampleEXT");
	gapil_gl_func_table[1023] = gapil_load_function("glTextureStorage3DMultisampleEXT");
	gapil_gl_func_table[1024] = gapil_load_function("glVertexArrayBindVertexBufferEXT");
	gapil_gl_func_table[1025] = gapil_load_function("glVertexArrayVertexAttribFormatEXT");
	gapil_gl_func_table[1026] = gapil_load_function("glVertexArrayVertexAttribIFormatEXT");
	gapil_gl_func_table[1027] = gapil_load_function("glVertexArrayVertexAttribLFormatEXT");
	gapil_gl_func_table[1028] = gapil_load_function("glVertexArrayVertexAttribBindingEXT");
	gapil_gl_func_table[1029] = gapil_load_function("glVertexArrayVertexBindingDivisorEXT");
	gapil_gl_func_table[1030] = gapil_load_function("glVertexArrayVertexAttribLOffsetEXT");
	gapil_gl_func_table[1031] = gapil_load_function("glTexturePageCommitmentEXT");
	gapil_gl_func_table[1032] = gapil_load_function("glVertexArrayVertexAttribDivisorEXT");
	gapil_gl_func_table[1033] = gapil_load_function("glDrawArraysInstancedEXT");
	gapil_gl_func_table[1034] = gapil_load_function("glDrawElementsInstancedEXT");
	gapil_gl_func_table[1035] = gapil_load_function("glPolygonOffsetClampEXT");
	gapil_gl_func_table[1036] = gapil_load_function("glRasterSamplesEXT");
	gapil_gl_func_table[1037] = gapil_load_function("glUseShaderProgramEXT");
	gapil_gl_func_table[1038] = gapil_load_function("glActiveProgramEXT");
	gapil_gl_func_table[1039] = gapil_load_function("glCreateShaderProgramEXT");
	gapil_gl_func_table[1040] = gapil_load_function("glFramebufferFetchBarrierEXT");
	gapil_gl_func_table[1041] = gapil_load_function("glTexStorage1DEXT");
	gapil_gl_func_table[1042] = gapil_load_function("glTexStorage2DEXT");
	gapil_gl_func_table[1043] = gapil_load_function("glTexStorage3DEXT");
	gapil_gl_func_table[1044] = gapil_load_function("glWindowRectanglesEXT");
	gapil_gl_func_table[1045] = gapil_load_function("glApplyFramebufferAttachmentCMAAINTEL");
	gapil_gl_func_table[1046] = gapil_load_function("glBeginPerfQueryINTEL");
	gapil_gl_func_table[1047] = gapil_load_function("glCreatePerfQueryINTEL");
	gapil_gl_func_table[1048] = gapil_load_function("glDeletePerfQueryINTEL");
	gapil_gl_func_table[1049] = gapil_load_function("glEndPerfQueryINTEL");
	gapil_gl_func_table[1050] = gapil_load_function("glGetFirstPerfQueryIdINTEL");
	gapil_gl_func_table[1051] = gapil_load_function("glGetNextPerfQueryIdINTEL");
	gapil_gl_func_table[1052] = gapil_load_function("glGetPerfCounterInfoINTEL");
	gapil_gl_func_table[1053] = gapil_load_function("glGetPerfQueryDataINTEL");
	gapil_gl_func_table[1054] = gapil_load_function("glGetPerfQueryIdByNameINTEL");
	gapil_gl_func_table[1055] = gapil_load_function("glGetPerfQueryInfoINTEL");
	gapil_gl_func_table[1056] = gapil_load_function("glFramebufferParameteriMESA");
	gapil_gl_func_table[1057] = gapil_load_function("glGetFramebufferParameterivMESA");
	gapil_gl_func_table[1058] = gapil_load_function("glMultiDrawArraysIndirectBindlessNV");
	gapil_gl_func_table[1059] = gapil_load_function("glMultiDrawElementsIndirectBindlessNV");
	gapil_gl_func_table[1060] = gapil_load_function("glMultiDrawArraysIndirectBindlessCountNV");
	gapil_gl_func_table[1061] = gapil_load_function("glMultiDrawElementsIndirectBindlessCountNV");
	gapil_gl_func_table[1062] = gapil_load_function("glGetTextureHandleNV");
	gapil_gl_func_table[1063] = gapil_load_function("glGetTextureSamplerHandleNV");
	gapil_gl_func_table[1064] = gapil_load_function("glMakeTextureHandleResidentNV");
	gapil_gl_func_table[1065] = gapil_load_function("glMakeTextureHandleNonResidentNV");
	gapil_gl_func_table[1066] = gapil_load_function("glGetImageHandleNV");
	gapil_gl_func_table[1067] = gapil_load_function("glMakeImageHandleResidentNV");
	gapil_gl_func_table[1068] = gapil_load_function("glMakeImageHandleNonResidentNV");
	gapil_gl_func_table[1069] = gapil_load_function("glUniformHandleui64NV");
	gapil_gl_func_table[1070] = gapil_load_function("glUniformHandleui64vNV");
	gapil_gl_func_table[1071] = gapil_load_function("glProgramUniformHandleui64NV");
	gapil_gl_func_table[1072] = gapil_load_function("glProgramUniformHandleui64vNV");
	gapil_gl_func_table[1073] = gapil_load_function("glIsTextureHandleResidentNV");
	gapil_gl_func_table[1074] = gapil_load_function("glIsImageHandleResidentNV");
	gapil_gl_func_table[1075] = gapil_load_function("glBlendParameteriNV");
	gapil_gl_func_table[1076] = gapil_load_function("glBlendBarrierNV");
	gapil_gl_func_table[1077] = gapil_load_function("glViewportPositionWScaleNV");
	gapil_gl_func_table[1078] = gapil_load_function("glCreateStatesNV");
	gapil_gl_func_table[1079] = gapil_load_function("glDeleteStatesNV");
	gapil_gl_func_table[1080] = gapil_load_function("glIsStateNV");
	gapil_gl_func_table[1081] = gapil_load_function("glStateCaptureNV");
	gapil_gl_func_table[1082] = gapil_load_function("glGetCommandHeaderNV");
	gapil_gl_func_table[1083] = gapil_load_function("glGetStageIndexNV");
	gapil_gl_func_table[1084] = gapil_load_function("glDrawCommandsNV");
	gapil_gl_func_table[1085] = gapil_load_function("glDrawCommandsAddressNV");
	gapil_gl_func_table[1086] = gapil_load_function("glDrawCommandsStatesNV");
	gapil_gl_func_table[1087] = gapil_load_function("glDrawCommandsStatesAddressNV");
	gapil_gl_func_table[1088] = gapil_load_function("glCreateCommandListsNV");
	gapil_gl_func_table[1089] = gapil_load_function("glDeleteCommandListsNV");
	gapil_gl_func_table[1090] = gapil_load_function("glIsCommandListNV");
	gapil_gl_func_table[1091] = gapil_load_function("glListDrawCommandsStatesClientNV");
	gapil_gl_func_table[1092] = gapil_load_function("glCommandListSegmentsNV");
	gapil_gl_func_table[1093] = gapil_load_function("glCompileCommandListNV");
	gapil_gl_func_table[1094] = gapil_load_function("glCallCommandListNV");
	gapil_gl_func_table[1095] = gapil_load_function("glBeginConditionalRenderNV");
	gapil_gl_func_table[1096] = gapil_load_function("glEndConditionalRenderNV");
	gapil_gl_func_table[1097] = gapil_load_function("glSubpixelPrecisionBiasNV");
	gapil_gl_func_table[1098] = gapil_load_function("glConservativeRasterParameterfNV");
	gapil_gl_func_table[1099] = gapil_load_function("glConservativeRasterParameteriNV");
	gapil_gl_func_table[1100] = gapil_load_function("glDepthRangedNV");
	gapil_gl_func_table[1101] = gapil_load_function("glClearDepthdNV");
	gapil_gl_func_table[1102] = gapil_load_function("glDepthBoundsdNV");
	gapil_gl_func_table[1103] = gapil_load_function("glDrawVkImageNV");
	gapil_gl_func_table[1104] = gapil_load_function("glGetVkProcAddrNV");
	gapil_gl_func_table[1105] = gapil_load_function("glWaitVkSemaphoreNV");
	gapil_gl_func_table[1106] = gapil_load_function("glSignalVkSemaphoreNV");
	gapil_gl_func_table[1107] = gapil_load_function("glSignalVkFenceNV");
	gapil_gl_func_table[1108] = gapil_load_function("glFragmentCoverageColorNV");
	gapil_gl_func_table[1109] = gapil_load_function("glCoverageModulationTableNV");
	gapil_gl_func_table[1110] = gapil_load_function("glGetCoverageModulationTableNV");
	gapil_gl_func_table[1111] = gapil_load_function("glCoverageModulationNV");
	gapil_gl_func_table[1112] = gapil_load_function("glRenderbufferStorageMultisampleCoverageNV");
	gapil_gl_func_table[1113] = gapil_load_function("glUniform1i64NV");
	gapil_gl_func_table[1114] = gapil_load_function("glUniform2i64NV");
	gapil_gl_func_table[1115] = gapil_load_function("glUniform3i64NV");
	gapil_gl_func_table[1116] = gapil_load_function("glUniform4i64NV");
	gapil_gl_func_table[1117] = gapil_load_function("glUniform1i64vNV");
	gapil_gl_func_table[1118] = gapil_load_function("glUniform2i64vNV");
	gapil_gl_func_table[1119] = gapil_load_function("glUniform3i64vNV");
	gapil_gl_func_table[1120] = gapil_load_function("glUniform4i64vNV");
	gapil_gl_func_table[1121] = gapil_load_function("glUniform1ui64NV");
	gapil_gl_func_table[1122] = gapil_load_function("glUniform2ui64NV");
	gapil_gl_func_table[1123] = gapil_load_function("glUniform3ui64NV");
	gapil_gl_func_table[1124] = gapil_load_function("glUniform4ui64NV");
	gapil_gl_func_table[1125] = gapil_load_function("glUniform1ui64vNV");
	gapil_gl_func_table[1126] = gapil_load_function("glUniform2ui64vNV");
	gapil_gl_func_table[1127] = gapil_load_function("glUniform3ui64vNV");
	gapil_gl_func_table[1128] = gapil_load_function("glUniform4ui64vNV");
	gapil_gl_func_table[1129] = gapil_load_function("glGetUniformi64vNV");
	gapil_gl_func_table[1130] = gapil_load_function("glProgramUniform1i64NV");
	gapil_gl_func_table[1131] = gapil_load_function("glProgramUniform2i64NV");
	gapil_gl_func_table[1132] = gapil_load_function("glProgramUniform3i64NV");
	gapil_gl_func_table[1133] = gapil_load_function("glProgramUniform4i64NV");
	gapil_gl_func_table[1134] = gapil_load_function("glProgramUniform1i64vNV");
	gapil_gl_func_table[1135] = gapil_load_function("glProgramUniform2i64vNV");
	gapil_gl_func_table[1136] = gapil_load_function("glProgramUniform3i64vNV");
	gapil_gl_func_table[1137] = gapil_load_function("glProgramUniform4i64vNV");
	gapil_gl_func_table[1138] = gapil_load_function("glProgramUniform1ui64NV");
	gapil_gl_func_table[1139] = gapil_load_function("glProgramUniform2ui64NV");
	gapil_gl_func_table[1140] = gapil_load_function("glProgramUniform3ui64NV");
	gapil_gl_func_table[1141] = gapil_load_function("glProgramUniform4ui64NV");
	gapil_gl_func_table[1142] = gapil_load_function("glProgramUniform1ui64vNV");
	gapil_gl_func_table[1143] = gapil_load_function("glProgramUniform2ui64vNV");
	gapil_gl_func_table[1144] = gapil_load_function("glProgramUniform3ui64vNV");
	gapil_gl_func_table[1145] = gapil_load_function("glProgramUniform4ui64vNV");
	gapil_gl_func_table[1146] = gapil_load_function("glGetInternalformatSampleivNV");
	gapil_gl_func_table[1147] = gapil_load_function("glGetMemoryObjectDetachedResourcesuivNV");
	gapil_gl_func_table[1148] = gapil_load_function("glResetMemoryObjectParameterNV");
	gapil_gl_func_table[1149] = gapil_load_function("glTexAttachMemoryNV");
	gapil_gl_func_table[1150] = gapil_load_function("glBufferAttachMemoryNV");
	gapil_gl_func_table[1151] = gapil_load_function("glTextureAttachMemoryNV");
	gapil_gl_func_table[1152] = gapil_load_function("glNamedBufferAttachMemoryNV");
	gapil_gl_func_table[1153] = gapil_load_function("glBufferPageCommitmentMemNV");
	gapil_gl_func_table[1154] = gapil_load_function("glTexPageCommitmentMemNV");
	gapil_gl_func_table[1155] = gapil_load_function("glNamedBufferPageCommitmentMemNV");
	gapil_gl_func_table[1156] = gapil_load_function("glTexturePageCommitmentMemNV");
	gapil_gl_func_table[1157] = gapil_load_function("glDrawMeshTasksNV");
	gapil_gl_func_table[1158] = gapil_load_function("glDrawMeshTasksIndirectNV");
	gapil_gl_func_table[1159] = gapil_load_function("glMultiDrawMeshTasksIndirectNV");
	gapil_gl_func_table[1160] = gapil_load_function("glMultiDrawMeshTasksIndirectCountNV");
	gapil_gl_func_table[1161] = gapil_load_function("glGenPathsNV");
	gapil_gl_func_table[1162] = gapil_load_function("glDeletePathsNV");
	gapil_gl_func_table[1163] = gapil_load_function("glIsPathNV");
	gapil_gl_func_table[1164] = gapil_load_function("glPathCommandsNV");
	gapil_gl_func_table[1165] = gapil_load_function("glPathCoordsNV");
	gapil_gl_func_table[1166] = gapil_load_function("glPathSubCommandsNV");
	gapil_gl_func_table[1167] = gapil_load_function("glPathSubCoordsNV");
	gapil_gl_func_table[1168] = gapil_load_function("glPathStringNV");
	gapil_gl_func_table[1169] = gapil_load_function("glPathGlyphsNV");
	gapil_gl_func_table[1170] = gapil_load_function("glPathGlyphRangeNV");
	gapil_gl_func_table[1171] = gapil_load_function("glWeightPathsNV");
	gapil_gl_func_table[1172] = gapil_load_function("glCopyPathNV");
	gapil_gl_func_table[1173] = gapil_load_function("glInterpolatePathsNV");
	gapil_gl_func_table[1174] = gapil_load_function("glTransformPathNV");
	gapil_gl_func_table[1175] = gapil_load_function("glPathParameterivNV");
	gapil_gl_func_table[1176] = gapil_load_function("glPathParameteriNV");
	gapil_gl_func_table[1177] = gapil_load_function("glPathParameterfvNV");
	gapil_gl_func_table[1178] = gapil_load_function("glPathParameterfNV");
	gapil_gl_func_table[1179] = gapil_load_function("glPathDashArrayNV");
	gapil_gl_func_table[1180] = gapil_load_function("glPathStencilFuncNV");
	gapil_gl_func_table[1181] = gapil_load_function("glPathStencilDepthOffsetNV");
	gapil_gl_func_table[1182] = gapil_load_function("glStencilFillPathNV");
	gapil_gl_func_table[1183] = gapil_load_function("glStencilStrokePathNV");
	gapil_gl_func_table[1184] = gapil_load_function("glStencilFillPathInstancedNV");
	gapil_gl_func_table[1185] = gapil_load_function("glStencilStrokePathInstancedNV");
	gapil_gl_func_table[1186] = gapil_load_function("glPathCoverDepthFuncNV");
	gapil_gl_func_table[1187] = gapil_load_function("glCoverFillPathNV");
	gapil_gl_func_table[1188] = gapil_load_function("glCoverStrokePathNV");
	gapil_gl_func_table[1189] = gapil_load_function("glCoverFillPathInstancedNV");
	gapil_gl_func_table[1190] = gapil_load_function("glCoverStrokePathInstancedNV");
	gapil_gl_func_table[1191] = gapil_load_function("glGetPathParameterivNV");
	gapil_gl_func_table[1192] = gapil_load_function("glGetPathParameterfvNV");
	gapil_gl_func_table[1193] = gapil_load_function("glGetPathCommandsNV");
	gapil_gl_func_table[1194] = gapil_load_function("glGetPathCoordsNV");
	gapil_gl_func_table[1195] = gapil_load_function("glGetPathDashArrayNV");
	gapil_gl_func_table[1196] = gapil_load_function("glGetPathMetricsNV");
	gapil_gl_func_table[1197] = gapil_load_function("glGetPathMetricRangeNV");
	gapil_gl_func_table[1198] = gapil_load_function("glGetPathSpacingNV");
	gapil_gl_func_table[1199] = gapil_load_function("glIsPointInFillPathNV");
	gapil_gl_func_table[1200] = gapil_load_function("glIsPointInStrokePathNV");
	gapil_gl_func_table[1201] = gapil_load_function("glGetPathLengthNV");
	gapil_gl_func_table[1202] = gapil_load_function("glPointAlongPathNV");
	gapil_gl_func_table[1203] = gapil_load_function("glMatrixLoad3x2fNV");
	gapil_gl_func_table[1204] = gapil_load_function("glMatrixLoad3x3fNV");
	gapil_gl_func_table[1205] = gapil_load_function("glMatrixLoadTranspose3x3fNV");
	gapil_gl_func_table[1206] = gapil_load_function("glMatrixMult3x2fNV");
	gapil_gl_func_table[1207] = gapil_load_function("glMatrixMult3x3fNV");
	gapil_gl_func_table[1208] = gapil_load_function("glMatrixMultTranspose3x3fNV");
	gapil_gl_func_table[1209] = gapil_load_function("glStencilThenCoverFillPathNV");
	gapil_gl_func_table[1210] = gapil_load_function("glStencilThenCoverStrokePathNV");
	gapil_gl_func_table[1211] = gapil_load_function("glStencilThenCoverFillPathInstancedNV");
	gapil_gl_func_table[1212] = gapil_load_function("glStencilThenCoverStrokePathInstancedNV");
	gapil_gl_func_table[1213] = gapil_load_function("glPathGlyphIndexRangeNV");
	gapil_gl_func_table[1214] = gapil_load_function("glPathGlyphIndexArrayNV");
	gapil_gl_func_table[1215] = gapil_load_function("glPathMemoryGlyphIndexArrayNV");
	gapil_gl_func_table[1216] = gapil_load_function("glProgramPathFragmentInputGenNV");
	gapil_gl_func_table[1217] = gapil_load_function("glGetProgramResourcefvNV");
	gapil_gl_func_table[1218] = gapil_load_function("glFramebufferSampleLocationsfvNV");
	gapil_gl_func_table[1219] = gapil_load_function("glNamedFramebufferSampleLocationsfvNV");
	gapil_gl_func_table[1220] = gapil_load_function("glResolveDepthValuesNV");
	gapil_gl_func_table[1221] = gapil_load_function("glScissorExclusiveNV");
	gapil_gl_func_table[1222] = gapil_load_function("glScissorExclusiveArrayvNV");
	gapil_gl_func_table[1223] = gapil_load_function("glMakeBufferResidentNV");
	gapil_gl_func_table[1224] = gapil_load_function("glMakeBufferNonResidentNV");
	gapil_gl_func_table[1225] = gapil_load_function("glIsBufferResidentNV");
	gapil_gl_func_table[1226] = gapil_load_function("glMakeNamedBufferResidentNV");
	gapil_gl_func_table[1227] = gapil_load_function("glMakeNamedBufferNonResidentNV");
	gapil_gl_func_table[1228] = gapil_load_function("glIsNamedBufferResidentNV");
	gapil_gl_func_table[1229] = gapil_load_function("glGetBufferParameterui64vNV");
	gapil_gl_func_table[1230] = gapil_load_function("glGetNamedBufferParameterui64vNV");
	gapil_gl_func_table[1231] = gapil_load_function("glGetIntegerui64vNV");
	gapil_gl_func_table[1232] = gapil_load_function("glUniformui64NV");
	gapil_gl_func_table[1233] = gapil_load_function("glUniformui64vNV");
	gapil_gl_func_table[1234] = gapil_load_function("glGetUniformui64vNV");
	gapil_gl_func_table[1235] = gapil_load_function("glProgramUniformui64NV");
	gapil_gl_func_table[1236] = gapil_load_function("glProgramUniformui64vNV");
	gapil_gl_func_table[1237] = gapil_load_function("glBindShadingRateImageNV");
	gapil_gl_func_table[1238] = gapil_load_function("glGetShadingRateImagePaletteNV");
	gapil_gl_func_table[1239] = gapil_load_function("glGetShadingRateSampleLocationivNV");
	gapil_gl_func_table[1240] = gapil_load_function("glShadingRateImageBarrierNV");
	gapil_gl_func_table[1241] = gapil_load_function("glShadingRateImagePaletteNV");
	gapil_gl_func_table[1242] = gapil_load_function("glShadingRateSampleOrderNV");
	gapil_gl_func_table[1243] = gapil_load_function("glShadingRateSampleOrderCustomNV");
	gapil_gl_func_table[1244] = gapil_load_function("glTextureBarrierNV");
	gapil_gl_func_table[1245] = gapil_load_function("glVertexAttribL1i64NV");
	gapil_gl_func_table[1246] = gapil_load_function("glVertexAttribL2i64NV");
	gapil_gl_func_table[1247] = gapil_load_function("glVertexAttribL3i64NV");
	gapil_gl_func_table[1248] = gapil_load_function("glVertexAttribL4i64NV");
	gapil_gl_func_table[1249] = gapil_load_function("glVertexAttribL1i64vNV");
	gapil_gl_func_table[1250] = gapil_load_function("glVertexAttribL2i64vNV");
	gapil_gl_func_table[1251] = gapil_load_function("glVertexAttribL3i64vNV");
	gapil_gl_func_table[1252] = gapil_load_function("glVertexAttribL4i64vNV");
	gapil_gl_func_table[1253] = gapil_load_function("glVertexAttribL1ui64NV");
	gapil_gl_func_table[1254] = gapil_load_function("glVertexAttribL2ui64NV");
	gapil_gl_func_table[1255] = gapil_load_function("glVertexAttribL3ui64NV");
	gapil_gl_func_table[1256] = gapil_load_function("glVertexAttribL4ui64NV");
	gapil_gl_func_table[1257] = gapil_load_function("glVertexAttribL1ui64vNV");
	gapil_gl_func_table[1258] = gapil_load_function("glVertexAttribL2ui64vNV");
	gapil_gl_func_table[1259] = gapil_load_function("glVertexAttribL3ui64vNV");
	gapil_gl_func_table[1260] = gapil_load_function("glVertexAttribL4ui64vNV");
	gapil_gl_func_table[1261] = gapil_load_function("glGetVertexAttribLi64vNV");
	gapil_gl_func_table[1262] = gapil_load_function("glGetVertexAttribLui64vNV");
	gapil_gl_func_table[1263] = gapil_load_function("glVertexAttribLFormatNV");
	gapil_gl_func_table[1264] = gapil_load_function("glBufferAddressRangeNV");
	gapil_gl_func_table[1265] = gapil_load_function("glVertexFormatNV");
	gapil_gl_func_table[1266] = gapil_load_function("glNormalFormatNV");
	gapil_gl_func_table[1267] = gapil_load_function("glColorFormatNV");
	gapil_gl_func_table[1268] = gapil_load_function("glIndexFormatNV");
	gapil_gl_func_table[1269] = gapil_load_function("glTexCoordFormatNV");
	gapil_gl_func_table[1270] = gapil_load_function("glEdgeFlagFormatNV");
	gapil_gl_func_table[1271] = gapil_load_function("glSecondaryColorFormatNV");
	gapil_gl_func_table[1272] = gapil_load_function("glFogCoordFormatNV");
	gapil_gl_func_table[1273] = gapil_load_function("glVertexAttribFormatNV");
	gapil_gl_func_table[1274] = gapil_load_function("glVertexAttribIFormatNV");
	gapil_gl_func_table[1275] = gapil_load_function("glGetIntegerui64i_vNV");
	gapil_gl_func_table[1276] = gapil_load_function("glViewportSwizzleNV");
	gapil_gl_func_table[1277] = gapil_load_function("glFramebufferTextureMultiviewOVR");
	gapil_gl_func_table[1278] = gapil_load_function("glNamedFramebufferTextureMultiviewOVR");

	gapil_load_extensions();
}

GLAPI void APIENTRY glCullFace(GLenum mode)
{
	PFNGLCULLFACEPROC internal_f = (PFNGLCULLFACEPROC)gapil_gl_func_table[0];
	assert(internal_f != NULL);
	return internal_f(mode);
}

GLAPI void APIENTRY glFrontFace(GLenum mode)
{
	PFNGLFRONTFACEPROC internal_f = (PFNGLFRONTFACEPROC)gapil_gl_func_table[1];
	assert(internal_f != NULL);
	return internal_f(mode);
}

GLAPI void APIENTRY glHint(GLenum target, GLenum mode)
{
	PFNGLHINTPROC internal_f = (PFNGLHINTPROC)gapil_gl_func_table[2];
	assert(internal_f != NULL);
	return internal_f(target, mode);
}

GLAPI void APIENTRY glLineWidth(GLfloat width)
{
	PFNGLLINEWIDTHPROC internal_f = (PFNGLLINEWIDTHPROC)gapil_gl_func_table[3];
	assert(internal_f != NULL);
	return internal_f(width);
}

GLAPI void APIENTRY glPointSize(GLfloat size)
{
	PFNGLPOINTSIZEPROC internal_f = (PFNGLPOINTSIZEPROC)gapil_gl_func_table[4];
	assert(internal_f != NULL);
	return internal_f(size);
}

GLAPI void APIENTRY glPolygonMode(GLenum face, GLenum mode)
{
	PFNGLPOLYGONMODEPROC internal_f = (PFNGLPOLYGONMODEPROC)gapil_gl_func_table[5];
	assert(internal_f != NULL);
	return internal_f(face, mode);
}

GLAPI void APIENTRY glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLSCISSORPROC internal_f = (PFNGLSCISSORPROC)gapil_gl_func_table[6];
	assert(internal_f != NULL);
	return internal_f(x, y, width, height);
}

GLAPI void APIENTRY glTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
	PFNGLTEXPARAMETERFPROC internal_f = (PFNGLTEXPARAMETERFPROC)gapil_gl_func_table[7];
	assert(internal_f != NULL);
	return internal_f(target, pname, param);
}

GLAPI void APIENTRY glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params)
{
	PFNGLTEXPARAMETERFVPROC internal_f = (PFNGLTEXPARAMETERFVPROC)gapil_gl_func_table[8];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glTexParameteri(GLenum target, GLenum pname, GLint param)
{
	PFNGLTEXPARAMETERIPROC internal_f = (PFNGLTEXPARAMETERIPROC)gapil_gl_func_table[9];
	assert(internal_f != NULL);
	return internal_f(target, pname, param);
}

GLAPI void APIENTRY glTexParameteriv(GLenum target, GLenum pname, const GLint * params)
{
	PFNGLTEXPARAMETERIVPROC internal_f = (PFNGLTEXPARAMETERIVPROC)gapil_gl_func_table[10];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXIMAGE1DPROC internal_f = (PFNGLTEXIMAGE1DPROC)gapil_gl_func_table[11];
	assert(internal_f != NULL);
	return internal_f(target, level, internalformat, width, border, format, type, pixels);
}

GLAPI void APIENTRY glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXIMAGE2DPROC internal_f = (PFNGLTEXIMAGE2DPROC)gapil_gl_func_table[12];
	assert(internal_f != NULL);
	return internal_f(target, level, internalformat, width, height, border, format, type, pixels);
}

GLAPI void APIENTRY glDrawBuffer(GLenum buf)
{
	PFNGLDRAWBUFFERPROC internal_f = (PFNGLDRAWBUFFERPROC)gapil_gl_func_table[13];
	assert(internal_f != NULL);
	return internal_f(buf);
}

GLAPI void APIENTRY glClear(GLbitfield mask)
{
	PFNGLCLEARPROC internal_f = (PFNGLCLEARPROC)gapil_gl_func_table[14];
	assert(internal_f != NULL);
	return internal_f(mask);
}

GLAPI void APIENTRY glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	PFNGLCLEARCOLORPROC internal_f = (PFNGLCLEARCOLORPROC)gapil_gl_func_table[15];
	assert(internal_f != NULL);
	return internal_f(red, green, blue, alpha);
}

GLAPI void APIENTRY glClearStencil(GLint s)
{
	PFNGLCLEARSTENCILPROC internal_f = (PFNGLCLEARSTENCILPROC)gapil_gl_func_table[16];
	assert(internal_f != NULL);
	return internal_f(s);
}

GLAPI void APIENTRY glClearDepth(GLdouble depth)
{
	PFNGLCLEARDEPTHPROC internal_f = (PFNGLCLEARDEPTHPROC)gapil_gl_func_table[17];
	assert(internal_f != NULL);
	return internal_f(depth);
}

GLAPI void APIENTRY glStencilMask(GLuint mask)
{
	PFNGLSTENCILMASKPROC internal_f = (PFNGLSTENCILMASKPROC)gapil_gl_func_table[18];
	assert(internal_f != NULL);
	return internal_f(mask);
}

GLAPI void APIENTRY glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
	PFNGLCOLORMASKPROC internal_f = (PFNGLCOLORMASKPROC)gapil_gl_func_table[19];
	assert(internal_f != NULL);
	return internal_f(red, green, blue, alpha);
}

GLAPI void APIENTRY glDepthMask(GLboolean flag)
{
	PFNGLDEPTHMASKPROC internal_f = (PFNGLDEPTHMASKPROC)gapil_gl_func_table[20];
	assert(internal_f != NULL);
	return internal_f(flag);
}

GLAPI void APIENTRY glDisable(GLenum cap)
{
	PFNGLDISABLEPROC internal_f = (PFNGLDISABLEPROC)gapil_gl_func_table[21];
	assert(internal_f != NULL);
	return internal_f(cap);
}

GLAPI void APIENTRY glEnable(GLenum cap)
{
	PFNGLENABLEPROC internal_f = (PFNGLENABLEPROC)gapil_gl_func_table[22];
	assert(internal_f != NULL);
	return internal_f(cap);
}

GLAPI void APIENTRY glFinish()
{
	PFNGLFINISHPROC internal_f = (PFNGLFINISHPROC)gapil_gl_func_table[23];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glFlush()
{
	PFNGLFLUSHPROC internal_f = (PFNGLFLUSHPROC)gapil_gl_func_table[24];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glBlendFunc(GLenum sfactor, GLenum dfactor)
{
	PFNGLBLENDFUNCPROC internal_f = (PFNGLBLENDFUNCPROC)gapil_gl_func_table[25];
	assert(internal_f != NULL);
	return internal_f(sfactor, dfactor);
}

GLAPI void APIENTRY glLogicOp(GLenum opcode)
{
	PFNGLLOGICOPPROC internal_f = (PFNGLLOGICOPPROC)gapil_gl_func_table[26];
	assert(internal_f != NULL);
	return internal_f(opcode);
}

GLAPI void APIENTRY glStencilFunc(GLenum func, GLint ref, GLuint mask)
{
	PFNGLSTENCILFUNCPROC internal_f = (PFNGLSTENCILFUNCPROC)gapil_gl_func_table[27];
	assert(internal_f != NULL);
	return internal_f(func, ref, mask);
}

GLAPI void APIENTRY glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
	PFNGLSTENCILOPPROC internal_f = (PFNGLSTENCILOPPROC)gapil_gl_func_table[28];
	assert(internal_f != NULL);
	return internal_f(fail, zfail, zpass);
}

GLAPI void APIENTRY glDepthFunc(GLenum func)
{
	PFNGLDEPTHFUNCPROC internal_f = (PFNGLDEPTHFUNCPROC)gapil_gl_func_table[29];
	assert(internal_f != NULL);
	return internal_f(func);
}

GLAPI void APIENTRY glPixelStoref(GLenum pname, GLfloat param)
{
	PFNGLPIXELSTOREFPROC internal_f = (PFNGLPIXELSTOREFPROC)gapil_gl_func_table[30];
	assert(internal_f != NULL);
	return internal_f(pname, param);
}

GLAPI void APIENTRY glPixelStorei(GLenum pname, GLint param)
{
	PFNGLPIXELSTOREIPROC internal_f = (PFNGLPIXELSTOREIPROC)gapil_gl_func_table[31];
	assert(internal_f != NULL);
	return internal_f(pname, param);
}

GLAPI void APIENTRY glReadBuffer(GLenum src)
{
	PFNGLREADBUFFERPROC internal_f = (PFNGLREADBUFFERPROC)gapil_gl_func_table[32];
	assert(internal_f != NULL);
	return internal_f(src);
}

GLAPI void APIENTRY glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels)
{
	PFNGLREADPIXELSPROC internal_f = (PFNGLREADPIXELSPROC)gapil_gl_func_table[33];
	assert(internal_f != NULL);
	return internal_f(x, y, width, height, format, type, pixels);
}

GLAPI void APIENTRY glGetBooleanv(GLenum pname, GLboolean * data)
{
	PFNGLGETBOOLEANVPROC internal_f = (PFNGLGETBOOLEANVPROC)gapil_gl_func_table[34];
	assert(internal_f != NULL);
	return internal_f(pname, data);
}

GLAPI void APIENTRY glGetDoublev(GLenum pname, GLdouble * data)
{
	PFNGLGETDOUBLEVPROC internal_f = (PFNGLGETDOUBLEVPROC)gapil_gl_func_table[35];
	assert(internal_f != NULL);
	return internal_f(pname, data);
}

GLAPI GLenum APIENTRY glGetError()
{
	PFNGLGETERRORPROC internal_f = (PFNGLGETERRORPROC)gapil_gl_func_table[36];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glGetFloatv(GLenum pname, GLfloat * data)
{
	PFNGLGETFLOATVPROC internal_f = (PFNGLGETFLOATVPROC)gapil_gl_func_table[37];
	assert(internal_f != NULL);
	return internal_f(pname, data);
}

GLAPI void APIENTRY glGetIntegerv(GLenum pname, GLint * data)
{
	PFNGLGETINTEGERVPROC internal_f = (PFNGLGETINTEGERVPROC)gapil_gl_func_table[38];
	assert(internal_f != NULL);
	return internal_f(pname, data);
}

GLAPI const GLubyte * APIENTRY glGetString(GLenum name)
{
	PFNGLGETSTRINGPROC internal_f = (PFNGLGETSTRINGPROC)gapil_gl_func_table[39];
	assert(internal_f != NULL);
	return internal_f(name);
}

GLAPI void APIENTRY glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void * pixels)
{
	PFNGLGETTEXIMAGEPROC internal_f = (PFNGLGETTEXIMAGEPROC)gapil_gl_func_table[40];
	assert(internal_f != NULL);
	return internal_f(target, level, format, type, pixels);
}

GLAPI void APIENTRY glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params)
{
	PFNGLGETTEXPARAMETERFVPROC internal_f = (PFNGLGETTEXPARAMETERFVPROC)gapil_gl_func_table[41];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glGetTexParameteriv(GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETTEXPARAMETERIVPROC internal_f = (PFNGLGETTEXPARAMETERIVPROC)gapil_gl_func_table[42];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params)
{
	PFNGLGETTEXLEVELPARAMETERFVPROC internal_f = (PFNGLGETTEXLEVELPARAMETERFVPROC)gapil_gl_func_table[43];
	assert(internal_f != NULL);
	return internal_f(target, level, pname, params);
}

GLAPI void APIENTRY glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params)
{
	PFNGLGETTEXLEVELPARAMETERIVPROC internal_f = (PFNGLGETTEXLEVELPARAMETERIVPROC)gapil_gl_func_table[44];
	assert(internal_f != NULL);
	return internal_f(target, level, pname, params);
}

GLAPI GLboolean APIENTRY glIsEnabled(GLenum cap)
{
	PFNGLISENABLEDPROC internal_f = (PFNGLISENABLEDPROC)gapil_gl_func_table[45];
	assert(internal_f != NULL);
	return internal_f(cap);
}

GLAPI void APIENTRY glDepthRange(GLdouble n, GLdouble f)
{
	PFNGLDEPTHRANGEPROC internal_f = (PFNGLDEPTHRANGEPROC)gapil_gl_func_table[46];
	assert(internal_f != NULL);
	return internal_f(n, f);
}

GLAPI void APIENTRY glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLVIEWPORTPROC internal_f = (PFNGLVIEWPORTPROC)gapil_gl_func_table[47];
	assert(internal_f != NULL);
	return internal_f(x, y, width, height);
}

GLAPI void APIENTRY glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
	PFNGLDRAWARRAYSPROC internal_f = (PFNGLDRAWARRAYSPROC)gapil_gl_func_table[48];
	assert(internal_f != NULL);
	return internal_f(mode, first, count);
}

GLAPI void APIENTRY glDrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices)
{
	PFNGLDRAWELEMENTSPROC internal_f = (PFNGLDRAWELEMENTSPROC)gapil_gl_func_table[49];
	assert(internal_f != NULL);
	return internal_f(mode, count, type, indices);
}

GLAPI void APIENTRY glGetPointerv(GLenum pname, void ** params)
{
	PFNGLGETPOINTERVPROC internal_f = (PFNGLGETPOINTERVPROC)gapil_gl_func_table[50];
	assert(internal_f != NULL);
	return internal_f(pname, params);
}

GLAPI void APIENTRY glPolygonOffset(GLfloat factor, GLfloat units)
{
	PFNGLPOLYGONOFFSETPROC internal_f = (PFNGLPOLYGONOFFSETPROC)gapil_gl_func_table[51];
	assert(internal_f != NULL);
	return internal_f(factor, units);
}

GLAPI void APIENTRY glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
{
	PFNGLCOPYTEXIMAGE1DPROC internal_f = (PFNGLCOPYTEXIMAGE1DPROC)gapil_gl_func_table[52];
	assert(internal_f != NULL);
	return internal_f(target, level, internalformat, x, y, width, border);
}

GLAPI void APIENTRY glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	PFNGLCOPYTEXIMAGE2DPROC internal_f = (PFNGLCOPYTEXIMAGE2DPROC)gapil_gl_func_table[53];
	assert(internal_f != NULL);
	return internal_f(target, level, internalformat, x, y, width, height, border);
}

GLAPI void APIENTRY glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
	PFNGLCOPYTEXSUBIMAGE1DPROC internal_f = (PFNGLCOPYTEXSUBIMAGE1DPROC)gapil_gl_func_table[54];
	assert(internal_f != NULL);
	return internal_f(target, level, xoffset, x, y, width);
}

GLAPI void APIENTRY glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLCOPYTEXSUBIMAGE2DPROC internal_f = (PFNGLCOPYTEXSUBIMAGE2DPROC)gapil_gl_func_table[55];
	assert(internal_f != NULL);
	return internal_f(target, level, xoffset, yoffset, x, y, width, height);
}

GLAPI void APIENTRY glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXSUBIMAGE1DPROC internal_f = (PFNGLTEXSUBIMAGE1DPROC)gapil_gl_func_table[56];
	assert(internal_f != NULL);
	return internal_f(target, level, xoffset, width, format, type, pixels);
}

GLAPI void APIENTRY glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXSUBIMAGE2DPROC internal_f = (PFNGLTEXSUBIMAGE2DPROC)gapil_gl_func_table[57];
	assert(internal_f != NULL);
	return internal_f(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

GLAPI void APIENTRY glBindTexture(GLenum target, GLuint texture)
{
	PFNGLBINDTEXTUREPROC internal_f = (PFNGLBINDTEXTUREPROC)gapil_gl_func_table[58];
	assert(internal_f != NULL);
	return internal_f(target, texture);
}

GLAPI void APIENTRY glDeleteTextures(GLsizei n, const GLuint * textures)
{
	PFNGLDELETETEXTURESPROC internal_f = (PFNGLDELETETEXTURESPROC)gapil_gl_func_table[59];
	assert(internal_f != NULL);
	return internal_f(n, textures);
}

GLAPI void APIENTRY glGenTextures(GLsizei n, GLuint * textures)
{
	PFNGLGENTEXTURESPROC internal_f = (PFNGLGENTEXTURESPROC)gapil_gl_func_table[60];
	assert(internal_f != NULL);
	return internal_f(n, textures);
}

GLAPI GLboolean APIENTRY glIsTexture(GLuint texture)
{
	PFNGLISTEXTUREPROC internal_f = (PFNGLISTEXTUREPROC)gapil_gl_func_table[61];
	assert(internal_f != NULL);
	return internal_f(texture);
}

GLAPI void APIENTRY glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices)
{
	PFNGLDRAWRANGEELEMENTSPROC internal_f = (PFNGLDRAWRANGEELEMENTSPROC)gapil_gl_func_table[62];
	assert(internal_f != NULL);
	return internal_f(mode, start, end, count, type, indices);
}

GLAPI void APIENTRY glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXIMAGE3DPROC internal_f = (PFNGLTEXIMAGE3DPROC)gapil_gl_func_table[63];
	assert(internal_f != NULL);
	return internal_f(target, level, internalformat, width, height, depth, border, format, type, pixels);
}

GLAPI void APIENTRY glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXSUBIMAGE3DPROC internal_f = (PFNGLTEXSUBIMAGE3DPROC)gapil_gl_func_table[64];
	assert(internal_f != NULL);
	return internal_f(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

GLAPI void APIENTRY glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLCOPYTEXSUBIMAGE3DPROC internal_f = (PFNGLCOPYTEXSUBIMAGE3DPROC)gapil_gl_func_table[65];
	assert(internal_f != NULL);
	return internal_f(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

GLAPI void APIENTRY glActiveTexture(GLenum texture)
{
	PFNGLACTIVETEXTUREPROC internal_f = (PFNGLACTIVETEXTUREPROC)gapil_gl_func_table[66];
	assert(internal_f != NULL);
	return internal_f(texture);
}

GLAPI void APIENTRY glSampleCoverage(GLfloat value, GLboolean invert)
{
	PFNGLSAMPLECOVERAGEPROC internal_f = (PFNGLSAMPLECOVERAGEPROC)gapil_gl_func_table[67];
	assert(internal_f != NULL);
	return internal_f(value, invert);
}

GLAPI void APIENTRY glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data)
{
	PFNGLCOMPRESSEDTEXIMAGE3DPROC internal_f = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)gapil_gl_func_table[68];
	assert(internal_f != NULL);
	return internal_f(target, level, internalformat, width, height, depth, border, imageSize, data);
}

GLAPI void APIENTRY glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data)
{
	PFNGLCOMPRESSEDTEXIMAGE2DPROC internal_f = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)gapil_gl_func_table[69];
	assert(internal_f != NULL);
	return internal_f(target, level, internalformat, width, height, border, imageSize, data);
}

GLAPI void APIENTRY glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data)
{
	PFNGLCOMPRESSEDTEXIMAGE1DPROC internal_f = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)gapil_gl_func_table[70];
	assert(internal_f != NULL);
	return internal_f(target, level, internalformat, width, border, imageSize, data);
}

GLAPI void APIENTRY glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data)
{
	PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC internal_f = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)gapil_gl_func_table[71];
	assert(internal_f != NULL);
	return internal_f(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

GLAPI void APIENTRY glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data)
{
	PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC internal_f = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)gapil_gl_func_table[72];
	assert(internal_f != NULL);
	return internal_f(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

GLAPI void APIENTRY glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data)
{
	PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC internal_f = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)gapil_gl_func_table[73];
	assert(internal_f != NULL);
	return internal_f(target, level, xoffset, width, format, imageSize, data);
}

GLAPI void APIENTRY glGetCompressedTexImage(GLenum target, GLint level, void * img)
{
	PFNGLGETCOMPRESSEDTEXIMAGEPROC internal_f = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)gapil_gl_func_table[74];
	assert(internal_f != NULL);
	return internal_f(target, level, img);
}

GLAPI void APIENTRY glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
	PFNGLBLENDFUNCSEPARATEPROC internal_f = (PFNGLBLENDFUNCSEPARATEPROC)gapil_gl_func_table[75];
	assert(internal_f != NULL);
	return internal_f(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

GLAPI void APIENTRY glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount)
{
	PFNGLMULTIDRAWARRAYSPROC internal_f = (PFNGLMULTIDRAWARRAYSPROC)gapil_gl_func_table[76];
	assert(internal_f != NULL);
	return internal_f(mode, first, count, drawcount);
}

GLAPI void APIENTRY glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const void *const * indices, GLsizei drawcount)
{
	PFNGLMULTIDRAWELEMENTSPROC internal_f = (PFNGLMULTIDRAWELEMENTSPROC)gapil_gl_func_table[77];
	assert(internal_f != NULL);
	return internal_f(mode, count, type, indices, drawcount);
}

GLAPI void APIENTRY glPointParameterf(GLenum pname, GLfloat param)
{
	PFNGLPOINTPARAMETERFPROC internal_f = (PFNGLPOINTPARAMETERFPROC)gapil_gl_func_table[78];
	assert(internal_f != NULL);
	return internal_f(pname, param);
}

GLAPI void APIENTRY glPointParameterfv(GLenum pname, const GLfloat * params)
{
	PFNGLPOINTPARAMETERFVPROC internal_f = (PFNGLPOINTPARAMETERFVPROC)gapil_gl_func_table[79];
	assert(internal_f != NULL);
	return internal_f(pname, params);
}

GLAPI void APIENTRY glPointParameteri(GLenum pname, GLint param)
{
	PFNGLPOINTPARAMETERIPROC internal_f = (PFNGLPOINTPARAMETERIPROC)gapil_gl_func_table[80];
	assert(internal_f != NULL);
	return internal_f(pname, param);
}

GLAPI void APIENTRY glPointParameteriv(GLenum pname, const GLint * params)
{
	PFNGLPOINTPARAMETERIVPROC internal_f = (PFNGLPOINTPARAMETERIVPROC)gapil_gl_func_table[81];
	assert(internal_f != NULL);
	return internal_f(pname, params);
}

GLAPI void APIENTRY glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	PFNGLBLENDCOLORPROC internal_f = (PFNGLBLENDCOLORPROC)gapil_gl_func_table[82];
	assert(internal_f != NULL);
	return internal_f(red, green, blue, alpha);
}

GLAPI void APIENTRY glBlendEquation(GLenum mode)
{
	PFNGLBLENDEQUATIONPROC internal_f = (PFNGLBLENDEQUATIONPROC)gapil_gl_func_table[83];
	assert(internal_f != NULL);
	return internal_f(mode);
}

GLAPI void APIENTRY glGenQueries(GLsizei n, GLuint * ids)
{
	PFNGLGENQUERIESPROC internal_f = (PFNGLGENQUERIESPROC)gapil_gl_func_table[84];
	assert(internal_f != NULL);
	return internal_f(n, ids);
}

GLAPI void APIENTRY glDeleteQueries(GLsizei n, const GLuint * ids)
{
	PFNGLDELETEQUERIESPROC internal_f = (PFNGLDELETEQUERIESPROC)gapil_gl_func_table[85];
	assert(internal_f != NULL);
	return internal_f(n, ids);
}

GLAPI GLboolean APIENTRY glIsQuery(GLuint id)
{
	PFNGLISQUERYPROC internal_f = (PFNGLISQUERYPROC)gapil_gl_func_table[86];
	assert(internal_f != NULL);
	return internal_f(id);
}

GLAPI void APIENTRY glBeginQuery(GLenum target, GLuint id)
{
	PFNGLBEGINQUERYPROC internal_f = (PFNGLBEGINQUERYPROC)gapil_gl_func_table[87];
	assert(internal_f != NULL);
	return internal_f(target, id);
}

GLAPI void APIENTRY glEndQuery(GLenum target)
{
	PFNGLENDQUERYPROC internal_f = (PFNGLENDQUERYPROC)gapil_gl_func_table[88];
	assert(internal_f != NULL);
	return internal_f(target);
}

GLAPI void APIENTRY glGetQueryiv(GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETQUERYIVPROC internal_f = (PFNGLGETQUERYIVPROC)gapil_gl_func_table[89];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params)
{
	PFNGLGETQUERYOBJECTIVPROC internal_f = (PFNGLGETQUERYOBJECTIVPROC)gapil_gl_func_table[90];
	assert(internal_f != NULL);
	return internal_f(id, pname, params);
}

GLAPI void APIENTRY glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params)
{
	PFNGLGETQUERYOBJECTUIVPROC internal_f = (PFNGLGETQUERYOBJECTUIVPROC)gapil_gl_func_table[91];
	assert(internal_f != NULL);
	return internal_f(id, pname, params);
}

GLAPI void APIENTRY glBindBuffer(GLenum target, GLuint buffer)
{
	PFNGLBINDBUFFERPROC internal_f = (PFNGLBINDBUFFERPROC)gapil_gl_func_table[92];
	assert(internal_f != NULL);
	return internal_f(target, buffer);
}

GLAPI void APIENTRY glDeleteBuffers(GLsizei n, const GLuint * buffers)
{
	PFNGLDELETEBUFFERSPROC internal_f = (PFNGLDELETEBUFFERSPROC)gapil_gl_func_table[93];
	assert(internal_f != NULL);
	return internal_f(n, buffers);
}

GLAPI void APIENTRY glGenBuffers(GLsizei n, GLuint * buffers)
{
	PFNGLGENBUFFERSPROC internal_f = (PFNGLGENBUFFERSPROC)gapil_gl_func_table[94];
	assert(internal_f != NULL);
	return internal_f(n, buffers);
}

GLAPI GLboolean APIENTRY glIsBuffer(GLuint buffer)
{
	PFNGLISBUFFERPROC internal_f = (PFNGLISBUFFERPROC)gapil_gl_func_table[95];
	assert(internal_f != NULL);
	return internal_f(buffer);
}

GLAPI void APIENTRY glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage)
{
	PFNGLBUFFERDATAPROC internal_f = (PFNGLBUFFERDATAPROC)gapil_gl_func_table[96];
	assert(internal_f != NULL);
	return internal_f(target, size, data, usage);
}

GLAPI void APIENTRY glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data)
{
	PFNGLBUFFERSUBDATAPROC internal_f = (PFNGLBUFFERSUBDATAPROC)gapil_gl_func_table[97];
	assert(internal_f != NULL);
	return internal_f(target, offset, size, data);
}

GLAPI void APIENTRY glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void * data)
{
	PFNGLGETBUFFERSUBDATAPROC internal_f = (PFNGLGETBUFFERSUBDATAPROC)gapil_gl_func_table[98];
	assert(internal_f != NULL);
	return internal_f(target, offset, size, data);
}

GLAPI void * APIENTRY glMapBuffer(GLenum target, GLenum access)
{
	PFNGLMAPBUFFERPROC internal_f = (PFNGLMAPBUFFERPROC)gapil_gl_func_table[99];
	assert(internal_f != NULL);
	return internal_f(target, access);
}

GLAPI GLboolean APIENTRY glUnmapBuffer(GLenum target)
{
	PFNGLUNMAPBUFFERPROC internal_f = (PFNGLUNMAPBUFFERPROC)gapil_gl_func_table[100];
	assert(internal_f != NULL);
	return internal_f(target);
}

GLAPI void APIENTRY glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETBUFFERPARAMETERIVPROC internal_f = (PFNGLGETBUFFERPARAMETERIVPROC)gapil_gl_func_table[101];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glGetBufferPointerv(GLenum target, GLenum pname, void ** params)
{
	PFNGLGETBUFFERPOINTERVPROC internal_f = (PFNGLGETBUFFERPOINTERVPROC)gapil_gl_func_table[102];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
	PFNGLBLENDEQUATIONSEPARATEPROC internal_f = (PFNGLBLENDEQUATIONSEPARATEPROC)gapil_gl_func_table[103];
	assert(internal_f != NULL);
	return internal_f(modeRGB, modeAlpha);
}

GLAPI void APIENTRY glDrawBuffers(GLsizei n, const GLenum * bufs)
{
	PFNGLDRAWBUFFERSPROC internal_f = (PFNGLDRAWBUFFERSPROC)gapil_gl_func_table[104];
	assert(internal_f != NULL);
	return internal_f(n, bufs);
}

GLAPI void APIENTRY glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
	PFNGLSTENCILOPSEPARATEPROC internal_f = (PFNGLSTENCILOPSEPARATEPROC)gapil_gl_func_table[105];
	assert(internal_f != NULL);
	return internal_f(face, sfail, dpfail, dppass);
}

GLAPI void APIENTRY glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
	PFNGLSTENCILFUNCSEPARATEPROC internal_f = (PFNGLSTENCILFUNCSEPARATEPROC)gapil_gl_func_table[106];
	assert(internal_f != NULL);
	return internal_f(face, func, ref, mask);
}

GLAPI void APIENTRY glStencilMaskSeparate(GLenum face, GLuint mask)
{
	PFNGLSTENCILMASKSEPARATEPROC internal_f = (PFNGLSTENCILMASKSEPARATEPROC)gapil_gl_func_table[107];
	assert(internal_f != NULL);
	return internal_f(face, mask);
}

GLAPI void APIENTRY glAttachShader(GLuint program, GLuint shader)
{
	PFNGLATTACHSHADERPROC internal_f = (PFNGLATTACHSHADERPROC)gapil_gl_func_table[108];
	assert(internal_f != NULL);
	return internal_f(program, shader);
}

GLAPI void APIENTRY glBindAttribLocation(GLuint program, GLuint index, const GLchar * name)
{
	PFNGLBINDATTRIBLOCATIONPROC internal_f = (PFNGLBINDATTRIBLOCATIONPROC)gapil_gl_func_table[109];
	assert(internal_f != NULL);
	return internal_f(program, index, name);
}

GLAPI void APIENTRY glCompileShader(GLuint shader)
{
	PFNGLCOMPILESHADERPROC internal_f = (PFNGLCOMPILESHADERPROC)gapil_gl_func_table[110];
	assert(internal_f != NULL);
	return internal_f(shader);
}

GLAPI GLuint APIENTRY glCreateProgram()
{
	PFNGLCREATEPROGRAMPROC internal_f = (PFNGLCREATEPROGRAMPROC)gapil_gl_func_table[111];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI GLuint APIENTRY glCreateShader(GLenum type)
{
	PFNGLCREATESHADERPROC internal_f = (PFNGLCREATESHADERPROC)gapil_gl_func_table[112];
	assert(internal_f != NULL);
	return internal_f(type);
}

GLAPI void APIENTRY glDeleteProgram(GLuint program)
{
	PFNGLDELETEPROGRAMPROC internal_f = (PFNGLDELETEPROGRAMPROC)gapil_gl_func_table[113];
	assert(internal_f != NULL);
	return internal_f(program);
}

GLAPI void APIENTRY glDeleteShader(GLuint shader)
{
	PFNGLDELETESHADERPROC internal_f = (PFNGLDELETESHADERPROC)gapil_gl_func_table[114];
	assert(internal_f != NULL);
	return internal_f(shader);
}

GLAPI void APIENTRY glDetachShader(GLuint program, GLuint shader)
{
	PFNGLDETACHSHADERPROC internal_f = (PFNGLDETACHSHADERPROC)gapil_gl_func_table[115];
	assert(internal_f != NULL);
	return internal_f(program, shader);
}

GLAPI void APIENTRY glDisableVertexAttribArray(GLuint index)
{
	PFNGLDISABLEVERTEXATTRIBARRAYPROC internal_f = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)gapil_gl_func_table[116];
	assert(internal_f != NULL);
	return internal_f(index);
}

GLAPI void APIENTRY glEnableVertexAttribArray(GLuint index)
{
	PFNGLENABLEVERTEXATTRIBARRAYPROC internal_f = (PFNGLENABLEVERTEXATTRIBARRAYPROC)gapil_gl_func_table[117];
	assert(internal_f != NULL);
	return internal_f(index);
}

GLAPI void APIENTRY glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name)
{
	PFNGLGETACTIVEATTRIBPROC internal_f = (PFNGLGETACTIVEATTRIBPROC)gapil_gl_func_table[118];
	assert(internal_f != NULL);
	return internal_f(program, index, bufSize, length, size, type, name);
}

GLAPI void APIENTRY glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name)
{
	PFNGLGETACTIVEUNIFORMPROC internal_f = (PFNGLGETACTIVEUNIFORMPROC)gapil_gl_func_table[119];
	assert(internal_f != NULL);
	return internal_f(program, index, bufSize, length, size, type, name);
}

GLAPI void APIENTRY glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders)
{
	PFNGLGETATTACHEDSHADERSPROC internal_f = (PFNGLGETATTACHEDSHADERSPROC)gapil_gl_func_table[120];
	assert(internal_f != NULL);
	return internal_f(program, maxCount, count, shaders);
}

GLAPI GLint APIENTRY glGetAttribLocation(GLuint program, const GLchar * name)
{
	PFNGLGETATTRIBLOCATIONPROC internal_f = (PFNGLGETATTRIBLOCATIONPROC)gapil_gl_func_table[121];
	assert(internal_f != NULL);
	return internal_f(program, name);
}

GLAPI void APIENTRY glGetProgramiv(GLuint program, GLenum pname, GLint * params)
{
	PFNGLGETPROGRAMIVPROC internal_f = (PFNGLGETPROGRAMIVPROC)gapil_gl_func_table[122];
	assert(internal_f != NULL);
	return internal_f(program, pname, params);
}

GLAPI void APIENTRY glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
	PFNGLGETPROGRAMINFOLOGPROC internal_f = (PFNGLGETPROGRAMINFOLOGPROC)gapil_gl_func_table[123];
	assert(internal_f != NULL);
	return internal_f(program, bufSize, length, infoLog);
}

GLAPI void APIENTRY glGetShaderiv(GLuint shader, GLenum pname, GLint * params)
{
	PFNGLGETSHADERIVPROC internal_f = (PFNGLGETSHADERIVPROC)gapil_gl_func_table[124];
	assert(internal_f != NULL);
	return internal_f(shader, pname, params);
}

GLAPI void APIENTRY glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
	PFNGLGETSHADERINFOLOGPROC internal_f = (PFNGLGETSHADERINFOLOGPROC)gapil_gl_func_table[125];
	assert(internal_f != NULL);
	return internal_f(shader, bufSize, length, infoLog);
}

GLAPI void APIENTRY glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source)
{
	PFNGLGETSHADERSOURCEPROC internal_f = (PFNGLGETSHADERSOURCEPROC)gapil_gl_func_table[126];
	assert(internal_f != NULL);
	return internal_f(shader, bufSize, length, source);
}

GLAPI GLint APIENTRY glGetUniformLocation(GLuint program, const GLchar * name)
{
	PFNGLGETUNIFORMLOCATIONPROC internal_f = (PFNGLGETUNIFORMLOCATIONPROC)gapil_gl_func_table[127];
	assert(internal_f != NULL);
	return internal_f(program, name);
}

GLAPI void APIENTRY glGetUniformfv(GLuint program, GLint location, GLfloat * params)
{
	PFNGLGETUNIFORMFVPROC internal_f = (PFNGLGETUNIFORMFVPROC)gapil_gl_func_table[128];
	assert(internal_f != NULL);
	return internal_f(program, location, params);
}

GLAPI void APIENTRY glGetUniformiv(GLuint program, GLint location, GLint * params)
{
	PFNGLGETUNIFORMIVPROC internal_f = (PFNGLGETUNIFORMIVPROC)gapil_gl_func_table[129];
	assert(internal_f != NULL);
	return internal_f(program, location, params);
}

GLAPI void APIENTRY glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble * params)
{
	PFNGLGETVERTEXATTRIBDVPROC internal_f = (PFNGLGETVERTEXATTRIBDVPROC)gapil_gl_func_table[130];
	assert(internal_f != NULL);
	return internal_f(index, pname, params);
}

GLAPI void APIENTRY glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params)
{
	PFNGLGETVERTEXATTRIBFVPROC internal_f = (PFNGLGETVERTEXATTRIBFVPROC)gapil_gl_func_table[131];
	assert(internal_f != NULL);
	return internal_f(index, pname, params);
}

GLAPI void APIENTRY glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params)
{
	PFNGLGETVERTEXATTRIBIVPROC internal_f = (PFNGLGETVERTEXATTRIBIVPROC)gapil_gl_func_table[132];
	assert(internal_f != NULL);
	return internal_f(index, pname, params);
}

GLAPI void APIENTRY glGetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer)
{
	PFNGLGETVERTEXATTRIBPOINTERVPROC internal_f = (PFNGLGETVERTEXATTRIBPOINTERVPROC)gapil_gl_func_table[133];
	assert(internal_f != NULL);
	return internal_f(index, pname, pointer);
}

GLAPI GLboolean APIENTRY glIsProgram(GLuint program)
{
	PFNGLISPROGRAMPROC internal_f = (PFNGLISPROGRAMPROC)gapil_gl_func_table[134];
	assert(internal_f != NULL);
	return internal_f(program);
}

GLAPI GLboolean APIENTRY glIsShader(GLuint shader)
{
	PFNGLISSHADERPROC internal_f = (PFNGLISSHADERPROC)gapil_gl_func_table[135];
	assert(internal_f != NULL);
	return internal_f(shader);
}

GLAPI void APIENTRY glLinkProgram(GLuint program)
{
	PFNGLLINKPROGRAMPROC internal_f = (PFNGLLINKPROGRAMPROC)gapil_gl_func_table[136];
	assert(internal_f != NULL);
	return internal_f(program);
}

GLAPI void APIENTRY glShaderSource(GLuint shader, GLsizei count, const GLchar *const * string, const GLint * length)
{
	PFNGLSHADERSOURCEPROC internal_f = (PFNGLSHADERSOURCEPROC)gapil_gl_func_table[137];
	assert(internal_f != NULL);
	return internal_f(shader, count, string, length);
}

GLAPI void APIENTRY glUseProgram(GLuint program)
{
	PFNGLUSEPROGRAMPROC internal_f = (PFNGLUSEPROGRAMPROC)gapil_gl_func_table[138];
	assert(internal_f != NULL);
	return internal_f(program);
}

GLAPI void APIENTRY glUniform1f(GLint location, GLfloat v0)
{
	PFNGLUNIFORM1FPROC internal_f = (PFNGLUNIFORM1FPROC)gapil_gl_func_table[139];
	assert(internal_f != NULL);
	return internal_f(location, v0);
}

GLAPI void APIENTRY glUniform2f(GLint location, GLfloat v0, GLfloat v1)
{
	PFNGLUNIFORM2FPROC internal_f = (PFNGLUNIFORM2FPROC)gapil_gl_func_table[140];
	assert(internal_f != NULL);
	return internal_f(location, v0, v1);
}

GLAPI void APIENTRY glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	PFNGLUNIFORM3FPROC internal_f = (PFNGLUNIFORM3FPROC)gapil_gl_func_table[141];
	assert(internal_f != NULL);
	return internal_f(location, v0, v1, v2);
}

GLAPI void APIENTRY glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	PFNGLUNIFORM4FPROC internal_f = (PFNGLUNIFORM4FPROC)gapil_gl_func_table[142];
	assert(internal_f != NULL);
	return internal_f(location, v0, v1, v2, v3);
}

GLAPI void APIENTRY glUniform1i(GLint location, GLint v0)
{
	PFNGLUNIFORM1IPROC internal_f = (PFNGLUNIFORM1IPROC)gapil_gl_func_table[143];
	assert(internal_f != NULL);
	return internal_f(location, v0);
}

GLAPI void APIENTRY glUniform2i(GLint location, GLint v0, GLint v1)
{
	PFNGLUNIFORM2IPROC internal_f = (PFNGLUNIFORM2IPROC)gapil_gl_func_table[144];
	assert(internal_f != NULL);
	return internal_f(location, v0, v1);
}

GLAPI void APIENTRY glUniform3i(GLint location, GLint v0, GLint v1, GLint v2)
{
	PFNGLUNIFORM3IPROC internal_f = (PFNGLUNIFORM3IPROC)gapil_gl_func_table[145];
	assert(internal_f != NULL);
	return internal_f(location, v0, v1, v2);
}

GLAPI void APIENTRY glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	PFNGLUNIFORM4IPROC internal_f = (PFNGLUNIFORM4IPROC)gapil_gl_func_table[146];
	assert(internal_f != NULL);
	return internal_f(location, v0, v1, v2, v3);
}

GLAPI void APIENTRY glUniform1fv(GLint location, GLsizei count, const GLfloat * value)
{
	PFNGLUNIFORM1FVPROC internal_f = (PFNGLUNIFORM1FVPROC)gapil_gl_func_table[147];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform2fv(GLint location, GLsizei count, const GLfloat * value)
{
	PFNGLUNIFORM2FVPROC internal_f = (PFNGLUNIFORM2FVPROC)gapil_gl_func_table[148];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform3fv(GLint location, GLsizei count, const GLfloat * value)
{
	PFNGLUNIFORM3FVPROC internal_f = (PFNGLUNIFORM3FVPROC)gapil_gl_func_table[149];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform4fv(GLint location, GLsizei count, const GLfloat * value)
{
	PFNGLUNIFORM4FVPROC internal_f = (PFNGLUNIFORM4FVPROC)gapil_gl_func_table[150];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform1iv(GLint location, GLsizei count, const GLint * value)
{
	PFNGLUNIFORM1IVPROC internal_f = (PFNGLUNIFORM1IVPROC)gapil_gl_func_table[151];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform2iv(GLint location, GLsizei count, const GLint * value)
{
	PFNGLUNIFORM2IVPROC internal_f = (PFNGLUNIFORM2IVPROC)gapil_gl_func_table[152];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform3iv(GLint location, GLsizei count, const GLint * value)
{
	PFNGLUNIFORM3IVPROC internal_f = (PFNGLUNIFORM3IVPROC)gapil_gl_func_table[153];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform4iv(GLint location, GLsizei count, const GLint * value)
{
	PFNGLUNIFORM4IVPROC internal_f = (PFNGLUNIFORM4IVPROC)gapil_gl_func_table[154];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLUNIFORMMATRIX2FVPROC internal_f = (PFNGLUNIFORMMATRIX2FVPROC)gapil_gl_func_table[155];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLUNIFORMMATRIX3FVPROC internal_f = (PFNGLUNIFORMMATRIX3FVPROC)gapil_gl_func_table[156];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLUNIFORMMATRIX4FVPROC internal_f = (PFNGLUNIFORMMATRIX4FVPROC)gapil_gl_func_table[157];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glValidateProgram(GLuint program)
{
	PFNGLVALIDATEPROGRAMPROC internal_f = (PFNGLVALIDATEPROGRAMPROC)gapil_gl_func_table[158];
	assert(internal_f != NULL);
	return internal_f(program);
}

GLAPI void APIENTRY glVertexAttrib1d(GLuint index, GLdouble x)
{
	PFNGLVERTEXATTRIB1DPROC internal_f = (PFNGLVERTEXATTRIB1DPROC)gapil_gl_func_table[159];
	assert(internal_f != NULL);
	return internal_f(index, x);
}

GLAPI void APIENTRY glVertexAttrib1dv(GLuint index, const GLdouble * v)
{
	PFNGLVERTEXATTRIB1DVPROC internal_f = (PFNGLVERTEXATTRIB1DVPROC)gapil_gl_func_table[160];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib1f(GLuint index, GLfloat x)
{
	PFNGLVERTEXATTRIB1FPROC internal_f = (PFNGLVERTEXATTRIB1FPROC)gapil_gl_func_table[161];
	assert(internal_f != NULL);
	return internal_f(index, x);
}

GLAPI void APIENTRY glVertexAttrib1fv(GLuint index, const GLfloat * v)
{
	PFNGLVERTEXATTRIB1FVPROC internal_f = (PFNGLVERTEXATTRIB1FVPROC)gapil_gl_func_table[162];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib1s(GLuint index, GLshort x)
{
	PFNGLVERTEXATTRIB1SPROC internal_f = (PFNGLVERTEXATTRIB1SPROC)gapil_gl_func_table[163];
	assert(internal_f != NULL);
	return internal_f(index, x);
}

GLAPI void APIENTRY glVertexAttrib1sv(GLuint index, const GLshort * v)
{
	PFNGLVERTEXATTRIB1SVPROC internal_f = (PFNGLVERTEXATTRIB1SVPROC)gapil_gl_func_table[164];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y)
{
	PFNGLVERTEXATTRIB2DPROC internal_f = (PFNGLVERTEXATTRIB2DPROC)gapil_gl_func_table[165];
	assert(internal_f != NULL);
	return internal_f(index, x, y);
}

GLAPI void APIENTRY glVertexAttrib2dv(GLuint index, const GLdouble * v)
{
	PFNGLVERTEXATTRIB2DVPROC internal_f = (PFNGLVERTEXATTRIB2DVPROC)gapil_gl_func_table[166];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y)
{
	PFNGLVERTEXATTRIB2FPROC internal_f = (PFNGLVERTEXATTRIB2FPROC)gapil_gl_func_table[167];
	assert(internal_f != NULL);
	return internal_f(index, x, y);
}

GLAPI void APIENTRY glVertexAttrib2fv(GLuint index, const GLfloat * v)
{
	PFNGLVERTEXATTRIB2FVPROC internal_f = (PFNGLVERTEXATTRIB2FVPROC)gapil_gl_func_table[168];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib2s(GLuint index, GLshort x, GLshort y)
{
	PFNGLVERTEXATTRIB2SPROC internal_f = (PFNGLVERTEXATTRIB2SPROC)gapil_gl_func_table[169];
	assert(internal_f != NULL);
	return internal_f(index, x, y);
}

GLAPI void APIENTRY glVertexAttrib2sv(GLuint index, const GLshort * v)
{
	PFNGLVERTEXATTRIB2SVPROC internal_f = (PFNGLVERTEXATTRIB2SVPROC)gapil_gl_func_table[170];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	PFNGLVERTEXATTRIB3DPROC internal_f = (PFNGLVERTEXATTRIB3DPROC)gapil_gl_func_table[171];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z);
}

GLAPI void APIENTRY glVertexAttrib3dv(GLuint index, const GLdouble * v)
{
	PFNGLVERTEXATTRIB3DVPROC internal_f = (PFNGLVERTEXATTRIB3DVPROC)gapil_gl_func_table[172];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
	PFNGLVERTEXATTRIB3FPROC internal_f = (PFNGLVERTEXATTRIB3FPROC)gapil_gl_func_table[173];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z);
}

GLAPI void APIENTRY glVertexAttrib3fv(GLuint index, const GLfloat * v)
{
	PFNGLVERTEXATTRIB3FVPROC internal_f = (PFNGLVERTEXATTRIB3FVPROC)gapil_gl_func_table[174];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z)
{
	PFNGLVERTEXATTRIB3SPROC internal_f = (PFNGLVERTEXATTRIB3SPROC)gapil_gl_func_table[175];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z);
}

GLAPI void APIENTRY glVertexAttrib3sv(GLuint index, const GLshort * v)
{
	PFNGLVERTEXATTRIB3SVPROC internal_f = (PFNGLVERTEXATTRIB3SVPROC)gapil_gl_func_table[176];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4Nbv(GLuint index, const GLbyte * v)
{
	PFNGLVERTEXATTRIB4NBVPROC internal_f = (PFNGLVERTEXATTRIB4NBVPROC)gapil_gl_func_table[177];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4Niv(GLuint index, const GLint * v)
{
	PFNGLVERTEXATTRIB4NIVPROC internal_f = (PFNGLVERTEXATTRIB4NIVPROC)gapil_gl_func_table[178];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4Nsv(GLuint index, const GLshort * v)
{
	PFNGLVERTEXATTRIB4NSVPROC internal_f = (PFNGLVERTEXATTRIB4NSVPROC)gapil_gl_func_table[179];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)
{
	PFNGLVERTEXATTRIB4NUBPROC internal_f = (PFNGLVERTEXATTRIB4NUBPROC)gapil_gl_func_table[180];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z, w);
}

GLAPI void APIENTRY glVertexAttrib4Nubv(GLuint index, const GLubyte * v)
{
	PFNGLVERTEXATTRIB4NUBVPROC internal_f = (PFNGLVERTEXATTRIB4NUBVPROC)gapil_gl_func_table[181];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4Nuiv(GLuint index, const GLuint * v)
{
	PFNGLVERTEXATTRIB4NUIVPROC internal_f = (PFNGLVERTEXATTRIB4NUIVPROC)gapil_gl_func_table[182];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4Nusv(GLuint index, const GLushort * v)
{
	PFNGLVERTEXATTRIB4NUSVPROC internal_f = (PFNGLVERTEXATTRIB4NUSVPROC)gapil_gl_func_table[183];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4bv(GLuint index, const GLbyte * v)
{
	PFNGLVERTEXATTRIB4BVPROC internal_f = (PFNGLVERTEXATTRIB4BVPROC)gapil_gl_func_table[184];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	PFNGLVERTEXATTRIB4DPROC internal_f = (PFNGLVERTEXATTRIB4DPROC)gapil_gl_func_table[185];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z, w);
}

GLAPI void APIENTRY glVertexAttrib4dv(GLuint index, const GLdouble * v)
{
	PFNGLVERTEXATTRIB4DVPROC internal_f = (PFNGLVERTEXATTRIB4DVPROC)gapil_gl_func_table[186];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	PFNGLVERTEXATTRIB4FPROC internal_f = (PFNGLVERTEXATTRIB4FPROC)gapil_gl_func_table[187];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z, w);
}

GLAPI void APIENTRY glVertexAttrib4fv(GLuint index, const GLfloat * v)
{
	PFNGLVERTEXATTRIB4FVPROC internal_f = (PFNGLVERTEXATTRIB4FVPROC)gapil_gl_func_table[188];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4iv(GLuint index, const GLint * v)
{
	PFNGLVERTEXATTRIB4IVPROC internal_f = (PFNGLVERTEXATTRIB4IVPROC)gapil_gl_func_table[189];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)
{
	PFNGLVERTEXATTRIB4SPROC internal_f = (PFNGLVERTEXATTRIB4SPROC)gapil_gl_func_table[190];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z, w);
}

GLAPI void APIENTRY glVertexAttrib4sv(GLuint index, const GLshort * v)
{
	PFNGLVERTEXATTRIB4SVPROC internal_f = (PFNGLVERTEXATTRIB4SVPROC)gapil_gl_func_table[191];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4ubv(GLuint index, const GLubyte * v)
{
	PFNGLVERTEXATTRIB4UBVPROC internal_f = (PFNGLVERTEXATTRIB4UBVPROC)gapil_gl_func_table[192];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4uiv(GLuint index, const GLuint * v)
{
	PFNGLVERTEXATTRIB4UIVPROC internal_f = (PFNGLVERTEXATTRIB4UIVPROC)gapil_gl_func_table[193];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttrib4usv(GLuint index, const GLushort * v)
{
	PFNGLVERTEXATTRIB4USVPROC internal_f = (PFNGLVERTEXATTRIB4USVPROC)gapil_gl_func_table[194];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer)
{
	PFNGLVERTEXATTRIBPOINTERPROC internal_f = (PFNGLVERTEXATTRIBPOINTERPROC)gapil_gl_func_table[195];
	assert(internal_f != NULL);
	return internal_f(index, size, type, normalized, stride, pointer);
}

GLAPI void APIENTRY glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLUNIFORMMATRIX2X3FVPROC internal_f = (PFNGLUNIFORMMATRIX2X3FVPROC)gapil_gl_func_table[196];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLUNIFORMMATRIX3X2FVPROC internal_f = (PFNGLUNIFORMMATRIX3X2FVPROC)gapil_gl_func_table[197];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLUNIFORMMATRIX2X4FVPROC internal_f = (PFNGLUNIFORMMATRIX2X4FVPROC)gapil_gl_func_table[198];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLUNIFORMMATRIX4X2FVPROC internal_f = (PFNGLUNIFORMMATRIX4X2FVPROC)gapil_gl_func_table[199];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLUNIFORMMATRIX3X4FVPROC internal_f = (PFNGLUNIFORMMATRIX3X4FVPROC)gapil_gl_func_table[200];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLUNIFORMMATRIX4X3FVPROC internal_f = (PFNGLUNIFORMMATRIX4X3FVPROC)gapil_gl_func_table[201];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
{
	PFNGLCOLORMASKIPROC internal_f = (PFNGLCOLORMASKIPROC)gapil_gl_func_table[202];
	assert(internal_f != NULL);
	return internal_f(index, r, g, b, a);
}

GLAPI void APIENTRY glGetBooleani_v(GLenum target, GLuint index, GLboolean * data)
{
	PFNGLGETBOOLEANI_VPROC internal_f = (PFNGLGETBOOLEANI_VPROC)gapil_gl_func_table[203];
	assert(internal_f != NULL);
	return internal_f(target, index, data);
}

GLAPI void APIENTRY glGetIntegeri_v(GLenum target, GLuint index, GLint * data)
{
	PFNGLGETINTEGERI_VPROC internal_f = (PFNGLGETINTEGERI_VPROC)gapil_gl_func_table[204];
	assert(internal_f != NULL);
	return internal_f(target, index, data);
}

GLAPI void APIENTRY glEnablei(GLenum target, GLuint index)
{
	PFNGLENABLEIPROC internal_f = (PFNGLENABLEIPROC)gapil_gl_func_table[205];
	assert(internal_f != NULL);
	return internal_f(target, index);
}

GLAPI void APIENTRY glDisablei(GLenum target, GLuint index)
{
	PFNGLDISABLEIPROC internal_f = (PFNGLDISABLEIPROC)gapil_gl_func_table[206];
	assert(internal_f != NULL);
	return internal_f(target, index);
}

GLAPI GLboolean APIENTRY glIsEnabledi(GLenum target, GLuint index)
{
	PFNGLISENABLEDIPROC internal_f = (PFNGLISENABLEDIPROC)gapil_gl_func_table[207];
	assert(internal_f != NULL);
	return internal_f(target, index);
}

GLAPI void APIENTRY glBeginTransformFeedback(GLenum primitiveMode)
{
	PFNGLBEGINTRANSFORMFEEDBACKPROC internal_f = (PFNGLBEGINTRANSFORMFEEDBACKPROC)gapil_gl_func_table[208];
	assert(internal_f != NULL);
	return internal_f(primitiveMode);
}

GLAPI void APIENTRY glEndTransformFeedback()
{
	PFNGLENDTRANSFORMFEEDBACKPROC internal_f = (PFNGLENDTRANSFORMFEEDBACKPROC)gapil_gl_func_table[209];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	PFNGLBINDBUFFERRANGEPROC internal_f = (PFNGLBINDBUFFERRANGEPROC)gapil_gl_func_table[210];
	assert(internal_f != NULL);
	return internal_f(target, index, buffer, offset, size);
}

GLAPI void APIENTRY glBindBufferBase(GLenum target, GLuint index, GLuint buffer)
{
	PFNGLBINDBUFFERBASEPROC internal_f = (PFNGLBINDBUFFERBASEPROC)gapil_gl_func_table[211];
	assert(internal_f != NULL);
	return internal_f(target, index, buffer);
}

GLAPI void APIENTRY glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const * varyings, GLenum bufferMode)
{
	PFNGLTRANSFORMFEEDBACKVARYINGSPROC internal_f = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)gapil_gl_func_table[212];
	assert(internal_f != NULL);
	return internal_f(program, count, varyings, bufferMode);
}

GLAPI void APIENTRY glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name)
{
	PFNGLGETTRANSFORMFEEDBACKVARYINGPROC internal_f = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)gapil_gl_func_table[213];
	assert(internal_f != NULL);
	return internal_f(program, index, bufSize, length, size, type, name);
}

GLAPI void APIENTRY glClampColor(GLenum target, GLenum clamp)
{
	PFNGLCLAMPCOLORPROC internal_f = (PFNGLCLAMPCOLORPROC)gapil_gl_func_table[214];
	assert(internal_f != NULL);
	return internal_f(target, clamp);
}

GLAPI void APIENTRY glBeginConditionalRender(GLuint id, GLenum mode)
{
	PFNGLBEGINCONDITIONALRENDERPROC internal_f = (PFNGLBEGINCONDITIONALRENDERPROC)gapil_gl_func_table[215];
	assert(internal_f != NULL);
	return internal_f(id, mode);
}

GLAPI void APIENTRY glEndConditionalRender()
{
	PFNGLENDCONDITIONALRENDERPROC internal_f = (PFNGLENDCONDITIONALRENDERPROC)gapil_gl_func_table[216];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer)
{
	PFNGLVERTEXATTRIBIPOINTERPROC internal_f = (PFNGLVERTEXATTRIBIPOINTERPROC)gapil_gl_func_table[217];
	assert(internal_f != NULL);
	return internal_f(index, size, type, stride, pointer);
}

GLAPI void APIENTRY glGetVertexAttribIiv(GLuint index, GLenum pname, GLint * params)
{
	PFNGLGETVERTEXATTRIBIIVPROC internal_f = (PFNGLGETVERTEXATTRIBIIVPROC)gapil_gl_func_table[218];
	assert(internal_f != NULL);
	return internal_f(index, pname, params);
}

GLAPI void APIENTRY glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint * params)
{
	PFNGLGETVERTEXATTRIBIUIVPROC internal_f = (PFNGLGETVERTEXATTRIBIUIVPROC)gapil_gl_func_table[219];
	assert(internal_f != NULL);
	return internal_f(index, pname, params);
}

GLAPI void APIENTRY glVertexAttribI1i(GLuint index, GLint x)
{
	PFNGLVERTEXATTRIBI1IPROC internal_f = (PFNGLVERTEXATTRIBI1IPROC)gapil_gl_func_table[220];
	assert(internal_f != NULL);
	return internal_f(index, x);
}

GLAPI void APIENTRY glVertexAttribI2i(GLuint index, GLint x, GLint y)
{
	PFNGLVERTEXATTRIBI2IPROC internal_f = (PFNGLVERTEXATTRIBI2IPROC)gapil_gl_func_table[221];
	assert(internal_f != NULL);
	return internal_f(index, x, y);
}

GLAPI void APIENTRY glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z)
{
	PFNGLVERTEXATTRIBI3IPROC internal_f = (PFNGLVERTEXATTRIBI3IPROC)gapil_gl_func_table[222];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z);
}

GLAPI void APIENTRY glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w)
{
	PFNGLVERTEXATTRIBI4IPROC internal_f = (PFNGLVERTEXATTRIBI4IPROC)gapil_gl_func_table[223];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z, w);
}

GLAPI void APIENTRY glVertexAttribI1ui(GLuint index, GLuint x)
{
	PFNGLVERTEXATTRIBI1UIPROC internal_f = (PFNGLVERTEXATTRIBI1UIPROC)gapil_gl_func_table[224];
	assert(internal_f != NULL);
	return internal_f(index, x);
}

GLAPI void APIENTRY glVertexAttribI2ui(GLuint index, GLuint x, GLuint y)
{
	PFNGLVERTEXATTRIBI2UIPROC internal_f = (PFNGLVERTEXATTRIBI2UIPROC)gapil_gl_func_table[225];
	assert(internal_f != NULL);
	return internal_f(index, x, y);
}

GLAPI void APIENTRY glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z)
{
	PFNGLVERTEXATTRIBI3UIPROC internal_f = (PFNGLVERTEXATTRIBI3UIPROC)gapil_gl_func_table[226];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z);
}

GLAPI void APIENTRY glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
{
	PFNGLVERTEXATTRIBI4UIPROC internal_f = (PFNGLVERTEXATTRIBI4UIPROC)gapil_gl_func_table[227];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z, w);
}

GLAPI void APIENTRY glVertexAttribI1iv(GLuint index, const GLint * v)
{
	PFNGLVERTEXATTRIBI1IVPROC internal_f = (PFNGLVERTEXATTRIBI1IVPROC)gapil_gl_func_table[228];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribI2iv(GLuint index, const GLint * v)
{
	PFNGLVERTEXATTRIBI2IVPROC internal_f = (PFNGLVERTEXATTRIBI2IVPROC)gapil_gl_func_table[229];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribI3iv(GLuint index, const GLint * v)
{
	PFNGLVERTEXATTRIBI3IVPROC internal_f = (PFNGLVERTEXATTRIBI3IVPROC)gapil_gl_func_table[230];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribI4iv(GLuint index, const GLint * v)
{
	PFNGLVERTEXATTRIBI4IVPROC internal_f = (PFNGLVERTEXATTRIBI4IVPROC)gapil_gl_func_table[231];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribI1uiv(GLuint index, const GLuint * v)
{
	PFNGLVERTEXATTRIBI1UIVPROC internal_f = (PFNGLVERTEXATTRIBI1UIVPROC)gapil_gl_func_table[232];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribI2uiv(GLuint index, const GLuint * v)
{
	PFNGLVERTEXATTRIBI2UIVPROC internal_f = (PFNGLVERTEXATTRIBI2UIVPROC)gapil_gl_func_table[233];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribI3uiv(GLuint index, const GLuint * v)
{
	PFNGLVERTEXATTRIBI3UIVPROC internal_f = (PFNGLVERTEXATTRIBI3UIVPROC)gapil_gl_func_table[234];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribI4uiv(GLuint index, const GLuint * v)
{
	PFNGLVERTEXATTRIBI4UIVPROC internal_f = (PFNGLVERTEXATTRIBI4UIVPROC)gapil_gl_func_table[235];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribI4bv(GLuint index, const GLbyte * v)
{
	PFNGLVERTEXATTRIBI4BVPROC internal_f = (PFNGLVERTEXATTRIBI4BVPROC)gapil_gl_func_table[236];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribI4sv(GLuint index, const GLshort * v)
{
	PFNGLVERTEXATTRIBI4SVPROC internal_f = (PFNGLVERTEXATTRIBI4SVPROC)gapil_gl_func_table[237];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribI4ubv(GLuint index, const GLubyte * v)
{
	PFNGLVERTEXATTRIBI4UBVPROC internal_f = (PFNGLVERTEXATTRIBI4UBVPROC)gapil_gl_func_table[238];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribI4usv(GLuint index, const GLushort * v)
{
	PFNGLVERTEXATTRIBI4USVPROC internal_f = (PFNGLVERTEXATTRIBI4USVPROC)gapil_gl_func_table[239];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glGetUniformuiv(GLuint program, GLint location, GLuint * params)
{
	PFNGLGETUNIFORMUIVPROC internal_f = (PFNGLGETUNIFORMUIVPROC)gapil_gl_func_table[240];
	assert(internal_f != NULL);
	return internal_f(program, location, params);
}

GLAPI void APIENTRY glBindFragDataLocation(GLuint program, GLuint color, const GLchar * name)
{
	PFNGLBINDFRAGDATALOCATIONPROC internal_f = (PFNGLBINDFRAGDATALOCATIONPROC)gapil_gl_func_table[241];
	assert(internal_f != NULL);
	return internal_f(program, color, name);
}

GLAPI GLint APIENTRY glGetFragDataLocation(GLuint program, const GLchar * name)
{
	PFNGLGETFRAGDATALOCATIONPROC internal_f = (PFNGLGETFRAGDATALOCATIONPROC)gapil_gl_func_table[242];
	assert(internal_f != NULL);
	return internal_f(program, name);
}

GLAPI void APIENTRY glUniform1ui(GLint location, GLuint v0)
{
	PFNGLUNIFORM1UIPROC internal_f = (PFNGLUNIFORM1UIPROC)gapil_gl_func_table[243];
	assert(internal_f != NULL);
	return internal_f(location, v0);
}

GLAPI void APIENTRY glUniform2ui(GLint location, GLuint v0, GLuint v1)
{
	PFNGLUNIFORM2UIPROC internal_f = (PFNGLUNIFORM2UIPROC)gapil_gl_func_table[244];
	assert(internal_f != NULL);
	return internal_f(location, v0, v1);
}

GLAPI void APIENTRY glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2)
{
	PFNGLUNIFORM3UIPROC internal_f = (PFNGLUNIFORM3UIPROC)gapil_gl_func_table[245];
	assert(internal_f != NULL);
	return internal_f(location, v0, v1, v2);
}

GLAPI void APIENTRY glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
	PFNGLUNIFORM4UIPROC internal_f = (PFNGLUNIFORM4UIPROC)gapil_gl_func_table[246];
	assert(internal_f != NULL);
	return internal_f(location, v0, v1, v2, v3);
}

GLAPI void APIENTRY glUniform1uiv(GLint location, GLsizei count, const GLuint * value)
{
	PFNGLUNIFORM1UIVPROC internal_f = (PFNGLUNIFORM1UIVPROC)gapil_gl_func_table[247];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform2uiv(GLint location, GLsizei count, const GLuint * value)
{
	PFNGLUNIFORM2UIVPROC internal_f = (PFNGLUNIFORM2UIVPROC)gapil_gl_func_table[248];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform3uiv(GLint location, GLsizei count, const GLuint * value)
{
	PFNGLUNIFORM3UIVPROC internal_f = (PFNGLUNIFORM3UIVPROC)gapil_gl_func_table[249];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform4uiv(GLint location, GLsizei count, const GLuint * value)
{
	PFNGLUNIFORM4UIVPROC internal_f = (PFNGLUNIFORM4UIVPROC)gapil_gl_func_table[250];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glTexParameterIiv(GLenum target, GLenum pname, const GLint * params)
{
	PFNGLTEXPARAMETERIIVPROC internal_f = (PFNGLTEXPARAMETERIIVPROC)gapil_gl_func_table[251];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glTexParameterIuiv(GLenum target, GLenum pname, const GLuint * params)
{
	PFNGLTEXPARAMETERIUIVPROC internal_f = (PFNGLTEXPARAMETERIUIVPROC)gapil_gl_func_table[252];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETTEXPARAMETERIIVPROC internal_f = (PFNGLGETTEXPARAMETERIIVPROC)gapil_gl_func_table[253];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params)
{
	PFNGLGETTEXPARAMETERIUIVPROC internal_f = (PFNGLGETTEXPARAMETERIUIVPROC)gapil_gl_func_table[254];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint * value)
{
	PFNGLCLEARBUFFERIVPROC internal_f = (PFNGLCLEARBUFFERIVPROC)gapil_gl_func_table[255];
	assert(internal_f != NULL);
	return internal_f(buffer, drawbuffer, value);
}

GLAPI void APIENTRY glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint * value)
{
	PFNGLCLEARBUFFERUIVPROC internal_f = (PFNGLCLEARBUFFERUIVPROC)gapil_gl_func_table[256];
	assert(internal_f != NULL);
	return internal_f(buffer, drawbuffer, value);
}

GLAPI void APIENTRY glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat * value)
{
	PFNGLCLEARBUFFERFVPROC internal_f = (PFNGLCLEARBUFFERFVPROC)gapil_gl_func_table[257];
	assert(internal_f != NULL);
	return internal_f(buffer, drawbuffer, value);
}

GLAPI void APIENTRY glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
{
	PFNGLCLEARBUFFERFIPROC internal_f = (PFNGLCLEARBUFFERFIPROC)gapil_gl_func_table[258];
	assert(internal_f != NULL);
	return internal_f(buffer, drawbuffer, depth, stencil);
}

GLAPI const GLubyte * APIENTRY glGetStringi(GLenum name, GLuint index)
{
	PFNGLGETSTRINGIPROC internal_f = (PFNGLGETSTRINGIPROC)gapil_gl_func_table[259];
	assert(internal_f != NULL);
	return internal_f(name, index);
}

GLAPI GLboolean APIENTRY glIsRenderbuffer(GLuint renderbuffer)
{
	PFNGLISRENDERBUFFERPROC internal_f = (PFNGLISRENDERBUFFERPROC)gapil_gl_func_table[260];
	assert(internal_f != NULL);
	return internal_f(renderbuffer);
}

GLAPI void APIENTRY glBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
	PFNGLBINDRENDERBUFFERPROC internal_f = (PFNGLBINDRENDERBUFFERPROC)gapil_gl_func_table[261];
	assert(internal_f != NULL);
	return internal_f(target, renderbuffer);
}

GLAPI void APIENTRY glDeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers)
{
	PFNGLDELETERENDERBUFFERSPROC internal_f = (PFNGLDELETERENDERBUFFERSPROC)gapil_gl_func_table[262];
	assert(internal_f != NULL);
	return internal_f(n, renderbuffers);
}

GLAPI void APIENTRY glGenRenderbuffers(GLsizei n, GLuint * renderbuffers)
{
	PFNGLGENRENDERBUFFERSPROC internal_f = (PFNGLGENRENDERBUFFERSPROC)gapil_gl_func_table[263];
	assert(internal_f != NULL);
	return internal_f(n, renderbuffers);
}

GLAPI void APIENTRY glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLRENDERBUFFERSTORAGEPROC internal_f = (PFNGLRENDERBUFFERSTORAGEPROC)gapil_gl_func_table[264];
	assert(internal_f != NULL);
	return internal_f(target, internalformat, width, height);
}

GLAPI void APIENTRY glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETRENDERBUFFERPARAMETERIVPROC internal_f = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)gapil_gl_func_table[265];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI GLboolean APIENTRY glIsFramebuffer(GLuint framebuffer)
{
	PFNGLISFRAMEBUFFERPROC internal_f = (PFNGLISFRAMEBUFFERPROC)gapil_gl_func_table[266];
	assert(internal_f != NULL);
	return internal_f(framebuffer);
}

GLAPI void APIENTRY glBindFramebuffer(GLenum target, GLuint framebuffer)
{
	PFNGLBINDFRAMEBUFFERPROC internal_f = (PFNGLBINDFRAMEBUFFERPROC)gapil_gl_func_table[267];
	assert(internal_f != NULL);
	return internal_f(target, framebuffer);
}

GLAPI void APIENTRY glDeleteFramebuffers(GLsizei n, const GLuint * framebuffers)
{
	PFNGLDELETEFRAMEBUFFERSPROC internal_f = (PFNGLDELETEFRAMEBUFFERSPROC)gapil_gl_func_table[268];
	assert(internal_f != NULL);
	return internal_f(n, framebuffers);
}

GLAPI void APIENTRY glGenFramebuffers(GLsizei n, GLuint * framebuffers)
{
	PFNGLGENFRAMEBUFFERSPROC internal_f = (PFNGLGENFRAMEBUFFERSPROC)gapil_gl_func_table[269];
	assert(internal_f != NULL);
	return internal_f(n, framebuffers);
}

GLAPI GLenum APIENTRY glCheckFramebufferStatus(GLenum target)
{
	PFNGLCHECKFRAMEBUFFERSTATUSPROC internal_f = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)gapil_gl_func_table[270];
	assert(internal_f != NULL);
	return internal_f(target);
}

GLAPI void APIENTRY glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	PFNGLFRAMEBUFFERTEXTURE1DPROC internal_f = (PFNGLFRAMEBUFFERTEXTURE1DPROC)gapil_gl_func_table[271];
	assert(internal_f != NULL);
	return internal_f(target, attachment, textarget, texture, level);
}

GLAPI void APIENTRY glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	PFNGLFRAMEBUFFERTEXTURE2DPROC internal_f = (PFNGLFRAMEBUFFERTEXTURE2DPROC)gapil_gl_func_table[272];
	assert(internal_f != NULL);
	return internal_f(target, attachment, textarget, texture, level);
}

GLAPI void APIENTRY glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
{
	PFNGLFRAMEBUFFERTEXTURE3DPROC internal_f = (PFNGLFRAMEBUFFERTEXTURE3DPROC)gapil_gl_func_table[273];
	assert(internal_f != NULL);
	return internal_f(target, attachment, textarget, texture, level, zoffset);
}

GLAPI void APIENTRY glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
	PFNGLFRAMEBUFFERRENDERBUFFERPROC internal_f = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)gapil_gl_func_table[274];
	assert(internal_f != NULL);
	return internal_f(target, attachment, renderbuffertarget, renderbuffer);
}

GLAPI void APIENTRY glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params)
{
	PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC internal_f = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)gapil_gl_func_table[275];
	assert(internal_f != NULL);
	return internal_f(target, attachment, pname, params);
}

GLAPI void APIENTRY glGenerateMipmap(GLenum target)
{
	PFNGLGENERATEMIPMAPPROC internal_f = (PFNGLGENERATEMIPMAPPROC)gapil_gl_func_table[276];
	assert(internal_f != NULL);
	return internal_f(target);
}

GLAPI void APIENTRY glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
{
	PFNGLBLITFRAMEBUFFERPROC internal_f = (PFNGLBLITFRAMEBUFFERPROC)gapil_gl_func_table[277];
	assert(internal_f != NULL);
	return internal_f(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

GLAPI void APIENTRY glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC internal_f = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)gapil_gl_func_table[278];
	assert(internal_f != NULL);
	return internal_f(target, samples, internalformat, width, height);
}

GLAPI void APIENTRY glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
	PFNGLFRAMEBUFFERTEXTURELAYERPROC internal_f = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)gapil_gl_func_table[279];
	assert(internal_f != NULL);
	return internal_f(target, attachment, texture, level, layer);
}

GLAPI void * APIENTRY glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
	PFNGLMAPBUFFERRANGEPROC internal_f = (PFNGLMAPBUFFERRANGEPROC)gapil_gl_func_table[280];
	assert(internal_f != NULL);
	return internal_f(target, offset, length, access);
}

GLAPI void APIENTRY glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length)
{
	PFNGLFLUSHMAPPEDBUFFERRANGEPROC internal_f = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)gapil_gl_func_table[281];
	assert(internal_f != NULL);
	return internal_f(target, offset, length);
}

GLAPI void APIENTRY glBindVertexArray(GLuint array)
{
	PFNGLBINDVERTEXARRAYPROC internal_f = (PFNGLBINDVERTEXARRAYPROC)gapil_gl_func_table[282];
	assert(internal_f != NULL);
	return internal_f(array);
}

GLAPI void APIENTRY glDeleteVertexArrays(GLsizei n, const GLuint * arrays)
{
	PFNGLDELETEVERTEXARRAYSPROC internal_f = (PFNGLDELETEVERTEXARRAYSPROC)gapil_gl_func_table[283];
	assert(internal_f != NULL);
	return internal_f(n, arrays);
}

GLAPI void APIENTRY glGenVertexArrays(GLsizei n, GLuint * arrays)
{
	PFNGLGENVERTEXARRAYSPROC internal_f = (PFNGLGENVERTEXARRAYSPROC)gapil_gl_func_table[284];
	assert(internal_f != NULL);
	return internal_f(n, arrays);
}

GLAPI GLboolean APIENTRY glIsVertexArray(GLuint array)
{
	PFNGLISVERTEXARRAYPROC internal_f = (PFNGLISVERTEXARRAYPROC)gapil_gl_func_table[285];
	assert(internal_f != NULL);
	return internal_f(array);
}

GLAPI void APIENTRY glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount)
{
	PFNGLDRAWARRAYSINSTANCEDPROC internal_f = (PFNGLDRAWARRAYSINSTANCEDPROC)gapil_gl_func_table[286];
	assert(internal_f != NULL);
	return internal_f(mode, first, count, instancecount);
}

GLAPI void APIENTRY glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount)
{
	PFNGLDRAWELEMENTSINSTANCEDPROC internal_f = (PFNGLDRAWELEMENTSINSTANCEDPROC)gapil_gl_func_table[287];
	assert(internal_f != NULL);
	return internal_f(mode, count, type, indices, instancecount);
}

GLAPI void APIENTRY glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer)
{
	PFNGLTEXBUFFERPROC internal_f = (PFNGLTEXBUFFERPROC)gapil_gl_func_table[288];
	assert(internal_f != NULL);
	return internal_f(target, internalformat, buffer);
}

GLAPI void APIENTRY glPrimitiveRestartIndex(GLuint index)
{
	PFNGLPRIMITIVERESTARTINDEXPROC internal_f = (PFNGLPRIMITIVERESTARTINDEXPROC)gapil_gl_func_table[289];
	assert(internal_f != NULL);
	return internal_f(index);
}

GLAPI void APIENTRY glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
{
	PFNGLCOPYBUFFERSUBDATAPROC internal_f = (PFNGLCOPYBUFFERSUBDATAPROC)gapil_gl_func_table[290];
	assert(internal_f != NULL);
	return internal_f(readTarget, writeTarget, readOffset, writeOffset, size);
}

GLAPI void APIENTRY glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const * uniformNames, GLuint * uniformIndices)
{
	PFNGLGETUNIFORMINDICESPROC internal_f = (PFNGLGETUNIFORMINDICESPROC)gapil_gl_func_table[291];
	assert(internal_f != NULL);
	return internal_f(program, uniformCount, uniformNames, uniformIndices);
}

GLAPI void APIENTRY glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params)
{
	PFNGLGETACTIVEUNIFORMSIVPROC internal_f = (PFNGLGETACTIVEUNIFORMSIVPROC)gapil_gl_func_table[292];
	assert(internal_f != NULL);
	return internal_f(program, uniformCount, uniformIndices, pname, params);
}

GLAPI void APIENTRY glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName)
{
	PFNGLGETACTIVEUNIFORMNAMEPROC internal_f = (PFNGLGETACTIVEUNIFORMNAMEPROC)gapil_gl_func_table[293];
	assert(internal_f != NULL);
	return internal_f(program, uniformIndex, bufSize, length, uniformName);
}

GLAPI GLuint APIENTRY glGetUniformBlockIndex(GLuint program, const GLchar * uniformBlockName)
{
	PFNGLGETUNIFORMBLOCKINDEXPROC internal_f = (PFNGLGETUNIFORMBLOCKINDEXPROC)gapil_gl_func_table[294];
	assert(internal_f != NULL);
	return internal_f(program, uniformBlockName);
}

GLAPI void APIENTRY glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params)
{
	PFNGLGETACTIVEUNIFORMBLOCKIVPROC internal_f = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)gapil_gl_func_table[295];
	assert(internal_f != NULL);
	return internal_f(program, uniformBlockIndex, pname, params);
}

GLAPI void APIENTRY glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName)
{
	PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC internal_f = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)gapil_gl_func_table[296];
	assert(internal_f != NULL);
	return internal_f(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}

GLAPI void APIENTRY glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
{
	PFNGLUNIFORMBLOCKBINDINGPROC internal_f = (PFNGLUNIFORMBLOCKBINDINGPROC)gapil_gl_func_table[297];
	assert(internal_f != NULL);
	return internal_f(program, uniformBlockIndex, uniformBlockBinding);
}

GLAPI void APIENTRY glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex)
{
	PFNGLDRAWELEMENTSBASEVERTEXPROC internal_f = (PFNGLDRAWELEMENTSBASEVERTEXPROC)gapil_gl_func_table[298];
	assert(internal_f != NULL);
	return internal_f(mode, count, type, indices, basevertex);
}

GLAPI void APIENTRY glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex)
{
	PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC internal_f = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)gapil_gl_func_table[299];
	assert(internal_f != NULL);
	return internal_f(mode, start, end, count, type, indices, basevertex);
}

GLAPI void APIENTRY glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex)
{
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC internal_f = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)gapil_gl_func_table[300];
	assert(internal_f != NULL);
	return internal_f(mode, count, type, indices, instancecount, basevertex);
}

GLAPI void APIENTRY glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei * count, GLenum type, const void *const * indices, GLsizei drawcount, const GLint * basevertex)
{
	PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC internal_f = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)gapil_gl_func_table[301];
	assert(internal_f != NULL);
	return internal_f(mode, count, type, indices, drawcount, basevertex);
}

GLAPI void APIENTRY glProvokingVertex(GLenum mode)
{
	PFNGLPROVOKINGVERTEXPROC internal_f = (PFNGLPROVOKINGVERTEXPROC)gapil_gl_func_table[302];
	assert(internal_f != NULL);
	return internal_f(mode);
}

GLAPI GLsync APIENTRY glFenceSync(GLenum condition, GLbitfield flags)
{
	PFNGLFENCESYNCPROC internal_f = (PFNGLFENCESYNCPROC)gapil_gl_func_table[303];
	assert(internal_f != NULL);
	return internal_f(condition, flags);
}

GLAPI GLboolean APIENTRY glIsSync(GLsync sync)
{
	PFNGLISSYNCPROC internal_f = (PFNGLISSYNCPROC)gapil_gl_func_table[304];
	assert(internal_f != NULL);
	return internal_f(sync);
}

GLAPI void APIENTRY glDeleteSync(GLsync sync)
{
	PFNGLDELETESYNCPROC internal_f = (PFNGLDELETESYNCPROC)gapil_gl_func_table[305];
	assert(internal_f != NULL);
	return internal_f(sync);
}

GLAPI GLenum APIENTRY glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
	PFNGLCLIENTWAITSYNCPROC internal_f = (PFNGLCLIENTWAITSYNCPROC)gapil_gl_func_table[306];
	assert(internal_f != NULL);
	return internal_f(sync, flags, timeout);
}

GLAPI void APIENTRY glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
	PFNGLWAITSYNCPROC internal_f = (PFNGLWAITSYNCPROC)gapil_gl_func_table[307];
	assert(internal_f != NULL);
	return internal_f(sync, flags, timeout);
}

GLAPI void APIENTRY glGetInteger64v(GLenum pname, GLint64 * data)
{
	PFNGLGETINTEGER64VPROC internal_f = (PFNGLGETINTEGER64VPROC)gapil_gl_func_table[308];
	assert(internal_f != NULL);
	return internal_f(pname, data);
}

GLAPI void APIENTRY glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values)
{
	PFNGLGETSYNCIVPROC internal_f = (PFNGLGETSYNCIVPROC)gapil_gl_func_table[309];
	assert(internal_f != NULL);
	return internal_f(sync, pname, count, length, values);
}

GLAPI void APIENTRY glGetInteger64i_v(GLenum target, GLuint index, GLint64 * data)
{
	PFNGLGETINTEGER64I_VPROC internal_f = (PFNGLGETINTEGER64I_VPROC)gapil_gl_func_table[310];
	assert(internal_f != NULL);
	return internal_f(target, index, data);
}

GLAPI void APIENTRY glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 * params)
{
	PFNGLGETBUFFERPARAMETERI64VPROC internal_f = (PFNGLGETBUFFERPARAMETERI64VPROC)gapil_gl_func_table[311];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
	PFNGLFRAMEBUFFERTEXTUREPROC internal_f = (PFNGLFRAMEBUFFERTEXTUREPROC)gapil_gl_func_table[312];
	assert(internal_f != NULL);
	return internal_f(target, attachment, texture, level);
}

GLAPI void APIENTRY glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
{
	PFNGLTEXIMAGE2DMULTISAMPLEPROC internal_f = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)gapil_gl_func_table[313];
	assert(internal_f != NULL);
	return internal_f(target, samples, internalformat, width, height, fixedsamplelocations);
}

GLAPI void APIENTRY glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
{
	PFNGLTEXIMAGE3DMULTISAMPLEPROC internal_f = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)gapil_gl_func_table[314];
	assert(internal_f != NULL);
	return internal_f(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

GLAPI void APIENTRY glGetMultisamplefv(GLenum pname, GLuint index, GLfloat * val)
{
	PFNGLGETMULTISAMPLEFVPROC internal_f = (PFNGLGETMULTISAMPLEFVPROC)gapil_gl_func_table[315];
	assert(internal_f != NULL);
	return internal_f(pname, index, val);
}

GLAPI void APIENTRY glSampleMaski(GLuint maskNumber, GLbitfield mask)
{
	PFNGLSAMPLEMASKIPROC internal_f = (PFNGLSAMPLEMASKIPROC)gapil_gl_func_table[316];
	assert(internal_f != NULL);
	return internal_f(maskNumber, mask);
}

GLAPI void APIENTRY glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name)
{
	PFNGLBINDFRAGDATALOCATIONINDEXEDPROC internal_f = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)gapil_gl_func_table[317];
	assert(internal_f != NULL);
	return internal_f(program, colorNumber, index, name);
}

GLAPI GLint APIENTRY glGetFragDataIndex(GLuint program, const GLchar * name)
{
	PFNGLGETFRAGDATAINDEXPROC internal_f = (PFNGLGETFRAGDATAINDEXPROC)gapil_gl_func_table[318];
	assert(internal_f != NULL);
	return internal_f(program, name);
}

GLAPI void APIENTRY glGenSamplers(GLsizei count, GLuint * samplers)
{
	PFNGLGENSAMPLERSPROC internal_f = (PFNGLGENSAMPLERSPROC)gapil_gl_func_table[319];
	assert(internal_f != NULL);
	return internal_f(count, samplers);
}

GLAPI void APIENTRY glDeleteSamplers(GLsizei count, const GLuint * samplers)
{
	PFNGLDELETESAMPLERSPROC internal_f = (PFNGLDELETESAMPLERSPROC)gapil_gl_func_table[320];
	assert(internal_f != NULL);
	return internal_f(count, samplers);
}

GLAPI GLboolean APIENTRY glIsSampler(GLuint sampler)
{
	PFNGLISSAMPLERPROC internal_f = (PFNGLISSAMPLERPROC)gapil_gl_func_table[321];
	assert(internal_f != NULL);
	return internal_f(sampler);
}

GLAPI void APIENTRY glBindSampler(GLuint unit, GLuint sampler)
{
	PFNGLBINDSAMPLERPROC internal_f = (PFNGLBINDSAMPLERPROC)gapil_gl_func_table[322];
	assert(internal_f != NULL);
	return internal_f(unit, sampler);
}

GLAPI void APIENTRY glSamplerParameteri(GLuint sampler, GLenum pname, GLint param)
{
	PFNGLSAMPLERPARAMETERIPROC internal_f = (PFNGLSAMPLERPARAMETERIPROC)gapil_gl_func_table[323];
	assert(internal_f != NULL);
	return internal_f(sampler, pname, param);
}

GLAPI void APIENTRY glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint * param)
{
	PFNGLSAMPLERPARAMETERIVPROC internal_f = (PFNGLSAMPLERPARAMETERIVPROC)gapil_gl_func_table[324];
	assert(internal_f != NULL);
	return internal_f(sampler, pname, param);
}

GLAPI void APIENTRY glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)
{
	PFNGLSAMPLERPARAMETERFPROC internal_f = (PFNGLSAMPLERPARAMETERFPROC)gapil_gl_func_table[325];
	assert(internal_f != NULL);
	return internal_f(sampler, pname, param);
}

GLAPI void APIENTRY glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat * param)
{
	PFNGLSAMPLERPARAMETERFVPROC internal_f = (PFNGLSAMPLERPARAMETERFVPROC)gapil_gl_func_table[326];
	assert(internal_f != NULL);
	return internal_f(sampler, pname, param);
}

GLAPI void APIENTRY glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint * param)
{
	PFNGLSAMPLERPARAMETERIIVPROC internal_f = (PFNGLSAMPLERPARAMETERIIVPROC)gapil_gl_func_table[327];
	assert(internal_f != NULL);
	return internal_f(sampler, pname, param);
}

GLAPI void APIENTRY glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint * param)
{
	PFNGLSAMPLERPARAMETERIUIVPROC internal_f = (PFNGLSAMPLERPARAMETERIUIVPROC)gapil_gl_func_table[328];
	assert(internal_f != NULL);
	return internal_f(sampler, pname, param);
}

GLAPI void APIENTRY glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params)
{
	PFNGLGETSAMPLERPARAMETERIVPROC internal_f = (PFNGLGETSAMPLERPARAMETERIVPROC)gapil_gl_func_table[329];
	assert(internal_f != NULL);
	return internal_f(sampler, pname, params);
}

GLAPI void APIENTRY glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params)
{
	PFNGLGETSAMPLERPARAMETERIIVPROC internal_f = (PFNGLGETSAMPLERPARAMETERIIVPROC)gapil_gl_func_table[330];
	assert(internal_f != NULL);
	return internal_f(sampler, pname, params);
}

GLAPI void APIENTRY glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params)
{
	PFNGLGETSAMPLERPARAMETERFVPROC internal_f = (PFNGLGETSAMPLERPARAMETERFVPROC)gapil_gl_func_table[331];
	assert(internal_f != NULL);
	return internal_f(sampler, pname, params);
}

GLAPI void APIENTRY glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params)
{
	PFNGLGETSAMPLERPARAMETERIUIVPROC internal_f = (PFNGLGETSAMPLERPARAMETERIUIVPROC)gapil_gl_func_table[332];
	assert(internal_f != NULL);
	return internal_f(sampler, pname, params);
}

GLAPI void APIENTRY glQueryCounter(GLuint id, GLenum target)
{
	PFNGLQUERYCOUNTERPROC internal_f = (PFNGLQUERYCOUNTERPROC)gapil_gl_func_table[333];
	assert(internal_f != NULL);
	return internal_f(id, target);
}

GLAPI void APIENTRY glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params)
{
	PFNGLGETQUERYOBJECTI64VPROC internal_f = (PFNGLGETQUERYOBJECTI64VPROC)gapil_gl_func_table[334];
	assert(internal_f != NULL);
	return internal_f(id, pname, params);
}

GLAPI void APIENTRY glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params)
{
	PFNGLGETQUERYOBJECTUI64VPROC internal_f = (PFNGLGETQUERYOBJECTUI64VPROC)gapil_gl_func_table[335];
	assert(internal_f != NULL);
	return internal_f(id, pname, params);
}

GLAPI void APIENTRY glVertexAttribDivisor(GLuint index, GLuint divisor)
{
	PFNGLVERTEXATTRIBDIVISORPROC internal_f = (PFNGLVERTEXATTRIBDIVISORPROC)gapil_gl_func_table[336];
	assert(internal_f != NULL);
	return internal_f(index, divisor);
}

GLAPI void APIENTRY glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
	PFNGLVERTEXATTRIBP1UIPROC internal_f = (PFNGLVERTEXATTRIBP1UIPROC)gapil_gl_func_table[337];
	assert(internal_f != NULL);
	return internal_f(index, type, normalized, value);
}

GLAPI void APIENTRY glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value)
{
	PFNGLVERTEXATTRIBP1UIVPROC internal_f = (PFNGLVERTEXATTRIBP1UIVPROC)gapil_gl_func_table[338];
	assert(internal_f != NULL);
	return internal_f(index, type, normalized, value);
}

GLAPI void APIENTRY glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
	PFNGLVERTEXATTRIBP2UIPROC internal_f = (PFNGLVERTEXATTRIBP2UIPROC)gapil_gl_func_table[339];
	assert(internal_f != NULL);
	return internal_f(index, type, normalized, value);
}

GLAPI void APIENTRY glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value)
{
	PFNGLVERTEXATTRIBP2UIVPROC internal_f = (PFNGLVERTEXATTRIBP2UIVPROC)gapil_gl_func_table[340];
	assert(internal_f != NULL);
	return internal_f(index, type, normalized, value);
}

GLAPI void APIENTRY glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
	PFNGLVERTEXATTRIBP3UIPROC internal_f = (PFNGLVERTEXATTRIBP3UIPROC)gapil_gl_func_table[341];
	assert(internal_f != NULL);
	return internal_f(index, type, normalized, value);
}

GLAPI void APIENTRY glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value)
{
	PFNGLVERTEXATTRIBP3UIVPROC internal_f = (PFNGLVERTEXATTRIBP3UIVPROC)gapil_gl_func_table[342];
	assert(internal_f != NULL);
	return internal_f(index, type, normalized, value);
}

GLAPI void APIENTRY glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
	PFNGLVERTEXATTRIBP4UIPROC internal_f = (PFNGLVERTEXATTRIBP4UIPROC)gapil_gl_func_table[343];
	assert(internal_f != NULL);
	return internal_f(index, type, normalized, value);
}

GLAPI void APIENTRY glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value)
{
	PFNGLVERTEXATTRIBP4UIVPROC internal_f = (PFNGLVERTEXATTRIBP4UIVPROC)gapil_gl_func_table[344];
	assert(internal_f != NULL);
	return internal_f(index, type, normalized, value);
}

GLAPI void APIENTRY glMinSampleShading(GLfloat value)
{
	PFNGLMINSAMPLESHADINGPROC internal_f = (PFNGLMINSAMPLESHADINGPROC)gapil_gl_func_table[345];
	assert(internal_f != NULL);
	return internal_f(value);
}

GLAPI void APIENTRY glBlendEquationi(GLuint buf, GLenum mode)
{
	PFNGLBLENDEQUATIONIPROC internal_f = (PFNGLBLENDEQUATIONIPROC)gapil_gl_func_table[346];
	assert(internal_f != NULL);
	return internal_f(buf, mode);
}

GLAPI void APIENTRY glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
	PFNGLBLENDEQUATIONSEPARATEIPROC internal_f = (PFNGLBLENDEQUATIONSEPARATEIPROC)gapil_gl_func_table[347];
	assert(internal_f != NULL);
	return internal_f(buf, modeRGB, modeAlpha);
}

GLAPI void APIENTRY glBlendFunci(GLuint buf, GLenum src, GLenum dst)
{
	PFNGLBLENDFUNCIPROC internal_f = (PFNGLBLENDFUNCIPROC)gapil_gl_func_table[348];
	assert(internal_f != NULL);
	return internal_f(buf, src, dst);
}

GLAPI void APIENTRY glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
	PFNGLBLENDFUNCSEPARATEIPROC internal_f = (PFNGLBLENDFUNCSEPARATEIPROC)gapil_gl_func_table[349];
	assert(internal_f != NULL);
	return internal_f(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

GLAPI void APIENTRY glDrawArraysIndirect(GLenum mode, const void * indirect)
{
	PFNGLDRAWARRAYSINDIRECTPROC internal_f = (PFNGLDRAWARRAYSINDIRECTPROC)gapil_gl_func_table[350];
	assert(internal_f != NULL);
	return internal_f(mode, indirect);
}

GLAPI void APIENTRY glDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect)
{
	PFNGLDRAWELEMENTSINDIRECTPROC internal_f = (PFNGLDRAWELEMENTSINDIRECTPROC)gapil_gl_func_table[351];
	assert(internal_f != NULL);
	return internal_f(mode, type, indirect);
}

GLAPI void APIENTRY glUniform1d(GLint location, GLdouble x)
{
	PFNGLUNIFORM1DPROC internal_f = (PFNGLUNIFORM1DPROC)gapil_gl_func_table[352];
	assert(internal_f != NULL);
	return internal_f(location, x);
}

GLAPI void APIENTRY glUniform2d(GLint location, GLdouble x, GLdouble y)
{
	PFNGLUNIFORM2DPROC internal_f = (PFNGLUNIFORM2DPROC)gapil_gl_func_table[353];
	assert(internal_f != NULL);
	return internal_f(location, x, y);
}

GLAPI void APIENTRY glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z)
{
	PFNGLUNIFORM3DPROC internal_f = (PFNGLUNIFORM3DPROC)gapil_gl_func_table[354];
	assert(internal_f != NULL);
	return internal_f(location, x, y, z);
}

GLAPI void APIENTRY glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	PFNGLUNIFORM4DPROC internal_f = (PFNGLUNIFORM4DPROC)gapil_gl_func_table[355];
	assert(internal_f != NULL);
	return internal_f(location, x, y, z, w);
}

GLAPI void APIENTRY glUniform1dv(GLint location, GLsizei count, const GLdouble * value)
{
	PFNGLUNIFORM1DVPROC internal_f = (PFNGLUNIFORM1DVPROC)gapil_gl_func_table[356];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform2dv(GLint location, GLsizei count, const GLdouble * value)
{
	PFNGLUNIFORM2DVPROC internal_f = (PFNGLUNIFORM2DVPROC)gapil_gl_func_table[357];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform3dv(GLint location, GLsizei count, const GLdouble * value)
{
	PFNGLUNIFORM3DVPROC internal_f = (PFNGLUNIFORM3DVPROC)gapil_gl_func_table[358];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform4dv(GLint location, GLsizei count, const GLdouble * value)
{
	PFNGLUNIFORM4DVPROC internal_f = (PFNGLUNIFORM4DVPROC)gapil_gl_func_table[359];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLUNIFORMMATRIX2DVPROC internal_f = (PFNGLUNIFORMMATRIX2DVPROC)gapil_gl_func_table[360];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLUNIFORMMATRIX3DVPROC internal_f = (PFNGLUNIFORMMATRIX3DVPROC)gapil_gl_func_table[361];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLUNIFORMMATRIX4DVPROC internal_f = (PFNGLUNIFORMMATRIX4DVPROC)gapil_gl_func_table[362];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLUNIFORMMATRIX2X3DVPROC internal_f = (PFNGLUNIFORMMATRIX2X3DVPROC)gapil_gl_func_table[363];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLUNIFORMMATRIX2X4DVPROC internal_f = (PFNGLUNIFORMMATRIX2X4DVPROC)gapil_gl_func_table[364];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLUNIFORMMATRIX3X2DVPROC internal_f = (PFNGLUNIFORMMATRIX3X2DVPROC)gapil_gl_func_table[365];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLUNIFORMMATRIX3X4DVPROC internal_f = (PFNGLUNIFORMMATRIX3X4DVPROC)gapil_gl_func_table[366];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLUNIFORMMATRIX4X2DVPROC internal_f = (PFNGLUNIFORMMATRIX4X2DVPROC)gapil_gl_func_table[367];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLUNIFORMMATRIX4X3DVPROC internal_f = (PFNGLUNIFORMMATRIX4X3DVPROC)gapil_gl_func_table[368];
	assert(internal_f != NULL);
	return internal_f(location, count, transpose, value);
}

GLAPI void APIENTRY glGetUniformdv(GLuint program, GLint location, GLdouble * params)
{
	PFNGLGETUNIFORMDVPROC internal_f = (PFNGLGETUNIFORMDVPROC)gapil_gl_func_table[369];
	assert(internal_f != NULL);
	return internal_f(program, location, params);
}

GLAPI GLint APIENTRY glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar * name)
{
	PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC internal_f = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)gapil_gl_func_table[370];
	assert(internal_f != NULL);
	return internal_f(program, shadertype, name);
}

GLAPI GLuint APIENTRY glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar * name)
{
	PFNGLGETSUBROUTINEINDEXPROC internal_f = (PFNGLGETSUBROUTINEINDEXPROC)gapil_gl_func_table[371];
	assert(internal_f != NULL);
	return internal_f(program, shadertype, name);
}

GLAPI void APIENTRY glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values)
{
	PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC internal_f = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)gapil_gl_func_table[372];
	assert(internal_f != NULL);
	return internal_f(program, shadertype, index, pname, values);
}

GLAPI void APIENTRY glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name)
{
	PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC internal_f = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)gapil_gl_func_table[373];
	assert(internal_f != NULL);
	return internal_f(program, shadertype, index, bufSize, length, name);
}

GLAPI void APIENTRY glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name)
{
	PFNGLGETACTIVESUBROUTINENAMEPROC internal_f = (PFNGLGETACTIVESUBROUTINENAMEPROC)gapil_gl_func_table[374];
	assert(internal_f != NULL);
	return internal_f(program, shadertype, index, bufSize, length, name);
}

GLAPI void APIENTRY glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint * indices)
{
	PFNGLUNIFORMSUBROUTINESUIVPROC internal_f = (PFNGLUNIFORMSUBROUTINESUIVPROC)gapil_gl_func_table[375];
	assert(internal_f != NULL);
	return internal_f(shadertype, count, indices);
}

GLAPI void APIENTRY glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint * params)
{
	PFNGLGETUNIFORMSUBROUTINEUIVPROC internal_f = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)gapil_gl_func_table[376];
	assert(internal_f != NULL);
	return internal_f(shadertype, location, params);
}

GLAPI void APIENTRY glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint * values)
{
	PFNGLGETPROGRAMSTAGEIVPROC internal_f = (PFNGLGETPROGRAMSTAGEIVPROC)gapil_gl_func_table[377];
	assert(internal_f != NULL);
	return internal_f(program, shadertype, pname, values);
}

GLAPI void APIENTRY glPatchParameteri(GLenum pname, GLint value)
{
	PFNGLPATCHPARAMETERIPROC internal_f = (PFNGLPATCHPARAMETERIPROC)gapil_gl_func_table[378];
	assert(internal_f != NULL);
	return internal_f(pname, value);
}

GLAPI void APIENTRY glPatchParameterfv(GLenum pname, const GLfloat * values)
{
	PFNGLPATCHPARAMETERFVPROC internal_f = (PFNGLPATCHPARAMETERFVPROC)gapil_gl_func_table[379];
	assert(internal_f != NULL);
	return internal_f(pname, values);
}

GLAPI void APIENTRY glBindTransformFeedback(GLenum target, GLuint id)
{
	PFNGLBINDTRANSFORMFEEDBACKPROC internal_f = (PFNGLBINDTRANSFORMFEEDBACKPROC)gapil_gl_func_table[380];
	assert(internal_f != NULL);
	return internal_f(target, id);
}

GLAPI void APIENTRY glDeleteTransformFeedbacks(GLsizei n, const GLuint * ids)
{
	PFNGLDELETETRANSFORMFEEDBACKSPROC internal_f = (PFNGLDELETETRANSFORMFEEDBACKSPROC)gapil_gl_func_table[381];
	assert(internal_f != NULL);
	return internal_f(n, ids);
}

GLAPI void APIENTRY glGenTransformFeedbacks(GLsizei n, GLuint * ids)
{
	PFNGLGENTRANSFORMFEEDBACKSPROC internal_f = (PFNGLGENTRANSFORMFEEDBACKSPROC)gapil_gl_func_table[382];
	assert(internal_f != NULL);
	return internal_f(n, ids);
}

GLAPI GLboolean APIENTRY glIsTransformFeedback(GLuint id)
{
	PFNGLISTRANSFORMFEEDBACKPROC internal_f = (PFNGLISTRANSFORMFEEDBACKPROC)gapil_gl_func_table[383];
	assert(internal_f != NULL);
	return internal_f(id);
}

GLAPI void APIENTRY glPauseTransformFeedback()
{
	PFNGLPAUSETRANSFORMFEEDBACKPROC internal_f = (PFNGLPAUSETRANSFORMFEEDBACKPROC)gapil_gl_func_table[384];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glResumeTransformFeedback()
{
	PFNGLRESUMETRANSFORMFEEDBACKPROC internal_f = (PFNGLRESUMETRANSFORMFEEDBACKPROC)gapil_gl_func_table[385];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glDrawTransformFeedback(GLenum mode, GLuint id)
{
	PFNGLDRAWTRANSFORMFEEDBACKPROC internal_f = (PFNGLDRAWTRANSFORMFEEDBACKPROC)gapil_gl_func_table[386];
	assert(internal_f != NULL);
	return internal_f(mode, id);
}

GLAPI void APIENTRY glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream)
{
	PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC internal_f = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)gapil_gl_func_table[387];
	assert(internal_f != NULL);
	return internal_f(mode, id, stream);
}

GLAPI void APIENTRY glBeginQueryIndexed(GLenum target, GLuint index, GLuint id)
{
	PFNGLBEGINQUERYINDEXEDPROC internal_f = (PFNGLBEGINQUERYINDEXEDPROC)gapil_gl_func_table[388];
	assert(internal_f != NULL);
	return internal_f(target, index, id);
}

GLAPI void APIENTRY glEndQueryIndexed(GLenum target, GLuint index)
{
	PFNGLENDQUERYINDEXEDPROC internal_f = (PFNGLENDQUERYINDEXEDPROC)gapil_gl_func_table[389];
	assert(internal_f != NULL);
	return internal_f(target, index);
}

GLAPI void APIENTRY glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint * params)
{
	PFNGLGETQUERYINDEXEDIVPROC internal_f = (PFNGLGETQUERYINDEXEDIVPROC)gapil_gl_func_table[390];
	assert(internal_f != NULL);
	return internal_f(target, index, pname, params);
}

GLAPI void APIENTRY glReleaseShaderCompiler()
{
	PFNGLRELEASESHADERCOMPILERPROC internal_f = (PFNGLRELEASESHADERCOMPILERPROC)gapil_gl_func_table[391];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glShaderBinary(GLsizei count, const GLuint * shaders, GLenum binaryFormat, const void * binary, GLsizei length)
{
	PFNGLSHADERBINARYPROC internal_f = (PFNGLSHADERBINARYPROC)gapil_gl_func_table[392];
	assert(internal_f != NULL);
	return internal_f(count, shaders, binaryFormat, binary, length);
}

GLAPI void APIENTRY glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision)
{
	PFNGLGETSHADERPRECISIONFORMATPROC internal_f = (PFNGLGETSHADERPRECISIONFORMATPROC)gapil_gl_func_table[393];
	assert(internal_f != NULL);
	return internal_f(shadertype, precisiontype, range, precision);
}

GLAPI void APIENTRY glDepthRangef(GLfloat n, GLfloat f)
{
	PFNGLDEPTHRANGEFPROC internal_f = (PFNGLDEPTHRANGEFPROC)gapil_gl_func_table[394];
	assert(internal_f != NULL);
	return internal_f(n, f);
}

GLAPI void APIENTRY glClearDepthf(GLfloat d)
{
	PFNGLCLEARDEPTHFPROC internal_f = (PFNGLCLEARDEPTHFPROC)gapil_gl_func_table[395];
	assert(internal_f != NULL);
	return internal_f(d);
}

GLAPI void APIENTRY glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary)
{
	PFNGLGETPROGRAMBINARYPROC internal_f = (PFNGLGETPROGRAMBINARYPROC)gapil_gl_func_table[396];
	assert(internal_f != NULL);
	return internal_f(program, bufSize, length, binaryFormat, binary);
}

GLAPI void APIENTRY glProgramBinary(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length)
{
	PFNGLPROGRAMBINARYPROC internal_f = (PFNGLPROGRAMBINARYPROC)gapil_gl_func_table[397];
	assert(internal_f != NULL);
	return internal_f(program, binaryFormat, binary, length);
}

GLAPI void APIENTRY glProgramParameteri(GLuint program, GLenum pname, GLint value)
{
	PFNGLPROGRAMPARAMETERIPROC internal_f = (PFNGLPROGRAMPARAMETERIPROC)gapil_gl_func_table[398];
	assert(internal_f != NULL);
	return internal_f(program, pname, value);
}

GLAPI void APIENTRY glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program)
{
	PFNGLUSEPROGRAMSTAGESPROC internal_f = (PFNGLUSEPROGRAMSTAGESPROC)gapil_gl_func_table[399];
	assert(internal_f != NULL);
	return internal_f(pipeline, stages, program);
}

GLAPI void APIENTRY glActiveShaderProgram(GLuint pipeline, GLuint program)
{
	PFNGLACTIVESHADERPROGRAMPROC internal_f = (PFNGLACTIVESHADERPROGRAMPROC)gapil_gl_func_table[400];
	assert(internal_f != NULL);
	return internal_f(pipeline, program);
}

GLAPI GLuint APIENTRY glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const * strings)
{
	PFNGLCREATESHADERPROGRAMVPROC internal_f = (PFNGLCREATESHADERPROGRAMVPROC)gapil_gl_func_table[401];
	assert(internal_f != NULL);
	return internal_f(type, count, strings);
}

GLAPI void APIENTRY glBindProgramPipeline(GLuint pipeline)
{
	PFNGLBINDPROGRAMPIPELINEPROC internal_f = (PFNGLBINDPROGRAMPIPELINEPROC)gapil_gl_func_table[402];
	assert(internal_f != NULL);
	return internal_f(pipeline);
}

GLAPI void APIENTRY glDeleteProgramPipelines(GLsizei n, const GLuint * pipelines)
{
	PFNGLDELETEPROGRAMPIPELINESPROC internal_f = (PFNGLDELETEPROGRAMPIPELINESPROC)gapil_gl_func_table[403];
	assert(internal_f != NULL);
	return internal_f(n, pipelines);
}

GLAPI void APIENTRY glGenProgramPipelines(GLsizei n, GLuint * pipelines)
{
	PFNGLGENPROGRAMPIPELINESPROC internal_f = (PFNGLGENPROGRAMPIPELINESPROC)gapil_gl_func_table[404];
	assert(internal_f != NULL);
	return internal_f(n, pipelines);
}

GLAPI GLboolean APIENTRY glIsProgramPipeline(GLuint pipeline)
{
	PFNGLISPROGRAMPIPELINEPROC internal_f = (PFNGLISPROGRAMPIPELINEPROC)gapil_gl_func_table[405];
	assert(internal_f != NULL);
	return internal_f(pipeline);
}

GLAPI void APIENTRY glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint * params)
{
	PFNGLGETPROGRAMPIPELINEIVPROC internal_f = (PFNGLGETPROGRAMPIPELINEIVPROC)gapil_gl_func_table[406];
	assert(internal_f != NULL);
	return internal_f(pipeline, pname, params);
}

GLAPI void APIENTRY glProgramUniform1i(GLuint program, GLint location, GLint v0)
{
	PFNGLPROGRAMUNIFORM1IPROC internal_f = (PFNGLPROGRAMUNIFORM1IPROC)gapil_gl_func_table[407];
	assert(internal_f != NULL);
	return internal_f(program, location, v0);
}

GLAPI void APIENTRY glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint * value)
{
	PFNGLPROGRAMUNIFORM1IVPROC internal_f = (PFNGLPROGRAMUNIFORM1IVPROC)gapil_gl_func_table[408];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform1f(GLuint program, GLint location, GLfloat v0)
{
	PFNGLPROGRAMUNIFORM1FPROC internal_f = (PFNGLPROGRAMUNIFORM1FPROC)gapil_gl_func_table[409];
	assert(internal_f != NULL);
	return internal_f(program, location, v0);
}

GLAPI void APIENTRY glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORM1FVPROC internal_f = (PFNGLPROGRAMUNIFORM1FVPROC)gapil_gl_func_table[410];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform1d(GLuint program, GLint location, GLdouble v0)
{
	PFNGLPROGRAMUNIFORM1DPROC internal_f = (PFNGLPROGRAMUNIFORM1DPROC)gapil_gl_func_table[411];
	assert(internal_f != NULL);
	return internal_f(program, location, v0);
}

GLAPI void APIENTRY glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORM1DVPROC internal_f = (PFNGLPROGRAMUNIFORM1DVPROC)gapil_gl_func_table[412];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform1ui(GLuint program, GLint location, GLuint v0)
{
	PFNGLPROGRAMUNIFORM1UIPROC internal_f = (PFNGLPROGRAMUNIFORM1UIPROC)gapil_gl_func_table[413];
	assert(internal_f != NULL);
	return internal_f(program, location, v0);
}

GLAPI void APIENTRY glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint * value)
{
	PFNGLPROGRAMUNIFORM1UIVPROC internal_f = (PFNGLPROGRAMUNIFORM1UIVPROC)gapil_gl_func_table[414];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1)
{
	PFNGLPROGRAMUNIFORM2IPROC internal_f = (PFNGLPROGRAMUNIFORM2IPROC)gapil_gl_func_table[415];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1);
}

GLAPI void APIENTRY glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint * value)
{
	PFNGLPROGRAMUNIFORM2IVPROC internal_f = (PFNGLPROGRAMUNIFORM2IVPROC)gapil_gl_func_table[416];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1)
{
	PFNGLPROGRAMUNIFORM2FPROC internal_f = (PFNGLPROGRAMUNIFORM2FPROC)gapil_gl_func_table[417];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1);
}

GLAPI void APIENTRY glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORM2FVPROC internal_f = (PFNGLPROGRAMUNIFORM2FVPROC)gapil_gl_func_table[418];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1)
{
	PFNGLPROGRAMUNIFORM2DPROC internal_f = (PFNGLPROGRAMUNIFORM2DPROC)gapil_gl_func_table[419];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1);
}

GLAPI void APIENTRY glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORM2DVPROC internal_f = (PFNGLPROGRAMUNIFORM2DVPROC)gapil_gl_func_table[420];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1)
{
	PFNGLPROGRAMUNIFORM2UIPROC internal_f = (PFNGLPROGRAMUNIFORM2UIPROC)gapil_gl_func_table[421];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1);
}

GLAPI void APIENTRY glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint * value)
{
	PFNGLPROGRAMUNIFORM2UIVPROC internal_f = (PFNGLPROGRAMUNIFORM2UIVPROC)gapil_gl_func_table[422];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2)
{
	PFNGLPROGRAMUNIFORM3IPROC internal_f = (PFNGLPROGRAMUNIFORM3IPROC)gapil_gl_func_table[423];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2);
}

GLAPI void APIENTRY glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint * value)
{
	PFNGLPROGRAMUNIFORM3IVPROC internal_f = (PFNGLPROGRAMUNIFORM3IVPROC)gapil_gl_func_table[424];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	PFNGLPROGRAMUNIFORM3FPROC internal_f = (PFNGLPROGRAMUNIFORM3FPROC)gapil_gl_func_table[425];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2);
}

GLAPI void APIENTRY glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORM3FVPROC internal_f = (PFNGLPROGRAMUNIFORM3FVPROC)gapil_gl_func_table[426];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2)
{
	PFNGLPROGRAMUNIFORM3DPROC internal_f = (PFNGLPROGRAMUNIFORM3DPROC)gapil_gl_func_table[427];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2);
}

GLAPI void APIENTRY glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORM3DVPROC internal_f = (PFNGLPROGRAMUNIFORM3DVPROC)gapil_gl_func_table[428];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)
{
	PFNGLPROGRAMUNIFORM3UIPROC internal_f = (PFNGLPROGRAMUNIFORM3UIPROC)gapil_gl_func_table[429];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2);
}

GLAPI void APIENTRY glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint * value)
{
	PFNGLPROGRAMUNIFORM3UIVPROC internal_f = (PFNGLPROGRAMUNIFORM3UIVPROC)gapil_gl_func_table[430];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	PFNGLPROGRAMUNIFORM4IPROC internal_f = (PFNGLPROGRAMUNIFORM4IPROC)gapil_gl_func_table[431];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2, v3);
}

GLAPI void APIENTRY glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint * value)
{
	PFNGLPROGRAMUNIFORM4IVPROC internal_f = (PFNGLPROGRAMUNIFORM4IVPROC)gapil_gl_func_table[432];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	PFNGLPROGRAMUNIFORM4FPROC internal_f = (PFNGLPROGRAMUNIFORM4FPROC)gapil_gl_func_table[433];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2, v3);
}

GLAPI void APIENTRY glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORM4FVPROC internal_f = (PFNGLPROGRAMUNIFORM4FVPROC)gapil_gl_func_table[434];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3)
{
	PFNGLPROGRAMUNIFORM4DPROC internal_f = (PFNGLPROGRAMUNIFORM4DPROC)gapil_gl_func_table[435];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2, v3);
}

GLAPI void APIENTRY glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORM4DVPROC internal_f = (PFNGLPROGRAMUNIFORM4DVPROC)gapil_gl_func_table[436];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
	PFNGLPROGRAMUNIFORM4UIPROC internal_f = (PFNGLPROGRAMUNIFORM4UIPROC)gapil_gl_func_table[437];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2, v3);
}

GLAPI void APIENTRY glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint * value)
{
	PFNGLPROGRAMUNIFORM4UIVPROC internal_f = (PFNGLPROGRAMUNIFORM4UIVPROC)gapil_gl_func_table[438];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX2FVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)gapil_gl_func_table[439];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX3FVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)gapil_gl_func_table[440];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX4FVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)gapil_gl_func_table[441];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX2DVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)gapil_gl_func_table[442];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX3DVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)gapil_gl_func_table[443];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX4DVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)gapil_gl_func_table[444];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)gapil_gl_func_table[445];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)gapil_gl_func_table[446];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)gapil_gl_func_table[447];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)gapil_gl_func_table[448];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)gapil_gl_func_table[449];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)gapil_gl_func_table[450];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)gapil_gl_func_table[451];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)gapil_gl_func_table[452];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)gapil_gl_func_table[453];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)gapil_gl_func_table[454];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)gapil_gl_func_table[455];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)gapil_gl_func_table[456];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glValidateProgramPipeline(GLuint pipeline)
{
	PFNGLVALIDATEPROGRAMPIPELINEPROC internal_f = (PFNGLVALIDATEPROGRAMPIPELINEPROC)gapil_gl_func_table[457];
	assert(internal_f != NULL);
	return internal_f(pipeline);
}

GLAPI void APIENTRY glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
	PFNGLGETPROGRAMPIPELINEINFOLOGPROC internal_f = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)gapil_gl_func_table[458];
	assert(internal_f != NULL);
	return internal_f(pipeline, bufSize, length, infoLog);
}

GLAPI void APIENTRY glVertexAttribL1d(GLuint index, GLdouble x)
{
	PFNGLVERTEXATTRIBL1DPROC internal_f = (PFNGLVERTEXATTRIBL1DPROC)gapil_gl_func_table[459];
	assert(internal_f != NULL);
	return internal_f(index, x);
}

GLAPI void APIENTRY glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y)
{
	PFNGLVERTEXATTRIBL2DPROC internal_f = (PFNGLVERTEXATTRIBL2DPROC)gapil_gl_func_table[460];
	assert(internal_f != NULL);
	return internal_f(index, x, y);
}

GLAPI void APIENTRY glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	PFNGLVERTEXATTRIBL3DPROC internal_f = (PFNGLVERTEXATTRIBL3DPROC)gapil_gl_func_table[461];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z);
}

GLAPI void APIENTRY glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	PFNGLVERTEXATTRIBL4DPROC internal_f = (PFNGLVERTEXATTRIBL4DPROC)gapil_gl_func_table[462];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z, w);
}

GLAPI void APIENTRY glVertexAttribL1dv(GLuint index, const GLdouble * v)
{
	PFNGLVERTEXATTRIBL1DVPROC internal_f = (PFNGLVERTEXATTRIBL1DVPROC)gapil_gl_func_table[463];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribL2dv(GLuint index, const GLdouble * v)
{
	PFNGLVERTEXATTRIBL2DVPROC internal_f = (PFNGLVERTEXATTRIBL2DVPROC)gapil_gl_func_table[464];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribL3dv(GLuint index, const GLdouble * v)
{
	PFNGLVERTEXATTRIBL3DVPROC internal_f = (PFNGLVERTEXATTRIBL3DVPROC)gapil_gl_func_table[465];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribL4dv(GLuint index, const GLdouble * v)
{
	PFNGLVERTEXATTRIBL4DVPROC internal_f = (PFNGLVERTEXATTRIBL4DVPROC)gapil_gl_func_table[466];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer)
{
	PFNGLVERTEXATTRIBLPOINTERPROC internal_f = (PFNGLVERTEXATTRIBLPOINTERPROC)gapil_gl_func_table[467];
	assert(internal_f != NULL);
	return internal_f(index, size, type, stride, pointer);
}

GLAPI void APIENTRY glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble * params)
{
	PFNGLGETVERTEXATTRIBLDVPROC internal_f = (PFNGLGETVERTEXATTRIBLDVPROC)gapil_gl_func_table[468];
	assert(internal_f != NULL);
	return internal_f(index, pname, params);
}

GLAPI void APIENTRY glViewportArrayv(GLuint first, GLsizei count, const GLfloat * v)
{
	PFNGLVIEWPORTARRAYVPROC internal_f = (PFNGLVIEWPORTARRAYVPROC)gapil_gl_func_table[469];
	assert(internal_f != NULL);
	return internal_f(first, count, v);
}

GLAPI void APIENTRY glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
	PFNGLVIEWPORTINDEXEDFPROC internal_f = (PFNGLVIEWPORTINDEXEDFPROC)gapil_gl_func_table[470];
	assert(internal_f != NULL);
	return internal_f(index, x, y, w, h);
}

GLAPI void APIENTRY glViewportIndexedfv(GLuint index, const GLfloat * v)
{
	PFNGLVIEWPORTINDEXEDFVPROC internal_f = (PFNGLVIEWPORTINDEXEDFVPROC)gapil_gl_func_table[471];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glScissorArrayv(GLuint first, GLsizei count, const GLint * v)
{
	PFNGLSCISSORARRAYVPROC internal_f = (PFNGLSCISSORARRAYVPROC)gapil_gl_func_table[472];
	assert(internal_f != NULL);
	return internal_f(first, count, v);
}

GLAPI void APIENTRY glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)
{
	PFNGLSCISSORINDEXEDPROC internal_f = (PFNGLSCISSORINDEXEDPROC)gapil_gl_func_table[473];
	assert(internal_f != NULL);
	return internal_f(index, left, bottom, width, height);
}

GLAPI void APIENTRY glScissorIndexedv(GLuint index, const GLint * v)
{
	PFNGLSCISSORINDEXEDVPROC internal_f = (PFNGLSCISSORINDEXEDVPROC)gapil_gl_func_table[474];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble * v)
{
	PFNGLDEPTHRANGEARRAYVPROC internal_f = (PFNGLDEPTHRANGEARRAYVPROC)gapil_gl_func_table[475];
	assert(internal_f != NULL);
	return internal_f(first, count, v);
}

GLAPI void APIENTRY glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f)
{
	PFNGLDEPTHRANGEINDEXEDPROC internal_f = (PFNGLDEPTHRANGEINDEXEDPROC)gapil_gl_func_table[476];
	assert(internal_f != NULL);
	return internal_f(index, n, f);
}

GLAPI void APIENTRY glGetFloati_v(GLenum target, GLuint index, GLfloat * data)
{
	PFNGLGETFLOATI_VPROC internal_f = (PFNGLGETFLOATI_VPROC)gapil_gl_func_table[477];
	assert(internal_f != NULL);
	return internal_f(target, index, data);
}

GLAPI void APIENTRY glGetDoublei_v(GLenum target, GLuint index, GLdouble * data)
{
	PFNGLGETDOUBLEI_VPROC internal_f = (PFNGLGETDOUBLEI_VPROC)gapil_gl_func_table[478];
	assert(internal_f != NULL);
	return internal_f(target, index, data);
}

GLAPI void APIENTRY glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance)
{
	PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC internal_f = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)gapil_gl_func_table[479];
	assert(internal_f != NULL);
	return internal_f(mode, first, count, instancecount, baseinstance);
}

GLAPI void APIENTRY glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance)
{
	PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC internal_f = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)gapil_gl_func_table[480];
	assert(internal_f != NULL);
	return internal_f(mode, count, type, indices, instancecount, baseinstance);
}

GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)
{
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC internal_f = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)gapil_gl_func_table[481];
	assert(internal_f != NULL);
	return internal_f(mode, count, type, indices, instancecount, basevertex, baseinstance);
}

GLAPI void APIENTRY glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params)
{
	PFNGLGETINTERNALFORMATIVPROC internal_f = (PFNGLGETINTERNALFORMATIVPROC)gapil_gl_func_table[482];
	assert(internal_f != NULL);
	return internal_f(target, internalformat, pname, count, params);
}

GLAPI void APIENTRY glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params)
{
	PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC internal_f = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)gapil_gl_func_table[483];
	assert(internal_f != NULL);
	return internal_f(program, bufferIndex, pname, params);
}

GLAPI void APIENTRY glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)
{
	PFNGLBINDIMAGETEXTUREPROC internal_f = (PFNGLBINDIMAGETEXTUREPROC)gapil_gl_func_table[484];
	assert(internal_f != NULL);
	return internal_f(unit, texture, level, layered, layer, access, format);
}

GLAPI void APIENTRY glMemoryBarrier(GLbitfield barriers)
{
	PFNGLMEMORYBARRIERPROC internal_f = (PFNGLMEMORYBARRIERPROC)gapil_gl_func_table[485];
	assert(internal_f != NULL);
	return internal_f(barriers);
}

GLAPI void APIENTRY glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
{
	PFNGLTEXSTORAGE1DPROC internal_f = (PFNGLTEXSTORAGE1DPROC)gapil_gl_func_table[486];
	assert(internal_f != NULL);
	return internal_f(target, levels, internalformat, width);
}

GLAPI void APIENTRY glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLTEXSTORAGE2DPROC internal_f = (PFNGLTEXSTORAGE2DPROC)gapil_gl_func_table[487];
	assert(internal_f != NULL);
	return internal_f(target, levels, internalformat, width, height);
}

GLAPI void APIENTRY glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
	PFNGLTEXSTORAGE3DPROC internal_f = (PFNGLTEXSTORAGE3DPROC)gapil_gl_func_table[488];
	assert(internal_f != NULL);
	return internal_f(target, levels, internalformat, width, height, depth);
}

GLAPI void APIENTRY glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount)
{
	PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC internal_f = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)gapil_gl_func_table[489];
	assert(internal_f != NULL);
	return internal_f(mode, id, instancecount);
}

GLAPI void APIENTRY glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount)
{
	PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC internal_f = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)gapil_gl_func_table[490];
	assert(internal_f != NULL);
	return internal_f(mode, id, stream, instancecount);
}

GLAPI void APIENTRY glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data)
{
	PFNGLCLEARBUFFERDATAPROC internal_f = (PFNGLCLEARBUFFERDATAPROC)gapil_gl_func_table[491];
	assert(internal_f != NULL);
	return internal_f(target, internalformat, format, type, data);
}

GLAPI void APIENTRY glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data)
{
	PFNGLCLEARBUFFERSUBDATAPROC internal_f = (PFNGLCLEARBUFFERSUBDATAPROC)gapil_gl_func_table[492];
	assert(internal_f != NULL);
	return internal_f(target, internalformat, offset, size, format, type, data);
}

GLAPI void APIENTRY glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)
{
	PFNGLDISPATCHCOMPUTEPROC internal_f = (PFNGLDISPATCHCOMPUTEPROC)gapil_gl_func_table[493];
	assert(internal_f != NULL);
	return internal_f(num_groups_x, num_groups_y, num_groups_z);
}

GLAPI void APIENTRY glDispatchComputeIndirect(GLintptr indirect)
{
	PFNGLDISPATCHCOMPUTEINDIRECTPROC internal_f = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)gapil_gl_func_table[494];
	assert(internal_f != NULL);
	return internal_f(indirect);
}

GLAPI void APIENTRY glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)
{
	PFNGLCOPYIMAGESUBDATAPROC internal_f = (PFNGLCOPYIMAGESUBDATAPROC)gapil_gl_func_table[495];
	assert(internal_f != NULL);
	return internal_f(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}

GLAPI void APIENTRY glFramebufferParameteri(GLenum target, GLenum pname, GLint param)
{
	PFNGLFRAMEBUFFERPARAMETERIPROC internal_f = (PFNGLFRAMEBUFFERPARAMETERIPROC)gapil_gl_func_table[496];
	assert(internal_f != NULL);
	return internal_f(target, pname, param);
}

GLAPI void APIENTRY glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETFRAMEBUFFERPARAMETERIVPROC internal_f = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)gapil_gl_func_table[497];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 * params)
{
	PFNGLGETINTERNALFORMATI64VPROC internal_f = (PFNGLGETINTERNALFORMATI64VPROC)gapil_gl_func_table[498];
	assert(internal_f != NULL);
	return internal_f(target, internalformat, pname, count, params);
}

GLAPI void APIENTRY glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth)
{
	PFNGLINVALIDATETEXSUBIMAGEPROC internal_f = (PFNGLINVALIDATETEXSUBIMAGEPROC)gapil_gl_func_table[499];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, yoffset, zoffset, width, height, depth);
}

GLAPI void APIENTRY glInvalidateTexImage(GLuint texture, GLint level)
{
	PFNGLINVALIDATETEXIMAGEPROC internal_f = (PFNGLINVALIDATETEXIMAGEPROC)gapil_gl_func_table[500];
	assert(internal_f != NULL);
	return internal_f(texture, level);
}

GLAPI void APIENTRY glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length)
{
	PFNGLINVALIDATEBUFFERSUBDATAPROC internal_f = (PFNGLINVALIDATEBUFFERSUBDATAPROC)gapil_gl_func_table[501];
	assert(internal_f != NULL);
	return internal_f(buffer, offset, length);
}

GLAPI void APIENTRY glInvalidateBufferData(GLuint buffer)
{
	PFNGLINVALIDATEBUFFERDATAPROC internal_f = (PFNGLINVALIDATEBUFFERDATAPROC)gapil_gl_func_table[502];
	assert(internal_f != NULL);
	return internal_f(buffer);
}

GLAPI void APIENTRY glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments)
{
	PFNGLINVALIDATEFRAMEBUFFERPROC internal_f = (PFNGLINVALIDATEFRAMEBUFFERPROC)gapil_gl_func_table[503];
	assert(internal_f != NULL);
	return internal_f(target, numAttachments, attachments);
}

GLAPI void APIENTRY glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLINVALIDATESUBFRAMEBUFFERPROC internal_f = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)gapil_gl_func_table[504];
	assert(internal_f != NULL);
	return internal_f(target, numAttachments, attachments, x, y, width, height);
}

GLAPI void APIENTRY glMultiDrawArraysIndirect(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride)
{
	PFNGLMULTIDRAWARRAYSINDIRECTPROC internal_f = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)gapil_gl_func_table[505];
	assert(internal_f != NULL);
	return internal_f(mode, indirect, drawcount, stride);
}

GLAPI void APIENTRY glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride)
{
	PFNGLMULTIDRAWELEMENTSINDIRECTPROC internal_f = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)gapil_gl_func_table[506];
	assert(internal_f != NULL);
	return internal_f(mode, type, indirect, drawcount, stride);
}

GLAPI void APIENTRY glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint * params)
{
	PFNGLGETPROGRAMINTERFACEIVPROC internal_f = (PFNGLGETPROGRAMINTERFACEIVPROC)gapil_gl_func_table[507];
	assert(internal_f != NULL);
	return internal_f(program, programInterface, pname, params);
}

GLAPI GLuint APIENTRY glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar * name)
{
	PFNGLGETPROGRAMRESOURCEINDEXPROC internal_f = (PFNGLGETPROGRAMRESOURCEINDEXPROC)gapil_gl_func_table[508];
	assert(internal_f != NULL);
	return internal_f(program, programInterface, name);
}

GLAPI void APIENTRY glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name)
{
	PFNGLGETPROGRAMRESOURCENAMEPROC internal_f = (PFNGLGETPROGRAMRESOURCENAMEPROC)gapil_gl_func_table[509];
	assert(internal_f != NULL);
	return internal_f(program, programInterface, index, bufSize, length, name);
}

GLAPI void APIENTRY glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLint * params)
{
	PFNGLGETPROGRAMRESOURCEIVPROC internal_f = (PFNGLGETPROGRAMRESOURCEIVPROC)gapil_gl_func_table[510];
	assert(internal_f != NULL);
	return internal_f(program, programInterface, index, propCount, props, count, length, params);
}

GLAPI GLint APIENTRY glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar * name)
{
	PFNGLGETPROGRAMRESOURCELOCATIONPROC internal_f = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)gapil_gl_func_table[511];
	assert(internal_f != NULL);
	return internal_f(program, programInterface, name);
}

GLAPI GLint APIENTRY glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar * name)
{
	PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC internal_f = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)gapil_gl_func_table[512];
	assert(internal_f != NULL);
	return internal_f(program, programInterface, name);
}

GLAPI void APIENTRY glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding)
{
	PFNGLSHADERSTORAGEBLOCKBINDINGPROC internal_f = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)gapil_gl_func_table[513];
	assert(internal_f != NULL);
	return internal_f(program, storageBlockIndex, storageBlockBinding);
}

GLAPI void APIENTRY glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	PFNGLTEXBUFFERRANGEPROC internal_f = (PFNGLTEXBUFFERRANGEPROC)gapil_gl_func_table[514];
	assert(internal_f != NULL);
	return internal_f(target, internalformat, buffer, offset, size);
}

GLAPI void APIENTRY glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
{
	PFNGLTEXSTORAGE2DMULTISAMPLEPROC internal_f = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)gapil_gl_func_table[515];
	assert(internal_f != NULL);
	return internal_f(target, samples, internalformat, width, height, fixedsamplelocations);
}

GLAPI void APIENTRY glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
{
	PFNGLTEXSTORAGE3DMULTISAMPLEPROC internal_f = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)gapil_gl_func_table[516];
	assert(internal_f != NULL);
	return internal_f(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

GLAPI void APIENTRY glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)
{
	PFNGLTEXTUREVIEWPROC internal_f = (PFNGLTEXTUREVIEWPROC)gapil_gl_func_table[517];
	assert(internal_f != NULL);
	return internal_f(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}

GLAPI void APIENTRY glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
{
	PFNGLBINDVERTEXBUFFERPROC internal_f = (PFNGLBINDVERTEXBUFFERPROC)gapil_gl_func_table[518];
	assert(internal_f != NULL);
	return internal_f(bindingindex, buffer, offset, stride);
}

GLAPI void APIENTRY glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
{
	PFNGLVERTEXATTRIBFORMATPROC internal_f = (PFNGLVERTEXATTRIBFORMATPROC)gapil_gl_func_table[519];
	assert(internal_f != NULL);
	return internal_f(attribindex, size, type, normalized, relativeoffset);
}

GLAPI void APIENTRY glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
	PFNGLVERTEXATTRIBIFORMATPROC internal_f = (PFNGLVERTEXATTRIBIFORMATPROC)gapil_gl_func_table[520];
	assert(internal_f != NULL);
	return internal_f(attribindex, size, type, relativeoffset);
}

GLAPI void APIENTRY glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
	PFNGLVERTEXATTRIBLFORMATPROC internal_f = (PFNGLVERTEXATTRIBLFORMATPROC)gapil_gl_func_table[521];
	assert(internal_f != NULL);
	return internal_f(attribindex, size, type, relativeoffset);
}

GLAPI void APIENTRY glVertexAttribBinding(GLuint attribindex, GLuint bindingindex)
{
	PFNGLVERTEXATTRIBBINDINGPROC internal_f = (PFNGLVERTEXATTRIBBINDINGPROC)gapil_gl_func_table[522];
	assert(internal_f != NULL);
	return internal_f(attribindex, bindingindex);
}

GLAPI void APIENTRY glVertexBindingDivisor(GLuint bindingindex, GLuint divisor)
{
	PFNGLVERTEXBINDINGDIVISORPROC internal_f = (PFNGLVERTEXBINDINGDIVISORPROC)gapil_gl_func_table[523];
	assert(internal_f != NULL);
	return internal_f(bindingindex, divisor);
}

GLAPI void APIENTRY glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled)
{
	PFNGLDEBUGMESSAGECONTROLPROC internal_f = (PFNGLDEBUGMESSAGECONTROLPROC)gapil_gl_func_table[524];
	assert(internal_f != NULL);
	return internal_f(source, type, severity, count, ids, enabled);
}

GLAPI void APIENTRY glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf)
{
	PFNGLDEBUGMESSAGEINSERTPROC internal_f = (PFNGLDEBUGMESSAGEINSERTPROC)gapil_gl_func_table[525];
	assert(internal_f != NULL);
	return internal_f(source, type, id, severity, length, buf);
}

GLAPI void APIENTRY glDebugMessageCallback(GLDEBUGPROC callback, const void * userParam)
{
	PFNGLDEBUGMESSAGECALLBACKPROC internal_f = (PFNGLDEBUGMESSAGECALLBACKPROC)gapil_gl_func_table[526];
	assert(internal_f != NULL);
	return internal_f(callback, userParam);
}

GLAPI GLuint APIENTRY glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog)
{
	PFNGLGETDEBUGMESSAGELOGPROC internal_f = (PFNGLGETDEBUGMESSAGELOGPROC)gapil_gl_func_table[527];
	assert(internal_f != NULL);
	return internal_f(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}

GLAPI void APIENTRY glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar * message)
{
	PFNGLPUSHDEBUGGROUPPROC internal_f = (PFNGLPUSHDEBUGGROUPPROC)gapil_gl_func_table[528];
	assert(internal_f != NULL);
	return internal_f(source, id, length, message);
}

GLAPI void APIENTRY glPopDebugGroup()
{
	PFNGLPOPDEBUGGROUPPROC internal_f = (PFNGLPOPDEBUGGROUPPROC)gapil_gl_func_table[529];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar * label)
{
	PFNGLOBJECTLABELPROC internal_f = (PFNGLOBJECTLABELPROC)gapil_gl_func_table[530];
	assert(internal_f != NULL);
	return internal_f(identifier, name, length, label);
}

GLAPI void APIENTRY glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label)
{
	PFNGLGETOBJECTLABELPROC internal_f = (PFNGLGETOBJECTLABELPROC)gapil_gl_func_table[531];
	assert(internal_f != NULL);
	return internal_f(identifier, name, bufSize, length, label);
}

GLAPI void APIENTRY glObjectPtrLabel(const void * ptr, GLsizei length, const GLchar * label)
{
	PFNGLOBJECTPTRLABELPROC internal_f = (PFNGLOBJECTPTRLABELPROC)gapil_gl_func_table[532];
	assert(internal_f != NULL);
	return internal_f(ptr, length, label);
}

GLAPI void APIENTRY glGetObjectPtrLabel(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label)
{
	PFNGLGETOBJECTPTRLABELPROC internal_f = (PFNGLGETOBJECTPTRLABELPROC)gapil_gl_func_table[533];
	assert(internal_f != NULL);
	return internal_f(ptr, bufSize, length, label);
}

GLAPI void APIENTRY glBufferStorage(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags)
{
	PFNGLBUFFERSTORAGEPROC internal_f = (PFNGLBUFFERSTORAGEPROC)gapil_gl_func_table[534];
	assert(internal_f != NULL);
	return internal_f(target, size, data, flags);
}

GLAPI void APIENTRY glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void * data)
{
	PFNGLCLEARTEXIMAGEPROC internal_f = (PFNGLCLEARTEXIMAGEPROC)gapil_gl_func_table[535];
	assert(internal_f != NULL);
	return internal_f(texture, level, format, type, data);
}

GLAPI void APIENTRY glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data)
{
	PFNGLCLEARTEXSUBIMAGEPROC internal_f = (PFNGLCLEARTEXSUBIMAGEPROC)gapil_gl_func_table[536];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}

GLAPI void APIENTRY glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint * buffers)
{
	PFNGLBINDBUFFERSBASEPROC internal_f = (PFNGLBINDBUFFERSBASEPROC)gapil_gl_func_table[537];
	assert(internal_f != NULL);
	return internal_f(target, first, count, buffers);
}

GLAPI void APIENTRY glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes)
{
	PFNGLBINDBUFFERSRANGEPROC internal_f = (PFNGLBINDBUFFERSRANGEPROC)gapil_gl_func_table[538];
	assert(internal_f != NULL);
	return internal_f(target, first, count, buffers, offsets, sizes);
}

GLAPI void APIENTRY glBindTextures(GLuint first, GLsizei count, const GLuint * textures)
{
	PFNGLBINDTEXTURESPROC internal_f = (PFNGLBINDTEXTURESPROC)gapil_gl_func_table[539];
	assert(internal_f != NULL);
	return internal_f(first, count, textures);
}

GLAPI void APIENTRY glBindSamplers(GLuint first, GLsizei count, const GLuint * samplers)
{
	PFNGLBINDSAMPLERSPROC internal_f = (PFNGLBINDSAMPLERSPROC)gapil_gl_func_table[540];
	assert(internal_f != NULL);
	return internal_f(first, count, samplers);
}

GLAPI void APIENTRY glBindImageTextures(GLuint first, GLsizei count, const GLuint * textures)
{
	PFNGLBINDIMAGETEXTURESPROC internal_f = (PFNGLBINDIMAGETEXTURESPROC)gapil_gl_func_table[541];
	assert(internal_f != NULL);
	return internal_f(first, count, textures);
}

GLAPI void APIENTRY glBindVertexBuffers(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides)
{
	PFNGLBINDVERTEXBUFFERSPROC internal_f = (PFNGLBINDVERTEXBUFFERSPROC)gapil_gl_func_table[542];
	assert(internal_f != NULL);
	return internal_f(first, count, buffers, offsets, strides);
}

GLAPI void APIENTRY glClipControl(GLenum origin, GLenum depth)
{
	PFNGLCLIPCONTROLPROC internal_f = (PFNGLCLIPCONTROLPROC)gapil_gl_func_table[543];
	assert(internal_f != NULL);
	return internal_f(origin, depth);
}

GLAPI void APIENTRY glCreateTransformFeedbacks(GLsizei n, GLuint * ids)
{
	PFNGLCREATETRANSFORMFEEDBACKSPROC internal_f = (PFNGLCREATETRANSFORMFEEDBACKSPROC)gapil_gl_func_table[544];
	assert(internal_f != NULL);
	return internal_f(n, ids);
}

GLAPI void APIENTRY glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer)
{
	PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC internal_f = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)gapil_gl_func_table[545];
	assert(internal_f != NULL);
	return internal_f(xfb, index, buffer);
}

GLAPI void APIENTRY glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC internal_f = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)gapil_gl_func_table[546];
	assert(internal_f != NULL);
	return internal_f(xfb, index, buffer, offset, size);
}

GLAPI void APIENTRY glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint * param)
{
	PFNGLGETTRANSFORMFEEDBACKIVPROC internal_f = (PFNGLGETTRANSFORMFEEDBACKIVPROC)gapil_gl_func_table[547];
	assert(internal_f != NULL);
	return internal_f(xfb, pname, param);
}

GLAPI void APIENTRY glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint * param)
{
	PFNGLGETTRANSFORMFEEDBACKI_VPROC internal_f = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)gapil_gl_func_table[548];
	assert(internal_f != NULL);
	return internal_f(xfb, pname, index, param);
}

GLAPI void APIENTRY glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 * param)
{
	PFNGLGETTRANSFORMFEEDBACKI64_VPROC internal_f = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)gapil_gl_func_table[549];
	assert(internal_f != NULL);
	return internal_f(xfb, pname, index, param);
}

GLAPI void APIENTRY glCreateBuffers(GLsizei n, GLuint * buffers)
{
	PFNGLCREATEBUFFERSPROC internal_f = (PFNGLCREATEBUFFERSPROC)gapil_gl_func_table[550];
	assert(internal_f != NULL);
	return internal_f(n, buffers);
}

GLAPI void APIENTRY glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags)
{
	PFNGLNAMEDBUFFERSTORAGEPROC internal_f = (PFNGLNAMEDBUFFERSTORAGEPROC)gapil_gl_func_table[551];
	assert(internal_f != NULL);
	return internal_f(buffer, size, data, flags);
}

GLAPI void APIENTRY glNamedBufferData(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage)
{
	PFNGLNAMEDBUFFERDATAPROC internal_f = (PFNGLNAMEDBUFFERDATAPROC)gapil_gl_func_table[552];
	assert(internal_f != NULL);
	return internal_f(buffer, size, data, usage);
}

GLAPI void APIENTRY glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data)
{
	PFNGLNAMEDBUFFERSUBDATAPROC internal_f = (PFNGLNAMEDBUFFERSUBDATAPROC)gapil_gl_func_table[553];
	assert(internal_f != NULL);
	return internal_f(buffer, offset, size, data);
}

GLAPI void APIENTRY glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
{
	PFNGLCOPYNAMEDBUFFERSUBDATAPROC internal_f = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)gapil_gl_func_table[554];
	assert(internal_f != NULL);
	return internal_f(readBuffer, writeBuffer, readOffset, writeOffset, size);
}

GLAPI void APIENTRY glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data)
{
	PFNGLCLEARNAMEDBUFFERDATAPROC internal_f = (PFNGLCLEARNAMEDBUFFERDATAPROC)gapil_gl_func_table[555];
	assert(internal_f != NULL);
	return internal_f(buffer, internalformat, format, type, data);
}

GLAPI void APIENTRY glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data)
{
	PFNGLCLEARNAMEDBUFFERSUBDATAPROC internal_f = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)gapil_gl_func_table[556];
	assert(internal_f != NULL);
	return internal_f(buffer, internalformat, offset, size, format, type, data);
}

GLAPI void * APIENTRY glMapNamedBuffer(GLuint buffer, GLenum access)
{
	PFNGLMAPNAMEDBUFFERPROC internal_f = (PFNGLMAPNAMEDBUFFERPROC)gapil_gl_func_table[557];
	assert(internal_f != NULL);
	return internal_f(buffer, access);
}

GLAPI void * APIENTRY glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
	PFNGLMAPNAMEDBUFFERRANGEPROC internal_f = (PFNGLMAPNAMEDBUFFERRANGEPROC)gapil_gl_func_table[558];
	assert(internal_f != NULL);
	return internal_f(buffer, offset, length, access);
}

GLAPI GLboolean APIENTRY glUnmapNamedBuffer(GLuint buffer)
{
	PFNGLUNMAPNAMEDBUFFERPROC internal_f = (PFNGLUNMAPNAMEDBUFFERPROC)gapil_gl_func_table[559];
	assert(internal_f != NULL);
	return internal_f(buffer);
}

GLAPI void APIENTRY glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length)
{
	PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC internal_f = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)gapil_gl_func_table[560];
	assert(internal_f != NULL);
	return internal_f(buffer, offset, length);
}

GLAPI void APIENTRY glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint * params)
{
	PFNGLGETNAMEDBUFFERPARAMETERIVPROC internal_f = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)gapil_gl_func_table[561];
	assert(internal_f != NULL);
	return internal_f(buffer, pname, params);
}

GLAPI void APIENTRY glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 * params)
{
	PFNGLGETNAMEDBUFFERPARAMETERI64VPROC internal_f = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)gapil_gl_func_table[562];
	assert(internal_f != NULL);
	return internal_f(buffer, pname, params);
}

GLAPI void APIENTRY glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void ** params)
{
	PFNGLGETNAMEDBUFFERPOINTERVPROC internal_f = (PFNGLGETNAMEDBUFFERPOINTERVPROC)gapil_gl_func_table[563];
	assert(internal_f != NULL);
	return internal_f(buffer, pname, params);
}

GLAPI void APIENTRY glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data)
{
	PFNGLGETNAMEDBUFFERSUBDATAPROC internal_f = (PFNGLGETNAMEDBUFFERSUBDATAPROC)gapil_gl_func_table[564];
	assert(internal_f != NULL);
	return internal_f(buffer, offset, size, data);
}

GLAPI void APIENTRY glCreateFramebuffers(GLsizei n, GLuint * framebuffers)
{
	PFNGLCREATEFRAMEBUFFERSPROC internal_f = (PFNGLCREATEFRAMEBUFFERSPROC)gapil_gl_func_table[565];
	assert(internal_f != NULL);
	return internal_f(n, framebuffers);
}

GLAPI void APIENTRY glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
	PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC internal_f = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)gapil_gl_func_table[566];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, renderbuffertarget, renderbuffer);
}

GLAPI void APIENTRY glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param)
{
	PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC internal_f = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)gapil_gl_func_table[567];
	assert(internal_f != NULL);
	return internal_f(framebuffer, pname, param);
}

GLAPI void APIENTRY glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level)
{
	PFNGLNAMEDFRAMEBUFFERTEXTUREPROC internal_f = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)gapil_gl_func_table[568];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, texture, level);
}

GLAPI void APIENTRY glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
	PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC internal_f = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)gapil_gl_func_table[569];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, texture, level, layer);
}

GLAPI void APIENTRY glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf)
{
	PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC internal_f = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)gapil_gl_func_table[570];
	assert(internal_f != NULL);
	return internal_f(framebuffer, buf);
}

GLAPI void APIENTRY glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum * bufs)
{
	PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC internal_f = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)gapil_gl_func_table[571];
	assert(internal_f != NULL);
	return internal_f(framebuffer, n, bufs);
}

GLAPI void APIENTRY glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src)
{
	PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC internal_f = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)gapil_gl_func_table[572];
	assert(internal_f != NULL);
	return internal_f(framebuffer, src);
}

GLAPI void APIENTRY glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments)
{
	PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC internal_f = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)gapil_gl_func_table[573];
	assert(internal_f != NULL);
	return internal_f(framebuffer, numAttachments, attachments);
}

GLAPI void APIENTRY glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC internal_f = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)gapil_gl_func_table[574];
	assert(internal_f != NULL);
	return internal_f(framebuffer, numAttachments, attachments, x, y, width, height);
}

GLAPI void APIENTRY glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint * value)
{
	PFNGLCLEARNAMEDFRAMEBUFFERIVPROC internal_f = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)gapil_gl_func_table[575];
	assert(internal_f != NULL);
	return internal_f(framebuffer, buffer, drawbuffer, value);
}

GLAPI void APIENTRY glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint * value)
{
	PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC internal_f = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)gapil_gl_func_table[576];
	assert(internal_f != NULL);
	return internal_f(framebuffer, buffer, drawbuffer, value);
}

GLAPI void APIENTRY glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat * value)
{
	PFNGLCLEARNAMEDFRAMEBUFFERFVPROC internal_f = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)gapil_gl_func_table[577];
	assert(internal_f != NULL);
	return internal_f(framebuffer, buffer, drawbuffer, value);
}

GLAPI void APIENTRY glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
{
	PFNGLCLEARNAMEDFRAMEBUFFERFIPROC internal_f = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)gapil_gl_func_table[578];
	assert(internal_f != NULL);
	return internal_f(framebuffer, buffer, drawbuffer, depth, stencil);
}

GLAPI void APIENTRY glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
{
	PFNGLBLITNAMEDFRAMEBUFFERPROC internal_f = (PFNGLBLITNAMEDFRAMEBUFFERPROC)gapil_gl_func_table[579];
	assert(internal_f != NULL);
	return internal_f(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

GLAPI GLenum APIENTRY glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target)
{
	PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC internal_f = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)gapil_gl_func_table[580];
	assert(internal_f != NULL);
	return internal_f(framebuffer, target);
}

GLAPI void APIENTRY glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint * param)
{
	PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC internal_f = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)gapil_gl_func_table[581];
	assert(internal_f != NULL);
	return internal_f(framebuffer, pname, param);
}

GLAPI void APIENTRY glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params)
{
	PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC internal_f = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)gapil_gl_func_table[582];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, pname, params);
}

GLAPI void APIENTRY glCreateRenderbuffers(GLsizei n, GLuint * renderbuffers)
{
	PFNGLCREATERENDERBUFFERSPROC internal_f = (PFNGLCREATERENDERBUFFERSPROC)gapil_gl_func_table[583];
	assert(internal_f != NULL);
	return internal_f(n, renderbuffers);
}

GLAPI void APIENTRY glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLNAMEDRENDERBUFFERSTORAGEPROC internal_f = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)gapil_gl_func_table[584];
	assert(internal_f != NULL);
	return internal_f(renderbuffer, internalformat, width, height);
}

GLAPI void APIENTRY glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC internal_f = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)gapil_gl_func_table[585];
	assert(internal_f != NULL);
	return internal_f(renderbuffer, samples, internalformat, width, height);
}

GLAPI void APIENTRY glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint * params)
{
	PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC internal_f = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)gapil_gl_func_table[586];
	assert(internal_f != NULL);
	return internal_f(renderbuffer, pname, params);
}

GLAPI void APIENTRY glCreateTextures(GLenum target, GLsizei n, GLuint * textures)
{
	PFNGLCREATETEXTURESPROC internal_f = (PFNGLCREATETEXTURESPROC)gapil_gl_func_table[587];
	assert(internal_f != NULL);
	return internal_f(target, n, textures);
}

GLAPI void APIENTRY glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer)
{
	PFNGLTEXTUREBUFFERPROC internal_f = (PFNGLTEXTUREBUFFERPROC)gapil_gl_func_table[588];
	assert(internal_f != NULL);
	return internal_f(texture, internalformat, buffer);
}

GLAPI void APIENTRY glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	PFNGLTEXTUREBUFFERRANGEPROC internal_f = (PFNGLTEXTUREBUFFERRANGEPROC)gapil_gl_func_table[589];
	assert(internal_f != NULL);
	return internal_f(texture, internalformat, buffer, offset, size);
}

GLAPI void APIENTRY glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width)
{
	PFNGLTEXTURESTORAGE1DPROC internal_f = (PFNGLTEXTURESTORAGE1DPROC)gapil_gl_func_table[590];
	assert(internal_f != NULL);
	return internal_f(texture, levels, internalformat, width);
}

GLAPI void APIENTRY glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLTEXTURESTORAGE2DPROC internal_f = (PFNGLTEXTURESTORAGE2DPROC)gapil_gl_func_table[591];
	assert(internal_f != NULL);
	return internal_f(texture, levels, internalformat, width, height);
}

GLAPI void APIENTRY glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
	PFNGLTEXTURESTORAGE3DPROC internal_f = (PFNGLTEXTURESTORAGE3DPROC)gapil_gl_func_table[592];
	assert(internal_f != NULL);
	return internal_f(texture, levels, internalformat, width, height, depth);
}

GLAPI void APIENTRY glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
{
	PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC internal_f = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)gapil_gl_func_table[593];
	assert(internal_f != NULL);
	return internal_f(texture, samples, internalformat, width, height, fixedsamplelocations);
}

GLAPI void APIENTRY glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
{
	PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC internal_f = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)gapil_gl_func_table[594];
	assert(internal_f != NULL);
	return internal_f(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}

GLAPI void APIENTRY glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXTURESUBIMAGE1DPROC internal_f = (PFNGLTEXTURESUBIMAGE1DPROC)gapil_gl_func_table[595];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, width, format, type, pixels);
}

GLAPI void APIENTRY glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXTURESUBIMAGE2DPROC internal_f = (PFNGLTEXTURESUBIMAGE2DPROC)gapil_gl_func_table[596];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, yoffset, width, height, format, type, pixels);
}

GLAPI void APIENTRY glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXTURESUBIMAGE3DPROC internal_f = (PFNGLTEXTURESUBIMAGE3DPROC)gapil_gl_func_table[597];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

GLAPI void APIENTRY glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data)
{
	PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC internal_f = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)gapil_gl_func_table[598];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, width, format, imageSize, data);
}

GLAPI void APIENTRY glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data)
{
	PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC internal_f = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)gapil_gl_func_table[599];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}

GLAPI void APIENTRY glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data)
{
	PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC internal_f = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)gapil_gl_func_table[600];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

GLAPI void APIENTRY glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
	PFNGLCOPYTEXTURESUBIMAGE1DPROC internal_f = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)gapil_gl_func_table[601];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, x, y, width);
}

GLAPI void APIENTRY glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLCOPYTEXTURESUBIMAGE2DPROC internal_f = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)gapil_gl_func_table[602];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, yoffset, x, y, width, height);
}

GLAPI void APIENTRY glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLCOPYTEXTURESUBIMAGE3DPROC internal_f = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)gapil_gl_func_table[603];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}

GLAPI void APIENTRY glTextureParameterf(GLuint texture, GLenum pname, GLfloat param)
{
	PFNGLTEXTUREPARAMETERFPROC internal_f = (PFNGLTEXTUREPARAMETERFPROC)gapil_gl_func_table[604];
	assert(internal_f != NULL);
	return internal_f(texture, pname, param);
}

GLAPI void APIENTRY glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat * param)
{
	PFNGLTEXTUREPARAMETERFVPROC internal_f = (PFNGLTEXTUREPARAMETERFVPROC)gapil_gl_func_table[605];
	assert(internal_f != NULL);
	return internal_f(texture, pname, param);
}

GLAPI void APIENTRY glTextureParameteri(GLuint texture, GLenum pname, GLint param)
{
	PFNGLTEXTUREPARAMETERIPROC internal_f = (PFNGLTEXTUREPARAMETERIPROC)gapil_gl_func_table[606];
	assert(internal_f != NULL);
	return internal_f(texture, pname, param);
}

GLAPI void APIENTRY glTextureParameterIiv(GLuint texture, GLenum pname, const GLint * params)
{
	PFNGLTEXTUREPARAMETERIIVPROC internal_f = (PFNGLTEXTUREPARAMETERIIVPROC)gapil_gl_func_table[607];
	assert(internal_f != NULL);
	return internal_f(texture, pname, params);
}

GLAPI void APIENTRY glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint * params)
{
	PFNGLTEXTUREPARAMETERIUIVPROC internal_f = (PFNGLTEXTUREPARAMETERIUIVPROC)gapil_gl_func_table[608];
	assert(internal_f != NULL);
	return internal_f(texture, pname, params);
}

GLAPI void APIENTRY glTextureParameteriv(GLuint texture, GLenum pname, const GLint * param)
{
	PFNGLTEXTUREPARAMETERIVPROC internal_f = (PFNGLTEXTUREPARAMETERIVPROC)gapil_gl_func_table[609];
	assert(internal_f != NULL);
	return internal_f(texture, pname, param);
}

GLAPI void APIENTRY glGenerateTextureMipmap(GLuint texture)
{
	PFNGLGENERATETEXTUREMIPMAPPROC internal_f = (PFNGLGENERATETEXTUREMIPMAPPROC)gapil_gl_func_table[610];
	assert(internal_f != NULL);
	return internal_f(texture);
}

GLAPI void APIENTRY glBindTextureUnit(GLuint unit, GLuint texture)
{
	PFNGLBINDTEXTUREUNITPROC internal_f = (PFNGLBINDTEXTUREUNITPROC)gapil_gl_func_table[611];
	assert(internal_f != NULL);
	return internal_f(unit, texture);
}

GLAPI void APIENTRY glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels)
{
	PFNGLGETTEXTUREIMAGEPROC internal_f = (PFNGLGETTEXTUREIMAGEPROC)gapil_gl_func_table[612];
	assert(internal_f != NULL);
	return internal_f(texture, level, format, type, bufSize, pixels);
}

GLAPI void APIENTRY glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void * pixels)
{
	PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC internal_f = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)gapil_gl_func_table[613];
	assert(internal_f != NULL);
	return internal_f(texture, level, bufSize, pixels);
}

GLAPI void APIENTRY glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat * params)
{
	PFNGLGETTEXTURELEVELPARAMETERFVPROC internal_f = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)gapil_gl_func_table[614];
	assert(internal_f != NULL);
	return internal_f(texture, level, pname, params);
}

GLAPI void APIENTRY glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint * params)
{
	PFNGLGETTEXTURELEVELPARAMETERIVPROC internal_f = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)gapil_gl_func_table[615];
	assert(internal_f != NULL);
	return internal_f(texture, level, pname, params);
}

GLAPI void APIENTRY glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat * params)
{
	PFNGLGETTEXTUREPARAMETERFVPROC internal_f = (PFNGLGETTEXTUREPARAMETERFVPROC)gapil_gl_func_table[616];
	assert(internal_f != NULL);
	return internal_f(texture, pname, params);
}

GLAPI void APIENTRY glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint * params)
{
	PFNGLGETTEXTUREPARAMETERIIVPROC internal_f = (PFNGLGETTEXTUREPARAMETERIIVPROC)gapil_gl_func_table[617];
	assert(internal_f != NULL);
	return internal_f(texture, pname, params);
}

GLAPI void APIENTRY glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint * params)
{
	PFNGLGETTEXTUREPARAMETERIUIVPROC internal_f = (PFNGLGETTEXTUREPARAMETERIUIVPROC)gapil_gl_func_table[618];
	assert(internal_f != NULL);
	return internal_f(texture, pname, params);
}

GLAPI void APIENTRY glGetTextureParameteriv(GLuint texture, GLenum pname, GLint * params)
{
	PFNGLGETTEXTUREPARAMETERIVPROC internal_f = (PFNGLGETTEXTUREPARAMETERIVPROC)gapil_gl_func_table[619];
	assert(internal_f != NULL);
	return internal_f(texture, pname, params);
}

GLAPI void APIENTRY glCreateVertexArrays(GLsizei n, GLuint * arrays)
{
	PFNGLCREATEVERTEXARRAYSPROC internal_f = (PFNGLCREATEVERTEXARRAYSPROC)gapil_gl_func_table[620];
	assert(internal_f != NULL);
	return internal_f(n, arrays);
}

GLAPI void APIENTRY glDisableVertexArrayAttrib(GLuint vaobj, GLuint index)
{
	PFNGLDISABLEVERTEXARRAYATTRIBPROC internal_f = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)gapil_gl_func_table[621];
	assert(internal_f != NULL);
	return internal_f(vaobj, index);
}

GLAPI void APIENTRY glEnableVertexArrayAttrib(GLuint vaobj, GLuint index)
{
	PFNGLENABLEVERTEXARRAYATTRIBPROC internal_f = (PFNGLENABLEVERTEXARRAYATTRIBPROC)gapil_gl_func_table[622];
	assert(internal_f != NULL);
	return internal_f(vaobj, index);
}

GLAPI void APIENTRY glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer)
{
	PFNGLVERTEXARRAYELEMENTBUFFERPROC internal_f = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)gapil_gl_func_table[623];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer);
}

GLAPI void APIENTRY glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
{
	PFNGLVERTEXARRAYVERTEXBUFFERPROC internal_f = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)gapil_gl_func_table[624];
	assert(internal_f != NULL);
	return internal_f(vaobj, bindingindex, buffer, offset, stride);
}

GLAPI void APIENTRY glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides)
{
	PFNGLVERTEXARRAYVERTEXBUFFERSPROC internal_f = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)gapil_gl_func_table[625];
	assert(internal_f != NULL);
	return internal_f(vaobj, first, count, buffers, offsets, strides);
}

GLAPI void APIENTRY glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex)
{
	PFNGLVERTEXARRAYATTRIBBINDINGPROC internal_f = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)gapil_gl_func_table[626];
	assert(internal_f != NULL);
	return internal_f(vaobj, attribindex, bindingindex);
}

GLAPI void APIENTRY glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
{
	PFNGLVERTEXARRAYATTRIBFORMATPROC internal_f = (PFNGLVERTEXARRAYATTRIBFORMATPROC)gapil_gl_func_table[627];
	assert(internal_f != NULL);
	return internal_f(vaobj, attribindex, size, type, normalized, relativeoffset);
}

GLAPI void APIENTRY glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
	PFNGLVERTEXARRAYATTRIBIFORMATPROC internal_f = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)gapil_gl_func_table[628];
	assert(internal_f != NULL);
	return internal_f(vaobj, attribindex, size, type, relativeoffset);
}

GLAPI void APIENTRY glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
	PFNGLVERTEXARRAYATTRIBLFORMATPROC internal_f = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)gapil_gl_func_table[629];
	assert(internal_f != NULL);
	return internal_f(vaobj, attribindex, size, type, relativeoffset);
}

GLAPI void APIENTRY glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor)
{
	PFNGLVERTEXARRAYBINDINGDIVISORPROC internal_f = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)gapil_gl_func_table[630];
	assert(internal_f != NULL);
	return internal_f(vaobj, bindingindex, divisor);
}

GLAPI void APIENTRY glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint * param)
{
	PFNGLGETVERTEXARRAYIVPROC internal_f = (PFNGLGETVERTEXARRAYIVPROC)gapil_gl_func_table[631];
	assert(internal_f != NULL);
	return internal_f(vaobj, pname, param);
}

GLAPI void APIENTRY glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint * param)
{
	PFNGLGETVERTEXARRAYINDEXEDIVPROC internal_f = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)gapil_gl_func_table[632];
	assert(internal_f != NULL);
	return internal_f(vaobj, index, pname, param);
}

GLAPI void APIENTRY glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param)
{
	PFNGLGETVERTEXARRAYINDEXED64IVPROC internal_f = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)gapil_gl_func_table[633];
	assert(internal_f != NULL);
	return internal_f(vaobj, index, pname, param);
}

GLAPI void APIENTRY glCreateSamplers(GLsizei n, GLuint * samplers)
{
	PFNGLCREATESAMPLERSPROC internal_f = (PFNGLCREATESAMPLERSPROC)gapil_gl_func_table[634];
	assert(internal_f != NULL);
	return internal_f(n, samplers);
}

GLAPI void APIENTRY glCreateProgramPipelines(GLsizei n, GLuint * pipelines)
{
	PFNGLCREATEPROGRAMPIPELINESPROC internal_f = (PFNGLCREATEPROGRAMPIPELINESPROC)gapil_gl_func_table[635];
	assert(internal_f != NULL);
	return internal_f(n, pipelines);
}

GLAPI void APIENTRY glCreateQueries(GLenum target, GLsizei n, GLuint * ids)
{
	PFNGLCREATEQUERIESPROC internal_f = (PFNGLCREATEQUERIESPROC)gapil_gl_func_table[636];
	assert(internal_f != NULL);
	return internal_f(target, n, ids);
}

GLAPI void APIENTRY glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
{
	PFNGLGETQUERYBUFFEROBJECTI64VPROC internal_f = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)gapil_gl_func_table[637];
	assert(internal_f != NULL);
	return internal_f(id, buffer, pname, offset);
}

GLAPI void APIENTRY glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
{
	PFNGLGETQUERYBUFFEROBJECTIVPROC internal_f = (PFNGLGETQUERYBUFFEROBJECTIVPROC)gapil_gl_func_table[638];
	assert(internal_f != NULL);
	return internal_f(id, buffer, pname, offset);
}

GLAPI void APIENTRY glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
{
	PFNGLGETQUERYBUFFEROBJECTUI64VPROC internal_f = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)gapil_gl_func_table[639];
	assert(internal_f != NULL);
	return internal_f(id, buffer, pname, offset);
}

GLAPI void APIENTRY glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
{
	PFNGLGETQUERYBUFFEROBJECTUIVPROC internal_f = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)gapil_gl_func_table[640];
	assert(internal_f != NULL);
	return internal_f(id, buffer, pname, offset);
}

GLAPI void APIENTRY glMemoryBarrierByRegion(GLbitfield barriers)
{
	PFNGLMEMORYBARRIERBYREGIONPROC internal_f = (PFNGLMEMORYBARRIERBYREGIONPROC)gapil_gl_func_table[641];
	assert(internal_f != NULL);
	return internal_f(barriers);
}

GLAPI void APIENTRY glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels)
{
	PFNGLGETTEXTURESUBIMAGEPROC internal_f = (PFNGLGETTEXTURESUBIMAGEPROC)gapil_gl_func_table[642];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}

GLAPI void APIENTRY glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels)
{
	PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC internal_f = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)gapil_gl_func_table[643];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}

GLAPI GLenum APIENTRY glGetGraphicsResetStatus()
{
	PFNGLGETGRAPHICSRESETSTATUSPROC internal_f = (PFNGLGETGRAPHICSRESETSTATUSPROC)gapil_gl_func_table[644];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void * pixels)
{
	PFNGLGETNCOMPRESSEDTEXIMAGEPROC internal_f = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC)gapil_gl_func_table[645];
	assert(internal_f != NULL);
	return internal_f(target, lod, bufSize, pixels);
}

GLAPI void APIENTRY glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels)
{
	PFNGLGETNTEXIMAGEPROC internal_f = (PFNGLGETNTEXIMAGEPROC)gapil_gl_func_table[646];
	assert(internal_f != NULL);
	return internal_f(target, level, format, type, bufSize, pixels);
}

GLAPI void APIENTRY glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble * params)
{
	PFNGLGETNUNIFORMDVPROC internal_f = (PFNGLGETNUNIFORMDVPROC)gapil_gl_func_table[647];
	assert(internal_f != NULL);
	return internal_f(program, location, bufSize, params);
}

GLAPI void APIENTRY glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat * params)
{
	PFNGLGETNUNIFORMFVPROC internal_f = (PFNGLGETNUNIFORMFVPROC)gapil_gl_func_table[648];
	assert(internal_f != NULL);
	return internal_f(program, location, bufSize, params);
}

GLAPI void APIENTRY glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint * params)
{
	PFNGLGETNUNIFORMIVPROC internal_f = (PFNGLGETNUNIFORMIVPROC)gapil_gl_func_table[649];
	assert(internal_f != NULL);
	return internal_f(program, location, bufSize, params);
}

GLAPI void APIENTRY glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint * params)
{
	PFNGLGETNUNIFORMUIVPROC internal_f = (PFNGLGETNUNIFORMUIVPROC)gapil_gl_func_table[650];
	assert(internal_f != NULL);
	return internal_f(program, location, bufSize, params);
}

GLAPI void APIENTRY glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data)
{
	PFNGLREADNPIXELSPROC internal_f = (PFNGLREADNPIXELSPROC)gapil_gl_func_table[651];
	assert(internal_f != NULL);
	return internal_f(x, y, width, height, format, type, bufSize, data);
}

GLAPI void APIENTRY glTextureBarrier()
{
	PFNGLTEXTUREBARRIERPROC internal_f = (PFNGLTEXTUREBARRIERPROC)gapil_gl_func_table[652];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glSpecializeShader(GLuint shader, const GLchar * pEntryPoint, GLuint numSpecializationConstants, const GLuint * pConstantIndex, const GLuint * pConstantValue)
{
	PFNGLSPECIALIZESHADERPROC internal_f = (PFNGLSPECIALIZESHADERPROC)gapil_gl_func_table[653];
	assert(internal_f != NULL);
	return internal_f(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}

GLAPI void APIENTRY glMultiDrawArraysIndirectCount(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
{
	PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC internal_f = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)gapil_gl_func_table[654];
	assert(internal_f != NULL);
	return internal_f(mode, indirect, drawcount, maxdrawcount, stride);
}

GLAPI void APIENTRY glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
{
	PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC internal_f = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)gapil_gl_func_table[655];
	assert(internal_f != NULL);
	return internal_f(mode, type, indirect, drawcount, maxdrawcount, stride);
}

GLAPI void APIENTRY glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp)
{
	PFNGLPOLYGONOFFSETCLAMPPROC internal_f = (PFNGLPOLYGONOFFSETCLAMPPROC)gapil_gl_func_table[656];
	assert(internal_f != NULL);
	return internal_f(factor, units, clamp);
}

GLAPI void APIENTRY glPrimitiveBoundingBoxARB(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW)
{
	PFNGLPRIMITIVEBOUNDINGBOXARBPROC internal_f = (PFNGLPRIMITIVEBOUNDINGBOXARBPROC)gapil_gl_func_table[657];
	assert(internal_f != NULL);
	return internal_f(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}

GLAPI GLuint64 APIENTRY glGetTextureHandleARB(GLuint texture)
{
	PFNGLGETTEXTUREHANDLEARBPROC internal_f = (PFNGLGETTEXTUREHANDLEARBPROC)gapil_gl_func_table[658];
	assert(internal_f != NULL);
	return internal_f(texture);
}

GLAPI GLuint64 APIENTRY glGetTextureSamplerHandleARB(GLuint texture, GLuint sampler)
{
	PFNGLGETTEXTURESAMPLERHANDLEARBPROC internal_f = (PFNGLGETTEXTURESAMPLERHANDLEARBPROC)gapil_gl_func_table[659];
	assert(internal_f != NULL);
	return internal_f(texture, sampler);
}

GLAPI void APIENTRY glMakeTextureHandleResidentARB(GLuint64 handle)
{
	PFNGLMAKETEXTUREHANDLERESIDENTARBPROC internal_f = (PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)gapil_gl_func_table[660];
	assert(internal_f != NULL);
	return internal_f(handle);
}

GLAPI void APIENTRY glMakeTextureHandleNonResidentARB(GLuint64 handle)
{
	PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC internal_f = (PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)gapil_gl_func_table[661];
	assert(internal_f != NULL);
	return internal_f(handle);
}

GLAPI GLuint64 APIENTRY glGetImageHandleARB(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format)
{
	PFNGLGETIMAGEHANDLEARBPROC internal_f = (PFNGLGETIMAGEHANDLEARBPROC)gapil_gl_func_table[662];
	assert(internal_f != NULL);
	return internal_f(texture, level, layered, layer, format);
}

GLAPI void APIENTRY glMakeImageHandleResidentARB(GLuint64 handle, GLenum access)
{
	PFNGLMAKEIMAGEHANDLERESIDENTARBPROC internal_f = (PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)gapil_gl_func_table[663];
	assert(internal_f != NULL);
	return internal_f(handle, access);
}

GLAPI void APIENTRY glMakeImageHandleNonResidentARB(GLuint64 handle)
{
	PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC internal_f = (PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)gapil_gl_func_table[664];
	assert(internal_f != NULL);
	return internal_f(handle);
}

GLAPI void APIENTRY glUniformHandleui64ARB(GLint location, GLuint64 value)
{
	PFNGLUNIFORMHANDLEUI64ARBPROC internal_f = (PFNGLUNIFORMHANDLEUI64ARBPROC)gapil_gl_func_table[665];
	assert(internal_f != NULL);
	return internal_f(location, value);
}

GLAPI void APIENTRY glUniformHandleui64vARB(GLint location, GLsizei count, const GLuint64 * value)
{
	PFNGLUNIFORMHANDLEUI64VARBPROC internal_f = (PFNGLUNIFORMHANDLEUI64VARBPROC)gapil_gl_func_table[666];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glProgramUniformHandleui64ARB(GLuint program, GLint location, GLuint64 value)
{
	PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC internal_f = (PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC)gapil_gl_func_table[667];
	assert(internal_f != NULL);
	return internal_f(program, location, value);
}

GLAPI void APIENTRY glProgramUniformHandleui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64 * values)
{
	PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC internal_f = (PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC)gapil_gl_func_table[668];
	assert(internal_f != NULL);
	return internal_f(program, location, count, values);
}

GLAPI GLboolean APIENTRY glIsTextureHandleResidentARB(GLuint64 handle)
{
	PFNGLISTEXTUREHANDLERESIDENTARBPROC internal_f = (PFNGLISTEXTUREHANDLERESIDENTARBPROC)gapil_gl_func_table[669];
	assert(internal_f != NULL);
	return internal_f(handle);
}

GLAPI GLboolean APIENTRY glIsImageHandleResidentARB(GLuint64 handle)
{
	PFNGLISIMAGEHANDLERESIDENTARBPROC internal_f = (PFNGLISIMAGEHANDLERESIDENTARBPROC)gapil_gl_func_table[670];
	assert(internal_f != NULL);
	return internal_f(handle);
}

GLAPI void APIENTRY glVertexAttribL1ui64ARB(GLuint index, GLuint64EXT x)
{
	PFNGLVERTEXATTRIBL1UI64ARBPROC internal_f = (PFNGLVERTEXATTRIBL1UI64ARBPROC)gapil_gl_func_table[671];
	assert(internal_f != NULL);
	return internal_f(index, x);
}

GLAPI void APIENTRY glVertexAttribL1ui64vARB(GLuint index, const GLuint64EXT * v)
{
	PFNGLVERTEXATTRIBL1UI64VARBPROC internal_f = (PFNGLVERTEXATTRIBL1UI64VARBPROC)gapil_gl_func_table[672];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glGetVertexAttribLui64vARB(GLuint index, GLenum pname, GLuint64EXT * params)
{
	PFNGLGETVERTEXATTRIBLUI64VARBPROC internal_f = (PFNGLGETVERTEXATTRIBLUI64VARBPROC)gapil_gl_func_table[673];
	assert(internal_f != NULL);
	return internal_f(index, pname, params);
}

GLAPI GLsync APIENTRY glCreateSyncFromCLeventARB(struct _cl_context * context, struct _cl_event * event, GLbitfield flags)
{
	PFNGLCREATESYNCFROMCLEVENTARBPROC internal_f = (PFNGLCREATESYNCFROMCLEVENTARBPROC)gapil_gl_func_table[674];
	assert(internal_f != NULL);
	return internal_f(context, event, flags);
}

GLAPI void APIENTRY glDispatchComputeGroupSizeARB(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z)
{
	PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC internal_f = (PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC)gapil_gl_func_table[675];
	assert(internal_f != NULL);
	return internal_f(num_groups_x, num_groups_y, num_groups_z, group_size_x, group_size_y, group_size_z);
}

GLAPI void APIENTRY glDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled)
{
	PFNGLDEBUGMESSAGECONTROLARBPROC internal_f = (PFNGLDEBUGMESSAGECONTROLARBPROC)gapil_gl_func_table[676];
	assert(internal_f != NULL);
	return internal_f(source, type, severity, count, ids, enabled);
}

GLAPI void APIENTRY glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf)
{
	PFNGLDEBUGMESSAGEINSERTARBPROC internal_f = (PFNGLDEBUGMESSAGEINSERTARBPROC)gapil_gl_func_table[677];
	assert(internal_f != NULL);
	return internal_f(source, type, id, severity, length, buf);
}

GLAPI void APIENTRY glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const void * userParam)
{
	PFNGLDEBUGMESSAGECALLBACKARBPROC internal_f = (PFNGLDEBUGMESSAGECALLBACKARBPROC)gapil_gl_func_table[678];
	assert(internal_f != NULL);
	return internal_f(callback, userParam);
}

GLAPI GLuint APIENTRY glGetDebugMessageLogARB(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog)
{
	PFNGLGETDEBUGMESSAGELOGARBPROC internal_f = (PFNGLGETDEBUGMESSAGELOGARBPROC)gapil_gl_func_table[679];
	assert(internal_f != NULL);
	return internal_f(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}

GLAPI void APIENTRY glBlendEquationiARB(GLuint buf, GLenum mode)
{
	PFNGLBLENDEQUATIONIARBPROC internal_f = (PFNGLBLENDEQUATIONIARBPROC)gapil_gl_func_table[680];
	assert(internal_f != NULL);
	return internal_f(buf, mode);
}

GLAPI void APIENTRY glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
	PFNGLBLENDEQUATIONSEPARATEIARBPROC internal_f = (PFNGLBLENDEQUATIONSEPARATEIARBPROC)gapil_gl_func_table[681];
	assert(internal_f != NULL);
	return internal_f(buf, modeRGB, modeAlpha);
}

GLAPI void APIENTRY glBlendFunciARB(GLuint buf, GLenum src, GLenum dst)
{
	PFNGLBLENDFUNCIARBPROC internal_f = (PFNGLBLENDFUNCIARBPROC)gapil_gl_func_table[682];
	assert(internal_f != NULL);
	return internal_f(buf, src, dst);
}

GLAPI void APIENTRY glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
	PFNGLBLENDFUNCSEPARATEIARBPROC internal_f = (PFNGLBLENDFUNCSEPARATEIARBPROC)gapil_gl_func_table[683];
	assert(internal_f != NULL);
	return internal_f(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

GLAPI void APIENTRY glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount)
{
	PFNGLDRAWARRAYSINSTANCEDARBPROC internal_f = (PFNGLDRAWARRAYSINSTANCEDARBPROC)gapil_gl_func_table[684];
	assert(internal_f != NULL);
	return internal_f(mode, first, count, primcount);
}

GLAPI void APIENTRY glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount)
{
	PFNGLDRAWELEMENTSINSTANCEDARBPROC internal_f = (PFNGLDRAWELEMENTSINSTANCEDARBPROC)gapil_gl_func_table[685];
	assert(internal_f != NULL);
	return internal_f(mode, count, type, indices, primcount);
}

GLAPI void APIENTRY glProgramParameteriARB(GLuint program, GLenum pname, GLint value)
{
	PFNGLPROGRAMPARAMETERIARBPROC internal_f = (PFNGLPROGRAMPARAMETERIARBPROC)gapil_gl_func_table[686];
	assert(internal_f != NULL);
	return internal_f(program, pname, value);
}

GLAPI void APIENTRY glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
	PFNGLFRAMEBUFFERTEXTUREARBPROC internal_f = (PFNGLFRAMEBUFFERTEXTUREARBPROC)gapil_gl_func_table[687];
	assert(internal_f != NULL);
	return internal_f(target, attachment, texture, level);
}

GLAPI void APIENTRY glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
	PFNGLFRAMEBUFFERTEXTURELAYERARBPROC internal_f = (PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)gapil_gl_func_table[688];
	assert(internal_f != NULL);
	return internal_f(target, attachment, texture, level, layer);
}

GLAPI void APIENTRY glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face)
{
	PFNGLFRAMEBUFFERTEXTUREFACEARBPROC internal_f = (PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)gapil_gl_func_table[689];
	assert(internal_f != NULL);
	return internal_f(target, attachment, texture, level, face);
}

GLAPI void APIENTRY glSpecializeShaderARB(GLuint shader, const GLchar * pEntryPoint, GLuint numSpecializationConstants, const GLuint * pConstantIndex, const GLuint * pConstantValue)
{
	PFNGLSPECIALIZESHADERARBPROC internal_f = (PFNGLSPECIALIZESHADERARBPROC)gapil_gl_func_table[690];
	assert(internal_f != NULL);
	return internal_f(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}

GLAPI void APIENTRY glUniform1i64ARB(GLint location, GLint64 x)
{
	PFNGLUNIFORM1I64ARBPROC internal_f = (PFNGLUNIFORM1I64ARBPROC)gapil_gl_func_table[691];
	assert(internal_f != NULL);
	return internal_f(location, x);
}

GLAPI void APIENTRY glUniform2i64ARB(GLint location, GLint64 x, GLint64 y)
{
	PFNGLUNIFORM2I64ARBPROC internal_f = (PFNGLUNIFORM2I64ARBPROC)gapil_gl_func_table[692];
	assert(internal_f != NULL);
	return internal_f(location, x, y);
}

GLAPI void APIENTRY glUniform3i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z)
{
	PFNGLUNIFORM3I64ARBPROC internal_f = (PFNGLUNIFORM3I64ARBPROC)gapil_gl_func_table[693];
	assert(internal_f != NULL);
	return internal_f(location, x, y, z);
}

GLAPI void APIENTRY glUniform4i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w)
{
	PFNGLUNIFORM4I64ARBPROC internal_f = (PFNGLUNIFORM4I64ARBPROC)gapil_gl_func_table[694];
	assert(internal_f != NULL);
	return internal_f(location, x, y, z, w);
}

GLAPI void APIENTRY glUniform1i64vARB(GLint location, GLsizei count, const GLint64 * value)
{
	PFNGLUNIFORM1I64VARBPROC internal_f = (PFNGLUNIFORM1I64VARBPROC)gapil_gl_func_table[695];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform2i64vARB(GLint location, GLsizei count, const GLint64 * value)
{
	PFNGLUNIFORM2I64VARBPROC internal_f = (PFNGLUNIFORM2I64VARBPROC)gapil_gl_func_table[696];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform3i64vARB(GLint location, GLsizei count, const GLint64 * value)
{
	PFNGLUNIFORM3I64VARBPROC internal_f = (PFNGLUNIFORM3I64VARBPROC)gapil_gl_func_table[697];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform4i64vARB(GLint location, GLsizei count, const GLint64 * value)
{
	PFNGLUNIFORM4I64VARBPROC internal_f = (PFNGLUNIFORM4I64VARBPROC)gapil_gl_func_table[698];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform1ui64ARB(GLint location, GLuint64 x)
{
	PFNGLUNIFORM1UI64ARBPROC internal_f = (PFNGLUNIFORM1UI64ARBPROC)gapil_gl_func_table[699];
	assert(internal_f != NULL);
	return internal_f(location, x);
}

GLAPI void APIENTRY glUniform2ui64ARB(GLint location, GLuint64 x, GLuint64 y)
{
	PFNGLUNIFORM2UI64ARBPROC internal_f = (PFNGLUNIFORM2UI64ARBPROC)gapil_gl_func_table[700];
	assert(internal_f != NULL);
	return internal_f(location, x, y);
}

GLAPI void APIENTRY glUniform3ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z)
{
	PFNGLUNIFORM3UI64ARBPROC internal_f = (PFNGLUNIFORM3UI64ARBPROC)gapil_gl_func_table[701];
	assert(internal_f != NULL);
	return internal_f(location, x, y, z);
}

GLAPI void APIENTRY glUniform4ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w)
{
	PFNGLUNIFORM4UI64ARBPROC internal_f = (PFNGLUNIFORM4UI64ARBPROC)gapil_gl_func_table[702];
	assert(internal_f != NULL);
	return internal_f(location, x, y, z, w);
}

GLAPI void APIENTRY glUniform1ui64vARB(GLint location, GLsizei count, const GLuint64 * value)
{
	PFNGLUNIFORM1UI64VARBPROC internal_f = (PFNGLUNIFORM1UI64VARBPROC)gapil_gl_func_table[703];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform2ui64vARB(GLint location, GLsizei count, const GLuint64 * value)
{
	PFNGLUNIFORM2UI64VARBPROC internal_f = (PFNGLUNIFORM2UI64VARBPROC)gapil_gl_func_table[704];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform3ui64vARB(GLint location, GLsizei count, const GLuint64 * value)
{
	PFNGLUNIFORM3UI64VARBPROC internal_f = (PFNGLUNIFORM3UI64VARBPROC)gapil_gl_func_table[705];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform4ui64vARB(GLint location, GLsizei count, const GLuint64 * value)
{
	PFNGLUNIFORM4UI64VARBPROC internal_f = (PFNGLUNIFORM4UI64VARBPROC)gapil_gl_func_table[706];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glGetUniformi64vARB(GLuint program, GLint location, GLint64 * params)
{
	PFNGLGETUNIFORMI64VARBPROC internal_f = (PFNGLGETUNIFORMI64VARBPROC)gapil_gl_func_table[707];
	assert(internal_f != NULL);
	return internal_f(program, location, params);
}

GLAPI void APIENTRY glGetUniformui64vARB(GLuint program, GLint location, GLuint64 * params)
{
	PFNGLGETUNIFORMUI64VARBPROC internal_f = (PFNGLGETUNIFORMUI64VARBPROC)gapil_gl_func_table[708];
	assert(internal_f != NULL);
	return internal_f(program, location, params);
}

GLAPI void APIENTRY glGetnUniformi64vARB(GLuint program, GLint location, GLsizei bufSize, GLint64 * params)
{
	PFNGLGETNUNIFORMI64VARBPROC internal_f = (PFNGLGETNUNIFORMI64VARBPROC)gapil_gl_func_table[709];
	assert(internal_f != NULL);
	return internal_f(program, location, bufSize, params);
}

GLAPI void APIENTRY glGetnUniformui64vARB(GLuint program, GLint location, GLsizei bufSize, GLuint64 * params)
{
	PFNGLGETNUNIFORMUI64VARBPROC internal_f = (PFNGLGETNUNIFORMUI64VARBPROC)gapil_gl_func_table[710];
	assert(internal_f != NULL);
	return internal_f(program, location, bufSize, params);
}

GLAPI void APIENTRY glProgramUniform1i64ARB(GLuint program, GLint location, GLint64 x)
{
	PFNGLPROGRAMUNIFORM1I64ARBPROC internal_f = (PFNGLPROGRAMUNIFORM1I64ARBPROC)gapil_gl_func_table[711];
	assert(internal_f != NULL);
	return internal_f(program, location, x);
}

GLAPI void APIENTRY glProgramUniform2i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y)
{
	PFNGLPROGRAMUNIFORM2I64ARBPROC internal_f = (PFNGLPROGRAMUNIFORM2I64ARBPROC)gapil_gl_func_table[712];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y);
}

GLAPI void APIENTRY glProgramUniform3i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z)
{
	PFNGLPROGRAMUNIFORM3I64ARBPROC internal_f = (PFNGLPROGRAMUNIFORM3I64ARBPROC)gapil_gl_func_table[713];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y, z);
}

GLAPI void APIENTRY glProgramUniform4i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w)
{
	PFNGLPROGRAMUNIFORM4I64ARBPROC internal_f = (PFNGLPROGRAMUNIFORM4I64ARBPROC)gapil_gl_func_table[714];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y, z, w);
}

GLAPI void APIENTRY glProgramUniform1i64vARB(GLuint program, GLint location, GLsizei count, const GLint64 * value)
{
	PFNGLPROGRAMUNIFORM1I64VARBPROC internal_f = (PFNGLPROGRAMUNIFORM1I64VARBPROC)gapil_gl_func_table[715];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform2i64vARB(GLuint program, GLint location, GLsizei count, const GLint64 * value)
{
	PFNGLPROGRAMUNIFORM2I64VARBPROC internal_f = (PFNGLPROGRAMUNIFORM2I64VARBPROC)gapil_gl_func_table[716];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform3i64vARB(GLuint program, GLint location, GLsizei count, const GLint64 * value)
{
	PFNGLPROGRAMUNIFORM3I64VARBPROC internal_f = (PFNGLPROGRAMUNIFORM3I64VARBPROC)gapil_gl_func_table[717];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform4i64vARB(GLuint program, GLint location, GLsizei count, const GLint64 * value)
{
	PFNGLPROGRAMUNIFORM4I64VARBPROC internal_f = (PFNGLPROGRAMUNIFORM4I64VARBPROC)gapil_gl_func_table[718];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform1ui64ARB(GLuint program, GLint location, GLuint64 x)
{
	PFNGLPROGRAMUNIFORM1UI64ARBPROC internal_f = (PFNGLPROGRAMUNIFORM1UI64ARBPROC)gapil_gl_func_table[719];
	assert(internal_f != NULL);
	return internal_f(program, location, x);
}

GLAPI void APIENTRY glProgramUniform2ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y)
{
	PFNGLPROGRAMUNIFORM2UI64ARBPROC internal_f = (PFNGLPROGRAMUNIFORM2UI64ARBPROC)gapil_gl_func_table[720];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y);
}

GLAPI void APIENTRY glProgramUniform3ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z)
{
	PFNGLPROGRAMUNIFORM3UI64ARBPROC internal_f = (PFNGLPROGRAMUNIFORM3UI64ARBPROC)gapil_gl_func_table[721];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y, z);
}

GLAPI void APIENTRY glProgramUniform4ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w)
{
	PFNGLPROGRAMUNIFORM4UI64ARBPROC internal_f = (PFNGLPROGRAMUNIFORM4UI64ARBPROC)gapil_gl_func_table[722];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y, z, w);
}

GLAPI void APIENTRY glProgramUniform1ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64 * value)
{
	PFNGLPROGRAMUNIFORM1UI64VARBPROC internal_f = (PFNGLPROGRAMUNIFORM1UI64VARBPROC)gapil_gl_func_table[723];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform2ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64 * value)
{
	PFNGLPROGRAMUNIFORM2UI64VARBPROC internal_f = (PFNGLPROGRAMUNIFORM2UI64VARBPROC)gapil_gl_func_table[724];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform3ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64 * value)
{
	PFNGLPROGRAMUNIFORM3UI64VARBPROC internal_f = (PFNGLPROGRAMUNIFORM3UI64VARBPROC)gapil_gl_func_table[725];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform4ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64 * value)
{
	PFNGLPROGRAMUNIFORM4UI64VARBPROC internal_f = (PFNGLPROGRAMUNIFORM4UI64VARBPROC)gapil_gl_func_table[726];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glMultiDrawArraysIndirectCountARB(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
{
	PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC internal_f = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC)gapil_gl_func_table[727];
	assert(internal_f != NULL);
	return internal_f(mode, indirect, drawcount, maxdrawcount, stride);
}

GLAPI void APIENTRY glMultiDrawElementsIndirectCountARB(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
{
	PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC internal_f = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC)gapil_gl_func_table[728];
	assert(internal_f != NULL);
	return internal_f(mode, type, indirect, drawcount, maxdrawcount, stride);
}

GLAPI void APIENTRY glVertexAttribDivisorARB(GLuint index, GLuint divisor)
{
	PFNGLVERTEXATTRIBDIVISORARBPROC internal_f = (PFNGLVERTEXATTRIBDIVISORARBPROC)gapil_gl_func_table[729];
	assert(internal_f != NULL);
	return internal_f(index, divisor);
}

GLAPI void APIENTRY glMaxShaderCompilerThreadsARB(GLuint count)
{
	PFNGLMAXSHADERCOMPILERTHREADSARBPROC internal_f = (PFNGLMAXSHADERCOMPILERTHREADSARBPROC)gapil_gl_func_table[730];
	assert(internal_f != NULL);
	return internal_f(count);
}

GLAPI GLenum APIENTRY glGetGraphicsResetStatusARB()
{
	PFNGLGETGRAPHICSRESETSTATUSARBPROC internal_f = (PFNGLGETGRAPHICSRESETSTATUSARBPROC)gapil_gl_func_table[731];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * img)
{
	PFNGLGETNTEXIMAGEARBPROC internal_f = (PFNGLGETNTEXIMAGEARBPROC)gapil_gl_func_table[732];
	assert(internal_f != NULL);
	return internal_f(target, level, format, type, bufSize, img);
}

GLAPI void APIENTRY glReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data)
{
	PFNGLREADNPIXELSARBPROC internal_f = (PFNGLREADNPIXELSARBPROC)gapil_gl_func_table[733];
	assert(internal_f != NULL);
	return internal_f(x, y, width, height, format, type, bufSize, data);
}

GLAPI void APIENTRY glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, void * img)
{
	PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC internal_f = (PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)gapil_gl_func_table[734];
	assert(internal_f != NULL);
	return internal_f(target, lod, bufSize, img);
}

GLAPI void APIENTRY glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat * params)
{
	PFNGLGETNUNIFORMFVARBPROC internal_f = (PFNGLGETNUNIFORMFVARBPROC)gapil_gl_func_table[735];
	assert(internal_f != NULL);
	return internal_f(program, location, bufSize, params);
}

GLAPI void APIENTRY glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint * params)
{
	PFNGLGETNUNIFORMIVARBPROC internal_f = (PFNGLGETNUNIFORMIVARBPROC)gapil_gl_func_table[736];
	assert(internal_f != NULL);
	return internal_f(program, location, bufSize, params);
}

GLAPI void APIENTRY glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint * params)
{
	PFNGLGETNUNIFORMUIVARBPROC internal_f = (PFNGLGETNUNIFORMUIVARBPROC)gapil_gl_func_table[737];
	assert(internal_f != NULL);
	return internal_f(program, location, bufSize, params);
}

GLAPI void APIENTRY glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble * params)
{
	PFNGLGETNUNIFORMDVARBPROC internal_f = (PFNGLGETNUNIFORMDVARBPROC)gapil_gl_func_table[738];
	assert(internal_f != NULL);
	return internal_f(program, location, bufSize, params);
}

GLAPI void APIENTRY glFramebufferSampleLocationsfvARB(GLenum target, GLuint start, GLsizei count, const GLfloat * v)
{
	PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC internal_f = (PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)gapil_gl_func_table[739];
	assert(internal_f != NULL);
	return internal_f(target, start, count, v);
}

GLAPI void APIENTRY glNamedFramebufferSampleLocationsfvARB(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat * v)
{
	PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC internal_f = (PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)gapil_gl_func_table[740];
	assert(internal_f != NULL);
	return internal_f(framebuffer, start, count, v);
}

GLAPI void APIENTRY glEvaluateDepthValuesARB()
{
	PFNGLEVALUATEDEPTHVALUESARBPROC internal_f = (PFNGLEVALUATEDEPTHVALUESARBPROC)gapil_gl_func_table[741];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glMinSampleShadingARB(GLfloat value)
{
	PFNGLMINSAMPLESHADINGARBPROC internal_f = (PFNGLMINSAMPLESHADINGARBPROC)gapil_gl_func_table[742];
	assert(internal_f != NULL);
	return internal_f(value);
}

GLAPI void APIENTRY glNamedStringARB(GLenum type, GLint namelen, const GLchar * name, GLint stringlen, const GLchar * string)
{
	PFNGLNAMEDSTRINGARBPROC internal_f = (PFNGLNAMEDSTRINGARBPROC)gapil_gl_func_table[743];
	assert(internal_f != NULL);
	return internal_f(type, namelen, name, stringlen, string);
}

GLAPI void APIENTRY glDeleteNamedStringARB(GLint namelen, const GLchar * name)
{
	PFNGLDELETENAMEDSTRINGARBPROC internal_f = (PFNGLDELETENAMEDSTRINGARBPROC)gapil_gl_func_table[744];
	assert(internal_f != NULL);
	return internal_f(namelen, name);
}

GLAPI void APIENTRY glCompileShaderIncludeARB(GLuint shader, GLsizei count, const GLchar *const * path, const GLint * length)
{
	PFNGLCOMPILESHADERINCLUDEARBPROC internal_f = (PFNGLCOMPILESHADERINCLUDEARBPROC)gapil_gl_func_table[745];
	assert(internal_f != NULL);
	return internal_f(shader, count, path, length);
}

GLAPI GLboolean APIENTRY glIsNamedStringARB(GLint namelen, const GLchar * name)
{
	PFNGLISNAMEDSTRINGARBPROC internal_f = (PFNGLISNAMEDSTRINGARBPROC)gapil_gl_func_table[746];
	assert(internal_f != NULL);
	return internal_f(namelen, name);
}

GLAPI void APIENTRY glGetNamedStringARB(GLint namelen, const GLchar * name, GLsizei bufSize, GLint * stringlen, GLchar * string)
{
	PFNGLGETNAMEDSTRINGARBPROC internal_f = (PFNGLGETNAMEDSTRINGARBPROC)gapil_gl_func_table[747];
	assert(internal_f != NULL);
	return internal_f(namelen, name, bufSize, stringlen, string);
}

GLAPI void APIENTRY glGetNamedStringivARB(GLint namelen, const GLchar * name, GLenum pname, GLint * params)
{
	PFNGLGETNAMEDSTRINGIVARBPROC internal_f = (PFNGLGETNAMEDSTRINGIVARBPROC)gapil_gl_func_table[748];
	assert(internal_f != NULL);
	return internal_f(namelen, name, pname, params);
}

GLAPI void APIENTRY glBufferPageCommitmentARB(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit)
{
	PFNGLBUFFERPAGECOMMITMENTARBPROC internal_f = (PFNGLBUFFERPAGECOMMITMENTARBPROC)gapil_gl_func_table[749];
	assert(internal_f != NULL);
	return internal_f(target, offset, size, commit);
}

GLAPI void APIENTRY glNamedBufferPageCommitmentEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit)
{
	PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC internal_f = (PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC)gapil_gl_func_table[750];
	assert(internal_f != NULL);
	return internal_f(buffer, offset, size, commit);
}

GLAPI void APIENTRY glNamedBufferPageCommitmentARB(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit)
{
	PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC internal_f = (PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC)gapil_gl_func_table[751];
	assert(internal_f != NULL);
	return internal_f(buffer, offset, size, commit);
}

GLAPI void APIENTRY glTexPageCommitmentARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit)
{
	PFNGLTEXPAGECOMMITMENTARBPROC internal_f = (PFNGLTEXPAGECOMMITMENTARBPROC)gapil_gl_func_table[752];
	assert(internal_f != NULL);
	return internal_f(target, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}

GLAPI void APIENTRY glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer)
{
	PFNGLTEXBUFFERARBPROC internal_f = (PFNGLTEXBUFFERARBPROC)gapil_gl_func_table[753];
	assert(internal_f != NULL);
	return internal_f(target, internalformat, buffer);
}

GLAPI void APIENTRY glDepthRangeArraydvNV(GLuint first, GLsizei count, const GLdouble * v)
{
	PFNGLDEPTHRANGEARRAYDVNVPROC internal_f = (PFNGLDEPTHRANGEARRAYDVNVPROC)gapil_gl_func_table[754];
	assert(internal_f != NULL);
	return internal_f(first, count, v);
}

GLAPI void APIENTRY glDepthRangeIndexeddNV(GLuint index, GLdouble n, GLdouble f)
{
	PFNGLDEPTHRANGEINDEXEDDNVPROC internal_f = (PFNGLDEPTHRANGEINDEXEDDNVPROC)gapil_gl_func_table[755];
	assert(internal_f != NULL);
	return internal_f(index, n, f);
}

GLAPI void APIENTRY glBlendBarrierKHR()
{
	PFNGLBLENDBARRIERKHRPROC internal_f = (PFNGLBLENDBARRIERKHRPROC)gapil_gl_func_table[756];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glMaxShaderCompilerThreadsKHR(GLuint count)
{
	PFNGLMAXSHADERCOMPILERTHREADSKHRPROC internal_f = (PFNGLMAXSHADERCOMPILERTHREADSKHRPROC)gapil_gl_func_table[757];
	assert(internal_f != NULL);
	return internal_f(count);
}

GLAPI void APIENTRY glRenderbufferStorageMultisampleAdvancedAMD(GLenum target, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC internal_f = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC)gapil_gl_func_table[758];
	assert(internal_f != NULL);
	return internal_f(target, samples, storageSamples, internalformat, width, height);
}

GLAPI void APIENTRY glNamedRenderbufferStorageMultisampleAdvancedAMD(GLuint renderbuffer, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC internal_f = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC)gapil_gl_func_table[759];
	assert(internal_f != NULL);
	return internal_f(renderbuffer, samples, storageSamples, internalformat, width, height);
}

GLAPI void APIENTRY glGetPerfMonitorGroupsAMD(GLint * numGroups, GLsizei groupsSize, GLuint * groups)
{
	PFNGLGETPERFMONITORGROUPSAMDPROC internal_f = (PFNGLGETPERFMONITORGROUPSAMDPROC)gapil_gl_func_table[760];
	assert(internal_f != NULL);
	return internal_f(numGroups, groupsSize, groups);
}

GLAPI void APIENTRY glGetPerfMonitorCountersAMD(GLuint group, GLint * numCounters, GLint * maxActiveCounters, GLsizei counterSize, GLuint * counters)
{
	PFNGLGETPERFMONITORCOUNTERSAMDPROC internal_f = (PFNGLGETPERFMONITORCOUNTERSAMDPROC)gapil_gl_func_table[761];
	assert(internal_f != NULL);
	return internal_f(group, numCounters, maxActiveCounters, counterSize, counters);
}

GLAPI void APIENTRY glGetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei * length, GLchar * groupString)
{
	PFNGLGETPERFMONITORGROUPSTRINGAMDPROC internal_f = (PFNGLGETPERFMONITORGROUPSTRINGAMDPROC)gapil_gl_func_table[762];
	assert(internal_f != NULL);
	return internal_f(group, bufSize, length, groupString);
}

GLAPI void APIENTRY glGetPerfMonitorCounterStringAMD(GLuint group, GLuint counter, GLsizei bufSize, GLsizei * length, GLchar * counterString)
{
	PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC internal_f = (PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC)gapil_gl_func_table[763];
	assert(internal_f != NULL);
	return internal_f(group, counter, bufSize, length, counterString);
}

GLAPI void APIENTRY glGetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, void * data)
{
	PFNGLGETPERFMONITORCOUNTERINFOAMDPROC internal_f = (PFNGLGETPERFMONITORCOUNTERINFOAMDPROC)gapil_gl_func_table[764];
	assert(internal_f != NULL);
	return internal_f(group, counter, pname, data);
}

GLAPI void APIENTRY glGenPerfMonitorsAMD(GLsizei n, GLuint * monitors)
{
	PFNGLGENPERFMONITORSAMDPROC internal_f = (PFNGLGENPERFMONITORSAMDPROC)gapil_gl_func_table[765];
	assert(internal_f != NULL);
	return internal_f(n, monitors);
}

GLAPI void APIENTRY glDeletePerfMonitorsAMD(GLsizei n, GLuint * monitors)
{
	PFNGLDELETEPERFMONITORSAMDPROC internal_f = (PFNGLDELETEPERFMONITORSAMDPROC)gapil_gl_func_table[766];
	assert(internal_f != NULL);
	return internal_f(n, monitors);
}

GLAPI void APIENTRY glSelectPerfMonitorCountersAMD(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint * counterList)
{
	PFNGLSELECTPERFMONITORCOUNTERSAMDPROC internal_f = (PFNGLSELECTPERFMONITORCOUNTERSAMDPROC)gapil_gl_func_table[767];
	assert(internal_f != NULL);
	return internal_f(monitor, enable, group, numCounters, counterList);
}

GLAPI void APIENTRY glBeginPerfMonitorAMD(GLuint monitor)
{
	PFNGLBEGINPERFMONITORAMDPROC internal_f = (PFNGLBEGINPERFMONITORAMDPROC)gapil_gl_func_table[768];
	assert(internal_f != NULL);
	return internal_f(monitor);
}

GLAPI void APIENTRY glEndPerfMonitorAMD(GLuint monitor)
{
	PFNGLENDPERFMONITORAMDPROC internal_f = (PFNGLENDPERFMONITORAMDPROC)gapil_gl_func_table[769];
	assert(internal_f != NULL);
	return internal_f(monitor);
}

GLAPI void APIENTRY glGetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint * data, GLint * bytesWritten)
{
	PFNGLGETPERFMONITORCOUNTERDATAAMDPROC internal_f = (PFNGLGETPERFMONITORCOUNTERDATAAMDPROC)gapil_gl_func_table[770];
	assert(internal_f != NULL);
	return internal_f(monitor, pname, dataSize, data, bytesWritten);
}

GLAPI void APIENTRY glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image, const GLint * attrib_list)
{
	PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC internal_f = (PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC)gapil_gl_func_table[771];
	assert(internal_f != NULL);
	return internal_f(target, image, attrib_list);
}

GLAPI void APIENTRY glEGLImageTargetTextureStorageEXT(GLuint texture, GLeglImageOES image, const GLint * attrib_list)
{
	PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC internal_f = (PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC)gapil_gl_func_table[772];
	assert(internal_f != NULL);
	return internal_f(texture, image, attrib_list);
}

GLAPI void APIENTRY glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, const GLchar * label)
{
	PFNGLLABELOBJECTEXTPROC internal_f = (PFNGLLABELOBJECTEXTPROC)gapil_gl_func_table[773];
	assert(internal_f != NULL);
	return internal_f(type, object, length, label);
}

GLAPI void APIENTRY glGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei * length, GLchar * label)
{
	PFNGLGETOBJECTLABELEXTPROC internal_f = (PFNGLGETOBJECTLABELEXTPROC)gapil_gl_func_table[774];
	assert(internal_f != NULL);
	return internal_f(type, object, bufSize, length, label);
}

GLAPI void APIENTRY glInsertEventMarkerEXT(GLsizei length, const GLchar * marker)
{
	PFNGLINSERTEVENTMARKEREXTPROC internal_f = (PFNGLINSERTEVENTMARKEREXTPROC)gapil_gl_func_table[775];
	assert(internal_f != NULL);
	return internal_f(length, marker);
}

GLAPI void APIENTRY glPushGroupMarkerEXT(GLsizei length, const GLchar * marker)
{
	PFNGLPUSHGROUPMARKEREXTPROC internal_f = (PFNGLPUSHGROUPMARKEREXTPROC)gapil_gl_func_table[776];
	assert(internal_f != NULL);
	return internal_f(length, marker);
}

GLAPI void APIENTRY glPopGroupMarkerEXT()
{
	PFNGLPOPGROUPMARKEREXTPROC internal_f = (PFNGLPOPGROUPMARKEREXTPROC)gapil_gl_func_table[777];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glMatrixLoadfEXT(GLenum mode, const GLfloat * m)
{
	PFNGLMATRIXLOADFEXTPROC internal_f = (PFNGLMATRIXLOADFEXTPROC)gapil_gl_func_table[778];
	assert(internal_f != NULL);
	return internal_f(mode, m);
}

GLAPI void APIENTRY glMatrixLoaddEXT(GLenum mode, const GLdouble * m)
{
	PFNGLMATRIXLOADDEXTPROC internal_f = (PFNGLMATRIXLOADDEXTPROC)gapil_gl_func_table[779];
	assert(internal_f != NULL);
	return internal_f(mode, m);
}

GLAPI void APIENTRY glMatrixMultfEXT(GLenum mode, const GLfloat * m)
{
	PFNGLMATRIXMULTFEXTPROC internal_f = (PFNGLMATRIXMULTFEXTPROC)gapil_gl_func_table[780];
	assert(internal_f != NULL);
	return internal_f(mode, m);
}

GLAPI void APIENTRY glMatrixMultdEXT(GLenum mode, const GLdouble * m)
{
	PFNGLMATRIXMULTDEXTPROC internal_f = (PFNGLMATRIXMULTDEXTPROC)gapil_gl_func_table[781];
	assert(internal_f != NULL);
	return internal_f(mode, m);
}

GLAPI void APIENTRY glMatrixLoadIdentityEXT(GLenum mode)
{
	PFNGLMATRIXLOADIDENTITYEXTPROC internal_f = (PFNGLMATRIXLOADIDENTITYEXTPROC)gapil_gl_func_table[782];
	assert(internal_f != NULL);
	return internal_f(mode);
}

GLAPI void APIENTRY glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	PFNGLMATRIXROTATEFEXTPROC internal_f = (PFNGLMATRIXROTATEFEXTPROC)gapil_gl_func_table[783];
	assert(internal_f != NULL);
	return internal_f(mode, angle, x, y, z);
}

GLAPI void APIENTRY glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
	PFNGLMATRIXROTATEDEXTPROC internal_f = (PFNGLMATRIXROTATEDEXTPROC)gapil_gl_func_table[784];
	assert(internal_f != NULL);
	return internal_f(mode, angle, x, y, z);
}

GLAPI void APIENTRY glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z)
{
	PFNGLMATRIXSCALEFEXTPROC internal_f = (PFNGLMATRIXSCALEFEXTPROC)gapil_gl_func_table[785];
	assert(internal_f != NULL);
	return internal_f(mode, x, y, z);
}

GLAPI void APIENTRY glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z)
{
	PFNGLMATRIXSCALEDEXTPROC internal_f = (PFNGLMATRIXSCALEDEXTPROC)gapil_gl_func_table[786];
	assert(internal_f != NULL);
	return internal_f(mode, x, y, z);
}

GLAPI void APIENTRY glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z)
{
	PFNGLMATRIXTRANSLATEFEXTPROC internal_f = (PFNGLMATRIXTRANSLATEFEXTPROC)gapil_gl_func_table[787];
	assert(internal_f != NULL);
	return internal_f(mode, x, y, z);
}

GLAPI void APIENTRY glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z)
{
	PFNGLMATRIXTRANSLATEDEXTPROC internal_f = (PFNGLMATRIXTRANSLATEDEXTPROC)gapil_gl_func_table[788];
	assert(internal_f != NULL);
	return internal_f(mode, x, y, z);
}

GLAPI void APIENTRY glMatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
	PFNGLMATRIXFRUSTUMEXTPROC internal_f = (PFNGLMATRIXFRUSTUMEXTPROC)gapil_gl_func_table[789];
	assert(internal_f != NULL);
	return internal_f(mode, left, right, bottom, top, zNear, zFar);
}

GLAPI void APIENTRY glMatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
	PFNGLMATRIXORTHOEXTPROC internal_f = (PFNGLMATRIXORTHOEXTPROC)gapil_gl_func_table[790];
	assert(internal_f != NULL);
	return internal_f(mode, left, right, bottom, top, zNear, zFar);
}

GLAPI void APIENTRY glMatrixPopEXT(GLenum mode)
{
	PFNGLMATRIXPOPEXTPROC internal_f = (PFNGLMATRIXPOPEXTPROC)gapil_gl_func_table[791];
	assert(internal_f != NULL);
	return internal_f(mode);
}

GLAPI void APIENTRY glMatrixPushEXT(GLenum mode)
{
	PFNGLMATRIXPUSHEXTPROC internal_f = (PFNGLMATRIXPUSHEXTPROC)gapil_gl_func_table[792];
	assert(internal_f != NULL);
	return internal_f(mode);
}

GLAPI void APIENTRY glClientAttribDefaultEXT(GLbitfield mask)
{
	PFNGLCLIENTATTRIBDEFAULTEXTPROC internal_f = (PFNGLCLIENTATTRIBDEFAULTEXTPROC)gapil_gl_func_table[793];
	assert(internal_f != NULL);
	return internal_f(mask);
}

GLAPI void APIENTRY glPushClientAttribDefaultEXT(GLbitfield mask)
{
	PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC internal_f = (PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)gapil_gl_func_table[794];
	assert(internal_f != NULL);
	return internal_f(mask);
}

GLAPI void APIENTRY glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param)
{
	PFNGLTEXTUREPARAMETERFEXTPROC internal_f = (PFNGLTEXTUREPARAMETERFEXTPROC)gapil_gl_func_table[795];
	assert(internal_f != NULL);
	return internal_f(texture, target, pname, param);
}

GLAPI void APIENTRY glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat * params)
{
	PFNGLTEXTUREPARAMETERFVEXTPROC internal_f = (PFNGLTEXTUREPARAMETERFVEXTPROC)gapil_gl_func_table[796];
	assert(internal_f != NULL);
	return internal_f(texture, target, pname, params);
}

GLAPI void APIENTRY glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param)
{
	PFNGLTEXTUREPARAMETERIEXTPROC internal_f = (PFNGLTEXTUREPARAMETERIEXTPROC)gapil_gl_func_table[797];
	assert(internal_f != NULL);
	return internal_f(texture, target, pname, param);
}

GLAPI void APIENTRY glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint * params)
{
	PFNGLTEXTUREPARAMETERIVEXTPROC internal_f = (PFNGLTEXTUREPARAMETERIVEXTPROC)gapil_gl_func_table[798];
	assert(internal_f != NULL);
	return internal_f(texture, target, pname, params);
}

GLAPI void APIENTRY glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXTUREIMAGE1DEXTPROC internal_f = (PFNGLTEXTUREIMAGE1DEXTPROC)gapil_gl_func_table[799];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, internalformat, width, border, format, type, pixels);
}

GLAPI void APIENTRY glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXTUREIMAGE2DEXTPROC internal_f = (PFNGLTEXTUREIMAGE2DEXTPROC)gapil_gl_func_table[800];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, internalformat, width, height, border, format, type, pixels);
}

GLAPI void APIENTRY glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXTURESUBIMAGE1DEXTPROC internal_f = (PFNGLTEXTURESUBIMAGE1DEXTPROC)gapil_gl_func_table[801];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, xoffset, width, format, type, pixels);
}

GLAPI void APIENTRY glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXTURESUBIMAGE2DEXTPROC internal_f = (PFNGLTEXTURESUBIMAGE2DEXTPROC)gapil_gl_func_table[802];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, xoffset, yoffset, width, height, format, type, pixels);
}

GLAPI void APIENTRY glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
{
	PFNGLCOPYTEXTUREIMAGE1DEXTPROC internal_f = (PFNGLCOPYTEXTUREIMAGE1DEXTPROC)gapil_gl_func_table[803];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, internalformat, x, y, width, border);
}

GLAPI void APIENTRY glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	PFNGLCOPYTEXTUREIMAGE2DEXTPROC internal_f = (PFNGLCOPYTEXTUREIMAGE2DEXTPROC)gapil_gl_func_table[804];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, internalformat, x, y, width, height, border);
}

GLAPI void APIENTRY glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
	PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC internal_f = (PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)gapil_gl_func_table[805];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, xoffset, x, y, width);
}

GLAPI void APIENTRY glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC internal_f = (PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)gapil_gl_func_table[806];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, xoffset, yoffset, x, y, width, height);
}

GLAPI void APIENTRY glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void * pixels)
{
	PFNGLGETTEXTUREIMAGEEXTPROC internal_f = (PFNGLGETTEXTUREIMAGEEXTPROC)gapil_gl_func_table[807];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, format, type, pixels);
}

GLAPI void APIENTRY glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat * params)
{
	PFNGLGETTEXTUREPARAMETERFVEXTPROC internal_f = (PFNGLGETTEXTUREPARAMETERFVEXTPROC)gapil_gl_func_table[808];
	assert(internal_f != NULL);
	return internal_f(texture, target, pname, params);
}

GLAPI void APIENTRY glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETTEXTUREPARAMETERIVEXTPROC internal_f = (PFNGLGETTEXTUREPARAMETERIVEXTPROC)gapil_gl_func_table[809];
	assert(internal_f != NULL);
	return internal_f(texture, target, pname, params);
}

GLAPI void APIENTRY glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat * params)
{
	PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC internal_f = (PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)gapil_gl_func_table[810];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, pname, params);
}

GLAPI void APIENTRY glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint * params)
{
	PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC internal_f = (PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)gapil_gl_func_table[811];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, pname, params);
}

GLAPI void APIENTRY glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXTUREIMAGE3DEXTPROC internal_f = (PFNGLTEXTUREIMAGE3DEXTPROC)gapil_gl_func_table[812];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, internalformat, width, height, depth, border, format, type, pixels);
}

GLAPI void APIENTRY glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels)
{
	PFNGLTEXTURESUBIMAGE3DEXTPROC internal_f = (PFNGLTEXTURESUBIMAGE3DEXTPROC)gapil_gl_func_table[813];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

GLAPI void APIENTRY glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC internal_f = (PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)gapil_gl_func_table[814];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

GLAPI void APIENTRY glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture)
{
	PFNGLBINDMULTITEXTUREEXTPROC internal_f = (PFNGLBINDMULTITEXTUREEXTPROC)gapil_gl_func_table[815];
	assert(internal_f != NULL);
	return internal_f(texunit, target, texture);
}

GLAPI void APIENTRY glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void * pointer)
{
	PFNGLMULTITEXCOORDPOINTEREXTPROC internal_f = (PFNGLMULTITEXCOORDPOINTEREXTPROC)gapil_gl_func_table[816];
	assert(internal_f != NULL);
	return internal_f(texunit, size, type, stride, pointer);
}

GLAPI void APIENTRY glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param)
{
	PFNGLMULTITEXENVFEXTPROC internal_f = (PFNGLMULTITEXENVFEXTPROC)gapil_gl_func_table[817];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, param);
}

GLAPI void APIENTRY glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat * params)
{
	PFNGLMULTITEXENVFVEXTPROC internal_f = (PFNGLMULTITEXENVFVEXTPROC)gapil_gl_func_table[818];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, params);
}

GLAPI void APIENTRY glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param)
{
	PFNGLMULTITEXENVIEXTPROC internal_f = (PFNGLMULTITEXENVIEXTPROC)gapil_gl_func_table[819];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, param);
}

GLAPI void APIENTRY glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint * params)
{
	PFNGLMULTITEXENVIVEXTPROC internal_f = (PFNGLMULTITEXENVIVEXTPROC)gapil_gl_func_table[820];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, params);
}

GLAPI void APIENTRY glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param)
{
	PFNGLMULTITEXGENDEXTPROC internal_f = (PFNGLMULTITEXGENDEXTPROC)gapil_gl_func_table[821];
	assert(internal_f != NULL);
	return internal_f(texunit, coord, pname, param);
}

GLAPI void APIENTRY glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble * params)
{
	PFNGLMULTITEXGENDVEXTPROC internal_f = (PFNGLMULTITEXGENDVEXTPROC)gapil_gl_func_table[822];
	assert(internal_f != NULL);
	return internal_f(texunit, coord, pname, params);
}

GLAPI void APIENTRY glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param)
{
	PFNGLMULTITEXGENFEXTPROC internal_f = (PFNGLMULTITEXGENFEXTPROC)gapil_gl_func_table[823];
	assert(internal_f != NULL);
	return internal_f(texunit, coord, pname, param);
}

GLAPI void APIENTRY glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat * params)
{
	PFNGLMULTITEXGENFVEXTPROC internal_f = (PFNGLMULTITEXGENFVEXTPROC)gapil_gl_func_table[824];
	assert(internal_f != NULL);
	return internal_f(texunit, coord, pname, params);
}

GLAPI void APIENTRY glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param)
{
	PFNGLMULTITEXGENIEXTPROC internal_f = (PFNGLMULTITEXGENIEXTPROC)gapil_gl_func_table[825];
	assert(internal_f != NULL);
	return internal_f(texunit, coord, pname, param);
}

GLAPI void APIENTRY glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint * params)
{
	PFNGLMULTITEXGENIVEXTPROC internal_f = (PFNGLMULTITEXGENIVEXTPROC)gapil_gl_func_table[826];
	assert(internal_f != NULL);
	return internal_f(texunit, coord, pname, params);
}

GLAPI void APIENTRY glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat * params)
{
	PFNGLGETMULTITEXENVFVEXTPROC internal_f = (PFNGLGETMULTITEXENVFVEXTPROC)gapil_gl_func_table[827];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, params);
}

GLAPI void APIENTRY glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETMULTITEXENVIVEXTPROC internal_f = (PFNGLGETMULTITEXENVIVEXTPROC)gapil_gl_func_table[828];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, params);
}

GLAPI void APIENTRY glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble * params)
{
	PFNGLGETMULTITEXGENDVEXTPROC internal_f = (PFNGLGETMULTITEXGENDVEXTPROC)gapil_gl_func_table[829];
	assert(internal_f != NULL);
	return internal_f(texunit, coord, pname, params);
}

GLAPI void APIENTRY glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat * params)
{
	PFNGLGETMULTITEXGENFVEXTPROC internal_f = (PFNGLGETMULTITEXGENFVEXTPROC)gapil_gl_func_table[830];
	assert(internal_f != NULL);
	return internal_f(texunit, coord, pname, params);
}

GLAPI void APIENTRY glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint * params)
{
	PFNGLGETMULTITEXGENIVEXTPROC internal_f = (PFNGLGETMULTITEXGENIVEXTPROC)gapil_gl_func_table[831];
	assert(internal_f != NULL);
	return internal_f(texunit, coord, pname, params);
}

GLAPI void APIENTRY glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param)
{
	PFNGLMULTITEXPARAMETERIEXTPROC internal_f = (PFNGLMULTITEXPARAMETERIEXTPROC)gapil_gl_func_table[832];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, param);
}

GLAPI void APIENTRY glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint * params)
{
	PFNGLMULTITEXPARAMETERIVEXTPROC internal_f = (PFNGLMULTITEXPARAMETERIVEXTPROC)gapil_gl_func_table[833];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, params);
}

GLAPI void APIENTRY glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param)
{
	PFNGLMULTITEXPARAMETERFEXTPROC internal_f = (PFNGLMULTITEXPARAMETERFEXTPROC)gapil_gl_func_table[834];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, param);
}

GLAPI void APIENTRY glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat * params)
{
	PFNGLMULTITEXPARAMETERFVEXTPROC internal_f = (PFNGLMULTITEXPARAMETERFVEXTPROC)gapil_gl_func_table[835];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, params);
}

GLAPI void APIENTRY glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels)
{
	PFNGLMULTITEXIMAGE1DEXTPROC internal_f = (PFNGLMULTITEXIMAGE1DEXTPROC)gapil_gl_func_table[836];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, internalformat, width, border, format, type, pixels);
}

GLAPI void APIENTRY glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels)
{
	PFNGLMULTITEXIMAGE2DEXTPROC internal_f = (PFNGLMULTITEXIMAGE2DEXTPROC)gapil_gl_func_table[837];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, internalformat, width, height, border, format, type, pixels);
}

GLAPI void APIENTRY glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels)
{
	PFNGLMULTITEXSUBIMAGE1DEXTPROC internal_f = (PFNGLMULTITEXSUBIMAGE1DEXTPROC)gapil_gl_func_table[838];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, xoffset, width, format, type, pixels);
}

GLAPI void APIENTRY glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels)
{
	PFNGLMULTITEXSUBIMAGE2DEXTPROC internal_f = (PFNGLMULTITEXSUBIMAGE2DEXTPROC)gapil_gl_func_table[839];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, xoffset, yoffset, width, height, format, type, pixels);
}

GLAPI void APIENTRY glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
{
	PFNGLCOPYMULTITEXIMAGE1DEXTPROC internal_f = (PFNGLCOPYMULTITEXIMAGE1DEXTPROC)gapil_gl_func_table[840];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, internalformat, x, y, width, border);
}

GLAPI void APIENTRY glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	PFNGLCOPYMULTITEXIMAGE2DEXTPROC internal_f = (PFNGLCOPYMULTITEXIMAGE2DEXTPROC)gapil_gl_func_table[841];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, internalformat, x, y, width, height, border);
}

GLAPI void APIENTRY glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
	PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC internal_f = (PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)gapil_gl_func_table[842];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, xoffset, x, y, width);
}

GLAPI void APIENTRY glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC internal_f = (PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)gapil_gl_func_table[843];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, xoffset, yoffset, x, y, width, height);
}

GLAPI void APIENTRY glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void * pixels)
{
	PFNGLGETMULTITEXIMAGEEXTPROC internal_f = (PFNGLGETMULTITEXIMAGEEXTPROC)gapil_gl_func_table[844];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, format, type, pixels);
}

GLAPI void APIENTRY glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat * params)
{
	PFNGLGETMULTITEXPARAMETERFVEXTPROC internal_f = (PFNGLGETMULTITEXPARAMETERFVEXTPROC)gapil_gl_func_table[845];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, params);
}

GLAPI void APIENTRY glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETMULTITEXPARAMETERIVEXTPROC internal_f = (PFNGLGETMULTITEXPARAMETERIVEXTPROC)gapil_gl_func_table[846];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, params);
}

GLAPI void APIENTRY glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat * params)
{
	PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC internal_f = (PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)gapil_gl_func_table[847];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, pname, params);
}

GLAPI void APIENTRY glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint * params)
{
	PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC internal_f = (PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)gapil_gl_func_table[848];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, pname, params);
}

GLAPI void APIENTRY glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels)
{
	PFNGLMULTITEXIMAGE3DEXTPROC internal_f = (PFNGLMULTITEXIMAGE3DEXTPROC)gapil_gl_func_table[849];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, internalformat, width, height, depth, border, format, type, pixels);
}

GLAPI void APIENTRY glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels)
{
	PFNGLMULTITEXSUBIMAGE3DEXTPROC internal_f = (PFNGLMULTITEXSUBIMAGE3DEXTPROC)gapil_gl_func_table[850];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

GLAPI void APIENTRY glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC internal_f = (PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)gapil_gl_func_table[851];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

GLAPI void APIENTRY glEnableClientStateIndexedEXT(GLenum array, GLuint index)
{
	PFNGLENABLECLIENTSTATEINDEXEDEXTPROC internal_f = (PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)gapil_gl_func_table[852];
	assert(internal_f != NULL);
	return internal_f(array, index);
}

GLAPI void APIENTRY glDisableClientStateIndexedEXT(GLenum array, GLuint index)
{
	PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC internal_f = (PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)gapil_gl_func_table[853];
	assert(internal_f != NULL);
	return internal_f(array, index);
}

GLAPI void APIENTRY glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat * data)
{
	PFNGLGETFLOATINDEXEDVEXTPROC internal_f = (PFNGLGETFLOATINDEXEDVEXTPROC)gapil_gl_func_table[854];
	assert(internal_f != NULL);
	return internal_f(target, index, data);
}

GLAPI void APIENTRY glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble * data)
{
	PFNGLGETDOUBLEINDEXEDVEXTPROC internal_f = (PFNGLGETDOUBLEINDEXEDVEXTPROC)gapil_gl_func_table[855];
	assert(internal_f != NULL);
	return internal_f(target, index, data);
}

GLAPI void APIENTRY glGetPointerIndexedvEXT(GLenum target, GLuint index, void ** data)
{
	PFNGLGETPOINTERINDEXEDVEXTPROC internal_f = (PFNGLGETPOINTERINDEXEDVEXTPROC)gapil_gl_func_table[856];
	assert(internal_f != NULL);
	return internal_f(target, index, data);
}

GLAPI void APIENTRY glEnableIndexedEXT(GLenum target, GLuint index)
{
	PFNGLENABLEINDEXEDEXTPROC internal_f = (PFNGLENABLEINDEXEDEXTPROC)gapil_gl_func_table[857];
	assert(internal_f != NULL);
	return internal_f(target, index);
}

GLAPI void APIENTRY glDisableIndexedEXT(GLenum target, GLuint index)
{
	PFNGLDISABLEINDEXEDEXTPROC internal_f = (PFNGLDISABLEINDEXEDEXTPROC)gapil_gl_func_table[858];
	assert(internal_f != NULL);
	return internal_f(target, index);
}

GLAPI GLboolean APIENTRY glIsEnabledIndexedEXT(GLenum target, GLuint index)
{
	PFNGLISENABLEDINDEXEDEXTPROC internal_f = (PFNGLISENABLEDINDEXEDEXTPROC)gapil_gl_func_table[859];
	assert(internal_f != NULL);
	return internal_f(target, index);
}

GLAPI void APIENTRY glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint * data)
{
	PFNGLGETINTEGERINDEXEDVEXTPROC internal_f = (PFNGLGETINTEGERINDEXEDVEXTPROC)gapil_gl_func_table[860];
	assert(internal_f != NULL);
	return internal_f(target, index, data);
}

GLAPI void APIENTRY glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean * data)
{
	PFNGLGETBOOLEANINDEXEDVEXTPROC internal_f = (PFNGLGETBOOLEANINDEXEDVEXTPROC)gapil_gl_func_table[861];
	assert(internal_f != NULL);
	return internal_f(target, index, data);
}

GLAPI void APIENTRY glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits)
{
	PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC internal_f = (PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)gapil_gl_func_table[862];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, internalformat, width, height, depth, border, imageSize, bits);
}

GLAPI void APIENTRY glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits)
{
	PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC internal_f = (PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)gapil_gl_func_table[863];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, internalformat, width, height, border, imageSize, bits);
}

GLAPI void APIENTRY glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits)
{
	PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC internal_f = (PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)gapil_gl_func_table[864];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, internalformat, width, border, imageSize, bits);
}

GLAPI void APIENTRY glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits)
{
	PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC internal_f = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)gapil_gl_func_table[865];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits);
}

GLAPI void APIENTRY glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits)
{
	PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC internal_f = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)gapil_gl_func_table[866];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, xoffset, yoffset, width, height, format, imageSize, bits);
}

GLAPI void APIENTRY glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits)
{
	PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC internal_f = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)gapil_gl_func_table[867];
	assert(internal_f != NULL);
	return internal_f(texture, target, level, xoffset, width, format, imageSize, bits);
}

GLAPI void APIENTRY glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, void * img)
{
	PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC internal_f = (PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)gapil_gl_func_table[868];
	assert(internal_f != NULL);
	return internal_f(texture, target, lod, img);
}

GLAPI void APIENTRY glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits)
{
	PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC internal_f = (PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)gapil_gl_func_table[869];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, internalformat, width, height, depth, border, imageSize, bits);
}

GLAPI void APIENTRY glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits)
{
	PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC internal_f = (PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)gapil_gl_func_table[870];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, internalformat, width, height, border, imageSize, bits);
}

GLAPI void APIENTRY glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits)
{
	PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC internal_f = (PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)gapil_gl_func_table[871];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, internalformat, width, border, imageSize, bits);
}

GLAPI void APIENTRY glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits)
{
	PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC internal_f = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)gapil_gl_func_table[872];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits);
}

GLAPI void APIENTRY glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits)
{
	PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC internal_f = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)gapil_gl_func_table[873];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, xoffset, yoffset, width, height, format, imageSize, bits);
}

GLAPI void APIENTRY glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits)
{
	PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC internal_f = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)gapil_gl_func_table[874];
	assert(internal_f != NULL);
	return internal_f(texunit, target, level, xoffset, width, format, imageSize, bits);
}

GLAPI void APIENTRY glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, void * img)
{
	PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC internal_f = (PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)gapil_gl_func_table[875];
	assert(internal_f != NULL);
	return internal_f(texunit, target, lod, img);
}

GLAPI void APIENTRY glMatrixLoadTransposefEXT(GLenum mode, const GLfloat * m)
{
	PFNGLMATRIXLOADTRANSPOSEFEXTPROC internal_f = (PFNGLMATRIXLOADTRANSPOSEFEXTPROC)gapil_gl_func_table[876];
	assert(internal_f != NULL);
	return internal_f(mode, m);
}

GLAPI void APIENTRY glMatrixLoadTransposedEXT(GLenum mode, const GLdouble * m)
{
	PFNGLMATRIXLOADTRANSPOSEDEXTPROC internal_f = (PFNGLMATRIXLOADTRANSPOSEDEXTPROC)gapil_gl_func_table[877];
	assert(internal_f != NULL);
	return internal_f(mode, m);
}

GLAPI void APIENTRY glMatrixMultTransposefEXT(GLenum mode, const GLfloat * m)
{
	PFNGLMATRIXMULTTRANSPOSEFEXTPROC internal_f = (PFNGLMATRIXMULTTRANSPOSEFEXTPROC)gapil_gl_func_table[878];
	assert(internal_f != NULL);
	return internal_f(mode, m);
}

GLAPI void APIENTRY glMatrixMultTransposedEXT(GLenum mode, const GLdouble * m)
{
	PFNGLMATRIXMULTTRANSPOSEDEXTPROC internal_f = (PFNGLMATRIXMULTTRANSPOSEDEXTPROC)gapil_gl_func_table[879];
	assert(internal_f != NULL);
	return internal_f(mode, m);
}

GLAPI void APIENTRY glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage)
{
	PFNGLNAMEDBUFFERDATAEXTPROC internal_f = (PFNGLNAMEDBUFFERDATAEXTPROC)gapil_gl_func_table[880];
	assert(internal_f != NULL);
	return internal_f(buffer, size, data, usage);
}

GLAPI void APIENTRY glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data)
{
	PFNGLNAMEDBUFFERSUBDATAEXTPROC internal_f = (PFNGLNAMEDBUFFERSUBDATAEXTPROC)gapil_gl_func_table[881];
	assert(internal_f != NULL);
	return internal_f(buffer, offset, size, data);
}

GLAPI void * APIENTRY glMapNamedBufferEXT(GLuint buffer, GLenum access)
{
	PFNGLMAPNAMEDBUFFEREXTPROC internal_f = (PFNGLMAPNAMEDBUFFEREXTPROC)gapil_gl_func_table[882];
	assert(internal_f != NULL);
	return internal_f(buffer, access);
}

GLAPI GLboolean APIENTRY glUnmapNamedBufferEXT(GLuint buffer)
{
	PFNGLUNMAPNAMEDBUFFEREXTPROC internal_f = (PFNGLUNMAPNAMEDBUFFEREXTPROC)gapil_gl_func_table[883];
	assert(internal_f != NULL);
	return internal_f(buffer);
}

GLAPI void APIENTRY glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint * params)
{
	PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC internal_f = (PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)gapil_gl_func_table[884];
	assert(internal_f != NULL);
	return internal_f(buffer, pname, params);
}

GLAPI void APIENTRY glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, void ** params)
{
	PFNGLGETNAMEDBUFFERPOINTERVEXTPROC internal_f = (PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)gapil_gl_func_table[885];
	assert(internal_f != NULL);
	return internal_f(buffer, pname, params);
}

GLAPI void APIENTRY glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data)
{
	PFNGLGETNAMEDBUFFERSUBDATAEXTPROC internal_f = (PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)gapil_gl_func_table[886];
	assert(internal_f != NULL);
	return internal_f(buffer, offset, size, data);
}

GLAPI void APIENTRY glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0)
{
	PFNGLPROGRAMUNIFORM1FEXTPROC internal_f = (PFNGLPROGRAMUNIFORM1FEXTPROC)gapil_gl_func_table[887];
	assert(internal_f != NULL);
	return internal_f(program, location, v0);
}

GLAPI void APIENTRY glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1)
{
	PFNGLPROGRAMUNIFORM2FEXTPROC internal_f = (PFNGLPROGRAMUNIFORM2FEXTPROC)gapil_gl_func_table[888];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1);
}

GLAPI void APIENTRY glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	PFNGLPROGRAMUNIFORM3FEXTPROC internal_f = (PFNGLPROGRAMUNIFORM3FEXTPROC)gapil_gl_func_table[889];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2);
}

GLAPI void APIENTRY glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	PFNGLPROGRAMUNIFORM4FEXTPROC internal_f = (PFNGLPROGRAMUNIFORM4FEXTPROC)gapil_gl_func_table[890];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2, v3);
}

GLAPI void APIENTRY glProgramUniform1iEXT(GLuint program, GLint location, GLint v0)
{
	PFNGLPROGRAMUNIFORM1IEXTPROC internal_f = (PFNGLPROGRAMUNIFORM1IEXTPROC)gapil_gl_func_table[891];
	assert(internal_f != NULL);
	return internal_f(program, location, v0);
}

GLAPI void APIENTRY glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1)
{
	PFNGLPROGRAMUNIFORM2IEXTPROC internal_f = (PFNGLPROGRAMUNIFORM2IEXTPROC)gapil_gl_func_table[892];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1);
}

GLAPI void APIENTRY glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2)
{
	PFNGLPROGRAMUNIFORM3IEXTPROC internal_f = (PFNGLPROGRAMUNIFORM3IEXTPROC)gapil_gl_func_table[893];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2);
}

GLAPI void APIENTRY glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	PFNGLPROGRAMUNIFORM4IEXTPROC internal_f = (PFNGLPROGRAMUNIFORM4IEXTPROC)gapil_gl_func_table[894];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2, v3);
}

GLAPI void APIENTRY glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORM1FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM1FVEXTPROC)gapil_gl_func_table[895];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORM2FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM2FVEXTPROC)gapil_gl_func_table[896];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORM3FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM3FVEXTPROC)gapil_gl_func_table[897];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORM4FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM4FVEXTPROC)gapil_gl_func_table[898];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, const GLint * value)
{
	PFNGLPROGRAMUNIFORM1IVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM1IVEXTPROC)gapil_gl_func_table[899];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, const GLint * value)
{
	PFNGLPROGRAMUNIFORM2IVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM2IVEXTPROC)gapil_gl_func_table[900];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, const GLint * value)
{
	PFNGLPROGRAMUNIFORM3IVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM3IVEXTPROC)gapil_gl_func_table[901];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, const GLint * value)
{
	PFNGLPROGRAMUNIFORM4IVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM4IVEXTPROC)gapil_gl_func_table[902];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)gapil_gl_func_table[903];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)gapil_gl_func_table[904];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)gapil_gl_func_table[905];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)gapil_gl_func_table[906];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)gapil_gl_func_table[907];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)gapil_gl_func_table[908];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)gapil_gl_func_table[909];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)gapil_gl_func_table[910];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)gapil_gl_func_table[911];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer)
{
	PFNGLTEXTUREBUFFEREXTPROC internal_f = (PFNGLTEXTUREBUFFEREXTPROC)gapil_gl_func_table[912];
	assert(internal_f != NULL);
	return internal_f(texture, target, internalformat, buffer);
}

GLAPI void APIENTRY glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer)
{
	PFNGLMULTITEXBUFFEREXTPROC internal_f = (PFNGLMULTITEXBUFFEREXTPROC)gapil_gl_func_table[913];
	assert(internal_f != NULL);
	return internal_f(texunit, target, internalformat, buffer);
}

GLAPI void APIENTRY glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, const GLint * params)
{
	PFNGLTEXTUREPARAMETERIIVEXTPROC internal_f = (PFNGLTEXTUREPARAMETERIIVEXTPROC)gapil_gl_func_table[914];
	assert(internal_f != NULL);
	return internal_f(texture, target, pname, params);
}

GLAPI void APIENTRY glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, const GLuint * params)
{
	PFNGLTEXTUREPARAMETERIUIVEXTPROC internal_f = (PFNGLTEXTUREPARAMETERIUIVEXTPROC)gapil_gl_func_table[915];
	assert(internal_f != NULL);
	return internal_f(texture, target, pname, params);
}

GLAPI void APIENTRY glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETTEXTUREPARAMETERIIVEXTPROC internal_f = (PFNGLGETTEXTUREPARAMETERIIVEXTPROC)gapil_gl_func_table[916];
	assert(internal_f != NULL);
	return internal_f(texture, target, pname, params);
}

GLAPI void APIENTRY glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint * params)
{
	PFNGLGETTEXTUREPARAMETERIUIVEXTPROC internal_f = (PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)gapil_gl_func_table[917];
	assert(internal_f != NULL);
	return internal_f(texture, target, pname, params);
}

GLAPI void APIENTRY glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint * params)
{
	PFNGLMULTITEXPARAMETERIIVEXTPROC internal_f = (PFNGLMULTITEXPARAMETERIIVEXTPROC)gapil_gl_func_table[918];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, params);
}

GLAPI void APIENTRY glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, const GLuint * params)
{
	PFNGLMULTITEXPARAMETERIUIVEXTPROC internal_f = (PFNGLMULTITEXPARAMETERIUIVEXTPROC)gapil_gl_func_table[919];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, params);
}

GLAPI void APIENTRY glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETMULTITEXPARAMETERIIVEXTPROC internal_f = (PFNGLGETMULTITEXPARAMETERIIVEXTPROC)gapil_gl_func_table[920];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, params);
}

GLAPI void APIENTRY glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint * params)
{
	PFNGLGETMULTITEXPARAMETERIUIVEXTPROC internal_f = (PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)gapil_gl_func_table[921];
	assert(internal_f != NULL);
	return internal_f(texunit, target, pname, params);
}

GLAPI void APIENTRY glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0)
{
	PFNGLPROGRAMUNIFORM1UIEXTPROC internal_f = (PFNGLPROGRAMUNIFORM1UIEXTPROC)gapil_gl_func_table[922];
	assert(internal_f != NULL);
	return internal_f(program, location, v0);
}

GLAPI void APIENTRY glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1)
{
	PFNGLPROGRAMUNIFORM2UIEXTPROC internal_f = (PFNGLPROGRAMUNIFORM2UIEXTPROC)gapil_gl_func_table[923];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1);
}

GLAPI void APIENTRY glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)
{
	PFNGLPROGRAMUNIFORM3UIEXTPROC internal_f = (PFNGLPROGRAMUNIFORM3UIEXTPROC)gapil_gl_func_table[924];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2);
}

GLAPI void APIENTRY glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
	PFNGLPROGRAMUNIFORM4UIEXTPROC internal_f = (PFNGLPROGRAMUNIFORM4UIEXTPROC)gapil_gl_func_table[925];
	assert(internal_f != NULL);
	return internal_f(program, location, v0, v1, v2, v3);
}

GLAPI void APIENTRY glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, const GLuint * value)
{
	PFNGLPROGRAMUNIFORM1UIVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM1UIVEXTPROC)gapil_gl_func_table[926];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, const GLuint * value)
{
	PFNGLPROGRAMUNIFORM2UIVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM2UIVEXTPROC)gapil_gl_func_table[927];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, const GLuint * value)
{
	PFNGLPROGRAMUNIFORM3UIVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM3UIVEXTPROC)gapil_gl_func_table[928];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, const GLuint * value)
{
	PFNGLPROGRAMUNIFORM4UIVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM4UIVEXTPROC)gapil_gl_func_table[929];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat * params)
{
	PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC internal_f = (PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)gapil_gl_func_table[930];
	assert(internal_f != NULL);
	return internal_f(program, target, index, count, params);
}

GLAPI void APIENTRY glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w)
{
	PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC internal_f = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)gapil_gl_func_table[931];
	assert(internal_f != NULL);
	return internal_f(program, target, index, x, y, z, w);
}

GLAPI void APIENTRY glNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, const GLint * params)
{
	PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC internal_f = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)gapil_gl_func_table[932];
	assert(internal_f != NULL);
	return internal_f(program, target, index, params);
}

GLAPI void APIENTRY glNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint * params)
{
	PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC internal_f = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)gapil_gl_func_table[933];
	assert(internal_f != NULL);
	return internal_f(program, target, index, count, params);
}

GLAPI void APIENTRY glNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
{
	PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC internal_f = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)gapil_gl_func_table[934];
	assert(internal_f != NULL);
	return internal_f(program, target, index, x, y, z, w);
}

GLAPI void APIENTRY glNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, const GLuint * params)
{
	PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC internal_f = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)gapil_gl_func_table[935];
	assert(internal_f != NULL);
	return internal_f(program, target, index, params);
}

GLAPI void APIENTRY glNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint * params)
{
	PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC internal_f = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)gapil_gl_func_table[936];
	assert(internal_f != NULL);
	return internal_f(program, target, index, count, params);
}

GLAPI void APIENTRY glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint * params)
{
	PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC internal_f = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)gapil_gl_func_table[937];
	assert(internal_f != NULL);
	return internal_f(program, target, index, params);
}

GLAPI void APIENTRY glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint * params)
{
	PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC internal_f = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)gapil_gl_func_table[938];
	assert(internal_f != NULL);
	return internal_f(program, target, index, params);
}

GLAPI void APIENTRY glEnableClientStateiEXT(GLenum array, GLuint index)
{
	PFNGLENABLECLIENTSTATEIEXTPROC internal_f = (PFNGLENABLECLIENTSTATEIEXTPROC)gapil_gl_func_table[939];
	assert(internal_f != NULL);
	return internal_f(array, index);
}

GLAPI void APIENTRY glDisableClientStateiEXT(GLenum array, GLuint index)
{
	PFNGLDISABLECLIENTSTATEIEXTPROC internal_f = (PFNGLDISABLECLIENTSTATEIEXTPROC)gapil_gl_func_table[940];
	assert(internal_f != NULL);
	return internal_f(array, index);
}

GLAPI void APIENTRY glGetFloati_vEXT(GLenum pname, GLuint index, GLfloat * params)
{
	PFNGLGETFLOATI_VEXTPROC internal_f = (PFNGLGETFLOATI_VEXTPROC)gapil_gl_func_table[941];
	assert(internal_f != NULL);
	return internal_f(pname, index, params);
}

GLAPI void APIENTRY glGetDoublei_vEXT(GLenum pname, GLuint index, GLdouble * params)
{
	PFNGLGETDOUBLEI_VEXTPROC internal_f = (PFNGLGETDOUBLEI_VEXTPROC)gapil_gl_func_table[942];
	assert(internal_f != NULL);
	return internal_f(pname, index, params);
}

GLAPI void APIENTRY glGetPointeri_vEXT(GLenum pname, GLuint index, void ** params)
{
	PFNGLGETPOINTERI_VEXTPROC internal_f = (PFNGLGETPOINTERI_VEXTPROC)gapil_gl_func_table[943];
	assert(internal_f != NULL);
	return internal_f(pname, index, params);
}

GLAPI void APIENTRY glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const void * string)
{
	PFNGLNAMEDPROGRAMSTRINGEXTPROC internal_f = (PFNGLNAMEDPROGRAMSTRINGEXTPROC)gapil_gl_func_table[944];
	assert(internal_f != NULL);
	return internal_f(program, target, format, len, string);
}

GLAPI void APIENTRY glNamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC internal_f = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)gapil_gl_func_table[945];
	assert(internal_f != NULL);
	return internal_f(program, target, index, x, y, z, w);
}

GLAPI void APIENTRY glNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, const GLdouble * params)
{
	PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC internal_f = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)gapil_gl_func_table[946];
	assert(internal_f != NULL);
	return internal_f(program, target, index, params);
}

GLAPI void APIENTRY glNamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC internal_f = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)gapil_gl_func_table[947];
	assert(internal_f != NULL);
	return internal_f(program, target, index, x, y, z, w);
}

GLAPI void APIENTRY glNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, const GLfloat * params)
{
	PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC internal_f = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)gapil_gl_func_table[948];
	assert(internal_f != NULL);
	return internal_f(program, target, index, params);
}

GLAPI void APIENTRY glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble * params)
{
	PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC internal_f = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)gapil_gl_func_table[949];
	assert(internal_f != NULL);
	return internal_f(program, target, index, params);
}

GLAPI void APIENTRY glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat * params)
{
	PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC internal_f = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)gapil_gl_func_table[950];
	assert(internal_f != NULL);
	return internal_f(program, target, index, params);
}

GLAPI void APIENTRY glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETNAMEDPROGRAMIVEXTPROC internal_f = (PFNGLGETNAMEDPROGRAMIVEXTPROC)gapil_gl_func_table[951];
	assert(internal_f != NULL);
	return internal_f(program, target, pname, params);
}

GLAPI void APIENTRY glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, void * string)
{
	PFNGLGETNAMEDPROGRAMSTRINGEXTPROC internal_f = (PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)gapil_gl_func_table[952];
	assert(internal_f != NULL);
	return internal_f(program, target, pname, string);
}

GLAPI void APIENTRY glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC internal_f = (PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)gapil_gl_func_table[953];
	assert(internal_f != NULL);
	return internal_f(renderbuffer, internalformat, width, height);
}

GLAPI void APIENTRY glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint * params)
{
	PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC internal_f = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)gapil_gl_func_table[954];
	assert(internal_f != NULL);
	return internal_f(renderbuffer, pname, params);
}

GLAPI void APIENTRY glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC internal_f = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)gapil_gl_func_table[955];
	assert(internal_f != NULL);
	return internal_f(renderbuffer, samples, internalformat, width, height);
}

GLAPI void APIENTRY glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC internal_f = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)gapil_gl_func_table[956];
	assert(internal_f != NULL);
	return internal_f(renderbuffer, coverageSamples, colorSamples, internalformat, width, height);
}

GLAPI GLenum APIENTRY glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target)
{
	PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC internal_f = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)gapil_gl_func_table[957];
	assert(internal_f != NULL);
	return internal_f(framebuffer, target);
}

GLAPI void APIENTRY glNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC internal_f = (PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)gapil_gl_func_table[958];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, textarget, texture, level);
}

GLAPI void APIENTRY glNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC internal_f = (PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)gapil_gl_func_table[959];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, textarget, texture, level);
}

GLAPI void APIENTRY glNamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
{
	PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC internal_f = (PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)gapil_gl_func_table[960];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, textarget, texture, level, zoffset);
}

GLAPI void APIENTRY glNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
	PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC internal_f = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)gapil_gl_func_table[961];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, renderbuffertarget, renderbuffer);
}

GLAPI void APIENTRY glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params)
{
	PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC internal_f = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)gapil_gl_func_table[962];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, pname, params);
}

GLAPI void APIENTRY glGenerateTextureMipmapEXT(GLuint texture, GLenum target)
{
	PFNGLGENERATETEXTUREMIPMAPEXTPROC internal_f = (PFNGLGENERATETEXTUREMIPMAPEXTPROC)gapil_gl_func_table[963];
	assert(internal_f != NULL);
	return internal_f(texture, target);
}

GLAPI void APIENTRY glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target)
{
	PFNGLGENERATEMULTITEXMIPMAPEXTPROC internal_f = (PFNGLGENERATEMULTITEXMIPMAPEXTPROC)gapil_gl_func_table[964];
	assert(internal_f != NULL);
	return internal_f(texunit, target);
}

GLAPI void APIENTRY glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode)
{
	PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC internal_f = (PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)gapil_gl_func_table[965];
	assert(internal_f != NULL);
	return internal_f(framebuffer, mode);
}

GLAPI void APIENTRY glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum * bufs)
{
	PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC internal_f = (PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)gapil_gl_func_table[966];
	assert(internal_f != NULL);
	return internal_f(framebuffer, n, bufs);
}

GLAPI void APIENTRY glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode)
{
	PFNGLFRAMEBUFFERREADBUFFEREXTPROC internal_f = (PFNGLFRAMEBUFFERREADBUFFEREXTPROC)gapil_gl_func_table[967];
	assert(internal_f != NULL);
	return internal_f(framebuffer, mode);
}

GLAPI void APIENTRY glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint * params)
{
	PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC internal_f = (PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)gapil_gl_func_table[968];
	assert(internal_f != NULL);
	return internal_f(framebuffer, pname, params);
}

GLAPI void APIENTRY glNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
{
	PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC internal_f = (PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)gapil_gl_func_table[969];
	assert(internal_f != NULL);
	return internal_f(readBuffer, writeBuffer, readOffset, writeOffset, size);
}

GLAPI void APIENTRY glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level)
{
	PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC internal_f = (PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)gapil_gl_func_table[970];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, texture, level);
}

GLAPI void APIENTRY glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
	PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC internal_f = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)gapil_gl_func_table[971];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, texture, level, layer);
}

GLAPI void APIENTRY glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face)
{
	PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC internal_f = (PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)gapil_gl_func_table[972];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, texture, level, face);
}

GLAPI void APIENTRY glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer)
{
	PFNGLTEXTURERENDERBUFFEREXTPROC internal_f = (PFNGLTEXTURERENDERBUFFEREXTPROC)gapil_gl_func_table[973];
	assert(internal_f != NULL);
	return internal_f(texture, target, renderbuffer);
}

GLAPI void APIENTRY glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer)
{
	PFNGLMULTITEXRENDERBUFFEREXTPROC internal_f = (PFNGLMULTITEXRENDERBUFFEREXTPROC)gapil_gl_func_table[974];
	assert(internal_f != NULL);
	return internal_f(texunit, target, renderbuffer);
}

GLAPI void APIENTRY glVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset)
{
	PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC internal_f = (PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC)gapil_gl_func_table[975];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer, size, type, stride, offset);
}

GLAPI void APIENTRY glVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset)
{
	PFNGLVERTEXARRAYCOLOROFFSETEXTPROC internal_f = (PFNGLVERTEXARRAYCOLOROFFSETEXTPROC)gapil_gl_func_table[976];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer, size, type, stride, offset);
}

GLAPI void APIENTRY glVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset)
{
	PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC internal_f = (PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC)gapil_gl_func_table[977];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer, stride, offset);
}

GLAPI void APIENTRY glVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset)
{
	PFNGLVERTEXARRAYINDEXOFFSETEXTPROC internal_f = (PFNGLVERTEXARRAYINDEXOFFSETEXTPROC)gapil_gl_func_table[978];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer, type, stride, offset);
}

GLAPI void APIENTRY glVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset)
{
	PFNGLVERTEXARRAYNORMALOFFSETEXTPROC internal_f = (PFNGLVERTEXARRAYNORMALOFFSETEXTPROC)gapil_gl_func_table[979];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer, type, stride, offset);
}

GLAPI void APIENTRY glVertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset)
{
	PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC internal_f = (PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC)gapil_gl_func_table[980];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer, size, type, stride, offset);
}

GLAPI void APIENTRY glVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset)
{
	PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC internal_f = (PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC)gapil_gl_func_table[981];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer, texunit, size, type, stride, offset);
}

GLAPI void APIENTRY glVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset)
{
	PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC internal_f = (PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC)gapil_gl_func_table[982];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer, type, stride, offset);
}

GLAPI void APIENTRY glVertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset)
{
	PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC internal_f = (PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC)gapil_gl_func_table[983];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer, size, type, stride, offset);
}

GLAPI void APIENTRY glVertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset)
{
	PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC internal_f = (PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC)gapil_gl_func_table[984];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer, index, size, type, normalized, stride, offset);
}

GLAPI void APIENTRY glVertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset)
{
	PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC internal_f = (PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC)gapil_gl_func_table[985];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer, index, size, type, stride, offset);
}

GLAPI void APIENTRY glEnableVertexArrayEXT(GLuint vaobj, GLenum array)
{
	PFNGLENABLEVERTEXARRAYEXTPROC internal_f = (PFNGLENABLEVERTEXARRAYEXTPROC)gapil_gl_func_table[986];
	assert(internal_f != NULL);
	return internal_f(vaobj, array);
}

GLAPI void APIENTRY glDisableVertexArrayEXT(GLuint vaobj, GLenum array)
{
	PFNGLDISABLEVERTEXARRAYEXTPROC internal_f = (PFNGLDISABLEVERTEXARRAYEXTPROC)gapil_gl_func_table[987];
	assert(internal_f != NULL);
	return internal_f(vaobj, array);
}

GLAPI void APIENTRY glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index)
{
	PFNGLENABLEVERTEXARRAYATTRIBEXTPROC internal_f = (PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)gapil_gl_func_table[988];
	assert(internal_f != NULL);
	return internal_f(vaobj, index);
}

GLAPI void APIENTRY glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index)
{
	PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC internal_f = (PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)gapil_gl_func_table[989];
	assert(internal_f != NULL);
	return internal_f(vaobj, index);
}

GLAPI void APIENTRY glGetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint * param)
{
	PFNGLGETVERTEXARRAYINTEGERVEXTPROC internal_f = (PFNGLGETVERTEXARRAYINTEGERVEXTPROC)gapil_gl_func_table[990];
	assert(internal_f != NULL);
	return internal_f(vaobj, pname, param);
}

GLAPI void APIENTRY glGetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, void ** param)
{
	PFNGLGETVERTEXARRAYPOINTERVEXTPROC internal_f = (PFNGLGETVERTEXARRAYPOINTERVEXTPROC)gapil_gl_func_table[991];
	assert(internal_f != NULL);
	return internal_f(vaobj, pname, param);
}

GLAPI void APIENTRY glGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint * param)
{
	PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC internal_f = (PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC)gapil_gl_func_table[992];
	assert(internal_f != NULL);
	return internal_f(vaobj, index, pname, param);
}

GLAPI void APIENTRY glGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, void ** param)
{
	PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC internal_f = (PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC)gapil_gl_func_table[993];
	assert(internal_f != NULL);
	return internal_f(vaobj, index, pname, param);
}

GLAPI void * APIENTRY glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
	PFNGLMAPNAMEDBUFFERRANGEEXTPROC internal_f = (PFNGLMAPNAMEDBUFFERRANGEEXTPROC)gapil_gl_func_table[994];
	assert(internal_f != NULL);
	return internal_f(buffer, offset, length, access);
}

GLAPI void APIENTRY glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length)
{
	PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC internal_f = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)gapil_gl_func_table[995];
	assert(internal_f != NULL);
	return internal_f(buffer, offset, length);
}

GLAPI void APIENTRY glNamedBufferStorageEXT(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags)
{
	PFNGLNAMEDBUFFERSTORAGEEXTPROC internal_f = (PFNGLNAMEDBUFFERSTORAGEEXTPROC)gapil_gl_func_table[996];
	assert(internal_f != NULL);
	return internal_f(buffer, size, data, flags);
}

GLAPI void APIENTRY glClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data)
{
	PFNGLCLEARNAMEDBUFFERDATAEXTPROC internal_f = (PFNGLCLEARNAMEDBUFFERDATAEXTPROC)gapil_gl_func_table[997];
	assert(internal_f != NULL);
	return internal_f(buffer, internalformat, format, type, data);
}

GLAPI void APIENTRY glClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data)
{
	PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC internal_f = (PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)gapil_gl_func_table[998];
	assert(internal_f != NULL);
	return internal_f(buffer, internalformat, offset, size, format, type, data);
}

GLAPI void APIENTRY glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param)
{
	PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC internal_f = (PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)gapil_gl_func_table[999];
	assert(internal_f != NULL);
	return internal_f(framebuffer, pname, param);
}

GLAPI void APIENTRY glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint * params)
{
	PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC internal_f = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)gapil_gl_func_table[1000];
	assert(internal_f != NULL);
	return internal_f(framebuffer, pname, params);
}

GLAPI void APIENTRY glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x)
{
	PFNGLPROGRAMUNIFORM1DEXTPROC internal_f = (PFNGLPROGRAMUNIFORM1DEXTPROC)gapil_gl_func_table[1001];
	assert(internal_f != NULL);
	return internal_f(program, location, x);
}

GLAPI void APIENTRY glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y)
{
	PFNGLPROGRAMUNIFORM2DEXTPROC internal_f = (PFNGLPROGRAMUNIFORM2DEXTPROC)gapil_gl_func_table[1002];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y);
}

GLAPI void APIENTRY glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z)
{
	PFNGLPROGRAMUNIFORM3DEXTPROC internal_f = (PFNGLPROGRAMUNIFORM3DEXTPROC)gapil_gl_func_table[1003];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y, z);
}

GLAPI void APIENTRY glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	PFNGLPROGRAMUNIFORM4DEXTPROC internal_f = (PFNGLPROGRAMUNIFORM4DEXTPROC)gapil_gl_func_table[1004];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y, z, w);
}

GLAPI void APIENTRY glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORM1DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM1DVEXTPROC)gapil_gl_func_table[1005];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORM2DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM2DVEXTPROC)gapil_gl_func_table[1006];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORM3DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM3DVEXTPROC)gapil_gl_func_table[1007];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORM4DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORM4DVEXTPROC)gapil_gl_func_table[1008];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC)gapil_gl_func_table[1009];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC)gapil_gl_func_table[1010];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC)gapil_gl_func_table[1011];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix2x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC)gapil_gl_func_table[1012];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix2x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC)gapil_gl_func_table[1013];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix3x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC)gapil_gl_func_table[1014];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix3x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC)gapil_gl_func_table[1015];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix4x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC)gapil_gl_func_table[1016];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glProgramUniformMatrix4x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC internal_f = (PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC)gapil_gl_func_table[1017];
	assert(internal_f != NULL);
	return internal_f(program, location, count, transpose, value);
}

GLAPI void APIENTRY glTextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	PFNGLTEXTUREBUFFERRANGEEXTPROC internal_f = (PFNGLTEXTUREBUFFERRANGEEXTPROC)gapil_gl_func_table[1018];
	assert(internal_f != NULL);
	return internal_f(texture, target, internalformat, buffer, offset, size);
}

GLAPI void APIENTRY glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
{
	PFNGLTEXTURESTORAGE1DEXTPROC internal_f = (PFNGLTEXTURESTORAGE1DEXTPROC)gapil_gl_func_table[1019];
	assert(internal_f != NULL);
	return internal_f(texture, target, levels, internalformat, width);
}

GLAPI void APIENTRY glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLTEXTURESTORAGE2DEXTPROC internal_f = (PFNGLTEXTURESTORAGE2DEXTPROC)gapil_gl_func_table[1020];
	assert(internal_f != NULL);
	return internal_f(texture, target, levels, internalformat, width, height);
}

GLAPI void APIENTRY glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
	PFNGLTEXTURESTORAGE3DEXTPROC internal_f = (PFNGLTEXTURESTORAGE3DEXTPROC)gapil_gl_func_table[1021];
	assert(internal_f != NULL);
	return internal_f(texture, target, levels, internalformat, width, height, depth);
}

GLAPI void APIENTRY glTextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
{
	PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC internal_f = (PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)gapil_gl_func_table[1022];
	assert(internal_f != NULL);
	return internal_f(texture, target, samples, internalformat, width, height, fixedsamplelocations);
}

GLAPI void APIENTRY glTextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
{
	PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC internal_f = (PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)gapil_gl_func_table[1023];
	assert(internal_f != NULL);
	return internal_f(texture, target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

GLAPI void APIENTRY glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
{
	PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC internal_f = (PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)gapil_gl_func_table[1024];
	assert(internal_f != NULL);
	return internal_f(vaobj, bindingindex, buffer, offset, stride);
}

GLAPI void APIENTRY glVertexArrayVertexAttribFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
{
	PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC internal_f = (PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)gapil_gl_func_table[1025];
	assert(internal_f != NULL);
	return internal_f(vaobj, attribindex, size, type, normalized, relativeoffset);
}

GLAPI void APIENTRY glVertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
	PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC internal_f = (PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)gapil_gl_func_table[1026];
	assert(internal_f != NULL);
	return internal_f(vaobj, attribindex, size, type, relativeoffset);
}

GLAPI void APIENTRY glVertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
	PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC internal_f = (PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)gapil_gl_func_table[1027];
	assert(internal_f != NULL);
	return internal_f(vaobj, attribindex, size, type, relativeoffset);
}

GLAPI void APIENTRY glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex)
{
	PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC internal_f = (PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)gapil_gl_func_table[1028];
	assert(internal_f != NULL);
	return internal_f(vaobj, attribindex, bindingindex);
}

GLAPI void APIENTRY glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor)
{
	PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC internal_f = (PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)gapil_gl_func_table[1029];
	assert(internal_f != NULL);
	return internal_f(vaobj, bindingindex, divisor);
}

GLAPI void APIENTRY glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset)
{
	PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC internal_f = (PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC)gapil_gl_func_table[1030];
	assert(internal_f != NULL);
	return internal_f(vaobj, buffer, index, size, type, stride, offset);
}

GLAPI void APIENTRY glTexturePageCommitmentEXT(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit)
{
	PFNGLTEXTUREPAGECOMMITMENTEXTPROC internal_f = (PFNGLTEXTUREPAGECOMMITMENTEXTPROC)gapil_gl_func_table[1031];
	assert(internal_f != NULL);
	return internal_f(texture, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}

GLAPI void APIENTRY glVertexArrayVertexAttribDivisorEXT(GLuint vaobj, GLuint index, GLuint divisor)
{
	PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC internal_f = (PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC)gapil_gl_func_table[1032];
	assert(internal_f != NULL);
	return internal_f(vaobj, index, divisor);
}

GLAPI void APIENTRY glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount)
{
	PFNGLDRAWARRAYSINSTANCEDEXTPROC internal_f = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)gapil_gl_func_table[1033];
	assert(internal_f != NULL);
	return internal_f(mode, start, count, primcount);
}

GLAPI void APIENTRY glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount)
{
	PFNGLDRAWELEMENTSINSTANCEDEXTPROC internal_f = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC)gapil_gl_func_table[1034];
	assert(internal_f != NULL);
	return internal_f(mode, count, type, indices, primcount);
}

GLAPI void APIENTRY glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp)
{
	PFNGLPOLYGONOFFSETCLAMPEXTPROC internal_f = (PFNGLPOLYGONOFFSETCLAMPEXTPROC)gapil_gl_func_table[1035];
	assert(internal_f != NULL);
	return internal_f(factor, units, clamp);
}

GLAPI void APIENTRY glRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations)
{
	PFNGLRASTERSAMPLESEXTPROC internal_f = (PFNGLRASTERSAMPLESEXTPROC)gapil_gl_func_table[1036];
	assert(internal_f != NULL);
	return internal_f(samples, fixedsamplelocations);
}

GLAPI void APIENTRY glUseShaderProgramEXT(GLenum type, GLuint program)
{
	PFNGLUSESHADERPROGRAMEXTPROC internal_f = (PFNGLUSESHADERPROGRAMEXTPROC)gapil_gl_func_table[1037];
	assert(internal_f != NULL);
	return internal_f(type, program);
}

GLAPI void APIENTRY glActiveProgramEXT(GLuint program)
{
	PFNGLACTIVEPROGRAMEXTPROC internal_f = (PFNGLACTIVEPROGRAMEXTPROC)gapil_gl_func_table[1038];
	assert(internal_f != NULL);
	return internal_f(program);
}

GLAPI GLuint APIENTRY glCreateShaderProgramEXT(GLenum type, const GLchar * string)
{
	PFNGLCREATESHADERPROGRAMEXTPROC internal_f = (PFNGLCREATESHADERPROGRAMEXTPROC)gapil_gl_func_table[1039];
	assert(internal_f != NULL);
	return internal_f(type, string);
}

GLAPI void APIENTRY glFramebufferFetchBarrierEXT()
{
	PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC internal_f = (PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC)gapil_gl_func_table[1040];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glTexStorage1DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
{
	PFNGLTEXSTORAGE1DEXTPROC internal_f = (PFNGLTEXSTORAGE1DEXTPROC)gapil_gl_func_table[1041];
	assert(internal_f != NULL);
	return internal_f(target, levels, internalformat, width);
}

GLAPI void APIENTRY glTexStorage2DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLTEXSTORAGE2DEXTPROC internal_f = (PFNGLTEXSTORAGE2DEXTPROC)gapil_gl_func_table[1042];
	assert(internal_f != NULL);
	return internal_f(target, levels, internalformat, width, height);
}

GLAPI void APIENTRY glTexStorage3DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
	PFNGLTEXSTORAGE3DEXTPROC internal_f = (PFNGLTEXSTORAGE3DEXTPROC)gapil_gl_func_table[1043];
	assert(internal_f != NULL);
	return internal_f(target, levels, internalformat, width, height, depth);
}

GLAPI void APIENTRY glWindowRectanglesEXT(GLenum mode, GLsizei count, const GLint * box)
{
	PFNGLWINDOWRECTANGLESEXTPROC internal_f = (PFNGLWINDOWRECTANGLESEXTPROC)gapil_gl_func_table[1044];
	assert(internal_f != NULL);
	return internal_f(mode, count, box);
}

GLAPI void APIENTRY glApplyFramebufferAttachmentCMAAINTEL()
{
	PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC internal_f = (PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC)gapil_gl_func_table[1045];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glBeginPerfQueryINTEL(GLuint queryHandle)
{
	PFNGLBEGINPERFQUERYINTELPROC internal_f = (PFNGLBEGINPERFQUERYINTELPROC)gapil_gl_func_table[1046];
	assert(internal_f != NULL);
	return internal_f(queryHandle);
}

GLAPI void APIENTRY glCreatePerfQueryINTEL(GLuint queryId, GLuint * queryHandle)
{
	PFNGLCREATEPERFQUERYINTELPROC internal_f = (PFNGLCREATEPERFQUERYINTELPROC)gapil_gl_func_table[1047];
	assert(internal_f != NULL);
	return internal_f(queryId, queryHandle);
}

GLAPI void APIENTRY glDeletePerfQueryINTEL(GLuint queryHandle)
{
	PFNGLDELETEPERFQUERYINTELPROC internal_f = (PFNGLDELETEPERFQUERYINTELPROC)gapil_gl_func_table[1048];
	assert(internal_f != NULL);
	return internal_f(queryHandle);
}

GLAPI void APIENTRY glEndPerfQueryINTEL(GLuint queryHandle)
{
	PFNGLENDPERFQUERYINTELPROC internal_f = (PFNGLENDPERFQUERYINTELPROC)gapil_gl_func_table[1049];
	assert(internal_f != NULL);
	return internal_f(queryHandle);
}

GLAPI void APIENTRY glGetFirstPerfQueryIdINTEL(GLuint * queryId)
{
	PFNGLGETFIRSTPERFQUERYIDINTELPROC internal_f = (PFNGLGETFIRSTPERFQUERYIDINTELPROC)gapil_gl_func_table[1050];
	assert(internal_f != NULL);
	return internal_f(queryId);
}

GLAPI void APIENTRY glGetNextPerfQueryIdINTEL(GLuint queryId, GLuint * nextQueryId)
{
	PFNGLGETNEXTPERFQUERYIDINTELPROC internal_f = (PFNGLGETNEXTPERFQUERYIDINTELPROC)gapil_gl_func_table[1051];
	assert(internal_f != NULL);
	return internal_f(queryId, nextQueryId);
}

GLAPI void APIENTRY glGetPerfCounterInfoINTEL(GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar * counterName, GLuint counterDescLength, GLchar * counterDesc, GLuint * counterOffset, GLuint * counterDataSize, GLuint * counterTypeEnum, GLuint * counterDataTypeEnum, GLuint64 * rawCounterMaxValue)
{
	PFNGLGETPERFCOUNTERINFOINTELPROC internal_f = (PFNGLGETPERFCOUNTERINFOINTELPROC)gapil_gl_func_table[1052];
	assert(internal_f != NULL);
	return internal_f(queryId, counterId, counterNameLength, counterName, counterDescLength, counterDesc, counterOffset, counterDataSize, counterTypeEnum, counterDataTypeEnum, rawCounterMaxValue);
}

GLAPI void APIENTRY glGetPerfQueryDataINTEL(GLuint queryHandle, GLuint flags, GLsizei dataSize, void * data, GLuint * bytesWritten)
{
	PFNGLGETPERFQUERYDATAINTELPROC internal_f = (PFNGLGETPERFQUERYDATAINTELPROC)gapil_gl_func_table[1053];
	assert(internal_f != NULL);
	return internal_f(queryHandle, flags, dataSize, data, bytesWritten);
}

GLAPI void APIENTRY glGetPerfQueryIdByNameINTEL(GLchar * queryName, GLuint * queryId)
{
	PFNGLGETPERFQUERYIDBYNAMEINTELPROC internal_f = (PFNGLGETPERFQUERYIDBYNAMEINTELPROC)gapil_gl_func_table[1054];
	assert(internal_f != NULL);
	return internal_f(queryName, queryId);
}

GLAPI void APIENTRY glGetPerfQueryInfoINTEL(GLuint queryId, GLuint queryNameLength, GLchar * queryName, GLuint * dataSize, GLuint * noCounters, GLuint * noInstances, GLuint * capsMask)
{
	PFNGLGETPERFQUERYINFOINTELPROC internal_f = (PFNGLGETPERFQUERYINFOINTELPROC)gapil_gl_func_table[1055];
	assert(internal_f != NULL);
	return internal_f(queryId, queryNameLength, queryName, dataSize, noCounters, noInstances, capsMask);
}

GLAPI void APIENTRY glFramebufferParameteriMESA(GLenum target, GLenum pname, GLint param)
{
	PFNGLFRAMEBUFFERPARAMETERIMESAPROC internal_f = (PFNGLFRAMEBUFFERPARAMETERIMESAPROC)gapil_gl_func_table[1056];
	assert(internal_f != NULL);
	return internal_f(target, pname, param);
}

GLAPI void APIENTRY glGetFramebufferParameterivMESA(GLenum target, GLenum pname, GLint * params)
{
	PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC internal_f = (PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC)gapil_gl_func_table[1057];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glMultiDrawArraysIndirectBindlessNV(GLenum mode, const void * indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount)
{
	PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC internal_f = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC)gapil_gl_func_table[1058];
	assert(internal_f != NULL);
	return internal_f(mode, indirect, drawCount, stride, vertexBufferCount);
}

GLAPI void APIENTRY glMultiDrawElementsIndirectBindlessNV(GLenum mode, GLenum type, const void * indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount)
{
	PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC internal_f = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC)gapil_gl_func_table[1059];
	assert(internal_f != NULL);
	return internal_f(mode, type, indirect, drawCount, stride, vertexBufferCount);
}

GLAPI void APIENTRY glMultiDrawArraysIndirectBindlessCountNV(GLenum mode, const void * indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount)
{
	PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC internal_f = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC)gapil_gl_func_table[1060];
	assert(internal_f != NULL);
	return internal_f(mode, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
}

GLAPI void APIENTRY glMultiDrawElementsIndirectBindlessCountNV(GLenum mode, GLenum type, const void * indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount)
{
	PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC internal_f = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC)gapil_gl_func_table[1061];
	assert(internal_f != NULL);
	return internal_f(mode, type, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
}

GLAPI GLuint64 APIENTRY glGetTextureHandleNV(GLuint texture)
{
	PFNGLGETTEXTUREHANDLENVPROC internal_f = (PFNGLGETTEXTUREHANDLENVPROC)gapil_gl_func_table[1062];
	assert(internal_f != NULL);
	return internal_f(texture);
}

GLAPI GLuint64 APIENTRY glGetTextureSamplerHandleNV(GLuint texture, GLuint sampler)
{
	PFNGLGETTEXTURESAMPLERHANDLENVPROC internal_f = (PFNGLGETTEXTURESAMPLERHANDLENVPROC)gapil_gl_func_table[1063];
	assert(internal_f != NULL);
	return internal_f(texture, sampler);
}

GLAPI void APIENTRY glMakeTextureHandleResidentNV(GLuint64 handle)
{
	PFNGLMAKETEXTUREHANDLERESIDENTNVPROC internal_f = (PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)gapil_gl_func_table[1064];
	assert(internal_f != NULL);
	return internal_f(handle);
}

GLAPI void APIENTRY glMakeTextureHandleNonResidentNV(GLuint64 handle)
{
	PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC internal_f = (PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)gapil_gl_func_table[1065];
	assert(internal_f != NULL);
	return internal_f(handle);
}

GLAPI GLuint64 APIENTRY glGetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format)
{
	PFNGLGETIMAGEHANDLENVPROC internal_f = (PFNGLGETIMAGEHANDLENVPROC)gapil_gl_func_table[1066];
	assert(internal_f != NULL);
	return internal_f(texture, level, layered, layer, format);
}

GLAPI void APIENTRY glMakeImageHandleResidentNV(GLuint64 handle, GLenum access)
{
	PFNGLMAKEIMAGEHANDLERESIDENTNVPROC internal_f = (PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)gapil_gl_func_table[1067];
	assert(internal_f != NULL);
	return internal_f(handle, access);
}

GLAPI void APIENTRY glMakeImageHandleNonResidentNV(GLuint64 handle)
{
	PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC internal_f = (PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)gapil_gl_func_table[1068];
	assert(internal_f != NULL);
	return internal_f(handle);
}

GLAPI void APIENTRY glUniformHandleui64NV(GLint location, GLuint64 value)
{
	PFNGLUNIFORMHANDLEUI64NVPROC internal_f = (PFNGLUNIFORMHANDLEUI64NVPROC)gapil_gl_func_table[1069];
	assert(internal_f != NULL);
	return internal_f(location, value);
}

GLAPI void APIENTRY glUniformHandleui64vNV(GLint location, GLsizei count, const GLuint64 * value)
{
	PFNGLUNIFORMHANDLEUI64VNVPROC internal_f = (PFNGLUNIFORMHANDLEUI64VNVPROC)gapil_gl_func_table[1070];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glProgramUniformHandleui64NV(GLuint program, GLint location, GLuint64 value)
{
	PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC internal_f = (PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC)gapil_gl_func_table[1071];
	assert(internal_f != NULL);
	return internal_f(program, location, value);
}

GLAPI void APIENTRY glProgramUniformHandleui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64 * values)
{
	PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC internal_f = (PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC)gapil_gl_func_table[1072];
	assert(internal_f != NULL);
	return internal_f(program, location, count, values);
}

GLAPI GLboolean APIENTRY glIsTextureHandleResidentNV(GLuint64 handle)
{
	PFNGLISTEXTUREHANDLERESIDENTNVPROC internal_f = (PFNGLISTEXTUREHANDLERESIDENTNVPROC)gapil_gl_func_table[1073];
	assert(internal_f != NULL);
	return internal_f(handle);
}

GLAPI GLboolean APIENTRY glIsImageHandleResidentNV(GLuint64 handle)
{
	PFNGLISIMAGEHANDLERESIDENTNVPROC internal_f = (PFNGLISIMAGEHANDLERESIDENTNVPROC)gapil_gl_func_table[1074];
	assert(internal_f != NULL);
	return internal_f(handle);
}

GLAPI void APIENTRY glBlendParameteriNV(GLenum pname, GLint value)
{
	PFNGLBLENDPARAMETERINVPROC internal_f = (PFNGLBLENDPARAMETERINVPROC)gapil_gl_func_table[1075];
	assert(internal_f != NULL);
	return internal_f(pname, value);
}

GLAPI void APIENTRY glBlendBarrierNV()
{
	PFNGLBLENDBARRIERNVPROC internal_f = (PFNGLBLENDBARRIERNVPROC)gapil_gl_func_table[1076];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glViewportPositionWScaleNV(GLuint index, GLfloat xcoeff, GLfloat ycoeff)
{
	PFNGLVIEWPORTPOSITIONWSCALENVPROC internal_f = (PFNGLVIEWPORTPOSITIONWSCALENVPROC)gapil_gl_func_table[1077];
	assert(internal_f != NULL);
	return internal_f(index, xcoeff, ycoeff);
}

GLAPI void APIENTRY glCreateStatesNV(GLsizei n, GLuint * states)
{
	PFNGLCREATESTATESNVPROC internal_f = (PFNGLCREATESTATESNVPROC)gapil_gl_func_table[1078];
	assert(internal_f != NULL);
	return internal_f(n, states);
}

GLAPI void APIENTRY glDeleteStatesNV(GLsizei n, const GLuint * states)
{
	PFNGLDELETESTATESNVPROC internal_f = (PFNGLDELETESTATESNVPROC)gapil_gl_func_table[1079];
	assert(internal_f != NULL);
	return internal_f(n, states);
}

GLAPI GLboolean APIENTRY glIsStateNV(GLuint state)
{
	PFNGLISSTATENVPROC internal_f = (PFNGLISSTATENVPROC)gapil_gl_func_table[1080];
	assert(internal_f != NULL);
	return internal_f(state);
}

GLAPI void APIENTRY glStateCaptureNV(GLuint state, GLenum mode)
{
	PFNGLSTATECAPTURENVPROC internal_f = (PFNGLSTATECAPTURENVPROC)gapil_gl_func_table[1081];
	assert(internal_f != NULL);
	return internal_f(state, mode);
}

GLAPI GLuint APIENTRY glGetCommandHeaderNV(GLenum tokenID, GLuint size)
{
	PFNGLGETCOMMANDHEADERNVPROC internal_f = (PFNGLGETCOMMANDHEADERNVPROC)gapil_gl_func_table[1082];
	assert(internal_f != NULL);
	return internal_f(tokenID, size);
}

GLAPI GLushort APIENTRY glGetStageIndexNV(GLenum shadertype)
{
	PFNGLGETSTAGEINDEXNVPROC internal_f = (PFNGLGETSTAGEINDEXNVPROC)gapil_gl_func_table[1083];
	assert(internal_f != NULL);
	return internal_f(shadertype);
}

GLAPI void APIENTRY glDrawCommandsNV(GLenum primitiveMode, GLuint buffer, const GLintptr * indirects, const GLsizei * sizes, GLuint count)
{
	PFNGLDRAWCOMMANDSNVPROC internal_f = (PFNGLDRAWCOMMANDSNVPROC)gapil_gl_func_table[1084];
	assert(internal_f != NULL);
	return internal_f(primitiveMode, buffer, indirects, sizes, count);
}

GLAPI void APIENTRY glDrawCommandsAddressNV(GLenum primitiveMode, const GLuint64 * indirects, const GLsizei * sizes, GLuint count)
{
	PFNGLDRAWCOMMANDSADDRESSNVPROC internal_f = (PFNGLDRAWCOMMANDSADDRESSNVPROC)gapil_gl_func_table[1085];
	assert(internal_f != NULL);
	return internal_f(primitiveMode, indirects, sizes, count);
}

GLAPI void APIENTRY glDrawCommandsStatesNV(GLuint buffer, const GLintptr * indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count)
{
	PFNGLDRAWCOMMANDSSTATESNVPROC internal_f = (PFNGLDRAWCOMMANDSSTATESNVPROC)gapil_gl_func_table[1086];
	assert(internal_f != NULL);
	return internal_f(buffer, indirects, sizes, states, fbos, count);
}

GLAPI void APIENTRY glDrawCommandsStatesAddressNV(const GLuint64 * indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count)
{
	PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC internal_f = (PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC)gapil_gl_func_table[1087];
	assert(internal_f != NULL);
	return internal_f(indirects, sizes, states, fbos, count);
}

GLAPI void APIENTRY glCreateCommandListsNV(GLsizei n, GLuint * lists)
{
	PFNGLCREATECOMMANDLISTSNVPROC internal_f = (PFNGLCREATECOMMANDLISTSNVPROC)gapil_gl_func_table[1088];
	assert(internal_f != NULL);
	return internal_f(n, lists);
}

GLAPI void APIENTRY glDeleteCommandListsNV(GLsizei n, const GLuint * lists)
{
	PFNGLDELETECOMMANDLISTSNVPROC internal_f = (PFNGLDELETECOMMANDLISTSNVPROC)gapil_gl_func_table[1089];
	assert(internal_f != NULL);
	return internal_f(n, lists);
}

GLAPI GLboolean APIENTRY glIsCommandListNV(GLuint list)
{
	PFNGLISCOMMANDLISTNVPROC internal_f = (PFNGLISCOMMANDLISTNVPROC)gapil_gl_func_table[1090];
	assert(internal_f != NULL);
	return internal_f(list);
}

GLAPI void APIENTRY glListDrawCommandsStatesClientNV(GLuint list, GLuint segment, const void ** indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count)
{
	PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC internal_f = (PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC)gapil_gl_func_table[1091];
	assert(internal_f != NULL);
	return internal_f(list, segment, indirects, sizes, states, fbos, count);
}

GLAPI void APIENTRY glCommandListSegmentsNV(GLuint list, GLuint segments)
{
	PFNGLCOMMANDLISTSEGMENTSNVPROC internal_f = (PFNGLCOMMANDLISTSEGMENTSNVPROC)gapil_gl_func_table[1092];
	assert(internal_f != NULL);
	return internal_f(list, segments);
}

GLAPI void APIENTRY glCompileCommandListNV(GLuint list)
{
	PFNGLCOMPILECOMMANDLISTNVPROC internal_f = (PFNGLCOMPILECOMMANDLISTNVPROC)gapil_gl_func_table[1093];
	assert(internal_f != NULL);
	return internal_f(list);
}

GLAPI void APIENTRY glCallCommandListNV(GLuint list)
{
	PFNGLCALLCOMMANDLISTNVPROC internal_f = (PFNGLCALLCOMMANDLISTNVPROC)gapil_gl_func_table[1094];
	assert(internal_f != NULL);
	return internal_f(list);
}

GLAPI void APIENTRY glBeginConditionalRenderNV(GLuint id, GLenum mode)
{
	PFNGLBEGINCONDITIONALRENDERNVPROC internal_f = (PFNGLBEGINCONDITIONALRENDERNVPROC)gapil_gl_func_table[1095];
	assert(internal_f != NULL);
	return internal_f(id, mode);
}

GLAPI void APIENTRY glEndConditionalRenderNV()
{
	PFNGLENDCONDITIONALRENDERNVPROC internal_f = (PFNGLENDCONDITIONALRENDERNVPROC)gapil_gl_func_table[1096];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glSubpixelPrecisionBiasNV(GLuint xbits, GLuint ybits)
{
	PFNGLSUBPIXELPRECISIONBIASNVPROC internal_f = (PFNGLSUBPIXELPRECISIONBIASNVPROC)gapil_gl_func_table[1097];
	assert(internal_f != NULL);
	return internal_f(xbits, ybits);
}

GLAPI void APIENTRY glConservativeRasterParameterfNV(GLenum pname, GLfloat value)
{
	PFNGLCONSERVATIVERASTERPARAMETERFNVPROC internal_f = (PFNGLCONSERVATIVERASTERPARAMETERFNVPROC)gapil_gl_func_table[1098];
	assert(internal_f != NULL);
	return internal_f(pname, value);
}

GLAPI void APIENTRY glConservativeRasterParameteriNV(GLenum pname, GLint param)
{
	PFNGLCONSERVATIVERASTERPARAMETERINVPROC internal_f = (PFNGLCONSERVATIVERASTERPARAMETERINVPROC)gapil_gl_func_table[1099];
	assert(internal_f != NULL);
	return internal_f(pname, param);
}

GLAPI void APIENTRY glDepthRangedNV(GLdouble zNear, GLdouble zFar)
{
	PFNGLDEPTHRANGEDNVPROC internal_f = (PFNGLDEPTHRANGEDNVPROC)gapil_gl_func_table[1100];
	assert(internal_f != NULL);
	return internal_f(zNear, zFar);
}

GLAPI void APIENTRY glClearDepthdNV(GLdouble depth)
{
	PFNGLCLEARDEPTHDNVPROC internal_f = (PFNGLCLEARDEPTHDNVPROC)gapil_gl_func_table[1101];
	assert(internal_f != NULL);
	return internal_f(depth);
}

GLAPI void APIENTRY glDepthBoundsdNV(GLdouble zmin, GLdouble zmax)
{
	PFNGLDEPTHBOUNDSDNVPROC internal_f = (PFNGLDEPTHBOUNDSDNVPROC)gapil_gl_func_table[1102];
	assert(internal_f != NULL);
	return internal_f(zmin, zmax);
}

GLAPI void APIENTRY glDrawVkImageNV(GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1)
{
	PFNGLDRAWVKIMAGENVPROC internal_f = (PFNGLDRAWVKIMAGENVPROC)gapil_gl_func_table[1103];
	assert(internal_f != NULL);
	return internal_f(vkImage, sampler, x0, y0, x1, y1, z, s0, t0, s1, t1);
}

GLAPI GLVULKANPROCNV APIENTRY glGetVkProcAddrNV(const GLchar * name)
{
	PFNGLGETVKPROCADDRNVPROC internal_f = (PFNGLGETVKPROCADDRNVPROC)gapil_gl_func_table[1104];
	assert(internal_f != NULL);
	return internal_f(name);
}

GLAPI void APIENTRY glWaitVkSemaphoreNV(GLuint64 vkSemaphore)
{
	PFNGLWAITVKSEMAPHORENVPROC internal_f = (PFNGLWAITVKSEMAPHORENVPROC)gapil_gl_func_table[1105];
	assert(internal_f != NULL);
	return internal_f(vkSemaphore);
}

GLAPI void APIENTRY glSignalVkSemaphoreNV(GLuint64 vkSemaphore)
{
	PFNGLSIGNALVKSEMAPHORENVPROC internal_f = (PFNGLSIGNALVKSEMAPHORENVPROC)gapil_gl_func_table[1106];
	assert(internal_f != NULL);
	return internal_f(vkSemaphore);
}

GLAPI void APIENTRY glSignalVkFenceNV(GLuint64 vkFence)
{
	PFNGLSIGNALVKFENCENVPROC internal_f = (PFNGLSIGNALVKFENCENVPROC)gapil_gl_func_table[1107];
	assert(internal_f != NULL);
	return internal_f(vkFence);
}

GLAPI void APIENTRY glFragmentCoverageColorNV(GLuint color)
{
	PFNGLFRAGMENTCOVERAGECOLORNVPROC internal_f = (PFNGLFRAGMENTCOVERAGECOLORNVPROC)gapil_gl_func_table[1108];
	assert(internal_f != NULL);
	return internal_f(color);
}

GLAPI void APIENTRY glCoverageModulationTableNV(GLsizei n, const GLfloat * v)
{
	PFNGLCOVERAGEMODULATIONTABLENVPROC internal_f = (PFNGLCOVERAGEMODULATIONTABLENVPROC)gapil_gl_func_table[1109];
	assert(internal_f != NULL);
	return internal_f(n, v);
}

GLAPI void APIENTRY glGetCoverageModulationTableNV(GLsizei bufSize, GLfloat * v)
{
	PFNGLGETCOVERAGEMODULATIONTABLENVPROC internal_f = (PFNGLGETCOVERAGEMODULATIONTABLENVPROC)gapil_gl_func_table[1110];
	assert(internal_f != NULL);
	return internal_f(bufSize, v);
}

GLAPI void APIENTRY glCoverageModulationNV(GLenum components)
{
	PFNGLCOVERAGEMODULATIONNVPROC internal_f = (PFNGLCOVERAGEMODULATIONNVPROC)gapil_gl_func_table[1111];
	assert(internal_f != NULL);
	return internal_f(components);
}

GLAPI void APIENTRY glRenderbufferStorageMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height)
{
	PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC internal_f = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)gapil_gl_func_table[1112];
	assert(internal_f != NULL);
	return internal_f(target, coverageSamples, colorSamples, internalformat, width, height);
}

GLAPI void APIENTRY glUniform1i64NV(GLint location, GLint64EXT x)
{
	PFNGLUNIFORM1I64NVPROC internal_f = (PFNGLUNIFORM1I64NVPROC)gapil_gl_func_table[1113];
	assert(internal_f != NULL);
	return internal_f(location, x);
}

GLAPI void APIENTRY glUniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y)
{
	PFNGLUNIFORM2I64NVPROC internal_f = (PFNGLUNIFORM2I64NVPROC)gapil_gl_func_table[1114];
	assert(internal_f != NULL);
	return internal_f(location, x, y);
}

GLAPI void APIENTRY glUniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z)
{
	PFNGLUNIFORM3I64NVPROC internal_f = (PFNGLUNIFORM3I64NVPROC)gapil_gl_func_table[1115];
	assert(internal_f != NULL);
	return internal_f(location, x, y, z);
}

GLAPI void APIENTRY glUniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)
{
	PFNGLUNIFORM4I64NVPROC internal_f = (PFNGLUNIFORM4I64NVPROC)gapil_gl_func_table[1116];
	assert(internal_f != NULL);
	return internal_f(location, x, y, z, w);
}

GLAPI void APIENTRY glUniform1i64vNV(GLint location, GLsizei count, const GLint64EXT * value)
{
	PFNGLUNIFORM1I64VNVPROC internal_f = (PFNGLUNIFORM1I64VNVPROC)gapil_gl_func_table[1117];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform2i64vNV(GLint location, GLsizei count, const GLint64EXT * value)
{
	PFNGLUNIFORM2I64VNVPROC internal_f = (PFNGLUNIFORM2I64VNVPROC)gapil_gl_func_table[1118];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform3i64vNV(GLint location, GLsizei count, const GLint64EXT * value)
{
	PFNGLUNIFORM3I64VNVPROC internal_f = (PFNGLUNIFORM3I64VNVPROC)gapil_gl_func_table[1119];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform4i64vNV(GLint location, GLsizei count, const GLint64EXT * value)
{
	PFNGLUNIFORM4I64VNVPROC internal_f = (PFNGLUNIFORM4I64VNVPROC)gapil_gl_func_table[1120];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform1ui64NV(GLint location, GLuint64EXT x)
{
	PFNGLUNIFORM1UI64NVPROC internal_f = (PFNGLUNIFORM1UI64NVPROC)gapil_gl_func_table[1121];
	assert(internal_f != NULL);
	return internal_f(location, x);
}

GLAPI void APIENTRY glUniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y)
{
	PFNGLUNIFORM2UI64NVPROC internal_f = (PFNGLUNIFORM2UI64NVPROC)gapil_gl_func_table[1122];
	assert(internal_f != NULL);
	return internal_f(location, x, y);
}

GLAPI void APIENTRY glUniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)
{
	PFNGLUNIFORM3UI64NVPROC internal_f = (PFNGLUNIFORM3UI64NVPROC)gapil_gl_func_table[1123];
	assert(internal_f != NULL);
	return internal_f(location, x, y, z);
}

GLAPI void APIENTRY glUniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)
{
	PFNGLUNIFORM4UI64NVPROC internal_f = (PFNGLUNIFORM4UI64NVPROC)gapil_gl_func_table[1124];
	assert(internal_f != NULL);
	return internal_f(location, x, y, z, w);
}

GLAPI void APIENTRY glUniform1ui64vNV(GLint location, GLsizei count, const GLuint64EXT * value)
{
	PFNGLUNIFORM1UI64VNVPROC internal_f = (PFNGLUNIFORM1UI64VNVPROC)gapil_gl_func_table[1125];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform2ui64vNV(GLint location, GLsizei count, const GLuint64EXT * value)
{
	PFNGLUNIFORM2UI64VNVPROC internal_f = (PFNGLUNIFORM2UI64VNVPROC)gapil_gl_func_table[1126];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform3ui64vNV(GLint location, GLsizei count, const GLuint64EXT * value)
{
	PFNGLUNIFORM3UI64VNVPROC internal_f = (PFNGLUNIFORM3UI64VNVPROC)gapil_gl_func_table[1127];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glUniform4ui64vNV(GLint location, GLsizei count, const GLuint64EXT * value)
{
	PFNGLUNIFORM4UI64VNVPROC internal_f = (PFNGLUNIFORM4UI64VNVPROC)gapil_gl_func_table[1128];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glGetUniformi64vNV(GLuint program, GLint location, GLint64EXT * params)
{
	PFNGLGETUNIFORMI64VNVPROC internal_f = (PFNGLGETUNIFORMI64VNVPROC)gapil_gl_func_table[1129];
	assert(internal_f != NULL);
	return internal_f(program, location, params);
}

GLAPI void APIENTRY glProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x)
{
	PFNGLPROGRAMUNIFORM1I64NVPROC internal_f = (PFNGLPROGRAMUNIFORM1I64NVPROC)gapil_gl_func_table[1130];
	assert(internal_f != NULL);
	return internal_f(program, location, x);
}

GLAPI void APIENTRY glProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y)
{
	PFNGLPROGRAMUNIFORM2I64NVPROC internal_f = (PFNGLPROGRAMUNIFORM2I64NVPROC)gapil_gl_func_table[1131];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y);
}

GLAPI void APIENTRY glProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z)
{
	PFNGLPROGRAMUNIFORM3I64NVPROC internal_f = (PFNGLPROGRAMUNIFORM3I64NVPROC)gapil_gl_func_table[1132];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y, z);
}

GLAPI void APIENTRY glProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)
{
	PFNGLPROGRAMUNIFORM4I64NVPROC internal_f = (PFNGLPROGRAMUNIFORM4I64NVPROC)gapil_gl_func_table[1133];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y, z, w);
}

GLAPI void APIENTRY glProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT * value)
{
	PFNGLPROGRAMUNIFORM1I64VNVPROC internal_f = (PFNGLPROGRAMUNIFORM1I64VNVPROC)gapil_gl_func_table[1134];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT * value)
{
	PFNGLPROGRAMUNIFORM2I64VNVPROC internal_f = (PFNGLPROGRAMUNIFORM2I64VNVPROC)gapil_gl_func_table[1135];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT * value)
{
	PFNGLPROGRAMUNIFORM3I64VNVPROC internal_f = (PFNGLPROGRAMUNIFORM3I64VNVPROC)gapil_gl_func_table[1136];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT * value)
{
	PFNGLPROGRAMUNIFORM4I64VNVPROC internal_f = (PFNGLPROGRAMUNIFORM4I64VNVPROC)gapil_gl_func_table[1137];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x)
{
	PFNGLPROGRAMUNIFORM1UI64NVPROC internal_f = (PFNGLPROGRAMUNIFORM1UI64NVPROC)gapil_gl_func_table[1138];
	assert(internal_f != NULL);
	return internal_f(program, location, x);
}

GLAPI void APIENTRY glProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y)
{
	PFNGLPROGRAMUNIFORM2UI64NVPROC internal_f = (PFNGLPROGRAMUNIFORM2UI64NVPROC)gapil_gl_func_table[1139];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y);
}

GLAPI void APIENTRY glProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)
{
	PFNGLPROGRAMUNIFORM3UI64NVPROC internal_f = (PFNGLPROGRAMUNIFORM3UI64NVPROC)gapil_gl_func_table[1140];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y, z);
}

GLAPI void APIENTRY glProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)
{
	PFNGLPROGRAMUNIFORM4UI64NVPROC internal_f = (PFNGLPROGRAMUNIFORM4UI64NVPROC)gapil_gl_func_table[1141];
	assert(internal_f != NULL);
	return internal_f(program, location, x, y, z, w);
}

GLAPI void APIENTRY glProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value)
{
	PFNGLPROGRAMUNIFORM1UI64VNVPROC internal_f = (PFNGLPROGRAMUNIFORM1UI64VNVPROC)gapil_gl_func_table[1142];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value)
{
	PFNGLPROGRAMUNIFORM2UI64VNVPROC internal_f = (PFNGLPROGRAMUNIFORM2UI64VNVPROC)gapil_gl_func_table[1143];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value)
{
	PFNGLPROGRAMUNIFORM3UI64VNVPROC internal_f = (PFNGLPROGRAMUNIFORM3UI64VNVPROC)gapil_gl_func_table[1144];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value)
{
	PFNGLPROGRAMUNIFORM4UI64VNVPROC internal_f = (PFNGLPROGRAMUNIFORM4UI64VNVPROC)gapil_gl_func_table[1145];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glGetInternalformatSampleivNV(GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei count, GLint * params)
{
	PFNGLGETINTERNALFORMATSAMPLEIVNVPROC internal_f = (PFNGLGETINTERNALFORMATSAMPLEIVNVPROC)gapil_gl_func_table[1146];
	assert(internal_f != NULL);
	return internal_f(target, internalformat, samples, pname, count, params);
}

GLAPI void APIENTRY glGetMemoryObjectDetachedResourcesuivNV(GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint * params)
{
	PFNGLGETMEMORYOBJECTDETACHEDRESOURCESUIVNVPROC internal_f = (PFNGLGETMEMORYOBJECTDETACHEDRESOURCESUIVNVPROC)gapil_gl_func_table[1147];
	assert(internal_f != NULL);
	return internal_f(memory, pname, first, count, params);
}

GLAPI void APIENTRY glResetMemoryObjectParameterNV(GLuint memory, GLenum pname)
{
	PFNGLRESETMEMORYOBJECTPARAMETERNVPROC internal_f = (PFNGLRESETMEMORYOBJECTPARAMETERNVPROC)gapil_gl_func_table[1148];
	assert(internal_f != NULL);
	return internal_f(memory, pname);
}

GLAPI void APIENTRY glTexAttachMemoryNV(GLenum target, GLuint memory, GLuint64 offset)
{
	PFNGLTEXATTACHMEMORYNVPROC internal_f = (PFNGLTEXATTACHMEMORYNVPROC)gapil_gl_func_table[1149];
	assert(internal_f != NULL);
	return internal_f(target, memory, offset);
}

GLAPI void APIENTRY glBufferAttachMemoryNV(GLenum target, GLuint memory, GLuint64 offset)
{
	PFNGLBUFFERATTACHMEMORYNVPROC internal_f = (PFNGLBUFFERATTACHMEMORYNVPROC)gapil_gl_func_table[1150];
	assert(internal_f != NULL);
	return internal_f(target, memory, offset);
}

GLAPI void APIENTRY glTextureAttachMemoryNV(GLuint texture, GLuint memory, GLuint64 offset)
{
	PFNGLTEXTUREATTACHMEMORYNVPROC internal_f = (PFNGLTEXTUREATTACHMEMORYNVPROC)gapil_gl_func_table[1151];
	assert(internal_f != NULL);
	return internal_f(texture, memory, offset);
}

GLAPI void APIENTRY glNamedBufferAttachMemoryNV(GLuint buffer, GLuint memory, GLuint64 offset)
{
	PFNGLNAMEDBUFFERATTACHMEMORYNVPROC internal_f = (PFNGLNAMEDBUFFERATTACHMEMORYNVPROC)gapil_gl_func_table[1152];
	assert(internal_f != NULL);
	return internal_f(buffer, memory, offset);
}

GLAPI void APIENTRY glBufferPageCommitmentMemNV(GLenum target, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit)
{
	PFNGLBUFFERPAGECOMMITMENTMEMNVPROC internal_f = (PFNGLBUFFERPAGECOMMITMENTMEMNVPROC)gapil_gl_func_table[1153];
	assert(internal_f != NULL);
	return internal_f(target, offset, size, memory, memOffset, commit);
}

GLAPI void APIENTRY glTexPageCommitmentMemNV(GLenum target, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit)
{
	PFNGLTEXPAGECOMMITMENTMEMNVPROC internal_f = (PFNGLTEXPAGECOMMITMENTMEMNVPROC)gapil_gl_func_table[1154];
	assert(internal_f != NULL);
	return internal_f(target, layer, level, xoffset, yoffset, zoffset, width, height, depth, memory, offset, commit);
}

GLAPI void APIENTRY glNamedBufferPageCommitmentMemNV(GLuint buffer, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit)
{
	PFNGLNAMEDBUFFERPAGECOMMITMENTMEMNVPROC internal_f = (PFNGLNAMEDBUFFERPAGECOMMITMENTMEMNVPROC)gapil_gl_func_table[1155];
	assert(internal_f != NULL);
	return internal_f(buffer, offset, size, memory, memOffset, commit);
}

GLAPI void APIENTRY glTexturePageCommitmentMemNV(GLuint texture, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit)
{
	PFNGLTEXTUREPAGECOMMITMENTMEMNVPROC internal_f = (PFNGLTEXTUREPAGECOMMITMENTMEMNVPROC)gapil_gl_func_table[1156];
	assert(internal_f != NULL);
	return internal_f(texture, layer, level, xoffset, yoffset, zoffset, width, height, depth, memory, offset, commit);
}

GLAPI void APIENTRY glDrawMeshTasksNV(GLuint first, GLuint count)
{
	PFNGLDRAWMESHTASKSNVPROC internal_f = (PFNGLDRAWMESHTASKSNVPROC)gapil_gl_func_table[1157];
	assert(internal_f != NULL);
	return internal_f(first, count);
}

GLAPI void APIENTRY glDrawMeshTasksIndirectNV(GLintptr indirect)
{
	PFNGLDRAWMESHTASKSINDIRECTNVPROC internal_f = (PFNGLDRAWMESHTASKSINDIRECTNVPROC)gapil_gl_func_table[1158];
	assert(internal_f != NULL);
	return internal_f(indirect);
}

GLAPI void APIENTRY glMultiDrawMeshTasksIndirectNV(GLintptr indirect, GLsizei drawcount, GLsizei stride)
{
	PFNGLMULTIDRAWMESHTASKSINDIRECTNVPROC internal_f = (PFNGLMULTIDRAWMESHTASKSINDIRECTNVPROC)gapil_gl_func_table[1159];
	assert(internal_f != NULL);
	return internal_f(indirect, drawcount, stride);
}

GLAPI void APIENTRY glMultiDrawMeshTasksIndirectCountNV(GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
{
	PFNGLMULTIDRAWMESHTASKSINDIRECTCOUNTNVPROC internal_f = (PFNGLMULTIDRAWMESHTASKSINDIRECTCOUNTNVPROC)gapil_gl_func_table[1160];
	assert(internal_f != NULL);
	return internal_f(indirect, drawcount, maxdrawcount, stride);
}

GLAPI GLuint APIENTRY glGenPathsNV(GLsizei range)
{
	PFNGLGENPATHSNVPROC internal_f = (PFNGLGENPATHSNVPROC)gapil_gl_func_table[1161];
	assert(internal_f != NULL);
	return internal_f(range);
}

GLAPI void APIENTRY glDeletePathsNV(GLuint path, GLsizei range)
{
	PFNGLDELETEPATHSNVPROC internal_f = (PFNGLDELETEPATHSNVPROC)gapil_gl_func_table[1162];
	assert(internal_f != NULL);
	return internal_f(path, range);
}

GLAPI GLboolean APIENTRY glIsPathNV(GLuint path)
{
	PFNGLISPATHNVPROC internal_f = (PFNGLISPATHNVPROC)gapil_gl_func_table[1163];
	assert(internal_f != NULL);
	return internal_f(path);
}

GLAPI void APIENTRY glPathCommandsNV(GLuint path, GLsizei numCommands, const GLubyte * commands, GLsizei numCoords, GLenum coordType, const void * coords)
{
	PFNGLPATHCOMMANDSNVPROC internal_f = (PFNGLPATHCOMMANDSNVPROC)gapil_gl_func_table[1164];
	assert(internal_f != NULL);
	return internal_f(path, numCommands, commands, numCoords, coordType, coords);
}

GLAPI void APIENTRY glPathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, const void * coords)
{
	PFNGLPATHCOORDSNVPROC internal_f = (PFNGLPATHCOORDSNVPROC)gapil_gl_func_table[1165];
	assert(internal_f != NULL);
	return internal_f(path, numCoords, coordType, coords);
}

GLAPI void APIENTRY glPathSubCommandsNV(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte * commands, GLsizei numCoords, GLenum coordType, const void * coords)
{
	PFNGLPATHSUBCOMMANDSNVPROC internal_f = (PFNGLPATHSUBCOMMANDSNVPROC)gapil_gl_func_table[1166];
	assert(internal_f != NULL);
	return internal_f(path, commandStart, commandsToDelete, numCommands, commands, numCoords, coordType, coords);
}

GLAPI void APIENTRY glPathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void * coords)
{
	PFNGLPATHSUBCOORDSNVPROC internal_f = (PFNGLPATHSUBCOORDSNVPROC)gapil_gl_func_table[1167];
	assert(internal_f != NULL);
	return internal_f(path, coordStart, numCoords, coordType, coords);
}

GLAPI void APIENTRY glPathStringNV(GLuint path, GLenum format, GLsizei length, const void * pathString)
{
	PFNGLPATHSTRINGNVPROC internal_f = (PFNGLPATHSTRINGNVPROC)gapil_gl_func_table[1168];
	assert(internal_f != NULL);
	return internal_f(path, format, length, pathString);
}

GLAPI void APIENTRY glPathGlyphsNV(GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void * charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale)
{
	PFNGLPATHGLYPHSNVPROC internal_f = (PFNGLPATHGLYPHSNVPROC)gapil_gl_func_table[1169];
	assert(internal_f != NULL);
	return internal_f(firstPathName, fontTarget, fontName, fontStyle, numGlyphs, type, charcodes, handleMissingGlyphs, pathParameterTemplate, emScale);
}

GLAPI void APIENTRY glPathGlyphRangeNV(GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale)
{
	PFNGLPATHGLYPHRANGENVPROC internal_f = (PFNGLPATHGLYPHRANGENVPROC)gapil_gl_func_table[1170];
	assert(internal_f != NULL);
	return internal_f(firstPathName, fontTarget, fontName, fontStyle, firstGlyph, numGlyphs, handleMissingGlyphs, pathParameterTemplate, emScale);
}

GLAPI void APIENTRY glWeightPathsNV(GLuint resultPath, GLsizei numPaths, const GLuint * paths, const GLfloat * weights)
{
	PFNGLWEIGHTPATHSNVPROC internal_f = (PFNGLWEIGHTPATHSNVPROC)gapil_gl_func_table[1171];
	assert(internal_f != NULL);
	return internal_f(resultPath, numPaths, paths, weights);
}

GLAPI void APIENTRY glCopyPathNV(GLuint resultPath, GLuint srcPath)
{
	PFNGLCOPYPATHNVPROC internal_f = (PFNGLCOPYPATHNVPROC)gapil_gl_func_table[1172];
	assert(internal_f != NULL);
	return internal_f(resultPath, srcPath);
}

GLAPI void APIENTRY glInterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight)
{
	PFNGLINTERPOLATEPATHSNVPROC internal_f = (PFNGLINTERPOLATEPATHSNVPROC)gapil_gl_func_table[1173];
	assert(internal_f != NULL);
	return internal_f(resultPath, pathA, pathB, weight);
}

GLAPI void APIENTRY glTransformPathNV(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat * transformValues)
{
	PFNGLTRANSFORMPATHNVPROC internal_f = (PFNGLTRANSFORMPATHNVPROC)gapil_gl_func_table[1174];
	assert(internal_f != NULL);
	return internal_f(resultPath, srcPath, transformType, transformValues);
}

GLAPI void APIENTRY glPathParameterivNV(GLuint path, GLenum pname, const GLint * value)
{
	PFNGLPATHPARAMETERIVNVPROC internal_f = (PFNGLPATHPARAMETERIVNVPROC)gapil_gl_func_table[1175];
	assert(internal_f != NULL);
	return internal_f(path, pname, value);
}

GLAPI void APIENTRY glPathParameteriNV(GLuint path, GLenum pname, GLint value)
{
	PFNGLPATHPARAMETERINVPROC internal_f = (PFNGLPATHPARAMETERINVPROC)gapil_gl_func_table[1176];
	assert(internal_f != NULL);
	return internal_f(path, pname, value);
}

GLAPI void APIENTRY glPathParameterfvNV(GLuint path, GLenum pname, const GLfloat * value)
{
	PFNGLPATHPARAMETERFVNVPROC internal_f = (PFNGLPATHPARAMETERFVNVPROC)gapil_gl_func_table[1177];
	assert(internal_f != NULL);
	return internal_f(path, pname, value);
}

GLAPI void APIENTRY glPathParameterfNV(GLuint path, GLenum pname, GLfloat value)
{
	PFNGLPATHPARAMETERFNVPROC internal_f = (PFNGLPATHPARAMETERFNVPROC)gapil_gl_func_table[1178];
	assert(internal_f != NULL);
	return internal_f(path, pname, value);
}

GLAPI void APIENTRY glPathDashArrayNV(GLuint path, GLsizei dashCount, const GLfloat * dashArray)
{
	PFNGLPATHDASHARRAYNVPROC internal_f = (PFNGLPATHDASHARRAYNVPROC)gapil_gl_func_table[1179];
	assert(internal_f != NULL);
	return internal_f(path, dashCount, dashArray);
}

GLAPI void APIENTRY glPathStencilFuncNV(GLenum func, GLint ref, GLuint mask)
{
	PFNGLPATHSTENCILFUNCNVPROC internal_f = (PFNGLPATHSTENCILFUNCNVPROC)gapil_gl_func_table[1180];
	assert(internal_f != NULL);
	return internal_f(func, ref, mask);
}

GLAPI void APIENTRY glPathStencilDepthOffsetNV(GLfloat factor, GLfloat units)
{
	PFNGLPATHSTENCILDEPTHOFFSETNVPROC internal_f = (PFNGLPATHSTENCILDEPTHOFFSETNVPROC)gapil_gl_func_table[1181];
	assert(internal_f != NULL);
	return internal_f(factor, units);
}

GLAPI void APIENTRY glStencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask)
{
	PFNGLSTENCILFILLPATHNVPROC internal_f = (PFNGLSTENCILFILLPATHNVPROC)gapil_gl_func_table[1182];
	assert(internal_f != NULL);
	return internal_f(path, fillMode, mask);
}

GLAPI void APIENTRY glStencilStrokePathNV(GLuint path, GLint reference, GLuint mask)
{
	PFNGLSTENCILSTROKEPATHNVPROC internal_f = (PFNGLSTENCILSTROKEPATHNVPROC)gapil_gl_func_table[1183];
	assert(internal_f != NULL);
	return internal_f(path, reference, mask);
}

GLAPI void APIENTRY glStencilFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat * transformValues)
{
	PFNGLSTENCILFILLPATHINSTANCEDNVPROC internal_f = (PFNGLSTENCILFILLPATHINSTANCEDNVPROC)gapil_gl_func_table[1184];
	assert(internal_f != NULL);
	return internal_f(numPaths, pathNameType, paths, pathBase, fillMode, mask, transformType, transformValues);
}

GLAPI void APIENTRY glStencilStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat * transformValues)
{
	PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC internal_f = (PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC)gapil_gl_func_table[1185];
	assert(internal_f != NULL);
	return internal_f(numPaths, pathNameType, paths, pathBase, reference, mask, transformType, transformValues);
}

GLAPI void APIENTRY glPathCoverDepthFuncNV(GLenum func)
{
	PFNGLPATHCOVERDEPTHFUNCNVPROC internal_f = (PFNGLPATHCOVERDEPTHFUNCNVPROC)gapil_gl_func_table[1186];
	assert(internal_f != NULL);
	return internal_f(func);
}

GLAPI void APIENTRY glCoverFillPathNV(GLuint path, GLenum coverMode)
{
	PFNGLCOVERFILLPATHNVPROC internal_f = (PFNGLCOVERFILLPATHNVPROC)gapil_gl_func_table[1187];
	assert(internal_f != NULL);
	return internal_f(path, coverMode);
}

GLAPI void APIENTRY glCoverStrokePathNV(GLuint path, GLenum coverMode)
{
	PFNGLCOVERSTROKEPATHNVPROC internal_f = (PFNGLCOVERSTROKEPATHNVPROC)gapil_gl_func_table[1188];
	assert(internal_f != NULL);
	return internal_f(path, coverMode);
}

GLAPI void APIENTRY glCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat * transformValues)
{
	PFNGLCOVERFILLPATHINSTANCEDNVPROC internal_f = (PFNGLCOVERFILLPATHINSTANCEDNVPROC)gapil_gl_func_table[1189];
	assert(internal_f != NULL);
	return internal_f(numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues);
}

GLAPI void APIENTRY glCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat * transformValues)
{
	PFNGLCOVERSTROKEPATHINSTANCEDNVPROC internal_f = (PFNGLCOVERSTROKEPATHINSTANCEDNVPROC)gapil_gl_func_table[1190];
	assert(internal_f != NULL);
	return internal_f(numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues);
}

GLAPI void APIENTRY glGetPathParameterivNV(GLuint path, GLenum pname, GLint * value)
{
	PFNGLGETPATHPARAMETERIVNVPROC internal_f = (PFNGLGETPATHPARAMETERIVNVPROC)gapil_gl_func_table[1191];
	assert(internal_f != NULL);
	return internal_f(path, pname, value);
}

GLAPI void APIENTRY glGetPathParameterfvNV(GLuint path, GLenum pname, GLfloat * value)
{
	PFNGLGETPATHPARAMETERFVNVPROC internal_f = (PFNGLGETPATHPARAMETERFVNVPROC)gapil_gl_func_table[1192];
	assert(internal_f != NULL);
	return internal_f(path, pname, value);
}

GLAPI void APIENTRY glGetPathCommandsNV(GLuint path, GLubyte * commands)
{
	PFNGLGETPATHCOMMANDSNVPROC internal_f = (PFNGLGETPATHCOMMANDSNVPROC)gapil_gl_func_table[1193];
	assert(internal_f != NULL);
	return internal_f(path, commands);
}

GLAPI void APIENTRY glGetPathCoordsNV(GLuint path, GLfloat * coords)
{
	PFNGLGETPATHCOORDSNVPROC internal_f = (PFNGLGETPATHCOORDSNVPROC)gapil_gl_func_table[1194];
	assert(internal_f != NULL);
	return internal_f(path, coords);
}

GLAPI void APIENTRY glGetPathDashArrayNV(GLuint path, GLfloat * dashArray)
{
	PFNGLGETPATHDASHARRAYNVPROC internal_f = (PFNGLGETPATHDASHARRAYNVPROC)gapil_gl_func_table[1195];
	assert(internal_f != NULL);
	return internal_f(path, dashArray);
}

GLAPI void APIENTRY glGetPathMetricsNV(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLsizei stride, GLfloat * metrics)
{
	PFNGLGETPATHMETRICSNVPROC internal_f = (PFNGLGETPATHMETRICSNVPROC)gapil_gl_func_table[1196];
	assert(internal_f != NULL);
	return internal_f(metricQueryMask, numPaths, pathNameType, paths, pathBase, stride, metrics);
}

GLAPI void APIENTRY glGetPathMetricRangeNV(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat * metrics)
{
	PFNGLGETPATHMETRICRANGENVPROC internal_f = (PFNGLGETPATHMETRICRANGENVPROC)gapil_gl_func_table[1197];
	assert(internal_f != NULL);
	return internal_f(metricQueryMask, firstPathName, numPaths, stride, metrics);
}

GLAPI void APIENTRY glGetPathSpacingNV(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat * returnedSpacing)
{
	PFNGLGETPATHSPACINGNVPROC internal_f = (PFNGLGETPATHSPACINGNVPROC)gapil_gl_func_table[1198];
	assert(internal_f != NULL);
	return internal_f(pathListMode, numPaths, pathNameType, paths, pathBase, advanceScale, kerningScale, transformType, returnedSpacing);
}

GLAPI GLboolean APIENTRY glIsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y)
{
	PFNGLISPOINTINFILLPATHNVPROC internal_f = (PFNGLISPOINTINFILLPATHNVPROC)gapil_gl_func_table[1199];
	assert(internal_f != NULL);
	return internal_f(path, mask, x, y);
}

GLAPI GLboolean APIENTRY glIsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y)
{
	PFNGLISPOINTINSTROKEPATHNVPROC internal_f = (PFNGLISPOINTINSTROKEPATHNVPROC)gapil_gl_func_table[1200];
	assert(internal_f != NULL);
	return internal_f(path, x, y);
}

GLAPI GLfloat APIENTRY glGetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments)
{
	PFNGLGETPATHLENGTHNVPROC internal_f = (PFNGLGETPATHLENGTHNVPROC)gapil_gl_func_table[1201];
	assert(internal_f != NULL);
	return internal_f(path, startSegment, numSegments);
}

GLAPI GLboolean APIENTRY glPointAlongPathNV(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat * x, GLfloat * y, GLfloat * tangentX, GLfloat * tangentY)
{
	PFNGLPOINTALONGPATHNVPROC internal_f = (PFNGLPOINTALONGPATHNVPROC)gapil_gl_func_table[1202];
	assert(internal_f != NULL);
	return internal_f(path, startSegment, numSegments, distance, x, y, tangentX, tangentY);
}

GLAPI void APIENTRY glMatrixLoad3x2fNV(GLenum matrixMode, const GLfloat * m)
{
	PFNGLMATRIXLOAD3X2FNVPROC internal_f = (PFNGLMATRIXLOAD3X2FNVPROC)gapil_gl_func_table[1203];
	assert(internal_f != NULL);
	return internal_f(matrixMode, m);
}

GLAPI void APIENTRY glMatrixLoad3x3fNV(GLenum matrixMode, const GLfloat * m)
{
	PFNGLMATRIXLOAD3X3FNVPROC internal_f = (PFNGLMATRIXLOAD3X3FNVPROC)gapil_gl_func_table[1204];
	assert(internal_f != NULL);
	return internal_f(matrixMode, m);
}

GLAPI void APIENTRY glMatrixLoadTranspose3x3fNV(GLenum matrixMode, const GLfloat * m)
{
	PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC internal_f = (PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC)gapil_gl_func_table[1205];
	assert(internal_f != NULL);
	return internal_f(matrixMode, m);
}

GLAPI void APIENTRY glMatrixMult3x2fNV(GLenum matrixMode, const GLfloat * m)
{
	PFNGLMATRIXMULT3X2FNVPROC internal_f = (PFNGLMATRIXMULT3X2FNVPROC)gapil_gl_func_table[1206];
	assert(internal_f != NULL);
	return internal_f(matrixMode, m);
}

GLAPI void APIENTRY glMatrixMult3x3fNV(GLenum matrixMode, const GLfloat * m)
{
	PFNGLMATRIXMULT3X3FNVPROC internal_f = (PFNGLMATRIXMULT3X3FNVPROC)gapil_gl_func_table[1207];
	assert(internal_f != NULL);
	return internal_f(matrixMode, m);
}

GLAPI void APIENTRY glMatrixMultTranspose3x3fNV(GLenum matrixMode, const GLfloat * m)
{
	PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC internal_f = (PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC)gapil_gl_func_table[1208];
	assert(internal_f != NULL);
	return internal_f(matrixMode, m);
}

GLAPI void APIENTRY glStencilThenCoverFillPathNV(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode)
{
	PFNGLSTENCILTHENCOVERFILLPATHNVPROC internal_f = (PFNGLSTENCILTHENCOVERFILLPATHNVPROC)gapil_gl_func_table[1209];
	assert(internal_f != NULL);
	return internal_f(path, fillMode, mask, coverMode);
}

GLAPI void APIENTRY glStencilThenCoverStrokePathNV(GLuint path, GLint reference, GLuint mask, GLenum coverMode)
{
	PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC internal_f = (PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC)gapil_gl_func_table[1210];
	assert(internal_f != NULL);
	return internal_f(path, reference, mask, coverMode);
}

GLAPI void APIENTRY glStencilThenCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat * transformValues)
{
	PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC internal_f = (PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC)gapil_gl_func_table[1211];
	assert(internal_f != NULL);
	return internal_f(numPaths, pathNameType, paths, pathBase, fillMode, mask, coverMode, transformType, transformValues);
}

GLAPI void APIENTRY glStencilThenCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat * transformValues)
{
	PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC internal_f = (PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC)gapil_gl_func_table[1212];
	assert(internal_f != NULL);
	return internal_f(numPaths, pathNameType, paths, pathBase, reference, mask, coverMode, transformType, transformValues);
}

GLAPI GLenum APIENTRY glPathGlyphIndexRangeNV(GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint * baseAndCount)
{
	PFNGLPATHGLYPHINDEXRANGENVPROC internal_f = (PFNGLPATHGLYPHINDEXRANGENVPROC)gapil_gl_func_table[1213];
	assert(internal_f != NULL);
	return internal_f(fontTarget, fontName, fontStyle, pathParameterTemplate, emScale, baseAndCount);
}

GLAPI GLenum APIENTRY glPathGlyphIndexArrayNV(GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale)
{
	PFNGLPATHGLYPHINDEXARRAYNVPROC internal_f = (PFNGLPATHGLYPHINDEXARRAYNVPROC)gapil_gl_func_table[1214];
	assert(internal_f != NULL);
	return internal_f(firstPathName, fontTarget, fontName, fontStyle, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale);
}

GLAPI GLenum APIENTRY glPathMemoryGlyphIndexArrayNV(GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void * fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale)
{
	PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC internal_f = (PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC)gapil_gl_func_table[1215];
	assert(internal_f != NULL);
	return internal_f(firstPathName, fontTarget, fontSize, fontData, faceIndex, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale);
}

GLAPI void APIENTRY glProgramPathFragmentInputGenNV(GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat * coeffs)
{
	PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC internal_f = (PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC)gapil_gl_func_table[1216];
	assert(internal_f != NULL);
	return internal_f(program, location, genMode, components, coeffs);
}

GLAPI void APIENTRY glGetProgramResourcefvNV(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLfloat * params)
{
	PFNGLGETPROGRAMRESOURCEFVNVPROC internal_f = (PFNGLGETPROGRAMRESOURCEFVNVPROC)gapil_gl_func_table[1217];
	assert(internal_f != NULL);
	return internal_f(program, programInterface, index, propCount, props, count, length, params);
}

GLAPI void APIENTRY glFramebufferSampleLocationsfvNV(GLenum target, GLuint start, GLsizei count, const GLfloat * v)
{
	PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC internal_f = (PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)gapil_gl_func_table[1218];
	assert(internal_f != NULL);
	return internal_f(target, start, count, v);
}

GLAPI void APIENTRY glNamedFramebufferSampleLocationsfvNV(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat * v)
{
	PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC internal_f = (PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)gapil_gl_func_table[1219];
	assert(internal_f != NULL);
	return internal_f(framebuffer, start, count, v);
}

GLAPI void APIENTRY glResolveDepthValuesNV()
{
	PFNGLRESOLVEDEPTHVALUESNVPROC internal_f = (PFNGLRESOLVEDEPTHVALUESNVPROC)gapil_gl_func_table[1220];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glScissorExclusiveNV(GLint x, GLint y, GLsizei width, GLsizei height)
{
	PFNGLSCISSOREXCLUSIVENVPROC internal_f = (PFNGLSCISSOREXCLUSIVENVPROC)gapil_gl_func_table[1221];
	assert(internal_f != NULL);
	return internal_f(x, y, width, height);
}

GLAPI void APIENTRY glScissorExclusiveArrayvNV(GLuint first, GLsizei count, const GLint * v)
{
	PFNGLSCISSOREXCLUSIVEARRAYVNVPROC internal_f = (PFNGLSCISSOREXCLUSIVEARRAYVNVPROC)gapil_gl_func_table[1222];
	assert(internal_f != NULL);
	return internal_f(first, count, v);
}

GLAPI void APIENTRY glMakeBufferResidentNV(GLenum target, GLenum access)
{
	PFNGLMAKEBUFFERRESIDENTNVPROC internal_f = (PFNGLMAKEBUFFERRESIDENTNVPROC)gapil_gl_func_table[1223];
	assert(internal_f != NULL);
	return internal_f(target, access);
}

GLAPI void APIENTRY glMakeBufferNonResidentNV(GLenum target)
{
	PFNGLMAKEBUFFERNONRESIDENTNVPROC internal_f = (PFNGLMAKEBUFFERNONRESIDENTNVPROC)gapil_gl_func_table[1224];
	assert(internal_f != NULL);
	return internal_f(target);
}

GLAPI GLboolean APIENTRY glIsBufferResidentNV(GLenum target)
{
	PFNGLISBUFFERRESIDENTNVPROC internal_f = (PFNGLISBUFFERRESIDENTNVPROC)gapil_gl_func_table[1225];
	assert(internal_f != NULL);
	return internal_f(target);
}

GLAPI void APIENTRY glMakeNamedBufferResidentNV(GLuint buffer, GLenum access)
{
	PFNGLMAKENAMEDBUFFERRESIDENTNVPROC internal_f = (PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)gapil_gl_func_table[1226];
	assert(internal_f != NULL);
	return internal_f(buffer, access);
}

GLAPI void APIENTRY glMakeNamedBufferNonResidentNV(GLuint buffer)
{
	PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC internal_f = (PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)gapil_gl_func_table[1227];
	assert(internal_f != NULL);
	return internal_f(buffer);
}

GLAPI GLboolean APIENTRY glIsNamedBufferResidentNV(GLuint buffer)
{
	PFNGLISNAMEDBUFFERRESIDENTNVPROC internal_f = (PFNGLISNAMEDBUFFERRESIDENTNVPROC)gapil_gl_func_table[1228];
	assert(internal_f != NULL);
	return internal_f(buffer);
}

GLAPI void APIENTRY glGetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT * params)
{
	PFNGLGETBUFFERPARAMETERUI64VNVPROC internal_f = (PFNGLGETBUFFERPARAMETERUI64VNVPROC)gapil_gl_func_table[1229];
	assert(internal_f != NULL);
	return internal_f(target, pname, params);
}

GLAPI void APIENTRY glGetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT * params)
{
	PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC internal_f = (PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)gapil_gl_func_table[1230];
	assert(internal_f != NULL);
	return internal_f(buffer, pname, params);
}

GLAPI void APIENTRY glGetIntegerui64vNV(GLenum value, GLuint64EXT * result)
{
	PFNGLGETINTEGERUI64VNVPROC internal_f = (PFNGLGETINTEGERUI64VNVPROC)gapil_gl_func_table[1231];
	assert(internal_f != NULL);
	return internal_f(value, result);
}

GLAPI void APIENTRY glUniformui64NV(GLint location, GLuint64EXT value)
{
	PFNGLUNIFORMUI64NVPROC internal_f = (PFNGLUNIFORMUI64NVPROC)gapil_gl_func_table[1232];
	assert(internal_f != NULL);
	return internal_f(location, value);
}

GLAPI void APIENTRY glUniformui64vNV(GLint location, GLsizei count, const GLuint64EXT * value)
{
	PFNGLUNIFORMUI64VNVPROC internal_f = (PFNGLUNIFORMUI64VNVPROC)gapil_gl_func_table[1233];
	assert(internal_f != NULL);
	return internal_f(location, count, value);
}

GLAPI void APIENTRY glGetUniformui64vNV(GLuint program, GLint location, GLuint64EXT * params)
{
	PFNGLGETUNIFORMUI64VNVPROC internal_f = (PFNGLGETUNIFORMUI64VNVPROC)gapil_gl_func_table[1234];
	assert(internal_f != NULL);
	return internal_f(program, location, params);
}

GLAPI void APIENTRY glProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT value)
{
	PFNGLPROGRAMUNIFORMUI64NVPROC internal_f = (PFNGLPROGRAMUNIFORMUI64NVPROC)gapil_gl_func_table[1235];
	assert(internal_f != NULL);
	return internal_f(program, location, value);
}

GLAPI void APIENTRY glProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value)
{
	PFNGLPROGRAMUNIFORMUI64VNVPROC internal_f = (PFNGLPROGRAMUNIFORMUI64VNVPROC)gapil_gl_func_table[1236];
	assert(internal_f != NULL);
	return internal_f(program, location, count, value);
}

GLAPI void APIENTRY glBindShadingRateImageNV(GLuint texture)
{
	PFNGLBINDSHADINGRATEIMAGENVPROC internal_f = (PFNGLBINDSHADINGRATEIMAGENVPROC)gapil_gl_func_table[1237];
	assert(internal_f != NULL);
	return internal_f(texture);
}

GLAPI void APIENTRY glGetShadingRateImagePaletteNV(GLuint viewport, GLuint entry, GLenum * rate)
{
	PFNGLGETSHADINGRATEIMAGEPALETTENVPROC internal_f = (PFNGLGETSHADINGRATEIMAGEPALETTENVPROC)gapil_gl_func_table[1238];
	assert(internal_f != NULL);
	return internal_f(viewport, entry, rate);
}

GLAPI void APIENTRY glGetShadingRateSampleLocationivNV(GLenum rate, GLuint samples, GLuint index, GLint * location)
{
	PFNGLGETSHADINGRATESAMPLELOCATIONIVNVPROC internal_f = (PFNGLGETSHADINGRATESAMPLELOCATIONIVNVPROC)gapil_gl_func_table[1239];
	assert(internal_f != NULL);
	return internal_f(rate, samples, index, location);
}

GLAPI void APIENTRY glShadingRateImageBarrierNV(GLboolean synchronize)
{
	PFNGLSHADINGRATEIMAGEBARRIERNVPROC internal_f = (PFNGLSHADINGRATEIMAGEBARRIERNVPROC)gapil_gl_func_table[1240];
	assert(internal_f != NULL);
	return internal_f(synchronize);
}

GLAPI void APIENTRY glShadingRateImagePaletteNV(GLuint viewport, GLuint first, GLsizei count, const GLenum * rates)
{
	PFNGLSHADINGRATEIMAGEPALETTENVPROC internal_f = (PFNGLSHADINGRATEIMAGEPALETTENVPROC)gapil_gl_func_table[1241];
	assert(internal_f != NULL);
	return internal_f(viewport, first, count, rates);
}

GLAPI void APIENTRY glShadingRateSampleOrderNV(GLenum order)
{
	PFNGLSHADINGRATESAMPLEORDERNVPROC internal_f = (PFNGLSHADINGRATESAMPLEORDERNVPROC)gapil_gl_func_table[1242];
	assert(internal_f != NULL);
	return internal_f(order);
}

GLAPI void APIENTRY glShadingRateSampleOrderCustomNV(GLenum rate, GLuint samples, const GLint * locations)
{
	PFNGLSHADINGRATESAMPLEORDERCUSTOMNVPROC internal_f = (PFNGLSHADINGRATESAMPLEORDERCUSTOMNVPROC)gapil_gl_func_table[1243];
	assert(internal_f != NULL);
	return internal_f(rate, samples, locations);
}

GLAPI void APIENTRY glTextureBarrierNV()
{
	PFNGLTEXTUREBARRIERNVPROC internal_f = (PFNGLTEXTUREBARRIERNVPROC)gapil_gl_func_table[1244];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY glVertexAttribL1i64NV(GLuint index, GLint64EXT x)
{
	PFNGLVERTEXATTRIBL1I64NVPROC internal_f = (PFNGLVERTEXATTRIBL1I64NVPROC)gapil_gl_func_table[1245];
	assert(internal_f != NULL);
	return internal_f(index, x);
}

GLAPI void APIENTRY glVertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y)
{
	PFNGLVERTEXATTRIBL2I64NVPROC internal_f = (PFNGLVERTEXATTRIBL2I64NVPROC)gapil_gl_func_table[1246];
	assert(internal_f != NULL);
	return internal_f(index, x, y);
}

GLAPI void APIENTRY glVertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z)
{
	PFNGLVERTEXATTRIBL3I64NVPROC internal_f = (PFNGLVERTEXATTRIBL3I64NVPROC)gapil_gl_func_table[1247];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z);
}

GLAPI void APIENTRY glVertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)
{
	PFNGLVERTEXATTRIBL4I64NVPROC internal_f = (PFNGLVERTEXATTRIBL4I64NVPROC)gapil_gl_func_table[1248];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z, w);
}

GLAPI void APIENTRY glVertexAttribL1i64vNV(GLuint index, const GLint64EXT * v)
{
	PFNGLVERTEXATTRIBL1I64VNVPROC internal_f = (PFNGLVERTEXATTRIBL1I64VNVPROC)gapil_gl_func_table[1249];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribL2i64vNV(GLuint index, const GLint64EXT * v)
{
	PFNGLVERTEXATTRIBL2I64VNVPROC internal_f = (PFNGLVERTEXATTRIBL2I64VNVPROC)gapil_gl_func_table[1250];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribL3i64vNV(GLuint index, const GLint64EXT * v)
{
	PFNGLVERTEXATTRIBL3I64VNVPROC internal_f = (PFNGLVERTEXATTRIBL3I64VNVPROC)gapil_gl_func_table[1251];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribL4i64vNV(GLuint index, const GLint64EXT * v)
{
	PFNGLVERTEXATTRIBL4I64VNVPROC internal_f = (PFNGLVERTEXATTRIBL4I64VNVPROC)gapil_gl_func_table[1252];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribL1ui64NV(GLuint index, GLuint64EXT x)
{
	PFNGLVERTEXATTRIBL1UI64NVPROC internal_f = (PFNGLVERTEXATTRIBL1UI64NVPROC)gapil_gl_func_table[1253];
	assert(internal_f != NULL);
	return internal_f(index, x);
}

GLAPI void APIENTRY glVertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y)
{
	PFNGLVERTEXATTRIBL2UI64NVPROC internal_f = (PFNGLVERTEXATTRIBL2UI64NVPROC)gapil_gl_func_table[1254];
	assert(internal_f != NULL);
	return internal_f(index, x, y);
}

GLAPI void APIENTRY glVertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)
{
	PFNGLVERTEXATTRIBL3UI64NVPROC internal_f = (PFNGLVERTEXATTRIBL3UI64NVPROC)gapil_gl_func_table[1255];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z);
}

GLAPI void APIENTRY glVertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)
{
	PFNGLVERTEXATTRIBL4UI64NVPROC internal_f = (PFNGLVERTEXATTRIBL4UI64NVPROC)gapil_gl_func_table[1256];
	assert(internal_f != NULL);
	return internal_f(index, x, y, z, w);
}

GLAPI void APIENTRY glVertexAttribL1ui64vNV(GLuint index, const GLuint64EXT * v)
{
	PFNGLVERTEXATTRIBL1UI64VNVPROC internal_f = (PFNGLVERTEXATTRIBL1UI64VNVPROC)gapil_gl_func_table[1257];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribL2ui64vNV(GLuint index, const GLuint64EXT * v)
{
	PFNGLVERTEXATTRIBL2UI64VNVPROC internal_f = (PFNGLVERTEXATTRIBL2UI64VNVPROC)gapil_gl_func_table[1258];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribL3ui64vNV(GLuint index, const GLuint64EXT * v)
{
	PFNGLVERTEXATTRIBL3UI64VNVPROC internal_f = (PFNGLVERTEXATTRIBL3UI64VNVPROC)gapil_gl_func_table[1259];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glVertexAttribL4ui64vNV(GLuint index, const GLuint64EXT * v)
{
	PFNGLVERTEXATTRIBL4UI64VNVPROC internal_f = (PFNGLVERTEXATTRIBL4UI64VNVPROC)gapil_gl_func_table[1260];
	assert(internal_f != NULL);
	return internal_f(index, v);
}

GLAPI void APIENTRY glGetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT * params)
{
	PFNGLGETVERTEXATTRIBLI64VNVPROC internal_f = (PFNGLGETVERTEXATTRIBLI64VNVPROC)gapil_gl_func_table[1261];
	assert(internal_f != NULL);
	return internal_f(index, pname, params);
}

GLAPI void APIENTRY glGetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT * params)
{
	PFNGLGETVERTEXATTRIBLUI64VNVPROC internal_f = (PFNGLGETVERTEXATTRIBLUI64VNVPROC)gapil_gl_func_table[1262];
	assert(internal_f != NULL);
	return internal_f(index, pname, params);
}

GLAPI void APIENTRY glVertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride)
{
	PFNGLVERTEXATTRIBLFORMATNVPROC internal_f = (PFNGLVERTEXATTRIBLFORMATNVPROC)gapil_gl_func_table[1263];
	assert(internal_f != NULL);
	return internal_f(index, size, type, stride);
}

GLAPI void APIENTRY glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length)
{
	PFNGLBUFFERADDRESSRANGENVPROC internal_f = (PFNGLBUFFERADDRESSRANGENVPROC)gapil_gl_func_table[1264];
	assert(internal_f != NULL);
	return internal_f(pname, index, address, length);
}

GLAPI void APIENTRY glVertexFormatNV(GLint size, GLenum type, GLsizei stride)
{
	PFNGLVERTEXFORMATNVPROC internal_f = (PFNGLVERTEXFORMATNVPROC)gapil_gl_func_table[1265];
	assert(internal_f != NULL);
	return internal_f(size, type, stride);
}

GLAPI void APIENTRY glNormalFormatNV(GLenum type, GLsizei stride)
{
	PFNGLNORMALFORMATNVPROC internal_f = (PFNGLNORMALFORMATNVPROC)gapil_gl_func_table[1266];
	assert(internal_f != NULL);
	return internal_f(type, stride);
}

GLAPI void APIENTRY glColorFormatNV(GLint size, GLenum type, GLsizei stride)
{
	PFNGLCOLORFORMATNVPROC internal_f = (PFNGLCOLORFORMATNVPROC)gapil_gl_func_table[1267];
	assert(internal_f != NULL);
	return internal_f(size, type, stride);
}

GLAPI void APIENTRY glIndexFormatNV(GLenum type, GLsizei stride)
{
	PFNGLINDEXFORMATNVPROC internal_f = (PFNGLINDEXFORMATNVPROC)gapil_gl_func_table[1268];
	assert(internal_f != NULL);
	return internal_f(type, stride);
}

GLAPI void APIENTRY glTexCoordFormatNV(GLint size, GLenum type, GLsizei stride)
{
	PFNGLTEXCOORDFORMATNVPROC internal_f = (PFNGLTEXCOORDFORMATNVPROC)gapil_gl_func_table[1269];
	assert(internal_f != NULL);
	return internal_f(size, type, stride);
}

GLAPI void APIENTRY glEdgeFlagFormatNV(GLsizei stride)
{
	PFNGLEDGEFLAGFORMATNVPROC internal_f = (PFNGLEDGEFLAGFORMATNVPROC)gapil_gl_func_table[1270];
	assert(internal_f != NULL);
	return internal_f(stride);
}

GLAPI void APIENTRY glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride)
{
	PFNGLSECONDARYCOLORFORMATNVPROC internal_f = (PFNGLSECONDARYCOLORFORMATNVPROC)gapil_gl_func_table[1271];
	assert(internal_f != NULL);
	return internal_f(size, type, stride);
}

GLAPI void APIENTRY glFogCoordFormatNV(GLenum type, GLsizei stride)
{
	PFNGLFOGCOORDFORMATNVPROC internal_f = (PFNGLFOGCOORDFORMATNVPROC)gapil_gl_func_table[1272];
	assert(internal_f != NULL);
	return internal_f(type, stride);
}

GLAPI void APIENTRY glVertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride)
{
	PFNGLVERTEXATTRIBFORMATNVPROC internal_f = (PFNGLVERTEXATTRIBFORMATNVPROC)gapil_gl_func_table[1273];
	assert(internal_f != NULL);
	return internal_f(index, size, type, normalized, stride);
}

GLAPI void APIENTRY glVertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride)
{
	PFNGLVERTEXATTRIBIFORMATNVPROC internal_f = (PFNGLVERTEXATTRIBIFORMATNVPROC)gapil_gl_func_table[1274];
	assert(internal_f != NULL);
	return internal_f(index, size, type, stride);
}

GLAPI void APIENTRY glGetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT * result)
{
	PFNGLGETINTEGERUI64I_VNVPROC internal_f = (PFNGLGETINTEGERUI64I_VNVPROC)gapil_gl_func_table[1275];
	assert(internal_f != NULL);
	return internal_f(value, index, result);
}

GLAPI void APIENTRY glViewportSwizzleNV(GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew)
{
	PFNGLVIEWPORTSWIZZLENVPROC internal_f = (PFNGLVIEWPORTSWIZZLENVPROC)gapil_gl_func_table[1276];
	assert(internal_f != NULL);
	return internal_f(index, swizzlex, swizzley, swizzlez, swizzlew);
}

GLAPI void APIENTRY glFramebufferTextureMultiviewOVR(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews)
{
	PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC internal_f = (PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)gapil_gl_func_table[1277];
	assert(internal_f != NULL);
	return internal_f(target, attachment, texture, level, baseViewIndex, numViews);
}

GLAPI void APIENTRY glNamedFramebufferTextureMultiviewOVR(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews)
{
	PFNGLNAMEDFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC internal_f = (PFNGLNAMEDFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)gapil_gl_func_table[1278];
	assert(internal_f != NULL);
	return internal_f(framebuffer, attachment, texture, level, baseViewIndex, numViews);
}

#ifdef _WIN32
static gapil_func gapil_wgl_func_table [119] = {0};static HMODULE gapil_opengl_dll = NULL;

static gapil_func gapil_load_function(const char* name)
{
	if(gapil_opengl_dll == NULL)
		gapil_opengl_dll = LoadLibraryA("opengl32.dll");

	gapil_func f = (gapil_func)GetProcAddress(gapil_opengl_dll, name);
	if(f == NULL) f = (gapil_func)wglGetProcAddress(name);
	return f;
}

void gapil_load_extensions()
{
	gapil_wgl_func_table[0] = gapil_load_function("wglCreateBufferRegionARB");
	gapil_wgl_func_table[1] = gapil_load_function("wglDeleteBufferRegionARB");
	gapil_wgl_func_table[2] = gapil_load_function("wglSaveBufferRegionARB");
	gapil_wgl_func_table[3] = gapil_load_function("wglRestoreBufferRegionARB");
	gapil_wgl_func_table[4] = gapil_load_function("wglCreateContextAttribsARB");
	gapil_wgl_func_table[5] = gapil_load_function("wglGetExtensionsStringARB");
	gapil_wgl_func_table[6] = gapil_load_function("wglMakeContextCurrentARB");
	gapil_wgl_func_table[7] = gapil_load_function("wglGetCurrentReadDCARB");
	gapil_wgl_func_table[8] = gapil_load_function("wglCreatePbufferARB");
	gapil_wgl_func_table[9] = gapil_load_function("wglGetPbufferDCARB");
	gapil_wgl_func_table[10] = gapil_load_function("wglReleasePbufferDCARB");
	gapil_wgl_func_table[11] = gapil_load_function("wglDestroyPbufferARB");
	gapil_wgl_func_table[12] = gapil_load_function("wglQueryPbufferARB");
	gapil_wgl_func_table[13] = gapil_load_function("wglGetPixelFormatAttribivARB");
	gapil_wgl_func_table[14] = gapil_load_function("wglGetPixelFormatAttribfvARB");
	gapil_wgl_func_table[15] = gapil_load_function("wglChoosePixelFormatARB");
	gapil_wgl_func_table[16] = gapil_load_function("wglBindTexImageARB");
	gapil_wgl_func_table[17] = gapil_load_function("wglReleaseTexImageARB");
	gapil_wgl_func_table[18] = gapil_load_function("wglSetPbufferAttribARB");
	gapil_wgl_func_table[19] = gapil_load_function("wglSetStereoEmitterState3DL");
	gapil_wgl_func_table[20] = gapil_load_function("wglGetGPUIDsAMD");
	gapil_wgl_func_table[21] = gapil_load_function("wglGetGPUInfoAMD");
	gapil_wgl_func_table[22] = gapil_load_function("wglGetContextGPUIDAMD");
	gapil_wgl_func_table[23] = gapil_load_function("wglCreateAssociatedContextAMD");
	gapil_wgl_func_table[24] = gapil_load_function("wglCreateAssociatedContextAttribsAMD");
	gapil_wgl_func_table[25] = gapil_load_function("wglDeleteAssociatedContextAMD");
	gapil_wgl_func_table[26] = gapil_load_function("wglMakeAssociatedContextCurrentAMD");
	gapil_wgl_func_table[27] = gapil_load_function("wglGetCurrentAssociatedContextAMD");
	gapil_wgl_func_table[28] = gapil_load_function("wglBlitContextFramebufferAMD");
	gapil_wgl_func_table[29] = gapil_load_function("wglCreateDisplayColorTableEXT");
	gapil_wgl_func_table[30] = gapil_load_function("wglLoadDisplayColorTableEXT");
	gapil_wgl_func_table[31] = gapil_load_function("wglBindDisplayColorTableEXT");
	gapil_wgl_func_table[32] = gapil_load_function("wglDestroyDisplayColorTableEXT");
	gapil_wgl_func_table[33] = gapil_load_function("wglGetExtensionsStringEXT");
	gapil_wgl_func_table[34] = gapil_load_function("wglMakeContextCurrentEXT");
	gapil_wgl_func_table[35] = gapil_load_function("wglGetCurrentReadDCEXT");
	gapil_wgl_func_table[36] = gapil_load_function("wglCreatePbufferEXT");
	gapil_wgl_func_table[37] = gapil_load_function("wglGetPbufferDCEXT");
	gapil_wgl_func_table[38] = gapil_load_function("wglReleasePbufferDCEXT");
	gapil_wgl_func_table[39] = gapil_load_function("wglDestroyPbufferEXT");
	gapil_wgl_func_table[40] = gapil_load_function("wglQueryPbufferEXT");
	gapil_wgl_func_table[41] = gapil_load_function("wglGetPixelFormatAttribivEXT");
	gapil_wgl_func_table[42] = gapil_load_function("wglGetPixelFormatAttribfvEXT");
	gapil_wgl_func_table[43] = gapil_load_function("wglChoosePixelFormatEXT");
	gapil_wgl_func_table[44] = gapil_load_function("wglSwapIntervalEXT");
	gapil_wgl_func_table[45] = gapil_load_function("wglGetSwapIntervalEXT");
	gapil_wgl_func_table[46] = gapil_load_function("wglGetDigitalVideoParametersI3D");
	gapil_wgl_func_table[47] = gapil_load_function("wglSetDigitalVideoParametersI3D");
	gapil_wgl_func_table[48] = gapil_load_function("wglGetGammaTableParametersI3D");
	gapil_wgl_func_table[49] = gapil_load_function("wglSetGammaTableParametersI3D");
	gapil_wgl_func_table[50] = gapil_load_function("wglGetGammaTableI3D");
	gapil_wgl_func_table[51] = gapil_load_function("wglSetGammaTableI3D");
	gapil_wgl_func_table[52] = gapil_load_function("wglEnableGenlockI3D");
	gapil_wgl_func_table[53] = gapil_load_function("wglDisableGenlockI3D");
	gapil_wgl_func_table[54] = gapil_load_function("wglIsEnabledGenlockI3D");
	gapil_wgl_func_table[55] = gapil_load_function("wglGenlockSourceI3D");
	gapil_wgl_func_table[56] = gapil_load_function("wglGetGenlockSourceI3D");
	gapil_wgl_func_table[57] = gapil_load_function("wglGenlockSourceEdgeI3D");
	gapil_wgl_func_table[58] = gapil_load_function("wglGetGenlockSourceEdgeI3D");
	gapil_wgl_func_table[59] = gapil_load_function("wglGenlockSampleRateI3D");
	gapil_wgl_func_table[60] = gapil_load_function("wglGetGenlockSampleRateI3D");
	gapil_wgl_func_table[61] = gapil_load_function("wglGenlockSourceDelayI3D");
	gapil_wgl_func_table[62] = gapil_load_function("wglGetGenlockSourceDelayI3D");
	gapil_wgl_func_table[63] = gapil_load_function("wglQueryGenlockMaxSourceDelayI3D");
	gapil_wgl_func_table[64] = gapil_load_function("wglCreateImageBufferI3D");
	gapil_wgl_func_table[65] = gapil_load_function("wglDestroyImageBufferI3D");
	gapil_wgl_func_table[66] = gapil_load_function("wglAssociateImageBufferEventsI3D");
	gapil_wgl_func_table[67] = gapil_load_function("wglReleaseImageBufferEventsI3D");
	gapil_wgl_func_table[68] = gapil_load_function("wglEnableFrameLockI3D");
	gapil_wgl_func_table[69] = gapil_load_function("wglDisableFrameLockI3D");
	gapil_wgl_func_table[70] = gapil_load_function("wglIsEnabledFrameLockI3D");
	gapil_wgl_func_table[71] = gapil_load_function("wglQueryFrameLockMasterI3D");
	gapil_wgl_func_table[72] = gapil_load_function("wglGetFrameUsageI3D");
	gapil_wgl_func_table[73] = gapil_load_function("wglBeginFrameTrackingI3D");
	gapil_wgl_func_table[74] = gapil_load_function("wglEndFrameTrackingI3D");
	gapil_wgl_func_table[75] = gapil_load_function("wglQueryFrameTrackingI3D");
	gapil_wgl_func_table[76] = gapil_load_function("wglDXSetResourceShareHandleNV");
	gapil_wgl_func_table[77] = gapil_load_function("wglDXOpenDeviceNV");
	gapil_wgl_func_table[78] = gapil_load_function("wglDXCloseDeviceNV");
	gapil_wgl_func_table[79] = gapil_load_function("wglDXRegisterObjectNV");
	gapil_wgl_func_table[80] = gapil_load_function("wglDXUnregisterObjectNV");
	gapil_wgl_func_table[81] = gapil_load_function("wglDXObjectAccessNV");
	gapil_wgl_func_table[82] = gapil_load_function("wglDXLockObjectsNV");
	gapil_wgl_func_table[83] = gapil_load_function("wglDXUnlockObjectsNV");
	gapil_wgl_func_table[84] = gapil_load_function("wglCopyImageSubDataNV");
	gapil_wgl_func_table[85] = gapil_load_function("wglDelayBeforeSwapNV");
	gapil_wgl_func_table[86] = gapil_load_function("wglEnumGpusNV");
	gapil_wgl_func_table[87] = gapil_load_function("wglEnumGpuDevicesNV");
	gapil_wgl_func_table[88] = gapil_load_function("wglCreateAffinityDCNV");
	gapil_wgl_func_table[89] = gapil_load_function("wglEnumGpusFromAffinityDCNV");
	gapil_wgl_func_table[90] = gapil_load_function("wglDeleteDCNV");
	gapil_wgl_func_table[91] = gapil_load_function("wglEnumerateVideoDevicesNV");
	gapil_wgl_func_table[92] = gapil_load_function("wglBindVideoDeviceNV");
	gapil_wgl_func_table[93] = gapil_load_function("wglQueryCurrentContextNV");
	gapil_wgl_func_table[94] = gapil_load_function("wglJoinSwapGroupNV");
	gapil_wgl_func_table[95] = gapil_load_function("wglBindSwapBarrierNV");
	gapil_wgl_func_table[96] = gapil_load_function("wglQuerySwapGroupNV");
	gapil_wgl_func_table[97] = gapil_load_function("wglQueryMaxSwapGroupsNV");
	gapil_wgl_func_table[98] = gapil_load_function("wglQueryFrameCountNV");
	gapil_wgl_func_table[99] = gapil_load_function("wglResetFrameCountNV");
	gapil_wgl_func_table[100] = gapil_load_function("wglAllocateMemoryNV");
	gapil_wgl_func_table[101] = gapil_load_function("wglFreeMemoryNV");
	gapil_wgl_func_table[102] = gapil_load_function("wglBindVideoCaptureDeviceNV");
	gapil_wgl_func_table[103] = gapil_load_function("wglEnumerateVideoCaptureDevicesNV");
	gapil_wgl_func_table[104] = gapil_load_function("wglLockVideoCaptureDeviceNV");
	gapil_wgl_func_table[105] = gapil_load_function("wglQueryVideoCaptureDeviceNV");
	gapil_wgl_func_table[106] = gapil_load_function("wglReleaseVideoCaptureDeviceNV");
	gapil_wgl_func_table[107] = gapil_load_function("wglGetVideoDeviceNV");
	gapil_wgl_func_table[108] = gapil_load_function("wglReleaseVideoDeviceNV");
	gapil_wgl_func_table[109] = gapil_load_function("wglBindVideoImageNV");
	gapil_wgl_func_table[110] = gapil_load_function("wglReleaseVideoImageNV");
	gapil_wgl_func_table[111] = gapil_load_function("wglSendPbufferToVideoNV");
	gapil_wgl_func_table[112] = gapil_load_function("wglGetVideoInfoNV");
	gapil_wgl_func_table[113] = gapil_load_function("wglGetSyncValuesOML");
	gapil_wgl_func_table[114] = gapil_load_function("wglGetMscRateOML");
	gapil_wgl_func_table[115] = gapil_load_function("wglSwapBuffersMscOML");
	gapil_wgl_func_table[116] = gapil_load_function("wglSwapLayerBuffersMscOML");
	gapil_wgl_func_table[117] = gapil_load_function("wglWaitForMscOML");
	gapil_wgl_func_table[118] = gapil_load_function("wglWaitForSbcOML");

}

GLAPI HANDLE APIENTRY wglCreateBufferRegionARB(HDC hDC, int iLayerPlane, UINT uType)
{
	PFNWGLCREATEBUFFERREGIONARBPROC internal_f = (PFNWGLCREATEBUFFERREGIONARBPROC)gapil_wgl_func_table[0];
	assert(internal_f != NULL);
	return internal_f(hDC, iLayerPlane, uType);
}

GLAPI void APIENTRY wglDeleteBufferRegionARB(HANDLE hRegion)
{
	PFNWGLDELETEBUFFERREGIONARBPROC internal_f = (PFNWGLDELETEBUFFERREGIONARBPROC)gapil_wgl_func_table[1];
	assert(internal_f != NULL);
	return internal_f(hRegion);
}

GLAPI BOOL APIENTRY wglSaveBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height)
{
	PFNWGLSAVEBUFFERREGIONARBPROC internal_f = (PFNWGLSAVEBUFFERREGIONARBPROC)gapil_wgl_func_table[2];
	assert(internal_f != NULL);
	return internal_f(hRegion, x, y, width, height);
}

GLAPI BOOL APIENTRY wglRestoreBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc)
{
	PFNWGLRESTOREBUFFERREGIONARBPROC internal_f = (PFNWGLRESTOREBUFFERREGIONARBPROC)gapil_wgl_func_table[3];
	assert(internal_f != NULL);
	return internal_f(hRegion, x, y, width, height, xSrc, ySrc);
}

GLAPI HGLRC APIENTRY wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int * attribList)
{
	PFNWGLCREATECONTEXTATTRIBSARBPROC internal_f = (PFNWGLCREATECONTEXTATTRIBSARBPROC)gapil_wgl_func_table[4];
	assert(internal_f != NULL);
	return internal_f(hDC, hShareContext, attribList);
}

GLAPI const char * APIENTRY wglGetExtensionsStringARB(HDC hdc)
{
	PFNWGLGETEXTENSIONSSTRINGARBPROC internal_f = (PFNWGLGETEXTENSIONSSTRINGARBPROC)gapil_wgl_func_table[5];
	assert(internal_f != NULL);
	return internal_f(hdc);
}

GLAPI BOOL APIENTRY wglMakeContextCurrentARB(HDC hDrawDC, HDC hReadDC, HGLRC hglrc)
{
	PFNWGLMAKECONTEXTCURRENTARBPROC internal_f = (PFNWGLMAKECONTEXTCURRENTARBPROC)gapil_wgl_func_table[6];
	assert(internal_f != NULL);
	return internal_f(hDrawDC, hReadDC, hglrc);
}

GLAPI HDC APIENTRY wglGetCurrentReadDCARB()
{
	PFNWGLGETCURRENTREADDCARBPROC internal_f = (PFNWGLGETCURRENTREADDCARBPROC)gapil_wgl_func_table[7];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI HPBUFFERARB APIENTRY wglCreatePbufferARB(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList)
{
	PFNWGLCREATEPBUFFERARBPROC internal_f = (PFNWGLCREATEPBUFFERARBPROC)gapil_wgl_func_table[8];
	assert(internal_f != NULL);
	return internal_f(hDC, iPixelFormat, iWidth, iHeight, piAttribList);
}

GLAPI HDC APIENTRY wglGetPbufferDCARB(HPBUFFERARB hPbuffer)
{
	PFNWGLGETPBUFFERDCARBPROC internal_f = (PFNWGLGETPBUFFERDCARBPROC)gapil_wgl_func_table[9];
	assert(internal_f != NULL);
	return internal_f(hPbuffer);
}

GLAPI int APIENTRY wglReleasePbufferDCARB(HPBUFFERARB hPbuffer, HDC hDC)
{
	PFNWGLRELEASEPBUFFERDCARBPROC internal_f = (PFNWGLRELEASEPBUFFERDCARBPROC)gapil_wgl_func_table[10];
	assert(internal_f != NULL);
	return internal_f(hPbuffer, hDC);
}

GLAPI BOOL APIENTRY wglDestroyPbufferARB(HPBUFFERARB hPbuffer)
{
	PFNWGLDESTROYPBUFFERARBPROC internal_f = (PFNWGLDESTROYPBUFFERARBPROC)gapil_wgl_func_table[11];
	assert(internal_f != NULL);
	return internal_f(hPbuffer);
}

GLAPI BOOL APIENTRY wglQueryPbufferARB(HPBUFFERARB hPbuffer, int iAttribute, int * piValue)
{
	PFNWGLQUERYPBUFFERARBPROC internal_f = (PFNWGLQUERYPBUFFERARBPROC)gapil_wgl_func_table[12];
	assert(internal_f != NULL);
	return internal_f(hPbuffer, iAttribute, piValue);
}

GLAPI BOOL APIENTRY wglGetPixelFormatAttribivARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, int * piValues)
{
	PFNWGLGETPIXELFORMATATTRIBIVARBPROC internal_f = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC)gapil_wgl_func_table[13];
	assert(internal_f != NULL);
	return internal_f(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
}

GLAPI BOOL APIENTRY wglGetPixelFormatAttribfvARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, FLOAT * pfValues)
{
	PFNWGLGETPIXELFORMATATTRIBFVARBPROC internal_f = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC)gapil_wgl_func_table[14];
	assert(internal_f != NULL);
	return internal_f(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
}

GLAPI BOOL APIENTRY wglChoosePixelFormatARB(HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats)
{
	PFNWGLCHOOSEPIXELFORMATARBPROC internal_f = (PFNWGLCHOOSEPIXELFORMATARBPROC)gapil_wgl_func_table[15];
	assert(internal_f != NULL);
	return internal_f(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
}

GLAPI BOOL APIENTRY wglBindTexImageARB(HPBUFFERARB hPbuffer, int iBuffer)
{
	PFNWGLBINDTEXIMAGEARBPROC internal_f = (PFNWGLBINDTEXIMAGEARBPROC)gapil_wgl_func_table[16];
	assert(internal_f != NULL);
	return internal_f(hPbuffer, iBuffer);
}

GLAPI BOOL APIENTRY wglReleaseTexImageARB(HPBUFFERARB hPbuffer, int iBuffer)
{
	PFNWGLRELEASETEXIMAGEARBPROC internal_f = (PFNWGLRELEASETEXIMAGEARBPROC)gapil_wgl_func_table[17];
	assert(internal_f != NULL);
	return internal_f(hPbuffer, iBuffer);
}

GLAPI BOOL APIENTRY wglSetPbufferAttribARB(HPBUFFERARB hPbuffer, const int * piAttribList)
{
	PFNWGLSETPBUFFERATTRIBARBPROC internal_f = (PFNWGLSETPBUFFERATTRIBARBPROC)gapil_wgl_func_table[18];
	assert(internal_f != NULL);
	return internal_f(hPbuffer, piAttribList);
}

GLAPI BOOL APIENTRY wglSetStereoEmitterState3DL(HDC hDC, UINT uState)
{
	PFNWGLSETSTEREOEMITTERSTATE3DLPROC internal_f = (PFNWGLSETSTEREOEMITTERSTATE3DLPROC)gapil_wgl_func_table[19];
	assert(internal_f != NULL);
	return internal_f(hDC, uState);
}

GLAPI UINT APIENTRY wglGetGPUIDsAMD(UINT maxCount, UINT * ids)
{
	PFNWGLGETGPUIDSAMDPROC internal_f = (PFNWGLGETGPUIDSAMDPROC)gapil_wgl_func_table[20];
	assert(internal_f != NULL);
	return internal_f(maxCount, ids);
}

GLAPI INT APIENTRY wglGetGPUInfoAMD(UINT id, INT property, GLenum dataType, UINT size, void * data)
{
	PFNWGLGETGPUINFOAMDPROC internal_f = (PFNWGLGETGPUINFOAMDPROC)gapil_wgl_func_table[21];
	assert(internal_f != NULL);
	return internal_f(id, property, dataType, size, data);
}

GLAPI UINT APIENTRY wglGetContextGPUIDAMD(HGLRC hglrc)
{
	PFNWGLGETCONTEXTGPUIDAMDPROC internal_f = (PFNWGLGETCONTEXTGPUIDAMDPROC)gapil_wgl_func_table[22];
	assert(internal_f != NULL);
	return internal_f(hglrc);
}

GLAPI HGLRC APIENTRY wglCreateAssociatedContextAMD(UINT id)
{
	PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC internal_f = (PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC)gapil_wgl_func_table[23];
	assert(internal_f != NULL);
	return internal_f(id);
}

GLAPI HGLRC APIENTRY wglCreateAssociatedContextAttribsAMD(UINT id, HGLRC hShareContext, const int * attribList)
{
	PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC internal_f = (PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)gapil_wgl_func_table[24];
	assert(internal_f != NULL);
	return internal_f(id, hShareContext, attribList);
}

GLAPI BOOL APIENTRY wglDeleteAssociatedContextAMD(HGLRC hglrc)
{
	PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC internal_f = (PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC)gapil_wgl_func_table[25];
	assert(internal_f != NULL);
	return internal_f(hglrc);
}

GLAPI BOOL APIENTRY wglMakeAssociatedContextCurrentAMD(HGLRC hglrc)
{
	PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC internal_f = (PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)gapil_wgl_func_table[26];
	assert(internal_f != NULL);
	return internal_f(hglrc);
}

GLAPI HGLRC APIENTRY wglGetCurrentAssociatedContextAMD()
{
	PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC internal_f = (PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC)gapil_wgl_func_table[27];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI void APIENTRY wglBlitContextFramebufferAMD(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
{
	PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC internal_f = (PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC)gapil_wgl_func_table[28];
	assert(internal_f != NULL);
	return internal_f(dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

GLAPI GLboolean APIENTRY wglCreateDisplayColorTableEXT(GLushort id)
{
	PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC internal_f = (PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC)gapil_wgl_func_table[29];
	assert(internal_f != NULL);
	return internal_f(id);
}

GLAPI GLboolean APIENTRY wglLoadDisplayColorTableEXT(const GLushort * table, GLuint length)
{
	PFNWGLLOADDISPLAYCOLORTABLEEXTPROC internal_f = (PFNWGLLOADDISPLAYCOLORTABLEEXTPROC)gapil_wgl_func_table[30];
	assert(internal_f != NULL);
	return internal_f(table, length);
}

GLAPI GLboolean APIENTRY wglBindDisplayColorTableEXT(GLushort id)
{
	PFNWGLBINDDISPLAYCOLORTABLEEXTPROC internal_f = (PFNWGLBINDDISPLAYCOLORTABLEEXTPROC)gapil_wgl_func_table[31];
	assert(internal_f != NULL);
	return internal_f(id);
}

GLAPI void APIENTRY wglDestroyDisplayColorTableEXT(GLushort id)
{
	PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC internal_f = (PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC)gapil_wgl_func_table[32];
	assert(internal_f != NULL);
	return internal_f(id);
}

GLAPI const char * APIENTRY wglGetExtensionsStringEXT()
{
	PFNWGLGETEXTENSIONSSTRINGEXTPROC internal_f = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)gapil_wgl_func_table[33];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI BOOL APIENTRY wglMakeContextCurrentEXT(HDC hDrawDC, HDC hReadDC, HGLRC hglrc)
{
	PFNWGLMAKECONTEXTCURRENTEXTPROC internal_f = (PFNWGLMAKECONTEXTCURRENTEXTPROC)gapil_wgl_func_table[34];
	assert(internal_f != NULL);
	return internal_f(hDrawDC, hReadDC, hglrc);
}

GLAPI HDC APIENTRY wglGetCurrentReadDCEXT()
{
	PFNWGLGETCURRENTREADDCEXTPROC internal_f = (PFNWGLGETCURRENTREADDCEXTPROC)gapil_wgl_func_table[35];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI HPBUFFEREXT APIENTRY wglCreatePbufferEXT(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList)
{
	PFNWGLCREATEPBUFFEREXTPROC internal_f = (PFNWGLCREATEPBUFFEREXTPROC)gapil_wgl_func_table[36];
	assert(internal_f != NULL);
	return internal_f(hDC, iPixelFormat, iWidth, iHeight, piAttribList);
}

GLAPI HDC APIENTRY wglGetPbufferDCEXT(HPBUFFEREXT hPbuffer)
{
	PFNWGLGETPBUFFERDCEXTPROC internal_f = (PFNWGLGETPBUFFERDCEXTPROC)gapil_wgl_func_table[37];
	assert(internal_f != NULL);
	return internal_f(hPbuffer);
}

GLAPI int APIENTRY wglReleasePbufferDCEXT(HPBUFFEREXT hPbuffer, HDC hDC)
{
	PFNWGLRELEASEPBUFFERDCEXTPROC internal_f = (PFNWGLRELEASEPBUFFERDCEXTPROC)gapil_wgl_func_table[38];
	assert(internal_f != NULL);
	return internal_f(hPbuffer, hDC);
}

GLAPI BOOL APIENTRY wglDestroyPbufferEXT(HPBUFFEREXT hPbuffer)
{
	PFNWGLDESTROYPBUFFEREXTPROC internal_f = (PFNWGLDESTROYPBUFFEREXTPROC)gapil_wgl_func_table[39];
	assert(internal_f != NULL);
	return internal_f(hPbuffer);
}

GLAPI BOOL APIENTRY wglQueryPbufferEXT(HPBUFFEREXT hPbuffer, int iAttribute, int * piValue)
{
	PFNWGLQUERYPBUFFEREXTPROC internal_f = (PFNWGLQUERYPBUFFEREXTPROC)gapil_wgl_func_table[40];
	assert(internal_f != NULL);
	return internal_f(hPbuffer, iAttribute, piValue);
}

GLAPI BOOL APIENTRY wglGetPixelFormatAttribivEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, int * piValues)
{
	PFNWGLGETPIXELFORMATATTRIBIVEXTPROC internal_f = (PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)gapil_wgl_func_table[41];
	assert(internal_f != NULL);
	return internal_f(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
}

GLAPI BOOL APIENTRY wglGetPixelFormatAttribfvEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, FLOAT * pfValues)
{
	PFNWGLGETPIXELFORMATATTRIBFVEXTPROC internal_f = (PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)gapil_wgl_func_table[42];
	assert(internal_f != NULL);
	return internal_f(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
}

GLAPI BOOL APIENTRY wglChoosePixelFormatEXT(HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats)
{
	PFNWGLCHOOSEPIXELFORMATEXTPROC internal_f = (PFNWGLCHOOSEPIXELFORMATEXTPROC)gapil_wgl_func_table[43];
	assert(internal_f != NULL);
	return internal_f(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
}

GLAPI BOOL APIENTRY wglSwapIntervalEXT(int interval)
{
	PFNWGLSWAPINTERVALEXTPROC internal_f = (PFNWGLSWAPINTERVALEXTPROC)gapil_wgl_func_table[44];
	assert(internal_f != NULL);
	return internal_f(interval);
}

GLAPI int APIENTRY wglGetSwapIntervalEXT()
{
	PFNWGLGETSWAPINTERVALEXTPROC internal_f = (PFNWGLGETSWAPINTERVALEXTPROC)gapil_wgl_func_table[45];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI BOOL APIENTRY wglGetDigitalVideoParametersI3D(HDC hDC, int iAttribute, int * piValue)
{
	PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC internal_f = (PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)gapil_wgl_func_table[46];
	assert(internal_f != NULL);
	return internal_f(hDC, iAttribute, piValue);
}

GLAPI BOOL APIENTRY wglSetDigitalVideoParametersI3D(HDC hDC, int iAttribute, const int * piValue)
{
	PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC internal_f = (PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)gapil_wgl_func_table[47];
	assert(internal_f != NULL);
	return internal_f(hDC, iAttribute, piValue);
}

GLAPI BOOL APIENTRY wglGetGammaTableParametersI3D(HDC hDC, int iAttribute, int * piValue)
{
	PFNWGLGETGAMMATABLEPARAMETERSI3DPROC internal_f = (PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)gapil_wgl_func_table[48];
	assert(internal_f != NULL);
	return internal_f(hDC, iAttribute, piValue);
}

GLAPI BOOL APIENTRY wglSetGammaTableParametersI3D(HDC hDC, int iAttribute, const int * piValue)
{
	PFNWGLSETGAMMATABLEPARAMETERSI3DPROC internal_f = (PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)gapil_wgl_func_table[49];
	assert(internal_f != NULL);
	return internal_f(hDC, iAttribute, piValue);
}

GLAPI BOOL APIENTRY wglGetGammaTableI3D(HDC hDC, int iEntries, USHORT * puRed, USHORT * puGreen, USHORT * puBlue)
{
	PFNWGLGETGAMMATABLEI3DPROC internal_f = (PFNWGLGETGAMMATABLEI3DPROC)gapil_wgl_func_table[50];
	assert(internal_f != NULL);
	return internal_f(hDC, iEntries, puRed, puGreen, puBlue);
}

GLAPI BOOL APIENTRY wglSetGammaTableI3D(HDC hDC, int iEntries, const USHORT * puRed, const USHORT * puGreen, const USHORT * puBlue)
{
	PFNWGLSETGAMMATABLEI3DPROC internal_f = (PFNWGLSETGAMMATABLEI3DPROC)gapil_wgl_func_table[51];
	assert(internal_f != NULL);
	return internal_f(hDC, iEntries, puRed, puGreen, puBlue);
}

GLAPI BOOL APIENTRY wglEnableGenlockI3D(HDC hDC)
{
	PFNWGLENABLEGENLOCKI3DPROC internal_f = (PFNWGLENABLEGENLOCKI3DPROC)gapil_wgl_func_table[52];
	assert(internal_f != NULL);
	return internal_f(hDC);
}

GLAPI BOOL APIENTRY wglDisableGenlockI3D(HDC hDC)
{
	PFNWGLDISABLEGENLOCKI3DPROC internal_f = (PFNWGLDISABLEGENLOCKI3DPROC)gapil_wgl_func_table[53];
	assert(internal_f != NULL);
	return internal_f(hDC);
}

GLAPI BOOL APIENTRY wglIsEnabledGenlockI3D(HDC hDC, BOOL * pFlag)
{
	PFNWGLISENABLEDGENLOCKI3DPROC internal_f = (PFNWGLISENABLEDGENLOCKI3DPROC)gapil_wgl_func_table[54];
	assert(internal_f != NULL);
	return internal_f(hDC, pFlag);
}

GLAPI BOOL APIENTRY wglGenlockSourceI3D(HDC hDC, UINT uSource)
{
	PFNWGLGENLOCKSOURCEI3DPROC internal_f = (PFNWGLGENLOCKSOURCEI3DPROC)gapil_wgl_func_table[55];
	assert(internal_f != NULL);
	return internal_f(hDC, uSource);
}

GLAPI BOOL APIENTRY wglGetGenlockSourceI3D(HDC hDC, UINT * uSource)
{
	PFNWGLGETGENLOCKSOURCEI3DPROC internal_f = (PFNWGLGETGENLOCKSOURCEI3DPROC)gapil_wgl_func_table[56];
	assert(internal_f != NULL);
	return internal_f(hDC, uSource);
}

GLAPI BOOL APIENTRY wglGenlockSourceEdgeI3D(HDC hDC, UINT uEdge)
{
	PFNWGLGENLOCKSOURCEEDGEI3DPROC internal_f = (PFNWGLGENLOCKSOURCEEDGEI3DPROC)gapil_wgl_func_table[57];
	assert(internal_f != NULL);
	return internal_f(hDC, uEdge);
}

GLAPI BOOL APIENTRY wglGetGenlockSourceEdgeI3D(HDC hDC, UINT * uEdge)
{
	PFNWGLGETGENLOCKSOURCEEDGEI3DPROC internal_f = (PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)gapil_wgl_func_table[58];
	assert(internal_f != NULL);
	return internal_f(hDC, uEdge);
}

GLAPI BOOL APIENTRY wglGenlockSampleRateI3D(HDC hDC, UINT uRate)
{
	PFNWGLGENLOCKSAMPLERATEI3DPROC internal_f = (PFNWGLGENLOCKSAMPLERATEI3DPROC)gapil_wgl_func_table[59];
	assert(internal_f != NULL);
	return internal_f(hDC, uRate);
}

GLAPI BOOL APIENTRY wglGetGenlockSampleRateI3D(HDC hDC, UINT * uRate)
{
	PFNWGLGETGENLOCKSAMPLERATEI3DPROC internal_f = (PFNWGLGETGENLOCKSAMPLERATEI3DPROC)gapil_wgl_func_table[60];
	assert(internal_f != NULL);
	return internal_f(hDC, uRate);
}

GLAPI BOOL APIENTRY wglGenlockSourceDelayI3D(HDC hDC, UINT uDelay)
{
	PFNWGLGENLOCKSOURCEDELAYI3DPROC internal_f = (PFNWGLGENLOCKSOURCEDELAYI3DPROC)gapil_wgl_func_table[61];
	assert(internal_f != NULL);
	return internal_f(hDC, uDelay);
}

GLAPI BOOL APIENTRY wglGetGenlockSourceDelayI3D(HDC hDC, UINT * uDelay)
{
	PFNWGLGETGENLOCKSOURCEDELAYI3DPROC internal_f = (PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)gapil_wgl_func_table[62];
	assert(internal_f != NULL);
	return internal_f(hDC, uDelay);
}

GLAPI BOOL APIENTRY wglQueryGenlockMaxSourceDelayI3D(HDC hDC, UINT * uMaxLineDelay, UINT * uMaxPixelDelay)
{
	PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC internal_f = (PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)gapil_wgl_func_table[63];
	assert(internal_f != NULL);
	return internal_f(hDC, uMaxLineDelay, uMaxPixelDelay);
}

GLAPI LPVOID APIENTRY wglCreateImageBufferI3D(HDC hDC, DWORD dwSize, UINT uFlags)
{
	PFNWGLCREATEIMAGEBUFFERI3DPROC internal_f = (PFNWGLCREATEIMAGEBUFFERI3DPROC)gapil_wgl_func_table[64];
	assert(internal_f != NULL);
	return internal_f(hDC, dwSize, uFlags);
}

GLAPI BOOL APIENTRY wglDestroyImageBufferI3D(HDC hDC, LPVOID pAddress)
{
	PFNWGLDESTROYIMAGEBUFFERI3DPROC internal_f = (PFNWGLDESTROYIMAGEBUFFERI3DPROC)gapil_wgl_func_table[65];
	assert(internal_f != NULL);
	return internal_f(hDC, pAddress);
}

GLAPI BOOL APIENTRY wglAssociateImageBufferEventsI3D(HDC hDC, const HANDLE * pEvent, const LPVOID * pAddress, const DWORD * pSize, UINT count)
{
	PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC internal_f = (PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)gapil_wgl_func_table[66];
	assert(internal_f != NULL);
	return internal_f(hDC, pEvent, pAddress, pSize, count);
}

GLAPI BOOL APIENTRY wglReleaseImageBufferEventsI3D(HDC hDC, const LPVOID * pAddress, UINT count)
{
	PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC internal_f = (PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)gapil_wgl_func_table[67];
	assert(internal_f != NULL);
	return internal_f(hDC, pAddress, count);
}

GLAPI BOOL APIENTRY wglEnableFrameLockI3D()
{
	PFNWGLENABLEFRAMELOCKI3DPROC internal_f = (PFNWGLENABLEFRAMELOCKI3DPROC)gapil_wgl_func_table[68];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI BOOL APIENTRY wglDisableFrameLockI3D()
{
	PFNWGLDISABLEFRAMELOCKI3DPROC internal_f = (PFNWGLDISABLEFRAMELOCKI3DPROC)gapil_wgl_func_table[69];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI BOOL APIENTRY wglIsEnabledFrameLockI3D(BOOL * pFlag)
{
	PFNWGLISENABLEDFRAMELOCKI3DPROC internal_f = (PFNWGLISENABLEDFRAMELOCKI3DPROC)gapil_wgl_func_table[70];
	assert(internal_f != NULL);
	return internal_f(pFlag);
}

GLAPI BOOL APIENTRY wglQueryFrameLockMasterI3D(BOOL * pFlag)
{
	PFNWGLQUERYFRAMELOCKMASTERI3DPROC internal_f = (PFNWGLQUERYFRAMELOCKMASTERI3DPROC)gapil_wgl_func_table[71];
	assert(internal_f != NULL);
	return internal_f(pFlag);
}

GLAPI BOOL APIENTRY wglGetFrameUsageI3D(float * pUsage)
{
	PFNWGLGETFRAMEUSAGEI3DPROC internal_f = (PFNWGLGETFRAMEUSAGEI3DPROC)gapil_wgl_func_table[72];
	assert(internal_f != NULL);
	return internal_f(pUsage);
}

GLAPI BOOL APIENTRY wglBeginFrameTrackingI3D()
{
	PFNWGLBEGINFRAMETRACKINGI3DPROC internal_f = (PFNWGLBEGINFRAMETRACKINGI3DPROC)gapil_wgl_func_table[73];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI BOOL APIENTRY wglEndFrameTrackingI3D()
{
	PFNWGLENDFRAMETRACKINGI3DPROC internal_f = (PFNWGLENDFRAMETRACKINGI3DPROC)gapil_wgl_func_table[74];
	assert(internal_f != NULL);
	return internal_f();
}

GLAPI BOOL APIENTRY wglQueryFrameTrackingI3D(DWORD * pFrameCount, DWORD * pMissedFrames, float * pLastMissedUsage)
{
	PFNWGLQUERYFRAMETRACKINGI3DPROC internal_f = (PFNWGLQUERYFRAMETRACKINGI3DPROC)gapil_wgl_func_table[75];
	assert(internal_f != NULL);
	return internal_f(pFrameCount, pMissedFrames, pLastMissedUsage);
}

GLAPI BOOL APIENTRY wglDXSetResourceShareHandleNV(void * dxObject, HANDLE shareHandle)
{
	PFNWGLDXSETRESOURCESHAREHANDLENVPROC internal_f = (PFNWGLDXSETRESOURCESHAREHANDLENVPROC)gapil_wgl_func_table[76];
	assert(internal_f != NULL);
	return internal_f(dxObject, shareHandle);
}

GLAPI HANDLE APIENTRY wglDXOpenDeviceNV(void * dxDevice)
{
	PFNWGLDXOPENDEVICENVPROC internal_f = (PFNWGLDXOPENDEVICENVPROC)gapil_wgl_func_table[77];
	assert(internal_f != NULL);
	return internal_f(dxDevice);
}

GLAPI BOOL APIENTRY wglDXCloseDeviceNV(HANDLE hDevice)
{
	PFNWGLDXCLOSEDEVICENVPROC internal_f = (PFNWGLDXCLOSEDEVICENVPROC)gapil_wgl_func_table[78];
	assert(internal_f != NULL);
	return internal_f(hDevice);
}

GLAPI HANDLE APIENTRY wglDXRegisterObjectNV(HANDLE hDevice, void * dxObject, GLuint name, GLenum type, GLenum access)
{
	PFNWGLDXREGISTEROBJECTNVPROC internal_f = (PFNWGLDXREGISTEROBJECTNVPROC)gapil_wgl_func_table[79];
	assert(internal_f != NULL);
	return internal_f(hDevice, dxObject, name, type, access);
}

GLAPI BOOL APIENTRY wglDXUnregisterObjectNV(HANDLE hDevice, HANDLE hObject)
{
	PFNWGLDXUNREGISTEROBJECTNVPROC internal_f = (PFNWGLDXUNREGISTEROBJECTNVPROC)gapil_wgl_func_table[80];
	assert(internal_f != NULL);
	return internal_f(hDevice, hObject);
}

GLAPI BOOL APIENTRY wglDXObjectAccessNV(HANDLE hObject, GLenum access)
{
	PFNWGLDXOBJECTACCESSNVPROC internal_f = (PFNWGLDXOBJECTACCESSNVPROC)gapil_wgl_func_table[81];
	assert(internal_f != NULL);
	return internal_f(hObject, access);
}

GLAPI BOOL APIENTRY wglDXLockObjectsNV(HANDLE hDevice, GLint count, HANDLE * hObjects)
{
	PFNWGLDXLOCKOBJECTSNVPROC internal_f = (PFNWGLDXLOCKOBJECTSNVPROC)gapil_wgl_func_table[82];
	assert(internal_f != NULL);
	return internal_f(hDevice, count, hObjects);
}

GLAPI BOOL APIENTRY wglDXUnlockObjectsNV(HANDLE hDevice, GLint count, HANDLE * hObjects)
{
	PFNWGLDXUNLOCKOBJECTSNVPROC internal_f = (PFNWGLDXUNLOCKOBJECTSNVPROC)gapil_wgl_func_table[83];
	assert(internal_f != NULL);
	return internal_f(hDevice, count, hObjects);
}

GLAPI BOOL APIENTRY wglCopyImageSubDataNV(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth)
{
	PFNWGLCOPYIMAGESUBDATANVPROC internal_f = (PFNWGLCOPYIMAGESUBDATANVPROC)gapil_wgl_func_table[84];
	assert(internal_f != NULL);
	return internal_f(hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);
}

GLAPI BOOL APIENTRY wglDelayBeforeSwapNV(HDC hDC, GLfloat seconds)
{
	PFNWGLDELAYBEFORESWAPNVPROC internal_f = (PFNWGLDELAYBEFORESWAPNVPROC)gapil_wgl_func_table[85];
	assert(internal_f != NULL);
	return internal_f(hDC, seconds);
}

GLAPI BOOL APIENTRY wglEnumGpusNV(UINT iGpuIndex, HGPUNV * phGpu)
{
	PFNWGLENUMGPUSNVPROC internal_f = (PFNWGLENUMGPUSNVPROC)gapil_wgl_func_table[86];
	assert(internal_f != NULL);
	return internal_f(iGpuIndex, phGpu);
}

GLAPI BOOL APIENTRY wglEnumGpuDevicesNV(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice)
{
	PFNWGLENUMGPUDEVICESNVPROC internal_f = (PFNWGLENUMGPUDEVICESNVPROC)gapil_wgl_func_table[87];
	assert(internal_f != NULL);
	return internal_f(hGpu, iDeviceIndex, lpGpuDevice);
}

GLAPI HDC APIENTRY wglCreateAffinityDCNV(const HGPUNV * phGpuList)
{
	PFNWGLCREATEAFFINITYDCNVPROC internal_f = (PFNWGLCREATEAFFINITYDCNVPROC)gapil_wgl_func_table[88];
	assert(internal_f != NULL);
	return internal_f(phGpuList);
}

GLAPI BOOL APIENTRY wglEnumGpusFromAffinityDCNV(HDC hAffinityDC, UINT iGpuIndex, HGPUNV * hGpu)
{
	PFNWGLENUMGPUSFROMAFFINITYDCNVPROC internal_f = (PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)gapil_wgl_func_table[89];
	assert(internal_f != NULL);
	return internal_f(hAffinityDC, iGpuIndex, hGpu);
}

GLAPI BOOL APIENTRY wglDeleteDCNV(HDC hdc)
{
	PFNWGLDELETEDCNVPROC internal_f = (PFNWGLDELETEDCNVPROC)gapil_wgl_func_table[90];
	assert(internal_f != NULL);
	return internal_f(hdc);
}

GLAPI int APIENTRY wglEnumerateVideoDevicesNV(HDC hDc, HVIDEOOUTPUTDEVICENV * phDeviceList)
{
	PFNWGLENUMERATEVIDEODEVICESNVPROC internal_f = (PFNWGLENUMERATEVIDEODEVICESNVPROC)gapil_wgl_func_table[91];
	assert(internal_f != NULL);
	return internal_f(hDc, phDeviceList);
}

GLAPI BOOL APIENTRY wglBindVideoDeviceNV(HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int * piAttribList)
{
	PFNWGLBINDVIDEODEVICENVPROC internal_f = (PFNWGLBINDVIDEODEVICENVPROC)gapil_wgl_func_table[92];
	assert(internal_f != NULL);
	return internal_f(hDc, uVideoSlot, hVideoDevice, piAttribList);
}

GLAPI BOOL APIENTRY wglQueryCurrentContextNV(int iAttribute, int * piValue)
{
	PFNWGLQUERYCURRENTCONTEXTNVPROC internal_f = (PFNWGLQUERYCURRENTCONTEXTNVPROC)gapil_wgl_func_table[93];
	assert(internal_f != NULL);
	return internal_f(iAttribute, piValue);
}

GLAPI BOOL APIENTRY wglJoinSwapGroupNV(HDC hDC, GLuint group)
{
	PFNWGLJOINSWAPGROUPNVPROC internal_f = (PFNWGLJOINSWAPGROUPNVPROC)gapil_wgl_func_table[94];
	assert(internal_f != NULL);
	return internal_f(hDC, group);
}

GLAPI BOOL APIENTRY wglBindSwapBarrierNV(GLuint group, GLuint barrier)
{
	PFNWGLBINDSWAPBARRIERNVPROC internal_f = (PFNWGLBINDSWAPBARRIERNVPROC)gapil_wgl_func_table[95];
	assert(internal_f != NULL);
	return internal_f(group, barrier);
}

GLAPI BOOL APIENTRY wglQuerySwapGroupNV(HDC hDC, GLuint * group, GLuint * barrier)
{
	PFNWGLQUERYSWAPGROUPNVPROC internal_f = (PFNWGLQUERYSWAPGROUPNVPROC)gapil_wgl_func_table[96];
	assert(internal_f != NULL);
	return internal_f(hDC, group, barrier);
}

GLAPI BOOL APIENTRY wglQueryMaxSwapGroupsNV(HDC hDC, GLuint * maxGroups, GLuint * maxBarriers)
{
	PFNWGLQUERYMAXSWAPGROUPSNVPROC internal_f = (PFNWGLQUERYMAXSWAPGROUPSNVPROC)gapil_wgl_func_table[97];
	assert(internal_f != NULL);
	return internal_f(hDC, maxGroups, maxBarriers);
}

GLAPI BOOL APIENTRY wglQueryFrameCountNV(HDC hDC, GLuint * count)
{
	PFNWGLQUERYFRAMECOUNTNVPROC internal_f = (PFNWGLQUERYFRAMECOUNTNVPROC)gapil_wgl_func_table[98];
	assert(internal_f != NULL);
	return internal_f(hDC, count);
}

GLAPI BOOL APIENTRY wglResetFrameCountNV(HDC hDC)
{
	PFNWGLRESETFRAMECOUNTNVPROC internal_f = (PFNWGLRESETFRAMECOUNTNVPROC)gapil_wgl_func_table[99];
	assert(internal_f != NULL);
	return internal_f(hDC);
}

GLAPI void * APIENTRY wglAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority)
{
	PFNWGLALLOCATEMEMORYNVPROC internal_f = (PFNWGLALLOCATEMEMORYNVPROC)gapil_wgl_func_table[100];
	assert(internal_f != NULL);
	return internal_f(size, readfreq, writefreq, priority);
}

GLAPI void APIENTRY wglFreeMemoryNV(void * pointer)
{
	PFNWGLFREEMEMORYNVPROC internal_f = (PFNWGLFREEMEMORYNVPROC)gapil_wgl_func_table[101];
	assert(internal_f != NULL);
	return internal_f(pointer);
}

GLAPI BOOL APIENTRY wglBindVideoCaptureDeviceNV(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice)
{
	PFNWGLBINDVIDEOCAPTUREDEVICENVPROC internal_f = (PFNWGLBINDVIDEOCAPTUREDEVICENVPROC)gapil_wgl_func_table[102];
	assert(internal_f != NULL);
	return internal_f(uVideoSlot, hDevice);
}

GLAPI UINT APIENTRY wglEnumerateVideoCaptureDevicesNV(HDC hDc, HVIDEOINPUTDEVICENV * phDeviceList)
{
	PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC internal_f = (PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC)gapil_wgl_func_table[103];
	assert(internal_f != NULL);
	return internal_f(hDc, phDeviceList);
}

GLAPI BOOL APIENTRY wglLockVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice)
{
	PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC internal_f = (PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC)gapil_wgl_func_table[104];
	assert(internal_f != NULL);
	return internal_f(hDc, hDevice);
}

GLAPI BOOL APIENTRY wglQueryVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int * piValue)
{
	PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC internal_f = (PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC)gapil_wgl_func_table[105];
	assert(internal_f != NULL);
	return internal_f(hDc, hDevice, iAttribute, piValue);
}

GLAPI BOOL APIENTRY wglReleaseVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice)
{
	PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC internal_f = (PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC)gapil_wgl_func_table[106];
	assert(internal_f != NULL);
	return internal_f(hDc, hDevice);
}

GLAPI BOOL APIENTRY wglGetVideoDeviceNV(HDC hDC, int numDevices, HPVIDEODEV * hVideoDevice)
{
	PFNWGLGETVIDEODEVICENVPROC internal_f = (PFNWGLGETVIDEODEVICENVPROC)gapil_wgl_func_table[107];
	assert(internal_f != NULL);
	return internal_f(hDC, numDevices, hVideoDevice);
}

GLAPI BOOL APIENTRY wglReleaseVideoDeviceNV(HPVIDEODEV hVideoDevice)
{
	PFNWGLRELEASEVIDEODEVICENVPROC internal_f = (PFNWGLRELEASEVIDEODEVICENVPROC)gapil_wgl_func_table[108];
	assert(internal_f != NULL);
	return internal_f(hVideoDevice);
}

GLAPI BOOL APIENTRY wglBindVideoImageNV(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer)
{
	PFNWGLBINDVIDEOIMAGENVPROC internal_f = (PFNWGLBINDVIDEOIMAGENVPROC)gapil_wgl_func_table[109];
	assert(internal_f != NULL);
	return internal_f(hVideoDevice, hPbuffer, iVideoBuffer);
}

GLAPI BOOL APIENTRY wglReleaseVideoImageNV(HPBUFFERARB hPbuffer, int iVideoBuffer)
{
	PFNWGLRELEASEVIDEOIMAGENVPROC internal_f = (PFNWGLRELEASEVIDEOIMAGENVPROC)gapil_wgl_func_table[110];
	assert(internal_f != NULL);
	return internal_f(hPbuffer, iVideoBuffer);
}

GLAPI BOOL APIENTRY wglSendPbufferToVideoNV(HPBUFFERARB hPbuffer, int iBufferType, unsigned long * pulCounterPbuffer, BOOL bBlock)
{
	PFNWGLSENDPBUFFERTOVIDEONVPROC internal_f = (PFNWGLSENDPBUFFERTOVIDEONVPROC)gapil_wgl_func_table[111];
	assert(internal_f != NULL);
	return internal_f(hPbuffer, iBufferType, pulCounterPbuffer, bBlock);
}

GLAPI BOOL APIENTRY wglGetVideoInfoNV(HPVIDEODEV hpVideoDevice, unsigned long * pulCounterOutputPbuffer, unsigned long * pulCounterOutputVideo)
{
	PFNWGLGETVIDEOINFONVPROC internal_f = (PFNWGLGETVIDEOINFONVPROC)gapil_wgl_func_table[112];
	assert(internal_f != NULL);
	return internal_f(hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo);
}

GLAPI BOOL APIENTRY wglGetSyncValuesOML(HDC hdc, INT64 * ust, INT64 * msc, INT64 * sbc)
{
	PFNWGLGETSYNCVALUESOMLPROC internal_f = (PFNWGLGETSYNCVALUESOMLPROC)gapil_wgl_func_table[113];
	assert(internal_f != NULL);
	return internal_f(hdc, ust, msc, sbc);
}

GLAPI BOOL APIENTRY wglGetMscRateOML(HDC hdc, INT32 * numerator, INT32 * denominator)
{
	PFNWGLGETMSCRATEOMLPROC internal_f = (PFNWGLGETMSCRATEOMLPROC)gapil_wgl_func_table[114];
	assert(internal_f != NULL);
	return internal_f(hdc, numerator, denominator);
}

GLAPI INT64 APIENTRY wglSwapBuffersMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder)
{
	PFNWGLSWAPBUFFERSMSCOMLPROC internal_f = (PFNWGLSWAPBUFFERSMSCOMLPROC)gapil_wgl_func_table[115];
	assert(internal_f != NULL);
	return internal_f(hdc, target_msc, divisor, remainder);
}

GLAPI INT64 APIENTRY wglSwapLayerBuffersMscOML(HDC hdc, INT fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder)
{
	PFNWGLSWAPLAYERBUFFERSMSCOMLPROC internal_f = (PFNWGLSWAPLAYERBUFFERSMSCOMLPROC)gapil_wgl_func_table[116];
	assert(internal_f != NULL);
	return internal_f(hdc, fuPlanes, target_msc, divisor, remainder);
}

GLAPI BOOL APIENTRY wglWaitForMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 * ust, INT64 * msc, INT64 * sbc)
{
	PFNWGLWAITFORMSCOMLPROC internal_f = (PFNWGLWAITFORMSCOMLPROC)gapil_wgl_func_table[117];
	assert(internal_f != NULL);
	return internal_f(hdc, target_msc, divisor, remainder, ust, msc, sbc);
}

GLAPI BOOL APIENTRY wglWaitForSbcOML(HDC hdc, INT64 target_sbc, INT64 * ust, INT64 * msc, INT64 * sbc)
{
	PFNWGLWAITFORSBCOMLPROC internal_f = (PFNWGLWAITFORSBCOMLPROC)gapil_wgl_func_table[118];
	assert(internal_f != NULL);
	return internal_f(hdc, target_sbc, ust, msc, sbc);
}

#endif

#ifdef __cplusplus
}
#endif

#endif