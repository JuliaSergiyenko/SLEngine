#pragma once
#include "SLOpenGLES3.hpp"

// SLR_GLES3
namespace SLR_GLES3 {
	// SLBuffer_GLES3
	class SLBuffer_GLES3 : public ISLBuffer
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
		SLBuffer_GLES3(ISLRenderer* renderer);
		~SLBuffer_GLES3();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// update data
		virtual void UpdateData(float* data, uint32_t size);

		// get buffer size
		virtual uint32_t GetSize() const;
	};
}
