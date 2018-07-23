#pragma once

#include "../SLRenderer.hpp"

// SLR_GLES3
namespace SLR_GLES3 {
	// SLCamera_GLES3
	class SLCamera_GLES3 : public ISLCamera
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;
		
		// properties
		size_t mViewportWidth  = 0;
		size_t mViewportHeight = 0;
		float mProjection[16];
		float mTransform[16];
	public:
		// constructor and destructor
		SLCamera_GLES3(ISLRenderer* renderer);
		~SLCamera_GLES3();

		// get render device
		ISLRenderer* GetRenderer() const;

		// set properties
		virtual void SetViewport(size_t width, size_t height);
		virtual void SetProjection(float* mat);
		virtual void SetTransform(float* mat);

		// set properties
		virtual void GetViewport(size_t& width, size_t& height) const;
		virtual void GetProjection(float* mat) const;
		virtual void GetTransform(float* mat) const;
	};
}
