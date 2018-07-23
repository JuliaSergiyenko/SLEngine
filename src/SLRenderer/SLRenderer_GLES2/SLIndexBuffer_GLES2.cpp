#include "SLIndexBuffer_GLES2.hpp"

// SLR_GLES2
namespace SLR_GLES2
{
	// ISLIndexBuffer_GLES2
	SLIndexBuffer_GLES2::SLIndexBuffer_GLES2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~ISLIndexBuffer_GLES2
	SLIndexBuffer_GLES2::~SLIndexBuffer_GLES2()
	{
	}

	// GetRenderer
	ISLRenderer* SLIndexBuffer_GLES2::GetRenderer() const
	{
		return mRenderer;
	}

	// GetSize
	uint32_t SLIndexBuffer_GLES2::GetSize() const
	{
		return mSize;
	}
}
