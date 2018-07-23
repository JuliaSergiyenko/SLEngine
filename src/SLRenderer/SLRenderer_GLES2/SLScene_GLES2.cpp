#include "SLScene_GLES2.hpp"
#include <algorithm>

// SLR_GLES2
namespace SLR_GLES2
{
	// SLScene_GLES2
	SLScene_GLES2::SLScene_GLES2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLScene_GLES2
	SLScene_GLES2::~SLScene_GLES2()
	{
	}

	// GetRenderer
	ISLRenderer* SLScene_GLES2::GetRenderer() const
	{
		return mRenderer;
	}

	// SetCamera
	void SLScene_GLES2::SetCamera(ISLCamera* camera)
	{
		// check if exists
		if (mRenderer->IsCameraExists(camera))
			mCamera = (SLCamera_GLES2 *)camera;
	}

	// GetCamera
	ISLCamera* SLScene_GLES2::GetCamera() const
	{
		return mCamera;
	}

	// AddModel
	void SLScene_GLES2::AddModel(ISLModel* model)
	{
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			mModels.push_back((SLModel_GLES2 *)model);
	}

	// RemoveModel
	void SLScene_GLES2::RemoveModel(ISLModel* model)
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
	bool SLScene_GLES2::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	// SetVisibilityMode
	void SLScene_GLES2::SetVisibilityMode(SLSceneVisibilityMode visibilityMode)
	{
		mVisibilityMode = visibilityMode;
	}

	// GetVisibilityMode
	SLSceneVisibilityMode SLScene_GLES2::GetVisibilityMode() const
	{
		return mVisibilityMode;
	}
}
