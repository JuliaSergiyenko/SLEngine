#include "SLCamera_GLES3.hpp"
#include <memory>

// SLR_GLES3
namespace SLR_GLES3
{
	// SLCamera_GLES3
	SLCamera_GLES3::SLCamera_GLES3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLCamera_GLES3
	SLCamera_GLES3::~SLCamera_GLES3()
	{
	}

	// GetRenderer
	ISLRenderer* SLCamera_GLES3::GetRenderer() const
	{
		return mRenderer;
	}

	// SetViewport
	void SLCamera_GLES3::SetViewport(size_t width, size_t height)
	{
		mViewportWidth = width;
		mViewportHeight = height;
	}

	// SetProjection
	void SLCamera_GLES3::SetProjection(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mProjection, mat, sizeof(mProjection));
	}

	// SetTransform
	void SLCamera_GLES3::SetTransform(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mTransform, mat, sizeof(mTransform));
	}

	// GetViewport
	void SLCamera_GLES3::GetViewport(size_t& width, size_t& height) const
	{
		width = mViewportWidth;
		height = mViewportHeight;
	}

	// GetProjection
	void SLCamera_GLES3::GetProjection(float* mat) const
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mat, mProjection, sizeof(mProjection));
	}

	// GetTransform
	void SLCamera_GLES3::GetTransform(float* mat) const
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mat, mTransform, sizeof(mTransform));
	}
}
