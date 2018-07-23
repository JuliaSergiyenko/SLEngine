#include "SLCamera_GL3.hpp"
#include <memory>

// SLR_GL3
namespace SLR_GL3
{
	// SLCamera_GL3
	SLCamera_GL3::SLCamera_GL3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLCamera_GL3
	SLCamera_GL3::~SLCamera_GL3()
	{
	}

	// GetRenderer
	ISLRenderer* SLCamera_GL3::GetRenderer() const
	{
		return mRenderer;
	}

	// SetViewport
	void SLCamera_GL3::SetViewport(size_t width, size_t height)
	{
		mViewportWidth = width;
		mViewportHeight = height;
	}

	// SetProjection
	void SLCamera_GL3::SetProjection(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mProjection, mat, sizeof(mProjection));
	}

	// SetTransform
	void SLCamera_GL3::SetTransform(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mTransform, mat, sizeof(mTransform));
	}

	// GetViewport
	void SLCamera_GL3::GetViewport(size_t& width, size_t& height) const
	{
		width = mViewportWidth;
		height = mViewportHeight;
	}

	// GetProjection
	void SLCamera_GL3::GetProjection(float* mat) const
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mat, mProjection, sizeof(mProjection));
	}

	// GetTransform
	void SLCamera_GL3::GetTransform(float* mat) const
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mat, mTransform, sizeof(mTransform));
	}
}
