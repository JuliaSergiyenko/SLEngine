#include "SLRenderer_GL4.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

// SLR_GL4
namespace SLR_GL4 {
	// SLRenderer_GL4
	SLRenderer_GL4::SLRenderer_GL4()
	{
		// init opengl extensions
		InitOpenGL4();
		CreateDescription();

		// setup renderer
		mShaderManager.SetRenderer(this);
		mShaderManager.CreateShaders();
	}

	// ~SLRenderer_GL4
	SLRenderer_GL4::~SLRenderer_GL4()
	{
		// destructor
	}

	// CreateDescription
	void SLRenderer_GL4::CreateDescription()
	{
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
		mesh->mShader = mShaderManager.GetDefaultShader();
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
		mRenderScenes.push_back(scene);
		return scene;
	}

	// DeleteScene
	void SLRenderer_GL4::DeleteRenderScene(ISLRenderScene* scene)
	{
		// check if exists
		if (!IsRenderSceneExists(scene))
			return;

		// remove existing cameras
		mRenderScenes.erase(std::remove_if(mRenderScenes.begin(), mRenderScenes.end(), [&](SLRenderScene_GL4* item) {
			return item == scene;
		}), mRenderScenes.end());

		// delete scene
		delete (SLRenderScene_GL4 *)scene;
	}

	// IsRenderSceneExists
	bool SLRenderer_GL4::IsRenderSceneExists(ISLRenderScene* scene) const
	{
		return (std::find(mRenderScenes.begin(), mRenderScenes.end(), scene) != mRenderScenes.end());
	}

	// Render
	void SLRenderer_GL4::Render()
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
						// use program
						GL_CHECK(glUseProgram(mesh->mShader->mGLProgram));

						// set uniforms
						GL_CHECK(glUniformMatrix4fv(mesh->mShader->mGLModelMatUniformLoc, 1, GL_FALSE, model->mTransform));
						GL_CHECK(glUniformMatrix4fv(mesh->mShader->mGLViewMatUniformLoc, 1, GL_FALSE, scene->mCamera->mTransform));
						GL_CHECK(glUniformMatrix4fv(mesh->mShader->mGLProjMatUniformLoc, 1, GL_FALSE, scene->mCamera->mProjection));

						// bind buffers
						GL_CHECK(glBindVertexArray(mesh->mGLVertexArrayHandle));

						// set base texture unit
						if (mesh->mBaseTexture != nullptr)
						{
							GL_CHECK(glActiveTexture(GL_TEXTURE0 + cSLTextureUnit_Base));
							GL_CHECK(glBindTexture(GL_TEXTURE_2D, mesh->mBaseTexture->mGLTextureHadle));
							GL_CHECK(glBindSampler(cSLTextureUnit_Base, mesh->mBaseTexture->mGLSamplerHadle));
							GL_CHECK(glUniform1i(mesh->mShader->mGLBaseTextureUniformLoc, cSLTextureUnit_Base));
						}

						// set base texture unit
						if (mesh->mDetailTexture != nullptr)
						{
							GL_CHECK(glActiveTexture(GL_TEXTURE0 + cSLTextureUnit_Detail));
							GL_CHECK(glBindTexture(GL_TEXTURE_2D, mesh->mDetailTexture->mGLTextureHadle));
							GL_CHECK(glBindSampler(cSLTextureUnit_Detail, mesh->mDetailTexture->mGLSamplerHadle));
							GL_CHECK(glUniform1i(mesh->mShader->mGLDetailTextureUniformLoc, cSLTextureUnit_Detail));
						}

						// set normal texture unit
						if (mesh->mNormalTexture != nullptr)
						{
							GL_CHECK(glActiveTexture(GL_TEXTURE0 + cSLTextureUnit_Normal));
							GL_CHECK(glBindTexture(GL_TEXTURE_2D, mesh->mNormalTexture->mGLTextureHadle));
							GL_CHECK(glBindSampler(cSLTextureUnit_Normal, mesh->mNormalTexture->mGLSamplerHadle));
							GL_CHECK(glUniform1i(mesh->mShader->mGLNormalTextureUniformLoc, cSLTextureUnit_Normal));
						}

						// draw not indexed
						if (mesh->mIndexBuffer == nullptr)
							GL_CHECK(glDrawArrays(mesh->mGLPrimitiveMode, 0, mesh->mGLElementsCount));
						// draw indexed
						if (mesh->mIndexBuffer != nullptr)
							GL_CHECK(glDrawElements(mesh->mGLPrimitiveMode, mesh->mGLElementsCount, GL_UNSIGNED_SHORT, 0));

						// unbind base texture unit
						if (mesh->mBaseTexture != nullptr)
						{
							GL_CHECK(glActiveTexture(GL_TEXTURE0 + cSLTextureUnit_Base));
							GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
							GL_CHECK(glBindSampler(cSLTextureUnit_Base, 0));
						}

						// unbind detail texture unit
						if (mesh->mDetailTexture != nullptr)
						{
							GL_CHECK(glActiveTexture(GL_TEXTURE0 + cSLTextureUnit_Detail));
							GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
							GL_CHECK(glBindSampler(cSLTextureUnit_Detail, 0));
						}

						// unbind normal texture unit
						if (mesh->mNormalTexture != nullptr)
						{
							GL_CHECK(glActiveTexture(GL_TEXTURE0 + cSLTextureUnit_Normal));
							GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
							GL_CHECK(glBindSampler(cSLTextureUnit_Normal, 0));
						}

						// unbind buffers
						GL_CHECK(glBindVertexArray(0));

						// unuse program
						GL_CHECK(glUseProgram(0));
					}
				}
			}
		}
	}

	// DeleteResources
	void SLRenderer_GL4::DeleteResources()
	{
		// delete shaders
		mShaderManager.DeleteShaders();

		// delete all items
		std::for_each(mTexture2Ds.begin(), mTexture2Ds.end(), [](SLTexture2D_GL4* item) { delete item; });
		std::for_each(mBuffers.begin(), mBuffers.end(), [](SLBuffer_GL4* item) { delete item; });
		std::for_each(mIndexBuffers.begin(), mIndexBuffers.end(), [](SLIndexBuffer_GL4* item) { delete item; });
		std::for_each(mMeshes.begin(), mMeshes.end(), [](SLMesh_GL4* item) { delete item; });
		std::for_each(mModels.begin(), mModels.end(), [](SLModel_GL4* item) { delete item; });
		std::for_each(mCameras.begin(), mCameras.end(), [](SLCamera_GL4* item) { delete item; });
		std::for_each(mRenderScenes.begin(), mRenderScenes.end(), [](SLRenderScene_GL4* item) { delete item; });

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
	const char* SLRenderer_GL4::GetDescription() const
	{
		return mDescription.c_str();
	}
}
