#pragma once

#include "SLCamera_GL4.hpp"
#include "SLModel_GL4.hpp"
#include <vector>

// SLR_GL4
namespace SLR_GL4 {
	// SLRenderScene_GL4
	class SLRenderScene_GL4 : public ISLRenderScene
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;
	public:
		// camera
		SLCamera_GL4* mCamera = nullptr;

		// models
		std::vector<SLModel_GL4 *> mModels;

		// properties
		SLRenderSceneVisibilityMode mVisibilityMode = SL_RENDER_SCENE_VISIBILITY_MODE_VISIBLE;
	public:
		// constructor and destructor
		SLRenderScene_GL4(ISLRenderer* renderer);
		~SLRenderScene_GL4();

		// get render device
		ISLRenderer* GetRenderer() const;

		// camera functions
		virtual void SetCamera(ISLCamera* camera);
		virtual ISLCamera* GetCamera() const;

		// model functions
		virtual void AddModel(ISLModel* model);
		virtual void RemoveModel(ISLModel* model);
		virtual bool IsModelExists(ISLModel* model) const;

		// properties
		virtual void SetVisibilityMode(SLRenderSceneVisibilityMode visibilityMode);
		virtual SLRenderSceneVisibilityMode GetVisibilityMode() const;
	};
}
