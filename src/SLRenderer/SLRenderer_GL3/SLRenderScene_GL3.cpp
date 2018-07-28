#include "SLRenderScene_GL3.hpp"
#include <algorithm>

// SLR_GL3
namespace SLR_GL3
{
	// SLRenderScene_GL3
	SLRenderScene_GL3::SLRenderScene_GL3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLRenderScene_GL3
	SLRenderScene_GL3::~SLRenderScene_GL3()
	{
	}

	// GetRenderer
	ISLRenderer* SLRenderScene_GL3::GetRenderer() const
	{
		return mRenderer;
	}

	// SetCamera
	void SLRenderScene_GL3::SetCamera(ISLCamera* camera)
	{
		// check if exists
		if (mRenderer->IsCameraExists(camera))
			mCamera = (SLCamera_GL3 *)camera;
	}

	// GetCamera
	ISLCamera* SLRenderScene_GL3::GetCamera() const
	{
		return mCamera;
	}

	// AddModel
	void SLRenderScene_GL3::AddModel(ISLModel* model)
	{
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			mModels.push_back((SLModel_GL3 *)model);
	}

	// RemoveModel
	void SLRenderScene_GL3::RemoveModel(ISLModel* model)
	{
		// check if exists
		if (IsModelExists(model))
			return;
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			return;
		// remove existing model
		mModels.erase(std::remove_if(mModels.begin(), mModels.end(), [&](SLModel_GL3* item) {
			return item == model;
		}), mModels.end());
	}

	// IsModelExists
	bool SLRenderScene_GL3::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	// SetVisibilityMode
	void SLRenderScene_GL3::SetVisibilityMode(SLRenderSceneVisibilityMode visibilityMode)
	{
		mVisibilityMode = visibilityMode;
	}

	// GetVisibilityMode
	SLRenderSceneVisibilityMode SLRenderScene_GL3::GetVisibilityMode() const
	{
		return mVisibilityMode;
	}
}
