#include "SLRenderer_GLES2.hpp"

#include <iostream>
#include <algorithm>
#include <sstream>

// SLRGL4
namespace SLR_GLES2 {
	// SLRenderer_GLES2
	SLRenderer_GLES2::SLRenderer_GLES2()
	{
		// init opengl extensions
		InitOpenGLES2();

		// get opengl info
		mGLVendor = (const char *)glGetString(GL_VENDOR);
		mGLRenderer = (const char *)glGetString(GL_RENDERER);
		mGLVersion = (const char *)glGetString(GL_VERSION);
		mGLSLVersion = (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION);

		// create description
		std::stringstream lines;
		lines <<
			"SLRenderer OpenGL ES 2.x implementation" << std::endl <<
			"GL Vendor    : " << mGLVendor << std::endl <<
			"GL Renderer  : " << mGLRenderer << std::endl <<
			"GL Version   : " << mGLVersion << std::endl <<
			"GLSL Version : " << mGLSLVersion << std::endl;
		mDescription = lines.str();
	}

	// ~SLRenderer_GLES2
	SLRenderer_GLES2::~SLRenderer_GLES2()
	{
		// destructor
	}

	//////////////////////////////////////////////////////////////////////////
	// Texture2D
	//////////////////////////////////////////////////////////////////////////

	// CreateTexture2D
	ISLTexture2D* SLRenderer_GLES2::CreateTexture2D()
	{
		// create new texture
		SLTexture2D_GLES2* texture2D = new SLTexture2D_GLES2(this);
		mTexture2Ds.push_back(texture2D);
		return texture2D;
	}

	// DeleteTexture2D
	void SLRenderer_GLES2::DeleteTexture2D(ISLTexture2D* texture2d)
	{
		// check if exists
		if (!IsTexture2DExists(texture2d))
			return;

		// remove existing textures
		mTexture2Ds.erase(std::remove_if(mTexture2Ds.begin(), mTexture2Ds.end(), [&](SLTexture2D_GLES2* item) {
			return item == texture2d;
		}), mTexture2Ds.end());

		// delete texture
		delete (SLTexture2D_GLES2 *)texture2d;
	}

	// IsTexture2DExist
	bool SLRenderer_GLES2::IsTexture2DExists(ISLTexture2D* texture2d) const
	{
		return (std::find(mTexture2Ds.begin(), mTexture2Ds.end(), texture2d) != mTexture2Ds.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Buffer
	//////////////////////////////////////////////////////////////////////////

	// CreateBuffer
	ISLBuffer* SLRenderer_GLES2::CreateBuffer()
	{
		// create new buffer
		SLBuffer_GLES2* buffer = new SLBuffer_GLES2(this);
		mBuffers.push_back(buffer);
		return buffer;
	}

	// DeleteBuffer
	void SLRenderer_GLES2::DeleteBuffer(ISLBuffer* buffer)
	{
		// check if exists
		if (!IsBufferExists(buffer))
			return;

		// remove existing buffers
		mBuffers.erase(std::remove_if(mBuffers.begin(), mBuffers.end(), [&](SLBuffer_GLES2* item) {
			return item == buffer;
		}), mBuffers.end());

		// delete buffer
		delete (SLBuffer_GLES2 *)buffer;
	}

	// IsBufferExist
	bool SLRenderer_GLES2::IsBufferExists(ISLBuffer* buffer) const
	{
		return (std::find(mBuffers.begin(), mBuffers.end(), buffer) != mBuffers.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Index Buffer
	//////////////////////////////////////////////////////////////////////////

	// CreateIndexBuffer
	ISLIndexBuffer* SLRenderer_GLES2::CreateIndexBuffer()
	{
		// create new buffer
		SLIndexBuffer_GLES2* buffer = new SLIndexBuffer_GLES2(this);
		mIndexBuffers.push_back(buffer);
		return buffer;
	}

	// DeleteIndexBuffer
	void SLRenderer_GLES2::DeleteIndexBuffer(ISLIndexBuffer* buffer)
	{
		// check if exists
		if (!IsIndexBufferExists(buffer))
			return;

		// remove existing index buffers
		mIndexBuffers.erase(std::remove_if(mIndexBuffers.begin(), mIndexBuffers.end(), [&](SLIndexBuffer_GLES2* item) {
			return item == buffer;
		}), mIndexBuffers.end());

		// delete buffer
		delete (SLIndexBuffer_GLES2 *)buffer;
	}

	// IsIndexBufferExists
	bool SLRenderer_GLES2::IsIndexBufferExists(ISLIndexBuffer* buffer) const
	{
		return (std::find(mIndexBuffers.begin(), mIndexBuffers.end(), buffer) != mIndexBuffers.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Mesh
	//////////////////////////////////////////////////////////////////////////

	// CreateMesh
	ISLMesh* SLRenderer_GLES2::CreateMesh()
	{
		// create new buffer
		SLMesh_GLES2* mesh = new SLMesh_GLES2(this);
		mMeshes.push_back(mesh);
		return mesh;
	}

	// DeleteMesh
	void SLRenderer_GLES2::DeleteMesh(ISLMesh* mesh)
	{
		// check if exists
		if (!IsMeshExists(mesh))
			return;

		// remove existing meshes
		mMeshes.erase(std::remove_if(mMeshes.begin(), mMeshes.end(), [&](SLMesh_GLES2* item) {
			return item == mesh;
		}), mMeshes.end());

		// delete mesh
		delete (SLMesh_GLES2 *)mesh;
	}

	// IsMeshExists
	bool SLRenderer_GLES2::IsMeshExists(ISLMesh* mesh) const
	{
		return (std::find(mMeshes.begin(), mMeshes.end(), mesh) != mMeshes.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Model
	//////////////////////////////////////////////////////////////////////////

	// CreateModel
	ISLModel* SLRenderer_GLES2::CreateModel()
	{
		// create new buffer
		SLModel_GLES2* model = new SLModel_GLES2(this);
		mModels.push_back(model);
		return model;
	}

	// DeleteModel
	void SLRenderer_GLES2::DeleteModel(ISLModel* model)
	{
		// check if exists
		if (!IsModelExists(model))
			return;

		// remove existing models
		mModels.erase(std::remove_if(mModels.begin(), mModels.end(), [&](SLModel_GLES2* item) {
			return item == model;
		}), mModels.end());

		// delete model
		delete (SLModel_GLES2 *)model;
	}

	// IsModelExists
	bool SLRenderer_GLES2::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Camera
	//////////////////////////////////////////////////////////////////////////

	// CreateCamera
	ISLCamera* SLRenderer_GLES2::CreateCamera()
	{
		// create new buffer
		SLCamera_GLES2* camera = new SLCamera_GLES2(this);
		mCameras.push_back(camera);
		return camera;
	}

	// DeleteCamera
	void SLRenderer_GLES2::DeleteCamera(ISLCamera* camera)
	{
		// check if exists
		if (!IsCameraExists(camera))
			return;

		// remove existing cameras
		mCameras.erase(std::remove_if(mCameras.begin(), mCameras.end(), [&](SLCamera_GLES2* item) {
			return item == camera;
		}), mCameras.end());

		// delete camera
		delete (SLCamera_GLES2 *)camera;
	}

	// IsCameraExists
	bool SLRenderer_GLES2::IsCameraExists(ISLCamera* camera) const
	{
		return (std::find(mCameras.begin(), mCameras.end(), camera) != mCameras.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Scene
	//////////////////////////////////////////////////////////////////////////

	// CreateScene
	ISLRenderScene* SLRenderer_GLES2::CreateScene()
	{
		// create new buffer
		SLRenderScene_GLES2* scene = new SLRenderScene_GLES2(this);
		mRenderScenes.push_back(scene);
		return scene;
	}

	// DeleteScene
	void SLRenderer_GLES2::DeleteRenderScene(ISLRenderScene* scene)
	{
		// check if exists
		if (!IsRenderSceneExists(scene))
			return;

		// remove existing cameras
		mRenderScenes.erase(std::remove_if(mRenderScenes.begin(), mRenderScenes.end(), [&](SLRenderScene_GLES2* item) {
			return item == scene;
		}), mRenderScenes.end());

		// delete scene
		delete (SLRenderScene_GLES2 *)scene;
	}

	// IsRenderSceneExists
	bool SLRenderer_GLES2::IsRenderSceneExists(ISLRenderScene* scene) const
	{
		return (std::find(mRenderScenes.begin(), mRenderScenes.end(), scene) != mRenderScenes.end());
	}

	// Render
	void SLRenderer_GLES2::Render()
	{
		// 		// temporary output renderer info
		// 		std::cout << mTexture2Ds.size() << std::endl;
		// 		std::cout << mBuffers.size() << std::endl;
		// 		std::cout << mIndexBuffers.size() << std::endl;
		// 		std::cout << mMeshes.size() << std::endl;
		// 		std::cout << mModels.size() << std::endl;
		// 		std::cout << mCameras.size() << std::endl;
		// 		std::cout << mRenderScenes.size() << std::endl;
	}

	// DeleteResources
	void SLRenderer_GLES2::DeleteResources()
	{
		// delete all items
		std::for_each(mTexture2Ds.begin(), mTexture2Ds.end(), [](SLTexture2D_GLES2* item) { delete item; });
		std::for_each(mBuffers.begin(), mBuffers.end(), [](SLBuffer_GLES2* item) { delete item; });
		std::for_each(mIndexBuffers.begin(), mIndexBuffers.end(), [](SLIndexBuffer_GLES2* item) { delete item; });
		std::for_each(mMeshes.begin(), mMeshes.end(), [](SLMesh_GLES2* item) { delete item; });
		std::for_each(mModels.begin(), mModels.end(), [](SLModel_GLES2* item) { delete item; });
		std::for_each(mCameras.begin(), mCameras.end(), [](SLCamera_GLES2* item) { delete item; });
		std::for_each(mRenderScenes.begin(), mRenderScenes.end(), [](SLRenderScene_GLES2* item) { delete item; });

		// clear lists
		mTexture2Ds.clear();
		mBuffers.clear();
		mIndexBuffers.clear();
		mMeshes.clear();
		mModels.clear();
		mCameras.clear();
		mRenderScenes.clear();
	}

	// GetDescription
	const char* SLRenderer_GLES2::GetDescription() const
	{
		return mDescription.c_str();
	}
}
