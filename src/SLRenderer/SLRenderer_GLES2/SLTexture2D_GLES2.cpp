#include "SLTexture2D_GLES2.hpp"

namespace SLR_GLES2
{
	// SLTexture2D_GLES2
	SLTexture2D_GLES2::SLTexture2D_GLES2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLTexture2D_GLES2
	SLTexture2D_GLES2::~SLTexture2D_GLES2()
	{
	}

	// GetRenderer
	ISLRenderer* SLTexture2D_GLES2::GetRenderer() const
	{
		return mRenderer;
	}

	// SetWrapModeS
	void SLTexture2D_GLES2::SetWrapModeS(SLTextureWrapMode wrapMode)
	{
		mWrapModeS = wrapMode;
	}

	// SetWrapModeT
	void SLTexture2D_GLES2::SetWrapModeT(SLTextureWrapMode wrapMode)
	{
		mWrapModeT = wrapMode;
	}

	// SetFilterimgMode
	void SLTexture2D_GLES2::SetFilterimgMode(SLTextureFilterimgMode filterimgMode)
	{
		mFilterimgMode = filterimgMode;
	}

	// GetWrapModeS
	SLTextureWrapMode SLTexture2D_GLES2::GetWrapModeS() const
	{
		return mWrapModeS;
	}

	// GetWrapModeT
	SLTextureWrapMode SLTexture2D_GLES2::GetWrapModeT() const
	{
		return mWrapModeT;
	}

	// GetFilterimgMode
	SLTextureFilterimgMode SLTexture2D_GLES2::GetFilterimgMode() const
	{
		return mFilterimgMode;
	}
}
