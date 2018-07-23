#pragma once

#include "../SLRenderer.hpp"

// SLRGL4
namespace SLR_GL4 {
	// SLTexture2D_GL4
	class SLTexture2D_GL4 : public ISLTexture2D
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
		SLTexture2D_GL4(ISLRenderer* renderer);
		~SLTexture2D_GL4();

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
