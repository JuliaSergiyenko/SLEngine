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

	// UpdateImage
	void SLTexture2D_GLES2::UpdateImage(uint8_t * data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
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

	// SetFilteringMode
	void SLTexture2D_GLES2::SetFilteringMode(SLTextureFilterimgMode filterimgMode)
	{
		mFilteringMode = filterimgMode;
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
		return mFilteringMode;
	}
}
