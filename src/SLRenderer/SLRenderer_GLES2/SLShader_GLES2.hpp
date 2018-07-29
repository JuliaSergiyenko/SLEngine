#pragma once
#include "SLOpenGLES2.hpp"

// SLR_GLES2
namespace SLR_GLES2
{
	// SLShader_GLES2
	class SLShader_GLES2
	{
	public:
		// OpenGL handles and settings
		GLuint mGLVertexShader = 0;
		GLuint mGLFragmentShader = 0;
		GLuint mGLProgram = 0;

		// attributes locations
		GLint mGLPositionAttributeLoc = -1;
		GLint mGLColorAttributeLoc = -1;

		// uniform locations
		GLint mGLModelMatUniformLoc = -1;
		GLint mGLViewMatUniformLoc = -1;
		GLint mGLProjMatUniformLoc = -1;
	public:
		// constructor and destructor
		SLShader_GLES2();
		~SLShader_GLES2();

		// create shader
		bool CreateShader(const char* vertexSource, const char* fragmentSource);
		void DeleteShader();
	
		// status check functions
		static bool ShaderStatusCheck(GLuint shader);
		static bool ProgramStatusCheck(GLuint program);
	};
}