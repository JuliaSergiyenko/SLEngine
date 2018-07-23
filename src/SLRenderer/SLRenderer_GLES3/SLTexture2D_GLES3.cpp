#include "SLTexture2D_GLES3.hpp"

namespace SLR_GLES3
{
	// SLTexture2D_GLES3
	SLTexture2D_GLES3::SLTexture2D_GLES3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLTexture2D_GLES3
	SLTexture2D_GLES3::~SLTexture2D_GLES3()
	{
	}

	// GetRenderer
	ISLRenderer* SLTexture2D_GLES3::GetRenderer() const
	{
		return mRenderer;
	}

	// SetWrapModeS
	void SLTexture2D_GLES3::SetWrapModeS(SLTextureWrapMode wrapMode)
	{
		mWrapModeS = wrapMode;
	}

	// SetWrapModeT
	void SLTexture2D_GLES3::SetWrapModeT(SLTextureWrapMode wrapMode)
	{
		mWrapModeT = wrapMode;
	}

	// SetFilterimgMode
	void SLTexture2D_GLES3::SetFilterimgMode(SLTextureFilterimgMode filterimgMode)
	{
		mFilterimgMode = filterimgMode;
	}

	// GetWrapModeS
	SLTextureWrapMode SLTexture2D_GLES3::GetWrapModeS() const
	{
		return mWrapModeS;
	}

	// GetWrapModeT
	SLTextureWrapMode SLTexture2D_GLES3::GetWrapModeT() const
	{
		return mWrapModeT;
	}

	// GetFilterimgMode
	SLTextureFilterimgMode SLTexture2D_GLES3::GetFilterimgMode() const
	{
		return mFilterimgMode;
	}
}
