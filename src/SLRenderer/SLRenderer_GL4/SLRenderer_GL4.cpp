#include "SLRenderer_GL4.hpp"

#include <iostream>
#include <algorithm>
#include <sstream>

// SLRGL4
namespace SLR_GL4 {
	// SLRenderer_GL4
	SLRenderer_GL4::SLRenderer_GL4()
	{
		InitOpenGL4();

		// get opengl info
		mGLVendor = (const char *)glGetString(GL_VENDOR);
		mGLRenderer = (const char *)glGetString(GL_RENDERER);
		mGLVersion = (const char *)glGetString(GL_VERSION);
		mGLSLVersion = (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION);

		// create description
		std::stringstream lines;
		lines <<
			"SLRenderer OpenGL 4.x implementation" << std::endl <<
			"GL Vendor    : " << mGLVendor << std::endl <<
			"GL Renderer  : " << mGLRenderer << std::endl <<
			"GL Version   : " << mGLVersion << std::endl <<
			"GLSL Version : " << mGLSLVersion << std::endl;
		mDescription = lines.str();
	}

	// ~SLRenderer_GL4
	SLRenderer_GL4::~SLRenderer_GL4()
	{
		// destructor
	}

	//////////////////////////////////////////////////////////////////////////
	// Texture2D
	//////////////////////////////////////////////////////////////////////////

	// CreateTexture2D
	ISLTexture2D* SLRenderer_GL4::CreateTexture2D()
	{
		// create new texture
		SLTexture2D_GL4* texture2D = new SLTexture2D_GL4(this);
		mTexture2Ds.push_back(texture2D);
		return texture2D;
	}

	// DeleteTexture2D
	void SLRenderer_GL4::DeleteTexture2D(ISLTexture2D* texture2d)
	{
		// check if exists
		if (!IsTexture2DExists(texture2d))
			return;

		// remove existing textures
		mTexture2Ds.erase(std::remove_if(mTexture2Ds.begin(), mTexture2Ds.end(), [&](SLTexture2D_GL4* item) {
			return item == texture2d;
		}), mTexture2Ds.end());

		// delete texture
		delete (SLTexture2D_GL4 *)texture2d;
	}

	// IsTexture2DExist
	bool SLRenderer_GL4::IsTexture2DExists(ISLTexture2D* texture2d) const
	{
		return (std::find(mTexture2Ds.begin(), mTexture2Ds.end(), texture2d) != mTexture2Ds.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Buffer
	//////////////////////////////////////////////////////////////////////////

	// CreateBuffer
	ISLBuffer* SLRenderer_GL4::CreateBuffer()
	{
		// create new buffer
		SLBuffer_GL4* buffer = new SLBuffer_GL4(this);
		mBuffers.push_back(buffer);
		return buffer;
	}

	// DeleteBuffer
	void SLRenderer_GL4::DeleteBuffer(ISLBuffer* buffer)
	{
		// check if exists
		if (!IsBufferExists(buffer))
			return;

		// remove existing buffers
		mBuffers.erase(std::remove_if(mBuffers.begin(), mBuffers.end(), [&](SLBuffer_GL4* item) {
			return item == buffer;
		}), mBuffers.end());

		// delete buffer
		delete (SLBuffer_GL4 *)buffer;
	}

	// IsBufferExist
	bool SLRenderer_GL4::IsBufferExists(ISLBuffer* buffer) const
	{
		return (std::find(mBuffers.begin(), mBuffers.end(), buffer) != mBuffers.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Index Buffer
	//////////////////////////////////////////////////////////////////////////

	// CreateIndexBuffer
	ISLIndexBuffer* SLRenderer_GL4::CreateIndexBuffer()
	{
		// create new buffer
		SLIndexBuffer_GL4* buffer = new SLIndexBuffer_GL4(this);
		mIndexBuffers.push_back(buffer);
		return buffer;
	}

	// DeleteIndexBuffer
	void SLRenderer_GL4::DeleteIndexBuffer(ISLIndexBuffer* buffer)
	{
		// check if exists
		if (!IsIndexBufferExists(buffer))
			return;

		// remove existing index buffers
		mIndexBuffers.erase(std::remove_if(mIndexBuffers.begin(), mIndexBuffers.end(), [&](SLIndexBuffer_GL4* item) {
			return item == buffer;
		}), mIndexBuffers.end());

		// delete buffer
		delete (SLIndexBuffer_GL4 *)buffer;
	}

	// IsIndexBufferExists
	bool SLRenderer_GL4::IsIndexBufferExists(ISLIndexBuffer* buffer) const
	{
		return (std::find(mIndexBuffers.begin(), mIndexBuffers.end(), buffer) != mIndexBuffers.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Mesh
	//////////////////////////////////////////////////////////////////////////

	// CreateMesh
	ISLMesh* SLRenderer_GL4::CreateMesh()
	{
		// create new buffer
		SLMesh_GL4* mesh = new SLMesh_GL4(this);
		mMeshes.push_back(mesh);
		return mesh;
	}

	// DeleteMesh
	void SLRenderer_GL4::DeleteMesh(ISLMesh* mesh)
	{
		// check if exists
		if (!IsMeshExists(mesh))
			return;

		// remove existing meshes
		mMeshes.erase(std::remove_if(mMeshes.begin(), mMeshes.end(), [&](SLMesh_GL4* item) {
			return item == mesh;
		}), mMeshes.end());

		// delete mesh
		delete (SLMesh_GL4 *)mesh;
	}

	// IsMeshExists
	bool SLRenderer_GL4::IsMeshExists(ISLMesh* mesh) const
	{
		return (std::find(mMeshes.begin(), mMeshes.end(), mesh) != mMeshes.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Model
	//////////////////////////////////////////////////////////////////////////

	// CreateModel
	ISLModel* SLRenderer_GL4::CreateModel()
	{
		// create new buffer
		SLModel_GL4* model = new SLModel_GL4(this);
		mModels.push_back(model);
		return model;
	}

	// DeleteModel
	void SLRenderer_GL4::DeleteModel(ISLModel* model)
	{
		// check if exists
		if (!IsModelExists(model))
			return;

		// remove existing models
		mModels.erase(std::remove_if(mModels.begin(), mModels.end(), [&](SLModel_GL4* item) {
			return item == model;
		}), mModels.end());

		// delete model
		delete (SLModel_GL4 *)model;
	}

	// IsModelExists
	bool SLRenderer_GL4::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Camera
	//////////////////////////////////////////////////////////////////////////

	// CreateCamera
	ISLCamera* SLRenderer_GL4::CreateCamera()
	{
		// create new buffer
		SLCamera_GL4* camera = new SLCamera_GL4(this);
		mCameras.push_back(camera);
		return camera;
	}

	// DeleteCamera
	void SLRenderer_GL4::DeleteCamera(ISLCamera* camera)
	{
		// check if exists
		if (!IsCameraExists(camera))
			return;

		// remove existing cameras
		mCameras.erase(std::remove_if(mCameras.begin(), mCameras.end(), [&](SLCamera_GL4* item) {
			return item == camera;
		}), mCameras.end());

		// delete camera
		delete (SLCamera_GL4 *)camera;
	}

	// IsCameraExists
	bool SLRenderer_GL4::IsCameraExists(ISLCamera* camera) const
	{
		return (std::find(mCameras.begin(), mCameras.end(), camera) != mCameras.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Scene
	//////////////////////////////////////////////////////////////////////////

	// CreateScene
	ISLRenderScene* SLRenderer_GL4::CreateScene()
	{
		// create new buffer
		SLRenderScene_GL4* scene = new SLRenderScene_GL4(this);
		mScenes.push_back(scene);
		return scene;
	}

	// DeleteScene
	void SLRenderer_GL4::DeleteRenderScene(ISLRenderScene* scene)
	{
		// check if exists
		if (!IsRenderSceneExists(scene))
			return;

		// remove existing cameras
		mScenes.erase(std::remove_if(mScenes.begin(), mScenes.end(), [&](SLRenderScene_GL4* item) {
			return item == scene;
		}), mScenes.end());

		// delete scene
		delete (SLRenderScene_GL4 *)scene;
	}

	// IsRenderSceneExists
	bool SLRenderer_GL4::IsRenderSceneExists(ISLRenderScene* scene) const
	{
		return (std::find(mScenes.begin(), mScenes.end(), scene) != mScenes.end());
	}

	// Render
	void SLRenderer_GL4::Render()
	{
// 		// temporary output renderer info
// 		std::cout << mTexture2Ds.size() << std::endl;
// 		std::cout << mBuffers.size() << std::endl;
// 		std::cout << mIndexBuffers.size() << std::endl;
// 		std::cout << mMeshes.size() << std::endl;
// 		std::cout << mModels.size() << std::endl;
// 		std::cout << mCameras.size() << std::endl;
// 		std::cout << mScenes.size() << std::endl;
	}

	// DeleteResources
	void SLRenderer_GL4::DeleteResources()
	{
		// delete all items
		std::for_each(mTexture2Ds.begin(),   mTexture2Ds.end(),   [](SLTexture2D_GL4* item)   { delete item; });
		std::for_each(mBuffers.begin(),      mBuffers.end(),      [](SLBuffer_GL4* item)      { delete item; });
		std::for_each(mIndexBuffers.begin(), mIndexBuffers.end(), [](SLIndexBuffer_GL4* item) { delete item; });
		std::for_each(mMeshes.begin(),       mMeshes.end(),       [](SLMesh_GL4* item)        { delete item; });
		std::for_each(mModels.begin(),       mModels.end(),       [](SLModel_GL4* item)       { delete item; });
		std::for_each(mCameras.begin(),      mCameras.end(),      [](SLCamera_GL4* item)      { delete item; });
		std::for_each(mScenes.begin(),       mScenes.end(),       [](SLRenderScene_GL4* item)       { delete item; });

		// clear lists
		mTexture2Ds.clear();
		mBuffers.clear();
		mIndexBuffers.clear();
		mMeshes.clear();
		mModels.clear();
		mCameras.clear();
		mScenes.clear();
	}

	// GetDescription
	const char* SLRenderer_GL4::GetDescription() const
	{
		return mDescription.c_str();
	}
}
