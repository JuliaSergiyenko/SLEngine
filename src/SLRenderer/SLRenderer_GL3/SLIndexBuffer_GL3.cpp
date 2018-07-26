#include "SLIndexBuffer_GL3.hpp"

// SLR_GL3
namespace SLR_GL3
{
	// ISLIndexBuffer_GL3
	SLIndexBuffer_GL3::SLIndexBuffer_GL3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~ISLIndexBuffer_GL3
	SLIndexBuffer_GL3::~SLIndexBuffer_GL3()
	{
	}

	// GetRenderer
	ISLRenderer* SLIndexBuffer_GL3::GetRenderer() const
	{
		return mRenderer;
	}

	// UpdateData
	void SLIndexBuffer_GL3::UpdateData(uint16_t* data, uint32_t size)
	{
	}

	// GetSize
	uint32_t SLIndexBuffer_GL3::GetSize() const
	{
		return mSize;
	}
}
