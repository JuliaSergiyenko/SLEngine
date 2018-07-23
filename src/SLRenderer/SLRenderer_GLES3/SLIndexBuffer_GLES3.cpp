#include "SLIndexBuffer_GLES3.hpp"

// SLR_GLES3
namespace SLR_GLES3
{
	// ISLIndexBuffer_GLES3
	SLIndexBuffer_GLES3::SLIndexBuffer_GLES3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~ISLIndexBuffer_GLES3
	SLIndexBuffer_GLES3::~SLIndexBuffer_GLES3()
	{
	}

	// GetRenderer
	ISLRenderer* SLIndexBuffer_GLES3::GetRenderer() const
	{
		return mRenderer;
	}

	// GetSize
	uint32_t SLIndexBuffer_GLES3::GetSize() const
	{
		return mSize;
	}
}
