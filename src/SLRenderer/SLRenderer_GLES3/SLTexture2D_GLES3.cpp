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

	// UpdateImage
	void SLTexture2D_GLES3::UpdateImage(uint8_t * data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
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
