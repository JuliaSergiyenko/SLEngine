#include "SLRenderer_GLES3.hpp"
#include <stdexcept>

// SLRGL2
namespace SLR_GLES3 {
	// SLRenderer_GLES3
	SLRenderer_GLES3::SLRenderer_GLES3()
	{
		// constructor
	}

	// ~SLRenderer_GLES3
	SLRenderer_GLES3::~SLRenderer_GLES3()
	{
		// destructor
	}

	// CreateTexture2D
	ISLTexture2D* SLRenderer_GLES3::CreateTexture2D(uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateTexture2D
	void SLRenderer_GLES3::UpdateTexture2D(ISLTexture2D* texture2d, uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteTexture2D
	void SLRenderer_GLES3::DeleteTexture2D(ISLTexture2D* texture2d)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateBuffer
	ISLBuffer* SLRenderer_GLES3::CreateBuffer(float* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateBuffer
	void SLRenderer_GLES3::UpdateBuffer(ISLBuffer* buffer, float* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteBuffer
	void SLRenderer_GLES3::DeleteBuffer(ISLBuffer* buffer)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateIndexBuffer
	ISLIndexBuffer* SLRenderer_GLES3::CreateIndexBuffer(uint16_t* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// UpdateIndexBuffer
	void SLRenderer_GLES3::UpdateIndexBuffer(ISLIndexBuffer* buffer, uint16_t* data, uint32_t size)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteIndexBuffer
	void SLRenderer_GLES3::DeleteIndexBuffer(ISLIndexBuffer* buffer)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateMesh
	ISLMesh* SLRenderer_GLES3::CreateMesh()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteMesh
	void SLRenderer_GLES3::DeleteMesh(ISLMesh* mesh)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateModel
	ISLModel* SLRenderer_GLES3::CreateModel()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteModel
	void SLRenderer_GLES3::DeleteModel(ISLModel* model)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateCamera
	ISLCamera* SLRenderer_GLES3::CreateCamera()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteCamera
	void SLRenderer_GLES3::DeleteCamera(ISLCamera* camera)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// CreateScene
	ISLScene* SLRenderer_GLES3::CreateScene()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteScene
	void SLRenderer_GLES3::DeleteScene(ISLScene* scene)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// Render
	void SLRenderer_GLES3::Render()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// DeleteResources
	void SLRenderer_GLES3::DeleteResources()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	// GetDescription
	const char * SLRenderer_GLES3::GetDescription() const
	{
		return "SLRenderer OpenGL ES 3.2 implementation";
	}
}