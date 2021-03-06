#pragma once
#include "SLOpenGL2.hpp"

// SLR_GL2
namespace SLR_GL2 {
	// SLBuffer_GL2
	class SLBuffer_GL2 : public ISLBuffer
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
		SLBuffer_GL2(ISLRenderer* renderer);
		~SLBuffer_GL2();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// update data
		virtual void UpdateData(void* data, uint32_t size);

		// get buffer size
		virtual uint32_t GetSize() const;
	};
}
