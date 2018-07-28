#include "SLRenderScene_GLES2.hpp"
#include <algorithm>

// SLR_GLES2
namespace SLR_GLES2
{
	// SLRenderScene_GLES2
	SLRenderScene_GLES2::SLRenderScene_GLES2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLRenderScene_GLES2
	SLRenderScene_GLES2::~SLRenderScene_GLES2()
	{
	}

	// GetRenderer
	ISLRenderer* SLRenderScene_GLES2::GetRenderer() const
	{
		return mRenderer;
	}

	// SetCamera
	void SLRenderScene_GLES2::SetCamera(ISLCamera* camera)
	{
		// check if exists
		if (mRenderer->IsCameraExists(camera))
			mCamera = (SLCamera_GLES2 *)camera;
	}

	// GetCamera
	ISLCamera* SLRenderScene_GLES2::GetCamera() const
	{
		return mCamera;
	}

	// AddModel
	void SLRenderScene_GLES2::AddModel(ISLModel* model)
	{
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			mModels.push_back((SLModel_GLES2 *)model);
	}

	// RemoveModel
	void SLRenderScene_GLES2::RemoveModel(ISLModel* model)
	{
		// check if exists
		if (IsModelExists(model))
			return;
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			return;
		// remove existing model
		mModels.erase(std::remove_if(mModels.begin(), mModels.end(), [&](SLModel_GLES2* item) {
			return item == model;
		}), mModels.end());
	}

	// IsModelExists
	bool SLRenderScene_GLES2::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	// SetVisibilityMode
	void SLRenderScene_GLES2::SetVisibilityMode(SLRenderSceneVisibilityMode visibilityMode)
	{
		mVisibilityMode = visibilityMode;
	}

	// GetVisibilityMode
	SLRenderSceneVisibilityMode SLRenderScene_GLES2::GetVisibilityMode() const
	{
		return mVisibilityMode;
	}
}
