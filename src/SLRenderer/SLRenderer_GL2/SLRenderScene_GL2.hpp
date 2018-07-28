#pragma once

#include "SLCamera_GL2.hpp"
#include "SLModel_GL2.hpp"
#include <vector>

// SLR_GL2
namespace SLR_GL2 {
	// SLRenderScene_GL2
	class SLRenderScene_GL2 : public ISLRenderScene
	{
	private:
		// renderer
		ISLRenderer * mRenderer = nullptr;

		// camera
		SLCamera_GL2* mCamera = nullptr;

		// models
		std::vector<SLModel_GL2 *> mModels;

		// properties
		SLRenderSceneVisibilityMode mVisibilityMode = SL_RENDER_SCENE_VISIBILITY_MODE_VISIBLE;
	public:
		// constructor and destructor
		SLRenderScene_GL2(ISLRenderer* renderer);
		~SLRenderScene_GL2();

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
