#pragma once

#include "../SLRenderer.hpp"

// SLRGLES2
namespace SLR_GLES2 {
	// SLTexture2D_GLES2
	class SLTexture2D_GLES2 : public ISLTexture2D
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
		SLTexture2D_GLES2(ISLRenderer* renderer);
		~SLTexture2D_GLES2();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

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
