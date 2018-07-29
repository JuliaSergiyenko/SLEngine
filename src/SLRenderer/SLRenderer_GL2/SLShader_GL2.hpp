#pragma once
#include "SLOpenGL2.hpp"

// SLR_GL2
namespace SLR_GL2
{
	// SLShader_GL2
	class SLShader_GL2
	{
	public:
		// OpenGL handles and settings
		GLuint mGLVertexShader = 0;
		GLuint mGLFragmentShader = 0;
		GLuint mGLProgram = 0;

		// uniform locations
		GLint mGLModelMatUniformLoc = -1;
		GLint mGLViewMatUniformLoc = -1;
		GLint mGLProjMatUniformLoc = -1;
	public:
		// constructor and destructor
		SLShader_GL2();
		~SLShader_GL2();

		// create shader
		bool CreateShader(const char* vertexSource, const char* fragmentSource);
		void DeleteShader();
	
		// status check functions
		static bool ShaderStatusCheck(GLuint shader);
		static bool ProgramStatusCheck(GLuint program);
	};
}