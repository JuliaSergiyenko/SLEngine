#pragma once
#include "SLOpenGLES2.hpp"

// SLR_GLES2
namespace SLR_GLES2 {
	// SLBuffer_GLES2
	class SLBuffer_GLES2 : public ISLBuffer
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// properties
		uint32_t mSize = 0;
	public:
		// OpenGL handles and settings
		GLuint mGLBufferHandle = 0;
	public:
		// constructor and destructor
		SLBuffer_GLES2(ISLRenderer* renderer);
		~SLBuffer_GLES2();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// update data
		virtual void UpdateData(float* data, uint32_t size);

		// get buffer size
		virtual uint32_t GetSize() const;
	};
}
