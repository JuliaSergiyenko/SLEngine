#include "SLModel_GL4.hpp"
#include <algorithm>

// SLR_GL4
namespace SLR_GL4
{
	// SLModel_GL4
	SLModel_GL4::SLModel_GL4(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLModel_GL4
	SLModel_GL4::~SLModel_GL4()
	{
	}

	// GetRenderer
	ISLRenderer* SLModel_GL4::GetRenderer() const
	{
		return mRenderer;
	}

	// SetVisibilityMode
	void SLModel_GL4::SetVisibilityMode(SLModelVisibilityMode visibilityMode)
	{
		mVisibilityMode = visibilityMode;
	}

	// SetVisibilityMode
	SLModelVisibilityMode SLModel_GL4::GetVisibilityMode() const
	{
		return mVisibilityMode;
	}

	// AddMesh
	void SLModel_GL4::AddMesh(ISLMesh* mesh)
	{
		// check if exists
		if (IsMeshExists(mesh))
			return;
		// check if exists in renderer
		if (!GetRenderer()->IsMeshExists(mesh))
			return;
		mMeshes.push_back((SLMesh_GL4 *)mesh);
	}

	// RemoveMesh
	void SLModel_GL4::RemoveMesh(ISLMesh* mesh)
	{
		// check if exists
		if (!IsMeshExists(mesh))
			return;

		// remove existing meshes
		mMeshes.erase(std::remove_if(mMeshes.begin(), mMeshes.end(), [&](SLMesh_GL4* item) {
			return item == mesh;
		}), mMeshes.end());
	}

	// IsMeshExists
	bool SLModel_GL4::IsMeshExists(ISLMesh* mesh) const
	{
		return (std::find(mMeshes.begin(), mMeshes.end(), mesh) != mMeshes.end());
	}

	// SetTransform
	void SLModel_GL4::SetTransform(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mTransform, mat, sizeof(mTransform));
	}

	// GetTransform
	void SLModel_GL4::GetTransform(float* mat) const
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mat, mTransform, sizeof(mTransform));
	}
}
