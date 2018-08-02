#include "SLShaderManager_GL2.hpp"
#include "SLShaderSources_GL2.hpp"

namespace SLR_GL2 {
	// SLShaderManager_GL2
	SLShaderManager_GL2::SLShaderManager_GL2()
	{
	}

	// ~SLShaderManager_GL2
	SLShaderManager_GL2::~SLShaderManager_GL2()
	{
	}

	// SetRenderer
	void SLShaderManager_GL2::SetRenderer(ISLRenderer * renderer)
	{
		mRenderer = renderer;
	}

	// GetRenderer
	ISLRenderer* SLShaderManager_GL2::GetRenderer() const
	{
		return mRenderer;
	}

	// GetDefaultShader
	SLShader_GL2 * SLShaderManager_GL2::GetDefaultShader()
	{
		return &mShader_PositionColor;
	}

	void SLShaderManager_GL2::CreateShaders()
	{
		// create all shaders
		mShader_PositionColor.CreateShader(cVSShaderSource_PositionColorTexCoords, cFSShaderSource_PositionColorTexCoords);
	}

	void SLShaderManager_GL2::DeleteShaders()
	{
		// delete add shaders
		mShader_PositionColor.DeleteShader();
	}
}