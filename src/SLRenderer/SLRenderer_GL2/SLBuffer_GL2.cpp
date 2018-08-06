#include "SLBuffer_GL2.hpp"

// SLR_GL2
namespace SLR_GL2
{
	// SLBuffer_GL2
	SLBuffer_GL2::SLBuffer_GL2(ISLRenderer* renderer) : mRenderer(renderer)
	{
		// create buffer handle
		GL_CHECK(glGenBuffers(1, &mGLBufferHandle));
	}

	// ~SLBuffer_GL2
	SLBuffer_GL2::~SLBuffer_GL2()
	{
		// delete handles
		GL_CHECK(glDeleteBuffers(1, &mGLBufferHandle));
	}

	// GetRenderer
	ISLRenderer* SLBuffer_GL2::GetRenderer() const
	{
		return mRenderer;
	}

	// UpdateData
	void SLBuffer_GL2::UpdateData(void* data, uint32_t size)
	{
		// store settings
		mSize = size;

		// update buffer data
		GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mGLBufferHandle));
		GL_CHECK(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
		GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	// GetSize
	uint32_t SLBuffer_GL2::GetSize() const
	{
		return mSize;
	}
}
