#include "SLRenderer_GL2.hpp"

#include <iostream>
#include <algorithm>

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

	//////////////////////////////////////////////////////////////////////////
	// Texture2D
	//////////////////////////////////////////////////////////////////////////

	// CreateTexture2D
	ISLTexture2D* SLRenderer_GL2::CreateTexture2D(uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		// create new texture
		SLTexture2D_GL2* texture2D = new SLTexture2D_GL2(this);
		mTexture2Ds.push_back(texture2D);
		return texture2D;
	}

	// UpdateTexture2D
	void SLRenderer_GL2::UpdateTexture2D(ISLTexture2D* texture2d, uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		// check if exists
		if (!IsTexture2DExists(texture2d))
			return;
	}

	// DeleteTexture2D
	void SLRenderer_GL2::DeleteTexture2D(ISLTexture2D* texture2d)
	{
		// check if exists
		if (!IsTexture2DExists(texture2d))
			return;

		// remove existing textures
		mTexture2Ds.erase(std::remove_if(mTexture2Ds.begin(), mTexture2Ds.end(), [&](SLTexture2D_GL2* item) {
			return item == texture2d;
		}), mTexture2Ds.end());

		// delete texture
		delete (SLTexture2D_GL2 *)texture2d;
	}

	// IsTexture2DExist
	bool SLRenderer_GL2::IsTexture2DExists(ISLTexture2D* texture2d) const
	{
		return (std::find(mTexture2Ds.begin(), mTexture2Ds.end(), texture2d) != mTexture2Ds.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Buffer
	//////////////////////////////////////////////////////////////////////////

	// CreateBuffer
	ISLBuffer* SLRenderer_GL2::CreateBuffer(float* data, uint32_t size)
	{
		// create new buffer
		SLBuffer_GL2* buffer = new SLBuffer_GL2(this);
		mBuffers.push_back(buffer);
		return buffer;
	}

	// UpdateBuffer
	void SLRenderer_GL2::UpdateBuffer(ISLBuffer* buffer, float* data, uint32_t size)
	{
		// check if exists
		if (!IsBufferExists(buffer))
			return;
	}

	// DeleteBuffer
	void SLRenderer_GL2::DeleteBuffer(ISLBuffer* buffer)
	{
		// check if exists
		if (!IsBufferExists(buffer))
			return;

		// remove existing buffers
		mBuffers.erase(std::remove_if(mBuffers.begin(), mBuffers.end(), [&](SLBuffer_GL2* item) {
			return item == buffer;
		}), mBuffers.end());

		// delete buffer
		delete (SLBuffer_GL2 *)buffer;
	}

	// IsBufferExist
	bool SLRenderer_GL2::IsBufferExists(ISLBuffer* buffer) const
	{
		return (std::find(mBuffers.begin(), mBuffers.end(), buffer) != mBuffers.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Index Buffer
	//////////////////////////////////////////////////////////////////////////

	// CreateIndexBuffer
	ISLIndexBuffer* SLRenderer_GL2::CreateIndexBuffer(uint16_t* data, uint32_t size)
	{
		// create new buffer
		SLIndexBuffer_GL2* buffer = new SLIndexBuffer_GL2(this);
		mIndexBuffers.push_back(buffer);
		return buffer;
	}

	// UpdateIndexBuffer
	void SLRenderer_GL2::UpdateIndexBuffer(ISLIndexBuffer* buffer, uint16_t* data, uint32_t size)
	{
		// check if exists
		if (!IsIndexBufferExists(buffer))
			return;
	}

	// DeleteIndexBuffer
	void SLRenderer_GL2::DeleteIndexBuffer(ISLIndexBuffer* buffer)
	{
		// check if exists
		if (!IsIndexBufferExists(buffer))
			return;

		// remove existing index buffers
		mIndexBuffers.erase(std::remove_if(mIndexBuffers.begin(), mIndexBuffers.end(), [&](SLIndexBuffer_GL2* item) {
			return item == buffer;
		}), mIndexBuffers.end());

		// delete buffer
		delete (SLIndexBuffer_GL2 *)buffer;
	}

	// IsIndexBufferExists
	bool SLRenderer_GL2::IsIndexBufferExists(ISLIndexBuffer* buffer) const
	{
		return (std::find(mIndexBuffers.begin(), mIndexBuffers.end(), buffer) != mIndexBuffers.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Mesh
	//////////////////////////////////////////////////////////////////////////

	// CreateMesh
	ISLMesh* SLRenderer_GL2::CreateMesh()
	{
		// create new buffer
		SLMesh_GL2* mesh = new SLMesh_GL2(this);
		mMeshes.push_back(mesh);
		return mesh;
	}

	// DeleteMesh
	void SLRenderer_GL2::DeleteMesh(ISLMesh* mesh)
	{
		// check if exists
		if (!IsMeshExists(mesh))
			return;

		// remove existing meshes
		mMeshes.erase(std::remove_if(mMeshes.begin(), mMeshes.end(), [&](SLMesh_GL2* item) {
			return item == mesh;
		}), mMeshes.end());

		// delete mesh
		delete (SLMesh_GL2 *)mesh;
	}

	// IsMeshExists
	bool SLRenderer_GL2::IsMeshExists(ISLMesh* mesh) const
	{
		return (std::find(mMeshes.begin(), mMeshes.end(), mesh) != mMeshes.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Model
	//////////////////////////////////////////////////////////////////////////

	// CreateModel
	ISLModel* SLRenderer_GL2::CreateModel()
	{
		// create new buffer
		SLModel_GL2* model = new SLModel_GL2(this);
		mModels.push_back(model);
		return model;
	}

	// DeleteModel
	void SLRenderer_GL2::DeleteModel(ISLModel* model)
	{
		// check if exists
		if (!IsModelExists(model))
			return;

		// remove existing models
		mModels.erase(std::remove_if(mModels.begin(), mModels.end(), [&](SLModel_GL2* item) {
			return item == model;
		}), mModels.end());

		// delete model
		delete (SLModel_GL2 *)model;
	}

	// IsModelExists
	bool SLRenderer_GL2::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Camera
	//////////////////////////////////////////////////////////////////////////

	// CreateCamera
	ISLCamera* SLRenderer_GL2::CreateCamera()
	{
		// create new buffer
		SLCamera_GL2* camera = new SLCamera_GL2(this);
		mCameras.push_back(camera);
		return camera;
	}

	// DeleteCamera
	void SLRenderer_GL2::DeleteCamera(ISLCamera* camera)
	{
		// check if exists
		if (!IsCameraExists(camera))
			return;

		// remove existing cameras
		mCameras.erase(std::remove_if(mCameras.begin(), mCameras.end(), [&](SLCamera_GL2* item) {
			return item == camera;
		}), mCameras.end());

		// delete camera
		delete (SLCamera_GL2 *)camera;
	}

	// IsCameraExists
	bool SLRenderer_GL2::IsCameraExists(ISLCamera* camera) const
	{
		return (std::find(mCameras.begin(), mCameras.end(), camera) != mCameras.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Scene
	//////////////////////////////////////////////////////////////////////////

	// CreateScene
	ISLScene* SLRenderer_GL2::CreateScene()
	{
		// create new buffer
		SLScene_GL2* scene = new SLScene_GL2(this);
		mScenes.push_back(scene);
		return scene;
	}

	// DeleteScene
	void SLRenderer_GL2::DeleteScene(ISLScene* scene)
	{
		// check if exists
		if (!IsSceneExists(scene))
			return;

		// remove existing cameras
		mScenes.erase(std::remove_if(mScenes.begin(), mScenes.end(), [&](SLScene_GL2* item) {
			return item == scene;
		}), mScenes.end());

		// delete scene
		delete (SLScene_GL2 *)scene;
	}

	// IsSceneExists
	bool SLRenderer_GL2::IsSceneExists(ISLScene* scene) const
	{
		return (std::find(mScenes.begin(), mScenes.end(), scene) != mScenes.end());
	}

	// Render
	void SLRenderer_GL2::Render()
	{
		// temporary output renderer info
		std::cout << mTexture2Ds.size() << std::endl;
		std::cout << mBuffers.size() << std::endl;
		std::cout << mIndexBuffers.size() << std::endl;
		std::cout << mMeshes.size() << std::endl;
		std::cout << mModels.size() << std::endl;
		std::cout << mCameras.size() << std::endl;
		std::cout << mScenes.size() << std::endl;
	}

	// DeleteResources
	void SLRenderer_GL2::DeleteResources()
	{
		// delete all items
		std::for_each(mTexture2Ds.begin(), mTexture2Ds.end(), [](SLTexture2D_GL2* item) { delete item; });
		std::for_each(mBuffers.begin(), mBuffers.end(), [](SLBuffer_GL2* item) { delete item; });
		std::for_each(mIndexBuffers.begin(), mIndexBuffers.end(), [](SLIndexBuffer_GL2* item) { delete item; });
		std::for_each(mMeshes.begin(), mMeshes.end(), [](SLMesh_GL2* item) { delete item; });
		std::for_each(mModels.begin(), mModels.end(), [](SLModel_GL2* item) { delete item; });
		std::for_each(mCameras.begin(), mCameras.end(), [](SLCamera_GL2* item) { delete item; });
		std::for_each(mScenes.begin(), mScenes.end(), [](SLScene_GL2* item) { delete item; });

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
	const char* SLRenderer_GL2::GetDescription() const
	{
		return "SLRenderer OpenGL 2.1 implementation";
	}
}
