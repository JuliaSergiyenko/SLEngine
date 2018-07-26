#pragma once

// local components
#include "SLTexture2D_GLES3.hpp"
#include "SLBuffer_GLES3.hpp"
#include "SLIndexBuffer_GLES3.hpp"
#include "SLMesh_GLES3.hpp"
#include "SLModel_GLES3.hpp"
#include "SLCamera_GLES3.hpp"
#include "SLScene_GLES3.hpp"

// standard library
#include <vector>

// SLRGLES3
namespace SLR_GLES3 {
	// SLRendererGLES3
	class SLRenderer_GLES3 : public ISLRenderer
	{
	private:
		std::vector<SLTexture2D_GLES3 *>   mTexture2Ds;
		std::vector<SLBuffer_GLES3 *>      mBuffers;
		std::vector<SLIndexBuffer_GLES3 *> mIndexBuffers;
		std::vector<SLMesh_GLES3 *>        mMeshes;
		std::vector<SLModel_GLES3 *>       mModels;
		std::vector<SLCamera_GLES3 *>      mCameras;
		std::vector<SLScene_GLES3 *>       mScenes;
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
