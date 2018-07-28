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