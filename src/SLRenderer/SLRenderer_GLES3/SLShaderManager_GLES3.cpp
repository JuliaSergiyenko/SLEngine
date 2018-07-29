#include "SLShaderManager_GLES3.hpp"
#include "SLShaderSources_GLES3.hpp"

namespace SLR_GLES3 {
	// SLShaderManager_GLES3
	SLShaderManager_GLES3::SLShaderManager_GLES3()
	{
	}

	// ~SLShaderManager_GLES3
	SLShaderManager_GLES3::~SLShaderManager_GLES3()
	{
	}

	// SetRenderer
	void SLShaderManager_GLES3::SetRenderer(ISLRenderer * renderer)
	{
		mRenderer = renderer;
	}

	// GetRenderer
	ISLRenderer* SLShaderManager_GLES3::GetRenderer() const
	{
		return mRenderer;
	}

	// GetDefaultShader
	SLShader_GLES3 * SLShaderManager_GLES3::GetDefaultShader()
	{
		return &mShader_PositionColor;
	}

	void SLShaderManager_GLES3::CreateShaders()
	{
		// create all shaders
		mShader_PositionColor.CreateShader(cVSShaderSource_PositionColor, cFSShaderSource_PositionColor);
	}

	void SLShaderManager_GLES3::DeleteShaders()
	{
		// delete add shaders
		mShader_PositionColor.DeleteShader();
	}
}