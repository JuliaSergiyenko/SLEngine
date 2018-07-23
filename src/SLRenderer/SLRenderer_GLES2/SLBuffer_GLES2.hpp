#pragma once

#include "../SLRenderer.hpp"

// SLRGLES2
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
		// constructor and destructor
		SLBuffer_GLES2(ISLRenderer* renderer);
		~SLBuffer_GLES2();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// get buffer size
		virtual uint32_t GetSize() const;
	};
}
