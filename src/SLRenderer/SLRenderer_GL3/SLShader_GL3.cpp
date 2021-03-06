#pragma once
#include <iostream>
#include <vector>
#include "SLShader_GL3.hpp"

// SLR_GL3
namespace SLR_GL3
{
	// SLShader_GL3()
	SLShader_GL3::SLShader_GL3()
	{
	}

	// ~SLShader_GL3()
	SLShader_GL3::~SLShader_GL3()
	{
		// simply delete shader
		DeleteShader();
	}

	// create CreateShader
	bool SLShader_GL3::CreateShader(const char* vertexSource, const char* fragmentSource)
	{
		// create and compile vertex shader
		mGLVertexShader = GL_CHECK(glCreateShader(GL_VERTEX_SHADER));
		GL_CHECK(glShaderSource(mGLVertexShader, 1, &vertexSource, nullptr));
		GL_CHECK(glCompileShader(mGLVertexShader));
		if (!ShaderStatusCheck(mGLVertexShader))
		{
			GL_CHECK(glDeleteProgram(mGLVertexShader));
			mGLVertexShader = 0;
			return false;
		}

		// create and compile fragment shader
		mGLFragmentShader = GL_CHECK(glCreateShader(GL_FRAGMENT_SHADER));
		GL_CHECK(glShaderSource(mGLFragmentShader, 1, &fragmentSource, nullptr));
		GL_CHECK(glCompileShader(mGLFragmentShader));
		if (!ShaderStatusCheck(mGLFragmentShader))
		{
			GL_CHECK(glDeleteShader(mGLFragmentShader));
			GL_CHECK(glDeleteShader(mGLVertexShader));
			mGLFragmentShader = 0;
			mGLVertexShader = 0;
			return false;
		}

		// attach programs
		mGLProgram = GL_CHECK(glCreateProgram());
		GL_CHECK(glAttachShader(mGLProgram, mGLVertexShader));
		GL_CHECK(glAttachShader(mGLProgram, mGLFragmentShader));

		// link program
		GL_CHECK(glLinkProgram(mGLProgram));
		if (!ProgramStatusCheck(mGLProgram))
		{
			GL_CHECK(glDeleteProgram(mGLProgram));
			GL_CHECK(glDeleteProgram(mGLFragmentShader));
			GL_CHECK(glDeleteShader(mGLVertexShader));
			mGLProgram = 0;
			mGLFragmentShader = 0;
			mGLVertexShader = 0;
			return false;
		}

		// use program
		GL_CHECK(glUseProgram(mGLProgram));

		// get attributes location
		mGLPositionAttributeLoc = GL_CHECK(glGetAttribLocation(mGLProgram, "aPosition"));
		mGLColorAttributeLoc = GL_CHECK(glGetAttribLocation(mGLProgram, "aColor"));
		mGLNormalAttributeLoc = GL_CHECK(glGetAttribLocation(mGLProgram, "aNormal"));
		mGLTangentAttributeLoc = GL_CHECK(glGetAttribLocation(mGLProgram, "aTangent"));
		mGLTexCoordAttributeLoc = GL_CHECK(glGetAttribLocation(mGLProgram, "aTexCoord"));
		mGLWeightsAttributeLoc = GL_CHECK(glGetAttribLocation(mGLProgram, "aWeights"));

		// get texture units
		mGLBaseTextureUniformLoc = GL_CHECK(glGetUniformLocation(mGLProgram, "sBaseTexture"));
		mGLDetailTextureUniformLoc = GL_CHECK(glGetUniformLocation(mGLProgram, "sDetailTexture"));
		mGLNormalTextureUniformLoc = GL_CHECK(glGetUniformLocation(mGLProgram, "sNormalTexture"));

		// set texture location
		GL_CHECK(glUniform1i(mGLBaseTextureUniformLoc, cSLTextureUnit_Base));
		GL_CHECK(glUniform1i(mGLDetailTextureUniformLoc, cSLTextureUnit_Detail));
		GL_CHECK(glUniform1i(mGLNormalTextureUniformLoc, cSLTextureUnit_Normal));

		// get uniforms location
		mGLModelMatUniformLoc = GL_CHECK(glGetUniformLocation(mGLProgram, "uModelMat"));
		mGLViewMatUniformLoc = GL_CHECK(glGetUniformLocation(mGLProgram, "uViewMat"));
		mGLProjMatUniformLoc = GL_CHECK(glGetUniformLocation(mGLProgram, "uProjMat"));

		// unuse program
		GL_CHECK(glUseProgram(0));

		return true;
	}

	void SLShader_GL3::DeleteShader()
	{
		// delete shaders and program handle
		GL_CHECK(glDeleteProgram(mGLProgram));
		GL_CHECK(glDeleteShader(mGLFragmentShader));
		GL_CHECK(glDeleteShader(mGLVertexShader));
		mGLProgram = 0;
		mGLFragmentShader = 0;
		mGLVertexShader = 0;
	}

	// shader statuc check
	bool SLShader_GL3::ShaderStatusCheck(GLuint shader)
	{
		GLint isCompiled = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			// get max length of info log
			GLsizei maxLength = 0;
			GLsizei length = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

			// maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(shader, maxLength, &length, &infoLog[0]);
			std::cerr << infoLog.data() << std::endl;

			// Provide the infolog in whatever manner you deem best.
			// Exit with failure.
			return false;
		}
		return true;
	}

	// ProgramStatusCheck
	bool SLShader_GL3::ProgramStatusCheck(GLuint program)
	{
		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
		if (isLinked == GL_FALSE)
		{
			// get max length of info log
			GLint maxLength = 0;
			GLsizei length = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &length, &infoLog[0]);
			std::cerr << infoLog.data() << std::endl;

			// Provide the infolog in whatever manner you deem best.
			// Exit with failure.
			return false;
		}
		return true;
	}
}