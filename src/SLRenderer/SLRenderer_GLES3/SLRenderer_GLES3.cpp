#include "SLRenderer_GLES3.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

// SLR_GLES3
namespace SLR_GLES3 {
	// SLRenderer_GLES3
	SLRenderer_GLES3::SLRenderer_GLES3()
	{
		// init opengl extensions
		CreateDescription();

		// setup renderer
		mShaderManager.SetRenderer(this);
		mShaderManager.CreateShaders();
	}

	// ~SLRenderer_GLES3
	SLRenderer_GLES3::~SLRenderer_GLES3()
	{
		// destructor
	}

	// CreateDescription
	void SLRenderer_GLES3::CreateDescription()
	{
		// get opengl info
		mGLVendor = (const char *)glGetString(GL_VENDOR);
		mGLRenderer = (const char *)glGetString(GL_RENDERER);
		mGLVersion = (const char *)glGetString(GL_VERSION);
		mGLSLVersion = (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION);

		// create description
		std::stringstream lines;
		lines <<
			"SLRenderer OpenGL 3.x implementation" << std::endl <<
			"GL Vendor    : " << mGLVendor << std::endl <<
			"GL Renderer  : " << mGLRenderer << std::endl <<
			"GL Version   : " << mGLVersion << std::endl <<
			"GLSL Version : " << mGLSLVersion << std::endl;
		mDescription = lines.str();
	}

	//////////////////////////////////////////////////////////////////////////
	// Texture2D
	//////////////////////////////////////////////////////////////////////////

	// CreateTexture2D
	ISLTexture2D* SLRenderer_GLES3::CreateTexture2D()
	{
		// create new texture
		SLTexture2D_GLES3* texture2D = new SLTexture2D_GLES3(this);
		mTexture2Ds.push_back(texture2D);
		return texture2D;
	}

	// DeleteTexture2D
	void SLRenderer_GLES3::DeleteTexture2D(ISLTexture2D* texture2d)
	{
		// check if exists
		if (!IsTexture2DExists(texture2d))
			return;

		// remove existing textures
		mTexture2Ds.erase(std::remove_if(mTexture2Ds.begin(), mTexture2Ds.end(), [&](SLTexture2D_GLES3* item) {
			return item == texture2d;
		}), mTexture2Ds.end());

		// delete texture
		delete (SLTexture2D_GLES3 *)texture2d;
	}

	// IsTexture2DExist
	bool SLRenderer_GLES3::IsTexture2DExists(ISLTexture2D* texture2d) const
	{
		return (std::find(mTexture2Ds.begin(), mTexture2Ds.end(), texture2d) != mTexture2Ds.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Buffer
	//////////////////////////////////////////////////////////////////////////

	// CreateBuffer
	ISLBuffer* SLRenderer_GLES3::CreateBuffer()
	{
		// create new buffer
		SLBuffer_GLES3* buffer = new SLBuffer_GLES3(this);
		mBuffers.push_back(buffer);
		return buffer;
	}

	// DeleteBuffer
	void SLRenderer_GLES3::DeleteBuffer(ISLBuffer* buffer)
	{
		// check if exists
		if (!IsBufferExists(buffer))
			return;

		// remove existing buffers
		mBuffers.erase(std::remove_if(mBuffers.begin(), mBuffers.end(), [&](SLBuffer_GLES3* item) {
			return item == buffer;
		}), mBuffers.end());

		// delete buffer
		delete (SLBuffer_GLES3 *)buffer;
	}

	// IsBufferExist
	bool SLRenderer_GLES3::IsBufferExists(ISLBuffer* buffer) const
	{
		return (std::find(mBuffers.begin(), mBuffers.end(), buffer) != mBuffers.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Index Buffer
	//////////////////////////////////////////////////////////////////////////

	// CreateIndexBuffer
	ISLIndexBuffer* SLRenderer_GLES3::CreateIndexBuffer()
	{
		// create new buffer
		SLIndexBuffer_GLES3* buffer = new SLIndexBuffer_GLES3(this);
		mIndexBuffers.push_back(buffer);
		return buffer;
	}

	// DeleteIndexBuffer
	void SLRenderer_GLES3::DeleteIndexBuffer(ISLIndexBuffer* buffer)
	{
		// check if exists
		if (!IsIndexBufferExists(buffer))
			return;

		// remove existing index buffers
		mIndexBuffers.erase(std::remove_if(mIndexBuffers.begin(), mIndexBuffers.end(), [&](SLIndexBuffer_GLES3* item) {
			return item == buffer;
		}), mIndexBuffers.end());

		// delete buffer
		delete (SLIndexBuffer_GLES3 *)buffer;
	}

	// IsIndexBufferExists
	bool SLRenderer_GLES3::IsIndexBufferExists(ISLIndexBuffer* buffer) const
	{
		return (std::find(mIndexBuffers.begin(), mIndexBuffers.end(), buffer) != mIndexBuffers.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Mesh
	//////////////////////////////////////////////////////////////////////////

	// CreateMesh
	ISLMesh* SLRenderer_GLES3::CreateMesh()
	{
		// create new buffer
		SLMesh_GLES3* mesh = new SLMesh_GLES3(this);
		mesh->mShader = mShaderManager.GetDefaultShader();
		mMeshes.push_back(mesh);
		return mesh;
	}

	// DeleteMesh
	void SLRenderer_GLES3::DeleteMesh(ISLMesh* mesh)
	{
		// check if exists
		if (!IsMeshExists(mesh))
			return;

		// remove existing meshes
		mMeshes.erase(std::remove_if(mMeshes.begin(), mMeshes.end(), [&](SLMesh_GLES3* item) {
			return item == mesh;
		}), mMeshes.end());

		// delete mesh
		delete (SLMesh_GLES3 *)mesh;
	}

	// IsMeshExists
	bool SLRenderer_GLES3::IsMeshExists(ISLMesh* mesh) const
	{
		return (std::find(mMeshes.begin(), mMeshes.end(), mesh) != mMeshes.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Model
	//////////////////////////////////////////////////////////////////////////

	// CreateModel
	ISLModel* SLRenderer_GLES3::CreateModel()
	{
		// create new buffer
		SLModel_GLES3* model = new SLModel_GLES3(this);
		mModels.push_back(model);
		return model;
	}

	// DeleteModel
	void SLRenderer_GLES3::DeleteModel(ISLModel* model)
	{
		// check if exists
		if (!IsModelExists(model))
			return;

		// remove existing models
		mModels.erase(std::remove_if(mModels.begin(), mModels.end(), [&](SLModel_GLES3* item) {
			return item == model;
		}), mModels.end());

		// delete model
		delete (SLModel_GLES3 *)model;
	}

	// IsModelExists
	bool SLRenderer_GLES3::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Camera
	//////////////////////////////////////////////////////////////////////////

	// CreateCamera
	ISLCamera* SLRenderer_GLES3::CreateCamera()
	{
		// create new buffer
		SLCamera_GLES3* camera = new SLCamera_GLES3(this);
		mCameras.push_back(camera);
		return camera;
	}

	// DeleteCamera
	void SLRenderer_GLES3::DeleteCamera(ISLCamera* camera)
	{
		// check if exists
		if (!IsCameraExists(camera))
			return;

		// remove existing cameras
		mCameras.erase(std::remove_if(mCameras.begin(), mCameras.end(), [&](SLCamera_GLES3* item) {
			return item == camera;
		}), mCameras.end());

		// delete camera
		delete (SLCamera_GLES3 *)camera;
	}

	// IsCameraExists
	bool SLRenderer_GLES3::IsCameraExists(ISLCamera* camera) const
	{
		return (std::find(mCameras.begin(), mCameras.end(), camera) != mCameras.end());
	}

	//////////////////////////////////////////////////////////////////////////
	// Scene
	//////////////////////////////////////////////////////////////////////////

	// CreateScene
	ISLRenderScene* SLRenderer_GLES3::CreateScene()
	{
		// create new buffer
		SLRenderScene_GLES3* scene = new SLRenderScene_GLES3(this);
		mRenderScenes.push_back(scene);
		return scene;
	}

	// DeleteScene
	void SLRenderer_GLES3::DeleteRenderScene(ISLRenderScene* scene)
	{
		// check if exists
		if (!IsRenderSceneExists(scene))
			return;

		// remove existing cameras
		mRenderScenes.erase(std::remove_if(mRenderScenes.begin(), mRenderScenes.end(), [&](SLRenderScene_GLES3* item) {
			return item == scene;
		}), mRenderScenes.end());

		// delete scene
		delete (SLRenderScene_GLES3 *)scene;
	}

	// IsRenderSceneExists
	bool SLRenderer_GLES3::IsRenderSceneExists(ISLRenderScene* scene) const
	{
		return (std::find(mRenderScenes.begin(), mRenderScenes.end(), scene) != mRenderScenes.end());
	}

	// Render
	void SLRenderer_GLES3::Render()
	{
		// clear buffer
		GL_CHECK(glClearColor(1.0f / 255.0f, 36.0f / 255, 86.0f / 255.0f, 1.0f));
		GL_CHECK(glClearDepthf(1.0));
		GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		// iterate by all meshes
		for (auto scene : mRenderScenes) {
			if (scene->mVisibilityMode == SL_RENDER_SCENE_VISIBILITY_MODE_VISIBLE) {
				for (auto model : scene->mModels) {
					for (auto mesh : model->mMeshes)
					{
						// bind program and buffers
						GL_CHECK(glUseProgram(mesh->mShader->mGLProgram));
						GL_CHECK(glBindVertexArray(mesh->mGLVertexArrayHandle));

						// set uniforms
						GL_CHECK(glUniformMatrix4fv(mesh->mShader->mGLModelMatUniformLoc, 1, GL_FALSE, model->mTransform));
						GL_CHECK(glUniformMatrix4fv(mesh->mShader->mGLViewMatUniformLoc, 1, GL_FALSE, scene->mCamera->mTransform));
						GL_CHECK(glUniformMatrix4fv(mesh->mShader->mGLProjMatUniformLoc, 1, GL_FALSE, scene->mCamera->mProjection));

						// draw not indexed
						if (mesh->mIndexBuffer == nullptr)
							GL_CHECK(glDrawArrays(mesh->mGLPrimitiveMode, 0, mesh->mGLElementsCount));
						// draw indexed
						if (mesh->mIndexBuffer != nullptr)
							GL_CHECK(glDrawElements(mesh->mGLPrimitiveMode, mesh->mGLElementsCount, GL_UNSIGNED_SHORT, 0));

						// unbind program and buffers
						GL_CHECK(glBindVertexArray(0));
						GL_CHECK(glUseProgram(0));
					}
				}
			}
		}
	}

	// DeleteResources
	void SLRenderer_GLES3::DeleteResources()
	{
		// delete shaders
		mShaderManager.DeleteShaders();

		// delete all items
		std::for_each(mTexture2Ds.begin(), mTexture2Ds.end(), [](SLTexture2D_GLES3* item) { delete item; });
		std::for_each(mBuffers.begin(), mBuffers.end(), [](SLBuffer_GLES3* item) { delete item; });
		std::for_each(mIndexBuffers.begin(), mIndexBuffers.end(), [](SLIndexBuffer_GLES3* item) { delete item; });
		std::for_each(mMeshes.begin(), mMeshes.end(), [](SLMesh_GLES3* item) { delete item; });
		std::for_each(mModels.begin(), mModels.end(), [](SLModel_GLES3* item) { delete item; });
		std::for_each(mCameras.begin(), mCameras.end(), [](SLCamera_GLES3* item) { delete item; });
		std::for_each(mRenderScenes.begin(), mRenderScenes.end(), [](SLRenderScene_GLES3* item) { delete item; });

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
	const char* SLRenderer_GLES3::GetDescription() const
	{
		return mDescription.c_str();
	}
}
