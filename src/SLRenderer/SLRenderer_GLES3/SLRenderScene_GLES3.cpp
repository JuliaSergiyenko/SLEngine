#include "SLRenderScene_GLES3.hpp"
#include <algorithm>

// SLR_GLES3
namespace SLR_GLES3
{
	// SLRenderScene_GLES3
	SLRenderScene_GLES3::SLRenderScene_GLES3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLRenderScene_GLES3
	SLRenderScene_GLES3::~SLRenderScene_GLES3()
	{
	}

	// GetRenderer
	ISLRenderer* SLRenderScene_GLES3::GetRenderer() const
	{
		return mRenderer;
	}

	// SetCamera
	void SLRenderScene_GLES3::SetCamera(ISLCamera* camera)
	{
		// check if exists
		if (mRenderer->IsCameraExists(camera))
			mCamera = (SLCamera_GLES3 *)camera;
	}

	// GetCamera
	ISLCamera* SLRenderScene_GLES3::GetCamera() const
	{
		return mCamera;
	}

	// AddModel
	void SLRenderScene_GLES3::AddModel(ISLModel* model)
	{
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			mModels.push_back((SLModel_GLES3 *)model);
	}

	// RemoveModel
	void SLRenderScene_GLES3::RemoveModel(ISLModel* model)
	{
		// check if exists
		if (IsModelExists(model))
			return;
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			return;
		// remove existing model
		mModels.erase(std::remove_if(mModels.begin(), mModels.end(), [&](SLModel_GLES3* item) {
			return item == model;
		}), mModels.end());
	}

	// IsModelExists
	bool SLRenderScene_GLES3::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	// SetVisibilityMode
	void SLRenderScene_GLES3::SetVisibilityMode(SLRenderSceneVisibilityMode visibilityMode)
	{
		mVisibilityMode = visibilityMode;
	}

	// GetVisibilityMode
	SLRenderSceneVisibilityMode SLRenderScene_GLES3::GetVisibilityMode() const
	{
		return mVisibilityMode;
	}
}
