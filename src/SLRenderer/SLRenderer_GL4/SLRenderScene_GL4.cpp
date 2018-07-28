#include "SLRenderScene_GL4.hpp"
#include <algorithm>

// SLR_GL4
namespace SLR_GL4
{
	// SLRenderScene_GL4
	SLRenderScene_GL4::SLRenderScene_GL4(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLRenderScene_GL4
	SLRenderScene_GL4::~SLRenderScene_GL4()
	{
	}

	// GetRenderer
	ISLRenderer* SLRenderScene_GL4::GetRenderer() const
	{
		return mRenderer;
	}

	// SetCamera
	void SLRenderScene_GL4::SetCamera(ISLCamera* camera)
	{
		// check if exists
		if (mRenderer->IsCameraExists(camera))
			mCamera = (SLCamera_GL4 *)camera;
	}

	// GetCamera
	ISLCamera* SLRenderScene_GL4::GetCamera() const
	{
		return mCamera;
	}

	// AddModel
	void SLRenderScene_GL4::AddModel(ISLModel* model)
	{
		// check if exists in renderer
		if (mRenderer->IsModelExists(model))
			mModels.push_back((SLModel_GL4 *)model);
	}

	// RemoveModel
	void SLRenderScene_GL4::RemoveModel(ISLModel* model)
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
	bool SLRenderScene_GL4::IsModelExists(ISLModel* model) const
	{
		return (std::find(mModels.begin(), mModels.end(), model) != mModels.end());
	}

	// SetVisibilityMode
	void SLRenderScene_GL4::SetVisibilityMode(SLRenderSceneVisibilityMode visibilityMode)
	{
		mVisibilityMode = visibilityMode;
	}

	// GetVisibilityMode
	SLRenderSceneVisibilityMode SLRenderScene_GL4::GetVisibilityMode() const
	{
		return mVisibilityMode;
	}
}
