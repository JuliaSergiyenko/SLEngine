#include "SLRenderer_GL2.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

// SLR_GL2
namespace SLR_GL2 {
	// SLRenderer_GL2
	SLRenderer_GL2::SLRenderer_GL2()
	{
		// init opengl extensions
		InitOpenGL2();
		CreateDescription();

		// setup renderer
		mShaderManager.SetRenderer(this);
		mShaderManager.CreateShaders();
	}

	// ~SLRenderer_GL2
	SLRenderer_GL2::~SLRenderer_GL2()
	{
		// destructor
	}

	// CreateDescription
	void SLRenderer_GL2::CreateDescription()
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
	ISLTexture2D* SLRenderer_GL2::CreateTexture2D()
	{
		// create new texture
		SLTexture2D_GL2* texture2D = new SLTexture2D_GL2(this);
		mTexture2Ds.push_back(texture2D);
		return texture2D;
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
	ISLBuffer* SLRenderer_GL2::CreateBuffer()
	{
		// create new buffer
		SLBuffer_GL2* buffer = new SLBuffer_GL2(this);
		mBuffers.push_back(buffer);
		return buffer;
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
	ISLIndexBuffer* SLRenderer_GL2::CreateIndexBuffer()
	{
		// create new buffer
		SLIndexBuffer_GL2* buffer = new SLIndexBuffer_GL2(this);
		mIndexBuffers.push_back(buffer);
		return buffer;
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
		mesh->mShader = mShaderManager.GetDefaultShader();
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
	ISLRenderScene* SLRenderer_GL2::CreateScene()
	{
		// create new buffer
		SLRenderScene_GL2* scene = new SLRenderScene_GL2(this);
		mRenderScenes.push_back(scene);
		return scene;
	}

	// DeleteScene
	void SLRenderer_GL2::DeleteRenderScene(ISLRenderScene* scene)
	{
		// check if exists
		if (!IsRenderSceneExists(scene))
			return;

		// remove existing cameras
		mRenderScenes.erase(std::remove_if(mRenderScenes.begin(), mRenderScenes.end(), [&](SLRenderScene_GL2* item) {
			return item == scene;
		}), mRenderScenes.end());

		// delete scene
		delete (SLRenderScene_GL2 *)scene;
	}

	// IsRenderSceneExists
	bool SLRenderer_GL2::IsRenderSceneExists(ISLRenderScene* scene) const
	{
		return (std::find(mRenderScenes.begin(), mRenderScenes.end(), scene) != mRenderScenes.end());
	}

	// Render
	void SLRenderer_GL2::Render()
	{
		// clear buffer
		GL_CHECK(glClearColor(1.0f / 255.0f, 36.0f / 255, 86.0f / 255.0f, 1.0f));
		GL_CHECK(glClearDepth(1.0));
		GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		// iterate by all meshes
		for (auto scene : mRenderScenes) {
			if (scene->mVisibilityMode == SL_RENDER_SCENE_VISIBILITY_MODE_VISIBLE) {
				for (auto model : scene->mModels) {
					for (auto mesh : model->mMeshes)
					{
						// bind program and buffers
						GL_CHECK(glUseProgram(mesh->mShader->mGLProgram));

						// set uniforms
						GL_CHECK(glUniformMatrix4fv(mesh->mShader->mGLModelMatUniformLoc, 1, GL_FALSE, model->mTransform));
						GL_CHECK(glUniformMatrix4fv(mesh->mShader->mGLViewMatUniformLoc, 1, GL_FALSE, scene->mCamera->mTransform));
						GL_CHECK(glUniformMatrix4fv(mesh->mShader->mGLProjMatUniformLoc, 1, GL_FALSE, scene->mCamera->mProjection));

						// set position buffer
						if (mesh->mPositionBuffer != nullptr)
						{
							GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mesh->mPositionBuffer->mGLBufferHandle));
							GL_CHECK(glVertexAttribPointer(mesh->mGLPositionAttrLoc, 3, GL_FLOAT, GL_FALSE, 0, 0));
							GL_CHECK(glEnableVertexAttribArray(mesh->mGLPositionAttrLoc));
						}

						// set color buffer
						if (mesh->mColorBuffer != nullptr)
						{
							GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mesh->mColorBuffer->mGLBufferHandle));
							GL_CHECK(glVertexAttribPointer(mesh->mGLColorAttrLoc, 4, GL_FLOAT, GL_FALSE, 0, 0));
							GL_CHECK(glEnableVertexAttribArray(mesh->mGLColorAttrLoc));
						}

						// set normal buffer
						if (mesh->mNormalBuffer != nullptr)
						{
							GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mesh->mNormalBuffer->mGLBufferHandle));
							GL_CHECK(glVertexAttribPointer(mesh->mGLNormalAttrLoc, 3, GL_FLOAT, GL_FALSE, 0, 0));
							GL_CHECK(glEnableVertexAttribArray(mesh->mGLNormalAttrLoc));
						}

						// set tangent buffer
						if (mesh->mTangentBuffer != nullptr)
						{
							GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mesh->mTangentBuffer->mGLBufferHandle));
							GL_CHECK(glVertexAttribPointer(mesh->mGLTangentAttrLoc, 3, GL_FLOAT, GL_FALSE, 0, 0));
							GL_CHECK(glEnableVertexAttribArray(mesh->mGLTangentAttrLoc));
						}

						// set tex coord buffer
						if (mesh->mTexCoordBuffer != nullptr)
						{
							GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mesh->mTexCoordBuffer->mGLBufferHandle));
							GL_CHECK(glVertexAttribPointer(mesh->mGLTexCoordAttrLoc, 2, GL_FLOAT, GL_FALSE, 0, 0));
							GL_CHECK(glEnableVertexAttribArray(mesh->mGLTexCoordAttrLoc));
						}

						// set weights buffer
						if (mesh->mWeightsBuffer != nullptr)
						{
							GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mesh->mWeightsBuffer->mGLBufferHandle));
							GL_CHECK(glVertexAttribPointer(mesh->mGLWeightsAttrLoc, 4, GL_FLOAT, GL_FALSE, 0, 0));
							GL_CHECK(glEnableVertexAttribArray(mesh->mGLWeightsAttrLoc));
						}

						// set index buffer
						if (mesh->mIndexBuffer != nullptr)
							GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->mIndexBuffer->mGLBufferHandle));

						// draw not indexed
						if (mesh->mIndexBuffer == nullptr)
							GL_CHECK(glDrawArrays(mesh->mGLPrimitiveMode, 0, mesh->mGLElementsCount));
						// draw indexed
						if (mesh->mIndexBuffer != nullptr)
							GL_CHECK(glDrawElements(mesh->mGLPrimitiveMode, mesh->mGLElementsCount, GL_UNSIGNED_SHORT, 0));

						// disable position buffer
						if (mesh->mPositionBuffer != nullptr)
							GL_CHECK(glDisableVertexAttribArray(mesh->mGLPositionAttrLoc));
						// disable position buffer
						if (mesh->mColorBuffer != nullptr)
							GL_CHECK(glDisableVertexAttribArray(mesh->mGLColorAttrLoc));
						// disable position buffer
						if (mesh->mNormalBuffer != nullptr)
							GL_CHECK(glDisableVertexAttribArray(mesh->mGLNormalAttrLoc));
						// disable position buffer
						if (mesh->mTangentBuffer != nullptr)
							GL_CHECK(glDisableVertexAttribArray(mesh->mGLTangentAttrLoc));
						// disable position buffer
						if (mesh->mTexCoordBuffer != nullptr)
							GL_CHECK(glDisableVertexAttribArray(mesh->mGLTexCoordAttrLoc));
						// disable position buffer
						if (mesh->mWeightsBuffer != nullptr)
							GL_CHECK(glDisableVertexAttribArray(mesh->mGLWeightsAttrLoc));
						// disable index buffer
						if (mesh->mIndexBuffer != nullptr)
							GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

						// unbind program and buffers
						GL_CHECK(glUseProgram(0));
					}
				}
			}
		}
	}

	// DeleteResources
	void SLRenderer_GL2::DeleteResources()
	{
		// delete shaders
		mShaderManager.DeleteShaders();

		// delete all items
		std::for_each(mTexture2Ds.begin(), mTexture2Ds.end(), [](SLTexture2D_GL2* item) { delete item; });
		std::for_each(mBuffers.begin(), mBuffers.end(), [](SLBuffer_GL2* item) { delete item; });
		std::for_each(mIndexBuffers.begin(), mIndexBuffers.end(), [](SLIndexBuffer_GL2* item) { delete item; });
		std::for_each(mMeshes.begin(), mMeshes.end(), [](SLMesh_GL2* item) { delete item; });
		std::for_each(mModels.begin(), mModels.end(), [](SLModel_GL2* item) { delete item; });
		std::for_each(mCameras.begin(), mCameras.end(), [](SLCamera_GL2* item) { delete item; });
		std::for_each(mRenderScenes.begin(), mRenderScenes.end(), [](SLRenderScene_GL2* item) { delete item; });

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
	const char* SLRenderer_GL2::GetDescription() const
	{
		return mDescription.c_str();
	}
}
