#include "SLRenderer_GLES2.hpp"
#include <stdexcept>

// SLRGL2
namespace SLR_GLES2 {
	// SLRenderer_GLES2
	SLRenderer_GLES2::SLRenderer_GLES2()
	{
		// constructor
	}

	// ~SLRenderer_GLES2
	SLRenderer_GLES2::~SLRenderer_GLES2()
	{
		// destructor
	}

	// CreateTexture2D
	ISLTexture2D* SLRenderer_GLES2::CreateTexture2D(void * data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateTexture2D
	void SLRenderer_GLES2::UpdateTexture2D(ISLTexture2D* texture2d, void * data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteTexture2D
	void SLRenderer_GLES2::DeleteTexture2D(ISLTexture2D* texture2d)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateBuffer
	ISLBuffer* SLRenderer_GLES2::CreateBuffer(void* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateBuffer
	void SLRenderer_GLES2::UpdateBuffer(ISLBuffer* buffer, void* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteBuffer
	void SLRenderer_GLES2::DeleteBuffer(ISLBuffer* buffer)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateIndexBuffer
	ISLIndexBuffer* SLRenderer_GLES2::CreateIndexBuffer(uint16_t* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateIndexBuffer
	void SLRenderer_GLES2::UpdateIndexBuffer(ISLIndexBuffer* buffer, uint16_t* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteIndexBuffer
	void SLRenderer_GLES2::DeleteIndexBuffer(ISLIndexBuffer* buffer)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateMesh
	ISLMesh* SLRenderer_GLES2::CreateMesh()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteMesh
	void SLRenderer_GLES2::DeleteMesh(ISLMesh* mesh)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateModel
	ISLModel* SLRenderer_GLES2::CreateModel()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteModel
	void SLRenderer_GLES2::DeleteModel(ISLModel* model)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateCamera
	ISLCamera* SLRenderer_GLES2::CreateCamera()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteCamera
	void SLRenderer_GLES2::DeleteCamera(ISLCamera* camera)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// Render
	void SLRenderer_GLES2::Render(ISLCamera* camera)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteResources
	void SLRenderer_GLES2::DeleteResources()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// GetDescription
	const char * SLRenderer_GLES2::GetDescription() const
	{
		return "SLRenderer OpenGL ES 2.0 implementation";
	}

}