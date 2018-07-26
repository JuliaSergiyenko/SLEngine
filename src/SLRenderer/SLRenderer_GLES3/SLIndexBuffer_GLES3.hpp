#pragma once

#include "../SLRenderer.hpp"

// SLRGLES3
namespace SLR_GLES3 {
	// SLIndexBuffer_GLES3
	class SLIndexBuffer_GLES3 : public ISLIndexBuffer
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// properties
		uint32_t mSize = 0;
	public:
		// constructor and destructor
		SLIndexBuffer_GLES3(ISLRenderer* renderer);
		~SLIndexBuffer_GLES3();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// update data
		virtual void UpdateData(uint16_t* data, uint32_t size);

		// get buffer size
		virtual uint32_t GetSize() const;
	};
}
