#include "SLTexture2D_GL3.hpp"

namespace SLR_GL3
{
	// SLTexture2D_GL3
	SLTexture2D_GL3::SLTexture2D_GL3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLTexture2D_GL3
	SLTexture2D_GL3::~SLTexture2D_GL3()
	{
	}

	// GetRenderer
	ISLRenderer* SLTexture2D_GL3::GetRenderer() const
	{
		return mRenderer;
	}

	// SetWrapModeS
	void SLTexture2D_GL3::SetWrapModeS(SLTextureWrapMode wrapMode)
	{
		mWrapModeS = wrapMode;
	}

	// SetWrapModeT
	void SLTexture2D_GL3::SetWrapModeT(SLTextureWrapMode wrapMode)
	{
		mWrapModeT = wrapMode;
	}

	// SetFilterimgMode
	void SLTexture2D_GL3::SetFilterimgMode(SLTextureFilterimgMode filterimgMode)
	{
		mFilterimgMode = filterimgMode;
	}

	// GetWrapModeS
	SLTextureWrapMode SLTexture2D_GL3::GetWrapModeS() const
	{
		return mWrapModeS;
	}

	// GetWrapModeT
	SLTextureWrapMode SLTexture2D_GL3::GetWrapModeT() const
	{
		return mWrapModeT;
	}

	// GetFilterimgMode
	SLTextureFilterimgMode SLTexture2D_GL3::GetFilterimgMode() const
	{
		return mFilterimgMode;
	}
}
