#include "SLTexture2D_GL2.hpp"

// SLR_GL2
namespace SLR_GL2
{
	// SLTexture2D_GL2
	SLTexture2D_GL2::SLTexture2D_GL2(ISLRenderer* renderer) : mRenderer(renderer)
	{
		// create texture handle
		GL_CHECK(glGenTextures(1, &mGLTextureHadle));
		GL_CHECK(glBindTexture(GL_TEXTURE_2D, mGLTextureHadle));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mGLWrapModeS));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mGLWrapModeT));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mGLMinFilteringMode));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mGLMagFilteringMode));
		GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
	}

	// ~SLTexture2D_GL2
	SLTexture2D_GL2::~SLTexture2D_GL2()
	{
		// delete handles
		GL_CHECK(glDeleteTextures(1, &mGLTextureHadle));
	}

	// GetRenderer
	ISLRenderer* SLTexture2D_GL2::GetRenderer() const
	{
		return mRenderer;
	}

	// UpdateImage
	void SLTexture2D_GL2::UpdateImage(uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		// update texture image by layer
		GL_CHECK(glBindTexture(GL_TEXTURE_2D, mGLTextureHadle));
		GL_CHECK(glTexImage2D(GL_TEXTURE_2D, mipLevel, cSLPixelDataTypeToGLFormat[pixelDataType], width, height, 0, cSLPixelDataTypeToGLFormat[pixelDataType], GL_UNSIGNED_BYTE, data));
		GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
	}

	// SetWrapModeS
	void SLTexture2D_GL2::SetWrapModeS(SLTextureWrapMode wrapMode)
	{
		// store params
		mWrapModeS = wrapMode;
		mGLWrapModeS = cSLTextureWrapModeToGLWrapMode[mWrapModeS];

		// apply params
		GL_CHECK(glTexParameteri(mGLTextureHadle, GL_TEXTURE_WRAP_S, mGLWrapModeS));
	}

	// SetWrapModeT
	void SLTexture2D_GL2::SetWrapModeT(SLTextureWrapMode wrapMode)
	{
		// store params
		mWrapModeT = wrapMode;
		mGLWrapModeT = cSLTextureWrapModeToGLWrapMode[mWrapModeT];

		// apply params
		GL_CHECK(glTexParameteri(mGLTextureHadle, GL_TEXTURE_WRAP_T, mGLWrapModeT));
	}

	// SetFilteringMode
	void SLTexture2D_GL2::SetFilteringMode(SLTextureFilterimgMode filterimgMode)
	{
		// store params
		mFilteringMode = filterimgMode;
		mGLMinFilteringMode = cSLTextureFilterimgModeToGLFilteringMode[mFilteringMode];
		mGLMagFilteringMode = mFilteringMode <= SL_TEXTURE_FILTERING_MODE_LINEAR ? cSLTextureFilterimgModeToGLFilteringMode[mFilteringMode] : GL_LINEAR;

		// apply params
		GL_CHECK(glTexParameteri(mGLTextureHadle, GL_TEXTURE_MIN_FILTER, mGLMinFilteringMode));
		GL_CHECK(glTexParameteri(mGLTextureHadle, GL_TEXTURE_MAG_FILTER, mGLMagFilteringMode));
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
		return mFilteringMode;
	}
}
