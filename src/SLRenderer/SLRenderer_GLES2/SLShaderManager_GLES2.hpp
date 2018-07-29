#pragma once
#include "SLShader_GLES2.hpp"

// SLR_GLES2
namespace SLR_GLES2
{
	// SLShaderManager_GLES2
	class SLShaderManager_GLES2
	{
	private:
		// renderer
		ISLRenderer * mRenderer = nullptr;

		// shaders
		SLShader_GLES2 mShader_PositionColor;
	public:
		// constructor and destructor
		SLShaderManager_GLES2();
		~SLShaderManager_GLES2();

		// set and get renderer
		void SetRenderer(ISLRenderer * renderer);
		ISLRenderer* GetRenderer() const;

		// get shader
		SLShader_GLES2* GetDefaultShader();

		// shaders functions
		void CreateShaders();
		void DeleteShaders();
	};
}