#include "SLIndexBuffer_GLES3.hpp"

// SLR_GLES3
namespace SLR_GLES3
{
	// ISLIndexBuffer_GLES3
	SLIndexBuffer_GLES3::SLIndexBuffer_GLES3(ISLRenderer* renderer) : mRenderer(renderer)
	{
		// create buffer handle
		GL_CHECK(glGenBuffers(1, &mGLBufferHandle));
	}

	// ~ISLIndexBuffer_GLES3
	SLIndexBuffer_GLES3::~SLIndexBuffer_GLES3()
	{
		// delete handles
		GL_CHECK(glDeleteBuffers(1, &mGLBufferHandle));
	}

	// GetRenderer
	ISLRenderer* SLIndexBuffer_GLES3::GetRenderer() const
	{
		return mRenderer;
	}

	// UpdateData
	void SLIndexBuffer_GLES3::UpdateData(uint16_t* data, uint32_t size)
	{
		// store settings
		mSize = size;

		// update buffer data
		GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mGLBufferHandle));
		GL_CHECK(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
		GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

	// GetSize
	uint32_t SLIndexBuffer_GLES3::GetSize() const
	{
		return mSize;
	}
}
