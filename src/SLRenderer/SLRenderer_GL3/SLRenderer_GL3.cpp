#include "SLRenderer_GL3.hpp"
#include <stdexcept>

// SLRGL3
namespace SLR_GL3 {
	// SLRenderer_GL3
	SLRenderer_GL3::SLRenderer_GL3()
	{
		InitOpenGL3();
	}

	// ~SLRenderer_GL3
	SLRenderer_GL3::~SLRenderer_GL3()
	{
		// destructor
	}

	// CreateTexture2D
	ISLTexture2D* SLRenderer_GL3::CreateTexture2D(uint8_t * data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateTexture2D
	void SLRenderer_GL3::UpdateTexture2D(ISLTexture2D* texture2d, uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteTexture2D
	void SLRenderer_GL3::DeleteTexture2D(ISLTexture2D* texture2d)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateBuffer
	ISLBuffer* SLRenderer_GL3::CreateBuffer(float* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateBuffer
	void SLRenderer_GL3::UpdateBuffer(ISLBuffer* buffer, float* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteBuffer
	void SLRenderer_GL3::DeleteBuffer(ISLBuffer* buffer)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateIndexBuffer
	ISLIndexBuffer* SLRenderer_GL3::CreateIndexBuffer(uint16_t* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateIndexBuffer
	void SLRenderer_GL3::UpdateIndexBuffer(ISLIndexBuffer* buffer, uint16_t* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteIndexBuffer
	void SLRenderer_GL3::DeleteIndexBuffer(ISLIndexBuffer* buffer)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateMesh
	ISLMesh* SLRenderer_GL3::CreateMesh()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteMesh
	void SLRenderer_GL3::DeleteMesh(ISLMesh* mesh)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateModel
	ISLModel* SLRenderer_GL3::CreateModel()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteModel
	void SLRenderer_GL3::DeleteModel(ISLModel* model)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateCamera
	ISLCamera* SLRenderer_GL3::CreateCamera()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteCamera
	void SLRenderer_GL3::DeleteCamera(ISLCamera* camera)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// Render
	void SLRenderer_GL3::Render(ISLCamera* camera)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteResources
	void SLRenderer_GL3::DeleteResources()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// GetDescription
	const char * SLRenderer_GL3::GetDescription() const
	{
		return "SLRenderer OpenGL 3.2 implementation";
	}
}