#include "SLBuffer_GL2.hpp"

// SLR_GL2
namespace SLR_GL2
{
	// SLBuffer_GL2
	SLBuffer_GL2::SLBuffer_GL2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLBuffer_GL2
	SLBuffer_GL2::~SLBuffer_GL2()
	{
	}

	// GetRenderer
	ISLRenderer* SLBuffer_GL2::GetRenderer() const
	{
		return mRenderer;
	}

	// UpdateData
	void SLBuffer_GL2::UpdateData(float* data, uint32_t size)
	{
	}

	// GetSize
	uint32_t SLBuffer_GL2::GetSize() const
	{
		return mSize;
	}
}
