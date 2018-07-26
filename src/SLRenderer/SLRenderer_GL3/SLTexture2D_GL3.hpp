#pragma once

#include "../SLRenderer.hpp"

// SLRGL3
namespace SLR_GL3 {
	// SLTexture2D_GL3
	class SLTexture2D_GL3 : public ISLTexture2D
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// properties
		SLTextureWrapMode mWrapModeS = SL_TEXTURE_WRAP_MODE_REPEAT;
		SLTextureWrapMode mWrapModeT = SL_TEXTURE_WRAP_MODE_REPEAT;
		SLTextureFilterimgMode mFilterimgMode = SL_TEXTURE_FILTERING_MODE_MIPMAP_LENEAR;
	public:
		// constructor and destructor
		SLTexture2D_GL3(ISLRenderer* renderer);
		~SLTexture2D_GL3();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// update image
		virtual void UpdateImage(uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel = 0);

		// set texture wrap mode S and T
		virtual void SetWrapModeS(SLTextureWrapMode wrapMode);
		virtual void SetWrapModeT(SLTextureWrapMode wrapMode);
		virtual void SetFilterimgMode(SLTextureFilterimgMode filterimgMode);

		// get texture wrap mode S and T
		virtual SLTextureWrapMode GetWrapModeS() const;
		virtual SLTextureWrapMode GetWrapModeT() const;
		virtual SLTextureFilterimgMode GetFilterimgMode() const;
	};
}
