#include "SLTexture2D_GL2.hpp"

namespace SLR_GL2
{
	// SLTexture2D_GL2
	SLTexture2D_GL2::SLTexture2D_GL2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLTexture2D_GL2
	SLTexture2D_GL2::~SLTexture2D_GL2()
	{
	}

	// GetRenderer
	ISLRenderer* SLTexture2D_GL2::GetRenderer() const
	{
		return mRenderer;
	}

	// SetWrapModeS
	void SLTexture2D_GL2::SetWrapModeS(SLTextureWrapMode wrapMode)
	{
		mWrapModeS = wrapMode;
	}

	// SetWrapModeT
	void SLTexture2D_GL2::SetWrapModeT(SLTextureWrapMode wrapMode)
	{
		mWrapModeT = wrapMode;
	}

	// SetFilterimgMode
	void SLTexture2D_GL2::SetFilterimgMode(SLTextureFilterimgMode filterimgMode)
	{
		mFilterimgMode = filterimgMode;
	}

	// GetWrapModeS
	SLTextureWrapMode SLTexture2D_GL2::GetWrapModeS() const
	{
		return mWrapModeS;
	}

	// GetWrapModeT
	SLTextureWrapMode SLTexture2D_GL2::GetWrapModeT() const
	{
		return mWrapModeT;
	}

	// GetFilterimgMode
	SLTextureFilterimgMode SLTexture2D_GL2::GetFilterimgMode() const
	{
		return mFilterimgMode;
	}
}
