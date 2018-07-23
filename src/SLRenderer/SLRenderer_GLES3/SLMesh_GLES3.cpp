#include "SLMesh_GLES3.hpp"
#include <stdexcept>

namespace SLR_GLES3
{
	// SLMesh_GLES3
	SLMesh_GLES3::SLMesh_GLES3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLMesh_GLES3
	SLMesh_GLES3::~SLMesh_GLES3()
	{
	}

	// GetRenderer
	ISLRenderer* SLMesh_GLES3::GetRenderer() const
	{
		return mRenderer;
	}

	// SetBaseColor
	void SLMesh_GLES3::SetBaseColor(float r, float g, float b, float a)
	{
		mBaseColor[0] = r;
		mBaseColor[1] = g;
		mBaseColor[2] = b;
		mBaseColor[3] = a;
	}

	// SetBaseTexture
	void SLMesh_GLES3::SetBaseTexture(ISLTexture2D* texture)
	{
		mBaseTexture = (SLTexture2D_GLES3 *)texture;
	}

	// SetDetailTexture
	void SLMesh_GLES3::SetDetailTexture(ISLTexture2D* texture)
	{
		mDetailTexture = (SLTexture2D_GLES3 *)texture;
	}

	// SetNormalTexture
	void SLMesh_GLES3::SetNormalTexture(ISLTexture2D* texture)
	{
		mNormalTexture = (SLTexture2D_GLES3 *)texture;
	}

	// SetPositionBuffer
	void SLMesh_GLES3::SetPositionBuffer(ISLBuffer* buffer)
	{
		mPositionBuffer = (SLBuffer_GLES3 *)buffer;
	}

	// SetColorBuffer
	void SLMesh_GLES3::SetColorBuffer(ISLBuffer* buffer)
	{
		mColorBuffer = (SLBuffer_GLES3 *)buffer;
	}

	// SetNormalBuffer
	void SLMesh_GLES3::SetNormalBuffer(ISLBuffer* buffer)
	{
		mNormalBuffer = (SLBuffer_GLES3 *)buffer;
	}

	// SetTangentBuffer
	void SLMesh_GLES3::SetTangentBuffer(ISLBuffer* buffer)
	{
		mTangentBuffer = (SLBuffer_GLES3 *)buffer;
	}

	// SetTexCoordBuffer
	void SLMesh_GLES3::SetTexCoordBuffer(ISLBuffer* buffer)
	{
		mTexCoordBuffer = (SLBuffer_GLES3 *)buffer;
	}

	// SetWeightsBuffer
	void SLMesh_GLES3::SetWeightsBuffer(ISLBuffer* buffer)
	{
		mWeightsBuffer = (SLBuffer_GLES3 *)buffer;
	}

	// SetIndexBuffer
	void SLMesh_GLES3::SetIndexBuffer(ISLIndexBuffer* buffer)
	{
		mIndexBuffer = (SLIndexBuffer_GLES3 *)buffer;
	}

	// SetPrimitiveCount
	void SLMesh_GLES3::SetPrimitiveCount(uint32_t count)
	{
		mPrimitiveCount = count;
	}

	// SetPrimitiveType
	void SLMesh_GLES3::SetPrimitiveType(SLPrimitiveType primitiveType)
	{
		mPrimitiveType = primitiveType;
	}

	// GetBaseColor
	void SLMesh_GLES3::GetBaseColor(float& r, float& g, float& b, float& a) const
	{
		r = mBaseColor[0];
		g = mBaseColor[1];
		b = mBaseColor[2];
		a = mBaseColor[3];
	}

	// GetBaseTexture
	ISLTexture2D* SLMesh_GLES3::GetBaseTexture() const
	{
		return mBaseTexture;
	}

	// GetDetailTexture
	ISLTexture2D* SLMesh_GLES3::GetDetailTexture() const
	{
		return mDetailTexture;
	}

	// GetNormalTexture
	ISLTexture2D* SLMesh_GLES3::GetNormalTexture() const
	{
		return mNormalTexture;
	}

	// GetPositionBuffer
	ISLBuffer* SLMesh_GLES3::GetPositionBuffer() const
	{
		return mPositionBuffer;
	}

	// GetColorBuffer
	ISLBuffer* SLMesh_GLES3::GetColorBuffer() const
	{
		return mColorBuffer;
	}

	// GetNormalBuffer
	ISLBuffer* SLMesh_GLES3::GetNormalBuffer() const
	{
		return mNormalBuffer;
	}

	// GetTangentBuffer
	ISLBuffer* SLMesh_GLES3::GetTangentBuffer() const
	{
		return mTangentBuffer;
	}

	// GetTexCoordBuffer
	ISLBuffer* SLMesh_GLES3::GetTexCoordBuffer() const
	{
		return mTexCoordBuffer;
	}

	// GetWeightsBuffer
	ISLBuffer* SLMesh_GLES3::GetWeightsBuffer() const
	{
		return mWeightsBuffer;
	}

	// GetIndexBuffer
	ISLIndexBuffer* SLMesh_GLES3::GetIndexBuffer() const
	{
		return mIndexBuffer;
	}

	// GetPrimitiveCount
	uint32_t SLMesh_GLES3::GetPrimitiveCount() const
	{
		return mPrimitiveCount;
	}

	// GetPrimitiveType
	SLPrimitiveType SLMesh_GLES3::GetPrimitiveType() const
	{
		return mPrimitiveType;
	}
}
