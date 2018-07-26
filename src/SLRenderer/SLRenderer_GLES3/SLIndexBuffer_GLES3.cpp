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

	// UpdateData
	void SLIndexBuffer_GLES3::UpdateData(uint16_t* data, uint32_t size)
	{
	}

	// GetSize
	uint32_t SLIndexBuffer_GLES3::GetSize() const
	{
		return mSize;
	}
}
