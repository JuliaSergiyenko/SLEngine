#pragma once

#include "SLMesh_GL2.hpp"
#include <vector>

// SLR_GL2
namespace SLR_GL2 {
	// SLModel_GL2
	class SLModel_GL2 : public ISLModel
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;
	public:
		// visibility
		SLModelVisibilityMode mVisibilityMode = SL_MODEL_VISIBILITY_MODE_VISIBLE;

		// meshes
		std::vector<SLMesh_GL2 *> mMeshes;

		// transform
		float mTransform[16];
	public:
		// constructor and destructor
		SLModel_GL2(ISLRenderer* renderer);
		~SLModel_GL2();

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
