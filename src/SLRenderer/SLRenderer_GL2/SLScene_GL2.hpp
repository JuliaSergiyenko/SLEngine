#pragma once

#include "SLCamera_GL2.hpp"
#include "SLModel_GL2.hpp"
#include <vector>

// SLR_GL2
namespace SLR_GL2 {
	// SLScene_GL2
	class SLScene_GL2 : public ISLScene
	{
	private:
		// renderer
		ISLRenderer * mRenderer = nullptr;

		// camera
		SLCamera_GL2* mCamera = nullptr;

		// models
		std::vector<SLModel_GL2 *> mModels;

		// properties
		SLSceneVisibilityMode mVisibilityMode = SL_SCENE_VISIBILITY_MODE_VISIBLE;
	public:
		// constructor and destructor
		SLScene_GL2(ISLRenderer* renderer);
		~SLScene_GL2();

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
		virtual void SetVisibilityMode(SLSceneVisibilityMode visibilityMode);
		virtual SLSceneVisibilityMode GetVisibilityMode() const;
	};
}
