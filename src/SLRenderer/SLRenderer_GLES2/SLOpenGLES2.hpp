#pragma once

#include <cassert>
#include <GLES2/gl2.h>
#include "../SLRenderer.hpp"

// OpenGL check error defines
#ifdef _DEBUG
#define GL_CHECK(stmt) stmt; assert(glGetError() == GL_NO_ERROR);
#else
#define GL_CHECK(stmt) stmt
#endif

// SLR_GLES2
namespace SLR_GLES2
{
	// OpenGL vertex attribute locations
	static const GLuint cSLVertexAttribLication_Position = 0;
	static const GLuint cSLVertexAttribLication_Color = 1;
	static const GLuint cSLVertexAttribLication_Normal = 2;
	static const GLuint cSLVertexAttribLication_Tangent = 3;
	static const GLuint cSLVertexAttribLication_TexCoord = 4;
	static const GLuint cSLVertexAttribLication_Weights = 5;

	// OpenGL texture units
	static const GLint cSLTextureUnit_Base = 0;
	static const GLint cSLTextureUnit_Detail = 1;
	static const GLint cSLTextureUnit_Normal = 2;

	// SLPixelDataType to OpenGL format converter
	static const GLenum cSLPixelDataTypeToGLFormat[] = {
		GL_RGB,  // SL_PIXEL_DATA_TYPE_RGB  = 0,
		GL_RGB,  // SL_PIXEL_DATA_TYPE_BGR  = 1,
		GL_RGBA, // SL_PIXEL_DATA_TYPE_RGRA = 2,
		GL_RGBA, // SL_PIXEL_DATA_TYPE_BGRA = 3,
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
}