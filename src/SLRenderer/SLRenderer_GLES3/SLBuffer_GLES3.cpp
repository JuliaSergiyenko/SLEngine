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

	// UpdateData
	void SLBuffer_GLES3::UpdateData(float* data, uint32_t size)
	{
	}

	// GetSize
	uint32_t SLBuffer_GLES3::GetSize() const
	{
		return mSize;
	}
}
