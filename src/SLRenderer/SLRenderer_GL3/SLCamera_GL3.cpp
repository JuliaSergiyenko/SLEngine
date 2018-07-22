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

	// SetNearPlane
	void SLCamera_GL3::SetNearPlane(float nearPlane)
	{
		mNearPlane = nearPlane;
	}

	// SetFarPlane
	void SLCamera_GL3::SetFarPlane(float farPlane)
	{
		mFarPlane = farPlane;
	}

	// SetViewport
	void SLCamera_GL3::SetViewport(size_t width, size_t height)
	{
		mViewportWidth = width;
		mViewportHeight = height;
	}

	// SetProjection
	void SLCamera_GL3::SetProjection(float* matProj)
	{
		// check for null
		if (matProj != nullptr)
			std::memcpy(mMatProj, matProj, sizeof(mMatProj));
	}

	// SetTransform
	void SLCamera_GL3::SetTransform(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mTransform, mat, sizeof(mTransform));
	}

	// GetNearPlane
	float SLCamera_GL3::GetNearPlane()
	{
		return mNearPlane;
	}

	// GetFarPlane
	float SLCamera_GL3::GetFarPlane()
	{
		return mFarPlane;
	}

	// GetViewport
	void SLCamera_GL3::GetViewport(size_t& width, size_t& height)
	{
		width = mViewportWidth;
		height = mViewportHeight;
	}

	// GetProjection
	void SLCamera_GL3::GetProjection(float* matProj)
	{
		// check for null
		if (matProj != nullptr)
			std::memcpy(matProj, mMatProj, sizeof(mMatProj));
	}

	// GetTransform
	void SLCamera_GL3::GetTransform(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mat, mTransform, sizeof(mTransform));
	}
}
