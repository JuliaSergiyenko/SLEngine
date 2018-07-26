#pragma once

#include "../SLRenderer.hpp"

// SLRGL4
namespace SLR_GL4 {
	// SLBuffer_GL4
	class SLBuffer_GL4 : public ISLBuffer
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// properties
		uint32_t mSize = 0;
	public:
		// constructor and destructor
		SLBuffer_GL4(ISLRenderer* renderer);
		~SLBuffer_GL4();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// update data
		virtual void UpdateData(float* data, uint32_t size);

		// get buffer size
		virtual uint32_t GetSize() const;
	};
}
