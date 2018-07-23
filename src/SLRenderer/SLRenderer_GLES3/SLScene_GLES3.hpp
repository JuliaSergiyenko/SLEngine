#pragma once

#include "SLCamera_GLES3.hpp"
#include "SLModel_GLES3.hpp"
#include <vector>

// SLR_GLES3
namespace SLR_GLES3 {
	// SLScene_GLES3
	class SLScene_GLES3 : public ISLScene
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// camera
		SLCamera_GLES3* mCamera = nullptr;

		// models
		std::vector<SLModel_GLES3 *> mModels;

		// properties
		SLSceneVisibilityMode mVisibilityMode = SL_SCENE_VISIBILITY_MODE_VISIBLE;
	public:
		// constructor and destructor
		SLScene_GLES3(ISLRenderer* renderer);
		~SLScene_GLES3();

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
