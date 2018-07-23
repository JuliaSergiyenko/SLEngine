#include "SLCamera_GL2.hpp"
#include <memory>

// SLR_GL2
namespace SLR_GL2
{
	// SLCamera_GL2
	SLCamera_GL2::SLCamera_GL2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLCamera_GL2
	SLCamera_GL2::~SLCamera_GL2()
	{
	}

	// GetRenderer
	ISLRenderer* SLCamera_GL2::GetRenderer() const
	{
		return mRenderer;
	}

	// SetViewport
	void SLCamera_GL2::SetViewport(size_t width, size_t height)
	{
		mViewportWidth = width;
		mViewportHeight = height;
	}

	// SetProjection
	void SLCamera_GL2::SetProjection(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mProjection, mat, sizeof(mProjection));
	}

	// SetTransform
	void SLCamera_GL2::SetTransform(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mTransform, mat, sizeof(mTransform));
	}

	// GetViewport
	void SLCamera_GL2::GetViewport(size_t& width, size_t& height) const
	{
		width = mViewportWidth;
		height = mViewportHeight;
	}

	// GetProjection
	void SLCamera_GL2::GetProjection(float* mat) const
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mat, mProjection, sizeof(mProjection));
	}

	// GetTransform
	void SLCamera_GL2::GetTransform(float* mat) const
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mat, mTransform, sizeof(mTransform));
	}
}
