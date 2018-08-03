#include "glcore2.hpp"

// get OpenGL procedure address
#ifndef GetProcAddress
#if defined(_WIN32)
#define GetProcAddress(x) wglGetProcAddress(x)
#elif defined(__linux__)
#include <GL/glx.h>
#define GetProcAddress(x) glxGetProcAddress((const GLubyte *)x);
#endif
#endif

// GL_VERSION_1_2
PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = nullptr;
PFNGLTEXIMAGE3DPROC        glTexImage3D = nullptr;
PFNGLTEXSUBIMAGE3DPROC     glTexSubImage3D = nullptr;
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = nullptr;

// GL_VERSION_1_3
PFNGLACTIVETEXTUREPROC           glActiveTexture = nullptr;
PFNGLSAMPLECOVERAGEPROC          glSampleCoverage = nullptr;
PFNGLCOMPRESSEDTEXIMAGE3DPROC    glCompressedTexImage3D = nullptr;
PFNGLCOMPRESSEDTEXIMAGE2DPROC    glCompressedTexImage2D = nullptr;
PFNGLCOMPRESSEDTEXIMAGE1DPROC    glCompressedTexImage1D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = nullptr;
PFNGLGETCOMPRESSEDTEXIMAGEPROC   glGetCompressedTexImage = nullptr;

// GL_VERSION_1_4
PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = nullptr;
PFNGLMULTIDRAWARRAYSPROC   glMultiDrawArrays = nullptr;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = nullptr;
PFNGLPOINTPARAMETERFPROC   glPointParameterf = nullptr;
PFNGLPOINTPARAMETERFVPROC  glPointParameterfv = nullptr;
PFNGLPOINTPARAMETERIPROC   glPointParameteri = nullptr;
PFNGLPOINTPARAMETERIVPROC  glPointParameteriv = nullptr;
PFNGLBLENDCOLORPROC        glBlendColor = nullptr;
PFNGLBLENDEQUATIONPROC     glBlendEquation = nullptr;

// GL_VERSION_1_5
PFNGLGENQUERIESPROC           glGenQueries = nullptr;
PFNGLDELETEQUERIESPROC        glDeleteQueries = nullptr;
PFNGLISQUERYPROC              glIsQuery = nullptr;
PFNGLBEGINQUERYPROC           glBeginQuery = nullptr;
PFNGLENDQUERYPROC             glEndQuery = nullptr;
PFNGLGETQUERYIVPROC           glGetQueryiv = nullptr;
PFNGLGETQUERYOBJECTIVPROC     glGetQueryObjectiv = nullptr;
PFNGLGETQUERYOBJECTUIVPROC    glGetQueryObjectuiv = nullptr;
PFNGLBINDBUFFERPROC           glBindBuffer = nullptr;
PFNGLDELETEBUFFERSPROC        glDeleteBuffers = nullptr;
PFNGLGENBUFFERSPROC           glGenBuffers = nullptr;
PFNGLISBUFFERPROC             glIsBuffer = nullptr;
PFNGLBUFFERDATAPROC           glBufferData = nullptr;
PFNGLBUFFERSUBDATAPROC        glBufferSubData = nullptr;
PFNGLGETBUFFERSUBDATAPROC     glGetBufferSubData = nullptr;
PFNGLMAPBUFFERPROC            glMapBuffer = nullptr;
PFNGLUNMAPBUFFERPROC          glUnmapBuffer = nullptr;
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = nullptr;
PFNGLGETBUFFERPOINTERVPROC    glGetBufferPointerv = nullptr;

// GL_VERSION_2_0
PFNGLBLENDEQUATIONSEPARATEPROC    glBlendEquationSeparate = nullptr;
PFNGLDRAWBUFFERSPROC              glDrawBuffers = nullptr;
PFNGLSTENCILOPSEPARATEPROC        glStencilOpSeparate = nullptr;
PFNGLSTENCILFUNCSEPARATEPROC      glStencilFuncSeparate = nullptr;
PFNGLSTENCILMASKSEPARATEPROC      glStencilMaskSeparate = nullptr;
PFNGLATTACHSHADERPROC             glAttachShader = nullptr;
PFNGLBINDATTRIBLOCATIONPROC       glBindAttribLocation = nullptr;
PFNGLCOMPILESHADERPROC            glCompileShader = nullptr;
PFNGLCREATEPROGRAMPROC            glCreateProgram = nullptr;
PFNGLCREATESHADERPROC             glCreateShader = nullptr;
PFNGLDELETEPROGRAMPROC            glDeleteProgram = nullptr;
PFNGLDELETESHADERPROC             glDeleteShader = nullptr;
PFNGLDETACHSHADERPROC             glDetachShader = nullptr;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC  glEnableVertexAttribArray = nullptr;
PFNGLGETACTIVEATTRIBPROC          glGetActiveAttrib = nullptr;
PFNGLGETACTIVEUNIFORMPROC         glGetActiveUniform = nullptr;
PFNGLGETATTACHEDSHADERSPROC       glGetAttachedShaders = nullptr;
PFNGLGETATTRIBLOCATIONPROC        glGetAttribLocation = nullptr;
PFNGLGETPROGRAMIVPROC             glGetProgramiv = nullptr;
PFNGLGETPROGRAMINFOLOGPROC        glGetProgramInfoLog = nullptr;
PFNGLGETSHADERIVPROC              glGetShaderiv = nullptr;
PFNGLGETSHADERINFOLOGPROC         glGetShaderInfoLog = nullptr;
PFNGLGETSHADERSOURCEPROC          glGetShaderSource = nullptr;
PFNGLGETUNIFORMLOCATIONPROC       glGetUniformLocation = nullptr;
PFNGLGETUNIFORMFVPROC             glGetUniformfv = nullptr;
PFNGLGETUNIFORMIVPROC             glGetUniformiv = nullptr;
PFNGLGETVERTEXATTRIBDVPROC        glGetVertexAttribdv = nullptr;
PFNGLGETVERTEXATTRIBFVPROC        glGetVertexAttribfv = nullptr;
PFNGLGETVERTEXATTRIBIVPROC        glGetVertexAttribiv = nullptr;
PFNGLGETVERTEXATTRIBPOINTERVPROC  glGetVertexAttribPointerv = nullptr;
PFNGLISPROGRAMPROC                glIsProgram = nullptr;
PFNGLISSHADERPROC                 glIsShader = nullptr;
PFNGLLINKPROGRAMPROC              glLinkProgram = nullptr;
PFNGLSHADERSOURCEPROC             glShaderSource = nullptr;
PFNGLUSEPROGRAMPROC               glUseProgram = nullptr;
PFNGLUNIFORM1FPROC                glUniform1f = nullptr;
PFNGLUNIFORM2FPROC                glUniform2f = nullptr;
PFNGLUNIFORM3FPROC                glUniform3f = nullptr;
PFNGLUNIFORM4FPROC                glUniform4f = nullptr;
PFNGLUNIFORM1IPROC                glUniform1i = nullptr;
PFNGLUNIFORM2IPROC                glUniform2i = nullptr;
PFNGLUNIFORM3IPROC                glUniform3i = nullptr;
PFNGLUNIFORM4IPROC                glUniform4i = nullptr;
PFNGLUNIFORM1FVPROC               glUniform1fv = nullptr;
PFNGLUNIFORM2FVPROC               glUniform2fv = nullptr;
PFNGLUNIFORM3FVPROC               glUniform3fv = nullptr;
PFNGLUNIFORM4FVPROC               glUniform4fv = nullptr;
PFNGLUNIFORM1IVPROC               glUniform1iv = nullptr;
PFNGLUNIFORM2IVPROC               glUniform2iv = nullptr;
PFNGLUNIFORM3IVPROC               glUniform3iv = nullptr;
PFNGLUNIFORM4IVPROC               glUniform4iv = nullptr;
PFNGLUNIFORMMATRIX2FVPROC         glUniformMatrix2fv = nullptr;
PFNGLUNIFORMMATRIX3FVPROC         glUniformMatrix3fv = nullptr;
PFNGLUNIFORMMATRIX4FVPROC         glUniformMatrix4fv = nullptr;
PFNGLVALIDATEPROGRAMPROC          glValidateProgram = nullptr;
PFNGLVERTEXATTRIB1DPROC           glVertexAttrib1d = nullptr;
PFNGLVERTEXATTRIB1DVPROC          glVertexAttrib1dv = nullptr;
PFNGLVERTEXATTRIB1FPROC           glVertexAttrib1f = nullptr;
PFNGLVERTEXATTRIB1FVPROC          glVertexAttrib1fv = nullptr;
PFNGLVERTEXATTRIB1SPROC           glVertexAttrib1s = nullptr;
PFNGLVERTEXATTRIB1SVPROC          glVertexAttrib1sv = nullptr;
PFNGLVERTEXATTRIB2DPROC           glVertexAttrib2d = nullptr;
PFNGLVERTEXATTRIB2DVPROC          glVertexAttrib2dv = nullptr;
PFNGLVERTEXATTRIB2FPROC           glVertexAttrib2f = nullptr;
PFNGLVERTEXATTRIB2FVPROC          glVertexAttrib2fv = nullptr;
PFNGLVERTEXATTRIB2SPROC           glVertexAttrib2s = nullptr;
PFNGLVERTEXATTRIB2SVPROC          glVertexAttrib2sv = nullptr;
PFNGLVERTEXATTRIB3DPROC           glVertexAttrib3d = nullptr;
PFNGLVERTEXATTRIB3DVPROC          glVertexAttrib3dv = nullptr;
PFNGLVERTEXATTRIB3FPROC           glVertexAttrib3f = nullptr;
PFNGLVERTEXATTRIB3FVPROC          glVertexAttrib3fv = nullptr;
PFNGLVERTEXATTRIB3SPROC           glVertexAttrib3s = nullptr;
PFNGLVERTEXATTRIB3SVPROC          glVertexAttrib3sv = nullptr;
PFNGLVERTEXATTRIB4NBVPROC         glVertexAttrib4Nbv = nullptr;
PFNGLVERTEXATTRIB4NIVPROC         glVertexAttrib4Niv = nullptr;
PFNGLVERTEXATTRIB4NSVPROC         glVertexAttrib4Nsv = nullptr;
PFNGLVERTEXATTRIB4NUBPROC         glVertexAttrib4Nub = nullptr;
PFNGLVERTEXATTRIB4NUBVPROC        glVertexAttrib4Nubv = nullptr;
PFNGLVERTEXATTRIB4NUIVPROC        glVertexAttrib4Nuiv = nullptr;
PFNGLVERTEXATTRIB4NUSVPROC        glVertexAttrib4Nusv = nullptr;
PFNGLVERTEXATTRIB4BVPROC          glVertexAttrib4bv = nullptr;
PFNGLVERTEXATTRIB4DPROC           glVertexAttrib4d = nullptr;
PFNGLVERTEXATTRIB4DVPROC          glVertexAttrib4dv = nullptr;
PFNGLVERTEXATTRIB4FPROC           glVertexAttrib4f = nullptr;
PFNGLVERTEXATTRIB4FVPROC          glVertexAttrib4fv = nullptr;
PFNGLVERTEXATTRIB4IVPROC          glVertexAttrib4iv = nullptr;
PFNGLVERTEXATTRIB4SPROC           glVertexAttrib4s = nullptr;
PFNGLVERTEXATTRIB4SVPROC          glVertexAttrib4sv = nullptr;
PFNGLVERTEXATTRIB4UBVPROC         glVertexAttrib4ubv = nullptr;
PFNGLVERTEXATTRIB4UIVPROC         glVertexAttrib4uiv = nullptr;
PFNGLVERTEXATTRIB4USVPROC         glVertexAttrib4usv = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC      glVertexAttribPointer = nullptr;

// GL_VERSION_2_1
PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = nullptr;
PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = nullptr;
PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = nullptr;
PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = nullptr;
PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = nullptr;
PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = nullptr;

// glcore2Init
extern void glcore2Init()
{
	// GL_VERSION_1_2
	glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)GetProcAddress("glDrawRangeElements");
	glTexImage3D = (PFNGLTEXIMAGE3DPROC)GetProcAddress("glTexImage3D");
	glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)GetProcAddress("glTexSubImage3D");
	glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)GetProcAddress("glCopyTexSubImage3D");

	// GL_VERSION_1_3
	glActiveTexture = (PFNGLACTIVETEXTUREPROC)GetProcAddress("glActiveTexture");
	glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)GetProcAddress("glSampleCoverage");
	glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)GetProcAddress("glCompressedTexImage3D");
	glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)GetProcAddress("glCompressedTexImage2D");
	glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)GetProcAddress("glCompressedTexImage1D");
	glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)GetProcAddress("glCompressedTexSubImage3D");
	glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)GetProcAddress("glCompressedTexSubImage2D");
	glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)GetProcAddress("glCompressedTexSubImage1D");
	glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)GetProcAddress("glGetCompressedTexImage");

	// GL_VERSION_1_4
	glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)GetProcAddress("glBlendFuncSeparate");
	glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)GetProcAddress("glMultiDrawArrays");
	glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)GetProcAddress("glMultiDrawElements");
	glPointParameterf = (PFNGLPOINTPARAMETERFPROC)GetProcAddress("glPointParameterf");
	glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)GetProcAddress("glPointParameterfv");
	glPointParameteri = (PFNGLPOINTPARAMETERIPROC)GetProcAddress("glPointParameteri");
	glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)GetProcAddress("glPointParameteriv");
	glBlendColor = (PFNGLBLENDCOLORPROC)GetProcAddress("glBlendColor");
	glBlendEquation = (PFNGLBLENDEQUATIONPROC)GetProcAddress("glBlendEquation");

	// GL_VERSION_1_5
	glGenQueries = (PFNGLGENQUERIESPROC)GetProcAddress("glGenQueries");
	glDeleteQueries = (PFNGLDELETEQUERIESPROC)GetProcAddress("glDeleteQueries");
	glIsQuery = (PFNGLISQUERYPROC)GetProcAddress("glIsQuery");
	glBeginQuery = (PFNGLBEGINQUERYPROC)GetProcAddress("glBeginQuery");
	glEndQuery = (PFNGLENDQUERYPROC)GetProcAddress("glEndQuery");
	glGetQueryiv = (PFNGLGETQUERYIVPROC)GetProcAddress("glGetQueryiv");
	glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)GetProcAddress("glGetQueryObjectiv");
	glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)GetProcAddress("glGetQueryObjectuiv");
	glBindBuffer = (PFNGLBINDBUFFERPROC)GetProcAddress("glBindBuffer");
	glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)GetProcAddress("glDeleteBuffers");
	glGenBuffers = (PFNGLGENBUFFERSPROC)GetProcAddress("glGenBuffers");
	glIsBuffer = (PFNGLISBUFFERPROC)GetProcAddress("glIsBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)GetProcAddress("glBufferData");
	glBufferSubData = (PFNGLBUFFERSUBDATAPROC)GetProcAddress("glBufferSubData");
	glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)GetProcAddress("glGetBufferSubData");
	glMapBuffer = (PFNGLMAPBUFFERPROC)GetProcAddress("glMapBuffer");
	glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)GetProcAddress("glUnmapBuffer");
	glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)GetProcAddress("glGetBufferParameteriv");
	glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)GetProcAddress("glGetBufferPointerv");

	// GL_VERSION_2_0
	glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)GetProcAddress("glBlendEquationSeparate");
	glDrawBuffers = (PFNGLDRAWBUFFERSPROC)GetProcAddress("glDrawBuffers");
	glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)GetProcAddress("glStencilOpSeparate");
	glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)GetProcAddress("glStencilFuncSeparate");
	glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)GetProcAddress("glStencilMaskSeparate");
	glAttachShader = (PFNGLATTACHSHADERPROC)GetProcAddress("glAttachShader");
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)GetProcAddress("glBindAttribLocation");
	glCompileShader = (PFNGLCOMPILESHADERPROC)GetProcAddress("glCompileShader");
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)GetProcAddress("glCreateProgram");
	glCreateShader = (PFNGLCREATESHADERPROC)GetProcAddress("glCreateShader");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)GetProcAddress("glDeleteProgram");
	glDeleteShader = (PFNGLDELETESHADERPROC)GetProcAddress("glDeleteShader");
	glDetachShader = (PFNGLDETACHSHADERPROC)GetProcAddress("glDetachShader");
	glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)GetProcAddress("glDisableVertexAttribArray");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)GetProcAddress("glEnableVertexAttribArray");
	glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)GetProcAddress("glGetActiveAttrib");
	glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)GetProcAddress("glGetActiveUniform");
	glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)GetProcAddress("glGetAttachedShaders");
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)GetProcAddress("glGetAttribLocation");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)GetProcAddress("glGetProgramiv");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)GetProcAddress("glGetProgramInfoLog");
	glGetShaderiv = (PFNGLGETSHADERIVPROC)GetProcAddress("glGetShaderiv");
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)GetProcAddress("glGetShaderInfoLog");
	glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)GetProcAddress("glGetShaderSource");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)GetProcAddress("glGetUniformLocation");
	glGetUniformfv = (PFNGLGETUNIFORMFVPROC)GetProcAddress("glGetUniformfv");
	glGetUniformiv = (PFNGLGETUNIFORMIVPROC)GetProcAddress("glGetUniformiv");
	glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)GetProcAddress("glGetVertexAttribdv");
	glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)GetProcAddress("glGetVertexAttribfv");
	glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)GetProcAddress("glGetVertexAttribiv");
	glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)GetProcAddress("glGetVertexAttribPointerv");
	glIsProgram = (PFNGLISPROGRAMPROC)GetProcAddress("glIsProgram");
	glIsShader = (PFNGLISSHADERPROC)GetProcAddress("glIsShader");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)GetProcAddress("glLinkProgram");
	glShaderSource = (PFNGLSHADERSOURCEPROC)GetProcAddress("glShaderSource");
	glUseProgram = (PFNGLUSEPROGRAMPROC)GetProcAddress("glUseProgram");
	glUniform1f = (PFNGLUNIFORM1FPROC)GetProcAddress("glUniform1f");
	glUniform2f = (PFNGLUNIFORM2FPROC)GetProcAddress("glUniform2f");
	glUniform3f = (PFNGLUNIFORM3FPROC)GetProcAddress("glUniform3f");
	glUniform4f = (PFNGLUNIFORM4FPROC)GetProcAddress("glUniform4f");
	glUniform1i = (PFNGLUNIFORM1IPROC)GetProcAddress("glUniform1i");
	glUniform2i = (PFNGLUNIFORM2IPROC)GetProcAddress("glUniform2i");
	glUniform3i = (PFNGLUNIFORM3IPROC)GetProcAddress("glUniform3i");
	glUniform4i = (PFNGLUNIFORM4IPROC)GetProcAddress("glUniform4i");
	glUniform1fv = (PFNGLUNIFORM1FVPROC)GetProcAddress("glUniform1fv");
	glUniform2fv = (PFNGLUNIFORM2FVPROC)GetProcAddress("glUniform2fv");
	glUniform3fv = (PFNGLUNIFORM3FVPROC)GetProcAddress("glUniform3fv");
	glUniform4fv = (PFNGLUNIFORM4FVPROC)GetProcAddress("glUniform4fv");
	glUniform1iv = (PFNGLUNIFORM1IVPROC)GetProcAddress("glUniform1iv");
	glUniform2iv = (PFNGLUNIFORM2IVPROC)GetProcAddress("glUniform2iv");
	glUniform3iv = (PFNGLUNIFORM3IVPROC)GetProcAddress("glUniform3iv");
	glUniform4iv = (PFNGLUNIFORM4IVPROC)GetProcAddress("glUniform4iv");
	glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)GetProcAddress("glUniformMatrix2fv");
	glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)GetProcAddress("glUniformMatrix3fv");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)GetProcAddress("glUniformMatrix4fv");
	glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)GetProcAddress("glValidateProgram");
	glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)GetProcAddress("glVertexAttrib1d");
	glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)GetProcAddress("glVertexAttrib1dv");
	glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)GetProcAddress("glVertexAttrib1f");
	glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)GetProcAddress("glVertexAttrib1fv");
	glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)GetProcAddress("glVertexAttrib1s");
	glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)GetProcAddress("glVertexAttrib1sv");
	glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)GetProcAddress("glVertexAttrib2d");
	glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)GetProcAddress("glVertexAttrib2dv");
	glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)GetProcAddress("glVertexAttrib2f");
	glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)GetProcAddress("glVertexAttrib2fv");
	glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)GetProcAddress("glVertexAttrib2s");
	glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)GetProcAddress("glVertexAttrib2sv");
	glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)GetProcAddress("glVertexAttrib3d");
	glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)GetProcAddress("glVertexAttrib3dv");
	glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)GetProcAddress("glVertexAttrib3f");
	glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)GetProcAddress("glVertexAttrib3fv");
	glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)GetProcAddress("glVertexAttrib3s");
	glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)GetProcAddress("glVertexAttrib3sv");
	glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)GetProcAddress("glVertexAttrib4Nbv");
	glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)GetProcAddress("glVertexAttrib4Niv");
	glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)GetProcAddress("glVertexAttrib4Nsv");
	glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)GetProcAddress("glVertexAttrib4Nub");
	glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)GetProcAddress("glVertexAttrib4Nubv");
	glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)GetProcAddress("glVertexAttrib4Nuiv");
	glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)GetProcAddress("glVertexAttrib4Nusv");
	glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)GetProcAddress("glVertexAttrib4bv");
	glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)GetProcAddress("glVertexAttrib4d");
	glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)GetProcAddress("glVertexAttrib4dv");
	glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)GetProcAddress("glVertexAttrib4f");
	glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)GetProcAddress("glVertexAttrib4fv");
	glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)GetProcAddress("glVertexAttrib4iv");
	glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)GetProcAddress("glVertexAttrib4s");
	glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)GetProcAddress("glVertexAttrib4sv");
	glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)GetProcAddress("glVertexAttrib4ubv");
	glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)GetProcAddress("glVertexAttrib4uiv");
	glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)GetProcAddress("glVertexAttrib4usv");
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)GetProcAddress("glVertexAttribPointer");

	// GL_VERSION_2_1
	glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)GetProcAddress("glUniformMatrix2x3fv");
	glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)GetProcAddress("glUniformMatrix3x2fv");
	glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)GetProcAddress("glUniformMatrix2x4fv");
	glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)GetProcAddress("glUniformMatrix4x2fv");
	glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)GetProcAddress("glUniformMatrix3x4fv");
	glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)GetProcAddress("glUniformMatrix4x3fv");
}
