#pragma once
#include "SLShader_GLES3.hpp"

// SLR_GLES3
namespace SLR_GLES3
{
	// SLShaderManager_GLES3
	class SLShaderManager_GLES3
	{
	private:
		// renderer
		ISLRenderer * mRenderer = nullptr;

		// shaders
		SLShader_GLES3 mShader_PositionColor;
	public:
		// constructor and destructor
		SLShaderManager_GLES3();
		~SLShaderManager_GLES3();

		// set and get renderer
		void SetRenderer(ISLRenderer * renderer);
		ISLRenderer* GetRenderer() const;

		// get shader
		SLShader_GLES3* GetDefaultShader();

		// shaders functions
		void CreateShaders();
		void DeleteShaders();
	};
}