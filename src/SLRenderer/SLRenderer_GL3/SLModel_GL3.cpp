#include "SLModel_GL3.hpp"
#include <algorithm>

// SLR_GL3
namespace SLR_GL3
{
	// SLModel_GL3
	SLModel_GL3::SLModel_GL3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLModel_GL3
	SLModel_GL3::~SLModel_GL3()
	{
	}

	// GetRenderer
	ISLRenderer* SLModel_GL3::GetRenderer() const
	{
		return mRenderer;
	}

	// SetVisibilityMode
	void SLModel_GL3::SetVisibilityMode(SLModelVisibilityMode visibilityMode)
	{
		mVisibilityMode = visibilityMode;
	}

	// SetVisibilityMode
	SLModelVisibilityMode SLModel_GL3::GetVisibilityMode()
	{
		return mVisibilityMode;
	}

	// AddMesh
	void SLModel_GL3::AddMesh(ISLMesh* mesh)
	{
		// check if exists
		if (IsMeshExists(mesh))
			return;
		// check if exists in renderer
		if (!GetRenderer()->IsMeshExists(mesh))
			return;
		mMeshes.push_back((SLMesh_GL3 *)mesh);
	}

	// RemoveMesh
	void SLModel_GL3::RemoveMesh(ISLMesh* mesh)
	{
		// check if exists
		if (!IsMeshExists(mesh))
			return;

		// remove existing meshes
		mMeshes.erase(std::remove_if(mMeshes.begin(), mMeshes.end(), [&](SLMesh_GL3* item) {
			return item == mesh;
		}), mMeshes.end());
	}

	// IsMeshExists
	bool SLModel_GL3::IsMeshExists(ISLMesh* mesh)
	{
		// iterate items
		for (auto item : mMeshes)
			if (item == mesh)
				return true;
		return false;
	}

	// SetTransform
	void SLModel_GL3::SetTransform(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mTransform, mat, sizeof(mTransform));
	}

	// GetTransform
	void SLModel_GL3::GetTransform(float* mat)
	{
		// check for null
		if (mat != nullptr)
			std::memcpy(mat, mTransform, sizeof(mTransform));
	}
}
