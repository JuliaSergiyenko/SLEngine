#include "SLScene_GL2.hpp"
#include <algorithm>

// SLR_GL2
namespace SLR_GL2
{
	// SLScene_GL2
	SLScene_GL2::SLScene_GL2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLScene_GL2
	SLScene_GL2::~SLScene_GL2()
	{
	}

	// GetRenderer
	ISLRenderer* SLScene_GL2::GetRenderer() const
	{
		return mRenderer;
	}

	// SetCamera
	void SLScene_GL2::SetCamera(ISLCamera* camera)
	{
		// check if exists
		if (mRenderer->IsCameraExists(camera))
			mCamera = (SLCamera_GL2 *)camera;
	}

	// GetCamera
	ISLCamera* SLScene_GL2::GetCamera() const
	{
		return mCamera;
	}

	// AddModel
	void SLScene_GL2::AddModel(ISLModel* model)
	{
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			mModels.push_back((SLModel_GL2 *)model);
	}

	// RemoveModel
	void SLScene_GL2::RemoveModel(ISLModel* model)
	{
		// check if exists
		if (IsModelExists(model))
			return;
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			return;
		// remove existing model
		mModels.erase(std::remove_if(mModels.begin(), mModels.end(), [&](SLModel_GL2* item) {
			return item == model;
		}), mModels.end());
	}

	// IsModelExists
	bool SLScene_GL2::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	// SetVisibilityMode
	void SLScene_GL2::SetVisibilityMode(SLSceneVisibilityMode visibilityMode)
	{
		mVisibilityMode = visibilityMode;
	}

	// GetVisibilityMode
	SLSceneVisibilityMode SLScene_GL2::GetVisibilityMode() const
	{
		return mVisibilityMode;
	}
}
