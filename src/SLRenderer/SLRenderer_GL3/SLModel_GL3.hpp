#pragma once

#include "SLMesh_GL3.hpp"
#include <vector>

// SLR_GL3
namespace SLR_GL3 {
	// SLModel_GL3
	class SLModel_GL3 : public ISLModel
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// visibility
		SLModelVisibilityMode mVisibilityMode = SL_MODEL_VISIBILITY_MODE_VISIBLE;

		// meshes
		std::vector<SLMesh_GL3 *> mMeshes;

		// transform
		float mTransform[16];
	public:
		// constructor and destructor
		SLModel_GL3(ISLRenderer* renderer);
		~SLModel_GL3();

		// get render device
		ISLRenderer* GetRenderer() const;

		// visibility functions
		void SetVisibilityMode(SLModelVisibilityMode visibilityMode);
		SLModelVisibilityMode GetVisibilityMode();

		// mesh functions
		void AddMesh(ISLMesh* mesh);
		void RemoveMesh(ISLMesh* mesh);
		bool IsMeshExists(ISLMesh* mesh);

		// transform matrix functions
		void SetTransform(float* mat);
		void GetTransform(float* mat);
	};
}
