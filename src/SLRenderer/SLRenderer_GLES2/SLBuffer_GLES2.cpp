#include "SLBuffer_GLES2.hpp"

// SLR_GLES2
namespace SLR_GLES2
{
	// SLBuffer_GLES2
	SLBuffer_GLES2::SLBuffer_GLES2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLBuffer_GLES2
	SLBuffer_GLES2::~SLBuffer_GLES2()
	{
	}

	// GetRenderer
	ISLRenderer* SLBuffer_GLES2::GetRenderer() const
	{
		return mRenderer;
	}

	// update data
	void SLBuffer_GLES2::UpdateData(float* data, uint32_t size)
	{
	}

	// GetSize
	uint32_t SLBuffer_GLES2::GetSize() const
	{
		return mSize;
	}
}
