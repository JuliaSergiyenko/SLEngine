#include "SLBuffer_GLES3.hpp"

// SLR_GLES3
namespace SLR_GLES3
{
	// SLBuffer_GLES3
	SLBuffer_GLES3::SLBuffer_GLES3(ISLRenderer* renderer) : mRenderer(renderer)
	{
		// create buffer handle
		GL_CHECK(glGenBuffers(1, &mGLBufferHandle));
	}

	// ~SLBuffer_GLES3
	SLBuffer_GLES3::~SLBuffer_GLES3()
	{
		// delete handles
		GL_CHECK(glDeleteBuffers(1, &mGLBufferHandle));
	}

	// GetRenderer
	ISLRenderer* SLBuffer_GLES3::GetRenderer() const
	{
		return mRenderer;
	}

	// UpdateData
	void SLBuffer_GLES3::UpdateData(float* data, uint32_t size)
	{
		// store settings
		mSize = size;

		// update buffer data
		GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mGLBufferHandle));
		GL_CHECK(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
		GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	// GetSize
	uint32_t SLBuffer_GLES3::GetSize() const
	{
		return mSize;
	}
}
