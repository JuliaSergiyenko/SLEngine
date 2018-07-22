#pragma once

// local components
#include "SLTexture2D_GL3.hpp"
#include "SLBuffer_GL3.hpp"
#include "SLIndexBuffer_GL3.hpp"
#include "SLMesh_GL3.hpp"
#include "SLModel_GL3.hpp"
#include "SLCamera_GL3.hpp"
#include "SLScene_GL3.hpp"
#include "SLOpenGL3.hpp"

// standard library
#include <vector>

// SLRGL3
namespace SLR_GL3 {
	// SLRendererGL3
	class SLRenderer_GL3 : public ISLRenderer
	{
	private:
		std::vector<SLTexture2D_GL3 *>   mTexture2Ds;
		std::vector<SLBuffer_GL3 *>      mBuffers;
		std::vector<SLIndexBuffer_GL3 *> mIndexBuffers;
		std::vector<SLMesh_GL3 *>        mMeshes;
		std::vector<SLModel_GL3 *>       mModels;
		std::vector<SLCamera_GL3 *>      mCameras;
		std::vector<SLScene_GL3 *>       mScenes;
	public:
		// constructor and destructor
		SLRenderer_GL3();
		~SLRenderer_GL3();

		// texture functions
		virtual ISLTexture2D* CreateTexture2D(uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel = 0);
		virtual void UpdateTexture2D(ISLTexture2D* texture2d, uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel = 0);
		virtual void DeleteTexture2D(ISLTexture2D* texture2d);
		virtual bool IsTexture2DExists(ISLTexture2D* texture2d);

		// buffer functions
		virtual ISLBuffer* CreateBuffer(float* data, uint32_t size);
		virtual void UpdateBuffer(ISLBuffer* buffer, float* data, uint32_t size);
		virtual void DeleteBuffer(ISLBuffer* buffer);
		virtual bool IsBufferExists(ISLBuffer* buffer);

		// index buffer functions
		virtual ISLIndexBuffer* CreateIndexBuffer(uint16_t* data, uint32_t size);
		virtual void UpdateIndexBuffer(ISLIndexBuffer* buffer, uint16_t* data, uint32_t size);
		virtual void DeleteIndexBuffer(ISLIndexBuffer* buffer);
		virtual bool IsIndexBufferExists(ISLIndexBuffer* buffer);

		// mesh functions
		virtual ISLMesh* CreateMesh();
		virtual void DeleteMesh(ISLMesh* mesh);
		virtual bool IsMeshExists(ISLMesh* mesh);

		// model functions
		virtual ISLModel* CreateModel();
		virtual void DeleteModel(ISLModel* model);
		virtual bool IsModelExists(ISLModel* model);

		// camera functions
		virtual ISLCamera* CreateCamera();
		virtual void DeleteCamera(ISLCamera* camera);
		virtual bool IsCameraExists(ISLCamera* camera);

		// scene functions
		virtual ISLScene* CreateScene();
		virtual void DeleteScene(ISLScene* scene);
		virtual bool IsSceneExists(ISLScene* scene);

		// render
		virtual void Render();

		// delete resource
		virtual void DeleteResources();

		// get description
		virtual const char* GetDescription() const;
	};
}