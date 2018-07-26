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

	// UpdateData
	void SLIndexBuffer_GL4::UpdateData(uint16_t* data, uint32_t size)
	{
	}

	// GetSize
	uint32_t SLIndexBuffer_GL4::GetSize() const
	{
		return mSize;
	}
}
