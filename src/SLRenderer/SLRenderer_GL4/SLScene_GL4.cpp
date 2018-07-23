#include "SLScene_GL4.hpp"
#include <algorithm>

// SLR_GL4
namespace SLR_GL4
{
	// SLScene_GL4
	SLScene_GL4::SLScene_GL4(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLScene_GL4
	SLScene_GL4::~SLScene_GL4()
	{
	}

	// GetRenderer
	ISLRenderer* SLScene_GL4::GetRenderer() const
	{
		return mRenderer;
	}

	// SetCamera
	void SLScene_GL4::SetCamera(ISLCamera* camera)
	{
		// check if exists
		if (mRenderer->IsCameraExists(camera))
			mCamera = (SLCamera_GL4 *)camera;
	}

	// GetCamera
	ISLCamera* SLScene_GL4::GetCamera() const
	{
		return mCamera;
	}

	// AddModel
	void SLScene_GL4::AddModel(ISLModel* model)
	{
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			mModels.push_back((SLModel_GL4 *)model);
	}

	// RemoveModel
	void SLScene_GL4::RemoveModel(ISLModel* model)
	{
		// check if exists
		if (IsModelExists(model))
			return;
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			return;
		// remove existing model
		mModels.erase(std::remove_if(mModels.begin(), mModels.end(), [&](SLModel_GL4* item) {
			return item == model;
		}), mModels.end());
	}

	// IsModelExists
	bool SLScene_GL4::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	// SetVisibilityMode
	void SLScene_GL4::SetVisibilityMode(SLSceneVisibilityMode visibilityMode)
	{
		mVisibilityMode = visibilityMode;
	}

	// GetVisibilityMode
	SLSceneVisibilityMode SLScene_GL4::GetVisibilityMode() const
	{
		return mVisibilityMode;
	}
}
