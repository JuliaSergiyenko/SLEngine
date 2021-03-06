#pragma once
#include "SLOpenGL3.hpp"

// SLRGL3
namespace SLR_GL3 {
	// SLBuffer_GL3
	class SLBuffer_GL3 : public ISLBuffer
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
		SLBuffer_GL3(ISLRenderer* renderer);
		~SLBuffer_GL3();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// update data
		virtual void UpdateData(void* data, uint32_t size);

		// get buffer size
		virtual uint32_t GetSize() const;
	};
}
