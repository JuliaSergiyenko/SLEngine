#include "SLBuffer_GL4.hpp"

// SLR_GL4
namespace SLR_GL4
{
	// SLBuffer_GL4
	SLBuffer_GL4::SLBuffer_GL4(ISLRenderer* renderer) : mRenderer(renderer)
	{
		// create buffer handle
		GL_CHECK(glGenBuffers(1, &mGLBufferHandle));
	}

	// ~SLBuffer_GL4
	SLBuffer_GL4::~SLBuffer_GL4()
	{
		// delete handles
		GL_CHECK(glDeleteBuffers(1, &mGLBufferHandle));
	}

	// GetRenderer
	ISLRenderer* SLBuffer_GL4::GetRenderer() const
	{
		return mRenderer;
	}

	// UpdateData
	void SLBuffer_GL4::UpdateData(void* data, uint32_t size)
	{
		// store settings
		mSize = size;

		// update buffer data
		GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mGLBufferHandle));
		GL_CHECK(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
		GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	// GetSize
	uint32_t SLBuffer_GL4::GetSize() const
	{
		return mSize;
	}
}
