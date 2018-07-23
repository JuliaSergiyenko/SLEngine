#include "SLModel_GLES3.hpp"
#include <algorithm>

// SLR_GLES3
namespace SLR_GLES3
{
	// SLModel_GLES3
	SLModel_GLES3::SLModel_GLES3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLModel_GLES3
	SLModel_GLES3::~SLModel_GLES3()
	{
	}

	// GetRenderer
	ISLRenderer* SLModel_GLES3::GetRenderer() const
	{
		return mRenderer;
	}

	// SetVisibilityMode
	void SLModel_GLES3::SetVisibilityMode(SLModelVisibilityMode visibilityMode)
	{
		mVisibilityMode = visibilityMode;
	}

	// SetVisibilityMode
	SLModelVisibilityMode SLModel_GLES3::GetVisibilityMode() const
	{
		return mVisibilityMode;
	}

	// AddMesh
	void SLModel_GLES3::AddMesh(ISLMesh* mesh)
	{
		// check if exists
		if (IsMeshExists(mesh))
			return;
		// check if exists in renderer
		if (!GetRenderer()->IsMeshExists(mesh))
			return;
		mMeshes.push_back((SLMesh_GLES3 *)mesh);
	}

	// RemoveMesh
	void SLModel_GLES3::RemoveMesh(ISLMesh* mesh)
	{
		// check if exists
		if (!IsMeshExists(mesh))
			return;

		// remove existing meshes
		mMeshes.erase(std::remove_if(mMeshes.begin(), mMeshes.end(), [&](SLMesh_GLES3* item) {
			return item == mesh;
		}), mMeshes.end());
	}

	// IsMeshExists
	bool SLModel_GLES3::IsMeshExists(ISLMesh* mesh) const
	{
		return (std::find(mMeshes.begin(), mMeshes.end(), mesh) != mMeshes.end());
	}

	// SetTransform
	void SLModel_GLES3::SetTransform(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mTransform, mat, sizeof(mTransform));
	}

	// GetTransform
	void SLModel_GLES3::GetTransform(float* mat) const
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mat, mTransform, sizeof(mTransform));
	}
}
