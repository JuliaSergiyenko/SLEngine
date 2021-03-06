#pragma once

#include "SLCamera_GLES2.hpp"
#include "SLModel_GLES2.hpp"
#include <vector>

// SLR_GLES2
namespace SLR_GLES2 {
	// SLRenderScene_GLES2
	class SLRenderScene_GLES2 : public ISLRenderScene
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;
	public:
		// camera
		SLCamera_GLES2* mCamera = nullptr;

		// models
		std::vector<SLModel_GLES2 *> mModels;

		// properties
		SLRenderSceneVisibilityMode mVisibilityMode = SL_RENDER_SCENE_VISIBILITY_MODE_VISIBLE;
	public:
		// constructor and destructor
		SLRenderScene_GLES2(ISLRenderer* renderer);
		~SLRenderScene_GLES2();

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
