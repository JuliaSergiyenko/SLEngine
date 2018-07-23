#include "SLCamera_GL4.hpp"
#include <memory>

// SLR_GL4
namespace SLR_GL4
{
	// SLCamera_GL4
	SLCamera_GL4::SLCamera_GL4(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLCamera_GL4
	SLCamera_GL4::~SLCamera_GL4()
	{
	}

	// GetRenderer
	ISLRenderer* SLCamera_GL4::GetRenderer() const
	{
		return mRenderer;
	}

	// SetViewport
	void SLCamera_GL4::SetViewport(size_t width, size_t height)
	{
		mViewportWidth = width;
		mViewportHeight = height;
	}

	// SetProjection
	void SLCamera_GL4::SetProjection(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mProjection, mat, sizeof(mProjection));
	}

	// SetTransform
	void SLCamera_GL4::SetTransform(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mTransform, mat, sizeof(mTransform));
	}

	// GetViewport
	void SLCamera_GL4::GetViewport(size_t& width, size_t& height) const
	{
		width = mViewportWidth;
		height = mViewportHeight;
	}

	// GetProjection
	void SLCamera_GL4::GetProjection(float* mat) const
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mat, mProjection, sizeof(mProjection));
	}

	// GetTransform
	void SLCamera_GL4::GetTransform(float* mat) const
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mat, mTransform, sizeof(mTransform));
	}
}
