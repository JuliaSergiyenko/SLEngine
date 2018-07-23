#include "SLBuffer_GLES3.hpp"

// SLR_GLES3
namespace SLR_GLES3
{
	// SLBuffer_GLES3
	SLBuffer_GLES3::SLBuffer_GLES3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLBuffer_GLES3
	SLBuffer_GLES3::~SLBuffer_GLES3()
	{
	}

	// GetRenderer
	ISLRenderer* SLBuffer_GLES3::GetRenderer() const
	{
		return mRenderer;
	}

	// GetSize
	uint32_t SLBuffer_GLES3::GetSize() const
	{
		return mSize;
	}
}
