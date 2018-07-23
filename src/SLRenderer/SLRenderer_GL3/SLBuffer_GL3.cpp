#include "SLBuffer_GL3.hpp"

// SLR_GL3
namespace SLR_GL3
{
	// SLBuffer_GL3
	SLBuffer_GL3::SLBuffer_GL3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLBuffer_GL3
	SLBuffer_GL3::~SLBuffer_GL3()
	{
	}

	// GetRenderer
	ISLRenderer* SLBuffer_GL3::GetRenderer() const
	{
		return mRenderer;
	}

	// GetSize
	uint32_t SLBuffer_GL3::GetSize() const
	{
		return mSize;
	}
}
