#pragma once
#include "SLShader_GL4.hpp"

// SLR_GL4
namespace SLR_GL4
{
	// SLShaderManager_GL4
	class SLShaderManager_GL4
	{
	private:
		// renderer
		ISLRenderer * mRenderer = nullptr;

		// shaders
		SLShader_GL4 mShader_PositionColor;
	public:
		// constructor and destructor
		SLShaderManager_GL4();
		~SLShaderManager_GL4();

		// set and get renderer
		void SetRenderer(ISLRenderer * renderer);
		ISLRenderer* GetRenderer() const;

		// get shader
		SLShader_GL4* GetDefaultShader();

		// shaders functions
		void CreateShaders();
		void DeleteShaders();
	};
}