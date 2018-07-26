#include "SLTexture2D_GL3.hpp"

namespace SLR_GL3
{
	// SLTexture2D_GL3
	SLTexture2D_GL3::SLTexture2D_GL3(ISLRenderer* renderer) : mRenderer(renderer)
	{
		glGenTextures(1, &mTextureHadle);
	}

	// ~SLTexture2D_GL3
	SLTexture2D_GL3::~SLTexture2D_GL3()
	{
		glDeleteTextures(1, &mTextureHadle);
	}

	// GetRenderer
	ISLRenderer* SLTexture2D_GL3::GetRenderer() const
	{
		return mRenderer;
	}

	// UpdateImage
	void SLTexture2D_GL3::UpdateImage(uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		// add image to texture
		GL_CHECK(glBindTexture(GL_TEXTURE_2D, mTextureHadle));
		GL_CHECK(glTexImage2D(GL_TEXTURE_2D, mipLevel, cSLPixelDataTypeToGLFormat[pixelDataType], width, height, 0, cSLPixelDataTypeToGLFormat[pixelDataType], GL_UNSIGNED_BYTE, data));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mGLWrapModeS));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mGLWrapModeT));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mGLMinFilteringMode));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mGLMagFilteringMode));
		GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
	}

	// SetWrapModeS
	void SLTexture2D_GL3::SetWrapModeS(SLTextureWrapMode wrapMode)
	{
		// store params
		mWrapModeS = wrapMode;
		mGLWrapModeS = cSLTextureWrapModeToGLWrapMode[mWrapModeS];

		// check if texture exists
		if (glIsTexture(mTextureHadle))
		{
			// apply params
			GL_CHECK(glBindTexture(GL_TEXTURE_2D, mTextureHadle));
			GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mGLWrapModeS));
			GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
		}
	}

	// SetWrapModeT
	void SLTexture2D_GL3::SetWrapModeT(SLTextureWrapMode wrapMode)
	{
		// store params
		mWrapModeT = wrapMode;
		mGLWrapModeT = cSLTextureWrapModeToGLWrapMode[mWrapModeT];

		// check if texture exists
		if (glIsTexture(mTextureHadle))
		{
			// apply params
			GL_CHECK(glBindTexture(GL_TEXTURE_2D, mTextureHadle));
			GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mGLWrapModeT));
			GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
		}
	}

	// SetFilteringMode
	void SLTexture2D_GL3::SetFilteringMode(SLTextureFilterimgMode filterimgMode)
	{
		// store params
		mFilteringMode = filterimgMode;
		mGLMinFilteringMode = cSLTextureFilterimgModeToGLFilteringMode[mFilteringMode];
		mGLMagFilteringMode = mFilteringMode <= SL_TEXTURE_FILTERING_MODE_LINEAR ? cSLTextureFilterimgModeToGLFilteringMode[mFilteringMode] : GL_LINEAR;

		// check if texture exists
		if (glIsTexture(mTextureHadle))
		{
			// apply params
			GL_CHECK(glBindTexture(GL_TEXTURE_2D, mTextureHadle));
			GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mGLMinFilteringMode));
			GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mGLMagFilteringMode));
			GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
		}
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
		return mFilteringMode;
	}
}
