#pragma once

#include "../SLRenderer.hpp"

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
		// constructor and destructor
		SLBuffer_GL3(ISLRenderer* renderer);
		~SLBuffer_GL3();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// get buffer size
		virtual uint32_t GetSize() const;
	};
}
