#pragma once

#include <cassert>
#include <GL/glcorearb.h>
#include <GL/GL.h>
#include "../SLRenderer.hpp"

// OpenGL check error defines
#ifdef _DEBUG
#define GL_CHECK(stmt) stmt; assert(glGetError() == GL_NO_ERROR);
#else
#define GL_CHECK(stmt) stmt
#endif

// SLR_GL2
namespace SLR_GL2
{
	// SLPixelDataType to OpenGL format converter
	static const GLuint cSLVertexAttribLication_Position = 0;
	static const GLuint cSLVertexAttribLication_Color = 1;
	static const GLuint cSLVertexAttribLication_Normal = 2;
	static const GLuint cSLVertexAttribLication_Tangent = 3;
	static const GLuint cSLVertexAttribLication_TexCoord = 4;
	static const GLuint cSLVertexAttribLication_Weights = 5;

	// SLPixelDataType to OpenGL format converter
	static const GLenum cSLPixelDataTypeToGLFormat[] = {
		GL_RGB,  // SL_PIXEL_DATA_TYPE_RGB  = 0,
		GL_BGR,  // SL_PIXEL_DATA_TYPE_BGR  = 1,
		GL_RGBA, // SL_PIXEL_DATA_TYPE_RGRA = 2,
		GL_BGRA, // SL_PIXEL_DATA_TYPE_BGRA = 3,
	};

	// SLTextureWrapMode to OpenGL wrap mode converter
	static const GLenum cSLTextureWrapModeToGLWrapMode[] =
	{
		GL_CLAMP_TO_EDGE, // SL_TEXTURE_WRAP_MODE_CLAMP  = 0,
		GL_REPEAT,        // SL_TEXTURE_WRAP_MODE_REPEAT = 1,
	};

	// SLTextureFilterimgMode to OpenGL filtering mode
	static const GLenum cSLTextureFilterimgModeToGLFilteringMode[] =
	{
		GL_NEAREST,               // SL_TEXTURE_FILTERING_MODE_NEAREST        = 0,
		GL_LINEAR,                // SL_TEXTURE_FILTERING_MODE_LINEAR         = 1,
		GL_LINEAR_MIPMAP_NEAREST, // SL_TEXTURE_FILTERING_MODE_MIPMAP_NEAREST = 2,
		GL_LINEAR_MIPMAP_LINEAR,  // SL_TEXTURE_FILTERING_MODE_MIPMAP_LENEAR  = 3,
	};

	// SLPrimitiveType to OpenGL primitive type
	static const GLenum cSLPrimitiveTypeToGLPrimitiveMode[] =
	{
		GL_POINTS,         // SL_PRIMITIVE_TYPE_POINT = 0,
		GL_LINES,          // SL_PRIMITIVE_TYPE_LINE = 1,
		GL_LINE_STRIP,     // SL_PRIMITIVE_TYPE_LINE_STRIP = 2,
		GL_TRIANGLES,      // SL_PRIMITIVE_TYPE_TRIANGLE = 3,
		GL_TRIANGLE_STRIP, // SL_PRIMITIVE_TYPE_TRIANGLE_STRIP = 4,
	};

	// GL_VERSION_1_1
	extern PFNGLDRAWARRAYSPROC        glDrawArrays;
	extern PFNGLDRAWELEMENTSPROC      glDrawElements;
	extern PFNGLGETPOINTERVPROC       glGetPointerv;
	extern PFNGLPOLYGONOFFSETPROC     glPolygonOffset;
	extern PFNGLCOPYTEXIMAGE1DPROC    glCopyTexImage1D;
	extern PFNGLCOPYTEXIMAGE2DPROC    glCopyTexImage2D;
	extern PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D;
	extern PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D;
	extern PFNGLTEXSUBIMAGE1DPROC     glTexSubImage1D;
	extern PFNGLTEXSUBIMAGE2DPROC     glTexSubImage2D;
	extern PFNGLBINDTEXTUREPROC       glBindTexture;
	extern PFNGLDELETETEXTURESPROC    glDeleteTextures;
	extern PFNGLGENTEXTURESPROC       glGenTextures;
	extern PFNGLISTEXTUREPROC         glIsTexture;

	// GL_VERSION_1_2
	extern PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
	extern PFNGLTEXIMAGE3DPROC        glTexImage3D;
	extern PFNGLTEXSUBIMAGE3DPROC     glTexSubImage3D;
	extern PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;

	// GL_VERSION_1_3
	extern PFNGLACTIVETEXTUREPROC           glActiveTexture;
	extern PFNGLSAMPLECOVERAGEPROC          glSampleCoverage;
	extern PFNGLCOMPRESSEDTEXIMAGE3DPROC    glCompressedTexImage3D;
	extern PFNGLCOMPRESSEDTEXIMAGE2DPROC    glCompressedTexImage2D;
	extern PFNGLCOMPRESSEDTEXIMAGE1DPROC    glCompressedTexImage1D;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;
	extern PFNGLGETCOMPRESSEDTEXIMAGEPROC   glGetCompressedTexImage;

	// GL_VERSION_1_4
	extern PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
	extern PFNGLMULTIDRAWARRAYSPROC   glMultiDrawArrays;
	extern PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
	extern PFNGLPOINTPARAMETERFPROC   glPointParameterf;
	extern PFNGLPOINTPARAMETERFVPROC  glPointParameterfv;
	extern PFNGLPOINTPARAMETERIPROC   glPointParameteri;
	extern PFNGLPOINTPARAMETERIVPROC  glPointParameteriv;
	extern PFNGLBLENDCOLORPROC        glBlendColor;
	extern PFNGLBLENDEQUATIONPROC     glBlendEquation;

	// GL_VERSION_1_5
	extern PFNGLGENQUERIESPROC           glGenQueries;
	extern PFNGLDELETEQUERIESPROC        glDeleteQueries;
	extern PFNGLISQUERYPROC              glIsQuery;
	extern PFNGLBEGINQUERYPROC           glBeginQuery;
	extern PFNGLENDQUERYPROC             glEndQuery;
	extern PFNGLGETQUERYIVPROC           glGetQueryiv;
	extern PFNGLGETQUERYOBJECTIVPROC     glGetQueryObjectiv;
	extern PFNGLGETQUERYOBJECTUIVPROC    glGetQueryObjectuiv;
	extern PFNGLBINDBUFFERPROC           glBindBuffer;
	extern PFNGLDELETEBUFFERSPROC        glDeleteBuffers;
	extern PFNGLGENBUFFERSPROC           glGenBuffers;
	extern PFNGLISBUFFERPROC             glIsBuffer;
	extern PFNGLBUFFERDATAPROC           glBufferData;
	extern PFNGLBUFFERSUBDATAPROC        glBufferSubData;
	extern PFNGLGETBUFFERSUBDATAPROC     glGetBufferSubData;
	extern PFNGLMAPBUFFERPROC            glMapBuffer;
	extern PFNGLUNMAPBUFFERPROC          glUnmapBuffer;
	extern PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
	extern PFNGLGETBUFFERPOINTERVPROC    glGetBufferPointerv;

	// GL_VERSION_2_0
	extern PFNGLBLENDEQUATIONSEPARATEPROC    glBlendEquationSeparate;
	extern PFNGLDRAWBUFFERSPROC              glDrawBuffers;
	extern PFNGLSTENCILOPSEPARATEPROC        glStencilOpSeparate;
	extern PFNGLSTENCILFUNCSEPARATEPROC      glStencilFuncSeparate;
	extern PFNGLSTENCILMASKSEPARATEPROC      glStencilMaskSeparate;
	extern PFNGLATTACHSHADERPROC             glAttachShader;
	extern PFNGLBINDATTRIBLOCATIONPROC       glBindAttribLocation;
	extern PFNGLCOMPILESHADERPROC            glCompileShader;
	extern PFNGLCREATEPROGRAMPROC            glCreateProgram;
	extern PFNGLCREATESHADERPROC             glCreateShader;
	extern PFNGLDELETEPROGRAMPROC            glDeleteProgram;
	extern PFNGLDELETESHADERPROC             glDeleteShader;
	extern PFNGLDETACHSHADERPROC             glDetachShader;
	extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
	extern PFNGLENABLEVERTEXATTRIBARRAYPROC  glEnableVertexAttribArray;
	extern PFNGLGETACTIVEATTRIBPROC          glGetActiveAttrib;
	extern PFNGLGETACTIVEUNIFORMPROC         glGetActiveUniform;
	extern PFNGLGETATTACHEDSHADERSPROC       glGetAttachedShaders;
	extern PFNGLGETATTRIBLOCATIONPROC        glGetAttribLocation;
	extern PFNGLGETPROGRAMIVPROC             glGetProgramiv;
	extern PFNGLGETPROGRAMINFOLOGPROC        glGetProgramInfoLog;
	extern PFNGLGETSHADERIVPROC              glGetShaderiv;
	extern PFNGLGETSHADERINFOLOGPROC         glGetShaderInfoLog;
	extern PFNGLGETSHADERSOURCEPROC          glGetShaderSource;
	extern PFNGLGETUNIFORMLOCATIONPROC       glGetUniformLocation;
	extern PFNGLGETUNIFORMFVPROC             glGetUniformfv;
	extern PFNGLGETUNIFORMIVPROC             glGetUniformiv;
	extern PFNGLGETVERTEXATTRIBDVPROC        glGetVertexAttribdv;
	extern PFNGLGETVERTEXATTRIBFVPROC        glGetVertexAttribfv;
	extern PFNGLGETVERTEXATTRIBIVPROC        glGetVertexAttribiv;
	extern PFNGLGETVERTEXATTRIBPOINTERVPROC  glGetVertexAttribPointerv;
	extern PFNGLISPROGRAMPROC                glIsProgram;
	extern PFNGLISSHADERPROC                 glIsShader;
	extern PFNGLLINKPROGRAMPROC              glLinkProgram;
	extern PFNGLSHADERSOURCEPROC             glShaderSource;
	extern PFNGLUSEPROGRAMPROC               glUseProgram;
	extern PFNGLUNIFORM1FPROC                glUniform1f;
	extern PFNGLUNIFORM2FPROC                glUniform2f;
	extern PFNGLUNIFORM3FPROC                glUniform3f;
	extern PFNGLUNIFORM4FPROC                glUniform4f;
	extern PFNGLUNIFORM1IPROC                glUniform1i;
	extern PFNGLUNIFORM2IPROC                glUniform2i;
	extern PFNGLUNIFORM3IPROC                glUniform3i;
	extern PFNGLUNIFORM4IPROC                glUniform4i;
	extern PFNGLUNIFORM1FVPROC               glUniform1fv;
	extern PFNGLUNIFORM2FVPROC               glUniform2fv;
	extern PFNGLUNIFORM3FVPROC               glUniform3fv;
	extern PFNGLUNIFORM4FVPROC               glUniform4fv;
	extern PFNGLUNIFORM1IVPROC               glUniform1iv;
	extern PFNGLUNIFORM2IVPROC               glUniform2iv;
	extern PFNGLUNIFORM3IVPROC               glUniform3iv;
	extern PFNGLUNIFORM4IVPROC               glUniform4iv;
	extern PFNGLUNIFORMMATRIX2FVPROC         glUniformMatrix2fv;
	extern PFNGLUNIFORMMATRIX3FVPROC         glUniformMatrix3fv;
	extern PFNGLUNIFORMMATRIX4FVPROC         glUniformMatrix4fv;
	extern PFNGLVALIDATEPROGRAMPROC          glValidateProgram;
	extern PFNGLVERTEXATTRIB1DPROC           glVertexAttrib1d;
	extern PFNGLVERTEXATTRIB1DVPROC          glVertexAttrib1dv;
	extern PFNGLVERTEXATTRIB1FPROC           glVertexAttrib1f;
	extern PFNGLVERTEXATTRIB1FVPROC          glVertexAttrib1fv;
	extern PFNGLVERTEXATTRIB1SPROC           glVertexAttrib1s;
	extern PFNGLVERTEXATTRIB1SVPROC          glVertexAttrib1sv;
	extern PFNGLVERTEXATTRIB2DPROC           glVertexAttrib2d;
	extern PFNGLVERTEXATTRIB2DVPROC          glVertexAttrib2dv;
	extern PFNGLVERTEXATTRIB2FPROC           glVertexAttrib2f;
	extern PFNGLVERTEXATTRIB2FVPROC          glVertexAttrib2fv;
	extern PFNGLVERTEXATTRIB2SPROC           glVertexAttrib2s;
	extern PFNGLVERTEXATTRIB2SVPROC          glVertexAttrib2sv;
	extern PFNGLVERTEXATTRIB3DPROC           glVertexAttrib3d;
	extern PFNGLVERTEXATTRIB3DVPROC          glVertexAttrib3dv;
	extern PFNGLVERTEXATTRIB3FPROC           glVertexAttrib3f;
	extern PFNGLVERTEXATTRIB3FVPROC          glVertexAttrib3fv;
	extern PFNGLVERTEXATTRIB3SPROC           glVertexAttrib3s;
	extern PFNGLVERTEXATTRIB3SVPROC          glVertexAttrib3sv;
	extern PFNGLVERTEXATTRIB4NBVPROC         glVertexAttrib4Nbv;
	extern PFNGLVERTEXATTRIB4NIVPROC         glVertexAttrib4Niv;
	extern PFNGLVERTEXATTRIB4NSVPROC         glVertexAttrib4Nsv;
	extern PFNGLVERTEXATTRIB4NUBPROC         glVertexAttrib4Nub;
	extern PFNGLVERTEXATTRIB4NUBVPROC        glVertexAttrib4Nubv;
	extern PFNGLVERTEXATTRIB4NUIVPROC        glVertexAttrib4Nuiv;
	extern PFNGLVERTEXATTRIB4NUSVPROC        glVertexAttrib4Nusv;
	extern PFNGLVERTEXATTRIB4BVPROC          glVertexAttrib4bv;
	extern PFNGLVERTEXATTRIB4DPROC           glVertexAttrib4d;
	extern PFNGLVERTEXATTRIB4DVPROC          glVertexAttrib4dv;
	extern PFNGLVERTEXATTRIB4FPROC           glVertexAttrib4f;
	extern PFNGLVERTEXATTRIB4FVPROC          glVertexAttrib4fv;
	extern PFNGLVERTEXATTRIB4IVPROC          glVertexAttrib4iv;
	extern PFNGLVERTEXATTRIB4SPROC           glVertexAttrib4s;
	extern PFNGLVERTEXATTRIB4SVPROC          glVertexAttrib4sv;
	extern PFNGLVERTEXATTRIB4UBVPROC         glVertexAttrib4ubv;
	extern PFNGLVERTEXATTRIB4UIVPROC         glVertexAttrib4uiv;
	extern PFNGLVERTEXATTRIB4USVPROC         glVertexAttrib4usv;
	extern PFNGLVERTEXATTRIBPOINTERPROC      glVertexAttribPointer;

	// GL_VERSION_2_1
	extern PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
	extern PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
	extern PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
	extern PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
	extern PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
	extern PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;

	// init OpenGL 2.1
	extern void InitOpenGL2();
}