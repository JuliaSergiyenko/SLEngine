#include "SLBuffer_GL4.hpp"

// SLR_GL4
namespace SLR_GL4
{
	// SLBuffer_GL4
	SLBuffer_GL4::SLBuffer_GL4(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLBuffer_GL4
	SLBuffer_GL4::~SLBuffer_GL4()
	{
	}

	// GetRenderer
	ISLRenderer* SLBuffer_GL4::GetRenderer() const
	{
		return mRenderer;
	}

	// GetSize
	uint32_t SLBuffer_GL4::GetSize() const
	{
		return mSize;
	}
}
