#pragma once

#include "SLCamera_GL3.hpp"
#include "SLModel_GL3.hpp"
#include <vector>

// SLR_GL3
namespace SLR_GL3 {
	// SLRenderScene_GL3
	class SLRenderScene_GL3 : public ISLRenderScene
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// camera
		SLCamera_GL3* mCamera = nullptr;

		// models
		std::vector<SLModel_GL3 *> mModels;

		// properties
		SLRenderSceneVisibilityMode mVisibilityMode = SL_RENDER_SCENE_VISIBILITY_MODE_VISIBLE;
	public:
		// constructor and destructor
		SLRenderScene_GL3(ISLRenderer* renderer);
		~SLRenderScene_GL3();

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
