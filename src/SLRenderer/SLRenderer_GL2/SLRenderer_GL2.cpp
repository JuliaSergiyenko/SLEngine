#include "SLRenderer_GL2.hpp"
#include "SLOpenGL2.hpp"
#include <stdexcept>

// SLRGL2
namespace SLR_GL2 {
	// SLRenderer_GL2
	SLRenderer_GL2::SLRenderer_GL2()
	{
		InitOpenGL2();
	}

	// ~SLRenderer_GL2
	SLRenderer_GL2::~SLRenderer_GL2()
	{
		// destructor
	}

	// CreateTexture2D
	ISLTexture2D* SLRenderer_GL2::CreateTexture2D(uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateTexture2D
	void SLRenderer_GL2::UpdateTexture2D(ISLTexture2D* texture2d, uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteTexture2D
	void SLRenderer_GL2::DeleteTexture2D(ISLTexture2D* texture2d)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateBuffer
	ISLBuffer* SLRenderer_GL2::CreateBuffer(float* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateBuffer
	void SLRenderer_GL2::UpdateBuffer(ISLBuffer* buffer, float* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteBuffer
	void SLRenderer_GL2::DeleteBuffer(ISLBuffer* buffer)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateIndexBuffer
	ISLIndexBuffer* SLRenderer_GL2::CreateIndexBuffer(uint16_t* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateIndexBuffer
	void SLRenderer_GL2::UpdateIndexBuffer(ISLIndexBuffer* buffer, uint16_t* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteIndexBuffer
	void SLRenderer_GL2::DeleteIndexBuffer(ISLIndexBuffer* buffer)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateMesh
	ISLMesh* SLRenderer_GL2::CreateMesh()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteMesh
	void SLRenderer_GL2::DeleteMesh(ISLMesh* mesh)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateModel
	ISLModel* SLRenderer_GL2::CreateModel()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteModel
	void SLRenderer_GL2::DeleteModel(ISLModel* model)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateCamera
	ISLCamera* SLRenderer_GL2::CreateCamera()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteCamera
	void SLRenderer_GL2::DeleteCamera(ISLCamera* camera)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// Render
	void SLRenderer_GL2::Render(ISLCamera* camera)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteResources
	void SLRenderer_GL2::DeleteResources()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// GetDescription
	const char * SLRenderer_GL2::GetDescription() const
	{
		return "SLRenderer OpenGL 2.0 implementation";
	}
}