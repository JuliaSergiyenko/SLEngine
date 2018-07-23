#include "SLTexture2D_GL4.hpp"

namespace SLR_GL4
{
	// SLTexture2D_GL4
	SLTexture2D_GL4::SLTexture2D_GL4(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLTexture2D_GL4
	SLTexture2D_GL4::~SLTexture2D_GL4()
	{
	}

	// GetRenderer
	ISLRenderer* SLTexture2D_GL4::GetRenderer() const
	{
		return mRenderer;
	}

	// SetWrapModeS
	void SLTexture2D_GL4::SetWrapModeS(SLTextureWrapMode wrapMode)
	{
		mWrapModeS = wrapMode;
	}

	// SetWrapModeT
	void SLTexture2D_GL4::SetWrapModeT(SLTextureWrapMode wrapMode)
	{
		mWrapModeT = wrapMode;
	}

	// SetFilterimgMode
	void SLTexture2D_GL4::SetFilterimgMode(SLTextureFilterimgMode filterimgMode)
	{
		mFilterimgMode = filterimgMode;
	}

	// GetWrapModeS
	SLTextureWrapMode SLTexture2D_GL4::GetWrapModeS() const
	{
		return mWrapModeS;
	}

	// GetWrapModeT
	SLTextureWrapMode SLTexture2D_GL4::GetWrapModeT() const
	{
		return mWrapModeT;
	}

	// GetFilterimgMode
	SLTextureFilterimgMode SLTexture2D_GL4::GetFilterimgMode() const
	{
		return mFilterimgMode;
	}
}
