#include "SLShaderManager_GL4.hpp"
#include "SLShaderSources_GL4.hpp"

namespace SLR_GL4 {
	// SLShaderManager_GL4
	SLShaderManager_GL4::SLShaderManager_GL4()
	{
	}

	// ~SLShaderManager_GL4
	SLShaderManager_GL4::~SLShaderManager_GL4()
	{
	}

	// SetRenderer
	void SLShaderManager_GL4::SetRenderer(ISLRenderer * renderer)
	{
		mRenderer = renderer;
	}

	// GetRenderer
	ISLRenderer* SLShaderManager_GL4::GetRenderer() const
	{
		return mRenderer;
	}

	// GetDefaultShader
	SLShader_GL4 * SLShaderManager_GL4::GetDefaultShader()
	{
		return &mShader_PositionColor;
	}

	void SLShaderManager_GL4::CreateShaders()
	{
		// create all shaders
		mShader_PositionColor.CreateShader(cVSShaderSource_PositionColorNormalTexCoords, cFSShaderSource_PositionColorNormalTexCoords);
	}

	void SLShaderManager_GL4::DeleteShaders()
	{
		// delete add shaders
		mShader_PositionColor.DeleteShader();
	}
}