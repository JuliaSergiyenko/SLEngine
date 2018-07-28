#include "SLRenderScene_GL2.hpp"
#include <algorithm>

// SLR_GL2
namespace SLR_GL2
{
	// SLRenderScene_GL2
	SLRenderScene_GL2::SLRenderScene_GL2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLRenderScene_GL2
	SLRenderScene_GL2::~SLRenderScene_GL2()
	{
	}

	// GetRenderer
	ISLRenderer* SLRenderScene_GL2::GetRenderer() const
	{
		return mRenderer;
	}

	// SetCamera
	void SLRenderScene_GL2::SetCamera(ISLCamera* camera)
	{
		// check if exists
		if (mRenderer->IsCameraExists(camera))
			mCamera = (SLCamera_GL2 *)camera;
	}

	// GetCamera
	ISLCamera* SLRenderScene_GL2::GetCamera() const
	{
		return mCamera;
	}

	// AddModel
	void SLRenderScene_GL2::AddModel(ISLModel* model)
	{
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			mModels.push_back((SLModel_GL2 *)model);
	}

	// RemoveModel
	void SLRenderScene_GL2::RemoveModel(ISLModel* model)
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
	bool SLRenderScene_GL2::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	// SetVisibilityMode
	void SLRenderScene_GL2::SetVisibilityMode(SLRenderSceneVisibilityMode visibilityMode)
	{
		mVisibilityMode = visibilityMode;
	}

	// GetVisibilityMode
	SLRenderSceneVisibilityMode SLRenderScene_GL2::GetVisibilityMode() const
	{
		return mVisibilityMode;
	}
}
