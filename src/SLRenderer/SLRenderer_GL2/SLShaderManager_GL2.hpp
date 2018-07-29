#pragma once
#include "SLShader_GL2.hpp"

// SLR_GL2
namespace SLR_GL2
{
	// SLShaderManager_GL2
	class SLShaderManager_GL2
	{
	private:
		// renderer
		ISLRenderer * mRenderer = nullptr;

		// shaders
		SLShader_GL2 mShader_PositionColor;
	public:
		// constructor and destructor
		SLShaderManager_GL2();
		~SLShaderManager_GL2();

		// set and get renderer
		void SetRenderer(ISLRenderer * renderer);
		ISLRenderer* GetRenderer() const;

		// get shader
		SLShader_GL2* GetDefaultShader();

		// shaders functions
		void CreateShaders();
		void DeleteShaders();
	};
}