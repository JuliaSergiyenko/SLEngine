#pragma once

#include "SLMesh_GL4.hpp"
#include <vector>

// SLR_GL4
namespace SLR_GL4 {
	// SLModel_GL4
	class SLModel_GL4 : public ISLModel
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;
	public:
		// visibility
		SLModelVisibilityMode mVisibilityMode = SL_MODEL_VISIBILITY_MODE_VISIBLE;

		// meshes
		std::vector<SLMesh_GL4 *> mMeshes;

		// transform
		float mTransform[16];
	public:
		// constructor and destructor
		SLModel_GL4(ISLRenderer* renderer);
		~SLModel_GL4();

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
