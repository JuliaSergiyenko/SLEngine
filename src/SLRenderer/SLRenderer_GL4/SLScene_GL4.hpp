#pragma once

#include "SLCamera_GL4.hpp"
#include "SLModel_GL4.hpp"
#include <vector>

// SLR_GL4
namespace SLR_GL4 {
	// SLScene_GL4
	class SLScene_GL4 : public ISLScene
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// camera
		SLCamera_GL4* mCamera = nullptr;

		// models
		std::vector<SLModel_GL4 *> mModels;

		// properties
		SLSceneVisibilityMode mVisibilityMode = SL_SCENE_VISIBILITY_MODE_VISIBLE;
	public:
		// constructor and destructor
		SLScene_GL4(ISLRenderer* renderer);
		~SLScene_GL4();

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
