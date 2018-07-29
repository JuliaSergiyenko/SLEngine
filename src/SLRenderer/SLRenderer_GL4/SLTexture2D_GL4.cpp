#include "SLTexture2D_GL4.hpp"

// SLR_GL4
namespace SLR_GL4
{
	// SLTexture2D_GL4
	SLTexture2D_GL4::SLTexture2D_GL4(ISLRenderer* renderer) : mRenderer(renderer)
	{
		// create texture handle
		GL_CHECK(glGenTextures(1, &mGLTextureHadle));

		// create sample handle 
		GL_CHECK(glGenSamplers(1, &mGLSamplerHadle));
		GL_CHECK(glSamplerParameteri(mGLSamplerHadle, GL_TEXTURE_WRAP_S, mGLWrapModeS));
		GL_CHECK(glSamplerParameteri(mGLSamplerHadle, GL_TEXTURE_WRAP_T, mGLWrapModeT));
		GL_CHECK(glSamplerParameteri(mGLSamplerHadle, GL_TEXTURE_MIN_FILTER, mGLMinFilteringMode));
		GL_CHECK(glSamplerParameteri(mGLSamplerHadle, GL_TEXTURE_MAG_FILTER, mGLMagFilteringMode));
	}

	// ~SLTexture2D_GL4
	SLTexture2D_GL4::~SLTexture2D_GL4()
	{
		// delete handles
		GL_CHECK(glDeleteSamplers(1, &mGLSamplerHadle));
		GL_CHECK(glDeleteTextures(1, &mGLTextureHadle));
	}

	// GetRenderer
	ISLRenderer* SLTexture2D_GL4::GetRenderer() const
	{
		return mRenderer;
	}

	// UpdateImage
	void SLTexture2D_GL4::UpdateImage(uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		// update texture image by layer
		GL_CHECK(glBindTexture(GL_TEXTURE_2D, mGLTextureHadle));
		GL_CHECK(glTexImage2D(GL_TEXTURE_2D, mipLevel, cSLPixelDataTypeToGLFormat[pixelDataType], width, height, 0, cSLPixelDataTypeToGLFormat[pixelDataType], GL_UNSIGNED_BYTE, data));
		GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
	}

	// SetWrapModeS
	void SLTexture2D_GL4::SetWrapModeS(SLTextureWrapMode wrapMode)
	{
		// store params
		mWrapModeS = wrapMode;
		mGLWrapModeS = cSLTextureWrapModeToGLWrapMode[mWrapModeS];
		
		// apply params
		GL_CHECK(glSamplerParameteri(mGLSamplerHadle, GL_TEXTURE_WRAP_S, mGLWrapModeS));
	}

	// SetWrapModeT
	void SLTexture2D_GL4::SetWrapModeT(SLTextureWrapMode wrapMode)
	{
		// store params
		mWrapModeT = wrapMode;
		mGLWrapModeT = cSLTextureWrapModeToGLWrapMode[mWrapModeT];

		// apply params
		GL_CHECK(glSamplerParameteri(mGLSamplerHadle, GL_TEXTURE_WRAP_T, mGLWrapModeT));
	}

	// SetFilteringMode
	void SLTexture2D_GL4::SetFilteringMode(SLTextureFilterimgMode filterimgMode)
	{
		// store params
		mFilteringMode = filterimgMode;
		mGLMinFilteringMode = cSLTextureFilterimgModeToGLFilteringMode[mFilteringMode];
		mGLMagFilteringMode = mFilteringMode <= SL_TEXTURE_FILTERING_MODE_LINEAR ? cSLTextureFilterimgModeToGLFilteringMode[mFilteringMode] : GL_LINEAR;

		// apply params
		GL_CHECK(glSamplerParameteri(mGLSamplerHadle, GL_TEXTURE_MIN_FILTER, mGLMinFilteringMode));
		GL_CHECK(glSamplerParameteri(mGLSamplerHadle, GL_TEXTURE_MAG_FILTER, mGLMagFilteringMode));
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
		return mFilteringMode;
	}
}
