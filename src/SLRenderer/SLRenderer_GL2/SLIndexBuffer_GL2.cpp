#include "SLIndexBuffer_GL2.hpp"

// SLR_GL2
namespace SLR_GL2
{
	// ISLIndexBuffer_GL2
	SLIndexBuffer_GL2::SLIndexBuffer_GL2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~ISLIndexBuffer_GL2
	SLIndexBuffer_GL2::~SLIndexBuffer_GL2()
	{
	}

	// GetRenderer
	ISLRenderer* SLIndexBuffer_GL2::GetRenderer() const
	{
		return mRenderer;
	}

	// GetSize
	uint32_t SLIndexBuffer_GL2::GetSize() const
	{
		return mSize;
	}
}
