#pragma once

#include "../SLRenderer.hpp"

// SLRGL2
namespace SLR_GL2 {
	// SLIndexBuffer_GL2
	class SLIndexBuffer_GL2 : public ISLIndexBuffer
	{
	private:
		// renderer
		ISLRenderer * mRenderer = nullptr;

		// properties
		uint32_t mSize = 0;
	public:
		// constructor and destructor
		SLIndexBuffer_GL2(ISLRenderer* renderer);
		~SLIndexBuffer_GL2();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// get buffer size
		virtual uint32_t GetSize() const;
	};
}
