#include "SLIndexBuffer_GL4.hpp"

// SLR_GL4
namespace SLR_GL4
{
	// ISLIndexBuffer_GL4
	SLIndexBuffer_GL4::SLIndexBuffer_GL4(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~ISLIndexBuffer_GL4
	SLIndexBuffer_GL4::~SLIndexBuffer_GL4()
	{
	}

	// GetRenderer
	ISLRenderer* SLIndexBuffer_GL4::GetRenderer() const
	{
		return mRenderer;
	}

	// GetSize
	uint32_t SLIndexBuffer_GL4::GetSize() const
	{
		return mSize;
	}
}
