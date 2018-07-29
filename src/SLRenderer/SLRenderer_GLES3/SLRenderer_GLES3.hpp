#pragma once

// local components
#include "SLRenderScene_GLES3.hpp"
#include "SLShaderManager_GLES3.hpp"

// standard library
#include <string>

// SLR_GLES3
namespace SLR_GLES3 {
	// SLRendererGL3
	class SLRenderer_GLES3 : public ISLRenderer
	{
	private:
		// object vectors
		std::vector<SLTexture2D_GLES3 *>   mTexture2Ds;
		std::vector<SLBuffer_GLES3 *>      mBuffers;
		std::vector<SLIndexBuffer_GLES3 *> mIndexBuffers;
		std::vector<SLMesh_GLES3 *>        mMeshes;
		std::vector<SLModel_GLES3 *>       mModels;
		std::vector<SLCamera_GLES3 *>      mCameras;
		std::vector<SLRenderScene_GLES3 *> mRenderScenes;

		// renderer info
		std::string mGLVendor;
		std::string mGLRenderer;
		std::string mGLVersion;
		std::string mGLSLVersion;
		std::string mDescription;
	private:
		// helper function
		void CreateDescription();
	public:
		// internal resources
		SLShaderManager_GLES3 mShaderManager;
	public:
		// constructor and destructor
		SLRenderer_GLES3();
		~SLRenderer_GLES3();

		// texture functions
		virtual ISLTexture2D* CreateTexture2D();
		virtual void DeleteTexture2D(ISLTexture2D* texture2d);
		virtual bool IsTexture2DExists(ISLTexture2D* texture2d) const;

		// buffer functions
		virtual ISLBuffer* CreateBuffer();
		virtual void DeleteBuffer(ISLBuffer* buffer);
		virtual bool IsBufferExists(ISLBuffer* buffer) const;

		// index buffer functions
		virtual ISLIndexBuffer* CreateIndexBuffer();
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

		// render scene functions
		virtual ISLRenderScene* CreateScene();
		virtual void DeleteRenderScene(ISLRenderScene* scene);
		virtual bool IsRenderSceneExists(ISLRenderScene* scene) const;

		// render
		virtual void Render();

		// delete resource
		virtual void DeleteResources();

		// get description
		virtual const char* GetDescription() const;
	};
}
