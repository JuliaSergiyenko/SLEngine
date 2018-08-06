#include "SLShaderManager_GLES2.hpp"
#include "SLShaderSources_GLES2.hpp"

namespace SLR_GLES2 {
	// SLShaderManager_GLES2
	SLShaderManager_GLES2::SLShaderManager_GLES2()
	{
	}

	// ~SLShaderManager_GLES2
	SLShaderManager_GLES2::~SLShaderManager_GLES2()
	{
	}

	// SetRenderer
	void SLShaderManager_GLES2::SetRenderer(ISLRenderer * renderer)
	{
		mRenderer = renderer;
	}

	// GetRenderer
	ISLRenderer* SLShaderManager_GLES2::GetRenderer() const
	{
		return mRenderer;
	}

	// GetDefaultShader
	SLShader_GLES2 * SLShaderManager_GLES2::GetDefaultShader()
	{
		return &mShader_PositionColor;
	}

	void SLShaderManager_GLES2::CreateShaders()
	{
		// create all shaders
		mShader_PositionColor.CreateShader(cVSShaderSource_PositionColorNormalTexCoords, cFSShaderSource_PositionColorNormalTexCoords);
	}

	void SLShaderManager_GLES2::DeleteShaders()
	{
		// delete add shaders
		mShader_PositionColor.DeleteShader();
	}
}