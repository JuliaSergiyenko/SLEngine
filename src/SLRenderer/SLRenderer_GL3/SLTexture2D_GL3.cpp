#include "SLTexture2D_GL3.hpp"

// SLR_GL3
namespace SLR_GL3
{
	// SLTexture2D_GL3
	SLTexture2D_GL3::SLTexture2D_GL3(ISLRenderer* renderer) : mRenderer(renderer)
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

	// ~SLTexture2D_GL3
	SLTexture2D_GL3::~SLTexture2D_GL3()
	{
		// delete handles
		GL_CHECK(glDeleteSamplers(1, &mGLSamplerHadle));
		GL_CHECK(glDeleteTextures(1, &mGLTextureHadle));
	}

	// GetRenderer
	ISLRenderer* SLTexture2D_GL3::GetRenderer() const
	{
		return mRenderer;
	}
		
	// UpdateFormats
	void SLTexture2D_GL3::UpdateFormats(SLTextureDataType textureDataType)
	{
		switch (textureDataType)
		{
		case SL_TEXTURE_DATA_TYPE_RGB:
			mGLInternalFormat = GL_RGB;
			mGLFormat = GL_RGB;
			break;
		case SL_TEXTURE_DATA_TYPE_RGBA:
			mGLInternalFormat = GL_RGBA;
			mGLFormat = GL_RGBA;
			break;
		default:
			break;
		}
	}

	// UpdateImage
	void SLTexture2D_GL3::UpdateImage(int32_t mipLevel, SLTextureDataType textureDataType, uint32_t width, uint32_t height, const void* data, size_t dataSize)
	{
		// transform texture data type to texture formats
		UpdateFormats(textureDataType);

		// update texture image by layer
		GL_CHECK(glBindTexture(GL_TEXTURE_2D, mGLTextureHadle));
		GL_CHECK(glTexImage2D(GL_TEXTURE_2D, mipLevel, mGLInternalFormat, width, height, 0, mGLFormat, GL_UNSIGNED_BYTE, data));
		GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
	}

	// SetWrapModeS
	void SLTexture2D_GL3::SetWrapModeS(SLTextureWrapMode wrapMode)
	{
		// store params
		mWrapModeS = wrapMode;
		mGLWrapModeS = cSLTextureWrapModeToGLWrapMode[mWrapModeS];
		
		// apply params
		GL_CHECK(glSamplerParameteri(mGLSamplerHadle, GL_TEXTURE_WRAP_S, mGLWrapModeS));
	}

	// SetWrapModeT
	void SLTexture2D_GL3::SetWrapModeT(SLTextureWrapMode wrapMode)
	{
		// store params
		mWrapModeT = wrapMode;
		mGLWrapModeT = cSLTextureWrapModeToGLWrapMode[mWrapModeT];

		// apply params
		GL_CHECK(glSamplerParameteri(mGLSamplerHadle, GL_TEXTURE_WRAP_T, mGLWrapModeT));
	}

	// SetFilteringMode
	void SLTexture2D_GL3::SetFilteringMode(SLTextureFilterimgMode filterimgMode)
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
