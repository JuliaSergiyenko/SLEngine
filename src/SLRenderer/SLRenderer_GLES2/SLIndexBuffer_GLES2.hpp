#pragma once

#include "../SLRenderer.hpp"

// SLRGLES2
namespace SLR_GLES2 {
	// SLIndexBuffer_GLES2
	class SLIndexBuffer_GLES2 : public ISLIndexBuffer
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// properties
		uint32_t mSize = 0;
	public:
		// constructor and destructor
		SLIndexBuffer_GLES2(ISLRenderer* renderer);
		~SLIndexBuffer_GLES2();

		// get render device
		virtual ISLRenderer* GetRenderer() const;

		// update data
		virtual void UpdateData(uint16_t* data, uint32_t size);
		
		// get buffer size
		virtual uint32_t GetSize() const;
	};
}
