#include "SLRenderer_GL4.hpp"
#include <stdexcept>

// SLRGL4
namespace SLR_GL4 {
	// SLRenderer_GL4
	SLRenderer_GL4::SLRenderer_GL4()
	{
		InitOpenGL4();
	}

	// ~SLRenderer_GL4
	SLRenderer_GL4::~SLRenderer_GL4()
	{
		// destructor
	}

	// CreateTexture2D
	ISLTexture2D* SLRenderer_GL4::CreateTexture2D(uint8_t * data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateTexture2D
	void SLRenderer_GL4::UpdateTexture2D(ISLTexture2D* texture2d, uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteTexture2D
	void SLRenderer_GL4::DeleteTexture2D(ISLTexture2D* texture2d)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateBuffer
	ISLBuffer* SLRenderer_GL4::CreateBuffer(float* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateBuffer
	void SLRenderer_GL4::UpdateBuffer(ISLBuffer* buffer, float* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteBuffer
	void SLRenderer_GL4::DeleteBuffer(ISLBuffer* buffer)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateIndexBuffer
	ISLIndexBuffer* SLRenderer_GL4::CreateIndexBuffer(uint16_t* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateIndexBuffer
	void SLRenderer_GL4::UpdateIndexBuffer(ISLIndexBuffer* buffer, uint16_t* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteIndexBuffer
	void SLRenderer_GL4::DeleteIndexBuffer(ISLIndexBuffer* buffer)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateMesh
	ISLMesh* SLRenderer_GL4::CreateMesh()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteMesh
	void SLRenderer_GL4::DeleteMesh(ISLMesh* mesh)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateModel
	ISLModel* SLRenderer_GL4::CreateModel()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteModel
	void SLRenderer_GL4::DeleteModel(ISLModel* model)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateCamera
	ISLCamera* SLRenderer_GL4::CreateCamera()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteCamera
	void SLRenderer_GL4::DeleteCamera(ISLCamera* camera)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateScene
	ISLScene* SLRenderer_GL4::CreateScene()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteScene
	void SLRenderer_GL4::DeleteScene(ISLScene* scene)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// Render
	void SLRenderer_GL4::Render()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteResources
	void SLRenderer_GL4::DeleteResources()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// GetDescription
	const char * SLRenderer_GL4::GetDescription() const
	{
		return "SLRenderer OpenGL 4.6 implementation";
	}
}