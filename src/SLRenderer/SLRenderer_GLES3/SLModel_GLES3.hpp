#pragma once

#include "SLMesh_GLES3.hpp"
#include <vector>

// SLR_GLES3
namespace SLR_GLES3 {
	// SLModel_GLES3
	class SLModel_GLES3 : public ISLModel
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;

		// visibility
		SLModelVisibilityMode mVisibilityMode = SL_MODEL_VISIBILITY_MODE_VISIBLE;

		// meshes
		std::vector<SLMesh_GLES3 *> mMeshes;

		// transform
		float mTransform[16];
	public:
		// constructor and destructor
		SLModel_GLES3(ISLRenderer* renderer);
		~SLModel_GLES3();

		// get render device
		ISLRenderer* GetRenderer() const;

		// visibility functions
		void SetVisibilityMode(SLModelVisibilityMode visibilityMode);
		SLModelVisibilityMode GetVisibilityMode() const;

		// mesh functions
		void AddMesh(ISLMesh* mesh);
		void RemoveMesh(ISLMesh* mesh);
		bool IsMeshExists(ISLMesh* mesh) const;

		// transform matrix functions
		void SetTransform(float* mat);
		void GetTransform(float* mat) const;
	};
}
