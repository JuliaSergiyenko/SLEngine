#pragma once

// local components
#include "SLTexture2D_GLES2.hpp"
#include "SLBuffer_GLES2.hpp"
#include "SLIndexBuffer_GLES2.hpp"
#include "SLMesh_GLES2.hpp"
#include "SLModel_GLES2.hpp"
#include "SLCamera_GLES2.hpp"
#include "SLScene_GLES2.hpp"

// standard library
#include <vector>

// SLRGLES2
namespace SLR_GLES2 {
	// SLRendererGLES2
	class SLRenderer_GLES2 : public ISLRenderer
	{
	private:
		std::vector<SLTexture2D_GLES2 *>   mTexture2Ds;
		std::vector<SLBuffer_GLES2 *>      mBuffers;
		std::vector<SLIndexBuffer_GLES2 *> mIndexBuffers;
		std::vector<SLMesh_GLES2 *>        mMeshes;
		std::vector<SLModel_GLES2 *>       mModels;
		std::vector<SLCamera_GLES2 *>      mCameras;
		std::vector<SLScene_GLES2 *>       mScenes;
	public:
		// constructor and destructor
		SLRenderer_GLES2();
		~SLRenderer_GLES2();

		// texture functions
		virtual ISLTexture2D* CreateTexture2D(uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel = 0);
		virtual void UpdateTexture2D(ISLTexture2D* texture2d, uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel = 0);
		virtual void DeleteTexture2D(ISLTexture2D* texture2d);
		virtual bool IsTexture2DExists(ISLTexture2D* texture2d) const;

		// buffer functions
		virtual ISLBuffer* CreateBuffer(float* data, uint32_t size);
		virtual void UpdateBuffer(ISLBuffer* buffer, float* data, uint32_t size);
		virtual void DeleteBuffer(ISLBuffer* buffer);
		virtual bool IsBufferExists(ISLBuffer* buffer) const;

		// index buffer functions
		virtual ISLIndexBuffer* CreateIndexBuffer(uint16_t* data, uint32_t size);
		virtual void UpdateIndexBuffer(ISLIndexBuffer* buffer, uint16_t* data, uint32_t size);
		virtual void DeleteIndexBuffer(ISLIndexBuffer* buffer);
		virtual bool IsIndexBufferExists(ISLIndexBuffer* buffer) const;

		// mesh functions
		virtual ISLMesh* CreateMesh();
		virtual void DeleteMesh(ISLMesh* mesh);
		virtual bool IsMeshExists(ISLMesh* mesh) const;

		// model functions
		virtual ISLModel* CreateModel();
		virtual void DeleteModel(ISLModel* model);
		virtual bool IsModelExists(ISLModel* model) const;

		// camera functions
		virtual ISLCamera* CreateCamera();
		virtual void DeleteCamera(ISLCamera* camera);
		virtual bool IsCameraExists(ISLCamera* camera) const;

		// scene functions
		virtual ISLScene* CreateScene();
		virtual void DeleteScene(ISLScene* scene);
		virtual bool IsSceneExists(ISLScene* scene) const;

		// render
		virtual void Render();

		// delete resource
		virtual void DeleteResources();

		// get description
		virtual const char* GetDescription() const;
	};
}
