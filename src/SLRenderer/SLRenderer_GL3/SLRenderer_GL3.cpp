#include "SLRenderer_GL3.hpp"

#include <iostream>
#include <algorithm>

// SLRGL3
namespace SLR_GL3 {
	// SLRenderer_GL3
	SLRenderer_GL3::SLRenderer_GL3()
	{
		InitOpenGL3();
	}

	// ~SLRenderer_GL3
	SLRenderer_GL3::~SLRenderer_GL3()
	{
		// destructor
	}

	//////////////////////////////////////////////////////////////////////////
	// Texture2D
	//////////////////////////////////////////////////////////////////////////

	// CreateTexture2D
	ISLTexture2D* SLRenderer_GL3::CreateTexture2D(uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		// create new texture
		SLTexture2D_GL3* texture2D = new SLTexture2D_GL3(this);
		mTexture2Ds.push_back(texture2D);
		return texture2D;
	}

	// UpdateTexture2D
	void SLRenderer_GL3::UpdateTexture2D(ISLTexture2D* texture2d, uint8_t* data, uint32_t dataSize, uint32_t width, uint32_t height, SLPixelDataType pixelDataType, uint32_t mipLevel)
	{
		// check if exists
		if (!IsTexture2DExists(texture2d))
			return;
	}

	// DeleteTexture2D
	void SLRenderer_GL3::DeleteTexture2D(ISLTexture2D* texture2d)
	{
		// check if exists
		if (!IsTexture2DExists(texture2d))
			return;

		// remove existing textures
		mTexture2Ds.erase(std::remove_if(mTexture2Ds.begin(), mTexture2Ds.end(), [&](SLTexture2D_GL3* item) {
			return item == texture2d;
		}), mTexture2Ds.end());
	}

	// IsTexture2DExist
	bool SLRenderer_GL3::IsTexture2DExists(ISLTexture2D* texture2d)
	{
		// iterate items
		for (auto item : mTexture2Ds)
			if (item == texture2d)
				return true;
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	// Buffer
	//////////////////////////////////////////////////////////////////////////

	// CreateBuffer
	ISLBuffer* SLRenderer_GL3::CreateBuffer(float* data, uint32_t size)
	{
		// create new buffer
		SLBuffer_GL3* buffer = new SLBuffer_GL3(this);
		mBuffers.push_back(buffer);
		return buffer;
	}

	// UpdateBuffer
	void SLRenderer_GL3::UpdateBuffer(ISLBuffer* buffer, float* data, uint32_t size)
	{
		// check if exists
		if (!IsBufferExists(buffer))
			return;
	}

	// DeleteBuffer
	void SLRenderer_GL3::DeleteBuffer(ISLBuffer* buffer)
	{
		// check if exists
		if (!IsBufferExists(buffer))
			return;

		// remove existing buffers
		mBuffers.erase(std::remove_if(mBuffers.begin(), mBuffers.end(), [&](SLBuffer_GL3* item) {
			return item == buffer;
		}), mBuffers.end());
	}

	// IsBufferExist
	bool SLRenderer_GL3::IsBufferExists(ISLBuffer* buffer)
	{
		// iterate items
		for (auto item : mBuffers)
			if (item == buffer)
				return true;
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	// Index Buffer
	//////////////////////////////////////////////////////////////////////////

	// CreateIndexBuffer
	ISLIndexBuffer* SLRenderer_GL3::CreateIndexBuffer(uint16_t* data, uint32_t size)
	{
		// create new buffer
		SLIndexBuffer_GL3* buffer = new SLIndexBuffer_GL3(this);
		mIndexBuffers.push_back(buffer);
		return buffer;
	}

	// UpdateIndexBuffer
	void SLRenderer_GL3::UpdateIndexBuffer(ISLIndexBuffer* buffer, uint16_t* data, uint32_t size)
	{
		// check if exists
		if (!IsIndexBufferExists(buffer))
			return;
	}

	// DeleteIndexBuffer
	void SLRenderer_GL3::DeleteIndexBuffer(ISLIndexBuffer* buffer)
	{
		// check if exists
		if (!IsIndexBufferExists(buffer))
			return;

		// remove existing index buffers
		mIndexBuffers.erase(std::remove_if(mIndexBuffers.begin(), mIndexBuffers.end(), [&](SLIndexBuffer_GL3* item) {
			return item == buffer;
		}), mIndexBuffers.end());
	}

	// IsIndexBufferExists
	bool SLRenderer_GL3::IsIndexBufferExists(ISLIndexBuffer* buffer)
	{
		// iterate items
		for (auto item : mIndexBuffers)
			if (item == buffer)
				return true;
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	// Mesh
	//////////////////////////////////////////////////////////////////////////

	// CreateMesh
	ISLMesh* SLRenderer_GL3::CreateMesh()
	{
		// create new buffer
		SLMesh_GL3* mesh = new SLMesh_GL3(this);
		mMeshes.push_back(mesh);
		return mesh;
	}

	// DeleteMesh
	void SLRenderer_GL3::DeleteMesh(ISLMesh* mesh)
	{
		// check if exists
		if (!IsMeshExists(mesh))
			return;

		// remove existing meshes
		mMeshes.erase(std::remove_if(mMeshes.begin(), mMeshes.end(), [&](SLMesh_GL3* item) {
			return item == mesh;
		}), mMeshes.end());
	}

	// IsMeshExists
	bool SLRenderer_GL3::IsMeshExists(ISLMesh* mesh)
	{
		// iterate items
		for (auto item : mMeshes)
			if (item == mesh)
				return true;
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	// Model
	//////////////////////////////////////////////////////////////////////////

	// CreateModel
	ISLModel* SLRenderer_GL3::CreateModel()
	{
		// create new buffer
		SLModel_GL3* model = new SLModel_GL3(this);
		mModels.push_back(model);
		return model;
	}

	// DeleteModel
	void SLRenderer_GL3::DeleteModel(ISLModel* model)
	{
		// check if exists
		if (!IsModelExists(model))
			return;

		// remove existing models
		mModels.erase(std::remove_if(mModels.begin(), mModels.end(), [&](SLModel_GL3* item) {
			return item == model;
		}), mModels.end());
	}

	// IsModelExists
	bool SLRenderer_GL3::IsModelExists(ISLModel* model)
	{
		// iterate items
		for (auto item : mModels)
			if (item == model)
				return true;
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	// Camera
	//////////////////////////////////////////////////////////////////////////

	// CreateCamera
	ISLCamera* SLRenderer_GL3::CreateCamera()
	{
		// create new buffer
		SLCamera_GL3* camera = new SLCamera_GL3(this);
		mCameras.push_back(camera);
		return camera;
	}

	// DeleteCamera
	void SLRenderer_GL3::DeleteCamera(ISLCamera* camera)
	{
		// check if exists
		if (!IsCameraExists(camera))
			return;

		// remove existing cameras
		mCameras.erase(std::remove_if(mCameras.begin(), mCameras.end(), [&](SLCamera_GL3* item) {
			return item == camera;
		}), mCameras.end());
	}

	// IsCameraExists
	bool SLRenderer_GL3::IsCameraExists(ISLCamera* camera)
	{
		// iterate items
		for (auto item : mCameras)
			if (item == camera)
				return true;
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	// Scene
	//////////////////////////////////////////////////////////////////////////

	// CreateScene
	ISLScene* SLRenderer_GL3::CreateScene()
	{
		// create new buffer
		SLScene_GL3* scene = new SLScene_GL3(this);
		mScenes.push_back(scene);
		return scene;
	}

	// DeleteScene
	void SLRenderer_GL3::DeleteScene(ISLScene* scene)
	{
		// check if exists
		if (!IsSceneExists(scene))
			return;

		// remove existing cameras
		mScenes.erase(std::remove_if(mScenes.begin(), mScenes.end(), [&](SLScene_GL3* item) {
			return item == scene;
		}), mScenes.end());
	}

	// IsSceneExists
	bool SLRenderer_GL3::IsSceneExists(ISLScene* scene)
	{
		// iterate items
		for (auto item : mScenes)
			if (item == scene)
				return true;
		return false;
	}

	// Render
	void SLRenderer_GL3::Render()
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
	void SLRenderer_GL3::DeleteResources()
	{
		// delete all items
		std::for_each(mTexture2Ds.begin(),   mTexture2Ds.end(),   [](SLTexture2D_GL3* item)   { delete item; });
		std::for_each(mBuffers.begin(),      mBuffers.end(),      [](SLBuffer_GL3* item)      { delete item; });
		std::for_each(mIndexBuffers.begin(), mIndexBuffers.end(), [](SLIndexBuffer_GL3* item) { delete item; });
		std::for_each(mMeshes.begin(),       mMeshes.end(),       [](SLMesh_GL3* item)        { delete item; });
		std::for_each(mModels.begin(),       mModels.end(),       [](SLModel_GL3* item)       { delete item; });
		std::for_each(mCameras.begin(),      mCameras.end(),      [](SLCamera_GL3* item)      { delete item; });
		std::for_each(mScenes.begin(),       mScenes.end(),       [](SLScene_GL3* item)       { delete item; });

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
	const char* SLRenderer_GL3::GetDescription() const
	{
		return "SLRenderer OpenGL 3.2 implementation";
	}
}