#pragma once
#include "../SLRenderer.hpp"
#include "SLShader_GL3.hpp"

// SLR_GL3
namespace SLR_GL3
{
	// SLShaderManager_GL3
	class SLShaderManager_GL3
	{
	private:
		// renderer
		ISLRenderer * mRenderer = nullptr;

		// shaders
		SLShader_GL3 mShader_PositionColor;
	public:
		// constructor and destructor
		SLShaderManager_GL3();
		~SLShaderManager_GL3();

		// set and get renderer
		void SetRenderer(ISLRenderer * renderer);
		ISLRenderer* GetRenderer() const;

		// get shader
		SLShader_GL3* GetDefaultShader();

		// shaders functions
		void CreateShaders();
		void DeleteShaders();
	};
}