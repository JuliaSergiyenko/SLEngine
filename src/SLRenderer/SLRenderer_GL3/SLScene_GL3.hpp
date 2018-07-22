#pragma once

#include "SLCamera_GL3.hpp"
#include "SLModel_GL3.hpp"
#include <vector>

// SLR_GL3
namespace SLR_GL3 {
	// SLScene_GL3
	class SLScene_GL3 : public ISLScene
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// camera
		SLCamera_GL3* mCamera = nullptr;

		// models
		std::vector<SLModel_GL3 *> mModels;
	public:
		// constructor and destructor
		SLScene_GL3(ISLRenderer* renderer);
		~SLScene_GL3();

		// get render device
		ISLRenderer* GetRenderer() const;

		// camera functions
		virtual void SetCamera(ISLCamera* camera);
		virtual ISLCamera* GetCamera();

		// model functions
		virtual void AddModel(ISLModel* model);
		virtual void RemoveModel(ISLModel* model);
		virtual bool IsModelExists(ISLModel* model);
	};
}
