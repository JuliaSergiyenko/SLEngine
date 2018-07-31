#pragma once
#include "SLOpenGL3.hpp"

// SLR_GL3
namespace SLR_GL3
{
	// SLShader_GL3
	class SLShader_GL3
	{
	public:
		// OpenGL handles and settings
		GLuint mGLVertexShader = 0;
		GLuint mGLFragmentShader = 0;
		GLuint mGLProgram = 0;

		// OpenGL attributes locations
		GLint mGLPositionAttributeLoc = -1;
		GLint mGLColorAttributeLoc = -1;
		GLint mGLNormalAttributeLoc = -1;
		GLint mGLTangentAttributeLoc = -1;
		GLint mGLTexCoordAttributeLoc = -1;
		GLint mGLWeightsAttributeLoc = -1;

		// OpenGL texture uniforms locations
		GLint mGLBaseTextureUniformLoc = -1;
		GLint mGLDetailTextureUniformLoc = -1;
		GLint mGLNormalTextureUniformLoc = -1;

		// OpenGL uniform locations
		GLint mGLModelMatUniformLoc = -1;
		GLint mGLViewMatUniformLoc = -1;
		GLint mGLProjMatUniformLoc = -1;
	public:
		// constructor and destructor
		SLShader_GL3();
		~SLShader_GL3();

		// create shader
		bool CreateShader(const char* vertexSource, const char* fragmentSource);
		void DeleteShader();
	
		// status check functions
		static bool ShaderStatusCheck(GLuint shader);
		static bool ProgramStatusCheck(GLuint program);
	};
}