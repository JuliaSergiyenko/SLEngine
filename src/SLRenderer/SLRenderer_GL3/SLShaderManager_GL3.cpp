#include "SLShaderManager_GL3.hpp"
#include "SLShaderSources_GL3.hpp"

namespace SLR_GL3 {
	// SLShaderManager_GL3
	SLShaderManager_GL3::SLShaderManager_GL3()
	{
	}

	// ~SLShaderManager_GL3
	SLShaderManager_GL3::~SLShaderManager_GL3()
	{
	}

	// SetRenderer
	void SLShaderManager_GL3::SetRenderer(ISLRenderer * renderer)
	{
		mRenderer = renderer;
	}

	// GetRenderer
	ISLRenderer* SLShaderManager_GL3::GetRenderer() const
	{
		return mRenderer;
	}

	// GetDefaultShader
	SLShader_GL3 * SLShaderManager_GL3::GetDefaultShader()
	{
		return &mShader_PositionColor;
	}

	void SLShaderManager_GL3::CreateShaders()
	{
		// create all shaders
		mShader_PositionColor.CreateShader(cVSShaderSource_PositionColorNormalTexCoords, cFSShaderSource_PositionColorNormalTexCoords);
	}

	void SLShaderManager_GL3::DeleteShaders()
	{
		// delete add shaders
		mShader_PositionColor.DeleteShader();
	}
}