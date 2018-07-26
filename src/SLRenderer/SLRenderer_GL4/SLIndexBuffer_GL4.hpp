#pragma once

#include "../SLRenderer.hpp"

// SLRGL4
namespace SLR_GL4 {
	// SLIndexBuffer_GL4
	class SLIndexBuffer_GL4 : public ISLIndexBuffer
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// properties
		uint32_t mSize = 0;
	public:
		// constructor and destructor
		SLIndexBuffer_GL4(ISLRenderer* renderer);
		~SLIndexBuffer_GL4();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// update data
		virtual void UpdateData(uint16_t* data, uint32_t size);

		// get buffer size
		virtual uint32_t GetSize() const;
	};
}
