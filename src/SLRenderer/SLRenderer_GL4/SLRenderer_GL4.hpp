#pragma once

// local components
#include "SLRenderScene_GL4.hpp"
#include "SLShaderManager_GL4.hpp"

// standard library
#include <string>

// SLR_GL4
namespace SLR_GL4 {
	// SLRendererGL3
	class SLRenderer_GL4 : public ISLRenderer
	{
	private:
		// object vectors
		std::vector<SLTexture2D_GL4 *>   mTexture2Ds;
		std::vector<SLBuffer_GL4 *>      mBuffers;
		std::vector<SLIndexBuffer_GL4 *> mIndexBuffers;
		std::vector<SLMesh_GL4 *>        mMeshes;
		std::vector<SLModel_GL4 *>       mModels;
		std::vector<SLCamera_GL4 *>      mCameras;
		std::vector<SLRenderScene_GL4 *> mRenderScenes;

		// renderer info
		std::string mGLVendor;
		std::string mGLRenderer;
		std::string mGLVersion;
		std::string mGLSLVersion;
		std::string mDescription;

		// stat string
		char mStatString[1024];
	private:
		// helper function
		void CreateDescription();
	public:
		// internal resources
		SLShaderManager_GL4 mShaderManager;
	public:
		// constructor and destructor
		SLRenderer_GL4();
		~SLRenderer_GL4();

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
		virtual void FreeResources();

		// get description
		virtual const char* GetDescription() const;
		virtual const char* GetStatString();
	};
}
