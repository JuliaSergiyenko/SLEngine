#pragma once

#include "SLMesh_GLES2.hpp"
#include <vector>

// SLR_GLES2
namespace SLR_GLES2 {
	// SLModel_GLES2
	class SLModel_GLES2 : public ISLModel
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;
	public:
		// visibility
		SLModelVisibilityMode mVisibilityMode = SL_MODEL_VISIBILITY_MODE_VISIBLE;

		// meshes
		std::vector<SLMesh_GLES2 *> mMeshes;

		// transform
		float mTransform[16];
	public:
		// constructor and destructor
		SLModel_GLES2(ISLRenderer* renderer);
		~SLModel_GLES2();

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
