#include "SLScene_GLES3.hpp"
#include <algorithm>

// SLR_GLES3
namespace SLR_GLES3
{
	// SLScene_GLES3
	SLScene_GLES3::SLScene_GLES3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLScene_GLES3
	SLScene_GLES3::~SLScene_GLES3()
	{
	}

	// GetRenderer
	ISLRenderer* SLScene_GLES3::GetRenderer() const
	{
		return mRenderer;
	}

	// SetCamera
	void SLScene_GLES3::SetCamera(ISLCamera* camera)
	{
		// check if exists
		if (mRenderer->IsCameraExists(camera))
			mCamera = (SLCamera_GLES3 *)camera;
	}

	// GetCamera
	ISLCamera* SLScene_GLES3::GetCamera() const
	{
		return mCamera;
	}

	// AddModel
	void SLScene_GLES3::AddModel(ISLModel* model)
	{
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			mModels.push_back((SLModel_GLES3 *)model);
	}

	// RemoveModel
	void SLScene_GLES3::RemoveModel(ISLModel* model)
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
	bool SLScene_GLES3::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	// SetVisibilityMode
	void SLScene_GLES3::SetVisibilityMode(SLSceneVisibilityMode visibilityMode)
	{
		mVisibilityMode = visibilityMode;
	}

	// GetVisibilityMode
	SLSceneVisibilityMode SLScene_GLES3::GetVisibilityMode() const
	{
		return mVisibilityMode;
	}
}
